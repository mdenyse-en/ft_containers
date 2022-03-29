#ifndef STACK_HPP
#define STACK_HPP

#include "vector.hpp"
#include <vector>

namespace ft
{
	template<class T, class Container = ft::vector<T> >
	class stack
	{
		typedef	Container							container_type;
		typedef	typename Container::value_type		value_type;
		typedef	typename Container::size_type		size_type;
		typedef	typename Container::reference		reference;
		typedef	typename Container::const_reference	const_reference;

		protected:
			container_type	_c;
			template <class TS, class ContainerS>
			friend bool	operator==(const ft::stack<TS, ContainerS>& lhs, const ft::stack<TS, ContainerS>& rhs);
			template <class TS, class ContainerS>
			friend bool	operator!=(const ft::stack<TS, ContainerS>& lhs, const ft::stack<TS, ContainerS>& rhs);
			template <class TS, class ContainerS>
			friend bool	operator<(const ft::stack<TS, ContainerS>& lhs, const ft::stack<TS, ContainerS>& rhs);
			template <class TS, class ContainerS>
			friend bool	operator<=(const ft::stack<TS, ContainerS>& lhs, const ft::stack<TS, ContainerS>& rhs);
			template <class TS, class ContainerS>
			friend bool	operator>(const ft::stack<TS, ContainerS>& lhs, const ft::stack<TS, ContainerS>& rhs);
			template <class TS, class ContainerS>
			friend bool	operator>=(const ft::stack<TS, ContainerS>& lhs, const ft::stack<TS, ContainerS>& rhs);

		public:
			explicit	stack(const container_type& cont = container_type())/*:_c(cont){};*/ {_c = cont;};
			stack(const stack& other){_c = other._c;};
			~stack(){};

			stack&	operator=(const stack& other){_c = other._c; return (*this);};

			//element access
			T&	top(void){return (_c.back());};
			const T&	top(void) const {return (_c.back());};

			//capacity
			bool	empty(void) const{return (_c.empty());}; 
			size_t	size(void) const{return (_c.size());}; 

			//modifiers
			void	push(const value_type& value){_c.push_back(value);}; 
			void	pop(void){_c.pop_back();};
	};

	template <class T, class Container>
	bool	operator==(const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs)
	{return (lhs._c == rhs._c);}

	template <class T, class Container>
	bool	operator!=(const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs)
	{return (lhs._c != rhs._c);}

	template <class T, class Container>
	bool	operator<(const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs)
	{return (lhs._c < rhs._c);}

	template <class T, class Container>
	bool	operator<=(const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs)
	{return (lhs._c <= rhs._c);}

	template <class T, class Container>
	bool	operator>(const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs)
	{return (lhs._c > rhs._c);}

	template <class T, class Container>
	bool	operator>=(const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs)
	{return (lhs._c >= rhs._c);}

}

#endif