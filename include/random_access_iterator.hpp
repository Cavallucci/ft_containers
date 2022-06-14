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
	
		typedef ptrdiff_t							difference_type;          
		typedef T									value_type;     
		typedef T*			            		    pointer;             
		typedef T&									reference;          
		typedef random_access_iterator_tag			iterator_category;
		
	}
}
