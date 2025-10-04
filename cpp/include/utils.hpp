#ifndef __UTILS_HPP__
#define __UTILS_HPP__
#include "poscode.hpp"
#include "linkedList.hpp"
#include <string>
void split_qs(Poscode *A, size_t i, size_t j);
void counting_sort(Poscode* &A, size_t n, int p, int M);
void quick_sort(Poscode *A, size_t n);
void merge_sort(Poscode *A, size_t n);
void radix_sort(Poscode* &A, size_t n);

Poscode *readCodes(const std::string &strfile, size_t n);
void deleteCodes(Poscode *codes);
#endif

