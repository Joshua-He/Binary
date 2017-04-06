#include <iostream>

#ifndef TREENODE_H
#define TREENODE_H



class TreeNode{
 public:
  TreeNode();
  ~TreeNode();
  TreeNode* getRight();
  TreeNode* getLeft();

  void setLeft(TreeNode* newLeft);
  void setRight(TreeNode* newRight);
  int getValue();
  void setValue(int newvalue);
 private:
  
  TreeNode* left;
  TreeNode* right;
  int value;
};

#endif
