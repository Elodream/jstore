#include "mainwindow.h"
#include "downloader.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

   QTabWidget * wintab=new QTabWidget;
   wintab->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
   this->setCentralWidget(wintab);

   this->setMinimumSize(700,700);
   this->resize(780,700);
 Ctrl = new Downloader();
Ctrl->data(QUrl("http://127.0.0.1:8000/bucket/storefile/index.js"));
  store=new QWebEngineView(wintab);
  store->setContextMenuPolicy(Qt::NoContextMenu);
  this->setAcceptDrops(true);
 wintab->addTab(store, "store");

  wintab->addTab(new QLabel("yo" ), "my download");
  store->setUrl(QUrl("http://127.0.0.1:8000/store/"));
  store->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
  store->page()->profile()->setHttpUserAgent("jstore");

}

MainWindow::~MainWindow()
{
    delete ui;
}

