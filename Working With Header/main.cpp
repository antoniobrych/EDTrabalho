#include "tree.h"
#include <chrono>
#include "tree.cpp"
#include <iostream>
using namespace std;
using namespace std::chrono;

int main()
{
    Node* root = nullptr;

    // Cria uma árvore binária de grande profundidade
    for (int i = 1; i <= 10000; ++i)
    {
        root = insertNode(root, i);
    }

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

    return 0;
}

/*
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
void displayarray(int a[],int siz);

int main()
{
    int a[] = {3,0,1,8,7,2,5,4, 9, 6};

    cout << "Using ShellSort: " << endl;
    Node* head = nullptr;
    generateRandomDLL(&head, 10);
    displayList(head);
    cout << endl;
    cout << "Sorted by ShellSort: " << endl;
    shellSort(&head);
    displayList(head);
    cout << "Vamos fazer um caso de exemplo: https://www.youtube.com/watch?v=yn0EgXHb5jc " << endl;
    cout << "Considere a seguinte lista: ";
    for (int i = 0 ; i < 10 ; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    cout << "Vamos fazer a primeira iteração:" << endl;
    cout << "Encontramos o size da lista: 10" << endl;
    cout << "Temos o gap: size/2 --> gap = 10/2 " << endl;
    cout << "Fazemos a comparação do a[gap], a[5] com o a[0] " << endl;
    cout << "nesse caso, 2 < 3, então trocam de posição." << endl;
    cout << "E proseguimos fazendo as comparações a[5+1] a[0+1], e depois a[5+2] a[0+2] até chegar ao a[9] a[4]"<< endl;
    for (int j = 5 ; j <= 9 ; j ++)
    {
        if(a[j] < a[j-5])
        {
            int temp = a[j];
            a[j] = a[j-5];
            a[j-5] = temp;
        }
        displayarray(a,10);
        cout << endl;
    }
    cout << "Vemos que fora alterado apenas na primeira e na ultima iteracao."<< endl;
    cout << "Agora atualizamos o gap. Gap = 5/2, nesse caso usamos gap = 3" << endl;
    cout << "Fazemos a primeira iteracao: a[3] a[0] e prosseguimos como anteriormente" << endl;
    for (int k = 3; k<=9; k++)
    {
        if(a[k] < a[k - 3])
        {
            int temp = a[k];
            a[k] = a[k-3];
            a[k-3] = temp;
        }
        displayarray(a, 10);
        cout << endl;
    }
    cout << " E então, novamente reduzimos o gap pra 1" << endl;
    for (int k = 1; k<=9; k++)
    {
        if(a[k] < a[k - 1])
        {
            int temp = a[k];
            a[k] = a[k-1];
            a[k-1] = temp;
        }
        displayarray(a, 10);
        cout << endl;
    }

    return 0;
}

void displayarray(int a[],int siz)
{
    for (int i = 0; i < siz;i++)
    {
        cout << a[i] << " ";
    }
}
*/