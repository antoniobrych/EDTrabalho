#include "tree.h"
#include "tree.cpp"

#include <chrono>
#include <iostream>
using namespace std;
using namespace std::chrono;

// Define a new structure for nodes in the linked list
struct LinkedListNode {
    int iPayload;
    LinkedListNode* ptrNext;
    LinkedListNode* ptrPrev;
};

void displayList(LinkedListNode* node) {
    if (node == nullptr) {
        cout << "Lista Vazia: Não é possível realizar displayList" << endl;
        return;
    }
    LinkedListNode* temp = node;
    cout << "Payload: ";
    while (temp != nullptr) {
        cout << temp->iPayload << " ";
        temp = temp->ptrNext;
    }
    cout << endl;
}

void insertEnd(LinkedListNode** head, int iPayload) {
    LinkedListNode* newNode = (LinkedListNode*)malloc(sizeof(LinkedListNode));
    newNode->iPayload = iPayload;
    newNode->ptrNext = nullptr;
    newNode->ptrPrev = nullptr;

    if (*head == nullptr) {
        (*head) = newNode;
        return;
    }
    LinkedListNode* temp = (*head);
    while (temp->ptrNext != nullptr) {
        temp = temp->ptrNext;
    }
    newNode->ptrPrev = temp;
    temp->ptrNext = newNode;
}

int main() {
    Node* root = nullptr;

    // Parte 5 do Trabalho: Monitorar o desempenho de criação de árvores
    // Cria uma árvore binária de grande profundidade
    auto startTree = high_resolution_clock::now();
    for (int i = 1; i <= 10000; ++i) {
        root = insertNode(root, i);
    }
    auto stopTree = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stopTree - startTree);
    cout << "Tree creation time: " << duration.count()<<" microseconds." << endl;

    cout << "BFS Traversal: ";
    bfsTraversal(root);
    cout << endl;

    cout << "Tree Height: " << treeHeight(root) << endl;

    int searchValue = 9999;

    auto startBFS = high_resolution_clock::now();
    Node* foundNodeBFS = bfsSearch(root, searchValue);
    auto stopBFS = high_resolution_clock::now();
    auto durationBFS = duration_cast<microseconds>(stopBFS - startBFS);

    auto startDFS = high_resolution_clock::now();
    Node* foundNodeDFS = dfsSearch(root, searchValue);
    auto stopDFS = high_resolution_clock::now();
    auto durationDFS = duration_cast<microseconds>(stopDFS - startDFS);

    cout << "BFS Search: " << (foundNodeBFS != nullptr ? "Found" : "Not Found") << " in " << durationBFS.count() << " microseconds." << endl;
    cout << "DFS Search: " << (foundNodeDFS != nullptr ? "Found" : "Not Found") << " in " << durationDFS.count() << " microseconds." << endl;

    // Parte 4 do Trabalho: Monitorar o desempenho de criação de listas
    auto startListCreation = high_resolution_clock::now();
    LinkedListNode* myList = nullptr;
    for (int i = 1; i <= 10000; ++i) {
        insertEnd(&myList, i);
    }
    auto stopListCreation = high_resolution_clock::now();
    auto durationListCreation = duration_cast<microseconds>(stopListCreation - startListCreation);

    cout << "List Creation Time: " << durationListCreation.count() << " microseconds." << endl;

    return 0;
}
