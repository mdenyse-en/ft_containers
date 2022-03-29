#ifndef ITERATORS_HPP
#define ITERATORS_HPP


namespace ft{

	//enable_if
	template<bool B, class T = void>
	struct	enable_if{};

	template<class T>
	struct enable_if<true, T> {typedef T type;};



	template<class T>
	struct	is_integral: std::false_type{};

	template<>
	struct	is_integral<int>: std::true_type{};

	template<>
	struct	is_integral<char>: std::true_type{};


	template<class InputIt>
	struct	is_iterator: std::false_type{};

	template<>
	struct	is_iterator<std::random_access_iterator_tag>: std::true_type{};







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
		typedef	typename	std::ptrdiff_t					difference_type;
		typedef	T								value_type;
		typedef	T*								pointer;
		typedef	T&								reference;
		typedef	typename	std::random_access_iterator_tag	iterator_category;
	};

	template<class T>
	struct iterator_traits<const T*>{
		typedef	typename	std::ptrdiff_t					difference_type;
		typedef	T								value_type;
		typedef	const T*						pointer;
		typedef	const T&						reference;
		typedef	typename	std::random_access_iterator_tag	iterator_category;
	};

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
				this->_head += n;
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




	// template<class Iter1, class Iter2>
	// bool	operator==(const ft::vector_iterator<Iter1>& lhs, const ft::reverse_iterator<Iter2>&rhs)
	// {return (&(*(lhs.base())) == &(*(rhs.base())));};

	// template<class Iter1, class Iter2>
	// bool	operator==(const ft::reverse_iterator<Iter2>&lhs, const ft::vector_iterator<Iter1>& rhs)
	// {return (&(*(lhs.base())) == &(*(rhs.base())));};
}




#endif