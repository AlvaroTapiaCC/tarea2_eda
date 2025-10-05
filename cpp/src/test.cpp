#include "test.hpp"
#include "utils.hpp"
#include <vector>
#include <string>
#include <chrono>
#include <cmath>
#include <iostream>
#include <ostream>

using namespace std;
using namespace std::chrono;


SorterTest::SorterTest(const vector<string>& files_, const vector<size_t>& sizes_, int runs_)
    : files(files_), sizes(sizes_), runs(runs_) {}

double SorterTest::run_radix(const string& file, size_t n) {
    string strfile = "../../code_files/" + file;
    Poscode *original_data = readCodes(strfile, n);
    size_t *sorted = createIndexArray(n);
        auto start = high_resolution_clock::now();
    radix_sort(original_data, sorted, n);
        auto end = high_resolution_clock::now();
    delete[] original_data;
    delete[] sorted;
        duration<double> elapsed = end - start;
    return elapsed.count() * 1000; // milisegundos
}

double SorterTest::run_quick(const string& file, size_t n) {
    string strfile = "../../code_files/" + file;
    Poscode *original_data = readCodes(strfile, n);
        auto start = high_resolution_clock::now();
    quick_sort(original_data, n);
        auto end = high_resolution_clock::now();
    delete[] original_data;
        duration<double> elapsed = end - start;
    return elapsed.count() * 1000;
}

double SorterTest::run_merge(const string& file, size_t n) {
    string strfile = "../../code_files/" + file;
    Poscode *original_data = readCodes(strfile, n);
        auto start = high_resolution_clock::now();
    merge_sort(original_data, n);
        auto end = high_resolution_clock::now();
    delete[] original_data;
        duration<double> elapsed = end - start;
    return elapsed.count() * 1000;
}

double SorterTest::promedio(const vector<double>& v) const {
    double sum = 0;
    for (double x : v) sum += x;
    return sum / v.size();
}

double SorterTest::desviacion(const vector<double>& v, double prom) const {
    double sum = 0;
    for (double x : v) sum += (x - prom) * (x - prom);
    return sqrt(sum / v.size());
}

void SorterTest::run_all(ostream& out) {
    out << "Metodo,n,Promedio(ms),Desviacion(ms)" << endl;
    for (size_t i = 0; i < files.size(); i++) {
        string file = files[i];
        size_t n = sizes[i];

        // RADIX
        cout << "Running radix on n=" << n << endl;
        vector<double> tiempos_radix;
        for (int r = 0; r < runs; r++)
            tiempos_radix.push_back(run_radix(file, n));
        double prom_radix = promedio(tiempos_radix);
        double desv_radix = desviacion(tiempos_radix, prom_radix);
        out << "Radix," << n << "," << prom_radix << "," << desv_radix << endl;

        // QUICK
        cout << "Running quick on n=" << n << endl;
        vector<double> tiempos_quick;
        for (int r = 0; r < runs; r++)
            tiempos_quick.push_back(run_quick(file, n));
        double prom_quick = promedio(tiempos_quick);
        double desv_quick = desviacion(tiempos_quick, prom_quick);
        out << "Quick," << n << "," << prom_quick << "," << desv_quick << endl;

        // MERGE
        cout << "Running merge on n=" << n << endl;
        vector<double> tiempos_merge;
        for (int r = 0; r < runs; r++)
            tiempos_merge.push_back(run_merge(file, n));
        double prom_merge = promedio(tiempos_merge);
        double desv_merge = desviacion(tiempos_merge, prom_merge);
        out << "Merge," << n << "," << prom_merge << "," << desv_merge << endl;
    }
}