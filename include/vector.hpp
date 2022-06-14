#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include "access_iter.hpp"

namespace ft
{
	template <class T, class Allocator = std::allocator<T> >
	class vector
	{
/*---------------------------------MEMBER-------------------------------------*/
		public :
			typedef T										value_type;
			typedef Allocator								allocator_type;
			typedef size_t									size_type;
			typedef ptrdiff_t								difference_type;
			typedef T										&reference;
			typedef T const									&value_type;
			typedef allocator_type::pointer					pointer;
			typedef allocator_type::const_pointer			const_pointer;
//			typedef	 
	}
}
