node_type *nodeWithMimumValue(node_type *node) 
{
	node_type *current = node;
	while (current->_left_node != NULL)
		current = current->_left_node;
	return current;
}

node_type *deleteNode(node_type *node, const key_type& key) 
{
  // Find the node and delete it
    if (node == NULL)
        return node;
	if (key < node->_value.first)
		node->_left_node = deleteNode(node->_left_node, key);
	else if (key > node->_value.first)
		node->_right_node = deleteNode(node->_right_node, key); //end of recursive when k found
	else 
	{
		if ((node->_left_node == NULL) || (node->_right_node == NULL)) // if 1 or 0 child
		{
			node_type *tmp
			if (node->_left_node)
				tmp = node->_left_node
			else
				tmp = node->_right_node;
			if (tmp == NULL) // if 0 child
			{
				tmp = node;
				_alloc.destroy(tmp);
				_alloc.deallocate(tmp, 1);
				node = NULL;
				_size--;
			} 
			else // if 1 child
			{
				node_type*	tmp2;
				tmp->_parent_node = node->_parent_node;
				tmp2 = node;
				node = tmp;
				_alloc.destroy(tmp2);
				_alloc.deallocate(tmp2, 1);
				_size--;

			}
		}
		else // if 2 child
		{
			node_type *tmp;
			if (node->_right_node->_end == false)
				tmp = nodeWithMimumValue(node->_right_node); //tmp node juste after
			else
				tmp = node->_left_node;
			if (tmp != node->_right_node) // reverse parent and child 
			{
				tmp->_right_node = node->right_node;
				node->_right_node->_parent_node = tmp;
			}
			tmp->_left_node = node->_left_node;
			node->_left_node->_parent_node = tmp;
			tmp->_parent_node->_left_node = NULL; // not forget second child
			tmp->_parent_node = node->_parent_node; //bypassing node to delete
			if (_root == node)
				_root = tmp;
			_alloc.destroy(node);
			_alloc.deallocate(node, 1);
			_size--;
			node = tmp; // change node to point at the one who was deleted
		}
	}

	if (node == NULL)
		return (node);
	// Update the balance factor of each node and balance the tree
	node->_height = 1 + max(_height(node->_left_node), _height(node->_right_node));
	int balance = getBalance(node);
	//rotations
	if (balance > 1) 
	{
		if (getBalance(node->_left_node) >= 0) 
			return rightRotate(node);
		else
		{
			node->_left_node = leftRotate(node->_left_node);
			return rightRotate(node);
		}
	}
	if (balance < -1) 
	{
		if (getBalance(node->_right_node) <= 0)
			return leftRotate(node);
		else
		{
			node->_right_node = rightRotate(node->_right_node);
			return leftRotate(node);
		}
	}
	return node;
}