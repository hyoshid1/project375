#ifndef SORT_H
#define SORT_H
#include <iostream>
#include <sstream>
#include <cmath>
#include <vector>
#include "Node.h"
#include "List.h"
#include "BigIntegerLibrary.hh"

//Radix sort that uses buckets
void radixSort(BigUnsigned *array, int size, long k, int digits);
void popAdjList(List **adjList, BigUnsigned *array, int size, 
                BigUnsigned mod, BigUnsigned div);
void repopArray(List **adjList, BigUnsigned *array, int k);
long double calcBytes(std::string max, int maxLength);
void cRadixSort(std::vector<BigUnsigned> &vect, int size, long digits, int k);

//to compare with quicksort
int partition(BigInteger *array, int start, int size);
void quickSort(BigInteger *array, int start, int size);

#endif
