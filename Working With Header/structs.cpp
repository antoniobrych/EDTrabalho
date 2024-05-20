// Includes and usings:
#include <iostream>
#include "main.h"
// file of structs

Node* createNode(int iPayload){
    //função que cria um nó
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->iPayload = iPayload;
    temp->ptrNext = nullptr;
    temp->ptrPrev = nullptr;

    return  temp;
}

void displayList(Node* node){
    //função que exibe lista
    if(node == nullptr){
        cout << "Lista Vazia: Nao e possivel realizar displayList" << endl;
        return;
    }
    if(node->ptrPrev != nullptr){
        cout << "Meio ou fim da Lista: Não é possível realizar displayList" << endl;
        return;
    }
    Node* temp = node;
    cout << "Payload: ";
    while (temp != nullptr){
        cout << temp->iPayload << " ";
        temp = temp->ptrNext;
    }

    cout << endl;
}

void insertEnd(Node** head,int iPayload){
    //funcao que insere elemento no final da lista
    Node* newNode = createNode(iPayload);
    if (*head == nullptr){
        (*head) = newNode; // Inicio, meio e fim Raul Seixas
        return;
    }
    Node * temp = (*head);

    while (temp->ptrNext != nullptr){
        temp = temp->ptrNext;
    }
    newNode->ptrPrev = temp;
    temp->ptrNext = newNode;
}