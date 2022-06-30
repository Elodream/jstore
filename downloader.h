#ifndef DOWNLOADER_H
#define DOWNLOADER_H

#include <QObject>
#include <QByteArray>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include<QtWidgets>
#include<iostream>

#define  SAVE 1
#define USE 0

class Downloader : public QObject
{
    Q_OBJECT
    int mode;
       QNetworkAccessManager *manager;
   std::string  m_DownloadedData;
   QNetworkReply *reply;
   public:
       Downloader(int mode);

       static bool isHttpRedirect(QNetworkReply *reply);
       void downloadfinished(QNetworkReply *reply);
       void  data(QUrl url);
       void run();
       std::string  getdata();
  /* public slots:
       void execute();
       void downloadFinished(QNetworkReply *reply);
       void sslErrors(const QList<QSslError> &errors);*/

};

class Jsmanager : public QObject
{
  Q_OBJECT
    public slots:
    void use(QString &data)
    {

       Downloader* d =new Downloader(USE);
       d->data(QUrl(data));
        QMessageBox::information(NULL,"yo",data);
       d->deleteLater();
    }
};

#endif // DOWNLOADER_H
