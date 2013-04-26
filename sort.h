#ifndef SORT_H
#define SORT_H
#include "BigIntegerLibrary.hh"

void radixSort(std::string *array, int size, std::string max, int maxLength);
void popAdjList(List **adjList, std::string *array, int size,
                BigInteger mod, BigInteger div);
void repopArray(List **adjList, std::string *array, int k);
long double calcBytes(std::string max, int maxLength);

#endif
