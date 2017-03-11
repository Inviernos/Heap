#include "Heap.h"
#include <math.h>

//#include <iostream>

Heap::Heap()
{
    heap_size = -1;
    HeapArray = new int[1024];
    sorting = false;

}

Heap::~Heap()
{
    //dtor
}

/*
Swaps the element of the array
*/
void Heap::Swap(int p,int c)
{
     temp = HeapArray[c];
     HeapArray[c] = HeapArray[p];
     HeapArray[p] = temp;


}
//Sorts the Heap from the bottom
void Heap::SortUp()
{
    //sorting elements until you can't sort anymore
    while(sorting)
    {
        //you have not reached the first element
        if(index>0)
        {
            parent = floor((index-1)/2);

            //parent is bigger than the inserted element
            if(HeapArray[parent] > HeapArray[index])
            {
                Swap(parent,index);
                index= parent;

            }//you are done sorting
            else
            {
                sorting = false;
            }
        }//you reached the first element, you are done sorting
        else
        {
            sorting = false;
        }

    }
}

/*
sort the heap starting from the root going down
*/
void Heap::SortDown()
{
    //keep sorting elements until there is no more to sort
    while(sorting)
    {
            //children
            leftchild = (2*parent) + 1;
            rightchild = (2*parent) + 2;

            //There are two children
            if(rightchild <= heap_size)
            {

                //parent is bigger than left child
                if(HeapArray[parent] > HeapArray[leftchild] && HeapArray[leftchild] <= HeapArray[rightchild])
                {
                    Swap(parent,leftchild);
                    parent = leftchild;

                }//parent is bigger than left child
                else if(HeapArray[parent] > HeapArray[rightchild] && HeapArray[rightchild] < HeapArray[leftchild])
                {
                    Swap(parent,rightchild);
                    parent = rightchild;
                }//parent is smaller and sorting is done
                else
                {
                    sorting = false;
                }


            }//there is one child
            else if (leftchild <= heap_size)
            {
                //parent is bigger than left child
                if(HeapArray[parent] > HeapArray[leftchild])
                {
                    Swap(parent,leftchild);
                }

                //reached the end of heap and sorting is done
                sorting = false;

            }// there is no children
            else
            {
                sorting = false;
            }



    }


}
/*
This method prints out the heap and i also mark deleted in the status
array for the element that was deleted in the heap
*/
void Heap::printQueue(int randomarray[], std::string status[],int sizes)
{
    std::cout << "\nHeap: ";
    bool once = false;

    //go through the heap
    for(int n = 0;n <= sizes ;n++)
    {
        //find the minimum and look for the one that has been added
        if(randomarray[n] == minimum && status[n].compare("Enqueue") == 0)
        {
            //have you already marked an element
            if(!once)
            {
                status[n] = "Deleted";
                once = true;
            }

        }

        //make sure that heap array does not go out of bounds
        if(n <= heap_size)
        {
             std::cout << HeapArray[n] << " ";
        }

    }

}

/*
This method adds an item to the heap.
*/
void Heap::enqueue(int item)
{

    //add to the size
    heap_size += 1;

    //add to the heap
    HeapArray[heap_size] = item;



    //there is more than one item in the heap
    if(heap_size > 0)
    {

      sorting = true;
      index = heap_size;

      //sort the heap
      SortUp();


    }

}

/*
check if the heap is empty
*/
bool Heap::HeapEmpty()
{
    if(heap_size == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/*
delete the minimum item in heap
*/
void Heap::DeleteMin()
{

    minimum = HeapArray[0];

    std::cout << "\nMinimum Element Deleted: " << minimum << std::endl;

    //there is more than one element in heap
    if(heap_size > 0)
    {

        //set last element to first element
        HeapArray[0] = HeapArray[heap_size];
        HeapArray[heap_size] = -1;
        heap_size-= 1;
        parent = 0;
        sorting = true;

        //sort the heap
        SortDown();

    }//there is only one element
    else
    {
        HeapArray[0] = -1;
        heap_size=-1;
    }

}


