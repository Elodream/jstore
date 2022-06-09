#ifndef DOWNLOADER_H
#define DOWNLOADER_H

#include <QObject>
#include <QByteArray>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>

class Downloader : public QObject
{
    Q_OBJECT

       QNetworkAccessManager *manager;
   QByteArray  m_DownloadedData;
   QNetworkReply *reply;
   public:
       Downloader();
       //void download( QUrl url);
       static QString saveFileName(const QUrl &url);
       bool saveToDisk(const QString &filename, QIODevice *data);
       static bool isHttpRedirect(QNetworkReply *reply);
void onResult(QNetworkReply *reply);
       void  data(QUrl url);
  /* public slots:
       void execute();
       void downloadFinished(QNetworkReply *reply);
       void sslErrors(const QList<QSslError> &errors);*/

};

#endif // DOWNLOADER_H
