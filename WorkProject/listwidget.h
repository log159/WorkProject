#ifndef LISTWIDGET_H
#define LISTWIDGET_H

#include <QWidget>
#include <QListWidget>
#include <QString>

#include "houseitem.h"
#include "widget.h"
namespace Ui {
class ListWidget;
}

class ListWidget : public QWidget
{
    Q_OBJECT
private:
    Widget* configwidget;
    QListWidget* listWidget;
    double sumMuch;
public:
    explicit ListWidget(QWidget *parent = nullptr);
    ~ListWidget();
private:
    void initConnect();

private:
    Ui::ListWidget *ui;
};

#endif // LISTWIDGET_H
