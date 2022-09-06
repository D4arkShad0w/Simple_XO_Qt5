#include "myrect.h"
#include <QDebug>
#include <QGraphicsTextItem>
#include <QGraphicsScene>
#include <QMessageBox>
#include <QApplication>
extern char turn;
extern int board[9];

myrect::myrect() {



}

void myrect::quit()
{
    QApplication::quit();

}

void myrect::msgbox(QString c)
{


    QMessageBox box;

    if(c=="Draws") box.setText(c);
    else box.setText(c+" Wins        ");
    box.setInformativeText(" Do you want play again ?");
    box.setFixedWidth(400);
    box.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    box.setDefaultButton(QMessageBox::No);
    box.setIcon(QMessageBox::Information);
    box.setWindowTitle("End Game");
    int result=box.exec();


    switch (result) {
    case QMessageBox::No:
        quit();
        break;
    case QMessageBox::Yes:
        reset();
        break;
    default:
       quit();
        break;
    }






}

void myrect::reset()
{
    QList<QGraphicsItem*> list =scene()->items();

    foreach (QGraphicsItem* item, list) {
        item->setEnabled(true);
        if(item->data(10)=="o" || item->data(10)=="x")
           scene()->removeItem(item);


    }
    for ( int i =0 ; i<9 ; i++)
    {
        board[i]=4;
    }
}

void myrect::EndGame()
{
    QList<QGraphicsItem*> list =scene()->items();

    foreach (QGraphicsItem* item, list) {
        item->setEnabled(false);

    }



}

int myrect::number_table()
{
    for(int i=1 ; i<=9 ; i++)
    {
        if(this->data(i)=="r_1") return 1;
        if(this->data(i)=="r_2") return 2;
        if(this->data(i)=="r_3") return 3;
        if(this->data(i)=="r_4") return 4;
        if(this->data(i)=="r_5") return 5;
        if(this->data(i)=="r_6") return 6;
        if(this->data(i)=="r_7") return 7;
        if(this->data(i)=="r_8") return 8;
        if(this->data(i)=="r_9") return 9;

    }

}

void myrect::mousePressEvent(QGraphicsSceneMouseEvent *event)
{


    if(event->buttons() == Qt::LeftButton)
        if(turn=='x')
    {

            board[number_table()-1]=1;


        auto text = new QGraphicsTextItem;
        text->setData(10,"x");
        text->setPlainText("X");
        text->setPos(x()+10,y()-10);
        text->setFont(QFont("Tahoma",30));
         scene()->addItem(text);
            this->setEnabled(false);

    }

      if(turn=='o')
    {
          board[number_table()-1]= 0;

        auto text2 = new QGraphicsTextItem;
        text2->setData(10,"o");
        text2->setPlainText("O");
        text2->setPos(x()+10,y()-10);
        text2->setFont(QFont("Tahoma",30));
         scene()->addItem(text2);
         this->setEnabled(false);

    }
        if(checkwin()==1)
        {


           EndGame();
           msgbox("X");

        }
        if(checkwin()==3)
        {


           EndGame();
           msgbox("Draws");

        }
        if (checkwin()==2)
        {
            EndGame();
            msgbox("O");


        }

       changeturn();

}



void myrect::changeturn()
{
    if(turn=='x') turn='o';
    else turn='x';
}

int myrect::checkwin()
{


    if (board[0]==1 && board[1]==1 && board[2]==1) return 1;

    if (board[0]==0 && board[1]==0 && board[2]==0) return 2;


    if (board[3]==1 && board[4]==1 && board[5]==1) return 1;

    if (board[3]==0 && board[4]==0 && board[5]==0) return 2;



    if (board[6]==1 && board[7]==1 && board[8]==1) return 1;

    if (board[6]==0 && board[7]==0 && board[8]==0) return 2;


  if (board[0]==1 && board[4]==1 && board[8]==1) return 1;

  if (board[0]==0 && board[4]==0 && board[8]==0) return 2;


  if (board[2]==1 && board[4]==1 && board[6]==1) return 1;

  if (board[2]==0 && board[4]==0 && board[6]==0) return 2;


  if (board[0]==1 && board[3]==1 && board[6]==1) return 1;
  if (board[1]==1 && board[4]==1 && board[7]==1) return 1;
  if (board[2]==1 && board[5]==1 && board[8]==1) return 1;
  if (board[0]==0 && board[3]==0 && board[6]==0) return 2;
  if (board[1]==0 && board[4]==0 && board[7]==0) return 2;
  if (board[2]==0 && board[5]==0 && board[8]==0) return 2;


  if(board[0] !=4 &&     board[1]!=4 &&  board[2]!=4  &&  board[3]!=4 &&   board[4]!=4 &&    board[5]!=4 &&    board[7]!=4  &&  board[6]!=4 &&  board[8]!=4  )
  {
      return 3;
  }


}
