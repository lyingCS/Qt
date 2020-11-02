#include "fileinfo.h"
#include<QHBoxLayout>
#include<QVBoxLayout>
#include<QFileDialog>
#include<QDateTime>

FileInfo::FileInfo(QWidget *parent)
    : QDialog(parent)
{
    fileNameLabel=new QLabel("File name: ");
    fileNameLineEdit=new QLineEdit;
    fileBtn=new QPushButton("File");
    sizeLabel=new QLabel("Size: ");
    sizeLineEdit=new QLineEdit;
    createTimeLabel=new QLabel("Create time: ");
    createTimeLineEdit=new QLineEdit;
    lastModifiedLabel=new QLabel("Last modified time: ");
    lastModifiedLineEdit=new QLineEdit;
    lastReadLabel=new QLabel("Last read time: ");
    lastReadLineEdit=new QLineEdit;
    propertyLabel=new QLabel("Property");
    isDirChechBox=new QCheckBox("Dir");
    isFileCheckBox=new QCheckBox("File");
    isSymLinkCheckBox=new QCheckBox("Symbel link");
    isHiddenCheckBox=new QCheckBox("Hidden");
    isReadableChechBox=new QCheckBox("Read");
    isWritableCheckBox=new QCheckBox("Write");
    isExecutableCheckBox=new QCheckBox("Execute");
    getBtn=new QPushButton("Get file message");

    QGridLayout *gridLayout=new QGridLayout;
    gridLayout->addWidget(fileNameLabel,0,0);
    gridLayout->addWidget(fileNameLineEdit,0,1);
    gridLayout->addWidget(fileBtn,0,2);
    gridLayout->addWidget(sizeLabel,1,0);
    gridLayout->addWidget(sizeLineEdit,1,1,1,2);
    gridLayout->addWidget(createTimeLabel,2,0);
    gridLayout->addWidget(createTimeLineEdit,2,1,1,2);
    gridLayout->addWidget(lastModifiedLabel,3,0);
    gridLayout->addWidget(lastModifiedLineEdit,3,1,1,2);
    gridLayout->addWidget(lastReadLabel,4,0);
    gridLayout->addWidget(lastReadLineEdit,4,1,1,2);

    QHBoxLayout *layout2=new QHBoxLayout;
    layout2->addWidget(propertyLabel);
    layout2->addStretch();
    QHBoxLayout *layout3=new QHBoxLayout;
    layout3->addWidget(isDirChechBox);
    layout3->addWidget(isFileCheckBox);
    layout3->addWidget(isSymLinkCheckBox);
    layout3->addWidget(isHiddenCheckBox);
    layout3->addWidget(isReadableChechBox);
    layout3->addWidget(isWritableCheckBox);
    layout3->addWidget(isExecutableCheckBox);
    QHBoxLayout *layout4=new QHBoxLayout;
    layout4->addWidget(getBtn);
    QVBoxLayout *mainLayout=new QVBoxLayout(this);
    mainLayout->addLayout(gridLayout);
    mainLayout->addLayout(layout2);
    mainLayout->addLayout(layout3);
    mainLayout->addLayout(layout4);
    connect(fileBtn,SIGNAL(clicked()),this,SLOT(slotFile()));
    connect(getBtn,SIGNAL(clicked()),this,SLOT(slotGet()));
}

FileInfo::~FileInfo()
{
}

void FileInfo::slotFile()
{
    QString fileName=QFileDialog::getOpenFileName(this,"Open","/","files(*)");
    fileNameLineEdit->setText(fileName);
}

void FileInfo::slotGet()
{
    QString file=fileNameLineEdit->text();
    QFileInfo info(file);
    qint64 size=info.size();
    QDateTime created=info.birthTime();

    QDateTime lastModified=info.lastModified();
    QDateTime lastRead=info.lastRead();

    bool isDir=info.isDir();
    bool isFile=info.isFile();
    bool isSymLink=info.isSymLink();
    bool isHidden=info.isHidden();
    bool isReadable=info.isReadable();
    bool isWritable=info.isWritable();
    bool isExecutable=info.isExecutable();

    sizeLineEdit->setText(QString::number(size));
    createTimeLineEdit->setText(created.toString());
    lastModifiedLineEdit->setText(lastModified.toString());
    lastReadLineEdit->setText(lastRead.toString());
    isDirChechBox->setCheckState(isDir?Qt::Checked:Qt::Unchecked);
    isFileCheckBox->setCheckState(isFile?Qt::Checked:Qt::Unchecked);
    isSymLinkCheckBox->setCheckState(isSymLink?Qt::Checked:Qt::Unchecked);
    isHiddenCheckBox->setCheckState(isHidden?Qt::Checked:Qt::Unchecked);
    isReadableChechBox->setCheckState(isReadable?Qt::Checked:Qt::Unchecked);
    isWritableCheckBox->setCheckState(isWritable?Qt::Checked:Qt::Unchecked);
    isExecutableCheckBox->setCheckState(isExecutable?Qt::Checked:Qt::Unchecked);
}



























