#ifndef SORT_H
#define SORT_H

void radixSort(std::string *array, int size, std::string max, int maxLength);
void popAdjList(List **adjList, std::string *array, int size, int mod, int div);
void repopArray(List **adjList, std::string *array, int k);
int calcBytes(std::string max, int maxLength);
double mod(double x, double y);

#endif
