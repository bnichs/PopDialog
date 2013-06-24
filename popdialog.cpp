#include "popdialog.h"
#include <iostream>

#include <QPushButton>
#include <QToolTip>
#include <QWidget>
#include <QString>
#include <QIcon>
#include <QPixmap>
#include <QComboBox>
#include <QLabel>
#include <QRadioButton>
#include <QApplication>
#include <QtWidgets>

//#include "glwidget.h"


// #include <QGLWidget>
//#include <QtOpenGL/QGLWidget>
/*
void QPushButton::mousePressEvent(QMouseEvent *e)
{
    if(e->button()==Qt::LeftButton)
        emit rightClicked();
}
*/


MyDialog::MyDialog(QWidget *parent) : QDialog(parent)
{
}


void MyDialog::display(){
    setLayout(this->buildLayout());
}

void MyDialog::ActionTile(const char * handle/*,
                void (*func)(void *, char *, int )*/){
    //void * ptr=func;
    if (!handleMap[handle])
        std::cout<<"Handle not in layout yet"<<endl;
    else{
        Node * n = handleMap[handle];
        QPushButton * qpb = dynamic_cast<QPushButton*>(n->myWidget);
      //  connect (qpb,&QPushButton::clicked,func);
    }

}

void MyDialog::AddText(const char * handle,
                        const char * text){

    Node * n = new Node(handle);
    QLabel * qlb = new QLabel(text);
    n->myWidget=qlb;
    n->type=TEXT;
    addNode(n);
}

void MyDialog::AddButton(const char* handle,
                          const char * caption,
                          int length){

    Node * n = new Node(handle);
    QPushButton * qbp = new QPushButton(caption);
    qbp->resize(length, 100);
    n->myWidget=qbp;
    n->data=caption;
    n->type=BUTTON;
    addNode(n);
}

void MyDialog::AddToggle(const char * handle,
                          int length,
                          const char * caption){

    Node * n = new Node(handle);
    QRadioButton *qrb = new QRadioButton(caption);
    n->myWidget=qrb;
    n->data=handle;
    n->type=TOGGLE;
    addNode(n);
}

void MyDialog::AddSlider(const char * handle,
                          int length,
                          int height,
                          int style,
                          int min,
                          int max){

    Node * n = new Node(handle);
    n->data=handle;
    n->type=SLIDER;
    addNode(n);
}

/*
void MyDialog::AddGLView(const char * handle,
                          int width,
                          int height){

    Node * n = new Node(handle);
    GLWidget * glw = new GLWidget();
    glw->resize(10,10);
    n->type=OPENGL;
    n->myWidget=glw;
    addNode(n);
}*/

void MyDialog::AddPopList(const char * handle,
                           int len){

    Node * n = new Node(handle);
    QComboBox * qcb = new QComboBox();
    n->data=handle;
    n->type=POPLIST;
    n->myWidget=qcb;
    addNode(n);
}

void MyDialog::ListAdd(const char * handle,
                        const char * line){

    if (!handleMap[handle])
        std::cout<<"Handle not in layout yet"<<endl;
    else{
        Node * n= handleMap[handle];
        QComboBox * qcb = dynamic_cast<QComboBox*>(n->myWidget);
        QString qst(line);
        qcb->addItem(qst);
    }
}


void MyDialog::SetTileTip(const char * handle,
                           const char * value){

    if (!handleMap[handle])
        std::cout<<"Handle not in layout yet"<<endl;
    else{
        QWidget * widget = (handleMap[handle])->myWidget;
        widget->setToolTip(QString(value));
    }
}

void MyDialog::SetBitmap(const char * handle,
                          int id,
                          const char * fil){

    if (!handleMap[handle])
        std::cout<<"Handle not in layout yet"<<endl;
    else{
        Node * n = handleMap[handle];

        if (n->type==BUTTON){
            QPushButton * button = dynamic_cast<QPushButton*>(n->myWidget);
            QString theFile= QString(fil);
            QPixmap imDisplay(theFile);
            QIcon icon(imDisplay);
            button->setIcon(icon);
        }



    }



}

void MyDialog::AddTabCtrl(const char * tile, int length, int height){

}

void MyDialog::SetCurrentTab(const char *, int tab){

}

void MyDialog::AddTab(const char * tile, char * name){

}
