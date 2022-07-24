#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <string>
#include "iterator_traits.hpp"
#include "random_access_iterator.hpp"
#include "reverse_iterator.hpp"
#include "iterator.hpp"
#include "is_integral.hpp"
#include "enable_if.hpp"

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

//--------------default :
	
	//-----Constructors :

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
			
			size_t i = -1;
			while (i++ < count)
				_alloc.construct(_start + i, value);
		};

		//range constructor
		template <class InputIterator>
        vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL)
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

			for (size_t i = 0; first != last; i++)
			{
				_alloc.construct(_start + i, *first);
				first++;
			}
		};

	//-----Destructor :

		~vector()
		{	
			clear();
			_alloc.deallocate(_start, capacity());
		};

	//-----Operator= :

		vector	&operator=(vector &other)
		{
			if (other != *this)
				assign(other.begin(), other.end());
			return (*this);
		};
	
	//-----Assign :

		//range :
		template <class InputIterator>
		void assign (InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL)
		{
			if (_start)
				clear();
			insert(begin(), first, last);
		};

		//fill :
		void assign (size_t n, const value_type& val)
		{
			if (_start)
				clear();
			insert(begin(), n, val);
		};
	
	//-----Get_allocator :

		allocator_type get_allocator() const;

//---------------Element access :
	
	//-----At :

		//normal :
		reference at( size_type pos )
		{
			if (pos >= _size)
				throw std::out_of_range("vector:: Out of range");
			return (*(_start + pos));
		};

		//const :
		const_reference at(size_type pos) const
		{
			if (pos >= size())
				throw std::out_of_range("vector:: Out of range");
			return (*(_start + pos));
		};

	//-----Operator[] :

		//normal :
	    reference operator[] (size_type n)
		{ return (_start[n]);};

		//const :
		const_reference operator[] (size_type n) const
		{ return (_start[n]);};

	//-----Front :

		//normal :
		reference front()
		{ return (*_start);};

		//const :
		const_reference front() const
		{ return (*_start);};

	//-----Back :

		//normal :
	    reference back()
		{ return (*--end());};

		//const :
		const_reference back() const
		{ return (*--end());};

	//-----Data :

		//normal :
		T* data()
		{ return (_start); };

		//const :
		const T* data() const
		{ return (_start); };

//---------------Iterators :

	//-----Begin :

		//normal :
		iterator begin()
		{ return (iterator(_start));};

		//const :
		const_iterator begin() const
		{ return (const_iterator(_start));};

		//reverse :
		reverse_iterator rbegin()
		{ return (reverse_iterator(end()));};
		
		//const reverse :
		const_reverse_iterator rbegin() const
		{ return (const_reverse_iterator(end()));};

	//-----End :

		//normal :
		iterator end()
		{ return (iterator(_end));};

		//const :
		const_iterator end() const
		{ return (const_iterator(_end));};	

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

	//-----Capacity :
		size_type capacity() const
		{ return (this->_capacity);};

	//-----Reserve :
		void reserve (size_type n)
		{
			if (n > max_size())
				throw std::length_error("vector::reserve");
			if (n <= _capacity)
				return ;

			Allocator	tmp_alloc;
			pointer 	tmp_start = tmp_alloc.allocate(n);

			for (size_t i = 0; i < _size ; i++)
			{
				_alloc.construct(tmp_start + i, _start[i]);
				_alloc.destroy(_start + i);
			}
			_alloc.deallocate(_start, capacity());
			_start = tmp_start;
			_capacity = n;
			_end = _start + n;		
		};

