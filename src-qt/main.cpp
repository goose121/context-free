#include "mainwindow.h"
#include "cfdg_highlighter.h"
#include <QApplication>
#include <QTextEdit>
#include <QStringList>
#include <QtDebug>

QDebug operator<<(QDebug out, const std::string& str)
{
    out << QString::fromStdString(str);
    return out;
}

int main(int argc, char *argv[])
{
    if (QIcon::themeName() == "") {
        // TODO: Add a toggle for this somewhere
        QIcon::setThemeSearchPaths((QStringList) {"/usr/share/icons"});
        QIcon::setThemeName("Adwaita");
    }
    QApplication a(argc, argv);
    MainWindow w;
    QTextEdit *editor = w.findChild<QTextEdit*>("code");
    cfdg_highlighter highlighter(editor->document());
    w.setWindowTitle("New Document - ContextFree");
    w.show();
    return a.exec();
}
