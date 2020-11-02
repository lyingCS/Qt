#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("SVG Viewer");
    createMenu();
    svgWindow=new SvgWindow;
    setCentralWidget(svgWindow);
}

MainWindow::~MainWindow()
{
}

void MainWindow::createMenu()
{
    QMenu *fileMenu=menuBar()->addMenu("File");
    QAction *openAct=new QAction("Open",this);
    connect(openAct,SIGNAL(triggered()),this,SLOT(slotOpenFile()));
    fileMenu->addAction(openAct);
}

void MainWindow::slotOpenFile()
{
    QString name=QFileDialog::getOpenFileName(this,"Open","/","svg files(*.svg)");
    svgWindow->setFile(name);
}
























