#include "content.h"

Content::Content(QWidget *parent)
    : QFrame(parent)
{
    stack=new QStackedWidget(this);

    stack->setFrameStyle(QFrame::Panel|QFrame::Raised);
    baseInfo=new BaseInfo();
    contact=new Contact();
    detail=new Detail();
    stack->addWidget(baseInfo);
    stack->addWidget(contact);
    stack->addWidget(detail);

    AmendBtn=new QPushButton(tr("Amend"));
    CloseBtn=new QPushButton(tr("Close"));
    QHBoxLayout *BtnLayout=new QHBoxLayout;
    BtnLayout->addStretch(1);
    BtnLayout->addWidget(AmendBtn);
    BtnLayout->addWidget(CloseBtn);

    QVBoxLayout *RightLayout=new QVBoxLayout(this);
    RightLayout->setMargin(10);
    RightLayout->setSpacing(6);
    RightLayout->addWidget(stack);
    RightLayout->addLayout(BtnLayout);
}

Content::~Content()
{
}

