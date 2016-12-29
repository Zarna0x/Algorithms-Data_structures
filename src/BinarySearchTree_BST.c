#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Binary Search Tree Implementation in C;
struct BST_Node {
  int data;
  struct BST_Node* left;
  struct BST_Node* right;
};


/*
  @desc   => Get new BST_Node allocated in the heap section of memory
  @param  => int data (Value of node)
  @return => memory addres of newly allocated BST_Node in the heap
*/
struct BST_Node* GetNewBSTNode(int data) {
    struct BST_Node* NewNode = (struct BST_Node*)malloc(sizeof(struct BST_Node));

    NewNode->data = data;
    NewNode->left = NULL;
    NewNode->right = NULL;

    return NewNode;
}

/*
  @desc   => Insert new node in the Tree
  @param1 => struct BST_NODE** root (addres of root node)
  @param2 => int data, (value to be Inserted)
  @return void
*/
void BST_Insert(struct BST_Node** root,int data) {
    if ( *root == NULL ) { // If Tree is Empty
        *root = GetNewBSTNode(data);
        return;
     }

      else if (data <= (*root)->data) {
           // Go Left Subtree
           BST_Insert(&((*root)->left),data);
      }

      else {
          // Rigth Subtree
         BST_Insert(&((*root)->right),data);
      }


}

/*
  @desc   => Search If data specified by param is part of tree
  @param1 => struct BST_NODE** root (addres of root node)
  @param2 => int data, (value to be searched)
  @return bool (True if data is found, False if data is not found)
*/
bool BST_Search (struct BST_Node** root, int data) {
   if ((*root) == NULL) {
       return false;
   }

   if ((*root)->data == data) {
      return true;
   }

   // If data is less than root data Search at the left part of tree using recursion
   if (data <= (*root)->data) {
        BST_Search(&((*root)->left),data);
   }
    // Search at the right part of the tree
   else  {
      BST_Search(&((*root)->right),data);
   }
}

/*
 @desc   => find Min Element of Tree
 @param1 => pointer of struct node root
 @return => Min Value Of Tree
*/

int FindMin (struct BST_Node* root) {
  if ( root == NULL) {
      return ; // Tree is Empty
  }

  if (root->left == NULL) {
      return root->data; // There is only one element in the Tree
  }

  else  {
    FindMin(root->left);
  }
}

/*
 @desc   => find Max Valued Element of Tree
 @param1 => pointer of struct node root
 @return => Max Value Of Tree
*/

int FindMax (struct BST_Node* root) {
  if ( root == NULL) {
      return ; // Tree is Empty
  }

  if (root->right == NULL) {
      return root->data; // There is only one element in the Tree
  }

  else  {
    FindMax(root->right);
  }
}


int main () {

  struct BST_Node* root = NULL;

  BST_Insert(&root,15);
  BST_Insert(&root,10);
  BST_Insert(&root,20);
  BST_Insert(&root,700);
  BST_Insert(&root,99);
  printf("%d",BST_Search(&root,0));
  int Min = FindMin(root);
  int Max = FindMax(root);
  printf("\n Min -> %d \n Max ->%d",Min,Max);

  return 0;
}
