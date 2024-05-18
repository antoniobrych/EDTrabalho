#include <iostream>
#include <chrono>
#include <chrono>
#include <iostream>
#include <cmath>
using namespace std;
using namespace std::chrono;

//Tarefa feita por:

//Henrique Borges (mat. 231708033)
//Antonio Joaquim Brych (mat. 231708901)

typedef struct Node{
    int iPayload;
    Node* ptrNext;
    Node* ptrPrev;
}Node;

Node * createNode(int);
void insertFront(Node**,int);
void insertEnd(Node**,int);
void displayList(Node*);
void insertAfter(Node*, int);
void deleteNode(Node**,Node*);
void insertBefore(Node*, int);
void bubbleSort(Node*);
void deleteNodebyValue(Node**,int);
Node* searchNodebyValue(Node**,int);
void selection_sort(Node* head);
void selection_sort_2(Node* head);

int main() {

    const int num_executions = 100;
    int arr_exec[num_executions] = {};
    int arr_exec2[num_executions] = {};

    // Teste selection sort 1
    for (int i = 0; i < num_executions; ++i) {
        Node* head = nullptr;
        for (int i = -1000; i <= 0; i++) {
            insertEnd(&head, i * i * i);
        }
        auto start = high_resolution_clock::now();
        selection_sort(head);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        arr_exec[i] = duration.count();
    }

    // Teste selection sort 2
    for (int i = 0; i < num_executions; ++i) {
        Node* head = nullptr;
        for (int i = -1000; i <= 0; i++) {
            insertEnd(&head, i * i * i);
        }
        auto start = high_resolution_clock::now();
        selection_sort_2(head);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        arr_exec2[i] = duration.count();
    }

    int sum = 0;
    for (int i = 0; i < num_executions; ++i) {
        sum += arr_exec[i];
    }
    double average = static_cast<double>(sum) / num_executions;
    cout << "Average execution time of Selection Sort 1 (" << num_executions << " executions): " << average << " microseconds" << endl;

    double standard_deviation = 0;
    double sum2 = 0;
    for (int i = 0; i < num_executions; ++i) {
        sum2 += pow(arr_exec[i] - average, 2);
    }
    standard_deviation = sqrt(sum2 / num_executions);
    cout << "Standard deviation of execution time for Selection Sort 1 (" << num_executions << " executions): " << standard_deviation << " microseconds" << endl;

    sum = 0;
    for (int i = 0; i < num_executions; ++i) {
        sum += arr_exec2[i];
    }
    average = static_cast<double>(sum) / num_executions;
    cout << "Average execution time of Selection Sort 2 (" << num_executions << " executions): " << average << " microseconds" << endl;

    standard_deviation = 0;
    sum2 = 0;
    for (int i = 0; i < num_executions; ++i) {
        sum2 += pow(arr_exec2[i] - average, 2);
    }
    standard_deviation = sqrt(sum2 / num_executions);
    cout << "Standard deviation of execution time for Selection Sort 2 (" << num_executions << " executions): " << standard_deviation << " microseconds" << endl;

    return 0;
}



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

