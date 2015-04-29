#ifndef MYLISTWIDGET_H
#define MYLISTWIDGET_H

#include <QListWidget>
#include <QWidget>

class MyListWidget:public QListWidget
{
    Q_OBJECT
public:
    explicit MyListWidget(QWidget * parent = 0);
    void contextMenuEvent ( QContextMenuEvent * event );
    ~MyListWidget();
};

#endif // MYLISTWIDGET_H
