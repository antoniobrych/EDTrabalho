//
// Created by Jhonny on 20/05/2024.
//
#include<iostream>
#include <chrono>
#include <ctime>
#define Quantidade 10 // Quantidade de listas geradas
#define quantLista 10 // Quantidade de elementos em cada lista

using std::cout;
using std::endl;

using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::nanoseconds;

void bubble_sort(int a[],int length_a)
{
    bool swapped;
    int i = 0;
    do
    {
        swapped = false;
        for (int j = 0 ; j < length_a - 1 - i ; j ++ )
        {
            if (a[j] > a[j+1])
            {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp ;
                swapped = true;
            }
        }
        i++;
    } while(swapped);
    cout<< "Lista ordenada: " << endl;

    for (int k = 0 ; k < length_a; k++)
    {
        std::cout << a[k] << " ";
    }
    cout << endl;

}

int main()
{
    int tempos[Quantidade];
    for (int q = 0; q < Quantidade; q++)
    {
        unsigned seed = time(0);
        int lista[quantLista];
        cout << "Lista inicial: " << endl;
        for (int l = 0; l < quantLista; l ++)
        {
            lista[l] = 1+rand()%100;

            cout << lista[l] << " ";
        }
        cout << endl;
        auto timeStart = high_resolution_clock::now();
        bubble_sort(lista,quantLista);
        auto timeStop = high_resolution_clock::now();
        auto timeDuration = duration_cast<nanoseconds>(timeStop-timeStart);
        cout << "Tempo utilizado: " << timeDuration.count() << " nanosegundos." << endl;
        tempos[q] = timeDuration.count();
        cout << endl;
    }
    cout << "tempos: "<< endl;

    for (int y = 0; y < Quantidade; y ++)
    {
        cout<< tempos[y] << " ";
    }

    cout << endl;

    int mean = 0;
    for (int t = 0; t < Quantidade; t ++)
    {
        mean += tempos[t];
    }
    mean = mean/Quantidade;
    cout << "tempo medio: " << mean << endl;

    return 0;
}
