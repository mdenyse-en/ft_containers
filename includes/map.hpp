#ifndef MAP_HPP
#define MAP_HPP

#include "iterators.hpp"

namespace ft{
	template<class T1, class T2>
	struct pair{
		public:
			typedef	T1	first_type;
			typedef	T2	second_type;

			first_type	first;
			second_type	second;

			pair(void): first(), second(){};
			pair(const T1& x, const T2&y): first(x), second(y){};
			template<class U1, class U2>
			pair(const pair<U1, U2>& p): first(p.first), second(p.second){};
			pair(const pair& p) = default;

			pair&	operator=(const pair& other)
			{
				if (this == other)
					return (*this);
				this->first = other.first;
				this->second = other.second;
				return (*this);
			}
	};

	template<class T1, class T2>
	ft::pair<T1, T2> make_pair(T1 t, T2 u)
	{
		return (ft::pair<T1, T2>(t, u));
	};
}

#endif