void insertFront(Node** head,int iPayload){
    //função que insere elemento no inicio da lista
    Node* newNode = createNode(iPayload);
    // newNode->ptrPrev = nullptr
    if (*head != nullptr){
        (*head) = newNode;
        return;
    }
    (*head) = newNode;
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

void insertAfter(Node* ptrLocation, int iPayload){
    //funcao que insere elemento após outro, na lista

    if( ptrLocation == nullptr){
        cout << "Location e NULL." << endl;
        return;
    }
    Node* newNode = createNode(iPayload);
    // Corrigir nó a ser inserido
    newNode->ptrNext = ptrLocation->ptrNext;
    newNode->ptrPrev = ptrLocation;

    //corrigir ponto de insercao
    ptrLocation->ptrNext = newNode;
    if(newNode->ptrNext != nullptr) (newNode->ptrNext)->ptrPrev = newNode;

}


void deleteNode(Node** head,Node* ptrDelete){
    //funcao que apaga elemento da lista, com o elemento
    // a ser deletado

    if (head == nullptr || ptrDelete == nullptr){
        cout << "Nao foi possivel remover. " << endl;
        return;
    }
    // Caso o ptrDelete seja o primeiro elemento da lista
    if(*head == ptrDelete) (*head)= ptrDelete->ptrNext;

    // Se o ptrDelete nao e o ultimo no
    if(ptrDelete->ptrNext != nullptr) ptrDelete->ptrNext->ptrPrev = ptrDelete->ptrPrev;

    // Se o ptrDelete nao e o primeiro no
    if (ptrDelete->ptrPrev != nullptr) ptrDelete->ptrPrev->ptrNext = ptrDelete->ptrNext;


    free(ptrDelete);
}

// Exercício 1. Elaborar a funcao
// void insertBefore(Node*,int);

void insertBefore(Node* ptrLocation, int iPayload){
    //inserir antes de um elemento especifico
    if (ptrLocation == nullptr) {
        cout << "Lista vazia. " << endl;
        return;
    }
    Node* newNode = createNode(iPayload);
    if (ptrLocation->ptrPrev == nullptr){
        ptrLocation->ptrPrev = newNode;
        newNode->ptrNext = ptrLocation;
        newNode->ptrPrev = nullptr;
        cout << "Elemento inserido no inicio: " << iPayload << endl;
        return;
    }
    newNode->ptrPrev = ptrLocation->ptrPrev;
    newNode->ptrNext = ptrLocation;
    ptrLocation->ptrPrev->ptrNext = newNode;
    ptrLocation->ptrPrev = newNode;
    cout << "Elemento inserido antes de " << ptrLocation->iPayload << ":" << iPayload << endl;
    return;
}

// Exercício 2. Elaborar a funcao:
// void deleteNodebyValue(Node**,int);
void deleteNodebyValue(Node** head,int iPayload){
    //apaga elemento com valor especifico
    if (head == nullptr){
        cout << "Lista vazia: " << endl;
        return;
    }

    Node* searchResult = searchNodebyValue(head,iPayload);
    if (searchResult == nullptr){
        return;
    }
    deleteNode(head, searchResult);

}

// Exercício 3. Elaborar a funcao:
// Node* searchNodebyValue(Node**,int);
Node* searchNodebyValue(Node** head,int iPayload){
    //procura valor especifico na lista e o retorna
    if (head == nullptr){
        cout << "Lista vauzia. " << endl;
        return nullptr;
    }
    Node* newNode = createNode(iPayload);
    Node* temp = (*head);

    while (temp != nullptr){
        if (temp->iPayload == newNode->iPayload){
            newNode = temp;
            cout << "Elemento encontrado: " << newNode->iPayload << endl;
            return newNode;
        }
        temp = temp->ptrNext;
    }
    cout << "Elemento nao encontrado, " << newNode->iPayload << " nao esta na lista."<<endl;
    return nullptr;
}



void selection_sort(Node* head) {
    int aux1;
    for (Node* node_1 = head; node_1 != nullptr; node_1 = node_1->ptrNext) {
        for (Node* node_2 = node_1->ptrNext; node_2 != nullptr; node_2 = node_2->ptrNext) {
            if (node_1->iPayload < node_2->iPayload) {
                aux1 = node_1->iPayload;
                node_1->iPayload = node_2->iPayload;
                node_2->iPayload = aux1;
            }
        }
    }
}

void selection_sort_2(Node* head) {
    int aux1;
    for (Node* node_1 = head; node_1 != nullptr; node_1 = node_1->ptrNext) {
        Node* menor = node_1;
        for (Node* node_2 = node_1->ptrNext; node_2 != nullptr; node_2 = node_2->ptrNext) {
            if (node_2->iPayload < menor->iPayload) { // Correção aqui
                menor = node_2;
            }
        }
        aux1 = node_1->iPayload;
        node_1->iPayload = menor->iPayload;
        menor->iPayload = aux1;
    }
}