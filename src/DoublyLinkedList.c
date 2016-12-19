// Double Linked list implementation

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

struct node {
  int data;
  struct node* next;
  struct node* prev;
};

struct node* head;

bool isEmpty() {
   return head == NULL;
}

int countNodes() {
   struct node* counter_node = head;

   int i = 0;
   while (counter_node != NULL) {
      i++;
      counter_node = counter_node->next;
   }

   return i;
}

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

void DeleteHead () {
  if (head->next == NULL) {
     head = NULL;
     return;
  }


  head = head->next;
  head->prev = NULL;

}

void DeleteNth(int n){
  if(n > countNodes()){
     return;
  }
  struct node* temp = head;
  int i;
  for (i = 0; i <  n-2; i++) {
     temp = temp->next;
  }
   struct node* temp2 = temp->next;
   temp->next  = temp2->next;
   temp2->next->prev = temp;
   free(temp2);


}

void InsertNth (int x,int n) {
  if(n > countNodes()){
     return;
  }
  struct node* newNode = GetNewNode(x);
  if (n == 1) {

     head->prev    = newNode;
     newNode->next = head;
     head = newNode;
     return ;
  }

  int i;
  struct node* tmp_head = head;
  for (i = 0; i < n-2; i++) {
     tmp_head = tmp_head->next; // 2th node
  }

  newNode->next = tmp_head->next;
  tmp_head->next->prev = newNode;
  tmp_head->next = newNode;
  newNode->prev  = tmp_head;


}


void DeleteByValue (int x){
  struct node* tmp_ptr = head;
  int i = 1;
  bool check_if = false;
  int pos;

  while (tmp_ptr != NULL){
     if (tmp_ptr->data == x) {
        check_if = true;
        pos = i;
        break;
    }

     i++;
     tmp_ptr = tmp_ptr->next;
  }



   // Now delete post-th element
   struct node* temp = head;
   int j ;
   for (j = 0; j < pos - 2; j++) {
       temp = temp->next;
   }


   temp->next = tmp_ptr->next;
   tmp_ptr->next->prev = temp;
   free(tmp_ptr);
}

bool Exists (int x) {
   struct node* tmp = head;
   bool exists = false;
   int i;
   while (tmp != NULL){
     if (tmp->data == x) {
        exists = true;
        break;
    }

     i++;
     tmp = tmp->next;
  }

  return exists;
}

void DeleteLast(){
  struct node* tmp = head;
  while (tmp->next != NULL) {
     tmp = tmp->next;
  }
    tmp->prev->next = NULL;
    tmp = NULL;
    free(tmp);

}

void reverse(){
  struct node *currNode,*nextNode,*prevNode;
  currNode = head;

  while (currNode != NULL) {
     // set Next
     nextNode = currNode->next; // next = 2

     currNode->next = prevNode; // cuurnext =ĵnull

     prevNode = currNode;
     currNode = nextNode;
  }
     head = prevNode;

//printf("--%d--",head->next->next->data);
}

void clear() {
  struct node* current = head;
  struct node* next;

  while (current!= NULL) {
        next = current->next;
        free(current);
        //move one
        current = next;
  }

   head = NULL;


}

void Swap (int n) {
  if(n >= countNodes()){
     return;
  }

  struct node* tmp_ptr = head;

  // get n-th node pointer
  int i;
  for (i = 0; i < n-1 ;i++ ) {
     tmp_ptr = tmp_ptr->next;
  }
  // Swap adjacent nodes;
  struct node* nextNode = tmp_ptr->next;

  // Swap


  tmp_ptr->prev->next  = nextNode;
  nextNode->next->prev = tmp_ptr;

  tmp_ptr->next = nextNode->next;
  nextNode->prev = tmp_ptr->prev;
  tmp_ptr->prev  = nextNode;
  nextNode->next = tmp_ptr;

}

void ChangeNodePos(int n, int new_position) {
 if(n > countNodes()){
     return;
  }

  if (new_position > n) {
     int iter = new_position - n;
     int i = 1;
     while ( i <= iter) {
        Swap(n);
        i++;
        n++;
     }

  }else if (new_position < n) {
     int iter = n - new_position;
    return ;
  }

}

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
  return 0;
}
