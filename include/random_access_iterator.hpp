#ifndef RANDOM_ACCESS_ITERATOR_HPP
#define RANDOM_ACCESS_ITERATOR_HPP

#include "access_iter.hpp"

namespace ft
{

	struct input_iterator_tag { };
	struct output_iterator_tag { };
	struct forward_iterator_tag : public input_iterator_tag { };
	struct bidirectional_iterator_tag : public forward_iterator_tag { };
	struct random_access_iterator_tag : public bidirectional_iterator_tag { };
	struct contiguous_iterator_tag: public random_access_iterator_tag { };

	templace <class T>
	class random_access_iterator
	{
		public :
	
		typedef ft::iterator_traits<T>::value_type		value_type;     
		typedef ft::iterator_traits<T>::difference_type	difference_type;          
		typedef ft::iterator_traits<T>::reference		reference;          
		typedef T*										pointer;             
		typedef ft::random_access_iterator_tag			iterator_category;
		
		random_access_iterator();
		random_access_iterator(T *ptr);
		random_access_iterator(const random_access_iterator &src);
		~random_access_iterator();
		random_access_iterator &operator=(const random_access_iterator &rhs);
		

	}
}
