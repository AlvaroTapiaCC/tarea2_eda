#include "test.hpp"
#include <vector>
#include <string>
#include <fstream>

using namespace std;

int main() {
    vector<string> files = {"codes_500K.txt", "codes_1MM.txt", "codes_10MM.txt"};
    vector<size_t> sizes = {500000, 1000000, 10000000};
    SorterTest tester(files, sizes, 5);

    ofstream fout("../../results.csv");
    tester.run_all(fout);
    fout.close();

    return 0;
}