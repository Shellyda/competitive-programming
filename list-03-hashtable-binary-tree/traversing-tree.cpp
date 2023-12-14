/*
B - Traversing Tree

Because you just finished your course in Binary Search Tree, your teacher gave you a very simple problem.

First, you are given some data and you should insert them to a binary search tree. Datas that are smaller than the current node go to the left sub-tree. Otherwise, they go to the right sub-tree.

Then, you should print all data in the tree by traversing it pre-orderly, in-orderly, and post-orderly.

Input
First line contains a number n (0 < n <= 100).
Second line contains n datas pi (0 < pi <= 50000) that have to be inserted into the tree.

Output
Output consists of 3 lines.
First line starts with 'Pre order :' and is continued by printing the data pre-orderly.
Second line starts with 'In order  :' and is continued by printing the data in-orderly.
Third line starts with 'Post order:' and is continued by printing the data post-orderly.

Example
Inputcopy	Outputcopy
7
5 3 7 2 4 6 8

Pre order : 5 3 2 4 7 6 8
In order  : 2 3 4 5 6 7 8
Post order: 2 4 3 6 8 7 5

Warning!
There is 1 space right after 'Pre order'.
There are 2 spaces right after 'In order'.
There is no space right after 'Post order'.
There is no space (enter immediately) right after the last number is printed.
*/

#include <iostream>
using namespace std;

class TreeNode
{
public:
  int data;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinarySearchTree
{
private:
  TreeNode *root;

  TreeNode *insert(TreeNode *node, int value)
  {
    if (node == nullptr)
    {
      return new TreeNode(value);
    }

    if (value < node->data)
    {
      node->left = insert(node->left, value);
    }
    else
    {
      node->right = insert(node->right, value);
    }

    return node;
  }

  bool search(TreeNode *node, int value)
  {
    if (node == nullptr)
    {
      return false;
    }

    if (value == node->data)
    {
      return true;
    }
    else if (value < node->data)
    {
      return search(node->left, value);
    }
    else
    {
      return search(node->right, value);
    }
  }

  void preOrderTraversal(TreeNode *node)
  {
    if (node != nullptr)
    {
      cout << node->data << " ";
      preOrderTraversal(node->left);
      preOrderTraversal(node->right);
    }
  }

  void inOrderTraversal(TreeNode *node)
  {
    if (node != nullptr)
    {
      inOrderTraversal(node->left);
      cout << node->data << " ";
      inOrderTraversal(node->right);
    }
  }

  void postOrderTraversal(TreeNode *node)
  {
    if (node != nullptr)
    {
      postOrderTraversal(node->left);
      postOrderTraversal(node->right);
      cout << node->data << " ";
    }
  }

public:
  BinarySearchTree() : root(nullptr) {}

  void insert(int value)
  {
    root = insert(root, value);
  }

  bool search(int value)
  {
    return search(root, value);
  }

  void inOrderTraversal()
  {
    inOrderTraversal(root);
  }

  void preOrderTraversal()
  {
    preOrderTraversal(root);
  }

  void postOrderTraversal()
  {
    postOrderTraversal(root);
  }
};

int main()
{
  BinarySearchTree bst;

  int elementsNumber;

  cin >> elementsNumber;

  for (int i = 0; i < elementsNumber; i++)
  {
    int data;
    cin >> data;
    bst.insert(data);
  }

  cout << "Pre order : ";
  bst.preOrderTraversal();

  cout << endl;

  cout << "In order  : ";
  bst.inOrderTraversal();

  cout << endl;

  cout << "Post order: ";
  bst.postOrderTraversal();

  return 0;
}