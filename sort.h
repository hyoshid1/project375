#ifndef SORT_H
#define SORT_H
#include <iostream>
#include <sstream>
#include <cmath>
#include "Node.h"
#include "List.h"
#include "BigIntegerLibrary.hh"

//Radix sort that uses buckets
void radixSort(BigInteger *array, int size, long k, int digits);
void popAdjList(List **adjList, BigInteger *array, int size, 
                BigInteger mod, BigInteger div);
void repopArray(List **adjList, BigInteger *array, int k);
long double calcBytes(std::string max, int maxLength);

//to compare with quicksort
int partition(BigInteger *array, int start, int size);
void quickSort(BigInteger *array, int start, int size);

#endif
