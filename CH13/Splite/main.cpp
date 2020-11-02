#include <QCoreApplication>
#include<QTextCodec>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QTime>
#include<QElapsedTimer>
#include<QSqlError>
#include<QtDebug>
#include<QSqlDriver>
#include<QSqlRecord>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QTextCodec::setCodecForLocale(QTextCodec::codecForLocale());
    QSqlDatabase db=QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName("easybook-3313b0");
    db.setDatabaseName("qtDB.db");
    db.setUserName("zcs");
    db.setPassword("010Zcs902");
    db.open();

    QSqlQuery query;
    bool success=query.exec("create table automobile"
                            "(id int priamry key,"
                            "attribute varchar,"
                            "type varchar,"
                            "kind varchar,"
                            "nation int,"
                            "carnumber int,"
                            "elevaltor int,"
                            "distance int,"
                            "oil int,"
                            "temperature int)");
    if(success)
        qDebug()<<QObject::tr("Data table create successfully");
    else
        qDebug()<<QObject::tr("Data table create failed");
    query.exec("select * from automobile");
    QSqlRecord rec=query.record();
    qDebug()<<QObject::tr("automobile table field number: ")<<rec.count();
    QElapsedTimer t;
    t.start();
    query.prepare("insert into automobile values(?,?,?,?,?,?,?,?,?,?)");
    long records=100;
    for(int i=0;i<records;i++)
    {
        query.bindValue(0,i);
        query.bindValue(1,"foul-wheeled");
        query.bindValue(2,"car");
        query.bindValue(3,"fukang");
        query.bindValue(4,rand()%100);
        query.bindValue(5,rand()%10000);
        query.bindValue(6,rand()%300);
        query.bindValue(7,rand()%200000);
        query.bindValue(8,rand()%52);
        query.bindValue(9,rand()%100);
        success=query.exec();
        if(!success)
        {
            QSqlError lastError=query.lastError();
            qDebug()<<lastError.driverText()<<QString(QObject::tr("insert failed"));
        }
    }
    qDebug()<<QObject::tr("insert %1 records, use time: %2ms").arg(records).arg(t.elapsed());
    t.restart();
    success=query.exec("select *from automobile order by id desc");

    if(success)
        qDebug()<<QObject::tr("sort %1 records, use time %2ms").arg(records).arg(t.elapsed());
    else
        qDebug()<<QObject::tr("sort failed");
    t.restart();
    for(int i=0;i<records;i++)
    {
        query.clear();
        query.prepare(QString("update automobile set attribute=?,type=?"
                              "kind=?,nation=?,"
                              "carnumber=?,elevaltor=?,"
                              "distance=?,oil=?,"
                              "temperature=? where id=%1").arg(i));
        query.bindValue(0,"foul_wheels");
        query.bindValue(1,"car");
        query.bindValue(2,"fukang");
        query.bindValue(3,rand()%100);
        query.bindValue(4,rand()%10000);
        query.bindValue(5,rand()%300);
        query.bindValue(6,rand()%200000);
        query.bindValue(7,rand()%52);
        query.bindValue(8,rand()%100);
        success=query.exec();
        if(!success)
        {
            QSqlError lastError=query.lastError();
            qDebug()<<lastError.driverText()<<QString(QObject::tr("update failed"));
        }
    }
    qDebug()<<QObject::tr("update %1 records, use time: %2 ms").arg(records).arg(t.elapsed());
    t.restart();
    query.exec("delete from automobile where id=15");
    qDebug()<<QObject::tr("delete one record, use time: %1 ms").arg(t.elapsed());
    return 0;
    //return a.exec();
}




































