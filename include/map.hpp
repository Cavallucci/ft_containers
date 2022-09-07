#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include "vector.hpp"
#include "bidirectional_iterator.hpp"
#include "pair.hpp"
#include "enable_if.hpp"

namespace ft
{
    template <class T>
	struct less : std::binary_function<T, T, bool>
	{
		bool operator()(const T & x, const T & y) const
		{
			return (x < y);
		};
	};

    template <class T>
    struct tnode
    {
        T       _value;
        tnode*  _left_node;
        tnode*  _right_node;
        tnode*  _parent_node;
        int     _height;
        bool    _end;

        tnode(T value, tnode *left_node, tnode *right_node, tnode *parent_node, int height, bool end)
        : _value(value), _left_node(left_node), _right_node(right_node), _parent_node(parent_node), _height(height), _end(end){};

        ~tnode() {};
    };

/*================================== MAP ==========================================*/

	template < class Key
     , class T
     , class Compare = ft::less<Key>
     , class Allocator = std::allocator<std::pair<const Key, T> > >
    class map
	{
        public :

/*---------------------------------MEMBER TYPE-------------------------------------*/

        typedef Key                                                         key_type;
        typedef T                                                           mapped_type;
        typedef pair<const Key, T>                           value_type;
        typedef Compare                                                     key_compare;
        typedef tnode<value_type>						                    node_type;
        typedef Allocator                                                   allocator_type;
        typedef typename allocator_type::template rebind<node_type>::other  node_allocator;
        typedef typename allocator_type::reference                          reference;
        typedef typename allocator_type::const_reference                    const_reference;
        typedef typename allocator_type::pointer                            pointer;
        typedef typename allocator_type::const_pointer                      const_pointer;
        typedef typename allocator_type::difference_type                    difference_type;
        typedef typename allocator_type::size_type                          size_type;
        typedef ft::bidirectional_iterator<value_type, node_type*>          iterator;
        typedef ft::bidirectional_iterator<const value_type, node_type*>    const_iterator;
        typedef ft::reverse_iterator<iterator>                              reverse_iterator;
        typedef ft::reverse_iterator<const_iterator>                        const_reverse_iterator;

        protected :

        node_allocator  _alloc;
        key_compare     _compare;
        size_type       _size;
        node_type*      _root;

        public :
/*--------------------------------MEMBER CLASS-----------------------------------*/

        class value_compare
        {
            friend class map;
            
            protected:
                Compare comp;
                value_compare (Compare c) : comp(c) {}; 

            public:
                typedef bool result_type;
                typedef value_type first_argument_type;
                typedef value_type second_argument_type;
                
                bool operator() (const value_type& x, const value_type& y) const
                { return comp(x.first, y.first); };
        };
/*--------------------------------MEMBER FUNCTION--------------------------------*/

//--------------default :
	
	//-----Constructors :

        //empty
        explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
        : _alloc(alloc), _compare(comp), _size(0), _root(NULL) 
        {
            insert(value_type(key_type(), mapped_type()));
            _root->_end = true;
            if (_size > 0)
                _size--;
        };
        
