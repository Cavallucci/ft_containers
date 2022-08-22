 #ifndef BIDIRECTIONAL_ITERATOR_HPP
 #define BIDIRECTIONAL_ITERATOR_HPP

 #include "map.hpp"

 namespace ft
 {
    class bidirectional_iterator
    {
        public :

        typedef T								value_type;     
		typedef std::ptrdiff_t					difference_type;
		typedef T&								reference;          
		typedef T* 								pointer;           
		typedef ft::random_access_iterator_tag	iterator_category;

        /*============================MEMBER FUNCTIONS================================*/
        bidirectional_iterator() {_ptr = 0;};

		bidirectional_iterator(T *ptr): _ptr(ptr) {};

		bidirectional_iterator(const bidirectional_iterator &src) : _ptr(src._ptr){};

		bidirectional_iterator &operator=(const bidirectional_iterator &rhs){
			if (this!= &rhs)
				_ptr = rhs._ptr;
			return (*this);};

		virtual ~bidirectional_iterator(){};
		
		reference	operator*() const{
			return (*_ptr);}
		
		bidirectional_iterator &operator++(){
			++_ptr;
			return (*this);};
		
		// bidirectional_iterator operator++(int) {
		// 	bidirectional_iterator tmp = *this;
		// 	++(*this);
		// 	return (tmp);};
		
		bidirectional_iterator &operator--(){
			--_ptr;
			return (*this);};

		bidirectional_iterator operator--(int) {
			bidirectional_iterator tmp = *this;
			--(*this);
			return (tmp);};

		pointer	operator->() const {
			return (&(operator *()));};
		
		pointer base() const {
			return (_ptr);};
		
		friend std::ostream &operator<<(std::ostream &o, bidirectional_iterator<T> &rhs)
		{o << *rhs._ptr;
			return (o);};
		
		//template <class T>
		//bidirectional_iterator<T>::operator		bidirectional_iterator<const typename bidirectional_iterator<T>::value_type>(void) const
		//	{ return (bidirectional_iterator<const T>(this->base()));};
	
	private :

		pointer _ptr;

	};
		template <class T>
		bidirectional_iterator<T>::operator		bidirectional_iterator<const typename bidirectional_iterator<T>::value_type>(void) const
			{ return (bidirectional_iterator<const T>(this->base()));};
/*============================NON-MEMBER FUNCTIONS=============================*/

template< class Iterator1, class Iterator2 >
bool operator==( const bidirectional_iterator<Iterator1>& lhs,
                 const bidirectional_iterator<Iterator2>& rhs )
				 { return (lhs.base() == rhs.base());};

template< class Iterator1, class Iterator2 >
bool operator!=( const bidirectional_iterator<Iterator1>& lhs,
                 const bidirectional_iterator<Iterator2>& rhs )
				 { return (lhs.base() != rhs.base());};

template< class Iter >
bidirectional_iterator<Iter>
    operator+( typename bidirectional_iterator<Iter>::difference_type n,
               const bidirectional_iterator<Iter>& it )
			   { return (it + n); };

template< class Iterator >
typename bidirectional_iterator<Iterator>::difference_type
    operator-( const bidirectional_iterator<Iterator>& lhs,
               const bidirectional_iterator<Iterator>& rhs )
			   { return (lhs.base() - rhs.base());};

 template< class Iterator1, class Iterator2 >
 typename bidirectional_iterator<Iterator1>::difference_type
     operator-( const bidirectional_iterator<Iterator1>& lhs,
                const bidirectional_iterator<Iterator2>& rhs )
 			   { return (lhs.base() - rhs.base());};

}
#endif