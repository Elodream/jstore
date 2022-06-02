
#include <QApplication>
#include "mainwindow.h"


int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    QFile file("default.css");
    file.open(QFile::ReadOnly);
    QString stylesheet = QLatin1String(file.readAll());
    file.close();
    a.setStyleSheet(stylesheet);
    MainWindow main;
    main.show();

    return a.exec();
}
