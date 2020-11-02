#include "mainwidget.h"
#include<QColorDialog>

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
{
    paintArea=new PaintArea;

    shapeLabel=new QLabel("Shape");
    shapeComboBox=new QComboBox;
    shapeComboBox->addItem("Line",PaintArea::Line);
    shapeComboBox->addItem("Rectangle",PaintArea::Rectangle);
    shapeComboBox->addItem("RoundRect",PaintArea::RoundRect);
    shapeComboBox->addItem("Ellipse",PaintArea::Ellipse);
    shapeComboBox->addItem("Polygon",PaintArea::Polygon);
    shapeComboBox->addItem("Polyline",PaintArea::Polyline);
    shapeComboBox->addItem("Points",PaintArea::Points);
    shapeComboBox->addItem("Arc",PaintArea::Arc);
    shapeComboBox->addItem("Path",PaintArea::Path);
    shapeComboBox->addItem("Text",PaintArea::Text);
    shapeComboBox->addItem("Pixmap",PaintArea::Pixmap);
    connect(shapeComboBox,SIGNAL(activated(int)),this,SLOT(ShowShape(int)));

    penColorLabel=new QLabel("Pen color: ");
    penColorFrame=new QFrame;
    penColorFrame->setFrameStyle(QFrame::Panel|QFrame::Sunken);
    penColorFrame->setAutoFillBackground(true);
    penColorFrame->setPalette(QPalette(Qt::blue));
    penColorBtn=new QPushButton("Amend");
    connect(penColorBtn,SIGNAL(clicked()),this,SLOT(ShowPenColor()));

    penWidthLabel=new QLabel("Pen width: ");
    penWidthSpinBox=new QSpinBox;
    penWidthSpinBox->setRange(0,20);
    connect(penWidthSpinBox,SIGNAL(valueChanged(int)),this,SLOT(ShowPenWidth(int)));

    penStyleLabel=new QLabel("Pen style: ");
    penStyleComboBox=new QComboBox;
    penStyleComboBox->addItem("SolidLine",static_cast<int>(Qt::SolidLine));
    penStyleComboBox->addItem("DashLine",static_cast<int>(Qt::DashLine));
    penStyleComboBox->addItem("DotLine",static_cast<int>(Qt::DotLine));
    penStyleComboBox->addItem("DashDotLine",static_cast<int>(Qt::DashDotLine));
    penStyleComboBox->addItem("DashDotDotLine",static_cast<int>(Qt::DashDotDotLine));
    penStyleComboBox->addItem("CustomDashLine",static_cast<int>(Qt::CustomDashLine));
    connect(penStyleComboBox,SIGNAL(activated(int)),this,SLOT(ShowPenStyle(int)));

    penCapLabel=new QLabel("Pen cap: ");
    penCapComboBox=new QComboBox;
    penCapComboBox->addItem("SquareCap",Qt::SquareCap);
    penCapComboBox->addItem("FlatCap",Qt::FlatCap);
    penCapComboBox->addItem("RoundCap",Qt::RoundCap);
    connect(penCapComboBox,SIGNAL(activated(int)),this,SLOT(ShowPenCap(int)));

    penJoinLabel=new QLabel("Pen join: ");
    penJoinComboBox=new QComboBox;
    penJoinComboBox->addItem("BevelJoin",Qt::BevelJoin);
    penJoinComboBox->addItem("MiterJoin",Qt::MiterJoin);
    penJoinComboBox->addItem("RoundStyle",Qt::RoundJoin);
    connect(penJoinComboBox,SIGNAL(activated(int)),this,SLOT(ShowPenJoin(int)));

    fillRuleLabel=new QLabel("Fill rule: ");
    fillRuleComboBox=new QComboBox;
    fillRuleComboBox->addItem("Odd Even",Qt::OddEvenFill);
    fillRuleComboBox->addItem("WInding",Qt::WindingFill);
    connect(fillRuleComboBox,SIGNAL(activated(int)),this,SLOT(ShowFillRule()));

    spreadLabel=new QLabel("Spread result: ");
    spreadComboBox=new QComboBox;
    spreadComboBox->addItem("PadSpread",QGradient::PadSpread);
    spreadComboBox->addItem("RepeatSpread",QGradient::RepeatSpread);
    spreadComboBox->addItem("ReflectSpread",QGradient::ReflectSpread);
    connect(spreadComboBox,SIGNAL(activated(int)),this,SLOT(ShowSpreadStyle()));

    brushColorLabel=new QLabel("Brush color: ");
    brushColorFrame=new QFrame;
    brushColorFrame->setFrameStyle(QFrame::Panel|QFrame::Sunken);
    brushColorFrame->setAutoFillBackground(true);
    brushColorFrame->setPalette(QPalette(Qt::green));
    brushColorBtn=new QPushButton("Amend");
    connect(brushColorBtn,SIGNAL(clicked()),this,SLOT(ShowBrushColor()));

    brushStyleLabel=new QLabel("Brush style: ");
    brushStyleComboBox=new QComboBox;
    brushStyleComboBox->addItem("SolidPattern",static_cast<int>(Qt::SolidPattern));
    brushStyleComboBox->addItem("Dense1Pattern",static_cast<int>(Qt::Dense1Pattern));
    brushStyleComboBox->addItem("Dense2Pattern",static_cast<int>(Qt::Dense2Pattern));
    brushStyleComboBox->addItem("Dense3Pattern",static_cast<int>(Qt::Dense3Pattern));
    brushStyleComboBox->addItem("Dense4Pattern",static_cast<int>(Qt::Dense4Pattern));
    brushStyleComboBox->addItem("Dense5Pattern",static_cast<int>(Qt::Dense5Pattern));
    brushStyleComboBox->addItem("Dense6Pattern",static_cast<int>(Qt::Dense6Pattern));
    brushStyleComboBox->addItem("Dense7Pattern",static_cast<int>(Qt::Dense7Pattern));
    brushStyleComboBox->addItem("HorPattern",static_cast<int>(Qt::HorPattern));
    brushStyleComboBox->addItem("VerPattern",static_cast<int>(Qt::VerPattern));
    brushStyleComboBox->addItem("CrossPattern",static_cast<int>(Qt::CrossPattern));
    brushStyleComboBox->addItem("BDiagPattern",static_cast<int>(Qt::BDiagPattern));
    brushStyleComboBox->addItem("FDiagPattern",static_cast<int>(Qt::FDiagPattern));
    brushStyleComboBox->addItem("DiagCrossPattern",static_cast<int>(Qt::DiagCrossPattern));
    brushStyleComboBox->addItem("LinearGradientPattern",static_cast<int>(Qt::LinearGradientPattern));
    brushStyleComboBox->addItem("ConicalGradientPattern",static_cast<int>(Qt::ConicalGradientPattern));
    brushStyleComboBox->addItem("RadialGradientPattern",static_cast<int>(Qt::RadialGradientPattern));
    brushStyleComboBox->addItem("TexturePattern",static_cast<int>(Qt::TexturePattern));
    connect(brushStyleComboBox,SIGNAL(activated(int)),this,SLOT(ShowBrush(int)));

    rightLayout=new QGridLayout;
    rightLayout->addWidget(shapeLabel,0,0);
    rightLayout->addWidget(shapeComboBox,0,1);
    rightLayout->addWidget(penColorLabel,1,0);
    rightLayout->addWidget(penColorFrame,1,1);
    rightLayout->addWidget(penColorBtn,1,2);
    rightLayout->addWidget(penWidthLabel,2,0);
    rightLayout->addWidget(penWidthSpinBox,2,1);
    rightLayout->addWidget(penStyleLabel,3,0);
    rightLayout->addWidget(penStyleComboBox,3,1);
    rightLayout->addWidget(penCapLabel,4,0);
    rightLayout->addWidget(penCapComboBox,4,1);
    rightLayout->addWidget(penJoinLabel,5,0);
    rightLayout->addWidget(penJoinComboBox,5,1);
    rightLayout->addWidget(fillRuleLabel,6,0);
    rightLayout->addWidget(fillRuleComboBox,6,1);
    rightLayout->addWidget(spreadLabel,7,0);
    rightLayout->addWidget(spreadComboBox,7,1);
    rightLayout->addWidget(brushColorLabel,8,0);
    rightLayout->addWidget(brushColorFrame,8,1);
    rightLayout->addWidget(brushColorBtn,8,2);
    rightLayout->addWidget(brushStyleLabel,9,0);
    rightLayout->addWidget(brushStyleComboBox,9,1);
    QHBoxLayout *mainLayout=new QHBoxLayout(this);
    mainLayout->addWidget(paintArea);
    mainLayout->addLayout(rightLayout);
    mainLayout->setStretchFactor(paintArea,1);
    mainLayout->setStretchFactor(rightLayout,0);
    ShowShape(shapeComboBox->currentIndex());
}

