// Double Linked list implementation

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include "DoublyLinkedList.h"


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
Print();

  return 0;
}
