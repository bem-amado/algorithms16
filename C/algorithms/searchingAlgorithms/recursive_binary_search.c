/***************************************************************************
*   This is an implementation of binary search algorithm "using recursion" in c
*   @author: Mr.printf (127.0.0.mi)
*   Definition : binary search is one of the most used searching algorithm
*   it consists on finding the index of the target element comparing it
*   with the midle index in the sorted array...
*   Runnig time: O(n*logn)
*
*****************************************************************************/

#include <stdio.h>

int binarySearch (int array[], int left,int rigth, int key );

int size;
int result;

int
main(void) {
    //binary search works only with sorted array
    int myArray [] = {42,43,44,45,46,47,75,76,77,78,109,1010,120,130};

    //this operation guive us the real size of the array
    size = sizeof(myArray)/sizeof(int);

    result = binarySearch(myArray,0,(size-1), 75);

    (result == -1 )
    ? printf("target not found\n")

    :printf("target %d is found at position %d\012",myArray[result], result);

    return 0;
}


/*
 * Recursive binary search implementation
 */

int binarySearch(int array[], int left,int rigth, int key){

   int midle = (left + rigth)/2;

    if(left <= rigth){

        if(key == array[midle])
            return midle;
        if(key > array [midle])
            return binarySearch(array,(midle+1),rigth,key);
        else
            return binarySearch(array,left,(midle-1),key);
    }

  return (-1);
}


//compile : gcc -o Rbinary recursive_binary_search.c
//Execute : time ./Rbinary
/* output :

    target 75 is found at position 6

    real    0m0.002s
    user    0m0.002s
    sys     0m0.001s
 */
