#include "layouttree.h"
#include <vector>
#include <QPushButton>
#include <QRadioButton>
#include <QComboBox>
#include "node.h"
#include <iostream>
using namespace std;


/*
void LayoutTree::AddTab(const char * tile){

    Node * newTab = new Node();
    newTab->isLeaf=false;
    newTab->type=TAB;
    newTab->parent=currentParent;
    vector <Node *> *children=&(currentParent->children);
    children->push_back(newTab);
}*/

void LayoutTree::StartColumn(){


    Node * n = new Node();
    n->isLeaf=false;
    n->type=COL;
    n->parent=currentParent;
    currentParent->addChild(n);
    lastParent=currentParent;
    currentParent=n;

    /*cout<<root<<endl;
    if (!started){
        currentRow=root;
        root->type=ROW;
        started=true;
    }

    Node * newCol = new Node();
    newCol->isLeaf=false;
    newCol->type=COL;
    newCol->parent=currentRow;
    vector <Node *> *children=&(currentRow->children);
    children->push_back(newCol);
    currentParent=currentCol=newCol;*/
}

void LayoutTree::EndColumn(){
    //currentRow=currentCol->parent;
    //currentCol=NULL;
   // cout<<lastParent<<endl;
    currentParent=lastParent;
     currentParent=currentParent->parent;
}

void LayoutTree::StartRow(){

    Node * n = new Node();
    n->isLeaf=false;
    n->type=ROW;
    n->parent=currentParent;
    currentParent->addChild(n);
    lastParent=currentParent;
    currentParent=n;
/*    if (!started){
        currentCol=root;
        root->type=COL;
        started=true;
    }

    Node * newRow= new Node();
    newRow->type=ROW;
    newRow->isLeaf=false;
    newRow->parent=currentCol;
    vector <Node *> *children=&(currentCol->children);
    children->push_back(newRow);
    currentParent=currentRow=newRow;
*/
}

void LayoutTree::EndRow(){
    currentParent=currentParent->parent;
   // cout<<lastParent<<endl;
    /*currentCol=currentRow->parent;
    currentRow=NULL;*/
}





/*returns a qboxlayout object with all of the
 * nodes contained under the tree that seed is the root of
*/
void * LayoutTree::buildLayout(Node * seed){
    seed = (seed==NULL) ? root : seed;


    QBoxLayout * box;
    QTabWidget * tabCtrl;

    vector<Node *> children= seed->children;
    vector<Node* >::iterator child=children.begin();

    switch (seed->type){

    case ROW:
        box = new QHBoxLayout();

        for (;child!=children.end();vit++){
            if (child->type==ROW){
                cout<<"Can't nest Rows and Rows"<<endl;
                return;
            }

            if (child->isLeaf){
                box->addWidget(child->myWidget);
            }else{
                box->addLayout(buildLayout(child));
            }
        }

        break;
    case COL:
        box = new QVBoxLayout();
       return box;
        // break;
    case TABCTRL:
         tabCtrl = new QTabWidget;
         QWidget * tmp;

         for (;child!=children.end();child++){
             tmp=buildLayout(child);
             tabCtrl->addTab(tmp,"");

         }
        return tabCtrl;
       // break;

    case TAB:
        QWidget * theWidget;
        QBoxLayout * theBox;
        int type=-1;

        for (;child !=children.end();child++){
            if (child->type==ROW) type=1;
            if (child->type==COL) type=2;
        }


        if (type==-1 || type==2)//either no chidlren or they are cols
            theBox=new QVBoxLayout;
        else if (type==1)
            theBox=new QHBoxLayout;


        for (child = children.begin();child!=children.end();child++){
            if (child->isLeaf){
                theBox->addWidget(child->myWidget);
            }else{
                theBox->addLayout(buildLayout(child));
            }

        }
        theWidget->setLayout(theBox);

        return theWidget;

    default: // this is assuming the object is a widget

        break;



    }

   /* QBoxLayout * box;

    if (seed->type==ROW)
        box = new QHBoxLayout();
    else
        box = new QVBoxLayout();

    vector <Node *> children= seed->children;
    for (unsigned int i=0; i< children.size();i++){
        if (children.at(i)->isLeaf){
            Node * child = children.at(i);
            QWidget * widget=child->myWidget;
            box->addWidget(widget);
        }
        else{
            box->addLayout(buildLayout(children.at(i)));
        }
    }

    return box;*/
}

