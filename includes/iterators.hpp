#ifndef ITERATORS_HPP
#define ITERATORS_HPP


namespace ft{

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
			// typedef	typename std::bool	result_value;
			// typedef	t					first_argument_type;
			// typedef	t					second_argument_type;

			bool	operator()(const T& lhs, const T& rhs) const{
				return (lhs < rhs);
			}
	};

//enable_if
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


	template<class InputIt>
	struct	is_iterator: std::false_type{};

	template<> struct	is_iterator<std::random_access_iterator_tag>: std::true_type{};






//ITERATOR_TRAITS
	template<class Iter>
	struct iterator_traits{
		typedef typename	Iter::difference_type	difference_type;
		typedef typename	Iter::value_type		value_type;
		typedef typename	Iter::pointer			pointer;
		typedef typename	Iter::reference			reference;
		typedef typename	Iter::iterator_category	iterator_category;
	};

	// template<class Iter>
	// struct iterator_traits<const Iter>{
	// 	typedef typename	Iter::difference_type	difference_type;
	// 	typedef typename	Iter::value_type		value_type;
	// 	typedef const typename	Iter::pointer			pointer;
	// 	typedef const typename 	Iter::reference			reference;
	// 	typedef typename	Iter::iterator_category	iterator_category;
	// };

	template<class T>
	struct iterator_traits<T*>{
		typedef	typename	std::ptrdiff_t		difference_type;
		typedef	T								value_type;
		typedef	T*								pointer;
		typedef	T&								reference;
		typedef	typename	std::random_access_iterator_tag	iterator_category;
	};

	// template<class T>
	// struct iterator_traits<const T>{
	// 	typedef	typename	std::ptrdiff_t		difference_type;
	// 	typedef	T								value_type;
	// 	typedef	const T*						pointer;
	// 	typedef	const T&						reference;
	// 	typedef	typename	std::random_access_iterator_tag	iterator_category;
	// };

	template<class T>
	struct iterator_traits<const T*>{
		typedef	typename	std::ptrdiff_t		difference_type;
		typedef	T								value_type;
		typedef	const T*						pointer;
		typedef	const T&						reference;
		typedef	typename	std::random_access_iterator_tag	iterator_category;
	};

