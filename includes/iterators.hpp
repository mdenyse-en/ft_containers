#ifndef ITERATORS_HPP
#define ITERATORS_HPP

#include <cstddef>

namespace ft{

	template<class T> struct remove_const { typedef T type; };
	template<class T> struct remove_const <const T> { typedef T type; };

//LESS
	template<class Arg1, class Arg2, class Result>
	struct binary_function{
		public:
			typedef Result		result_value;
			typedef	Arg1		first_argument_type;
			typedef	Arg2		second_argument_type;
	};

	template<class T>
	struct less: ft::binary_function<T, T, bool>{
		public:
			bool	operator()(const T& lhs, const T& rhs) const{
				return (lhs < rhs);
			}
	};

//ENABLE_IF
	template<bool B, class T = void>
	struct	enable_if{};

	template<class T>
	struct enable_if<true, T> {typedef T type;};


	template<class T>
	struct	is_integral: std::false_type{};
	template<> struct	is_integral<int>: std::true_type{};
	template<> struct	is_integral<char>: std::true_type{};
	template<> struct	is_integral<bool>: std::true_type{};
	template<> struct	is_integral<char16_t>: std::true_type{};
	template<> struct	is_integral<char32_t>: std::true_type{};
	template<> struct	is_integral<wchar_t>: std::true_type{};
	template<> struct	is_integral<signed char>: std::true_type{};
	template<> struct	is_integral<short int>: std::true_type{};
	template<> struct	is_integral<unsigned int>: std::true_type{};
	template<> struct	is_integral<long int>: std::true_type{};
	template<> struct	is_integral<long long int>: std::true_type{};
	template<> struct	is_integral<unsigned char>: std::true_type{};
	template<> struct	is_integral<unsigned short int>: std::true_type{};
	template<> struct	is_integral<unsigned long int>: std::true_type{};
	template<> struct	is_integral<unsigned long long int>: std::true_type{};


//ITERATOR_TRAITS
	template<class Iter>
	struct iterator_traits{
		typedef typename	Iter::difference_type	difference_type;
		typedef typename	Iter::value_type		value_type;
		typedef typename	Iter::pointer			pointer;
		typedef typename	Iter::reference			reference;
		typedef typename	Iter::iterator_category	iterator_category;
	};

	template<class T>
	struct iterator_traits<T*>{
		typedef	typename	std::ptrdiff_t		difference_type;
		typedef	T								value_type;
		typedef	T*								pointer;
		typedef	T&								reference;
		typedef	typename	std::random_access_iterator_tag	iterator_category;
	};

	template<class T>
	struct iterator_traits<const T*>{
		typedef	typename	std::ptrdiff_t		difference_type;
		typedef	T								value_type;
		typedef	const T*						pointer;
		typedef	const T&						reference;
		typedef	typename	std::random_access_iterator_tag	iterator_category;
	};
	

//VECTOR_ITERATOR //////////////////////////////////////////////////////
	template<class T>
	class vector_iterator{
		private:
			typedef iterator_traits<T*>	_traits_type;

		public:
			typedef typename _traits_type::difference_type		difference_type;
			typedef typename _traits_type::value_type			value_type;
			typedef typename _traits_type::pointer				pointer;
			typedef typename _traits_type::reference			reference;
			typedef typename _traits_type::iterator_category	iterator_category;

		private:
			pointer	_head;

		public:
			vector_iterator(void): _head(nullptr){}
			vector_iterator(pointer p): _head(p){}
			vector_iterator(const vector_iterator<typename ft::remove_const<value_type>::type >& copy): _head(copy.base()){}
			~vector_iterator(){};

			vector_iterator&	operator=(const vector_iterator& it){
				if (&it != this){
					this->_head = it._head;
				}
				return (*this);
			}

			pointer	base(void) const{
				return (this->_head);
			}

			reference	operator*(void){
				return (*this->_head);
			}

			pointer		operator->(void){
				return (this->_head);
			}

			vector_iterator&	operator++(void){
				++(this->_head);
				return (*this);
			}

			vector_iterator	operator++(int){
				vector_iterator	tmp = *this;
				++(*this);
				return (tmp);
			}

			vector_iterator&	operator--(void){
				--this->_head;
				return (*this);
			}

