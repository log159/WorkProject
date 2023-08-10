#include "houseitem.h"

HouseItem::HouseItem(QWidget *parent) : QWidget(parent)
{

}

void HouseItem::initHouseItem()
{
    lab=new QLabel(this);
    lab->setFixedSize(this->size());
    lab->move(0,0);
    QFont font;
    font.setFamily("楷体");
    font.setPointSize(12);
    lab->setFont(font);
    lab->setAlignment(Qt::AlignVCenter);
    lab->setAttribute(Qt::WA_TransparentForMouseEvents);//鼠标穿透效果

}

void HouseItem::setString(const QString &str)
{
    lab->setText(str);

}

void HouseItem::setMuch(const double &much)
{
    item_much=much;
}

void HouseItem::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e)
    QPainter painter(this);
    painter.drawRect(0,0,this->width()-1,this->height()-1);

}
