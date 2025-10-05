#ifndef __TEST_HPP__
#define __TEST_HPP__

#include <string>
#include <vector>
#include <ostream>

using namespace std;

class SorterTest {
    private:
        vector<string> files;
        vector<size_t> sizes;
        int runs;

        double run_radix(const string& file, size_t n);
        double run_quick(const string& file, size_t n);
        double run_merge(const string& file, size_t n);

        double promedio(const vector<double>& v) const;
        double desviacion(const vector<double>& v, double prom) const;

    public:
        SorterTest(const vector<string>& files, const vector<size_t>& sizes, int runs = 5);
        void run_all(ostream& out);
};

#endif