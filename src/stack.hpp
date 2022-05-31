# ifndef STACK_HPP
# define STACK_HPP

namespace ft {
	template <class T, class Container = deque<T> >
		class stack {
			public:
				typedef typename Container::value_type value_type;
				typedef typename Container::size_type size_type;
				typedef Container container_type;
			protected:
				Container c;
				481
					ISO/IEC 14882:1998(E) © ISO/IEC
					23.2.3.3 Template class stack 23 Containers library
			public:
					explicit stack(const Container& = Container());
					bool empty() const { return c.empty(); }
					size_type size() const { return c.size(); }
					value_type& top() { return c.back(); }
					const value_type& top() const { return c.back(); }
					void push(const value_type& x) { c.push_back(x); }
					void pop() { c.pop_back(); }
		};
	template <class T, class Container>
		bool operator==(const stack<T, Container>& x,
				const stack<T, Container>& y);
	template <class T, class Container>
		bool operator< (const stack<T, Container>& x,
				const stack<T, Container>& y);
	template <class T, class Container>
		bool operator!=(const stack<T, Container>& x,
				const stack<T, Container>& y);
	template <class T, class Container>
		bool operator> (const stack<T, Container>& x,
				const stack<T, Container>& y);
	template <class T, class Container>
		bool operator>=(const stack<T, Container>& x,
				const stack<T, Container>& y);
	template <class T, class Container>
		bool operator<=(const stack<T, Container>& x,
				const stack<T, Container>& y);
}

#endif