			vector_iterator	operator--(int){
				vector_iterator	tmp = *this;
				--(*this);
				return (tmp);
			}

			vector_iterator		operator+(difference_type n){
				return (vector_iterator(this->_head + n));
			}

			vector_iterator		operator-(difference_type n){
				return (vector_iterator(this->_head - n));
			}

			vector_iterator&	operator+=(difference_type n){
				this->_head += n;
				return (*this);
			}

			vector_iterator&	operator-=(difference_type n){
				this->_head -= n;
				return (*this);
			}

			reference	operator[](difference_type n){
				return (this->_head[n]);
			}
	};

	template<class Iter1, class Iter2>
	bool	operator==(const ft::vector_iterator<Iter1>& lhs, const ft::vector_iterator<Iter2>& rhs)
	{return (lhs.base() == rhs.base());};

	template<class Iter1, class Iter2>
	bool	operator!=(const ft::vector_iterator<Iter1>& lhs, const ft::vector_iterator<Iter2>& rhs)
	{return (lhs.base() != rhs.base());};

	template<class Iter1, class Iter2>
	bool	operator>(const ft::vector_iterator<Iter1>& lhs, const ft::vector_iterator<Iter2>& rhs)
	{return (lhs.base() > rhs.base());};

	template<class Iter1, class Iter2>
	bool	operator>=(const ft::vector_iterator<Iter1>& lhs, const ft::vector_iterator<Iter2>& rhs)
	{return (lhs.base() >= rhs.base());};

	template<class Iter1, class Iter2>
	bool	operator<(const ft::vector_iterator<Iter1>& lhs, const ft::vector_iterator<Iter2>& rhs)
	{return (lhs.base() < rhs.base());};

	template<class Iter1, class Iter2>
	bool	operator<=(const ft::vector_iterator<Iter1>& lhs, const ft::vector_iterator<Iter2>& rhs)
	{return (lhs.base() <= rhs.base());};


//REVERSE ITERATOR: /////////////////////////////////////////////////////
	template<class Iter>
	class reverse_iterator
	{
		public:
			typedef	Iter													iterator_type;
			typedef typename ft::iterator_traits<Iter>::iterator_category	iterator_category;
			typedef typename ft::iterator_traits<Iter>::value_type			value_type;
			typedef typename ft::iterator_traits<Iter>::difference_type		difference_type;
			typedef typename ft::iterator_traits<Iter>::pointer				pointer;
			typedef typename ft::iterator_traits<Iter>::reference			reference;

		protected:
			iterator_type	_current;

		public:
			reverse_iterator(void): _current(){}
			explicit reverse_iterator(iterator_type x): _current(x){}
			template <class U>
			reverse_iterator(const reverse_iterator<U>& other): _current(other.base()){}
			~reverse_iterator(){}

			template <class U>
			reverse_iterator&	operator=(const reverse_iterator<U>& other)
			{
				if (this != &other)
					this->_current = other._current;
				return (*this);
			};

			iterator_type	base(void) const{
				return (this->_current);
			}

			reference	operator*(void) const{
				iterator_type	tmp = _current;
				return (*(--tmp));
			}

			pointer		operator->(void) const{
				return (&(operator*()));
			}

			reference	operator[](difference_type n){
				return (this->base()[-n - 1]);
			}

			reverse_iterator&	operator++(void){
				--(this->_current);
				return (*this);
			}

			reverse_iterator	operator++(int){
				reverse_iterator	tmp(*this);
				++(*this);
				return (tmp);
			}

			reverse_iterator&	operator+=(difference_type n){
				this->_current -= n;
				return (*this);
			}

			reverse_iterator&	operator--(void){
				++(this->_current);
				return (*this);
			}

			reverse_iterator	operator--(int){
				reverse_iterator	tmp(*this);
				--(*this);
				return (tmp);
			}

			reverse_iterator&	operator-=(difference_type n){
				this->_current += n;
				return (*this);
			}

			reverse_iterator	operator+(difference_type n)
			{return (reverse_iterator(this->base() - n));}

			reverse_iterator	operator-(difference_type n)
			{return (reverse_iterator(this->base() + n));}
	};

	template<class Iterator1, class Iterator2>
	bool	operator==(const ft::reverse_iterator<Iterator1>& lhs,
					   const ft::reverse_iterator<Iterator2>& rhs)
	{return (lhs.base() == rhs.base());}

