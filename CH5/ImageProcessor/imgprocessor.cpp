#include "imgprocessor.h"
#include<QApplication>
#include<QPixmap>
#include<QFileDialog>
#include<QFile>
#include<QTextStream>
#include<QPainter>
#include<QtPrintSupport/QPrinter>
#include<QtPrintSupport/QPrintDialog>
#include<QColor>
#include<QColorDialog>
#include<QTextList>
#include<QTextCodec>

ImgProcessor::ImgProcessor(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle(tr("Easy Word"));
    showWidget=new ShowWidget(this);
    setCentralWidget(showWidget);

    listLabel=new QLabel("Sort");
    listComboBox=new QComboBox;
    listComboBox->addItem("Standard");
    listComboBox->addItem("QtextListFormat::ListDisc");
    listComboBox->addItem("QtextListFormat::ListCircle");
    listComboBox->addItem("QtextListFormat::ListSquare");
    listComboBox->addItem("QtextListFormat::ListDecimal");
    listComboBox->addItem("QtextListFormat::ListLowerAlpha");
    listComboBox->addItem("QtextListFormat::ListUpperAlpha");
    listComboBox->addItem("QtextListFormat::ListLowerRoman");
    listComboBox->addItem("QtextListFormat::ListUpperRoman");

    fontLabel1=new QLabel(tr("Typeface"));
    fontComboBox=new QFontComboBox;
    fontComboBox->setFontFilters(QFontComboBox::ScalableFonts);
    fontLabel2=new QLabel(tr("Typesize"));
    sizeComboBox=new QComboBox;
    QFontDatabase db;
    foreach(int size,db.standardSizes())
        sizeComboBox->addItem(QString::number(size));
    boldBtn=new QToolButton;
    boldBtn->setIcon(QIcon("1.png"));
    boldBtn->setCheckable(true);
    italicBtn=new QToolButton;
    italicBtn->setIcon(QIcon("2.png"));
    italicBtn->setCheckable(true);
    underlineBtn=new QToolButton;
    underlineBtn->setIcon(QIcon("3.png"));
    underlineBtn->setCheckable(true);
    colorBtn=new QToolButton;
    colorBtn->setIcon(QIcon("4.png"));
    colorBtn->setCheckable(true);
    createAction();
    createMenus();
    createToolBars();
    if(img.load("11.jpg"))
    {
        showWidget->imageLabel->setPixmap(QPixmap::fromImage(img));
    }

    connect(fontComboBox,SIGNAL(activated(QString)),this,SLOT(ShowFontComboBox(QString)));
    connect(sizeComboBox,SIGNAL(activated(QString)),this,SLOT(ShowSizeSpinBox(QString)));
    connect(boldBtn,SIGNAL(clicked()),this,SLOT(ShowBoldBtn()));
    connect(italicBtn,SIGNAL(clicked()),this,SLOT(ShowItalicBtn()));
    connect(underlineBtn,SIGNAL(clicked()),this,SLOT(ShowUnderlineBtn()));
    connect(colorBtn,SIGNAL(clicked()),this,SLOT(ShowColorBtn()));
    connect(showWidget->text,SIGNAL(currentCharFormatChanged(const QTextCharFormat &)),this,
            SLOT(ShowCurrentFormatChanged(const QTextCharFormat&)));

    connect(listComboBox,SIGNAL(activated(int)),this,SLOT(ShowList(int)));
    connect(showWidget->text->document(),SIGNAL(undoAvailable(bool)),redoAction,SLOT(setEnabled(bool)));
    connect(showWidget->text->document(),SIGNAL(redoAvailable(bool)),redoAction,SLOT(setEnabled(bool)));
    connect(showWidget->text,SIGNAL(cursorPositionChanged()),this,SLOT(ShowCursorPositionChanged()));
}

ImgProcessor::~ImgProcessor()
{
}

