#ifndef __UTILS_HPP__
#define __UTILS_HPP__
#include "poscode.hpp"
#include "linkedList.hpp"
#include <string>

size_t* createIndexArray(size_t n);
void swap(Poscode* A, size_t i, size_t j);
size_t getRandomInt(size_t min, size_t max);
size_t split_qs(Poscode *A, size_t i, size_t j);
void quick_sort(Poscode *A, size_t n);
void quick_sort(Poscode *A, size_t i, size_t j);
void merge(Poscode *A, size_t i, size_t k, size_t j);
void merge_sort(Poscode *A, size_t i, size_t j);
void merge_sort(Poscode *A, size_t n);
void counting_sort(const Poscode* originalCodes, size_t* &A, size_t n, size_t p, size_t M);
void radix_sort(const Poscode* originalCodes, size_t* &A, size_t n);

Poscode *readCodes(const std::string &strfile, size_t n);
void deleteCodes(Poscode *codes);
#endif

