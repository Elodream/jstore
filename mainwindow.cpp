#include "mainwindow.h"
#include "downloader.h"
#include "ui_mainwindow.h"
#include<QtWebChannel/QtWebChannel>
#include<windows.h>
#include<iostream>

typedef bool(__stdcall *Func)(std::string  , std::string);

class Webpage:public QWebEnginePage
{

};





MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)

{

    AllocConsole();
    SetConsoleTitle(TEXT("Jstore"));
    freopen("CONOUT$", "wt", stdout);
    freopen("CONIN$", "rt", stdin);

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);


   QTabWidget * wintab=new QTabWidget;
   wintab->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
   this->setCentralWidget(wintab);
   this->setMinimumSize(700,700);
   this->resize(780,700);
   this->setAcceptDrops(true);
   Ctrl = new Downloader(USE);
   Ctrl->data(QUrl("http://127.0.0.1:8000/bucket/storefile/index.js"));
std::string fc=Ctrl->getdata();

  store=new QWebEngineView(wintab);
  store->setContextMenuPolicy(Qt::NoContextMenu);

 wintab->addTab(store, "store");

  wintab->addTab(new QLabel("yo" ), "my download");
  store->setUrl(QUrl("http://127.0.0.1:8000/store/"));
  store->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
  store->page()->profile()->setHttpUserAgent("jstore");

  Jsmanager *jsmanager = new Jsmanager;
  QWebChannel *channel = new QWebChannel(this);
  channel->registerObject("jsmanager", jsmanager);
  store->page()->setWebChannel(channel);

}

MainWindow::~MainWindow()
{
    delete ui;
}