//VECTOR_ITERATOR
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

			vector_iterator(void){
				this->_head = nullptr;
			}

			vector_iterator(pointer p){
				this->_head = p;
			}

			vector_iterator(const vector_iterator& copy){
				*this = copy;
			}

			~vector_iterator(){};

			vector_iterator&	operator=(const vector_iterator& it){
				if (&it != this)
				{
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
				//return &(*(this->_head)); //is diference with this?:
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
				//return (vector_iterator(this->_head));
			}

			vector_iterator&	operator-=(difference_type n){
				this->_head -= n;
				return (*this);
				//return (vector_iterator(this->_head));
			}

			reference	operator[](difference_type n){
				return (this->_head[n]);
			}

		//	pointer		operator*(const vector_iterator& )

		private:
			pointer	_head;
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


//MAP iterator
	template<class T, class Compare = std::less<T> >
	class map_iterator{
		private:
			typedef iterator_traits<T*>	_traits_type;

		public:
			typedef typename _traits_type::difference_type		difference_type;
			typedef typename _traits_type::value_type			value_type;
			typedef typename _traits_type::pointer				pointer;
			typedef typename _traits_type::reference			reference;
			typedef typename _traits_type::iterator_category	iterator_category;
			typedef typename T::key_value						key_value;

			map_iterator(void): _head(), _end(){
			//	this->_head = nullptr;

			}

			map_iterator(pointer p, pointer end, Compare comp = Compare()): _head(p), _end(end), _comp(comp){
			//	this->_head = p;
			}

			map_iterator(const map_iterator& copy){
				*this = copy;
			}

			~map_iterator(){};

			map_iterator&	operator=(const map_iterator& it){
				if (&it != this)
				{
					this->_head = it._head;
					this->_end = it._end;
					this->_comp = it._comp;
				}
				return (*this);
			}

			pointer	base(void) const{
				return (this->_head);
			}

			key_value&	operator*(void){
				return (this->_head->_key);
			}

			const key_value&	operator*(void) const{
				return (this->_head->_key);
			}

			key_value*		operator->(void){
				//return &(*(this->_head)); //is diference with this?:
				return &(this->_head->_key);
			}

			const key_value*		operator->(void) const{
				//return &(*(this->_head)); //is diference with this?:
				return &(this->_head->_key);
			}

			map_iterator&	operator++(void){
				pointer tmp = this->_head;
				//std::cout << "++" << tmp->_key.second << std::endl;
				// if (this->_head->_right == nullptr){
				// 	this->_head = this->_end;
				// 	return (*this);
				// }
				if (tmp->_right == nullptr && tmp->_parent == nullptr){
					this->_head = this->_end;
					return (*this);
				}
				else if ((tmp->_right == nullptr) && (tmp->_parent != nullptr)){
					if (tmp == tmp->_parent->_right){
						while (tmp->_parent && tmp == tmp->_parent->_right)
							tmp = tmp->_parent;
						if (tmp->_parent == nullptr){
							this->_head = this->_end;
							return (*this);
						}
						else{
							this->_head = tmp->_parent;
							return (*this);
						}
						// this->_head = tmp->_parent;
						// return (*this);
					}
					else {
						this->_head = tmp->_parent;
						return (*this);
					}
				} else if ((tmp->_right != nullptr)){
					tmp = tmp->_right;
					while (tmp->_left)
						tmp = tmp->_left;
					this->_head = tmp;
					return (*this);
				}
				return (*this);
			}

			map_iterator	operator++(int){
				map_iterator	tmp = *this;
				++(*this);
				return (tmp);
			}

			map_iterator&	operator--(void){
				pointer tmp = this->_head;
			//	std::cout << "--" << tmp->_key.second << std::endl;
				//std::cout << "-p-" << tmp << " " << this->_end << std::endl;

				if (tmp == this->_end){
					tmp = tmp->_parent;
					while (tmp->_right != nullptr)
						tmp = tmp->_right;
					this->_head = tmp;
					return (*this);
				}
				// if (tmp->_left == nullptr){
				// 	this->_head = this->_end;
				// 	return (*this);
				// }
				if (tmp->_left == nullptr && tmp->_parent == nullptr){
					this->_head = this->_end;
					return (*this);
				}
				else if ((tmp->_left == nullptr) && (tmp->_parent != nullptr)){
					if (tmp == tmp->_parent->_left){
						if (tmp->_parent->_parent != nullptr){
							while (tmp->_parent != nullptr && tmp != tmp->_parent->_right)
								tmp = tmp->_parent;
							if (tmp->_parent == nullptr){
								this->_head = this->_end;
								return (*this);
							}
							else {
								this->_head = tmp->_parent;
								return(*this);
							}
						}
						//	this->_head = tmp->_parent->_parent;
						else
							this->_head = this->_end;
						return (*this);
					}
					else {
						this->_head = tmp->_parent;
						return (*this);
					}
				} else if ((tmp->_left != nullptr)){
					tmp = tmp->_left;
					while (tmp->_right != nullptr)
						tmp = tmp->_right;
					this->_head = tmp;
					return (*this);
				}
				return (*this);
			}

			map_iterator	operator--(int){
				map_iterator	tmp = *this;
				--(*this);
				return (tmp);
			}

			map_iterator		operator+(difference_type n){
				while (n-- > 0)
					++(*this);
				return (*this);
			}

			map_iterator		operator-(difference_type n){
				while (n-- > 0)
					--(*this);
				return (map_iterator(this->_head));
			}

			map_iterator&	operator+=(difference_type n){
				this->_head = this->_head + n;
				return (*this);
				//return (vector_iterator(this->_head));
			}

			map_iterator&	operator-=(difference_type n){
				this->_head = this->_head - n;
				return (*this);
				//return (vector_iterator(this->_head));
			}

			reference	operator[](difference_type n){
				return (this->_head[n]);
			}

		//	pointer		operator*(const vector_iterator& )

		private:
			pointer	_head;
			pointer	_end;
			Compare	_comp;
	};

	template<class Iter1, class Iter2>
	bool	operator==(const ft::map_iterator<Iter1>& lhs, const ft::map_iterator<Iter2>& rhs)
	{return (lhs.base() == rhs.base());};

	template<class Iter1, class Iter2>
	bool	operator!=(const ft::map_iterator<Iter1>& lhs, const ft::map_iterator<Iter2>& rhs)
	{return (lhs.base() != rhs.base());};

	// template<class Iter1, class Iter2>
	// bool	operator>(const ft::map_iterator<Iter1>& lhs, const ft::map_iterator<Iter2>& rhs)
	// {return (lhs.base() > rhs.base());};

	// template<class Iter1, class Iter2>
	// bool	operator>=(const ft::map_iterator<Iter1>& lhs, const ft::map_iterator<Iter2>& rhs)
	// {return (lhs.base() >= rhs.base());};

	// template<class Iter1, class Iter2>
	// bool	operator<(const ft::map_iterator<Iter1>& lhs, const ft::map_iterator<Iter2>& rhs)
	// {return (lhs.base() < rhs.base());};

	// template<class Iter1, class Iter2>
	// bool	operator<=(const ft::map_iterator<Iter1>& lhs, const ft::map_iterator<Iter2>& rhs)
	// {return (lhs.base() <= rhs.base());};



//reverse iterator:
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

			iterator_type	base(void) const
			{
				return (this->_current);
			}

			reference	operator*(void) const
			{
				iterator_type	tmp = _current;
				return (*(--tmp));
				//return (*(this->_current));
			}

			pointer		operator->(void) const
			{
				//iterator_type	tmp = _current;
				//return (&(*(--tmp)));
				//return &(*(this->_current));
				return (&(operator*()));
			}

			reference	operator[](difference_type n)
			{
				return (this->base()[-n - 1]);
				// return (this->_current[-n - 1]);
			}


			reverse_iterator&	operator++(void)
			{
				--(this->_current);
				return (*this);
			}

			reverse_iterator&	operator++(int)
			{
				reverse_iterator	tmp = this;
				++(*this);
				return (*tmp);
			}

			reverse_iterator&	operator+=(difference_type n)
			{
				this->_current -= n;
				return (*this);
			}

			reverse_iterator&	operator--(void)
			{
				++(this->_current);
				return (*this);
			}

			reverse_iterator&	operator--(int)
			{
				reverse_iterator	tmp = this;
				--(*this);
				return (*tmp);
			}

			reverse_iterator&	operator-=(difference_type n)
			{
				this->_current += n;
				return (*this);
			}

			reverse_iterator	operator+(difference_type n)
			{return (reverse_iterator(this->base() - n));}

			reverse_iterator	operator-(difference_type n)
			{return (reverse_iterator(this->base() + n));}
		
		protected:
			iterator_type	_current;
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

	// template<class Iter1, class Iter2>
	// bool	operator==(const ft::vector_iterator<Iter1>& lhs, const ft::reverse_iterator<Iter2>&rhs)
	// {return (&(*(lhs.base())) == &(*(rhs.base())));};

	// template<class Iter1, class Iter2>
	// bool	operator==(const ft::reverse_iterator<Iter2>&lhs, const ft::vector_iterator<Iter1>& rhs)
	// {return (&(*(lhs.base())) == &(*(rhs.base())));};
}




#endif