#include "listwidget.h"
#include "ui_listwidget.h"

ListWidget::ListWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ListWidget)
{
    ui->setupUi(this);
    this->setFixedSize(1300,800);


    configwidget=new Widget(this);
    configwidget->move(0,0);
    configwidget->show();

    listWidget=new QListWidget(this);
    listWidget->setFixedSize(this->width()-420,this->height()-100);
    listWidget->move(420,100);

    sumMuch=0;

    QFont font;
    font.setFamily("楷体");
    font.setPointSize(15);
    ui->label->setFont(font);
    ui->label->setAlignment(Qt::AlignVCenter);
    ui->label->setAttribute(Qt::WA_TransparentForMouseEvents);



    initConnect();

}

ListWidget::~ListWidget()
{
    delete ui;
}

void ListWidget::initConnect()
{
    connect(configwidget,&Widget::addPush,[=](){


        QString str=configwidget->getString();

        QListWidgetItem *item = new QListWidgetItem();
        listWidget->addItem(item);
        HouseItem * widget=new HouseItem();
        widget->setFixedSize(listWidget->width()-10,80);
        widget->initHouseItem();
        widget->setString(str);
        widget->setMuch(configwidget->getMuch());
        item->setSizeHint(QSize(widget->width(),widget->height()));
        listWidget->setItemWidget(item,widget);

        sumMuch+=configwidget->getMuch();
        ui->label->setText("共计："+QString::number(sumMuch)+" 元（RMB）");

    });
}
