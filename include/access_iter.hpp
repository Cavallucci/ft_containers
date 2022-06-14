#ifndef ACCESS_ITER_HPP                                                               
#define ACCESS_ITER_HPP                                                           

#include "random_access_iterator.hpp"

namespace ft                                                                     
{                                                                                
	template <class Iter>                     
		struct iterator_traits;
	{                                                                            
		typedef typename Iter::difference_type			difference_type;          
		typedef typename Iter::value_type				value_type;     
		typedef typename Iter::pointer	                pointer;             
		typedef typename Iter::reference				reference;          
		typedef typename Iter::iterator_category		iterator_category;
	};

	template <class T>
		struct iterator_traits<T*>;
	{
		typedef ptrdiff_t								difference_type;          
		typedef T										value_type;     
		typedef T*				            		    pointer;             
		typedef T&										reference;          
		typedef random_access_iterator_tag				iterator_category;
	};

	template <class T>
		struct iterator_traits<const T*>;
	{
		typedef ptrdiff_t								difference_type;          
		typedef T										value_type;     
		typedef const T*		        		        pointer;             
		typedef const T&								reference;          
		typedef random_access_iterator_tag				iterator_category;
	};
}

#endif 