void ImgProcessor::createAction()
{
    openFileAction=new QAction(QIcon("12.jpg"),tr("Open"),this);
    openFileAction->setShortcut(tr("Ctrl+O"));
    openFileAction->setStatusTip(tr("Open a file"));
    connect(openFileAction,SIGNAL(triggered()),this,SLOT(ShowOpenFile()));

    NewFileAction=new QAction(QIcon("13.jpg"),tr("New"),this);
    NewFileAction->setShortcut(tr("Ctrl+N"));
    NewFileAction->setStatusTip(tr("Create a new file"));
    connect(NewFileAction,SIGNAL(triggered()),this,SLOT(ShowNewFile()));

    exitAction=new QAction(QIcon("14.jpg"),tr("Exit"),this);
    exitAction->setShortcut(tr("Ctrl+Q"));
    exitAction->setStatusTip(tr("Exit the program"));
    connect(exitAction,SIGNAL(triggered()),this,SLOT(close()));

    copyAction=new QAction(QIcon("15.jpg"),tr("Copy"),this);
    copyAction->setShortcut(tr("Ctrl+C"));
    copyAction->setStatusTip(tr("Copy the file"));
    connect(copyAction,SIGNAL(triggered()),showWidget->text,SLOT(copy()));

    cutAction=new QAction(QIcon("1.png"),tr("Cut"),this);
    cutAction->setShortcut(tr("Ctrl+X"));
    cutAction->setStatusTip(tr("Cut the file"));
    connect(cutAction,SIGNAL(triggered()),showWidget->text,SLOT(cut()));

    pasteAction=new QAction(QIcon("2.png"),tr("Paste"),this);
    pasteAction->setShortcut(tr("Ctrl+V"));
    pasteAction->setStatusTip(tr("Paste the file"));
    connect(pasteAction,SIGNAL(triggered()),showWidget->text,SLOT(paste()));

    aboutAction=new QAction(tr("About"),this);
    connect(aboutAction,SIGNAL(triggered()),this,SLOT(aboutQt()));

    PrintTextAction=new QAction(QIcon("3.png"),tr("Print the text"),this);
    PrintTextAction->setStatusTip(tr("Print a text"));
    connect(PrintTextAction,SIGNAL(triggered()),this,SLOT(ShowPrintText()));

    PrintImageAction=new QAction(QIcon("4.png"),tr("Print the image"),this);
    PrintImageAction->setStatusTip(tr("Print an image"));
    connect(PrintImageAction,SIGNAL(triggered()),this,SLOT(ShowPrintImage()));

    zoomInAction=new QAction(QIcon("1.png"),tr("Enlarge"),this);
    zoomInAction->setStatusTip(tr("Enlarge an image"));
    connect(zoomInAction,SIGNAL(triggered()),this,SLOT(ShowZoomIn()));

    zoomOutAction=new QAction(QIcon("2.png"),tr("Shrink"),this);
    zoomOutAction->setStatusTip(tr("Shrink an image"));
    connect(zoomOutAction,SIGNAL(triggered()),this,SLOT(ShowZoomOut()));

    rotate90Action=new QAction(QIcon("3.png"),tr("Rotate 90 degrees"),this);
    rotate90Action->setStatusTip(tr("Rotate the image 90 degrees"));
    connect(rotate90Action,SIGNAL(triggered()),this,SLOT(ShowRotate90()));

    rotate180Action=new QAction(QIcon("4.png"),tr("Rotate 180 degrees"),this);
    rotate180Action->setStatusTip(tr("Rotate the image 180 degrees"));
    connect(rotate180Action,SIGNAL(triggered()),this,SLOT(ShowRotate180()));

    rotate270Action=new QAction(QIcon("1.png"),tr("Rotate 270 degrees"),this);
    rotate270Action->setShortcut(tr("Rotate the image 270 degrees"));
    connect(rotate270Action,SIGNAL(triggered()),this,SLOT(ShowRotate270()));

    mirrorVerticalAction=new QAction(QIcon("2.png"),tr("Vertial mirror"),this);
    mirrorVerticalAction->setStatusTip(tr("Mirror an image vertically"));
    connect(mirrorVerticalAction,SIGNAL(triggered()),this,SLOT(ShowMirrorVertical()));

    mirrorHorizontalAction=new QAction(QIcon("3.png"),tr("Horizontal"),this);
    mirrorHorizontalAction->setStatusTip(tr("Mirror an image horizontally"));
    connect(mirrorHorizontalAction,SIGNAL(triggered()),this,SLOT(ShowMirrorHorizontal()));

    undoAction=new QAction(QIcon("4.png"),tr("Undo"),this);
    connect(undoAction,SIGNAL(triggered()),showWidget->text,SLOT(undo()));

    redoAction=new QAction(QIcon("1.png"),tr("Redo"),this);
    connect(redoAction,SIGNAL(triggered()),showWidget->text,SLOT(redo()));

    actGrp=new QActionGroup(this);
    leftAction=new QAction(QIcon("1.png"),"Left justifying",actGrp);
    leftAction->setCheckable(true);

    rightAction=new QAction(QIcon("2.png"),"Right justifying",actGrp);
    rightAction->setCheckable(true);

    centerAction=new QAction(QIcon("3.png"),"Center",actGrp);
    centerAction->setChecked(true);

    justifyAction=new QAction(QIcon("4.png"),"Justify",actGrp);
    justifyAction->setCheckable(true);

    connect(actGrp,SIGNAL(triggered(QAction*)),this,SLOT(ShowAlignment(QAction*)));
}

