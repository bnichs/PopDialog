#include "popdialog.h"
#include <QApplication>

#include "tree.h"
#include "layouttree.h"
#include <iostream>
#include <QDebug>
using namespace std;



static void insert(void *, char *, int)
{
qDebug() << "pressed";
}

int buildDialog(int argc, char *argv[]){
	QApplication a(argc, argv);
	MyDialog w;
    w.StartRow();
        w.StartColumn();
            w.StartRow();
            for (int i =0;i<6;i++){
                w.AddButton("b1");
            }
            w.EndRow();
            w.StartRow();
                w.StartColumn();
                    w.AddPopList("b2");
                    char * buf;
                    for (int i = 0; i<5; i++){
                        sprintf(buf,"%d",i);
                        cout<<buf<<endl;
                        w.ListAdd("b2",buf);
                    }
                w.EndColumn();
                w.StartColumn();
                    w.AddButton("b3");
                w.EndColumn();
                w.StartColumn();
                    w.StartRow();
                        w.AddButton("b4");
                    w.EndRow();
                    w.StartRow();
                        w.AddButton("b5");
                    w.EndRow();
                w.EndColumn();
            w.EndRow();
        w.EndColumn();
        w.StartColumn();
            w.AddToggle("t1");
            w.AddToggle("t2");
        w.EndColumn();
        w.StartColumn();
            w.StartRow();
                w.AddButton("b6");
                w.AddButton("b7");
            w.EndRow();
            w.StartRow();
                w.AddButton("b8");
                w.AddButton("b9");
            w.EndRow();
        w.EndColumn();
        w.StartColumn();
            w.AddButton("B1");
            w.AddButton("B2");
        w.EndColumn();
    w.EndRow();
    w.StartRow();
        w.AddButton("B3","Bottom Button");
        w.SetBitmap("B3");
        w.SetTileTip("B3","HOVER!!!!");
    w.EndRow();
    w.StartRow();
        w.StartColumn();
        //    w.AddGLView("g1");
        w.EndColumn();
        w.StartColumn();
            w.AddButton("but1","hey there");
          //  w.ActionTile("but1",&insert);
        w.EndColumn();
        w.AddText("L1","Baseball has been very good to me");
    w.EndRow();


    w.printTree();

    w.display();
	w.show();
	return a.exec();
}


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
	MyDialog w;
    w.StartRow();
        w.StartColumn();
            w.StartRow();
            for (int i =0;i<6;i++){
                w.AddButton("b1");
            }
            w.EndRow();
            w.StartRow();
                w.StartColumn();
                    w.AddPopList("b2");
                    char * newBuf= new char;
                    for (int i = 0; i<5; i++){
                        sprintf(newBuf,"%d",i);
                        //cout<newBuf<<endl;
                        w.ListAdd("b2",buf);
                    }
                w.EndColumn();
                w.StartColumn();
                    w.AddButton("b3");
                w.EndColumn();
                w.StartColumn();
                    w.StartRow();
                        w.AddButton("b4");
                    w.EndRow();
                    w.StartRow();
                        w.AddButton("b5");
                    w.EndRow();
                w.EndColumn();
            w.EndRow();
        w.EndColumn();
        w.StartColumn();
            w.AddToggle("t1");
            w.AddToggle("t2");
        w.EndColumn();
        w.StartColumn();
            w.StartRow();
                w.AddButton("b6");
                w.AddButton("b7");
            w.EndRow();
            w.StartRow();
                w.AddButton("b8");
                w.AddButton("b9");
            w.EndRow();
        w.EndColumn();
        w.StartColumn();
            w.AddButton("B1");
            w.AddButton("B2");
        w.EndColumn();
    w.EndRow();
    w.StartRow();
        w.AddButton("B3","Bottom Button");
        w.SetBitmap("B3");
        w.SetTileTip("B3","HOVER!!!!");
    w.EndRow();
    w.StartRow();
       // w.StartColumn();
         //   w.AddGLView("g1");
        //w.EndColumn();
        w.StartColumn();
            w.AddButton("but1","hey there");
          //  w.ActionTile("but1",&insert);
        w.EndColumn();
        w.AddText("L1","Baseball has been very good to me");
    w.EndRow();


    w.printTree();

    w.display();
	w.show();
	return a.exec();
}
