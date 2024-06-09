//
// Created by Jhonny on 09/06/2024.
//

#ifndef EDTRABALHO_TREE_H
#define EDTRABALHO_TREE_H

#include <iostream>

struct Node
{
    int iPayload;
    Node* ptrLeft;
    Node* ptrRight;
};

Node* createNode(int);
Node* insertNode(Node*, int);
void bfsTraversal_Queue(Node*);
int treeHeight(Node*);


#endif //EDTRABALHO_TREE_H
