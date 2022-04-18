#ifndef SET_HPP
#define SET_HPP

#include "iterators.hpp"
#include "RBTree.hpp"


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
			pair(const pair& p): first(p.first), second(p.second){};

			pair&	operator=(const pair& other)
			{
				if (this == &other)
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

	// template<class T1, class T2>
	// ft::pair<const T1, T2> make_pair(const T1 t, T2 u)
	// {
	// 	return (ft::pair<T1, T2>(t, u));
	// };


	template<class T1, class T2>
	bool	operator==(const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs){
		return ((lhs == rhs) && (lhs.second == rhs.second));
	};
	template<class T1, class T2>
	bool	operator!=(const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs){
		return (lhs != rhs);
	};
	template<class T1, class T2>
	bool	operator<(const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs){
		return ((lhs < rhs) || (!(rhs < lhs) && (lhs.second < rhs.second)));
	};
	template<class T1, class T2>
	bool	operator<=(const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs){
		return !(rhs < lhs);
	};
	template<class T1, class T2>
	bool	operator>(const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs){
		return (rhs < lhs);
	};
	template<class T1, class T2>
	bool	operator>=(const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs){
		return !(lhs < rhs);
	};


//SET /////////////////////////////
	template<
	class Key,
	class Compare = ft::less<Key>,
	class Allocator = std::allocator<Key> >
	class set{
		public:
			typedef	Key										key_type;
			typedef	Key										value_type;
			typedef	typename	std::size_t					size_type;
			typedef	typename	std::ptrdiff_t				difference_type;
			typedef				Compare						key_compare;
			typedef				Compare						value_compare;
			typedef				Allocator					allocator_type;
			typedef				value_type&					reference;
			typedef	const		value_type&					const_reference;
			typedef	typename	Allocator::pointer			pointer;
			typedef	typename	Allocator::const_pointer	const_pointer;
			typedef	ft::RBTree<value_type, value_compare, ft::RBTNode<value_type>, allocator_type>			tree_type;
			typedef	typename	tree_type::node_type				node_type;
			typedef	typename	tree_type::iterator					iterator;
			typedef	typename	tree_type::const_iterator			const_iterator;
			typedef	typename	ft::reverse_iterator<iterator>			reverse_iterator;
			typedef	typename	ft::reverse_iterator<const_iterator>	const_reverse_iterator;
			


			set(): _tree(value_compare(key_compare())){};
			explicit	set(const Compare& comp, const Allocator& alloc = Allocator()): _tree(), _comp(comp), _alloc(alloc){};

			template<class InputIt>
			set(InputIt first, InputIt last, const Compare& comp = Compare(), const Allocator& alloc = Allocator()):
			_tree(value_compare(key_compare())), _comp(comp), _alloc(alloc){
				this->insert(first, last);
			};

			set(const set& other): _tree(value_compare(key_compare())){
				//std::cout << "(set)" << std::endl;
				this->_comp = other._comp;
				this->_alloc = other._alloc;
				//this->_tree = other._tree;
				*this = other;
			};

			~set(){
			};

			//////
				// void	try_rightrotate(const T& key){
				// 	this->_tree.rotate_right(this->_tree.find_elem(key_type)));
				// }

				// void	try_leftrotate(const T& key){
				// 	this->_tree.rotate_left(this->_tree.find_elem(key_type)));
				// }

			/////

			set&	operator=(const set& other){
				//std::cout << "=" << std::endl;
				this->clear();
				this->_tree = other._tree;
				//this->insert(other.begin(), other.end());
				return (*this);
			};

			allocator_type	get_allocator() const{
				return (this->_alloc);
			};

		//Iterators
			iterator	begin(){
				return (iterator(this->_tree.min_elem(), this->_tree.tr_end()));
			};
			const_iterator	begin() const{
				return (const_iterator(this->_tree.min_elem(), this->_tree.tr_end()));
			};
			iterator	end(){
				return (iterator(this->_tree.tr_end(), this->_tree.tr_end()));
			};
			const_iterator	end() const{
				return (const_iterator(this->_tree.tr_end(), this->_tree.tr_end()));
			};
			
			reverse_iterator rbegin(void){
				if (this->_tree.empty())
					return (this->rend());
				return (reverse_iterator(this->end()));
			};

			const_reverse_iterator rbegin(void) const{
				if (this->_tree.empty() == 0)
					return (this->rend());
				return (reverse_iterator(this->end()));
			};

			reverse_iterator rend(void){
				return (reverse_iterator(this->begin()));
			};

			const_reverse_iterator rend(void) const{
				return (reverse_iterator(this->begin()));
			};
		
		//Capacity
			bool		empty() const {
				return (this->_tree.empty());
			};

			size_type	size() const {
				return (this->_tree.size());
			};

			size_type	max_size() const
			{return this->_alloc.max_size();};

		//Modifiers
			void		clear(){
				this->_tree.clear();
			}

			ft::pair<iterator, bool>	insert(const_reference value){
			//	std::cout << "1" << std::endl;
				if (this->count(value))
					return (ft::make_pair(iterator(this->_tree.find_elem(value), this->_tree.tr_end()), false));
				else
					return (ft::make_pair(iterator(this->_tree.insert(value), this->_tree.tr_end()), true));
			};

			iterator	insert(iterator hint, const_reference value){
				if (this->count(value))
					return (iterator(this->_tree.find_elem(value), this->end()));
				else
					return (iterator(this->_tree.insert(value), this->end()));
			};

			template<class InputIt>
			void		insert(InputIt first, InputIt last){
				for (InputIt f = first; f != last; f++){
					this->insert(*f);
				}
			};

			void	erase(iterator pos){
				this->_tree.remove(pos.base());
			};

			void	erase(iterator first, iterator last){ //do some right
				iterator	it;
				//std::cout << "last iterator: " << last->second <<std::endl;
				while (first != last){
					it = first;
					first++;
					this->_tree.remove(it.base());
				}
			};

			size_type	erase(const Key& key){
				//this->_tree.remove(key_type));
				return (this->_tree.remove(this->_tree.find_elem(key)));
			};

			void	swap(set& other){
				node_type*	tmp;

				tmp = this->_tree.tr_begin();
				this->_tree.set_begin(other._tree.tr_begin());
				other._tree.set_begin(tmp);

				tmp = this->_tree.tr_end();
				this->_tree.set_end(other._tree.tr_end());
				other._tree.set_end(tmp);
			};

		//Lookup
			size_type		count(const Key& key) const{
				// ft::pair<const int, int>	para = ;
				return (this->_tree.check_exist_value(key));
			};

			iterator		find(const Key& key){
				return (iterator(this->_tree.find_elem(key), this->_tree.tr_end()));
			};

			const_iterator	find(const Key& key) const{
				return (iterator(this->_tree.find_elem(key), this->_tree.tr_end()));
			};

			ft::pair<iterator, iterator>	equal_range(const Key& key){
				return (ft::make_pair(this->lower_bound(key), this->upper_bound(key)));
			};

			ft::pair<const_iterator, const_iterator>	equal_range(const Key& key) const{
				return (ft::make_pair(this->lower_bound(key), this->upper_bound(key)));
			};

			iterator		lower_bound(const Key& key){
				for (iterator it = this->begin(); it != this->end(); it++){
					//if (it->first >= key)
					if (!_comp(*it, key))
						return (it);
				}
				return (this->end());
			};

			const_iterator	lower_bound(const Key& key) const{
				for (iterator it = this->begin(); it != this->end(); it++){
					//if (it->first >= key)
					if (!_comp(*it, key))
						return (it);
				}
				return (this->end());
			};

			iterator		upper_bound(const Key& key){
				for (iterator it = this->begin(); it != this->end(); it++){
					//if (it->first > key)
					if (_comp(key, *it))
						return (it);
				}
				return (this->end());
			};

			const_iterator	upper_bound(const Key& key) const{
				for (iterator it = this->begin(); it != this->end(); it++){
					// if (it->first > key)
					if (_comp(key, *it))
						return (it);
				}
				return (this->end());
			};

		//Observers
			key_compare		key_comp() const{
				return (this->_comp);
			};

			// value_compare	value_comp() const{
			// 	return (this->_comp::key_value);
			// };

			// void	print(){
			// 	std::cout << RESET_COLOR << "tree output:" <<std::endl;
			// 	if (this->_tree.size() == 0)
			// 		std::cout << "TREE IS EMPTY" << std::endl;
			// 	else
			// 		this->_tree.print_tree(this->_tree.get_root(), 0);
			// 	std::cout << RESET_COLOR << "end output." <<std::endl;
			// };

		private:
			ft::RBTree<value_type, value_compare>	_tree;
			allocator_type		_alloc;
			Compare				_comp;
			//typename ft::RBTree<value_type>::node_type_pointer	_end;
	};

	template<class Key, class T, class Compare, class Alloc>
	bool	operator==(	const ft::set<Key,Compare, Alloc>& lhs,
						const ft::set<Key,Compare, Alloc>& rhs)
	{};
	template<class Key, class T, class Compare, class Alloc>
	bool	operator!=(	const ft::set<Key,Compare, Alloc>& lhs,
						const ft::set<Key,Compare, Alloc>& rhs)
	{};
	template<class Key, class T, class Compare, class Alloc>
	bool	operator<(	const ft::set<Key,Compare, Alloc>& lhs,
						const ft::set<Key,Compare, Alloc>& rhs)
	{};
	template<class Key, class T, class Compare, class Alloc>
	bool	operator<=(	const ft::set<Key,Compare, Alloc>& lhs,
						const ft::set<Key,Compare, Alloc>& rhs)
	{};
	template<class Key, class T, class Compare, class Alloc>
	bool	operator>(	const ft::set<Key,Compare, Alloc>& lhs,
						const ft::set<Key,Compare, Alloc>& rhs)
	{};
	template<class Key, class T, class Compare, class Alloc>
	bool	operator>=(	const ft::set<Key,Compare, Alloc>& lhs,
						const ft::set<Key, Compare, Alloc>& rhs)
	{};
	template<class Key, class T, class Compare, class Alloc>
	void	swap(const ft::set<Key, Compare, Alloc>& lhs,
				const ft::set<Key, Compare, Alloc>& rhs)
	{};
}

#endif