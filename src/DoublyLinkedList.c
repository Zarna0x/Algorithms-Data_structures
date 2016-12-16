// Double Linked list implementation

#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node* next;
  struct node* prev;
};

struct node* head;

struct node* GetNewNode(int x) {
  struct node* newNode = (struct node*)malloc(sizeof(struct node));
  newNode->data = x;
  newNode->prev = NULL;
  newNode->next = NULL;
  return newNode;

}

void InsertAtHead( int x ) {
   struct node* temp = GetNewNode(x);
   if (head == NULL) {
      head = temp;
      return;
   }
     head->prev = temp;
     temp->next = head;
     head       = temp;
 }

 void InsertAtTail (int x) {
     struct node* newNode = GetNewNode(x);
     struct node* temp    = head;

     if (head == NULL) {
        head = newNode;
        return;
     }

     //Iterate right
    while (temp->next != NULL) {
       temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;


 }

void ReversePrint() {
	struct node* temp = head;
	if(temp == NULL) return; // empty list, exit
	// Going to last Node
	while(temp->next != NULL) {
		temp = temp->next;
	}
	// Traversing backward using prev pointer
	printf("Reverse: ");
	while(temp != NULL) {
		printf("%d ",temp->data);
		temp = temp->prev;
	}
	printf("\n");
}

void Print () {
  struct node* temp = head;
  printf("Forward: ");
  while (temp != NULL) {
    printf("%d, ",temp->data);
    temp = temp->next;
  }
  printf("\n");
}

int main () {
  InsertAtHead(1);
  InsertAtHead(2);
  InsertAtHead(3);
  InsertAtHead(4);
 ////

 Print();

 InsertAtTail(9);
 Print();
 ReversePrint();

  return 0;
}
