// Double Linked list implementation

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include "DoublyLinkedList.h"
#include "stack.h"


int main () {
  InsertAtHead(1);
  InsertAtHead(2);
  InsertAtHead(3);
  InsertAtHead(4);
  InsertAtHead(5);
  InsertAtHead(6);
  InsertAtHead(7);
 ////

 Print();

 InsertAtTail(9);
 Print();
 ReversePrint();
 Print();
 DeleteHead();
 printf("After Delete Head: \n");
 Print();
 printf("Delete 3-th element: \n\n");
 DeleteNth(3);
 Print();


 printf("Insert 3-th element: \n\n");
 InsertNth(77,3);
 Print();



 //DeleteByValue (77);
 //DeleteByValue (5);
 Print();
 //DeleteLast();
 puts("___________");
 Print();
 printf("__________");
 reverse();
 Print();
 clear();
 printf("after clear \n");
 Print();
  InsertAtHead(1);
  InsertAtHead(2);
  InsertAtHead(3);
  InsertAtHead(4);
  InsertAtHead(5);
  InsertAtHead(6);
  InsertAtHead(7);
  InsertNth(77,3);
 ////

 Print();

 Swap(3);
 puts("\nafter swap:\n");
 Print();
 Swap(3);
 puts("\nafter swap2222:\n");
 Print();

/*
int i = 1;
int offset = 3;

while (i <= 3) {
 printf(" %d-> \n",i);
 Swap(offset);
 Print();
 i++;
 offset++;
}

 puts("\nafter swap333:\n");
 Print();
*/

ChangeNodePos(3,5);
puts("New Position");
Print();

SwapLeft(3);
Print();

ChangeNodePos(5,1);
//clear();
Print();

struct node* second = getNthNode(2);
struct node* fifth = getNthNode(5);

//printf("\n\n1)\nSecond address ->%p with data %d\nfifth address  ->%p with data %d\n\n\n",second,second->data,fifth,fifth->data);
printf("After Swap \n");
SwapTwo(&second,&fifth);
Print();
clear();
//struct node* meore = getNthNode(2);
//struct node* mexute = getNthNode(5);
//printf("\nhead->next = %p",head->next);
//printf("--%d--",meore->data);
// Create Stack;
InsertAtTail(1);
InsertAtTail(2);
InsertAtTail(3);
InsertAtTail(4);
InsertAtTail(5);
InsertAtTail(6);
InsertAtTail(7);
InsertAtTail(8);
InsertAtTail(9);
InsertAtTail(10);
Print();

DeleteEvenOrOdd("odd");
Print();
  return 0;
}
