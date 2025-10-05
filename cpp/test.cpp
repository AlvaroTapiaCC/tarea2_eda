#include "poscode.hpp"
#include "utils.hpp"
#include <string>
#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main(int nargs, char** vargs){
    srand(time(0));
    
    string strfile("../../code_files/codes_500K.txt");
    size_t n = 500000;

    Poscode *original_data = readCodes(strfile, n);
    size_t *sorted = createIndexArray(n);

    // RADIX
    cout << "\nSorting with radix_sort ..." << endl;
    auto radix_start = high_resolution_clock::now();
    radix_sort(original_data, sorted, n);
    auto radix_end = high_resolution_clock::now();
    duration<double> radix_time = radix_end - radix_start;
    cout << "Tiempo de ordenamiento: " << radix_time.count() * 1000 << " milisegundos" << endl;

    // QUICK
    cout << "\nSorting with quick_sort ..." << endl;
    auto quick_start = high_resolution_clock::now();
    quick_sort(original_data, n);
    auto quick_end = high_resolution_clock::now();
    duration<double> quick_time = quick_end - quick_start;
    cout << "Tiempo de ordenamiento: " << quick_time.count() * 1000 << " milisegundos" << endl;    

    // MERGE
    cout << "\nSorting with merge_sort ..." << endl;
    auto merge_start = high_resolution_clock::now();
    // radix_sort(original_data, n);
    auto merge_end = high_resolution_clock::now();
    duration<double> merge_time = merge_end - merge_start;
    cout << "Tiempo de ordenamiento: " << merge_time.count() * 1000 << " milisegundos" << endl;

    //cout << "\nFirst 10 codes (after sort):" << endl;
    for(size_t i = 0; i < 10; i++){        
        //cout<<original_data[sorted[i]].getData()<<endl;
    }
    return 0;
}