// Delete a node
node_type *deleteNode(node_type *root, int _value) {
  // Find the node and delete it
  if (root == NULL)
    return root;
  if (_value < root->_value)
    root->_left_node = deleteNode(root->_left_node, _value);
  else if (_value > root->_value)
    root->_right_node = deleteNode(root->_right_node, _value);
  else {
    if ((root->_left_node == NULL) ||
      (root->_right_node == NULL)) {
      node_type *temp = root->_left_node ? root->_left_node : root->_right_node;
      if (temp == NULL) {
        temp = root;
        root = NULL;
      } else
        *root = *temp;
      free(temp);
    } else {
      node_type *temp = nodeWithMimumValue(root->_right_node);
      root->_value = temp->_value;
      root->_right_node = deleteNode(root->_right_node,
                   temp->_value);
    }
  }

  if (root == NULL)
    return root;

  // Update the balance factor of each node and
  // balance the tree
  root->_height = 1 + max(_height(root->_left_node),
               _height(root->_right_node));
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
    if (getBalanceFactor(root->_right_node) <= 0) {
      return leftRotate(root);
    } else {
      root->_right_node = rightRotate(root->_right_node);
      return leftRotate(root);
    }
  }
  return root;
}