#ifndef HEAP_H
#define HEAP_H

#include <iostream>

class Heap
{
    public:
        Heap();
        void enqueue(int);
        void DeleteMin();
        bool HeapEmpty();
        void printQueue(int[],std::string[],int);
        virtual ~Heap();
    protected:
    private:
        void SortUp();
        void SortDown();
        void Swap(int,int);

    private:
        int heap_size;
        int index;
        int temp;
        int minimum;
        int *HeapArray;
        int parent;
        int rightchild;
        int leftchild;
        bool sorting;

};

#endif // HEAP_H
