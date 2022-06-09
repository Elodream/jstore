#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include <QtWebEngineWidgets/QtWebEngineWidgets>
#include"downloader.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class WebPage:public QWebEnginePage
{

};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QWebEngineView *store;
    Downloader * Ctrl;
     WebPage * storehome;
    QLabel *j;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
