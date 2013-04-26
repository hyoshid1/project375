#ifndef SORT_H
#define SORT_H
#include "BigIntegerLibrary.hh"

void radixSort(BigInteger *array, int size, std::string max, int maxLength);
void popAdjList(List **adjList, BigInteger *array, int size,
                BigInteger mod, BigInteger div);
void repopArray(List **adjList, BigInteger *array, int k);
long double calcBytes(std::string max, int maxLength);

#endif