	template<class Iterator1, class Iterator2>
	bool	operator!=(const ft::reverse_iterator<Iterator1>& lhs,
					   const ft::reverse_iterator<Iterator2>& rhs)
	{return (lhs.base() != rhs.base());}

	template<class Iterator1, class Iterator2>
	bool	operator<(const ft::reverse_iterator<Iterator1>& lhs,
					  const ft::reverse_iterator<Iterator2>& rhs)
	{return (lhs.base() < rhs.base());}

	template<class Iterator1, class Iterator2>
	bool	operator<=(const ft::reverse_iterator<Iterator1>& lhs,
					   const ft::reverse_iterator<Iterator2>& rhs)
	{return (lhs.base() <= rhs.base());}

	template<class Iterator1, class Iterator2>
	bool	operator>(const ft::reverse_iterator<Iterator1>& lhs,
					const ft::reverse_iterator<Iterator2>& rhs)
	{return (lhs.base() > rhs.base());}

	template<class Iterator1, class Iterator2>
	bool	operator>=(const ft::reverse_iterator<Iterator1>& lhs,
					const ft::reverse_iterator<Iterator2>& rhs)
	{return (lhs.base() >= rhs.base());}

	template<class Iter>
	ft::reverse_iterator<Iter>	operator+(typename ft::reverse_iterator<Iter>::difference_type n,
										const ft::reverse_iterator<Iter>& it)
	{return (ft::reverse_iterator<Iter>(it.base() - n));};

	template<class Iter>
	typename ft::reverse_iterator<Iter>::difference_type
		operator-(const ft::reverse_iterator<Iter>& lhs,
				const ft::reverse_iterator<Iter>& rhs)
	{return (rhs.base() - lhs.base());};



//LEXICOGRAPHICAL_COMPARE/////////////////
	template<class InputIt1, class InputIt2>
	bool	lexicographical_compare(InputIt1 first1, InputIt1 last1,
									InputIt2 first2, InputIt2 last2){
		while ((first1 != last1) && (first2 != last2)){
			if (*first1 < *first2) return (true);
			if (*first1 > *first2) return (false);
			first1++;
			first2++;
		}
		return ((first1 == last1) && (first2 != last2));
	}

	template<class InputIt1, class InputIt2, class Compare>
	bool	lexicographical_compare(InputIt1 first1, InputIt1 last1,
									InputIt2 first2, InputIt2 last2, Compare comp){
		while ((first1 != last1) && (first2 != last2)){
			if (comp(*first1, *first2)) return (true);
			if (comp(*first1, *first2)) return (false);
			first1++;
			first2++;
		}
		return ((first1 == last1) && (first2 != last2));
	}


	template<class InputIt1, class InputIt2>
	bool	equal(InputIt1 first1, InputIt1 last1, InputIt2 first2){
		for (; first1 != last1; ++first1, ++first2){
			if (!(*first1 == *first2))
				return (0);
		}
		return (1);
	};

	template<class InputIt1, class InputIt2, class BinaryPredicate>
	bool	equal(InputIt1 first1, InputIt1 last1, InputIt2 first2, BinaryPredicate p){
		for (; first1 != last1; ++first1, ++first2){
			if (!p(*first1, *first2))
				return (0);
		}
		return (1);
	};


	template<class Iter1, class Iter2>
	bool	operator==(const ft::vector_iterator<Iter1>& lhs, const ft::reverse_iterator<Iter2>&rhs)
	{return (lhs.base() == rhs.base());};

	template<class Iter1, class Iter2>
	bool	operator==(const ft::reverse_iterator<Iter2>&lhs, const ft::vector_iterator<Iter1>& rhs)
	{return (lhs.base() == rhs.base());};

	template<class Iter1, class Iter2>
	bool	operator!=(const ft::vector_iterator<Iter1>& lhs, const ft::reverse_iterator<Iter2>&rhs)
	{return !(lhs == rhs);};

	template<class Iter1, class Iter2>
	bool	operator!=(const ft::reverse_iterator<Iter2>&lhs, const ft::vector_iterator<Iter1>& rhs)
	{return !(lhs == rhs);};
}

#endif