/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *browse_button;
    QLineEdit *path_lineEdit;
    QPushButton *startIndex_button;
    QLabel *numFiles_label;
    QHBoxLayout *horizontalLayout_3;
    QListWidget *document_listView;
    QTextEdit *file_textBrowser;
    QHBoxLayout *horizontalLayout;
    QLineEdit *search_lineEdit;
    QPushButton *search_button;
    QProgressBar *Indexing_progress;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        browse_button = new QPushButton(centralwidget);
        browse_button->setObjectName(QString::fromUtf8("browse_button"));

        horizontalLayout_2->addWidget(browse_button);

        path_lineEdit = new QLineEdit(centralwidget);
        path_lineEdit->setObjectName(QString::fromUtf8("path_lineEdit"));

        horizontalLayout_2->addWidget(path_lineEdit);

        startIndex_button = new QPushButton(centralwidget);
        startIndex_button->setObjectName(QString::fromUtf8("startIndex_button"));

        horizontalLayout_2->addWidget(startIndex_button);


        verticalLayout->addLayout(horizontalLayout_2);

        numFiles_label = new QLabel(centralwidget);
        numFiles_label->setObjectName(QString::fromUtf8("numFiles_label"));

        verticalLayout->addWidget(numFiles_label);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        document_listView = new QListWidget(centralwidget);
        document_listView->setObjectName(QString::fromUtf8("document_listView"));

        horizontalLayout_3->addWidget(document_listView);

        file_textBrowser = new QTextEdit(centralwidget);
        file_textBrowser->setObjectName(QString::fromUtf8("file_textBrowser"));

        horizontalLayout_3->addWidget(file_textBrowser);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        search_lineEdit = new QLineEdit(centralwidget);
        search_lineEdit->setObjectName(QString::fromUtf8("search_lineEdit"));

        horizontalLayout->addWidget(search_lineEdit);

        search_button = new QPushButton(centralwidget);
        search_button->setObjectName(QString::fromUtf8("search_button"));

        horizontalLayout->addWidget(search_button);


        verticalLayout->addLayout(horizontalLayout);

        Indexing_progress = new QProgressBar(centralwidget);
        Indexing_progress->setObjectName(QString::fromUtf8("Indexing_progress"));
        Indexing_progress->setValue(24);
        Indexing_progress->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout->addWidget(Indexing_progress);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        browse_button->setText(QCoreApplication::translate("MainWindow", "Browse", nullptr));
        startIndex_button->setText(QCoreApplication::translate("MainWindow", "Index", nullptr));
        numFiles_label->setText(QCoreApplication::translate("MainWindow", "Found Files :", nullptr));
        search_button->setText(QCoreApplication::translate("MainWindow", "Search", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
