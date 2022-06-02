#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

   QTabWidget * wintab=new QTabWidget;
   this->setCentralWidget(wintab);
 wintab->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
  store=new QWebEngineView(wintab);
 wintab->addTab(store,"store");
 j=new QLabel("hhh",wintab);
 wintab->addTab(j,"my apps");
 store->setUrl(QUrl("https://docs.python.org/3/extending/embedding.html"));
 store->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);


}

MainWindow::~MainWindow()
{
    delete ui;
}

