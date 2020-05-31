#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QString>
#include <QMessageBox>
#include <QDir>
#include <QFileSystemModel>
#include <QFile>
#include <QTextStream>
#include <QListWidget>
#include <QListWidgetItem>
#include "trie.h"
#include <QPair>
#include <QFutureWatcher>
#include <QThread>
#include <iostream>
#include <QtGui>
#include <QApplication>
#include <QObject>
#include <QtConcurrent/QtConcurrentRun>
#include <QTextCharFormat>
#include <QTextCursor>
#include <ctime>





QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();
  void build_trie(QStringList input,int offset);
  void startIndex();
  QStringList findFiles(const QString &startDir, QStringList filters) ;


private slots:
  void on_browse_button_clicked();

  void on_startIndex_button_clicked();

  void on_path_lineEdit_editingFinished();

  void on_document_listView_itemDoubleClicked(QListWidgetItem *item);

  void on_search_button_clicked();

  void on_search_lineEdit_editingFinished();
  void slot_finished();
  void slot_finished_files();

private:
  Ui::MainWindow *ui;
  clock_t currentTime;
  QString currentDir;
  QFile currentFile;
  QFileSystemModel *fileModel;
  unsigned long long numOfWords;
  unsigned long long numOfLetters;
  bool dirChanged;
  QStringList indexedEntries;
  trie index;
  QFutureWatcher<void> FutureWatcher;
  QFutureWatcher<void> FutureWatcher_files;
//  int currentProgress;
//  int currentMax;
  void build_trie_oneFile(QString path, int File_id);
};


#endif // MAINWINDOW_H
