#include <stdlib.h>
#include <stdio.h>

struct node {
  int data;
  struct node* next;
};

struct node* top = NULL; // top of Stack (last element index)

void Push (int x) {
 // insert at head
  struct node* temp = (struct node*)malloc(sizeof(struct node));
  temp->data = x;
  temp->next = top;
  top = temp;
}

void Pop () {
// delete last element
  if (top == NULL) {
     return;
  }
  struct node* temp = top;
  top = top->next;
  free(temp);



}
 int main () {
  Push(1);
  Push(2);
  Pop();
  printf("%d",top->data);


    return 0;
 }
