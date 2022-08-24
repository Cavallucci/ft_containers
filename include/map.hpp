#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include "vector.hpp"
#include "bidirectional_iterator.hpp"

namespace ft
{
    template <class T>
    struct tnode
    {
        T   _value;
        tnode   *_left_node;
        tnode   *_right_node;
        tnode   *_parent_node;
        int     _balance;
        int     _height;
        bool    _end;

        tnode(T value, tnode *left_node, tnode *right_node, tnode *parent_node, int balance, int height, bool end)
        : _value(value), _left_node(left_node), _right_node(right_node), _parent_node(parent_node), _balance(balance), _height(height), _end(end){};

        ~tnode() {};
    }

	template < class Key
     , class T
     , class Compare = std::less<Key>
     , class Allocator = std::allocator<std::pair<const Key, T>>>
    class map
	{
        public :

        typedef Key                                         key_type;
        typedef T                                           mapped_type;
        typedef pair<const key_type,mapped_type>            value_type;
        typedef Compare                                     key_compare;
                                                            value_compare;
        typedef Allo                                        allocator_type;
        typedef allocator_type::reference                   reference;
        typedef allocator_type::const_reference             const_reference;
        typedef allocator_type::pointer                     pointer;
        typedef allocator_type::const_pointer               const_pointer;
        typedef allocator_type::difference_type             difference_type;
        typedef allocator_type::size_type                   size_type;
        typedef ft::bidirectional_iterator<iterator>        iterator;
        typedef ft::bidirectional_iterator<const_iterator>  const_iterator;
        typedef ft::reverse_iterator<iterator>              reverse_iterator;
        typedef ft::reverse_iterator<const_iterator>        const_reverse_iterator;

        template <class Key, class T, class Compare, class Alloc>
        class map<Key,T,Compare,Alloc>::value_compare : binary_function<value_type,value_type,bool>
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
    }
}