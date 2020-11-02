#include <QCoreApplication>
#include<QFile>
#include<QTextStream>
#include<QtDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QFile data("data.txt");
    if(data.open(QFile::WriteOnly|QFile::Truncate))
    {
        QTextStream out(&data);
        out<<"score"<<qSetFieldWidth(10)<<left<<90<<180;
    }
    return a.exec();
}
