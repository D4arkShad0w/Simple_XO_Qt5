#ifndef MYRECT_H
#define MYRECT_H
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsRectItem>

class myrect :  public QObject ,public QGraphicsRectItem
{
private:



public:
    myrect();
    void quit();
    void msgbox(QString c);
    void reset ();
    void EndGame();
    int number_table ();
    void mousePressEvent (QGraphicsSceneMouseEvent* event);
    void changeturn();
    int  checkwin();

};


#endif // MYRECT_H
