/ Rotate _right_node
        node_type *rightRotate(node_type *parent) 
        {
            node_type *left_child = parent->_left_node;
            node_type *right_child = left_child->_right_node;

            left_child->_right_node = parent;
            left_child->_parent_node = parent->_parent_node;
            parent->_left_node = right_child;
            if (left_child->_end == false)
					parent->_parent_node = left_child;
			if (right_child)
				right_child->_parent_node = parent;

            parent->_height = max(get_height(parent->_left_node), get_height(parent->_right_node)) + 1;
            left_child->_height = max(get_height(left_child->_left_node), get_height(left_child->_right_node)) +	1;

            return (left_child);
        }

        // Rotate _left_node
        node_type *leftRotate(node_type *parent) 
        {
            node_type *right_child = parent->_right_node;
            node_type *left_child = right_child->_left_node;
            
            right_child->_left_node = parent;
            right_child->_parent_node = parent->_parent_node;
            parent->_right_node = left_child;
            if (right_child->_end == false)
					parent->_parent_node = left_child;
			if (left_child)
				right_child->_parent_node = parent;


            left_child->_height = max(get_height(left_child->_left_node), get_height(left_child->_right_node)) +	1;
            parent->_height = max(get_height(parent->_left_node), get_height(parent->_right_node)) +	1;
            return (right_child);
        }
