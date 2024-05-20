//
// Created by Henrique on 18/05/2024.
//

#include <iostream>
#include "main.h"
using namespace std;

// File of Sort Functions

void bubbleSort(Node* head)
{
    if (head == nullptr||head->ptrNext == nullptr)
    {

        cout<<"List already sorted!"<<endl;

        return;

    }
    bool bIsSorted = false;

    Node *ptrAdj1, *ptrAdj2;

    while (!bIsSorted)
    {
        ptrAdj1 = head;
        ptrAdj2 = head->ptrNext;
        bIsSorted = true;
        while (ptrAdj2)
        {
            if (ptrAdj1->iPayload > ptrAdj2->iPayload)
            {
                int temp = ptrAdj1->iPayload;
                ptrAdj1->iPayload = ptrAdj2->iPayload;
                ptrAdj2->iPayload = temp;
                bIsSorted = false;
            }
            ptrAdj2 = ptrAdj2->ptrNext;
            ptrAdj1 = ptrAdj1->ptrNext;
        }
    }
}

void selection_sort(Node* head)
{
    int aux1;
    for (Node* node_1 = head; node_1 != nullptr; node_1 = node_1->ptrNext)
    {
        for (Node* node_2 = node_1->ptrNext; node_2 != nullptr; node_2 = node_2->ptrNext)
        {
            if (node_1->iPayload < node_2->iPayload)
            {
                aux1 = node_1->iPayload;
                node_1->iPayload = node_2->iPayload;
                node_2->iPayload = aux1;
            }
        }
    }
}

void insertionSort(Node** head)
{
    if ((*head) == nullptr || (*head)->ptrNext == nullptr)
    {
        return;
    }

    Node* sorted = nullptr;
    Node* current = (*head);

    while (current != nullptr)
    {
        Node* next = current->ptrNext;

        if (sorted == nullptr || sorted->iPayload >= current->iPayload)
        {
            current->ptrNext = sorted;
            if (sorted != nullptr)
            {
                sorted->ptrPrev = current;
            }
            sorted = current;
            sorted->ptrPrev = nullptr;
        }
        else
        {
            Node* temp = sorted;
            while (temp->ptrNext != nullptr && temp->ptrNext->iPayload < current->iPayload)
            {
                temp = temp->ptrNext;
            }
            current->ptrNext = temp->ptrNext;
            if (temp->ptrNext != nullptr)
            {
                temp->ptrNext->ptrPrev = current;
            }
            temp->ptrNext = current;
            current->ptrPrev = temp;
        }
        current = next;
    }
    (*head) = sorted;
}

