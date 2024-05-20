//
// Created by Henrique on 18/05/2024.
//
#include <iostream>
#include "main.h"
using namespace std;

int main()
{
    cout << "initializing" << std::endl;
    Node* myNode = createNode(1);
    cout << myNode->iPayload << endl;

    return 0;
}
