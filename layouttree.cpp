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
    cout<<root<<endl;
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
    currentParent=currentCol=newCol;
}

void LayoutTree::EndColumn(){
    currentRow=currentCol->parent;
    currentCol=NULL;
}

void LayoutTree::StartRow(){
    if (!started){
        currentCol=root;
        root->type=COL;
        started=true;
    }

    /*if (currentParent->type==ROW){
        std::cout<<"Cannot nest a row within a row"<<endl;
        return;
    }*/
    Node * newRow= new Node();
    newRow->type=ROW;
    newRow->isLeaf=false;
    newRow->parent=currentCol;
    vector <Node *> *children=&(currentCol->children);
    children->push_back(newRow);
    currentParent=currentRow=newRow;

}

void LayoutTree::EndRow(){
    currentCol=currentRow->parent;
    currentRow=NULL;
}


/*returns a qboxlayout object with all of the
 * nodes contained under the tree that seed is the root of
*/
QBoxLayout * LayoutTree::buildLayout(Node * seed){
    seed = seed==NULL ? root : seed;
    QBoxLayout * box;

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

    return box;
}

