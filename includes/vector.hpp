#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "iterators.hpp"

namespace ft{
	template<class T, class Alloc = std::allocator<T> >
	class	vector
	{
		public:
			typedef T										value_type;
			typedef Alloc									allocator_type;
			typedef typename std::size_t					size_type;
			typedef typename std::ptrdiff_t					difference_type;
			typedef value_type&								reference;
			typedef const value_type&						const_reference;
			typedef typename Alloc::pointer					pointer;
			typedef typename Alloc::const_pointer			const_pointer;
			typedef ft::vector_iterator<value_type>			iterator;
			typedef ft::vector_iterator<const value_type>	const_iterator;
			typedef	ft::reverse_iterator<iterator>			reverse_iterator;
			typedef	ft::reverse_iterator<const_iterator>	const_reverse_iterator;

		private:
			pointer			_start_cont;
			pointer			_end_cont;
			pointer			_end_el;
			allocator_type	_alloc;

		public:
			explicit	vector(const allocator_type& alloc = allocator_type()): 
			_alloc(alloc), _start_cont(nullptr), _end_cont(nullptr), _end_el(nullptr){};
			explicit	vector(size_type count, const_reference value = value_type(), const allocator_type& alloc = allocator_type()):
			_alloc(alloc), _start_cont(nullptr), _end_cont(nullptr), _end_el(nullptr)
			{
				this->_start_cont = this->_alloc.allocate(count);
				this->_end_el = this->_start_cont + count;
				this->_end_cont = this->_start_cont;
				while (count--)
				{
					this->_alloc.construct(this->_end_cont++, value);
				}
			};

			template<class InputIt>
			vector(InputIt first, InputIt last, const allocator_type& alloc = allocator_type(),
			typename	ft::enable_if<!ft::is_integral<InputIt>::value, InputIt>::type = 0):
			_alloc(alloc), _start_cont(nullptr), _end_cont(nullptr), _end_el(nullptr)
			{
				this->insert(this->begin(), first, last);
			};
			

			vector(const vector& other)
			{
				if (this != &other)
					*this = other;
			};

			~vector(void)
			{
				//std::cout << "destruct vector. capacity: " << this->capacity() << ", size" << this->size() << std::endl;
				this->clear();
				try{
					this->_alloc.deallocate(this->_start_cont, this->capacity());
				} catch (std::exception& ex){
					std::cout << ex.what() << std::endl;
				}
			};

			vector&	operator=(const vector& other)
			{
				if (this != &other)
				{
					this->clear();
					if (this->capacity() < other.size())
						this->reserve(other.size());
					this->insert(this->begin(), other.begin(), other.end());
				}
				return (*this);
			};

			void	assign(size_type count, const_reference value){
				*this = vector(count, value);
			};
			
			template<class InputIt>
			void	assign(InputIt first, InputIt last,
			typename	ft::enable_if<!ft::is_integral<InputIt>::value, InputIt>::type = 0){
				*this = vector(first, last);
			};
			
			allocator_type	get_allocator(void) const
			{
				return (this->_alloc);
			};

		//element access
			reference	at(size_type pos)
			{
				if (!(pos < this->size()))
					throw (std::out_of_range("vector"));
				return (*(this->_start_cont + pos));
			};
			const_reference	at(size_type pos) const
			{
				if (!(pos < this->size()))
					throw (std::out_of_range("vector"));
				return (*(this->_start_cont + pos));
			};
			reference	operator[](size_type n)
			{return (*(this->_start_cont + n));};

			const_reference	operator[](size_type n) const
			{return (*(this->_start_cont + n));};

			reference	front(void)
			{return (*(this->_start_cont));};

			const_reference	front(void) const
			{return (*(this->_start_cont));};

			reference	back(void)
			{return (*(this->_end_el - 1));};

			const_reference	back(void) const
			{return (*(this->_end_el - 1));};

			pointer	data(void)
			{return (this->_start_cont);};

			const_pointer data(void) const
			{return (this->_start_cont);};

		//iterators:
			iterator begin(void){
				return (iterator(this->_start_cont));
			};

			const_iterator	begin(void) const{
				return (const_iterator(this->_start_cont));
			};

			iterator end(void){
				if (this->size() == 0)
					return (this->begin());
				return (this->_end_el);
			};

			const_iterator end(void) const{
				if (this->size() == 0)
					return (this->begin());
				return (this->_end_el);
			};

			reverse_iterator rbegin(void){
				if (this->size() == 0)
					return (this->rend());
				return (reverse_iterator(this->end()));
			};

