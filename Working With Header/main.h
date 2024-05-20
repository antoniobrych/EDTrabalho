//
// Created by Henrique on 18/05/2024.
//

#ifndef __EDTRABALHO_MAIN_H_
#define __EDTRABALHO_MAIN_H_

// Struct
// Node and your functions
using namespace std;


typedef struct Node
{
    int iPayload;
    Node* ptrNext;
    Node* ptrPrev;
}Node;

Node * createNode(int);
void displayList(Node*);

// Sort Methods



#endif //EDTRABALHO_MAIN_H