void ImgProcessor::createMenus()
{
    fileMenu=menuBar()->addMenu(tr("File"));
    fileMenu->addAction(openFileAction);
    fileMenu->addAction(NewFileAction);
    fileMenu->addAction(PrintTextAction);
    fileMenu->addAction(PrintImageAction);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAction);

    zoomMenu=menuBar()->addMenu(tr("Edit"));
    zoomMenu->addAction(copyAction);
    zoomMenu->addAction(cutAction);
    zoomMenu->addAction(pasteAction);
    zoomMenu->addAction(aboutAction);
    zoomMenu->addSeparator();
    zoomMenu->addAction(zoomInAction);
    zoomMenu->addAction(zoomOutAction);

    rotateMenu=menuBar()->addMenu(tr("Rotate"));
    rotateMenu->addAction(rotate90Action);
    rotateMenu->addAction(rotate180Action);
    rotateMenu->addAction(rotate270Action);

    mirrorMenu=menuBar()->addMenu(tr("Mirror"));
    mirrorMenu->addAction(mirrorVerticalAction);
    mirrorMenu->addAction(mirrorHorizontalAction);
}

void ImgProcessor::createToolBars()
{
    fileTool=addToolBar("File");
    fileTool->addAction(openFileAction);
    fileTool->addAction(NewFileAction);
    fileTool->addAction(PrintTextAction);
    fileTool->addAction(PrintImageAction);

    zoomTool=addToolBar("Edit");
    zoomTool->addAction(copyAction);
    zoomTool->addAction(cutAction);
    zoomTool->addAction(pasteAction);
    zoomTool->addSeparator();
    zoomTool->addAction(zoomInAction);
    zoomTool->addAction(zoomOutAction);

    rotateTool=addToolBar("Rotate");
    rotateTool->addAction(rotate90Action);
    rotateTool->addAction(rotate180Action);
    rotateTool->addAction(rotate270Action);

    doToolBar=addToolBar("DoEdit");
    doToolBar->addAction(undoAction);
    doToolBar->addAction(redoAction);

    listToolBar=addToolBar("list");
    listToolBar->addWidget(listLabel);
    listToolBar->addWidget(listComboBox);
    listToolBar->addSeparator();
    listToolBar->addActions(actGrp->actions());

    fontToolBar=addToolBar("Font");
    fontToolBar->addWidget(fontLabel1);
    fontToolBar->addWidget(fontComboBox);
    fontToolBar->addWidget(fontLabel2);
    fontToolBar->addWidget(sizeComboBox);
    fontToolBar->addSeparator();
    fontToolBar->addWidget(boldBtn);
    fontToolBar->addWidget(italicBtn);
    fontToolBar->addWidget(underlineBtn);
    fontToolBar->addSeparator();
    fontToolBar->addWidget(colorBtn);


}

void ImgProcessor::ShowNewFile()
{
    ImgProcessor *newImgProcessor=new ImgProcessor;
    newImgProcessor->show();
}