			const_reverse_iterator rbegin(void) const{
				if (this->size() == 0)
					return (this->rend());
				return (reverse_iterator(this->end()));
			};

			reverse_iterator rend(void){
				return (reverse_iterator(this->begin()));
			};

			const_reverse_iterator rend(void) const{
				return (reverse_iterator(this->begin()));
			};

		//capacity
			bool	empty(void) const
			{return (this->size() == 0);};

			size_type	size(void) const
			{
				if (this->_start_cont == nullptr)
					return (0);
				return (this->_end_el - this->_start_cont);
			};

			size_type	max_size(void) const
			{return (this->_alloc.max_size());};

			void	reserve(size_type new_cap)
			{
				if (new_cap > this->max_size())
					throw(std::length_error("allocator<T>::allocate(size_t n) 'n' exceeds maximum supported size"));
				
				if (new_cap <= this->capacity())
					return ;

				pointer	new_start = this->_alloc.allocate(new_cap);
				pointer	new_end_el = new_start;
				
				int	i = 0;
				while (i < this->size())
					this->_alloc.construct(new_end_el++, this->_start_cont[i++]);
				this->clear();
				this->_alloc.deallocate(this->_start_cont, this->capacity());
				this->_start_cont = new_start;
				this->_end_cont = this->_start_cont + new_cap;
				this->_end_el = new_end_el;
			};

			size_type	capacity(void) const
			{return (this->_end_cont - this->_start_cont);};

		//modifiers
			void	clear(void){
				for (size_type i = 0; i < this->size(); i++){
					this->_alloc.destroy(this->_start_cont + i);
				}
				this->_end_el = this->_start_cont;
			};

			iterator	insert(iterator pos, const_reference value)
			{
				int	inp_pos = &(*pos) - this->_start_cont;
				this->insert(pos, 1, value);
				return(this->begin() + inp_pos);
			};

			void		insert(iterator pos, size_type count, const value_type& value)
			{
				if (count == 0)
					return ;
				size_type	new_size = this->size() + count;
				int		inp_pos = &(*pos) - this->_start_cont;
				size_type	empty_slots = 0;
				if (&(*pos) > this->_end_el)
					empty_slots = inp_pos - this->size();
				else
					empty_slots = 0;
				if (new_size + empty_slots > this->capacity())
				{
					if (new_size + empty_slots <= (this->capacity() * 2))
						this->reserve(this->capacity() * 2);
					else
						this->reserve(new_size + empty_slots);
				}
				pointer		tmp = this->_end_el + count + empty_slots;
				if (inp_pos < 0)
					tmp = this->_end_el + count;
				int			i = 0;
				if (inp_pos >= 0)
					while ((tmp - this->_start_cont > inp_pos - empty_slots) && (tmp >= this->_start_cont)){
						tmp--;
						if (tmp - this->_start_cont >= inp_pos + count)
							this->_alloc.construct(tmp, *(tmp - count - empty_slots));
						else if ((tmp - this->_start_cont >= inp_pos) && (tmp >= this->_start_cont))
							this->_alloc.construct(tmp, value);
						else
							this->_alloc.construct(tmp, value_type());
					}
				else {
					while (tmp >= this->_start_cont){
						tmp--;
						if (tmp - this->_start_cont >= count){
							this->_alloc.construct(tmp, *(tmp - count));
						}
						else if ((tmp - this->_start_cont < inp_pos + count)){
							this->_alloc.construct(tmp, value);
						}
						else{
							this->_alloc.construct(tmp, value_type());
						}
					}
				}
				this->_end_el = this->_start_cont + new_size + empty_slots;
			};

