// AVL tree implementation in C++

#include <iostream>
using namespace std;

class node_type {
   public:
  int _value;
  node_type *_left_node;
  node_type *_right_node;
  int _height;
};

int max(int a, int b);

// Calculate _height
int getHeight(node_type *N) {
  if (N == NULL)
    return 0;
  return N->_height;
}

int max(int a, int b) {
  return (a > b) ? a : b;
}

// Rotate _right_node
node_type *rightRotate(node_type *y) {
  node_type *x = y->_left_node;
  node_type *T2 = x->_right_node;
  x->_right_node = y;
  y->_left_node = T2;
  y->_height = max(_height(y->_left_node),
          _height(y->_right_node)) +
        1;
  x->_height = max(_height(x->_left_node),
          _height(x->_right_node)) +
        1;
  return x;
}

// Rotate _left_node
node_type *leftRotate(node_type *x) {
  node_type *y = x->_right_node;
  node_type *T2 = y->_left_node;
  y->_left_node = x;
  x->_right_node = T2;
  x->_height = max(_height(x->_left_node),
          _height(x->_right_node)) +
        1;
  y->_height = max(_height(y->_left_node),
          _height(y->_right_node)) +
        1;
  return y;
}

// Get the balance factor of each node
int getBalance(node_type *N) {
  if (N == NULL)
    return 0;
  return _height(N->_left_node) -
       _height(N->_right_node);
}

// node_type with minimum value
node_type *nodeWithMimumValue(node_type *node) {
  node_type *current = node;
  while (current->_left_node != NULL)
    current = current->_left_node;
  return current;
}