void ImgProcessor::ShowOpenFile()
{
    fileName=QFileDialog::getOpenFileName(this);
    if(!fileName.isEmpty())
    {
        if(showWidget->text->document()->isEmpty())
        {
            loadFile(fileName);
        }
        else
        {
            ImgProcessor *newImgProcessor=new ImgProcessor;
            newImgProcessor->show();
            newImgProcessor->loadFile(fileName);
        }
    }
}

void ImgProcessor::loadFile(QString filename)
{
    printf("file name:%s\n",filename.data());
    QFile file(filename);
    if(file.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        QTextStream textStream(&file);
        //QTextCodec *codec=QTextCodec::codecForName("GBK");
        while(!textStream.atEnd())
        {
            showWidget->text->append(textStream.readLine());
            printf("read line");
        }
        printf("end\n");
    }
}

void ImgProcessor::ShowPrintText()
{
    QPrinter printer;
    QPrintDialog printDialog(&printer,this);
    if(printDialog.exec())
    {
        QTextDocument *doc=showWidget->text->document();
        doc->print(&printer);
    }
}

void ImgProcessor::ShowPrintImage()
{
    QPrinter printer;
    QPrintDialog printDialog(&printer,this);
    if(printDialog.exec())
    {
        QPainter painter(&printer);
        QRect rect=painter.viewport();
        QSize size=img.size();
        size.scale(rect.size(),Qt::KeepAspectRatio);
        painter.setViewport(rect.x(),rect.y(),size.width(),size.height());
        painter.setWindow(img.rect());
        painter.drawImage(0,0,img);
    }
}

void ImgProcessor::ShowZoomIn()
{
    if(img.isNull())
    {
        return;
    }
    QMatrix matrix;
    matrix.scale(2,2);
    img=img.transformed(matrix);
    showWidget->imageLabel->setPixmap(QPixmap::fromImage(img));
}

void ImgProcessor::ShowZoomOut()
{
    if(img.isNull())
    {
        return;
    }
    QMatrix matrix;
    matrix.scale(0.5,0.5);
    img=img.transformed(matrix);
    showWidget->imageLabel->setPixmap(QPixmap::fromImage(img));
}

void ImgProcessor::ShowRotate90()
{
    if(img.isNull())
    {
        return;
    }
    QMatrix matrix;
    matrix.rotate(90);
    img=img.transformed(matrix);
    showWidget->imageLabel->setPixmap(QPixmap::fromImage(img));
}

void ImgProcessor::ShowRotate180()
{
    if(img.isNull())
    {
        return;
    }
    QMatrix matrix;
    matrix.rotate(180);
    img=img.transformed(matrix);
    showWidget->imageLabel->setPixmap(QPixmap::fromImage(img));
}

void ImgProcessor::ShowRotate270()
{
    if(img.isNull())
    {
        return;
    }
    QMatrix matrix;
    matrix.rotate(270);
    img=img.transformed(matrix);
    showWidget->imageLabel->setPixmap(QPixmap::fromImage(img));
}

void ImgProcessor::ShowMirrorVertical()
{
    if(img.isNull())
        return;
    img=img.mirrored(false,true);
    showWidget->imageLabel->setPixmap(QPixmap::fromImage(img));
}

void ImgProcessor::ShowMirrorHorizontal()
{
    if(img.isNull())
        return;
    img=img.mirrored(true,false);
    showWidget->imageLabel->setPixmap(QPixmap::fromImage(img));
}

void ImgProcessor::ShowFontComboBox(QString comboStr)
{
    QTextCharFormat fmt;
    fmt.setFontFamily(comboStr);
    mergeFormat(fmt);
}

void ImgProcessor::mergeFormat(QTextCharFormat format)
{
    QTextCursor cursor=showWidget->text->textCursor();

    if(!cursor.hasSelection())
    {
        cursor.select(QTextCursor::WordUnderCursor);
    }
    cursor.mergeCharFormat(format);
    showWidget->text->mergeCurrentCharFormat(format);
}

void ImgProcessor::ShowSizeSpinBox(QString spinValue)
{
    QTextCharFormat fmt;
    fmt.setFontPointSize(spinValue.toFloat());
    showWidget->text->mergeCurrentCharFormat(fmt);
}

