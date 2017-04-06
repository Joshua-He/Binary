#include <iostream>
#include "TreeNode.h"
#include <string.h>


using namespace std;


TreeNode::TreeNode(){
  left = NULL;
  right = NULL;
}


TreeNode::~TreeNode(){
  
}

void TreeNode::setLeft(TreeNode* newLeft){
  left = newLeft;
}

void TreeNode::setRight(TreeNode* newRight){
  right = newRight;
}

TreeNode* TreeNode::getLeft(){
  return left;
}

TreeNode* TreeNode::getRight(){
  return right;
}

int TreeNode::getValue(){
  return value;
}

void TreeNode::setValue(int newvalue){
  value = newvalue;
}





