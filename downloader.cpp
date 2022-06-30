#include "downloader.h"
#include<QtWidgets>


void Downloader::run()
{

}
Downloader::Downloader(int mode)
{
    this->mode=mode;
    manager = new QNetworkAccessManager();
    // ... and connect the signal to the handler
    connect(manager, &QNetworkAccessManager::finished, this, &Downloader::downloadfinished);

}


void Downloader::data(QUrl url)
{

    QNetworkRequest request;
    request.setUrl(url);
    manager->get(request);

}

void Downloader::downloadfinished(QNetworkReply *reply)
{

   auto fdata=reply->readAll();

   QTemporaryFile f;
f.setAutoRemove(false);
   if(f.open())
   {
      f.write(fdata);
    f.seek(0);
   }
 f.close();
std::cout<<fdata.toStdString();

   if(mode==USE)
   {
       QProcess * process = new QProcess(this->parent());
           QString file = "emu/jsinfinity/shell.exe";

        process->setProcessChannelMode(QProcess::MergedChannels);

           process->startDetached(file,{f.fileName()});
     //auto n=_execlp("emu/jsinfinity/shell.exe","emu/jsinfinity/shell.exe",f.fileName().toStdString().c_str(),NULL);
           std::cout<<process->readLine().toStdString();
   }
   else if(mode==SAVE)
   {

   }

    reply->deleteLater();

}

std::string  Downloader::getdata()
{

     return this->m_DownloadedData;
}
