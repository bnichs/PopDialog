#ifndef LAYOUTTREE_H
#define LAYOUTTREE_H

#include <QBoxLayout>
#include "tree.h"
#include <vector>
#include "node.h"

using namespace std;

class LayoutTree : public Tree{

public:
    LayoutTree() : Tree() {}

    //~LayoutTree();

    QBoxLayout * buildLayout(Node * seed=NULL);

    void StartColumn();

    void EndColumn();

    void StartRow();

    void EndRow();


};

#endif // LAYOUTTREE_H
