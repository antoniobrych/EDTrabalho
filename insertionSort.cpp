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
void insertionSort(Node**);
void deleteNodebyValue(Node**,int);
Node* searchNodebyValue(Node**,int);


int main() {
    int arri_exec[100] = {};
    //Criando uma lista encadeada vazia
    Node* head = nullptr;

    displayList(head);

    //inserindo um elemento no início da lista
    insertFront(&head,92);

    //inserindo elementos no final da lista
    insertEnd(&head,0);
    insertEnd(&head,1);
    insertEnd(&head,2);
    insertEnd(&head,3);

    displayList(head);

    //inserindo um novo nó antes do segundo nó da lista
    insertBefore(head->ptrNext,999);

    displayList(head);

    Node* foundNode = searchNodebyValue(&head, 2);

    //procurando por um nó com o valor 5 na lista
    Node* inexistentNode = searchNodebyValue(&head, 5);

    //excluindo um nó com o valor 0 da lista
    deleteNodebyValue(&head, 0);

    //exibindo a lista após a exclusão
    displayList(head);

    //excluindo um nó com o valor 122 (inexistente) da lista
    //testando se função está operando corretamente.
    deleteNodebyValue(&head, 122);

    displayList(head);

    //excluindo um nó com o valor 3 da lista
    deleteNodebyValue(&head, 3);

    //exibindo a lista após a exclusão
    displayList(head);
    const int num_executions = 100;
    int arr_exec[num_executions] = {};

    //laço para executar o teste várias vezes
    for (int i = 0; i < num_executions; ++i) {
        //código do teste
        Node* head = nullptr;
        for(int i = -1000;i<=0;i++){
            insertEnd(&head,i*i*i);
        }
        //cdigo de inicialização da lista e execução do Bubble Sort
        auto start = high_resolution_clock::now();
        insertionSort(&head);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        //armazena o tempo de execção em array
        arr_exec[i] = duration.count();
    }

    // Calcula a média dos tempos de execução
    int sum = 0;
    for (int i = 0; i < num_executions; ++i) {
        sum += arr_exec[i];
    }
    double average = static_cast<double>(sum) / num_executions;

    // Imprime a média dos tempos de execução
    cout << "Tempo médio de execução do Insertion Sort (" << num_executions << " execuções): " << average << " microssegundos" << endl;

    double standard_deviation = 0;
    double sum2 = 0;

    for (int i = 0; i < num_executions; ++i) {
        sum2 += pow(arr_exec[i] - average, 2);
    }

    // Calcula o  desvio padrão
    standard_deviation = sqrt(sum2 / num_executions);
    cout << "Desvio padrão de execução do Insertion Sort (" << num_executions << " execuções): " << standard_deviation << " microssegundos" << endl;

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



void insertionSort(Node** head) {
    if ((*head) == nullptr || (*head)->ptrNext == nullptr) {
        return;
    }

    Node* sorted = nullptr;
    Node* current = (*head);

    while (current != nullptr) {
        Node* next = current->ptrNext;

        if (sorted == nullptr || sorted->iPayload >= current->iPayload) {
            current->ptrNext = sorted;
            if (sorted != nullptr) {
                sorted->ptrPrev = current;
            }
            sorted = current;
            sorted->ptrPrev = nullptr;
        } else {
            Node* temp = sorted;
            while (temp->ptrNext != nullptr && temp->ptrNext->iPayload < current->iPayload) {
                temp = temp->ptrNext;
            }
            current->ptrNext = temp->ptrNext;
            if (temp->ptrNext != nullptr) {
                temp->ptrNext->ptrPrev = current;
            }
            temp->ptrNext = current;
            current->ptrPrev = temp;
        }
        current = next;
    }

    (*head) = sorted;
}
