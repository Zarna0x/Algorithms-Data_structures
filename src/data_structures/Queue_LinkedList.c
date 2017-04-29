#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node* next;
};

struct node* front = NULL;
struct node* rear  = NULL;

void Enqueue (int x) {
  // Insert Node At Tail
  struct node* tmp = (struct node*)malloc(sizeof(struct node*));
  tmp->data = x;
  tmp->next = NULL;

  if (front == NULL && rear == NULL)  { // If queue is empty
     front = rear = tmp;
     return ;
  }

  rear->next = tmp;
  rear = tmp;


}


void Dequeue () {
  // Remove First Element of Queue
   struct node* tmp = front;

   if (front == NULL) { // if Queue is empty
       return ;
   }else if (front == rear) { // if there are only one element in the queue
      front = rear = NULL;
      return ;
   }

   front = tmp->next;
   free(tmp);




}

int CountElements () {
  int i = 1;
  struct node* tmp = front;
  while (tmp->next != NULL) {
     tmp = tmp->next;
     i++;
  }

  return i;
}

void Print () {
  struct node* tmp = front;
  printf("Queue Elements: ");
  while (tmp != NULL) {
    printf(" %d ",tmp->data);
    tmp = tmp->next;
  }
}

int main () {
Enqueue(1);
Enqueue(2);
Enqueue(3);
Dequeue();
Dequeue();
Dequeue();
Dequeue();
Enqueue(9);
Print();

printf("\n\n==%d and %d==",front->data,rear->data);

  return 0;
}
