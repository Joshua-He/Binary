#include <iostream>
#include <string.h>
#include <stack>
#include "TreeNode.h"
#include <cstring>
#include <stdlib.h>

using namespace std;


/*

Joshua He 

Period 7 

*/

void addToTree(int number, TreeNode* &root);
void printTree(TreeNode* root);
void deleteTree(TreeNode* &root, int deletedNumber);

int main(){
  char array[5000] = "";
  char token[100] = "";
  int arrayLength = 0;
  int layer = 0;
  TreeNode* root = NULL;
  
  cout << "Enter numbers separated by one space (5 5 3323 234)" << endl;
  cin.getline(array, 5000);
  arrayLength = strlen(array);
  for (int i = 0; i <= arrayLength; i++){
    if (array[i] != ' ' && array[i] != '\0'){
      strncat(token, &array[i], 1);
    }
    else{
      if(token[0] != ' ' && token[0] != '\0'){
      int temp = atoi(token);
      token[0] = '\0';
      addToTree(temp, root);
      }
    }
  }
  
  cout << "HELLO: " << array << endl;
  printTree(root);
  
}

void addToTree(int number, TreeNode* &root){

  //Add new node with value of number to the tree
  if (root == NULL){
    TreeNode* newNode = new TreeNode;
    newNode->setValue(number);
    root = newNode;
    return;
  }
  else{
    if(number > root->getValue()){
      //Root has no right child
      if(root->getRight() == NULL){
	TreeNode* newNode = new TreeNode;
	newNode->setValue(number);
	root->setRight(newNode);
      }
      //Recursive call to add to right subtree using temporary variable
      else{
	TreeNode* temp = root->getRight();
	addToTree(number, temp);
      }
    }
    if(number <= root->getValue()){
      //Root has no left child
      if(root->getLeft() == NULL){
	  TreeNode* newNode = new TreeNode;
	  newNode->setValue(number);
	  root->setLeft(newNode);
      }
      //Recursive call to add to left subtree using temporary variable
      else{
	TreeNode* temp = root->getLeft();
	addToTree(number, temp);
      }
    } 
  }
}


//Print the tree

void printTree(TreeNode* root){
  if (root == NULL){
    return;
  }
  printTree(root->getLeft());
  cout << root->getValue() << " ";
  printTree(root->getRight());
}

// delete from the tree 
void deleteTree(TreeNode* &root, int deletedNumber){

  //Nothing
  if(root == NULL){
    return;
  }

  //deleted Number is bigger than the root, recursive call for root right child
  if(deletedNumber > root->getValue()){
    TreeNode* temp = root->getRight();
    deleteTree(temp, deletedNumber);
  }
  //deleted Number is less than the root, recursive call for root left child
  if(deletedNumber < root->getValue()){
    TreeNode* temp = root->getLeft();
    deleteTree(temp, deletedNumber);
  }

  //deleted Number is equal to root
  if(deletedNumber == root->getValue()){

    
    if(root->getLeft() == NULL && root->getRight() == NULL){
      delete root;
      root = NULL;
    }

    //If left and right child are not null or if left is null
    if(root->getRight() != NULL){
      TreeNode* temp = root;
      //set temp to right child value
      temp->setValue(root->getRight()->getValue());
      //set right child to root value
      root->getRight()->setValue(root->getValue());
      //set root to right child value
      root->setValue(temp->getValue());
      temp = root->getRight();
      deleteTree(temp, deletedNumber);
    }

    //ifright child is null
    if(root->getRight() == NULL && root->getLeft() != NULL){
       TreeNode* temp = root;
      //set temp to left child value
      temp->setValue(root->getLeft()->getValue());
      //set left child to root value
      root->getLeft()->setValue(root->getValue());
      //set root to Left child value
      root->setValue(temp->getValue());
      temp = root->getLeft();
      deleteTree(temp, deletedNumber);
    }
  }
}

//Print binary tree
void printTree(TreeNode* root, int indent){

  int layer = 0;

  if(root != NULL){
    

  }

  
  




}
