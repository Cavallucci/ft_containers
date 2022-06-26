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

	//----------default :
	
	//Constructors :

		//empty
		vector() : _alloc(allocator_type()), _start(NULL), _size(0), _capacity(0), _end(NULL) {};

		//empty container constructor (default constructor)
		explicit vector (const allocator_type &alloc) : _alloc(alloc), _start(NULL), _size(0), _capacity(0), _end(NULL) {};

		//copy constructor
		vector (vector &other) : _alloc(allocator_type()), _start(NULL), _size(0), _capacity(0), _end(NULL)
		{ *this = other; };

		//fill constructor
		explicit vector( size_type count, const T& value = T(), const Allocator& alloc = Allocator())
		{
			_alloc = alloc;
			_start = _alloc.allocate(count * 2);
			_size = count;
			_capacity = count * 2;
			_end = _start + _size;
			
			value = 0; //---> ligne a supprimer
		//	int i = -1;
		//	while (i++ < n)
		//		_alloc.construct(_start + i, value);
		};

		//range constructor
		template <class InputIterator>
        vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type())
		{
			_alloc = alloc;

			InputIterator f = first;
			InputIterator l = last;
			_size = 0;

			while (f != l)
			{
				_size++;
				f++;
			}
			_start = _alloc.allocate(_size);
			_end = _start + _size;
			_capacity = _size * 2;
		};

		// destructor :
		~vector() {};
	//	{	clear();
	//		_alloc.deallocate(_start, capacity());};

		vector	&operator=(vector &other) {
			*this = other;
		}

	//-----------Element access :

	//-----------Iterators :

	//-----------Capacity :

	//-----------Modifiers :

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
