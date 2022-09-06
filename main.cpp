#include <QGraphicsView>
#include <QApplication>
#include <myrect.h>
#include <QListView>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#define first 4
char turn = 'x';
int  board [9]={first,first,first,first,first,first,first,first,first};
int main(int argc, char *argv[])
{

    QApplication app(argc, argv);

    QGraphicsTextItem * author = new QGraphicsTextItem;
    author->setPlainText("Created by Mohammad AMin Moslemi");
    author->setFont(QFont("Tahoma",20));
    author->setDefaultTextColor(Qt::red);
    author->setPos(10,10);

      auto  scene = new QGraphicsScene;
  scene->addItem(author);
      auto view = new QGraphicsView;

 /*1*/     auto rect1=new myrect;
 /*2*/     auto rect2=new myrect;
      /*3*/auto rect3=new myrect;
 /*4*/     auto rect4=new myrect;
/*5*/      auto rect5=new myrect;
 /*6*/     auto rect6=new myrect;
  /*7*/    auto rect7=new myrect;
    /*8*/  auto rect8=new myrect;
     /*9*/ auto rect9=new myrect;

          rect1->setData(1,"r_1");
          rect2->setData(2,"r_2");

          rect3->setData(3,"r_3");
          rect4->setData(4,"r_4");


          rect5->setData(5,"r_5");
          rect6->setData(6,"r_6");


          rect7->setData(9,"r_7");


          rect8->setData(8,"r_8");
          rect9->setData(9,"r_9");








      rect1->setRect(0,0,100,100); rect2->setRect(0,0,100,100); rect3->setRect(0,0,100,100);
       rect4->setRect(0,0,100,100); rect5->setRect(0,0,100,100); rect6->setRect(0,0,100,100);
        rect7->setRect(0,0,100,100); rect8->setRect(0,0,100,100); rect9->setRect(0,0,100,100);



      rect1->setPos(200,100);
      rect2->setPos(300,100);
      rect3->setPos(400,100);

      rect4->setPos(200,200);
      rect5->setPos(300,200);
      rect6->setPos(400,200);

      rect7->setPos(200,300);
      rect8->setPos(300,300);
      rect9->setPos(400,300);



      scene->setSceneRect(0,0,690,500);
        view->setFixedSize(690,500);
        view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
      scene->addItem(rect1);scene->addItem(rect2);scene->addItem(rect3);scene->addItem(rect4);
      scene->addItem(rect5);scene->addItem(rect6);scene->addItem(rect7);scene->addItem(rect8);
      scene->addItem(rect9);




      view->setScene(scene);

      view->show();




    return app.exec();
}
