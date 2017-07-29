#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include "qtcanvas.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
        Q_OBJECT

    public:
        explicit MainWindow(QWidget *parent = 0);
        ~MainWindow();
        Ui::MainWindow *ui;
        QGraphicsScene *scene;
    public slots:
        void runCode();
        void saveFile();
        void openFile();
        void newFile();
        void doneRender();
    private:
	bool confirmModify();
        AsyncRenderer *r;
};

#endif // MAINWINDOW_H
