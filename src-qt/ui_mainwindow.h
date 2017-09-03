/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionNew;
    QAction *actionSave;
    QWidget *mainLayout;
    QVBoxLayout *verticalLayout;
    QFrame *toolbar;
    QHBoxLayout *horizontalLayout;
    QToolButton *runButton;
    QToolButton *cancelButton;
    QLabel *label;
    QSpinBox *framesBox;
    QHBoxLayout *centralLayout;
    QTextEdit *code;
    QGraphicsView *output;
    QFrame *mediaBar;
    QHBoxLayout *horizontalLayout_2;
    QToolButton *playButton;
    QSlider *playhead;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(756, 470);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        QIcon icon;
        QString iconThemeName = QStringLiteral("document-open");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon = QIcon::fromTheme(iconThemeName);
        } else {
            icon.addFile(QStringLiteral("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionOpen->setIcon(icon);
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QStringLiteral("actionNew"));
        QIcon icon1;
        iconThemeName = QStringLiteral("document-new");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon1 = QIcon::fromTheme(iconThemeName);
        } else {
            icon1.addFile(QStringLiteral("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionNew->setIcon(icon1);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        QIcon icon2;
        iconThemeName = QStringLiteral("document-save");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon2 = QIcon::fromTheme(iconThemeName);
        } else {
            icon2.addFile(QStringLiteral("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionSave->setIcon(icon2);
        actionSave->setMenuRole(QAction::TextHeuristicRole);
        mainLayout = new QWidget(MainWindow);
        mainLayout->setObjectName(QStringLiteral("mainLayout"));
        verticalLayout = new QVBoxLayout(mainLayout);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        toolbar = new QFrame(mainLayout);
        toolbar->setObjectName(QStringLiteral("toolbar"));
        horizontalLayout = new QHBoxLayout(toolbar);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        runButton = new QToolButton(toolbar);
        runButton->setObjectName(QStringLiteral("runButton"));
        runButton->setBaseSize(QSize(100, 100));
        QIcon icon3(QIcon::fromTheme(QStringLiteral("view-refresh")));
        runButton->setIcon(icon3);
        runButton->setToolButtonStyle(Qt::ToolButtonIconOnly);
        runButton->setAutoRaise(false);
        runButton->setArrowType(Qt::NoArrow);

        horizontalLayout->addWidget(runButton);

        cancelButton = new QToolButton(toolbar);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setEnabled(true);
        QIcon icon4(QIcon::fromTheme(QStringLiteral("process-stop")));
        cancelButton->setIcon(icon4);

        horizontalLayout->addWidget(cancelButton);

        label = new QLabel(toolbar);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        framesBox = new QSpinBox(toolbar);
        framesBox->setObjectName(QStringLiteral("framesBox"));

        horizontalLayout->addWidget(framesBox);


        verticalLayout->addWidget(toolbar, 0, Qt::AlignLeft);

        centralLayout = new QHBoxLayout();
        centralLayout->setSpacing(6);
        centralLayout->setObjectName(QStringLiteral("centralLayout"));
        code = new QTextEdit(mainLayout);
        code->setObjectName(QStringLiteral("code"));
        code->setAcceptRichText(false);

        centralLayout->addWidget(code);

        output = new QGraphicsView(mainLayout);
        output->setObjectName(QStringLiteral("output"));

        centralLayout->addWidget(output);


        verticalLayout->addLayout(centralLayout);

        mediaBar = new QFrame(mainLayout);
        mediaBar->setObjectName(QStringLiteral("mediaBar"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(mediaBar->sizePolicy().hasHeightForWidth());
        mediaBar->setSizePolicy(sizePolicy);
        mediaBar->setLayoutDirection(Qt::LeftToRight);
        mediaBar->setFrameShape(QFrame::NoFrame);
        mediaBar->setFrameShadow(QFrame::Plain);
        horizontalLayout_2 = new QHBoxLayout(mediaBar);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        playButton = new QToolButton(mediaBar);
        playButton->setObjectName(QStringLiteral("playButton"));
        QIcon icon5(QIcon::fromTheme(QStringLiteral("media-playback-start")));
        playButton->setIcon(icon5);
        playButton->setCheckable(true);

        horizontalLayout_2->addWidget(playButton, 0, Qt::AlignLeft|Qt::AlignVCenter);

        playhead = new QSlider(mediaBar);
        playhead->setObjectName(QStringLiteral("playhead"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(playhead->sizePolicy().hasHeightForWidth());
        playhead->setSizePolicy(sizePolicy1);
        playhead->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(playhead);


        verticalLayout->addWidget(mediaBar);

        MainWindow->setCentralWidget(mainLayout);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 756, 27));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionNew);
        menuFile->addAction(actionSave);
        menuFile->addSeparator();

        retranslateUi(MainWindow);
        QObject::connect(actionOpen, SIGNAL(triggered()), MainWindow, SLOT(openFile()));
        QObject::connect(actionSave, SIGNAL(triggered()), MainWindow, SLOT(saveFile()));
        QObject::connect(actionNew, SIGNAL(triggered()), MainWindow, SLOT(newFile()));
        QObject::connect(runButton, SIGNAL(clicked()), MainWindow, SLOT(runCode()));
        QObject::connect(cancelButton, SIGNAL(clicked()), MainWindow, SLOT(stop()));
        QObject::connect(playButton, SIGNAL(clicked(bool)), MainWindow, SLOT(startPlayback(bool)));
        QObject::connect(playhead, SIGNAL(valueChanged(int)), MainWindow, SLOT(setFrame(int)));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionOpen->setText(QApplication::translate("MainWindow", "&Open", 0));
#ifndef QT_NO_STATUSTIP
        actionOpen->setStatusTip(QApplication::translate("MainWindow", "Open", 0));
#endif // QT_NO_STATUSTIP
        actionOpen->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", 0));
        actionNew->setText(QApplication::translate("MainWindow", "&New", 0));
        actionNew->setShortcut(QApplication::translate("MainWindow", "Ctrl+N", 0));
        actionSave->setText(QApplication::translate("MainWindow", "&Save", 0));
        actionSave->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", 0));
        runButton->setText(QApplication::translate("MainWindow", "Build", 0));
        cancelButton->setText(QApplication::translate("MainWindow", "Cancel", 0));
        label->setText(QApplication::translate("MainWindow", "Animation Frames:", 0));
        playButton->setText(QApplication::translate("MainWindow", "Play", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "&File", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
