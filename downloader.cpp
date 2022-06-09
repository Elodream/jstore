#include "downloader.h"
#include<QtWidgets>
Downloader::Downloader()
{
    // Initialize manager ...
    manager = new QNetworkAccessManager();
    // ... and connect the signal to the handler
    connect(manager, &QNetworkAccessManager::finished, this, &Downloader::onResult);
}

void Downloader::data(QUrl url)
{

    QNetworkRequest request;
    request.setUrl(url);
    manager->get(request);

}

void Downloader::onResult(QNetworkReply *reply)
{
   m_DownloadedData=reply->readAll();
   QMessageBox a (QMessageBox::NoIcon,"yo",m_DownloadedData);
   a.exec();
}
