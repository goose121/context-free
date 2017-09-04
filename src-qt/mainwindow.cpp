#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <errno.h>
#include <cfdg.h>
#include <fstream>
#include <unistd.h>
#include <sys/stat.h>
#include <variation.h>
#include <cstdio>
#include "cf-util.h"
#include <commandLineSystem.h>
#include <QtDebug>
#include <QGraphicsItem>
#include <pthread.h>
#include <QGraphicsEllipseItem>
#include <QFileDialog>
#include <QDir>
#include <QMessageBox>
#include <QtConcurrent/QtConcurrent>
#include "qtcanvas.h"

// File i/o
inline QString readFileFromDisk(QString fname) {
    QFile file(fname);
    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(this, tr("Unable to open file for read"),
                                 file.errorString());
        return;
    }
    return file.readAll();
}

inline void writeStringToDisk(QString fname, QString ostring) {
    QFile file(fname);
    if (!file.open(QIODevice::WriteOnly)) {
        QMessageBox::information(this, tr("Unable to open file for write"),
                                 file.errorString());
        return;
    }
    QTextStream ostream(&file);
    ostream << ostring;
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);
    ui->cancelButton->setVisible(false);
    ui->mediaBar->setVisible(false);
    ui->code->setStyleSheet("font: 12px monospace");
    ui->output->setRenderHint(QPainter::Antialiasing);
    ui->output->setTransform(ui->output->transform().scale(1, -1));
    scene = new QGraphicsScene(this);
    ui->output->setScene(scene);
    ui->framesBox->setValue(1);
    ui->framesBox->setRange(1, 1000000);
    t.setInterval(1000/30);
    connect(&t, SIGNAL(timeout()), this, SLOT(incFrame()));
}

MainWindow::~MainWindow() {
    delete ui;
}

bool MainWindow::confirmModify() {

    if(!this->currentFile.isEmpty()) {
        QFile file(this->currentFile);
        if (!file.open(QIODevice::ReadOnly)) {
            QMessageBox::information(this, tr("Unable to open file for read"),
                                     file.errorString());
            return;
        }
        QTextStream istream(file);


        if ()
    }

    QMessageBox box;
    box.setText("You have unsaved changes which may be lost.");
    box.setInformativeText("Save your changes?");
    box.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
    box.setDefaultButton(QMessageBox::Save);
    int button = box.exec();
    switch(button) {
    case QMessageBox::Save:
        // save file and continue dangerous action
        this->saveFileAsAction();
        return true;
        break;
    case QMessageBox::Discard:
        // don't save file, but continue dangerous action
        return true;
        break;
    case QMessageBox::Cancel:
        // abort dangerous action
        return false;
        break;
    default:
        // this should never happen, unless I'm a grapefruit
        gerr("Unrecognized button! Aborting...");
        // Don't do it if you don't know what they said
        return false;
    }
}

void MainWindow::runCode() {

    this->saveFile();

    QGraphicsScene *tempScene = new QGraphicsScene(this);
    this->scene = tempScene;
    if(r != NULL)
        delete r;

    std::shared_ptr<QtCanvas> canv(new QtCanvas(ui->output->width(), ui->output->height()));
    ui->cancelButton->setVisible(true);
    ui->runButton->setDisabled(true);
    ui->mediaBar->setVisible(false);
    t.stop();
    r = new AsyncRenderer(ui->output->width(), ui->output->height(), ui->framesBox->value(), canv, this);
    connect(r, SIGNAL(done()), this, SLOT(doneRender()));
    connect(r, SIGNAL(aborted()), this, SLOT(abortRender()));
    connect(r, SIGNAL(updateRect()), this, SLOT(updateRect()));

    //qDebug() << ui->output->items() << endl;
}

void MainWindow::openFile() {
    qDebug() << "Open file" << endl;
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open file"), "", tr("CFDG file (*.cfdg);;All Files (*)"));
    if (fileName.isEmpty())
        return;
    else {
        QDir::setCurrent(QFileInfo( QFile(fileName) ).dir());

        this->setWindowTitle(fileName.remove(0, fileName.lastIndexOf("/")+1) + " - ContextFree");
        this->currentFile = fileName;

        QString file = readFileFromDisk(fileName);

        ui->code->document()->clearUndoRedoStacks();
        ui->code->document()->setPlainText(file);
    }
}

void MainWindow::saveFile() {
    if(this->currentFile.isEmpty())
        this->saveFileAs();
    else
        writeFileToDisk(this->currentFile, ui->code->document()->toPlainText());
}

void MainWindow::newFile() {
    ui->code->document()->clearUndoRedoStacks();
    ui->code->document()->setPlainText("");
    this->currentFile = "";
    this->setWindowTitle("New Document - ContextFree");
}

void MainWindow::saveFileAs() {

    QString fileName = QFileDialog::getSaveFileName(this, tr("Save file"), "", tr("CFDG file (*.cfdg);;All Files (*)"));

    if (fileName.isNull()) // User selected "Cancel"
        return;
    else {
        writeFileToDisk(fileName, ui->code->document()->toPlainText());
        QDir::setCurrent(QFileInfo( QFile(fileName) ).dir());
    }
}

void MainWindow::openFileAction() {
    if(!confirmModify())
        return;
    this->openFile();
}

void MainWindow::saveFileAction() {
    this->saveFile();
}

void MainWindow::saveFileAsAction() {
    this->saveFileAs();
}

void MainWindow::newFileAction() {
    if(!confirmModify())
        return;
    this->newFile();
}

void MainWindow::doneRender() {
    qDebug() << "Done rendering";

    ui->cancelButton->setVisible(false);
    ui->runButton->setEnabled(true);
    ui->mediaBar->setVisible(true);
    QGraphicsScene *temp = scene;
    r->frameIndex = 0;
    scene = r->getScenes()[0].get();
    ui->output->setScene(scene);
    ui->playhead->setMaximum(r->frameCount());
    delete temp;
}

void MainWindow::stop() {
    r->cleanup();
}

void MainWindow::abortRender() {
    qDebug() << "Aborted rendering";

    if(r != NULL) {
        delete r;
        r = NULL;
    }
    ui->cancelButton->setVisible(false);
    ui->runButton->setEnabled(true);
    ui->runButton->setText("Build");
}

void MainWindow::showmsg(const char* msg) {
    ui->statusBar->showMessage(msg, 1000);
    delete msg;
}

void MainWindow::updateRect() {
    QRectF ibr = scene->itemsBoundingRect();
    ui->output->setSceneRect(ibr);
    scene->setSceneRect(ibr);
}

void MainWindow::startPlayback(bool shouldPlay) {
    if(shouldPlay)
        t.start();
    else
        t.stop();
}

void MainWindow::incFrame() {
    vector<unique_ptr<QGraphicsScene> > &scenes = r->getScenes();
    if(++(r->frameIndex) < scenes.size()) {
        scene = scenes[r->frameIndex].get();
        ui->output->setScene(scene);
        ui->playhead->setValue(r->frameIndex);
        qDebug() << "Show frame " << r->frameIndex << " of " << r->frameCount();
    } else
        t.stop();
}

void MainWindow::setFrame(int frame) {
    vector<unique_ptr<QGraphicsScene> > &scenes = r->getScenes();
    if(frame < scenes.size()) {
        r->frameIndex = frame;
        scene = scenes[r->frameIndex].get();
        ui->output->setScene(scene);
    }
}