MainWidget::~MainWidget()
{
}

void MainWidget::ShowShape(int value)
{
    PaintArea::Shape shape=PaintArea::Shape(shapeComboBox->itemData(value,Qt::UserRole).toInt());
    paintArea->setShape(shape);
}

void MainWidget::ShowPenColor()
{
    QColor color=QColorDialog::getColor(Qt::red);
    penColorFrame->setPalette(QPalette(color));
    int value=penWidthSpinBox->value();
    Qt::PenStyle style=Qt::PenStyle(penStyleComboBox->itemData(penStyleComboBox->currentIndex(),Qt::UserRole).toInt());
    Qt::PenCapStyle cap=Qt::PenCapStyle(penCapComboBox->itemData(penCapComboBox->currentIndex(),Qt::UserRole).toInt());
    Qt::PenJoinStyle join=Qt::PenJoinStyle(penJoinComboBox->itemData(penJoinComboBox->currentIndex(),Qt::UserRole).toInt());
    paintArea->setPen(QPen(color,value,style,cap,join));
}

void MainWidget::ShowPenWidth(int value)
{
    QColor color=penColorFrame->palette().color(QPalette::Window);
    Qt::PenStyle style=Qt::PenStyle(penStyleComboBox->itemData(penStyleComboBox->currentIndex(),Qt::UserRole).toInt());
    Qt::PenCapStyle cap=Qt::PenCapStyle(penCapComboBox->itemData(penCapComboBox->currentIndex(),Qt::UserRole).toInt());
    Qt::PenJoinStyle join=Qt::PenJoinStyle(penJoinComboBox->itemData(penJoinComboBox->currentIndex(),Qt::UserRole).toInt());
    paintArea->setPen(QPen(color,value,style,cap,join));
}

