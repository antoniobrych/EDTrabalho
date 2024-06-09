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
