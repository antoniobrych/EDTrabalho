//
// Created by Henrique on 18/05/2024.
//
#include <iostream>
#include "main.h"
using namespace std;

void generateRandomDLL(Node** head, int numNodes)
{
    for (int i = 0; i < numNodes; ++i) {
        int payload = rand() % 100;
        insertEnd(head, payload);
    }
}

int main()
{
    cout << "Using ShellSort: " << endl;
    Node* head = nullptr;
    generateRandomDLL(&head, 30);
    displayList(head);
    cout << endl;
    cout << "Sorted by ShellSort: " << endl;
    shellSort(&head);
    displayList(head);


    return 0;
}

//
//  1 , 2 ,5 , 4 , 3 , 6,
// h = 4
// [ 1 , 4] [2, 3] [5 , 6]
// h = 2
// [1 , 2] [2 , 5] [5 ,4] [4,3] [3 ,6]
//
//
