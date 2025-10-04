#include "poscode.hpp"
#include "utils.hpp"
#include <string>
#include <iostream>

using namespace std;

int main(int nargs, char** vargs){
    string strfile("../../code_files/codes_1MM.txt");
    size_t n = 1000000;
    Poscode *data = readCodes(strfile, n);

    cout << "First 10 codes (before sort):" << endl;
    for(size_t i = 0; i < 10; i++){        
        cout<<data[i].getData()<<endl;
    }
    cout << "\nSorting..." << endl;
    radix_sort(data, n);
    
    cout << "\nFirst 10 codes (after sort):" << endl;
    for(size_t i = 0; i < 10; i++){        
        cout<<data[i].getData()<<endl;
    }
    return 0;
}