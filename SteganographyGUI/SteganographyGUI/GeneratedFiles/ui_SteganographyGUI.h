/********************************************************************************
** Form generated from reading UI file 'SteganographyGUI.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STEGANOGRAPHYGUI_H
#define UI_STEGANOGRAPHYGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "secretmessagetextedit.hpp"

QT_BEGIN_NAMESPACE

class Ui_SteganographyGUIClass
{
public:
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionClose;
    QAction *actionExit;
    QWidget *centralWidget;
    QLabel *imageLabel;
    SecretMessageTextEdit *messageBox;
    QPushButton *readButton;
    QPushButton *writeButton;
    QLabel *charAvailableLabel;
    QLabel *charRemainingLabel;
    QMenuBar *menuBar;
    QMenu *menuMenu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *SteganographyGUIClass)
    {
        if (SteganographyGUIClass->objectName().isEmpty())
            SteganographyGUIClass->setObjectName(QStringLiteral("SteganographyGUIClass"));
        SteganographyGUIClass->resize(974, 734);
        actionOpen = new QAction(SteganographyGUIClass);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionSave = new QAction(SteganographyGUIClass);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionClose = new QAction(SteganographyGUIClass);
        actionClose->setObjectName(QStringLiteral("actionClose"));
        actionExit = new QAction(SteganographyGUIClass);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        centralWidget = new QWidget(SteganographyGUIClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        imageLabel = new QLabel(centralWidget);
        imageLabel->setObjectName(QStringLiteral("imageLabel"));
        imageLabel->setGeometry(QRect(80, 10, 791, 471));
        imageLabel->setFrameShape(QFrame::WinPanel);
        imageLabel->setAlignment(Qt::AlignCenter);
        messageBox = new SecretMessageTextEdit(centralWidget);
        messageBox->setObjectName(QStringLiteral("messageBox"));
        messageBox->setGeometry(QRect(80, 540, 661, 107));
        readButton = new QPushButton(centralWidget);
        readButton->setObjectName(QStringLiteral("readButton"));
        readButton->setGeometry(QRect(760, 540, 112, 34));
        writeButton = new QPushButton(centralWidget);
        writeButton->setObjectName(QStringLiteral("writeButton"));
        writeButton->setGeometry(QRect(760, 610, 112, 34));
        charAvailableLabel = new QLabel(centralWidget);
        charAvailableLabel->setObjectName(QStringLiteral("charAvailableLabel"));
        charAvailableLabel->setGeometry(QRect(80, 510, 221, 19));
        charRemainingLabel = new QLabel(centralWidget);
        charRemainingLabel->setObjectName(QStringLiteral("charRemainingLabel"));
        charRemainingLabel->setGeometry(QRect(540, 510, 251, 19));
        SteganographyGUIClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(SteganographyGUIClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 974, 31));
        menuMenu = new QMenu(menuBar);
        menuMenu->setObjectName(QStringLiteral("menuMenu"));
        SteganographyGUIClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(SteganographyGUIClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        SteganographyGUIClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(SteganographyGUIClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        SteganographyGUIClass->setStatusBar(statusBar);

        menuBar->addAction(menuMenu->menuAction());
        menuMenu->addAction(actionOpen);
        menuMenu->addAction(actionSave);
        menuMenu->addSeparator();
        menuMenu->addAction(actionClose);
        menuMenu->addAction(actionExit);

        retranslateUi(SteganographyGUIClass);
        QObject::connect(actionExit, SIGNAL(triggered()), SteganographyGUIClass, SLOT(close()));
        QObject::connect(actionOpen, SIGNAL(triggered()), SteganographyGUIClass, SLOT(openBMP()));
        QObject::connect(SteganographyGUIClass, SIGNAL(sendPixmap(QPixmap)), imageLabel, SLOT(setPixmap(QPixmap)));
        QObject::connect(actionClose, SIGNAL(triggered()), SteganographyGUIClass, SLOT(closeBMP()));
        QObject::connect(readButton, SIGNAL(clicked()), SteganographyGUIClass, SLOT(readBMP()));
        QObject::connect(SteganographyGUIClass, SIGNAL(readMessage(QString)), messageBox, SLOT(setText(QString)));
        QObject::connect(SteganographyGUIClass, SIGNAL(setCharactersAvailable(QString)), charAvailableLabel, SLOT(setText(QString)));
        QObject::connect(writeButton, SIGNAL(clicked()), messageBox, SLOT(sendTextSlot()));
        QObject::connect(messageBox, SIGNAL(sendTextSignal(QString)), SteganographyGUIClass, SLOT(writeBMP(QString)));
        QObject::connect(actionSave, SIGNAL(triggered()), SteganographyGUIClass, SLOT(saveBMP()));
        QObject::connect(messageBox, SIGNAL(textChanged()), messageBox, SLOT(sendUpdateSlot()));
        QObject::connect(SteganographyGUIClass, SIGNAL(updateCharRemaining(QString)), charRemainingLabel, SLOT(setText(QString)));
        QObject::connect(messageBox, SIGNAL(sendUpdateSignal(QString)), SteganographyGUIClass, SLOT(updateCharRemainingSlot(QString)));

        QMetaObject::connectSlotsByName(SteganographyGUIClass);
    } // setupUi

    void retranslateUi(QMainWindow *SteganographyGUIClass)
    {
        SteganographyGUIClass->setWindowTitle(QApplication::translate("SteganographyGUIClass", "SteganographyGUI", Q_NULLPTR));
        actionOpen->setText(QApplication::translate("SteganographyGUIClass", "Open...", Q_NULLPTR));
        actionSave->setText(QApplication::translate("SteganographyGUIClass", "Save...", Q_NULLPTR));
        actionClose->setText(QApplication::translate("SteganographyGUIClass", "Close", Q_NULLPTR));
        actionExit->setText(QApplication::translate("SteganographyGUIClass", "Exit", Q_NULLPTR));
        imageLabel->setText(QApplication::translate("SteganographyGUIClass", "Please use the menu to load an image", Q_NULLPTR));
        readButton->setText(QApplication::translate("SteganographyGUIClass", "Read", Q_NULLPTR));
        writeButton->setText(QApplication::translate("SteganographyGUIClass", "Write", Q_NULLPTR));
        charAvailableLabel->setText(QApplication::translate("SteganographyGUIClass", "Characters Available: ", Q_NULLPTR));
        charRemainingLabel->setText(QApplication::translate("SteganographyGUIClass", "Characters Remaining:", Q_NULLPTR));
        menuMenu->setTitle(QApplication::translate("SteganographyGUIClass", "Menu", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SteganographyGUIClass: public Ui_SteganographyGUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STEGANOGRAPHYGUI_H
