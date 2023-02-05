/******************************************************************************
*  Hash table is an abstract data structure that associate arrays using keys.
*  Values are not stored in a sorted order
*  Be careful with colisions.
*  This is an implementation of Hash tables using structures in C .
*                                                       -@mr.printf
******************************************************************************/
//keys; hash function ; hash table
//O(1) to search or store in hash table
//Hash function must return the same value for the same key
// Hash table = arrays + linked lists

#include <stdio.h>
#include <stdlib.h>
#include <sys/select.h>
#include <sys/types.h>
#include <string.h>

#define HASH_MAX 12
//structure element
typedef struct element{
	char *name ;
	int age;
	struct element *next;

}element;

element *hash_table [HASH_MAX];

void initTable ();
unsigned int  hash_function (char *name);
void findElement(char *name);
void deleteElement(char *name);
int insertElement(element *p);
void printTable ();

int main(void ){
	//initialise the hash table
	initTable();
	//print the table after initialision
	//printTable();
	//create elements to put into the table
	element Javascript = {.name = "Javascript" , .age = 67 };
	element Java = {.name = "Java", .age = 1000 };
	element Adam = {.name = "Adam", .age = 94 };
	element Bash = {.name = "Bash", .age = 27};
	element Python = {.name = "Python", .age = 35 };
	element Node = {.name = "Node", .age = 12};
	element Ruby = {.name = "Ruby", .age = 24};
	element Vhdl = {.name = "Vhdl", .age = 74};
	element Matlab = {.name = "Matlab", .age = 4};
	element Html = {"Html", 25};
	element Css = {"Css", 12};
	element Php = {"Php", 68};
	//We use anagrams to create colisions
	element avaJ = {"avaJ", 38};
	element edoN = {"edoN", 24};
	element scriptJava = {"scriptJava", 24};

	//-------
	//adding elements in the hash table
	//we will use "external chaning" to deal with colisions
	//with external chaning if there is colision, the colision domain becomes the head of a linked list
	insertElement(&Java);
	insertElement(&Javascript);
	insertElement(&Adam);
	insertElement(&Bash);
	insertElement(&Python);
	insertElement(&Node);
	insertElement(&Html);
	insertElement(&Php);
	//inserting elements to create colisions
	insertElement(&avaJ); //the same hash as Java
	insertElement(&edoN); //hashed at the same location as Node
	insertElement(&scriptJava); //same hash as javascript

	//print out the table after addition
	printTable();
	//looking for people in the hash table
	findElement("Adam");
	findElement("ReactJs");
	findElement("Html");
	findElement("Java");
	//deleting elements in the table
	deleteElement("Python");
	deleteElement("ReactJs");
	//deleting the head
	deleteElement("scriptJava");
	//print out the table after deletion
	printTable();
	return 0;
}


/*
 * this function will print out the entire hash table
 */

void printTable(){
	printf("--->\n");
	for (int i = 0 ; i < HASH_MAX; i++){
		//if the index is empty
		if(hash_table[i] == NULL){
			printf("\t%d\t~~~\n",i);
		}
		else{
			//cursor pointer
			element *cursor = hash_table[i];
			printf("\t%d\t",i);
			while(cursor !=NULL){
				printf("%s <-> ",cursor->name);
				cursor = cursor->next;
			}
			putchar('\n');

		}
	}
	printf("<---\n");

}


/*
 * this function initialise all elements of the hash table to NULL
 */

void initTable(){
	for(int i = 0; i < HASH_MAX; i++){
		//initialise each element to NULL
		hash_table[i] = NULL;
	}
}
/*This is a poor hash function that takes a name as argument
 *And map it to the hash table generating an index
 * We add the ASCII value of each character in the name and
 * we divide the result by
 * the size of the table to get a true index
 */
unsigned int hash_function (char *name){

	//sum
	unsigned int index = 0;
	//Calculating the length of the name
	int size = strlen(name);
	for (int i = 0; i < size ; i++){

		index += name[i];

	}

	//return the exact index of the element in the hash table
	return index % HASH_MAX;
}

/*
 * This function will add the element passed as parameter into the
 * hash table at the rigth index and return 0 in case of success
 */

int insertElement (element *p){
	//if the element is NULL
	if(p == NULL)
		return 1;
	//hashing the value to get an index
	unsigned int index = hash_function(p->name);
	//In case of colision
	if (hash_table[index] != NULL){
		//the element p will become the head of a linked list
		p->next = hash_table[index];
		//hash_table[index]->next = NULL;
	}
	//if there is no colison detected then insert the element
	hash_table[index] = p;


	return 0;
}

/*
 * this function will find the index of an element if it
 * exists in the hash table "in normal case
 * it should return the index in case
 * of success or a negative integer if the element is not
 * in the table (but not here;XD - we return nothing)".
 */

void findElement(char *name){
	//first hash the name to get an index
	unsigned int index = hash_function(name);
	//cursor pointer
	element *cursor = hash_table[index];
	//Check if the hashed position is empty
	if (hash_table[index] == NULL){
		printf("target %s not found!\n", name);

	}else{
		//compare the element at the index position with the target
		while( cursor != NULL && strcmp(cursor->name, name) != 0 ){
		cursor = cursor->next;
		}
	//instead of returning the target position, we will print it
		if(strcmp(cursor->name, name) == 0){
		printf("%s found at position %d\n", name, index);
		}
		else{
		printf("target %s not found!\n", name);
		}
	}
}

/*
 * this function will find and delete the element passed as
 * parameter
 */

void deleteElement( char *name){
	//first look if the name is not null
	if(name == NULL)
		return;
	//then hash the name if it is not null to get an index value
	unsigned int index = hash_function(name);
	//cursor pointer
	element *cursor = hash_table[index];
	element *prevCursor = NULL;
	//Check if the hashed position is empty
	if (hash_table[index] == NULL){
		printf("the element %s is not in the table\n", name);

	}else{
		//check the entire linked list
		while(cursor != NULL && strcmp(name,cursor->name) != 0){
			prevCursor = cursor;
			cursor = cursor ->next;
		}
		//if the target is the head of the linked list
		if (prevCursor == NULL){
			hash_table[index] = cursor->next;
		}
		else{
			prevCursor->next = cursor->next;
		//printf("the element %s is not in the table\n", name);
		}
	}

}



/*Compile : gcc -o hash hash_table.c
 * execute : ./hash
 * output :
 * --->
        0       ~~~
        1       ~~~
        2       avaJ <-> Java <->
        3       scriptJava <-> Javascript <->
        4       ~~~
        5       ~~~
        6       edoN <-> Node <-> Python <->
        7       ~~~
        8       Php <->
        9       Html <->
        10      Bash <->
        11      Adam <->
<---
Adam found at position 11
target ReactJs not found!
Html found at position 9
Java found at position 2
the element ReactJs is not in the table
--->
        0       ~~~
        1       ~~~
        2       avaJ <-> Java <->
        3       Javascript <->
        4       ~~~
        5       ~~~
        6       edoN <-> Node <->
        7       ~~~
        8       Php <->
        9       Html <->
        10      Bash <->
        11      Adam <->
<---
*/