        //range
        template <class InputIterator>
        map (typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
        : _alloc(alloc), _compare(comp), _size(0), _root(NULL)
        { insert(first, last); };

        //copy
        map (const map& x)
        : _alloc(x._alloc), _compare(x._compare), _size(0), _root(NULL)
        { *this = x; };

    //-----Destructor :

		~map()
		{ destroyAll(_root); };

    //-----Operator= :

        map& operator= (const map& x)
        {
            if (this != &x)
            {
                destroyAll(_root);
                insert(x.begin(), x.end());
            }
            return (*this);
        };

    //-----Get allocator :

        allocator_type get_allocator() const
        { return (_alloc); };

//---------------Iterators :

	//-----Begin :

		//normal :
		iterator begin()
		{ 
            node_type*   tmp;

            tmp = _root;
            while (tmp && tmp->_left_node)
                tmp = tmp->_left_node;
            return (iterator(tmp));
        };

		//const :
		const_iterator begin() const
		{ 
            node_type*   tmp;

            tmp = _root;
            while (tmp && tmp->_left_node)
                tmp = tmp->_left_node;
            return (const_iterator(tmp));
        };

		//reverse :
		reverse_iterator rbegin()
		{ return (reverse_iterator(end()));};
		
		//const reverse :
		const_reverse_iterator rbegin() const
		{ return (const_reverse_iterator(end()));};

    //-----End :

		//normal :
		iterator end()
		{
            node_type*   tmp;

            tmp = _root;
            while (tmp && tmp->_end == false)
                tmp = tmp->_right_node;
            return (iterator(tmp));
        };

		//const :
		const_iterator end() const
		{ 
            node_type*   tmp;

            tmp = _root;
            while (tmp && tmp->_end == false)
                tmp = tmp->_right_node;
            return (const_iterator(tmp));
        };	

		//reverse :
		reverse_iterator rend()
		{ return (reverse_iterator(begin()));};

		//const reverse :
		const_reverse_iterator rend() const
		{ return (const_reverse_iterator(begin()));};

//---------------Capacity :

	//-----Empty :

		bool empty() const
		{
			if (_size == 0)
				return (true);
			return (false);
		};

    //-----Size :

		size_type size() const
		{ return (_size);};

	//-----Max size :

		size_t	max_size()const 
		{ return (_alloc.max_size());};

//---------------Element access :

	//-----Operator[] :

	    T& operator[] (const key_type& k)
		{ 
            node_type   *node = getNodeFromKey(k, _root);
            
            if (node)
                return (node->_value.second);
            insert(value_type(k, mapped_type()));
            return (getNodeFromKey(k, _root)->_value.second);
        };

//---------------Modifiers :

	//-----Clear :

		void clear()
		{ destroyAll(_root); };

	//-----Insert :

		//single element
        pair<iterator,bool> insert (const value_type& val)
        {
            size_t  tmp_size = size();
            bool    inserted = false;

            _root = createInsertNode(val, _root, NULL);
            if (size() != tmp_size)
                inserted = true;
            return (pair<iterator, bool>(getNodeFromKey(val.first, _root), inserted));
        };

        //with hint
        iterator insert (iterator position, const value_type& val)
        {
            (void)position;
            insert(val);
            return (getNodeFromKey(val.first, _root));
        };

        //range
        template <class InputIterator>
        void insert (InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL)
        {
            while (first != last)
            {
                insert(*first);
                first++;
            }
        };

    //-----Erase :

		//position :
		void erase (iterator position)
        {
            erase(position->first);
        };

		//key :
		size_type erase (const key_type& k)
        {
            size_t  tmp_size;

            tmp_size = size();
            _root = deleteNode(_root, k);
            if (tmp_size != size())
                return (1);
            return (0);
        };

        //first, last :
        void erase (iterator first, iterator last)
        {
            while (first != last)
                erase(first++);
        };

    //-----Swap :

        void swap( map& other )
        {
            node_allocator  tmp_alloc;
            key_compare     tmp_compare;
            size_type       tmp_size;
            node_type*      tmp_root;

			if (other != *this)
			{
				tmp_alloc = other._alloc;
				tmp_compare = other._compare;
				tmp_size = other._size;
				tmp_root = other._root;

				other._alloc = _alloc;
				other._compare = _compare;
				other._size = _size;
				other._root = _root;

				_alloc = tmp_alloc;
				_compare = tmp_compare;
				_size = tmp_size;
				_root = tmp_root;
            }
        };

//---------------Lookup :

    //-----Count :

        size_type count (const key_type& k) const
        {
            if (getConstNodeFromKey(k, _root))
                return (1);
            return (0);
        };
    
    //-----Find :

        iterator find (const key_type& k)
        {
            iterator    tmp = begin();

            while (tmp != end() && (*tmp).first != k)
                tmp++;
            return (tmp);
        };

        //const
        const_iterator find (const key_type& k) const
        {
            const_iterator    tmp = begin();

            while (tmp != end() && (*tmp).first != k)
                tmp++;
            return (tmp);
        };

    //-----Equal range :

        //const
        pair<const_iterator,const_iterator> equal_range (const key_type& k) const
        { return (ft::make_pair(lower_bound(k), upper_bound(k))); };

        pair<iterator,iterator> equal_range (const key_type& k)
        { return (ft::make_pair(lower_bound(k), upper_bound(k))); };
    
    //-----Lower bound :

        iterator lower_bound (const key_type& k)
        {
            iterator    tmp = begin();
            key_compare tmp_key = key_comp();

            while (tmp != end() && tmp_key((*tmp).first, k))
                tmp++;
            return (tmp);
        };

        //const
        const_iterator lower_bound (const key_type& k) const
        {
            const_iterator  tmp = begin();
            key_compare     tmp_key = key_comp();

            while (tmp != end() && tmp_key((*tmp).first, k))
                tmp++;
            return (tmp);
        };
    
    //-----Upper bound :

        iterator upper_bound (const key_type& k)
        {
            iterator    tmp = begin();
            key_compare tmp_key = key_comp();

            while (tmp != end() && tmp_key((*tmp).first, k))
                tmp++;
            if (tmp != end() && (*tmp).first == k)
                tmp++;
            return (tmp);
        }

        //const
        const_iterator upper_bound (const key_type& k) const
        {
            const_iterator    tmp = begin();
            key_compare tmp_key = key_comp();

            while (tmp != end() && tmp_key((*tmp).first, k))
                tmp++;
            if (tmp != end() && (*tmp).first == k)
                tmp++;
            return (tmp);
        }

//---------------Observers :

    //-----Key comp :

        key_compare key_comp() const
        { return (_compare); };

    //-----Value comp :

        value_compare value_comp() const
        { return (value_compare(key_compare())); };



/*===========================================================================================*/
/*===========================================================================================*/
/*===========================================================================================*/
/*================================== AVL FUNCTIONS ==========================================*/
/*===========================================================================================*/
/*===========================================================================================*/
/*===========================================================================================*/


        // Calculate _height
        int getHeight(node_type *N) 
        {
            if (N == NULL)
                return 0;
            return N->_height;
        }

        int max(int a, int b) 
        { return (a > b) ? a : b; };

        // Rotate _right_node
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
					parent->_parent_node = right_child;
			if (left_child)
				left_child->_parent_node = parent;

            parent->_height = max(get_height(parent->_left_node), get_height(parent->_right_node)) + 1;
			right_child->_height = max(get_height(right_child->_left_node), get_height(right_child->_right_node)) + 1;
            return (right_child);
        }

