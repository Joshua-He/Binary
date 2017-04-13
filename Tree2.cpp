#include <iostream>
#include <string.h>
#include <stack>
#include "TreeNode.h"
#include <cstring>
#include <stdlib.h>
#include <stdio.h>
#include <Vector>
#include <math.h>
#include <iomanip>

using namespace std;


/*

Joshua He 

Period 7 

*/

void addToTree(int number, TreeNode* &root);
void deleteTree(TreeNode* &root, int deletedNumber);
void printTree(TreeNode* root);
void getPrintList(TreeNode* root, int k, int array[1000]);
void printRow(int array[1000], int height, int depth, int cnt);
int  getHeight(TreeNode* root);
void printBinary(TreeNode* root, int numberOfSpace);
void printRow1(int array[1000], int cnt);

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
  
  //  cout << "HELLO: " << array << endl;
  cout << "Print of the binary search tree: " << endl;
  //printBinary(root, 0);
  printTree(root);

  char input[100]="";
  int  value;
  int loop=1;
  while (loop ==1) {
    cout << endl << "Enter command (add, delete, print, exit):" << endl;
    cin >> input;

    if (!strcmp(input, (char*)"delete")) {
      cout << "Enter a number to delete from tree:" << endl;
      cin >> value;
      deleteTree(root, value);

      }

    if (!strcmp(input, (char*)"print")) {
      //printBinary(root, 0);
      printTree(root);
     }

    if (!strcmp(input, (char*)"add")) {
      cout << "Enter a number to add to tree:" << endl;
      cin >> value;
      addToTree(value, root);
	}

    if (!strcmp(input, (char*)"exit")) {
	  loop=0;
	}

  }
  
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
    root->setRight(temp);
    return;
  }
  //deleted Number is less than the root, recursive call for root left child
  if(deletedNumber < root->getValue()){
    TreeNode* temp = root->getLeft();
    deleteTree(temp, deletedNumber);
    root->setLeft(temp);
    return;
  }

  //deleted Number is equal to root
  if(deletedNumber == root->getValue()){

    
    if(root->getLeft() == NULL && root->getRight() == NULL){
      delete root;
      root = NULL;
      return;
    }

    //If left and right child are not null or if left is null
    if (root->getRight() != NULL){
      TreeNode* temp;
      int v; 
      //set temp to right child value
      v = root->getRight()->getValue();
      //set right child to root value
      root->getRight()->setValue(root->getValue());
      //set root to right child value
      root->setValue(v);
      temp = root->getRight();
      deleteTree(temp, deletedNumber);
      root->setRight(temp);
      return;
    }

    //ifright child is null
    if(root->getRight() == NULL && root->getLeft() != NULL){
       TreeNode* temp;
       int v;
      //set temp to left child value
      v =root->getLeft()->getValue();
      //set left child to root value
      root->getLeft()->setValue(root->getValue());
      //set root to Left child value
      root->setValue(v);
      temp = root->getLeft();
      deleteTree(temp, deletedNumber);
      root->setLeft(temp);
    }
  }
}

//Print binary tree
/*void printTree(TreeNode* &root, int depth){
  for (int i = 0; i < depth; i++) {
    cout << "\t";
  }

  if(root == NULL){
    cout << "NULL" << endl;
  }
  if(root != NULL){
    cout << root->getValue() << endl;
    TreeNode* tempLeft = root->getLeft();
    TreeNode* tempRight = root->getRight();
    printTree(tempLeft, depth - 1);
    printTree(tempRight, depth + 1);
  }
  else{
    cout << "EMPTY" << endl;
  }
  }*/

// print a binary search tree, row by row
void printTree(TreeNode* root)
 {
      int array[1000];
      // initialize the array
      for (int i=0; i< 1000; i++)
	array[i] =-999;  // -999 represent null tree node

      // put the tree node value into the array
      getPrintList(root, 0, array);
      
      int height = getHeight(root);
      //      cout << "Tree height: " << height << endl;
      
      int cnt=1;
      for (int i = 0 ; i < height; i ++) {
	// printRow(array, height, i, cnt);
	printRow1(array, cnt);
	cnt = cnt * 2; 
      }
  }

// get height of tree
int getHeight(TreeNode* root)
{
  if (root == NULL) {
    return 0;
  }

  int righth, lefth;
  righth = getHeight(root->getRight());
  lefth = getHeight(root->getLeft());

  if (righth > lefth) {
    return righth +1;
  }
  else
    {
      return lefth+1;
    }
}

// get the tree into an array for printing
void getPrintList(TreeNode* root, int k, int array[1000])
{
  if (root == NULL)
    return;

  array[k] = root->getValue();
  getPrintList(root->getLeft(), k*2+1, array);
  getPrintList(root->getRight(), k*2+2, array);
}

// print a row
void printRow1(int array[1000], int cnt)
{
  int startIndex = cnt-1;
  int endIndex = startIndex + cnt;

  for (int i = startIndex; i < endIndex; i++) {
    if (array[i] != -999)
      printf("%4d ", array[i]);
    else
      printf(" ___ ");
  }
  printf("\n");
}

