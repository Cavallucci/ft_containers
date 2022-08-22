#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include "vector.hpp"
#include "bidirectional_iterator.hpp"

namespace ft
{
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
    }
}