        int get_height(node_type *node)
		{
		    if (!node)
                return (0);
		    return (node->_height);
		}

        // Get the balance factor of each node
        int getBalance(node_type *N) 
        {
            if (N == NULL)
                return 0;
            return (get_height(N->_left_node) - get_height(N->_right_node));
        }

        void	destroyAll(node_type *node)
        {
            if (!node)
                return;
            destroyAll(node->_left_node);
            destroyAll(node->_right_node);
            _alloc.destroy(node);
            _alloc.deallocate(node, 1);
            if (_size > 0)
                _size--;
            if (node == _root)
                _root = 0;
        };


        // Insert a node
        node_type *insertNode(node_type *node, const value_type& val, node_type *parent) 
        {
        //--- Find the correct postion and insert the node
            if (!node)
                return (newNode(val, parent));
            //si la recursive est finis
            if (node->_end == true)
            {
                node_type*  new_node;

                new_node = newNode(val, parent);
                new_node->_height = 1;
                node->_parent_node = new_node;
                new_node->_right_node = node;
                return (new_node);
            }
            //recursive 
            if (_compare(val.first, node->_value.first))
                node->_left_node = insertNode(node->_left_node, val, node);
            else if (_compare(node->_value.first, val.first))
                node->_right_node = insertNode(node->_right_node, val, node);
            else
                return (node);

        //--- Update the balance factor of each node and balance the tree
            node->_height = 1 + max(getHeight(node->_left_node), getHeight(node->_right_node));

			key_type left_key;
			if (node->_left_node)
				left_key = node->_left_node->_value.first;
            else
				left_key = key_type();

            int balance = getBalance(node);
            // if (balance > 1) 
            // {
            //     if (val < node->_left_node->_value) 
            //         return rightRotate(node);
            //     else if (val > node->_left_node->_value) 
            //     {
            //         node->_left_node = leftRotate(node->_left_node);
            //         return rightRotate(node);
            //     }
            // }
            // if (balance < -1) 
            // {
            //     if (val > node->_right_node->_value) 
            //         return leftRotate(node);
            //     else if (val < node->_right_node->_value) 
            //     {
            //         node->_right_node = rightRotate(node->_right_node);
            //         return leftRotate(node);
            //     }
            // }
            if (balance > 1 && getBalance(node->_left_node) >= 0)
                return (rightRotate(node));
            if (balance > 1 && getBalance(node->_left_node) < 0)
            {
                node->_left_node = leftRotate(node->_left_node);
                return (rightRotate(node));
            }
            if (balance < -1 && getBalance(node->_right_node) <= 0)
                return (leftRotate(node));
            if (balance < -1 && getBalance(node->_right_node) > 0)
            {
                node->_right_node = rightRotate(node->_right_node);
                return (leftRotate(node));
            }
            return (node);
        };

