#include <iostream>
#include "Heap.h"
#include <time.h>
#include <cstdlib>

using namespace std;

#define MAX 1024


int main()
{
    //variables
    srand(time(NULL));
    int randomnumber;
    int interator = 1;
    int deleted;
    bool untouch = true;

    //make the heap
    Heap H;

    //make your arrays
    int *randomarray = new int[MAX];
    std::string *status = new std::string[MAX];

    //add random numbers to array
    for(int x = 0;x < MAX;x++)
    {
        randomnumber = rand() % 1024 + 1;
        randomarray[x] = randomnumber;
        status[x] = "Untouched";
    }

    //first step: add first element to heap
    H.enqueue(randomarray[0]);
    status[0] = "Enqueue";

    //Repeat Steps 2 to 4 until heap is empty
    while(!H.HeapEmpty())
    {
        //Step 2: delete the minimum element
        H.DeleteMin();

        //Step 3: add elements that are untouched and do it four at a time if you can
        if(untouch)
        {
            //add four elements that are untouched
            for(int i = interator;i < (interator+4); i++)
            {
                //add an element that does not exceed the array
                if(i < MAX)
                {
                    H.enqueue(randomarray[i]);
                    status[i] = "Enqueue";
                    std::cout<< "\n" << randomarray[i] << " " << status[i] << "\n";


                }//index exceeds the array, then there are no untouched elements
                else
                {
                    untouch = false;

                }
            }

            if(interator > MAX)
            {
                interator = MAX-1;
            }
            else
            {
                interator+=4;
            }

        }

        //Step 4: Print the Queue
        H.printQueue(randomarray,status,interator);


        std::cin.ignore();
    }






}


