#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QRegExpValidator>
#include <QRegExp>
#include <QLineEdit>
#include <QString>
#include <QDebug>
#include <QWidget>
#include <QPainter>
#include <QPixmap>


namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
private:
    QString str;
    QString sum_str;
    double much;
public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget()override;

    void clearEdit();
    QString getString()const;
    double getMuch()const;

private:
    void setReg(QLineEdit* line);
    void paintEvent(QPaintEvent*e)override;
signals:
    void addPush();
private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
