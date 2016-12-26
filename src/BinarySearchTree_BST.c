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

}


int main () {

  struct BST_Node* root = NULL;

  BST_Insert(&root,15);
  BST_Insert(&root,10);
  BST_Insert(&root,20);
  BST_Insert(&root,700);
  BST_Insert(&root,0);

//printf("--%d AND %d AND %d--",root->data,root->left->data,root->left->left->data);
  return 0;
}