        // New node creation
        node_type *newNode(const value_type& val, node_type *parent) 
        {
            node_type *tmp = _alloc.allocate(1);
            _alloc.construct(tmp, node_type(val, NULL, NULL, parent, 0, false));
            _size++;
            return (tmp);
        };

        node_type*  createInsertNode(const value_type& val, node_type* node, node_type* parent)
        {
            //---Create a root
            if (!_root)
            {
                _root = newNode(val, NULL);
                node_type*  last_node = newNode(value_type(key_type(), mapped_type()), _root);
                _size--;
                _root->_right_node = last_node;
                last_node->_end = true;
                _root->_height = 0;
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
            return (insertNode(node, val, parent));
        };

        node_type*  getNodeFromKey(const key_type& key, node_type* node)
        {
            if (!node || node->_end)
                return NULL;
            if (_compare(key, node->_value.first))
                return (getNodeFromKey(key, node->_left_node));
            else if (_compare(node->_value.first, key))
                return (getNodeFromKey(key, node->_right_node));
            else
                return (node);
        };

        node_type*  getConstNodeFromKey(const key_type& key, node_type* node) const
        {
            if (!node || node->_end)
                return NULL;
            if (_compare(key, node->_value.first))
                return (getConstNodeFromKey(key, node->_left_node));
            else if (_compare(node->_value.first, key))
                return (getConstNodeFromKey(key, node->_right_node));
            else
                return (node);
        };

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
            if (node == NULL || node->_end == true)
                return node;
            if (_compare(key, node->_value.first))
                node->_left_node = deleteNode(node->_left_node, key);
            else if (_compare(node->_value.first, key))
                node->_right_node = deleteNode(node->_right_node, key); //end of recursive when k found
            else 
            {
                if ((node->_left_node == NULL) || (node->_right_node == NULL)) // if 1 or 0 child
                {
                    node_type *tmp;
                    if (node->_left_node)
                        tmp = node->_left_node;
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
                        tmp->_right_node = node->_right_node;
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
            node->_height = 1 + max(get_height(node->_left_node), get_height(node->_right_node));
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
/*===========================================================================================*/
/*===========================================================================================*/
    };
/*--------------------------------NON MEMBER FUNCTION--------------------------------*/

template <class Key, class T, class Compare, class Alloc>
  bool operator== ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs )
{
    typename ft::map<Key, T, Compare, Alloc>::const_iterator    tmp_lhs = lhs.begin();
    typename ft::map<Key, T, Compare, Alloc>::const_iterator    tmp_rhs = rhs.begin();

    if (lhs.size() != rhs.size())
        return (false);
    while (tmp_rhs != rhs.end() && tmp_lhs != lhs.end())
    {
        if (*tmp_rhs != *tmp_lhs)
            return (false);
        tmp_rhs++;
        tmp_lhs++;
    }
    return (true);
};
	
template <class Key, class T, class Compare, class Alloc>
  bool operator!= ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs )
{ return (!(lhs == rhs)); };
	
template <class Key, class T, class Compare, class Alloc>
  bool operator<  ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs )
{ return (lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));};

template <class Key, class T, class Compare, class Alloc>
  bool operator<= ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs )
{ return (lhs < rhs || lhs == rhs); };
	
template <class Key, class T, class Compare, class Alloc>
  bool operator>  ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs )
{ return (rhs < lhs); };

template <class Key, class T, class Compare, class Alloc>
  bool operator>= ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs )
{ return (lhs > rhs || lhs == rhs); };

template <class Key, class T, class Compare, class Alloc>
  void swap (map<Key,T,Compare,Alloc>& x, map<Key,T,Compare,Alloc>& y)
{
    x.swap(y);
};

}
#endif