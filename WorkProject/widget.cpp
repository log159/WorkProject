#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget (parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    much=0;


    setReg(ui->lineEdit_Sand_Square);
    setReg(ui->lineEdit_Sand_Vehicle);
    setReg(ui->lineEdit_Sand_Bag);

    setReg(ui->lineEdit_Common_Brick);

    setReg(ui->lineEdit_Cement);

    setReg(ui->lineEdit_Aerated);

    connect(ui->pushButton,&QPushButton::clicked,[=](){
        double sum=0;

        double sandSquare   =double(ui->lineEdit_Sand_Square->text().toDouble())*40;
        double sandVehicle  =double(ui->lineEdit_Sand_Vehicle->text().toDouble())*double(40)/double(3);
        double sandBag      =double(ui->lineEdit_Sand_Bag->text().toDouble())*double(40)/double(30);
        double commonBrick  =double(ui->lineEdit_Common_Brick->text().toDouble())*double(0.2);
        double cement       =double(ui->lineEdit_Cement->text().toDouble())*double(2);
        double aerated      =double(ui->lineEdit_Aerated->text().toDouble())*double(1);

        sum+=sandSquare;
        sum+=sandVehicle;
        sum+=sandBag;
        sum+=commonBrick;
        sum+=cement;
        sum+=aerated;

        much=sum;

        ui->label_SUM->setText(QString::number(sum));
        sum_str=QString::number(sum);

        str="  ";
        if(ui->lineEdit_Sand_Square->text()!=""||ui->lineEdit_Sand_Vehicle->text()!=""||ui->lineEdit_Sand_Bag->text()!=""){
            str+="沙子：";

            if(ui->lineEdit_Sand_Square->text()!=""){
                str+=ui->lineEdit_Sand_Square->text()+" 方 ";

            }
            if(ui->lineEdit_Sand_Vehicle->text()!=""){
                str+=ui->lineEdit_Sand_Vehicle->text()+" 车 ";

            }
            if(ui->lineEdit_Sand_Bag->text()!=""){
                str+=ui->lineEdit_Sand_Bag->text()+" 袋 ";

            }
        }
        if(ui->lineEdit_Common_Brick->text()!=""){
            str+="红砖："+ui->lineEdit_Common_Brick->text()+" 块 ";

        }
        if(ui->lineEdit_Cement->text()!=""){
            str+="水泥："+ui->lineEdit_Cement->text()+" 袋 ";
        }
        if(ui->lineEdit_Aerated->text()!=""){
            str+="加气块："+ui->lineEdit_Aerated->text()+" 块 ";
        }
        str+="总计："+sum_str+" 元（RMB）";
        emit addPush();
        clearEdit();

    });


}

Widget::~Widget()
{
    delete ui;
}

void Widget::clearEdit()
{
    ui->lineEdit_Sand_Square->clear();
    ui->lineEdit_Sand_Vehicle->clear();
    ui->lineEdit_Sand_Bag->clear();

    ui->lineEdit_Common_Brick->clear();

    ui->lineEdit_Cement->clear();

    ui->lineEdit_Aerated->clear();
}

QString Widget::getString() const
{
    return str;
}

double Widget::getMuch() const
{
    return much;
}

void Widget::setReg(QLineEdit *line)
{
    QRegExpValidator *validator = new QRegExpValidator(QRegExp("^-?\\d*\\.?\\d+$"), line);
    line->setValidator(validator);
}

void Widget::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e)
//    QPainter painter(this);
//    painter.drawPixmap(0,0,this->width(),this->height(),QPixmap(":/res/st.PNG"));

}