			template <class InputIt>//, typename ft::enable_if<!ft::is_integral<InputIt>::value, InputIt>::type 
			void		insert(iterator pos, InputIt first, InputIt last,
			typename	ft::enable_if<!ft::is_integral<InputIt>::value, InputIt>::type = 0)
			{
				size_type	inp_dist = &(*last) - &(*first);
				if ((inp_dist == 0) && (last < first))
					return ;
				size_type	new_size = this->size() + inp_dist;
				int		inp_pos = &(*pos) - this->_start_cont;
				size_type	empty_slots = 0;
				if (&(*pos) > this->_end_el)
					empty_slots = inp_pos - this->size();
				else
					empty_slots = 0;
				if (new_size + empty_slots > this->capacity())
				{
					if (new_size + empty_slots <= (this->capacity() * 2))
						this->reserve(this->capacity() * 2);
					else
						this->reserve(new_size + empty_slots);
				}
				pointer		tmp = this->_end_el + inp_dist + empty_slots;
				if (inp_pos < 0)
					tmp = this->_end_el + inp_dist;
				int			i = 0;
				if (inp_pos >= 0)
					while ((tmp - this->_start_cont > inp_pos - empty_slots) && (tmp > this->_start_cont)){
						tmp--;
						if (tmp - this->_start_cont >= inp_pos + inp_dist)
							this->_alloc.construct(tmp, *(tmp - inp_dist - empty_slots));
						else if ((tmp - this->_start_cont >= inp_pos) && (tmp >= this->_start_cont))
							this->_alloc.construct(tmp, *(--last));
						else
							this->_alloc.construct(tmp, value_type());
					}
				else {
					while (tmp > this->_start_cont){
						tmp--;
						if (tmp - this->_start_cont >= inp_dist){
							this->_alloc.construct(tmp, *(tmp - inp_dist));
						}
						else if ((tmp - this->_start_cont < inp_pos + inp_dist)){
							this->_alloc.construct(tmp, *(--last));
						}
						else{
							this->_alloc.construct(tmp, value_type());
						}
					}
				}
				this->_end_el = this->_start_cont + new_size + empty_slots;
			};

			iterator	erase(iterator pos, iterator pos2)
			{
				if ((pos >= this->begin()) && (pos < this->end()))
				{
					if (pos < pos2){
						iterator	tmp = pos;
						int			dist = &(*pos2) - &(*pos);
						while (tmp != this->end() - dist){
							*tmp = *(tmp + dist);
							tmp++;
						}
						while (tmp != this->end() - 1){
							this->_alloc.destroy(&(*tmp));
							tmp++;
						}
						this->_end_el -= dist;
						return (pos);
					}
				}
				return (pos);
			};

			iterator	erase(iterator pos){
				return (erase(pos, pos + 1));
			};

			void	push_back(const_reference value)
			{
				this->insert(this->end(), 1, value);
			};
			void	pop_back(void)
			{
				this->_end_el--;
				this->_alloc.destroy(this->_end_el);
			};
			void	resize(size_type count, value_type value = value_type()){
				if (count == this->size()){
					return ;
				}
				else if (count < this->size()){
					for(size_type i = count; i < this->size(); i++){
						this->_alloc.destroy(this->_start_cont + i);
					}
					this->_end_el = this->_start_cont + count;
				}
				else if ((count > this->size()) && (count <= this->capacity())){
					for (size_type i = this->size(); i < this->size() + count; i++){
						this->_alloc.construct(this->_start_cont + i, value);
					}
					this->_end_el = this->_start_cont + count;
				}
				else {
					if (this->capacity() * 2 < count)
						this->reserve(count);
					else
						this->reserve(this->capacity() * 2);
					this->resize(count, value);
				}
			};

			void	swap(vector& other){
				if (&other == this)
					return ;
				pointer	tmp;

				tmp = other._start_cont;
				other._start_cont = this->_start_cont;
				this->_start_cont = tmp;

				tmp = other._end_cont;
				other._end_cont = this->_end_cont;
				this->_end_cont = tmp;

				tmp = other._end_el;
				other._end_el = this->_end_el;
				this->_end_el = tmp;

				allocator_type other_alloc = other._alloc;
				other._alloc = this->_alloc;
				this->_alloc = other_alloc;
			};
	};

	template<class T, class Alloc>
	bool operator==(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs){
		if (lhs.size() != rhs.size())
			return (0);
		typename ft::vector<T>::const_iterator	it_lhs = lhs.begin();
		typename ft::vector<T>::const_iterator	it_rhs = rhs.begin();
		while (it_lhs != lhs.end()){
			if (*it_lhs != *it_rhs)
				return (0);
			it_lhs++;
			it_rhs++;
		}
		if (it_lhs != lhs.end() || it_rhs != rhs.end())
			return (0);
		return (1);
	}
	template<class T, class Alloc>
	bool operator!=(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs){
		return !(lhs == rhs);
	}
	template<class T, class Alloc>
	bool operator<(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs){
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}
	template<class T, class Alloc>
	bool operator<=(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs){
		return (lhs < rhs || lhs == rhs);
	}
	template<class T, class Alloc>
	bool operator>(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs){
		return (!(lhs < rhs) && (lhs != rhs));
	}
	template<class T, class Alloc>
	bool operator>=(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs){
		return (!(lhs < rhs));
	}

	template<class T, class Alloc>
	void	swap(const ft::vector<T, Alloc>& lhs,
				const ft::vector<T, Alloc>& rhs){
		lhs.swap(rhs);
	}
}

#endif