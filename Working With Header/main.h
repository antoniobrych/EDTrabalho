
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
void insertEnd(Node** ,int );

// Sort Methods
void bubbleSort(Node*);
void selection_sort(Node* head);
void insertionSort(Node** head);

// ShellSort
void shellSort(Node** head);


#endif //EDTRABALHO_MAIN_H
