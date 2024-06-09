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

struct ListNode
{
    Node* treeNode;
    ListNode* next;
};
void bfsTraversal(Node*);

Node* bfsSearch(Node*, int);
Node* dfsSearch(Node* , int );

Node* createNode(int);
Node* insertNode(Node*, int);
void bfsTraversal_Queue(Node*);
int treeHeight(Node*);


#endif //EDTRABALHO_TREE_H
