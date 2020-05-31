#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::MainWindow)
{
  numOfWords=0;
  numOfLetters=0;
  dirChanged=false;
  currentDir=".";
  fileModel = new QFileSystemModel(this);
  ui->setupUi(this);
  ui->statusbar->addWidget(ui->Indexing_progress);
  ui->Indexing_progress->setMinimum(0);
  ui->Indexing_progress->setMaximum(0);
  ui->Indexing_progress->setValue(0);
  ui->Indexing_progress->hide();
  ui->path_lineEdit->setText(currentDir);
  ui->file_textBrowser->setReadOnly(true);
  ui->numFiles_label->hide();
  connect(&this->FutureWatcher, SIGNAL (finished()), this, SLOT (slot_finished()));
  connect(&this->FutureWatcher_files, SIGNAL (finished()), this, SLOT (slot_finished_files()));
//  currentProgress=0;
}

MainWindow::~MainWindow()
{
  delete ui;
}


void MainWindow::on_browse_button_clicked()
{
  currentDir= QFileDialog::getExistingDirectory(this, tr("Open Directory"),currentDir,QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
  ui->path_lineEdit->setText(currentDir);
  dirChanged=true;

}

QStringList MainWindow::findFiles(const QString &startDir, QStringList filters)
{
	QStringList names;
	QDir dir(startDir);

	// Search the current directory to meet the conditions of the file
	foreach (QString file, dir.entryList(filters, QDir::Files))
		names += startDir + '/' + file;

	 // Search the subdirectory of the current directory to meet the conditions of the file
	foreach (QString subdir, dir.entryList(QDir::AllDirs | QDir::NoDotAndDotDot))
		names += findFiles(startDir + '/' + subdir, filters);

	return names;
}

void MainWindow::startIndex()
{
  ui->document_listView->clear();
  QStringList dirInput = findFiles(currentDir,QStringList()<<"*.txt");
//  QDir tempDir(currentDir,"*.txt",QDir::Unsorted,QDir::NoDotAndDotDot|QDir::Files);
//  foreach (QFileInfo var, tempDir.entryInfoList())
//    {
//      dirInput.append(var.absoluteFilePath());
//    }
  numOfWords=0;
  numOfLetters=0;
  int tempInd=indexedEntries.size();
  indexedEntries.append(dirInput);
  indexedEntries.removeDuplicates();
  ui->numFiles_label->show();
  ui->numFiles_label->setText("Found files :"+QString::number(indexedEntries.size()));
//      ui->Indexing_progress->show();
  QStringList tempInput(indexedEntries.mid(tempInd));
  ui->Indexing_progress->setValue(0);
  ui->Indexing_progress->setMaximum(tempInput.size());
//  currentProgress=0;
//  currentMax=tempInput.size();
//      ui->Indexing_progress->show();
  build_trie(tempInput , tempInd);
//      ui->Indexing_progress->hide();
//  ui->document_listView->addItems(indexedEntries);
//  ui->statusbar->showMessage("Done in "+ QString::number((float)currentTime/CLOCKS_PER_SEC)+" Seconds" , 2000);

//      foreach (QFileInfo i, dirInput)
//        {
//          ui->document_listView->add
//        }
//      fileModel->setRootPath(currentDir);
//      ui->document_listView->setModel(fileModel);
//      ui->document_listView->setModelColumn(fileModel->columnCount()-1);
//      ui->file_textBrowser
}
void MainWindow::on_startIndex_button_clicked()
{
  QMessageBox::StandardButton  messageAnswer= QMessageBox::Yes;
  if(!dirChanged)
    {
      messageAnswer =  QMessageBox::question(this , "Default Directory" , "Directory hasn't changed!\nAre you sure you want to index the \"\\home\" directory of the program?");
    }
  if(messageAnswer == QMessageBox::Yes)
    {
      ui->Indexing_progress->setValue(0);
      ui->Indexing_progress->show();
      ui->Indexing_progress->setMaximum(0);
//      startIndex();
      currentTime = clock();
      QFuture<void> future = QtConcurrent::run(this,&MainWindow::startIndex);
      FutureWatcher.setFuture(future);
      future.waitForFinished();
    }

}
void MainWindow::slot_finished()
{
  ui->document_listView->addItems(indexedEntries);
  ui->Indexing_progress->hide();
  currentTime = clock() - currentTime;
  ui->statusbar->showMessage("Looked up :"+QString::number(numOfWords)+"words , "+QString::number(numOfLetters)+ " letters in "+ QString::number((float)currentTime/CLOCKS_PER_SEC)+" Seconds " );
}
void MainWindow::slot_finished_files()
{
//  currentProgress++;
//  ui->Indexing_progress->setValue(currentProgress);
}




void MainWindow::on_path_lineEdit_editingFinished()
{
  if(QDir(ui->path_lineEdit->text()).exists())
    {
       currentDir=ui->path_lineEdit->text();
    }
  else
    {
      QMessageBox::warning(this,"Not Found","This Directory doesn't Exist");
    }
}

void MainWindow::on_document_listView_itemDoubleClicked(QListWidgetItem *item)
{
//  QString filePath = currentDir + "\\" + item->text();
  currentFile.close();
  currentFile.setFileName(item->text());//filePath);
  currentFile.open(QFile::ReadOnly |QFile::Text);
  if(currentFile.isOpen())
    {
      ui->file_textBrowser->setText(QTextStream(&currentFile).readAll());
      QTextCharFormat fmt;
      fmt.setBackground(Qt::yellow);

      QTextCursor cursor(ui->file_textBrowser->document());
//      ui->file_textBrowser->setTextCursor(cursor);
      bool flag=true;
      cursor.setPosition(0 , QTextCursor::MoveAnchor);
      flag =cursor.movePosition(QTextCursor::EndOfWord, QTextCursor::KeepAnchor);
      do
      {
          if(cursor.selectedText().toLower() == ui->search_lineEdit->text().toLower())
            {
               cursor.setCharFormat(fmt);
            }
          flag =cursor.movePosition(QTextCursor::NextWord, QTextCursor::MoveAnchor);
          flag =cursor.movePosition(QTextCursor::EndOfWord, QTextCursor::KeepAnchor);
      }while(flag);

    }
}


void MainWindow::on_search_button_clicked()
{
  ui->file_textBrowser->clear();
  ui->document_listView->clear();
  QString query;
  query = ui->search_lineEdit->text();
  QPair<bool , QVector<unsigned int >>temp;
  temp = index.check_word(query);
  if(temp.first)
    {
      foreach (unsigned int it, temp.second)
        {
          ui->document_listView->addItem(indexedEntries.at(it));
        }
      ui->numFiles_label->show();
      ui->numFiles_label->setText("Found files :"+QString::number(temp.second.size()));
    }
  else
    {
      ui->numFiles_label->show();
      ui->numFiles_label->setText("Found files :0");
    }

}
void MainWindow::build_trie(QStringList input, int offset)
{
  unsigned int  i=0;
//  ui->Indexing_progress->show();
  foreach(QString filePath , input)
    {
      QFuture<void> future1 = QtConcurrent::run(this,&MainWindow::build_trie_oneFile,filePath,offset+i);
      FutureWatcher_files.setFuture(future1);
      future1.waitForFinished();
      ui->Indexing_progress->setValue(i);

      i++;
    }
//  ui->Indexing_progress->hide();
}
void MainWindow::build_trie_oneFile(QString path , int File_id)
{
  QFile tempFile;
  QTextStream tempStream(&tempFile);
  QString tempInput;
  tempFile.setFileName(path);
  tempFile.open(QFile::ReadOnly |QFile::Text);
  if(tempFile.isOpen())
    {
      while(!tempStream.atEnd())
        {
          tempStream>>tempInput;
          index.add_index(tempInput,File_id);
          numOfWords++;
          numOfLetters+=tempInput.length();
        }
    }
  tempFile.close();
}

void MainWindow::on_search_lineEdit_editingFinished()
{
    MainWindow::on_search_button_clicked();
}
