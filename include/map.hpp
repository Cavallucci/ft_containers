#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include "vector.hpp"
#include "bidirectional_iterator.hpp"
#include "pair.hpp"

namespace ft
{
    template <class T>
    struct tnode
    {
        T       _value;
        tnode*  _left_node;
        tnode*  _right_node;
        tnode*  _parent_node;
        int     _balance;
        int     _height;
        bool    _end;

        tnode(T value, tnode *left_node, tnode *right_node, tnode *parent_node, int balance, int height, bool end)
        : _value(value), _left_node(left_node), _right_node(right_node), _parent_node(parent_node), _balance(balance), _height(height), _end(end){};

        ~tnode() {};
    }

/*================================== MAP ==========================================*/

	template < class Key
     , class T
     , class Compare = std::less<Key>
     , class Allocator = std::allocator<std::pair<const Key, T>>>
    class map
	{
        public :

/*---------------------------------MEMBER TYPE-------------------------------------*/

        typedef Key                                                         key_type;
        typedef T                                                           mapped_type;
        typedef pair<const key_type,mapped_type>                            value_type;
        typedef Compare                                                     key_compare;
        typedef Allo                                                        allocator_type;
        typedef allocator_type::reference                                   reference;
        typedef allocator_type::const_reference                             const_reference;
        typedef allocator_type::pointer                                     pointer;
        typedef allocator_type::const_pointer                               const_pointer;
        typedef allocator_type::difference_type                             difference_type;
        typedef allocator_type::size_type                                   size_type;
        typedef tnode<value_type>                                           node_type;
        typedef ft::bidirectional_iterator<value_type, node_type*>          iterator;
        typedef ft::bidirectional_iterator<const value_type, node_type*>    const_iterator;
        typedef ft::reverse_iterator<iterator>                              reverse_iterator;
        typedef ft::reverse_iterator<const_iterator>                        const_reverse_iterator;

        protected :

        node_allocator  _alloc;
        key_compare     _compare;
        size_type       _size;
        node_type*      _root;

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
                {
                    return comp(x.first, y.first);
                };
        };
/*--------------------------------MEMBER FUNCTION--------------------------------*/

//--------------default :
	
	//-----Constructors :

        //empty
        explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
        : _alloc(alloc), _compare(comp), _size(0), _root(NULL) {};
        
        //range
        template <class InputIterator>
        map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
        const allocator_type& alloc = allocator_type())
        : _alloc(alloc), _compare(comp), _size(0), _root(NULL)
        { insert(first, last); };

        //copy
        map (const map& x)
        : _alloc(alloc), _compare(comp), _size(0), _root(NULL)
        { *this = x; };

    //-----Destructor :

		~map()
		{	
			//destroy
		};
//---------------Iterators :

	//-----Begin :

		//normal :
		iterator begin()
		{ 
            node_type   tmp;

            tmp = _root;
            while (tmp && tmp->_left_node)
                tmp = tmp->_left_node;
            return (iterator(tmp));
        };

		//const :
		const_iterator begin() const
		{ 
            node_type   tmp;

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
            node_type   tmp;

            tmp = _root;
            while (tmp && tmp->_right_node)
                tmp = tmp->_right_node;
            return (iterator(tmp));
        };

		//const :
		const_iterator end() const
		{ 
            node_type   tmp;

            tmp = _root;
            while (tmp && tmp->_right_node)
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
            iterator tmp;

            tmp = find(k);
            if (k == end())
                insert(value_type(k, mapped_type()));
            tmp = find(k);
            return ((*tmp).second);
        };

//---------------Modifiers :

	//-----Clear :

		void clear()
		{ /*destroy*/ };

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
    }
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

}