//---------------Modifiers :

	//-----Clear :
		void clear()
		{ erase(begin(), end());};

	//-----Insert :
		//single element
		iterator insert( iterator pos, const T& value )
		{
			size_t	count = 1;

			insert(pos, count, value);
			return pos;
		};

		//fill :  inserts count copies of the value before pos
		void insert( iterator pos, size_type count, const T& value )
		{
			size_t index = pos - begin();

			if (!count)
				return;
			if (_size + count > _capacity)
				reserve(_size + count);
			
			for (size_t i = _size; i > index; i--)
			{
				_alloc.construct(_start + i + count - 1, *(_start + i - 1)); // si _start == 0 et pas 1, rajouter -1
				_alloc.destroy(_start + i - 1); // pareil 
			}
			for (size_t i = 0; i < count; i++)
			{
				_alloc.construct(_start + index + i, value);
				_size++;
			}
			_end = _start + _size;
			
		};

		//range :

		template <class InputIterator>
    	void insert (iterator pos, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL)
		{
			size_t	index = pos - begin();
			size_t	count = 0;
			ft::vector<value_type>	tmp(first, last);

			for(;first != last; count++)
				first++;
			for (size_t	i = 0; i < count; i++)
				insert(&_start[index + i], tmp[i]); //start+pos
		};

	//-----Erase :

		//position :
		iterator erase( iterator pos )
		{ return (erase(pos, pos + 1));};

		//first, last :
		iterator erase( iterator first, iterator last )
		{
			size_t		start = 0;
			size_t		count = 0;
			iterator	tmp_first = first;

			for(;first != last; count++)
				first++;
			while (tmp_first != iterator(_start + start))
				start++;
			size_t	end = start + count;

			while (start != end)
			{
				_alloc.destroy(_start + start);
				start++;
			}
			
			for (size_t i = end; i < _size; i++)
			{
				_alloc.construct(&_start[i - count], _start[i]);
				_alloc.destroy(&_start[i]);
			}
			
			_size -= count;
			_end = _start + _size;
			return (first);
		};

	//-----Push_back :

		void push_back (const value_type& val)
		{ insert(end(), val);};

	//-----Pop_back :

		void pop_back()
		{
			_alloc.destroy(&back());
			_size--;
			_end = _start + _size;
		};

	//-----Resize :

		void resize (size_type n, value_type val = value_type())
		{
			while (n < _size)
				pop_back();
			if (_size < n)
				insert(end(), n - _size, val);
		};

	//-----Swap :

		void swap( vector& other )
		{
			Allocator	tmp_alloc;
			pointer		tmp_start;
			size_type	tmp_size;
			size_type	tmp_capacity;
			pointer		tmp_end;

			if (other != *this)
			{
				tmp_alloc = other._alloc;
				tmp_start = other._start;
				tmp_size = other._size;
				tmp_capacity = other._capacity;
				tmp_end = other._end;

				other._alloc = _alloc;
				other._start = _start;
				other._size = _size;
				other._capacity = _capacity;
				other._end = _end;

				_alloc = tmp_alloc;
				_start = tmp_start;
				_size = tmp_size;
				_capacity = tmp_capacity;
				_end = tmp_end;
			}
		};

	private :
		Allocator	_alloc;
		pointer		_start;
		size_type	_size;
		size_type	_capacity;
		pointer		_end;
	};
/*--------------------------------NON-MEMBER FUNCTION--------------------------------*/

//-----Relational operators :

	//== :
	template <class T, class Alloc>
	bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		//The equality comparison (operator==) is performed by first comparing sizes,
		// and if they match, the elements are compared sequentially using operator==,
		// stopping at the first mismatch (as if using algorithm equal).

		if (lhs.size() != rhs.size())
			return (false);

		typename vector<T>::const_iterator tmp_lhs = lhs.begin();
		typename vector<T>::const_iterator tmp_rhs = rhs.begin();

		while (tmp_lhs != lhs.end() && tmp_rhs != rhs.end())
		{
			if (*tmp_lhs != *tmp_rhs)
				return (false);
			tmp_lhs++;
			tmp_rhs++;
		}
		return (true);
	};

	//!= :
	template <class T, class Alloc>
	bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{ return (!(lhs == rhs));};

	//< :
	template <class T, class Alloc>
	bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		typename vector<T>::const_iterator tmp_lhs = lhs.begin();
		typename vector<T>::const_iterator tmp_rhs = rhs.begin();

		while (tmp_lhs != lhs.end() && tmp_rhs != rhs.end())
		{
			if (*tmp_lhs >= *tmp_rhs)
				return (false);
			tmp_lhs++;
			tmp_rhs++;
		}
		return (true);
	};
	
	//<= :
	template <class T, class Alloc>
	bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{ return (!(lhs > rhs));};

	//> :
	template <class T, class Alloc>
	bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{ return (rhs < lhs);};

	//>= :
	template <class T, class Alloc>
	bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{ return (!(lhs < rhs));};

// swap :

template <class T, class Alloc>
void swap (vector<T,Alloc>& x, vector<T,Alloc>& y)
{
	if (x != y)
		x.swap(y);
};
}

#endif