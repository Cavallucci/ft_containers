#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <string>
#include "iterator_traits.hpp"
#include "random_access_iterator.hpp"
#include "reverse_iterator.hpp"

namespace ft
{
	template <class T, class Allocator = std::allocator<T> >
	class vector
	{
/*---------------------------------MEMBER TYPE-------------------------------------*/
		public :
			typedef T											value_type;
			typedef Allocator									allocator_type;
			typedef size_t										size_type;
			typedef std::ptrdiff_t								difference_type;
			typedef T											&reference;
			typedef T const										&const_reference;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;
			typedef random_access_iterator<value_type>			iterator;
			typedef random_access_iterator<const value_type>	const_iterator;
			typedef reverse_iterator<const_iterator>			const_reverse_iterator;
			typedef reverse_iterator<iterator>					reverse_iterator;

/*--------------------------------MEMBER FUNCTION--------------------------------*/

	// default :
		vector() : _alloc(allocator_type()), _start(NULL), _size(0), _capacity(0), _end(NULL) {};
//		explicit vector (const allocator_type &alloc);
//		vector (vector &&other);
		~vector()
		{};
	//		{	clear();
	//			_alloc.deallocate(_start, capacity());};

	// Element access :

	// Iterators :

	// Capacity :

	//Modifiers :

	private :
		Allocator	_alloc;
		pointer		_start;
		size_type	_size;
		size_type	_capacity;
		pointer		_end;
	};
/*--------------------------------NON-MEMBER FUNCTION--------------------------------*/
// operators :

// swap :

// erase :

}

#endif
