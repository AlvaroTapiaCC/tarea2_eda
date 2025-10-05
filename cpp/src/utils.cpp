#include "utils.hpp"
#include "linkedList.hpp"
#include <iostream>
#include <fstream>

using namespace std;
using namespace eda;

size_t* createIndexArray(size_t n){
    size_t* arr = new size_t[n];
    for (size_t i = 0; i < n; i++){
        arr[i] = i;
    }
    return arr;
}

void swap(Poscode* A, size_t i, size_t j){
    Poscode aux = A[i];
    A[i] = A[j];
    A[j] = aux;
}

size_t getRandomInt(size_t min, size_t max){
    float a = rand() / static_cast<float>(RAND_MAX);
    return static_cast<size_t>(a * (max - min) + min + 0.5);
}

size_t split_qs(Poscode* A, size_t i, size_t j){

    size_t p = getRandomInt(i, j);

    while (i  < j) {

        while ( i < p && A[i].getData() <= A[p].getData()){
            i = i + 1;
        }

        while ( j > p && A[j].getData() >= A[p].getData()){
            j = j - 1;
        }

        swap(A, i, j);

        if (i == p){
            p = j;
        }
        else if (j == p){
            p = i;
        }
    }
    return p;
}

void quick_sort(Poscode* A, size_t i, size_t j){
    if (i < j){
        size_t k = split_qs(A, i, j);
        if (k > 0){
            quick_sort(A, i, k-1);
        }
        quick_sort(A, k + 1, j);
    }
}

void quick_sort(Poscode* A, size_t n){
    quick_sort(A, 0, n - 1);
}

void counting_sort(const Poscode* originalCodes, size_t* &A, size_t n, int p, int M){
    LinkedList Lists[M];                    // arreglo de listas enlazadas para cada posible valor de la posicion p

    for (size_t c = 0; c < n; c++){         // recorrer arreglo de codigos
        char ch = originalCodes[A[c]].getValue(p-1);       // valor de la posicion p
        int idx = -1;                       // indice para identificar la lista, tiene que ser int

        if (p < 5 && ch >= '0' && ch <= '9') {
            idx = ch - '0';                 // distancia entre caracteres numericos en la tabla ASCII
        }
        else if (p >= 5 && ch >= 'A' && ch <= 'Z') {
            idx = ch - 'A';                 // distancia entre letras mayuscula en la tabla ASCII
        }

        Lists[idx].insertLast(A[c]);        // agregar poscode en la tail de la lista, agrupandolos segun su valor en la posicion p
    }

    int k = 0;
    for (int i = 0; i < M; i++){            // recorrer listas en orden creciente
        Node* ptr = Lists[i].getHead();     // obtener head de cada lista
        
        while (ptr != nullptr){             // recorrer nodos de la lista        
            A[k] = ptr->getData();          // volver a llenar A con poscodes ordenados
            k++;
            ptr = ptr->getNext();           // avanzar en la lista
        }
    }

    return;
}

void merge_sort(Poscode *A, size_t n){

}

void radix_sort(const Poscode* originalCodes, size_t* &A, size_t n){
    counting_sort(originalCodes, A, n, 6, 26);
    counting_sort(originalCodes, A, n, 5, 26);
    for (int p = 4; p > 0; p--){
        counting_sort(originalCodes, A, n, p, 10);
    }
}

Poscode *readCodes(const std::string &strfile, size_t n){
    // Replace "example.txt" with the actual path to your text file.
    Poscode *codes = new Poscode[n];

    std::ifstream inputFile(strfile);    
    if (!inputFile.is_open()) {
        std::cerr << "Error: Unable to open the file!" << std::endl;        
        return nullptr;
    }
    // 3. Read the file content line by line.
    std::string line;
    for(size_t i = 0; i < n; i++){
        std::getline(inputFile, line); 
        codes[i] = Poscode(line);
    }
    
    inputFile.close();
    return codes;
}

void deleteCodes(Poscode *codes){
    if (codes != nullptr) {
        delete[] codes;
    }    
}