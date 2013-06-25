#include "tree.h"
#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

void printTabs(int n){
    cout<< string(n,'\t');
}

Tree::Tree(){
    root=currentParent=new Node();
    root->isLeaf=false;
    started=false;
    currentLevel=0;
}

Tree::~Tree(){
    delete root;
}

//adds a node at the current tree position
void Tree::addNode(Node * node){
    handleMap[node->handle]= node;
    node->parent=currentParent;
    currentParent->addChild(node);
}

void Tree::printTree(Node * seed){
    if (seed==NULL)
        seed=root;

    printTabs(currentLevel);
    if (seed->isLeaf){
        cout<<seed->getType()<<": "<<seed->handle<<endl;
        return;
    }
    else{
       // cout<< (seed->isRow ? "^Row" : "^Col" )<<seed<<endl;
        cout<< "^" << seed->getType() <<": " <<seed<<endl;
        currentLevel++;
        for (unsigned int i = 0; i < seed->children.size(); i++){
            printTree(seed->children.at(i));
        }
        currentLevel--;

        printTabs(currentLevel);
        cout<< "~" << seed->getType() <<": " <<seed<<endl;
    }
}


