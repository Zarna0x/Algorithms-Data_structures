#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


//Using array implementation of stack ( also  can be done by linked list implementation)
#define MAX_STACK_SIZE 100

char Stack[MAX_STACK_SIZE];
int top = -1;

void push (char x) {
  if (top > MAX_STACK_SIZE) {
     return ;
  }

  Stack[++top] = x;
}

void pop() {
  if (top == -1) {
     return;
  }

  Stack[top--] = NULL;
}

bool arePair (char open, char end) {
   if (open == '(' && end == ')') return true;
   if (open == '{' && end == '}') return true;
   if (open == '[' && end == ']') return true;

   return false;
}

bool isBalanced (char *str) {
  int i;
  for (i = 0; i < strlen(str); i++) {
     if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
          push(str[i]);
     }else if (str[i] == ')' || str[i] == '}' || str[i] == '}') {
         if(top == -1  || !arePair(Stack[top],str[i]) ) {
             return false;
         }else {
             pop();
         }
     }
  }

  if (top == -1) {
     return true;
  }else {
      return false;
  }
}

int main () {
  char *mychar = "{()}";
  printf("%d",isBalanced(mychar));

  return 0;
}
