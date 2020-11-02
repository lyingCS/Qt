#include "dockwindows.h"
#include<QTextEdit>
#include<QDockWidget>

DockWindows::DockWindows(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle(tr("DockWindows"));
    QTextEdit *te=new QTextEdit(this);
    te->setText(tr("Main windows"));
    te->setAlignment(Qt::AlignCenter);
    setCentralWidget(te);

    QDockWidget *dock=new QDockWidget(tr("DocWindow1"),this);
    dock->setFeatures(QDockWidget::DockWidgetMovable);
    dock->setAllowedAreas(Qt::LeftDockWidgetArea|Qt::RightDockWidgetArea);
    QTextEdit *te1=new QTextEdit();
    te1->setText(tr("Windows1,The dock widget can be moved between docks by the user" ""));
    dock->setWidget(te1);
    addDockWidget(Qt::RightDockWidgetArea,dock);

    dock=new QDockWidget(tr("DockWindows2"),this);
    dock->setFeatures(QDockWidget::DockWidgetClosable|QDockWidget::DockWidgetFloatable);
    QTextEdit*te2=new QTextEdit();
    te2->setText(tr("Window2,The dock widget can be detached from the main window," "and float as an independent window, and can be closed"));
    dock->setWidget(te2);
    addDockWidget(Qt::RightDockWidgetArea,dock);

    dock=new QDockWidget(tr("DockWindows3"),this);
    dock->setFeatures(QDockWidget::AllDockWidgetFeatures);
    QTextEdit *te3=new QTextEdit();
    te3->setText(tr("Windows3,The dock widget can be closed, moved, and floated"));
    dock->setWidget(te3);
    addDockWidget(Qt::RightDockWidgetArea,dock);
}

DockWindows::~DockWindows()
{
}

