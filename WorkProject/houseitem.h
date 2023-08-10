#ifndef HOUSEITEM_H
#define HOUSEITEM_H

#include <QWidget>
#include <QPainter>
#include <QLabel>

class HouseItem : public QWidget
{
    Q_OBJECT
private:
    QLabel* lab;
    double item_much;
public:
    explicit HouseItem(QWidget *parent = nullptr);
    void initHouseItem();
    void setString(const QString& str);
    void setMuch(const double& much);

private:
    void paintEvent(QPaintEvent* e)override;

signals:

public slots:
};

#endif // HOUSEITEM_H
