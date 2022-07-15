#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include "random_access_iterator.hpp"
#include "iterator.hpp"
#include "iterator_traits.hpp"
#include <iostream>

namespace ft
{
	template <class Iterator>
	class reverse_iterator
	{
		public :
	
		typedef Iterator													iterator_type;
		typedef typename ft::iterator_traits<Iterator>::difference_type		difference_type;
		typedef typename ft::iterator_traits<Iterator>::value_type			value_type;     
		typedef typename ft::iterator_traits<Iterator>::reference			reference;          
		typedef typename ft::iterator_traits<Iterator>::pointer				pointer;           
		typedef typename ft::iterator_traits<Iterator>::iterator_category	iterator_category;

	//	operator	reverse_iterator<const value_type>(void) const;
		
/*============================MEMBER FUNCTIONS================================*/

		reverse_iterator() {_ptr = 0;};

		explicit reverse_iterator(Iterator ptr): _ptr(ptr) {};

		template <class Iter>
		reverse_iterator(const reverse_iterator<Iter>& src) : _ptr(src.base()){};

		reverse_iterator &operator=(const reverse_iterator &rhs){
			if (this!= &rhs)
				_ptr = rhs._ptr;
			return (*this);};

		virtual ~reverse_iterator(){};
		
		reference	operator*() const{
			return (*_ptr);}
		
		reverse_iterator &operator+(difference_type n) const {
			return (reverse_iterator(_ptr - n));};

		reverse_iterator &operator-(difference_type n) const {
			return (reverse_iterator(_ptr + n));};

		reverse_iterator &operator++(){
			--_ptr;
			return (*this);};
		
		reverse_iterator &operator++(int) {
			reverse_iterator tmp = *this;
			--(*this);
			return (tmp);};
		
		reverse_iterator &operator--(){
			++_ptr;
			return (*this);};

		reverse_iterator &operator--(int) {
			reverse_iterator tmp = *this;
			++(*this);
			return (tmp);};

		reverse_iterator &operator+=(difference_type n){
			_ptr -= n;
			return (*this);};
		
		reverse_iterator &operator-=(difference_type n){
			_ptr += n;
			return (*this);};

		pointer	operator->() const {
			return (&(operator *()));};

		reference operator[](difference_type n) const {
			return (_ptr[-n - 1]);};
		
		iterator_type base() const {
			return (_ptr);};
		
		friend std::ostream &operator<<(std::ostream &o, reverse_iterator<Iterator> &rhs)
		{o << *rhs._ptr;
			return (o);};
		
		operator		reverse_iterator<const value_type>(void) const
			{ return (reverse_iterator<const Iterator>(this->base()));};
	
	private :

		iterator_type _ptr;

	};
		// template <class Iterator>
		// reverse_iterator<Iterator>::operator		reverse_iterator<const typename reverse_iterator<Iterator>::value_type>(void) const
		// 	{ return (reverse_iterator<const Iterator>(this->base()));};
/*============================NON-MEMBER FUNCTIONS=============================*/

template< class Iterator1, class Iterator2 >
bool operator==( const reverse_iterator<Iterator1>& lhs,
                 const reverse_iterator<Iterator2>& rhs )
				 { return (lhs.base() == rhs.base());};

template< class Iterator1, class Iterator2 >
bool operator!=( const reverse_iterator<Iterator1>& lhs,
                 const reverse_iterator<Iterator2>& rhs )
				 { return (lhs.base() != rhs.base());};

template< class Iterator1, class Iterator2 >
bool operator<( const reverse_iterator<Iterator1>& lhs,
                const reverse_iterator<Iterator2>& rhs )
				{ return (lhs.base() < rhs.base());};

template< class Iterator1, class Iterator2 >
bool operator<=( const reverse_iterator<Iterator1>& lhs,
                 const reverse_iterator<Iterator2>& rhs )
				{ return (lhs.base() <= rhs.base());};

template< class Iterator1, class Iterator2 >
bool operator>( const reverse_iterator<Iterator1>& lhs,
                const reverse_iterator<Iterator2>& rhs )
				{ return (lhs.base() > rhs.base());};

template< class Iterator1, class Iterator2 >
bool operator>=( const reverse_iterator<Iterator1>& lhs,
                 const reverse_iterator<Iterator2>& rhs )
				{ return (lhs.base() >= rhs.base());};

template< class Iter >
reverse_iterator<Iter>
    operator+( typename reverse_iterator<Iter>::difference_type n,
               const reverse_iterator<Iter>& it )
			   { return (it + n); };

template< class Iterator >
typename reverse_iterator<Iterator>::difference_type
    operator-( const reverse_iterator<Iterator>& lhs,
               const reverse_iterator<Iterator>& rhs )
			   { return (lhs.base() - rhs.base());};
}

#endif