void ImgProcessor::ShowBoldBtn()
{
    QTextCharFormat fmt;
    fmt.setFontWeight(boldBtn->isChecked()?QFont::Bold:QFont::Normal);
    showWidget->text->mergeCurrentCharFormat(fmt);
}

void ImgProcessor::ShowItalicBtn()
{
    QTextCharFormat fmt;
    fmt.setFontItalic(italicBtn->isChecked());
    showWidget->text->mergeCurrentCharFormat(fmt);
}

void ImgProcessor::ShowUnderlineBtn()
{
    QTextCharFormat fmt;
    fmt.setFontUnderline(underlineBtn->isChecked());
    showWidget->text->mergeCurrentCharFormat(fmt);

}

void ImgProcessor::ShowColorBtn()
{
    QColor color=QColorDialog::getColor(Qt::red,this);
    if(color.isValid())
    {
        QTextCharFormat fmt;
        fmt.setForeground(color);
        showWidget->text->mergeCurrentCharFormat(fmt);
    }
}

void ImgProcessor::ShowCurrentFormatChanged(const QTextCharFormat &fmt)
{
    fontComboBox->setCurrentIndex(fontComboBox->findText(fmt.fontFamily()));
    sizeComboBox->setCurrentIndex(sizeComboBox->findText(QString::number(fmt.fontPointSize())));
    boldBtn->setChecked(fmt.font().bold());
    italicBtn->setChecked(fmt.fontItalic());
    underlineBtn->setChecked(fmt.fontUnderline());
}

void ImgProcessor::ShowAlignment(QAction*act)
{
    if(act==leftAction)
        showWidget->text->setAlignment(Qt::AlignLeft);
    if(act==rightAction)
        showWidget->text->setAlignment(Qt::AlignRight);
    if(act==centerAction)
        showWidget->text->setAlignment(Qt::AlignCenter);
    if(act==justifyAction)
        showWidget->text->setAlignment(Qt::AlignJustify);
}

void ImgProcessor::ShowCursorPositionChanged()
{
    if(showWidget->text->alignment()==Qt::AlignLeft)
        leftAction->setChecked(true);
    if(showWidget->text->alignment()==Qt::AlignRight)
        rightAction->setChecked(true);
    if(showWidget->text->alignment()==Qt::AlignCenter)
        centerAction->setChecked(true);
    if(showWidget->text->alignment()==Qt::AlignJustify)
        justifyAction->setChecked(true);
}

void ImgProcessor::ShowList(int index)
{
    QTextCursor cursor=showWidget->text->textCursor();
    if(index!=0)
    {
        QTextListFormat::Style style=QTextListFormat::ListDisc;
        switch (index)
        {
        case 1:
            style=QTextListFormat::ListDisc;
            break;
        case 2:
            style=QTextListFormat::ListCircle;
            break;
        case 3:
            style=QTextListFormat::ListSquare;
            break;
        case 4:
            style=QTextListFormat::ListDecimal;
            break;
        case 5:
            style=QTextListFormat::ListLowerAlpha;
            break;
        case 6:
            style=QTextListFormat::ListUpperAlpha;
            break;
        case 7:
            style=QTextListFormat::ListLowerRoman;
            break;
        case 8:
            style=QTextListFormat::ListUpperRoman;
            break;
        default:
            break;
        }
        cursor.beginEditBlock();
        QTextBlockFormat blockFmt=cursor.blockFormat();
        QTextListFormat listFmt;
        if(cursor.currentList())
        {
            listFmt=cursor.currentList()->format();

        }
        else
        {
            listFmt.setIndent(blockFmt.indent()+1);
            blockFmt.setIndent(0);
            cursor.setBlockFormat(blockFmt);
        }
        listFmt.setStyle(style);
        cursor.createList(listFmt);
        cursor.endEditBlock();
    }
    else
    {
        QTextBlockFormat bfmt;
        bfmt.setObjectIndex(-1);
        cursor.mergeBlockFormat(bfmt);
    }
}

void ImgProcessor::aboutQt()
{
    QApplication::aboutQt();
}

























