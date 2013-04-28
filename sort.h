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
void radixSort(std::vector<BigUnsigned> vect, int size, int digits, long k);
void popAdjList(List **adjList, std::vector<BigUnsigned> vect, int size, 
                BigUnsigned mod, BigUnsigned div);
void repopArray(List **adjList, std::vector<BigUnsigned> vect, int k);
long double calcBytes(std::string max, int maxLength);
void cRadixSort(std::vector<BigUnsigned> &vect, int size, long digits, int k);

//to compare with quicksort
int partition(BigInteger *array, int start, int size);
void quickSort(BigInteger *array, int start, int size);

#endif
