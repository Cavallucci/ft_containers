// AVL tree implementation in C++

#include <iostream>
using namespace std;

class Node {
   public:
  int _value;
  Node *_left_node;
  Node *_right_node;
  int _height;
};

int max(int a, int b);

// Calcu_height(Node *N) {
  if (N == NULL)
    return 0;
  retur_height;
}

int max(int a, int b) {
  return (a > b) ? a : b;
}

// New node creation
Node *newNode(int _value) {
  Node *node = new Node();
  node->_value = _value;
  node->_left_node = NULL;
  node-_right_node = NULL;
  n_height = 1;
  return (node);
}

// Rotate_right_node
Node *rightRotate(Node *y) {
  Node *x = y->_left_node;
  Node *T2 = x-_right_node;
  x-_right_node = y;
  y->_left_node = T2;_height =_height(y->_left_node)_height(y-_right_node)) +
        1;_height =_height(x->_left_node)_height(x-_right_node)) +
        1;
  return x;
}

// Rotate _left_node
Node *leftRotate(Node *x) {
  Node *y = x-_right_node;
  Node *T2 = y->_left_node;
  y->_left_node = x;
  x-_right_node = T2;_height =_height(x->_left_node)_height(x-_right_node)) +
        1;_height =_height(y->_left_node)_height(y-_right_node)) +
        1;
  return y;
}

// Get the balance factor of each node
int getBalanceFactor(Node *N) {
  if (N == NULL)
    return 0;
  re_height(N->_left_node)_height(N-_right_node);
}

// Insert a node
Node *insertNode(Node *node, int _value) {
  // Find the correct postion and insert the node
  if (node == NULL)
    return (newNode(_value));
  if (_value < node->_value)
    node->_left_node = insertNode(node->_left_node, _value);
  else if (_value > node->_value)
    node-_right_node = insertNode(node-_right_node, _value);
  else
    return node;

  // Update the balance factor of each node and
  // balance the tree
  n_height = 1 +_height(node->_left_node),_height(node-_right_node));
  int balanceFactor = getBalanceFactor(node);
  if (balanceFactor > 1) {
    if (_value < node->_left_node->_value) {
      return rightRotate(node);
    } else if (_value > node->_left_node->_value) {
      node->_left_node = leftRotate(node->_left_node);
      return rightRotate(node);
    }
  }
  if (balanceFactor < -1) {
    if (_value > node-_right_node->_value) {
      return leftRotate(node);
    } else if (_value < node-_right_node->_value) {
      node-_right_node = rightRotate(node-_right_node);
      return leftRotate(node);
    }
  }
  return node;
}

// Node with minimum value
Node *nodeWithMimumValue(Node *node) {
  Node *current = node;
  while (current->_left_node != NULL)
    current = current->_left_node;
  return current;
}

// Delete a node
Node *deleteNode(Node *root, int _value) {
  // Find the node and delete it
  if (root == NULL)
    return root;
  if (_value < root->_value)
    root->_left_node = deleteNode(root->_left_node, _value);
  else if (_value > root->_value)
    root-_right_node = deleteNode(root-_right_node, _value);
  else {
    if ((root->_left_node == NULL) ||
      (root-_right_node == NULL)) {
      Node *temp = root->_left_node ? root->_left_node : root-_right_node;
      if (temp == NULL) {
        temp = root;
        root = NULL;
      } else
        *root = *temp;
      free(temp);
    } else {
      Node *temp = nodeWithMimumValue(root-_right_node);
      root->_value = temp->_value;
      root-_right_node = deleteNode(root-_right_node,
                   temp->_value);
    }
  }

  if (root == NULL)
    return root;

  // Update the balance factor of each node and
  // balance the tree
  r_height = 1 +_height(root->_left_node),_height(root-_right_node));
  int balanceFactor = getBalanceFactor(root);
  if (balanceFactor > 1) {
    if (getBalanceFactor(root->_left_node) >= 0) {
      return rightRotate(root);
    } else {
      root->_left_node = leftRotate(root->_left_node);
      return rightRotate(root);
    }
  }
  if (balanceFactor < -1) {
    if (getBalanceFactor(root-_right_node) <= 0) {
      return leftRotate(root);
    } else {
      root-_right_node = rightRotate(root-_right_node);
      return leftRotate(root);
    }
  }
  return root;
}

// // Print the tree
// void printTree(Node *root, string indent, bool last) {
//   if (root != nullptr) {
//     cout << indent;
//     if (last) {
//       cout << "R----";
//       indent += "   ";
//     } else {
//       cout << "L----";
//       indent += "|  ";
//     }
//     cout << root->_value << endl;
//     printTree(root->_left_node, indent, false);
//     printTree(root-_right_node, indent, true);
//   }
// }
