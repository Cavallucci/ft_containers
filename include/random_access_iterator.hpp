#ifndef RANDOM_ACCESS_ITERATOR_HPP
#define RANDOM_ACCESS_ITERATOR_HPP

#include "iterator_traits.hpp"
#include <iostream>

namespace ft
{

	struct input_iterator_tag { };
	struct output_iterator_tag { };
	struct forward_iterator_tag : public input_iterator_tag { };
	struct bidirectional_iterator_tag : public forward_iterator_tag { };
	struct random_access_iterator_tag : public bidirectional_iterator_tag { };
	struct contiguous_iterator_tag: public random_access_iterator_tag { };

	template <class T>
	class random_access_iterator
	{
		public :
	
		typedef T								value_type;     
		typedef std::ptrdiff_t					difference_type;
		typedef T&								reference;          
		typedef T* 								pointer;           
		typedef ft::random_access_iterator_tag	iterator_category;

		operator										random_access_iterator<const value_type>(void) const;
		
/*============================MEMBER FUNCTIONS================================*/

		random_access_iterator() {_ptr = 0;};

		random_access_iterator(T *ptr): _ptr(ptr) {};

		random_access_iterator(const random_access_iterator &src) : _ptr(src._ptr){};

		random_access_iterator &operator=(const random_access_iterator &rhs){
			if (this!= &rhs)
				_ptr = rhs._ptr;
			return (*this);};

		virtual ~random_access_iterator(){};
		
		reference	operator*() const{
			return (*_ptr);}
		
		random_access_iterator operator+(difference_type n) const {
			return (random_access_iterator(_ptr + n));};

		random_access_iterator operator-(difference_type n) const {
			return (random_access_iterator(_ptr - n));};

		random_access_iterator &operator++(){
			++_ptr;
			return (*this);};
		
		random_access_iterator operator++(int) {
			random_access_iterator tmp = *this;
			++(*this);
			return (tmp);};
		
		random_access_iterator &operator--(){
			--_ptr;
			return (*this);};

		random_access_iterator operator--(int) {
			random_access_iterator tmp = *this;
			--(*this);
			return (tmp);};

		random_access_iterator &operator+=(difference_type n){
			_ptr += n;
			return (*this);};
		
		random_access_iterator &operator-=(difference_type n){
			_ptr -= n;
			return (*this);};

		pointer	operator->() const {
			return (&(operator *()));};

		reference operator[](difference_type n) const {
			return (_ptr[n]);};
		
		pointer base() const {
			return (_ptr);};
		
		friend std::ostream &operator<<(std::ostream &o, random_access_iterator<T> &rhs)
		{o << *rhs._ptr;
			return (o);};
		
		//template <class T>
		//random_access_iterator<T>::operator		random_access_iterator<const typename random_access_iterator<T>::value_type>(void) const
		//	{ return (random_access_iterator<const T>(this->base()));};
	
	private :

		pointer _ptr;

	};
		template <class T>
		random_access_iterator<T>::operator		random_access_iterator<const typename random_access_iterator<T>::value_type>(void) const
			{ return (random_access_iterator<const T>(this->base()));};
/*============================NON-MEMBER FUNCTIONS=============================*/

template< class Iterator1, class Iterator2 >
bool operator==( const random_access_iterator<Iterator1>& lhs,
                 const random_access_iterator<Iterator2>& rhs )
				 { return (lhs.base() == rhs.base());};

template< class Iterator1, class Iterator2 >
bool operator!=( const random_access_iterator<Iterator1>& lhs,
                 const random_access_iterator<Iterator2>& rhs )
				 { return (lhs.base() != rhs.base());};

template< class Iterator1, class Iterator2 >
bool operator<( const random_access_iterator<Iterator1>& lhs,
                const random_access_iterator<Iterator2>& rhs )
				{ return (lhs.base() < rhs.base());};

template< class Iterator1, class Iterator2 >
bool operator<=( const random_access_iterator<Iterator1>& lhs,
                 const random_access_iterator<Iterator2>& rhs )
				{ return (lhs.base() <= rhs.base());};

template< class Iterator1, class Iterator2 >
bool operator>( const random_access_iterator<Iterator1>& lhs,
                const random_access_iterator<Iterator2>& rhs )
				{ return (lhs.base() > rhs.base());};

template< class Iterator1, class Iterator2 >
bool operator>=( const random_access_iterator<Iterator1>& lhs,
                 const random_access_iterator<Iterator2>& rhs )
				{ return (lhs.base() >= rhs.base());};

template< class Iter >
random_access_iterator<Iter>
    operator+( typename random_access_iterator<Iter>::difference_type n,
               const random_access_iterator<Iter>& it )
			   { return (it + n); };

template< class Iterator >
typename random_access_iterator<Iterator>::difference_type
    operator-( const random_access_iterator<Iterator>& lhs,
               const random_access_iterator<Iterator>& rhs )
			   { return (lhs.base() - rhs.base());};
}

#endif