void MainWidget::ShowPenStyle(int styleValue)
{
    QColor color=penColorFrame->palette().color(QPalette::Window);
    int value=penWidthSpinBox->value();
    Qt::PenStyle style=Qt::PenStyle(penStyleComboBox->itemData(styleValue,Qt::UserRole).toInt());
    Qt::PenCapStyle cap=Qt::PenCapStyle(penCapComboBox->itemData(penCapComboBox->currentIndex(),Qt::UserRole).toInt());
    Qt::PenJoinStyle join=Qt::PenJoinStyle(penJoinComboBox->itemData(penJoinComboBox->currentIndex(),Qt::UserRole).toInt());
    paintArea->setPen(QPen(color,value,style,cap,join));
}

void MainWidget::ShowPenCap(int capValue)
{
    QColor color=penColorFrame->palette().color(QPalette::Window);
    int value=penWidthSpinBox->value();
    Qt::PenStyle style=Qt::PenStyle(penStyleComboBox->itemData(penStyleComboBox->currentIndex(),Qt::UserRole).toInt());
    Qt::PenCapStyle cap=Qt::PenCapStyle(penCapComboBox->itemData(capValue,Qt::UserRole).toInt());
    Qt::PenJoinStyle join=Qt::PenJoinStyle(penJoinComboBox->itemData(penJoinComboBox->currentIndex(),Qt::UserRole).toInt());
    paintArea->setPen(QPen(color,value,style,cap,join));
}

void MainWidget::ShowPenJoin(int joinValue)
{
    QColor color=penColorFrame->palette().color(QPalette::Window);
    int value=penWidthSpinBox->value();
    Qt::PenStyle style=Qt::PenStyle(penStyleComboBox->itemData(penStyleComboBox->currentIndex(),Qt::UserRole).toInt());
    Qt::PenCapStyle cap=Qt::PenCapStyle(penCapComboBox->itemData(penCapComboBox->currentIndex(),Qt::UserRole).toInt());
    Qt::PenJoinStyle join=Qt::PenJoinStyle(penJoinComboBox->itemData(joinValue,Qt::UserRole).toInt());
    paintArea->setPen(QPen(color,value,style,cap,join));
}

void MainWidget::ShowFillRule()
{
    Qt::FillRule rule=Qt::FillRule(fillRuleComboBox->itemData(fillRuleComboBox->currentIndex(),Qt::UserRole).toInt());
    paintArea->setFillRule(rule);
}

void MainWidget::ShowSpreadStyle()
{
    spread=QGradient::Spread(spreadComboBox->itemData(spreadComboBox->currentIndex(),Qt::UserRole).toInt());
}

void MainWidget::ShowBrushColor()
{
    QColor color=QColorDialog::getColor(Qt::blue);
    brushColorFrame->setPalette(QPalette(color));
    ShowBrush(brushStyleComboBox->currentIndex());
}

void MainWidget::ShowBrush(int value)
{
    QColor color=brushColorFrame->palette().color(QPalette::Window);
    Qt::BrushStyle style=Qt::BrushStyle(brushStyleComboBox->itemData(value,Qt::UserRole).toInt());
    if(style==Qt::LinearGradientPattern)
    {
        QLinearGradient linearGradient(0,0,400,400);
        linearGradient.setColorAt(0.0,Qt::white);
        linearGradient.setColorAt(0.2,color);
        linearGradient.setColorAt(1.0,Qt::black);
        linearGradient.setSpread(spread);
        paintArea->setBrush(linearGradient);
    }
    else if(style==Qt::RadialGradientPattern)
    {
        QRadialGradient radialGradient(200,200,150,150,100);
        radialGradient.setColorAt(0.0,Qt::white);
        radialGradient.setColorAt(0.2,color);
        radialGradient.setColorAt(1.0,Qt::black);
        radialGradient.setSpread(spread);
        paintArea->setBrush(radialGradient);
    }
    else if(style==Qt::ConicalGradientPattern)
    {
        QConicalGradient conicalGradient(200,200,30);
        conicalGradient.setColorAt(0.0,Qt::white);
        conicalGradient.setColorAt(0.2,color);
        conicalGradient.setColorAt(1.0,Qt::black);
        paintArea->setBrush(conicalGradient);
    }
    else if(style==Qt::TexturePattern)
    {
        paintArea->setBrush(QBrush(QPixmap("1.png")));
    }
    else
    {
        paintArea->setBrush(QBrush(color,style));
    }
}






























