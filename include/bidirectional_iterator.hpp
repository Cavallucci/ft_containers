 #ifndef BIDIRECTIONAL_ITERATOR_HPP
 #define BIDIRECTIONAL_ITERATOR_HPP

 #include "map.hpp"

 namespace ft
 {
	template <class T, class ptr_node>
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

		bidirectional_iterator(ptr_node ptr): _ptr(ptr) {};

		bidirectional_iterator(const bidirectional_iterator &src) : _ptr(src._ptr){};

		bidirectional_iterator &operator=(const bidirectional_iterator &rhs){
			if (this!= &rhs)
				_ptr = rhs._ptr;
			return (*this);};

		virtual ~bidirectional_iterator(){};
		
		reference	operator*() const{
			return (_ptr->_value);}
		
		bidirectional_iterator &operator++(void)
		{
			if (_ptr && _ptr->_right_node) //si droite, prendre droite puis toujours gauche pour avoir celui d'apres
			{
				_ptr = _ptr->_right_node;
				while (_ptr && _ptr->_left_node)
					_ptr = _ptr->_left_node;
			}
			else // sinon prendre gauche, puis remonter jusqua ce que tmp soit a gauche
			{
				ptr_node	tmp = _ptr;
				_ptr = _ptr->_parent_node;
				while (_ptr && _ptr->_left_node != tmp)
				{
					tmp = _ptr;
					_ptr = _ptr->_parent_node;
				}
			}
		 	return (*this);
		};
		
		bidirectional_iterator operator++(int) 
		{
		 	bidirectional_iterator tmp = *this;
		 	++(*this);
		 	return (tmp);
		};
		
		bidirectional_iterator &operator--()
		{
			if (_ptr && _ptr->_left_node) //si gauche, aller a gauche puis toujours a droite
			{
				_ptr = _ptr->_left_node;
				while (_ptr && _ptr->_right_node)
					_ptr = _ptr->_right_node;
			}
			else // sinon, prendre droite puis remonter jusqua ce aue tmp soit a droite
			{
				ptr_node	tmp;

				tmp = _ptr;
				_ptr = _ptr->_parent_node;
				while (_ptr && _ptr->_right_node != tmp)
				{
					tmp = _ptr;
					_ptr = _ptr->_parent_node;
				}
			}
			return (*this);
		};

		bidirectional_iterator operator--(int) {
			bidirectional_iterator tmp = *this;
			--(*this);
			return (tmp);};

		pointer	operator->() const {
			return (&(operator *()));};
		
		ptr_node	get_ptr() const { return (_ptr);};

		operator bidirectional_iterator<const T, ptr_node>() const
		{
			return (bidirectional_iterator<const T, ptr_node>(_ptr));
		};
		
		friend std::ostream &operator<<(std::ostream &o, bidirectional_iterator<T, ptr_node> &rhs)
		{o << *rhs._ptr;
			return (o);};
		
		template< class Iterator1>
		bool operator==( const bidirectional_iterator<Iterator1, ptr_node>& lhs) const
				 { return (get_ptr() == lhs.get_ptr());};

		template< class Iterator1>
		bool operator!=( const bidirectional_iterator<Iterator1, ptr_node>& lhs) const
				 { return (get_ptr() != lhs.get_ptr());};
	
	protected :

		ptr_node _ptr;

	};
}
#endif