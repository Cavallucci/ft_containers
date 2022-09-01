

// Insert a node
node_type *insertNode(node_type *node, const value_type& val, node_type *parent) 
{
//--- Find the correct postion and insert the node
    if (node == NULL)
        return (newNode(val, parent));
    //si la recursive est finis
    if (node->_end == true)
    {
        node_type*  new_node;

        new_node = newNode(val, parent);
        new_node->_height = 1;
        node->_parent_node = new_node;
        new_node->_right_node = new_node;
        return (new_node);
    }
    //recursive 
    if (val.first < node->_value.first)
        node->_left_node = insertNode(node->_left_node, val, node);
    else if (val.first > node->_value.first)
        node->_right_node = insertNode(node->_right_node, val, node);
    else
        return (node);

//--- Update the balance factor of each node and balance the tree
    node->_height = 1 + max(getHeight(node->_left_node), getHeight(node->_right_node));
    int balance = getBalance(node);

    if (balance > 1) 
    {
        if (val < node->_left_node->val) 
            return rightRotate(node);
        else if (val > node->_left_node->val) 
        {
            node->_left_node = leftRotate(node->_left_node);
            return rightRotate(node);
        }
    }
    if (balance < -1) 
    {
        if (val > node->_right_node->val) 
            return leftRotate(node);
        else if (val < node->_right_node->val) 
        {
            node->_right_node = rightRotate(node->_right_node);
            return leftRotate(node);
        }
    }
    return (node);
};

// New node creation
node_type *newNode(const value_type& val, node_type *parent) 
{
    node_type *tmp = _alloc.allocate(1);
    _alloc.construct(tmp, node_type(val, NULL, NULL, parent, 0, 0, false));
    _size++;
    return (tmp);
};

node_type*  createInsertNode(const value_type& val, node_type* node, node_type* parent)
{
    //---Create a root
    if (!_root)
    {
        _root = newNode(val, NULL);
        node_type*  last_node = newNode(value_type(key_type(), mapped_type(), _root));
        _size--;
        _root->_right_node = last_node;
        last_node->_end = true;
        _root->height = 0;
        return (_root);
    }
    //---Create new root if only 1 node
    if (_root->_end)
    {
        node_type*  new_root = newNode(val, NULL);

        _root->_parent_node = new_root;
        new_root->_right_node = _root;
        new_root->_height = 0;
        _root = new_root;
        return (_root);
    }
    //---Insert node
    return (insertNode(val, curr, parent));
};

node_type*  getNodeFromKey(const key_type& key, node_type* node)
{
    if (!node || node->_end)
        return NULL;
    if (key < node->_value.first)
        return (getNodeFromKey(key, node->left_node));
    else if (key > node->_value.first)
        return (getNodeFromKey(key, node->right_node));
    else
        return (node);
};

