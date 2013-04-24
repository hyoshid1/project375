#ifndef SORT_H
#define SORT_H

void radixSort(std::string *array, int size, unsigned int maxLength);
void popAdjList(List **adjList, std::string *array, int size, int mod, int div);
void repopArray(List **adjList, std::string *array);
void printArray(std::string *array, int size);

#endif
