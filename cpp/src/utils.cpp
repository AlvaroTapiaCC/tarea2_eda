#include "utils.hpp"
#include "linkedList.hpp"
#include <iostream>
#include <fstream>

using namespace std;
using namespace eda;

void split_qs(Poscode *A, size_t i, size_t j){

}

void counting_sort(Poscode* &A, size_t n, int p, int M){
    LinkedList Lists[M];                    // arreglo de listas enlazadas para cada posible valor de la posicion p

    // cout << "\n== p = " << p << " ==" << endl;

    for (size_t c = 0; c < n; c++){         // recorrer arreglo de codigos
        char ch = A[c].getValue(p-1);       // valor de la posicion p
        int idx = -1;                       // indice para identificar la lista, tiene que ser int

        if (p < 5 && ch >= '0' && ch <= '9') {
            idx = ch - '0';                 // distancia entre caracteres numericos en la tabla ASCII
        } else if (p >= 5 && ch >= 'A' && ch <= 'Z') {
            idx = ch - 'A';                 // distancia entre letras mayuscula en la tabla ASCII
        }

        Lists[idx].insertLast(c);           // agregar poscode en la tail de la lista, agrupandolos segun su valor en la posicion p
    }

    Poscode* temp = new Poscode[n];
    for (size_t i = 0; i < n; i++){
        temp[i] = A[i];
    }

    delete[] A;                             // liberar memoria de A
    A = new Poscode[n];                     // arreglo vacio

    int k = 0;
    for (int i = 0; i < M; i++){            // recorrer listas en orden creciente
        Node* ptr = Lists[i].getHead();     // obtener head de cada lista
        
        while (ptr != nullptr){             // recorrer nodos de la lista        
            A[k] = temp[ptr->getData()];    // volver a llenar A con poscodes ordenados
            k++;
            ptr = ptr->getNext();           // avanzar en la lista
        }
    }
    delete[] temp;

    // visualizar listas para depuracion
    /*for (int i = 0; i < M; i++){
        if (M == 26) { 
             cout << "\n--Lista " << static_cast<char>('A' + i) << "--\n" << endl;
             Lists[i].print();
        } else {
             cout << "\n--Lista " << i << "--\n" << endl;
             Lists[i].print();
        }
    }*/

    // visualizar arreglo para depuracion
    /*cout << "===Arreglo ordenado segun posicion " << p << "===" << endl;
    for (size_t i = 0; i < n; i=i+10){
        if (i < n){
            cout << A[i].getData() << endl;
        }
    }*/

    return;
}

void quick_sort(Poscode *A, size_t n){

}

void merge_sort(Poscode *A, size_t n){

}

void radix_sort(Poscode* &A, size_t n){
    counting_sort(A, n, 6, 26);
    counting_sort(A, n, 5, 26);
    for (int p = 4; p > 0; p--){
        counting_sort(A, n, p, 10);
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