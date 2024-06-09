//
// Created by Jhonny on 09/06/2024.
//

#include "tree.h"
#include <cstdlib>
using namespace std;

Node* createNode(int iValue)
{
    Node* tmp = (Node*) malloc(sizeof(Node));

    if (tmp == nullptr)
    {
        cerr << "Erro em createNode: malloc" << endl;
        exit(1);
    }

    tmp->iPayload = iValue;
    tmp->ptrLeft = nullptr;
    tmp->ptrRight = nullptr;

    return tmp;
}

Node* insertNode(Node* startingNode, int iData)
{
    if(startingNode == nullptr)
    {
        return createNode(iData);
    }

    if(iData < startingNode->iPayload)
    {
        startingNode->ptrLeft = insertNode(startingNode->ptrLeft, iData);
    }
    else
    {
        startingNode->ptrRight = insertNode(startingNode->ptrRight, iData);
    }

    return startingNode;
}

void bfsTraversal_Queue(Node* startingNode)
{
    if (startingNode == nullptr) return;

    Node* nodeQueue[100];
    int iQueueFront = 0;
    int iQueueRear = 0;

    nodeQueue[iQueueRear] = startingNode;
    iQueueRear++;

    while (iQueueFront < iQueueRear)
    {
        Node* currentNode = nodeQueue[iQueueFront];
        iQueueFront++;

        cout << currentNode->iPayload << " ";

        if (currentNode->ptrLeft != nullptr)
        {
            nodeQueue[iQueueRear] = currentNode->ptrLeft;
            iQueueRear++;
        }

        if (currentNode->ptrRight != nullptr)
        {
            nodeQueue[iQueueRear] = currentNode->ptrRight;
            iQueueRear++;
        }
    }
}

int treeHeight(Node* startingNode)
{
    if (startingNode == nullptr) return 0;
    else
    {
        int iLeftHeight = treeHeight(startingNode->ptrLeft);
        int iRightHeight = treeHeight(startingNode->ptrRight);

        return max(iLeftHeight, iRightHeight) + 1;
    }
}

/*
 *  BFS Transversal
 */
void bfsTraversal(Node* startingNode)
{
    if (startingNode == nullptr) return;

    ListNode* front = nullptr;
    ListNode* rear = nullptr;

    ListNode* newNode = (ListNode*) malloc(sizeof(ListNode));
    newNode->treeNode = startingNode;
    newNode->next = nullptr;

    front = rear = newNode;

    while (front != nullptr)
    {
        Node* currentNode = front->treeNode;
        cout << currentNode->iPayload << " ";

        if (currentNode->ptrLeft != nullptr)
        {
            ListNode* newLeftNode = (ListNode*) malloc(sizeof(ListNode));
            newLeftNode->treeNode = currentNode->ptrLeft;
            newLeftNode->next = nullptr;
            rear->next = newLeftNode;
            rear = newLeftNode;
        }

        if (currentNode->ptrRight != nullptr)
        {
            ListNode* newRightNode = (ListNode*) malloc(sizeof(ListNode));
            newRightNode->treeNode = currentNode->ptrRight;
            newRightNode->next = nullptr;
            rear->next = newRightNode;
            rear = newRightNode;
        }

        ListNode* temp = front;
        front = front->next;
        free(temp);
    }
}

/*
 * Parte 2 BFS search
 */

bool bfsSearch(Node* startingNode, int target)
{
    if (startingNode == nullptr) return false;

    ListNode* front = nullptr;
    ListNode* rear = nullptr;

    ListNode* newNode = (ListNode*) malloc(sizeof(ListNode));
    newNode->treeNode = startingNode;
    newNode->next = nullptr;

    front = rear = newNode;

    while (front != nullptr)
    {
        Node* currentNode = front->treeNode;

        if (currentNode->iPayload == target) return true;

        if (currentNode->ptrLeft != nullptr)
        {
            ListNode* newLeftNode = (ListNode*) malloc(sizeof(ListNode));
            newLeftNode->treeNode = currentNode->ptrLeft;
            newLeftNode->next = nullptr;
            rear->next = newLeftNode;
            rear = newLeftNode;
        }

        if (currentNode->ptrRight != nullptr)
        {
            ListNode* newRightNode = (ListNode*) malloc(sizeof(ListNode));
            newRightNode->treeNode = currentNode->ptrRight;
            newRightNode->next = nullptr;
            rear->next = newRightNode;
            rear = newRightNode;
        }

        ListNode* temp = front;
        front = front->next;
        free(temp);
    }

    return false;
}
