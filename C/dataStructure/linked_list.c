/******************************************************************************
*  The difference between linked list and array is that in array
*  data is stored at contiguous location in memory; in a linked list
*  we use pointers to link elements together in the memory.
*                                                       -@mr.printf
******************************************************************************/

#include <stdlib.h>
#include <stdio.h>


typedef struct node{

    int data; //the value pointed by next
    struct node *next; //the pointer for the next value

}node;

//util functions
node* createNode(node *head, int value);
void  deleteNode(node *head, node *target);
void  printList(node *head);
void  freeList(node *head);
node* insertNode(node *head,node *nodeBefore, node *nodeAfter, int value);

int
main(void){

 /* //METHOD: =>1
  node *n1 = malloc (sizeof(node));
  node *n2 = malloc (sizeof(node));
  node *n3 = malloc (sizeof(node));

  //inserting values on the list
  //first node
  n1 -> data = 8;
  n1 ->next  = n2;
  //second node
  n2 -> data = 2;
  n2 -> next = n3;
  //third node
  n3 -> data = 21;
  n3 -> next = NULL;
  //print linked list
  for(node *temp = n1; temp != NULL; temp = temp -> next){

      printf("%d -> ",temp->data);
    }
    printf("NULL\n");
    */

  //METHOD: => 2
  //The head
  node *head = malloc(sizeof(node));
  //if malloc fails
  if(head == NULL){
    perror("Error no memory allocated for the head\n");
    exit(EXIT_FAILURE);
  }

  head -> data = 10;
  node *newNode1 = createNode(head,9);

  //Link the head to the first node
  head -> next = newNode1;

  //Create and link others nodes:
   node *newNode2 = createNode(head,14);
   newNode1 ->next = newNode2;
   node *newNode3 = createNode(head,-1);
   newNode2 ->next = newNode3;
   node *newNode4 = createNode(head,77);
   newNode3 ->next = newNode4;
   node *newNode5 = createNode(head,96);
   newNode4 ->next = newNode5;

  //print List
  printList(head);

  //ADD node beteween nodes 3 and 4
  insertNode(head,newNode3,newNode4, 21);
  //print List
  printList(head);

  //Delete the Node 4 (data = 77)
  deleteNode(head,newNode4);
  //print List
  printList(head);
  //Delete the entire list
  freeList(head);
  //print List : special case we call printList in the freeList function
    return 0;
}

/*
 * printf the complete linked list
 */
void printList(node *head){
  int i;
  i = 0;

  if(head == NULL){
    printf("The list is empty\n");
    return;
  }else{
      for(node *cursor = head; cursor != NULL; cursor = cursor -> next){
          printf(" %d -> ", cursor -> data);
          i++;}
  }

  printf("NULL\n");

  printf("Number of Nodes : %d\n", i);
}

/*
 * Create new node at the end of the list
 */
node* createNode(node *head, int value){

  node *cursor;
  cursor = head;
  //Find the end of the list to instert new node
  while(cursor ->next != NULL){

    cursor = cursor ->next;
  }


  //allocate space for new node
  node *n = malloc(sizeof(node));
  //if malloc fails
  if(n == NULL){
    perror("Error no memory allocated for new node\n");
    exit(EXIT_FAILURE);
  }
  n -> data = value;
  n -> next = NULL;

  return n;

  free(n);
}

/*
 * Insert new node between 2 specified existent nodes
 */

node* insertNode(node *head, node *nodeBefore, node *nodeAfter, int value){

  //use the head to create new node
  node *node = createNode(head, value);
  //link the node before to new node and new node to node nodeAfter
  nodeBefore -> next = node;
  node -> next = nodeAfter;

  return node;
}


/*
 * Delete a specified node (first, end or between two nodes)
 */

void deleteNode(node *head, node *target){

    //Temporary cursor
    node *cursor = head;
    //other nodes - find target node
    while(cursor != NULL && cursor->next->data != target->data){

      cursor = cursor->next;
    }

    //if we find the target we will link the node before the target and the node after the target
    // then we free the target
    if(cursor->next->data == target->data){

      //link node after the target to the node before the target
      cursor->next = cursor->next->next;
      //free/delete the target
      free(target);

    }

}

/*
 * Use ths function to delete the entire linked list in memory
 * passing the head as argument
 */
void  freeList(node *head){

  //create temporary node pointer and cursor pointer
  node *tmp;//
  node *cursor = head;
  //take one node by one and delete it
  while(cursor != NULL){

    //save the next node
    tmp = cursor->next;
    //delete node
    free(cursor);
    //update cursor to the next node
    cursor = tmp;
  }
  //call print list with NULL argument because the list is empty
  printList(NULL);

}

/* OUTPUT
10 ->  9 ->  14 ->  -1 ->  77 ->  96 -> NULL
Number of Nodes : 6
10 ->  9 ->  14 ->  -1 ->  21 ->  77 ->  96 -> NULL
Number of Nodes : 7
10 ->  9 ->  14 ->  -1 ->  21 ->  96 -> NULL
Number of Nodes : 6
The list is empty
 */
