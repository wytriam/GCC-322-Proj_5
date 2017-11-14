/********************************************************************************
** Form generated from reading UI file 'HW5_Starter.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HW5_STARTER_H
#define UI_HW5_STARTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HW5_StarterClass
{
public:
    QAction *actionOpen;
    QAction *actionExit;
    QWidget *centralWidget;
    QLabel *pictureLabel;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *HW5_StarterClass)
    {
        if (HW5_StarterClass->objectName().isEmpty())
            HW5_StarterClass->setObjectName(QStringLiteral("HW5_StarterClass"));
        HW5_StarterClass->resize(1024, 860);
        actionOpen = new QAction(HW5_StarterClass);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionExit = new QAction(HW5_StarterClass);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        centralWidget = new QWidget(HW5_StarterClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pictureLabel = new QLabel(centralWidget);
        pictureLabel->setObjectName(QStringLiteral("pictureLabel"));
        pictureLabel->setGeometry(QRect(10, 10, 1001, 551));
        pictureLabel->setFrameShape(QFrame::WinPanel);
        HW5_StarterClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(HW5_StarterClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1024, 31));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        HW5_StarterClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(HW5_StarterClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        HW5_StarterClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(HW5_StarterClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        HW5_StarterClass->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);

        retranslateUi(HW5_StarterClass);
        QObject::connect(actionExit, SIGNAL(triggered()), HW5_StarterClass, SLOT(close()));
        QObject::connect(actionOpen, SIGNAL(triggered()), HW5_StarterClass, SLOT(loadFile()));
        QObject::connect(HW5_StarterClass, SIGNAL(sendPixmap(QPixmap)), pictureLabel, SLOT(setPixmap(QPixmap)));

        QMetaObject::connectSlotsByName(HW5_StarterClass);
    } // setupUi

    void retranslateUi(QMainWindow *HW5_StarterClass)
    {
        HW5_StarterClass->setWindowTitle(QApplication::translate("HW5_StarterClass", "HW5_Starter", Q_NULLPTR));
        actionOpen->setText(QApplication::translate("HW5_StarterClass", "Open File...", Q_NULLPTR));
        actionExit->setText(QApplication::translate("HW5_StarterClass", "Exit", Q_NULLPTR));
        pictureLabel->setText(QString());
        menuFile->setTitle(QApplication::translate("HW5_StarterClass", "File", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class HW5_StarterClass: public Ui_HW5_StarterClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HW5_STARTER_H
