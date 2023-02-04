/***************************************************************************
*   This is an implementation of linear search algorithm in c
*   @author: Mr.printf (127.0.0.mi)
*   Definition : linear search is a searching algorithm that consists on
*   sequencially compare the target value with each element of the array until
*   we find it...
*   Runnig time: O(n)
*
*****************************************************************************/

#include <stdio.h>

int linearSearch(int array [], int size, int key);

int size, result;
int
main(void){

    int myArray[] ={54,49,98,72,-1,14,0,12,28,96,13,58};
    size = sizeof(myArray) / sizeof(int);

    result = linearSearch(myArray,size,-1);
    (result == -1)
    ? printf("Target not found\n")
    : printf("Target %d is found at position %d\n", myArray[result], result);

    return 0;
}

/*
 * Linear search function recieves the array, size and the target value
 * it returns negative value if the target is not in the array and the index
 * position in other case...
 */
int linearSearch(int array[],int size, int key){

    for(int i = 0; i < size ; i++)
        if(array[i] == key)
            return i;


    return (-1);
}

//compile :  gcc -o linear linear_search.c
//execute :  ./linear
//output  :  Target -1 is found at position 4

