#include "watcher.h"
#include<QVBoxLayout>
#include<QDir>
#include<QMessageBox>
#include<QApplication>

Watcher::Watcher(QWidget *parent)
    : QWidget(parent)
{
    QStringList args=qApp->arguments();
    QString path;
    if(args.count()>1)
    {
        path=args[1];
    }
    else
    {
        path=QDir::currentPath();
    }
    pathLabel=new QLabel;
    pathLabel->setText("Watcher dir: "+path);
    QVBoxLayout *mainLayout=new QVBoxLayout(this);

    mainLayout->addWidget(pathLabel);
    fsWatcher.addPath(path);
    connect(&fsWatcher,SIGNAL(directoryChanged(QString)),this,SLOT(directoryChanged(QString)));
}

Watcher::~Watcher()
{
}

void Watcher::directoryChanged(QString path)
{
    QMessageBox::information(NULL,"Dir changed",path);
}
