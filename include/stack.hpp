# ifndef STACK_HPP
# define STACK_HPP

#include "vector.hpp"

namespace ft 
{
	template <class T, class Container = ft::vector<T> >
		class stack 
		{
			public:
				typedef typename Container::value_type value_type;
				typedef typename Container::size_type size_type;
				typedef Container container_type;
			protected:
				Container c;
			public:
					explicit stack(const Container &src = Container()) : c(src) {};
					bool empty() const { return c.empty(); }
					size_type size() const { return c.size(); }
					value_type& top() { return c.back(); }
					const value_type& top() const { return c.back(); }
					void push(const value_type& x) { c.push_back(x); }
					void pop() { c.pop_back(); }
			
					template <class T1, class Container1> friend bool operator==(const stack<T1, Container1> & lhs, const stack<T1, Container1> & rhs);
					template <class T1, class Container1> friend bool operator!=(const stack<T1, Container1> & lhs, const stack<T1, Container1> & rhs);
					template <class T1, class Container1> friend bool operator<(const stack<T1, Container1> & lhs, const stack<T1, Container1> & rhs);
					template <class T1, class Container1> friend bool operator<=(const stack<T1, Container1> & lhs, const stack<T1, Container1> & rhs);
					template <class T1, class Container1> friend bool operator>(const stack<T1, Container1> & lhs, const stack<T1, Container1> & rhs);
					template <class T1, class Container1> friend bool operator>=(const stack<T1, Container1> & lhs, const stack<T1, Container1> & rhs);
		};
		template <class T1, class Container1>
		bool operator==(const stack<T1, Container1>& x, const stack<T1, Container1>& y){
			return (x.c == y.c);};
		
		template <class T1, class Container1>
		bool operator< (const stack<T1, Container1>& x, const stack<T1, Container1>& y){
			return (x.c < y.c);};
		
		template <class T1, class Container1>
		bool operator!=(const stack<T1, Container1>& x, const stack<T1, Container1>& y){
			return (x.c != y.c);};
		
		template <class T1, class Container1>
		bool operator> (const stack<T1, Container1>& x, const stack<T1, Container1>& y){
			return (x.c > y.c);};
		
		template <class T1, class Container1>
		bool operator>=(const stack<T1, Container1>& x, const stack<T1, Container1>& y){
			return (x.c >= y.c);};
		
		template <class T1, class Container1>
		bool operator<=(const stack<T1, Container1>& x, const stack<T1, Container1>& y){
			return (x.c <= y.c);};
}

#endif
