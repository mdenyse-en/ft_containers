#ifndef RBTREE_HPP
#define RBTREE_HPP

#define RED_COLOR "\x1b[31m"
#define BLACK_COLOR "\x1b[30m"
#define RESET_COLOR "\x1b[0m"

namespace ft{
	
	enum RBT_color{red, black};

	template<class T>
	struct RBTNode{
		public:
			typedef	T	key_value;

			T			_key;
			RBTNode<T>*	_parent;
			RBTNode<T>*	_left;
			RBTNode<T>*	_right;
			RBT_color	_color;

			RBTNode(T key = T(), RBT_color color = red, RBTNode* par = nullptr, RBTNode* left = nullptr, RBTNode* right = nullptr):
			_key(key), _color(color), _parent (par), _left(left), _right(right){};

			RBTNode(const RBTNode& other): _key(other._key), _color(other._color), _parent(other._parent), _left(nullptr), _right(nullptr) {};
	};


//RBTree iterator //////////////////////////////////////////////////////////
	template<class T, class Node = RBTNode<T> >
	class RBTree_iterator{
		private:
			typedef ft::iterator_traits<T*>	_traits_type;

		public:
			typedef typename _traits_type::difference_type		difference_type;
			typedef typename _traits_type::value_type			value_type;
			typedef typename _traits_type::pointer				pointer;
			typedef typename _traits_type::reference			reference;
			typedef typename _traits_type::iterator_category	iterator_category;
			typedef T									key_value;
			typedef Node								node_type;
			typedef Node*								node_type_pointer;

		private:
			node_type_pointer	_head;
			node_type_pointer	_end;
		

		public:

			RBTree_iterator(void): _head(), _end(){
			//	this->_head = nullptr;

			}

			RBTree_iterator(node_type_pointer p, node_type_pointer end): _head(p), _end(end){
			//	this->_head = p;
			}

		//	RBTree_iterator(const RBTree_iterator& copy){
			RBTree_iterator(const RBTree_iterator<typename ft::remove_const<value_type>::type > copy): _head(copy.base()){
			//	*this = copy;
			}

			~RBTree_iterator(){};

			RBTree_iterator&	operator=(const RBTree_iterator& it){
				if (&it != this)
				{
					this->_head = it._head;
					this->_end = it._end;
				}
				return (*this);
			}

			node_type_pointer	base(void) const{
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

			RBTree_iterator&	operator++(void){
				node_type_pointer tmp = this->_head;

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

			RBTree_iterator	operator++(int){
				RBTree_iterator	tmp = *this;
				++(*this);
				return (tmp);
			}

			RBTree_iterator&	operator--(void){
				node_type_pointer tmp = this->_head;
				if (tmp == this->_end){
					tmp = tmp->_parent;
					if (tmp == this->_end){
						return (*this);
					}
					while (tmp->_right != nullptr)
						tmp = tmp->_right;
					this->_head = tmp;
					return (*this);
				}
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

			RBTree_iterator	operator--(int){
				RBTree_iterator	tmp = *this;
				--(*this);
				return (tmp);
			}

			RBTree_iterator		operator+(difference_type n){
				while (n-- > 0)
					++(*this);
				return (*this);
			}

			RBTree_iterator		operator-(difference_type n){
				while (n-- > 0)
					--(*this);
				return (*this);
			}

		//	pointer		operator*(const vector_iterator& )
			// friend bool	operator==(const RBTree_iterator& lhs, const RBTree_iterator& rhs)
			// {return (lhs.base() == rhs.base());};

			// template<class Iter1, class Iter2>
			// friend bool	operator!=(const RBTree_iterator& lhs, const RBTree_iterator& rhs)
			// {return (lhs.base() != rhs.base());};
	};

	template<class Iter1, class Iter2>
	bool	operator==(const ft::RBTree_iterator<Iter1>& lhs, const ft::RBTree_iterator<Iter2>& rhs)
	{return (lhs.base() == rhs.base());};

	template<class Iter1, class Iter2>
	bool	operator!=(const ft::RBTree_iterator<Iter1>& lhs, const ft::RBTree_iterator<Iter2>& rhs)
	{return (lhs.base() != rhs.base());};

	// template<class Iter1, class Iter2>
	// bool	operator>(const ft::RBTree_iterator<Iter1>& lhs, const ft::RBTree_iterator<Iter2>& rhs)
	// {return (lhs.base() > rhs.base());};

	// template<class Iter1, class Iter2>
	// bool	operator>=(const ft::RBTree_iterator<Iter1>& lhs, const ft::RBTree_iterator<Iter2>& rhs)
	// {return (lhs.base() >= rhs.base());};

	// template<class Iter1, class Iter2>
	// bool	operator<(const ft::RBTree_iterator<Iter1>& lhs, const ft::RBTree_iterator<Iter2>& rhs)
	// {return (lhs.base() < rhs.base());};

	// template<class Iter1, class Iter2>
	// bool	operator<=(const ft::RBTree_iterator<Iter1>& lhs, const ft::RBTree_iterator<Iter2>& rhs)
	// {return (lhs.base() <= rhs.base());};

//////// RED-BLACK TREE
	template<class T, class Compare = ft::less<T>, class Node = ft::RBTNode<T>, class Allocator = std::allocator<Node> >
	class RBTree{
		public:
			typedef	T			key_type;
			typedef	T*			key_pointer;
			typedef	T&			key_reference;
			typedef	Node		node_type;
			typedef	Node*		node_type_pointer;

			typedef	ft::RBTree_iterator<T, node_type>			iterator;
			typedef	ft::RBTree_iterator<const T, node_type>	const_iterator;

		private:
			node_type_pointer	_root;
			node_type_pointer	_end;
			Compare				_comp;
			Allocator			_alloc;

		public:
			RBTree(const Compare& comp, Allocator alloc = Allocator()): _comp(comp), _alloc(alloc){
				this->_end = _alloc.allocate(1);
				_alloc.construct(this->_end, node_type(key_type(), black, nullptr)); //root /nullptr
				this->_root = this->_end;
				this->_end->_parent = this->_root;
			};
			RBTree(const RBTree& other){
				*this = copy_tree(other);
			};
			~RBTree(void){
				//std::cout << "deleted tree" << std::endl;
				this->clear();
				this->_alloc.destroy(this->_end);
				this->_alloc.deallocate(this->_end, 1);
			};

			RBTree&	operator=(const RBTree& other){
				this->clear();
				this->_alloc.destroy(this->_end);
				this->_alloc.deallocate(this->_end, 1);
				this->_comp = other._comp;
				this->_alloc = other._alloc;
				this->_end = this->_alloc.allocate(1);
				this->_alloc.construct(this->_end, node_type(key_type(), black, nullptr)); //root /nullptr
				this->_root = this->_end;
				if (!other.empty())
					this->copy_tree(&(this->_root), other._root, nullptr);
				this->_end->_parent = this->_root;
				return (*this);
			}

			// void	copy(node_type_pointer* this_cur, node_type_pointer other_cur, node_type_pointer parent){
			// 	this->copy_tree(this_cur, other_cur, parent);
				
			// }

			node_type_pointer	tr_end() const{return (this->_end);}
			node_type_pointer	tr_begin() const{return (this->_root);}

			void	set_end(const node_type_pointer& other){this->_end = other;}
			void	set_begin(const node_type_pointer& other){this->_root = other;}

			void	copy_tree(node_type_pointer* this_cur, node_type_pointer other_cur, node_type_pointer parent){
				if (other_cur == nullptr)
					return ;
				
				*this_cur = this->_alloc.allocate(1);
				this->_alloc.construct(*this_cur, node_type(*other_cur));
				(*this_cur)->_parent = parent;
				
				if ((other_cur)->_left != nullptr){
					this->copy_tree(&((*this_cur)->_left), other_cur->_left, *this_cur);
				}
				if ((other_cur)->_right != nullptr){
					this->copy_tree(&((*this_cur)->_right), other_cur->_right, *this_cur);
				}
			}

			const node_type_pointer	get_root(void){
				return (this->_root);
			}

			void	delete_elems(node_type_pointer tmp){
				if (tmp == this->_end)
					return ;
				if (tmp == nullptr)
					return ;
				delete_elems(tmp->_left);
				delete_elems(tmp->_right);
				this->_alloc.destroy(tmp);
				this->_alloc.deallocate(tmp, 1);
			}

			void	clear(){
				this->delete_elems(this->_root);
				this->_root = this->_end;
				// this->_end->_parent = this->_root; //dont need i guess
			}

		//insert element
			node_type_pointer	insert(T key){
				//std::cout << "inserting: " << key.first << std::endl;
				if (this->_root == this->_end){
					//this->_root = new node_type(key, red);
					this->_root = _alloc.allocate(1);
					_alloc.construct(this->_root, node_type(key, black));
					this->_end->_parent = this->_root;
					// _alloc.construct(this->_end, node_type(T(), black, this->_root));
					return (this->_root);
				}

				node_type_pointer	tmp = this->_root;
				while (tmp){
					// if (key < tmp->_key)
					if (_comp(key, tmp->_key)){
						if (tmp->_left == nullptr){
							tmp->_left = _alloc.allocate(1);
							_alloc.construct(tmp->_left, node_type(key, red, tmp));
							this->insert_fix(tmp->_left);
							this->_end->_parent = this->_root; // maybe was change after fix
							return (tmp->_left);
						}
						else
							tmp = tmp->_left;
					}
					else if (_comp(tmp->_key, key)){//(tmp->_key < key)
						if (tmp->_right == nullptr){
							tmp->_right = _alloc.allocate(1);
							_alloc.construct(tmp->_right, node_type(key, red, tmp));
							this->insert_fix(tmp->_right);
							this->_end->_parent = this->_root; // maybe was change after fix
							return (tmp->_right);
						}
						else
							tmp = tmp->_right;
					}
				}
				return (this->_end);
			};

		//do the balance after insert
			void	insert_fix(node_type_pointer cur){
				// node_type_pointer	parent = cur->_parent;
				// node_type_pointer	uncle = this->get_uncle(cur);

				// if (parent->_color == black){
				// 	return ;
				// }
				// else 

				while (cur != this->_root && cur->_parent->_color == red){
					if (cur->_parent == cur->_parent->_parent->_left){
						node_type_pointer	uncle = cur->_parent->_parent->_right;
						if (uncle != nullptr && uncle->_color == red){
							cur->_parent->_color = black;
							uncle->_color = black;
							cur->_parent->_parent->_color = red;
							cur = cur->_parent->_parent;
						} else {
							if (cur == cur->_parent->_right){
								cur = cur->_parent;
								this->rotate_left(cur);
							}
							cur->_parent->_color = black;
							cur->_parent->_parent->_color = red;
							this->rotate_right(cur->_parent->_parent);
						}
					} else {
						node_type_pointer	uncle = cur->_parent->_parent->_left;
						if (uncle != nullptr && uncle->_color == red){
							cur->_parent->_color = black;
							uncle->_color = black;
							cur->_parent->_parent->_color = red;
							cur = cur->_parent->_parent;
						} else {
							if (cur == cur->_parent->_left){
								cur = cur->_parent;
								this->rotate_right(cur);
							}
							cur->_parent->_color = black;
							cur->_parent->_parent->_color = red;
							this->rotate_left(cur->_parent->_parent);
						}
					}
				}
				this->_root->_color = black;
			}

			node_type_pointer	get_grandf(node_type_pointer cur){
				if (cur != nullptr && cur->_parent != nullptr)
					return (cur->_parent->_parent);
				return (nullptr);
			}

			node_type_pointer	get_uncle(node_type_pointer cur){
				node_type_pointer	grand = this->get_grandf(cur);

				if (grand == nullptr)
					return (nullptr);
				if (grand->_left == cur->_parent)
					return (grand->_right);
				return (grand->_legt);
			}

			void	replace(T key){
				node_type_pointer	tmp = this->_root;

				while (_comp(tmp->_key, key) || _comp(key, tmp->_key)){ //(tmp->_key.first != key.first)
					if (_comp(key, tmp->_key)) //key.first < tmp->_key.first
						tmp = tmp->_left;
					else
						tmp = tmp->_right;
				}
				tmp->_key = key; // tmp->_key.second = key.second;
			}

			node_type_pointer	find_elem(T key){ //const?
				node_type_pointer	tmp = this->_root;
				while (tmp){
					if (_comp(key, tmp->_key)){ //(key.first < tmp->_key.first)
						tmp = tmp->_left;
					}
					else if (_comp(tmp->_key, key)){ //(tmp->_key.first < key.first)
						tmp = tmp->_right;
					}
					else {
						return (tmp);
					}
				}
				return (this->_end);
			}

			bool	check_exist_value(const T key) const{
				node_type_pointer	tmp = this->_root;

				while (tmp != nullptr){
					if (_comp(tmp->_key, key)) // (tmp->_key < key)
						tmp = tmp->_right;
					else if (_comp(key, tmp->_key)) //(key < tmp->_key)
						tmp = tmp->_left;
					else
						return (1);
					// if (key.first == tmp->_key.first) //(key.first == tmp->_key.first)
					// 	return (1);
					// if (key < tmp->_key) //(key < tmp->_key)
					// 	tmp = tmp->_left;
					// else
					// 	tmp = tmp->_right;
				}
				return (0);
			}


	//remove elements
/*
			size_t	remove(node_type_pointer tmp){
				if (this->empty() || tmp == nullptr)
					return (0);

			//if left and right elements of deleted element are NULL
				if (tmp->_left == nullptr && tmp->_right == nullptr){
					if (tmp->_parent != nullptr && tmp->_parent->_left == tmp){
						tmp->_parent->_left = nullptr;
					} else if (tmp->_parent != nullptr && tmp->_parent->_right == tmp){
						tmp->_parent->_right = nullptr;
					} else if (tmp->_parent == nullptr){
						this->_root = this->_end;
					}
					this->_alloc.destroy(tmp);
					this->_alloc.deallocate(tmp, 1);
					return (1);
				}

				ft::RBT_color	color;
				if (tmp->_left == nullptr){
					if (tmp->_parent && tmp->_parent->_left == tmp){
						tmp->_right->_color = color;
						tmp->_parent->_left = tmp->_right;
						
					}
					else if (tmp->_parent && tmp->_parent->_right == tmp){
						tmp->_right->_color = color;
						tmp->_parent->_right = tmp->_right;
					}
					else {
						this->_root = tmp->_right;
						
					}
					
					if (tmp->_right != nullptr)
							tmp->_right->_parent = nullptr;


					this->_alloc.destroy(tmp);
					this->_alloc.deallocate(tmp, 1);
					return (1);
				}
				else if (tmp->_right == nullptr){
					if (tmp->_parent && tmp->_parent->_left == tmp){
						tmp->_left->_color = color;
						tmp->_parent->_left = tmp->_left;
						tmp->_left->_parent = tmp->_parent;
					}
					else if (tmp->_parent && tmp->_parent->_right == tmp){
						tmp->_left->_color = color;
						tmp->_parent->_right = tmp->_left;
						tmp->_left->_parent = tmp->_parent;
					}
					else {
						this->_root = tmp->_left;
						tmp->_left->_parent = nullptr;
					}
					this->_alloc.destroy(tmp);
					this->_alloc.deallocate(tmp, 1);
					return (1);
				}
				else { //both childs are not NULL
					node_type_pointer	repl = tmp->_right;
					while (repl->_left != nullptr)
						repl = repl->_left;
					if (repl->_parent != tmp){
						repl->_parent->_left = repl->_right; //to don't lost right member of min right child
						repl->_right = tmp->_right;
					}
					repl->_left = tmp->_left;

					if (tmp->_left != nullptr)
						tmp->_left->_parent = repl;
					repl->_parent = tmp->_parent;
					

					if (tmp->_parent != nullptr && tmp->_parent->_left == tmp){
						tmp->_parent->_left = repl;
					}
					else if (tmp->_parent != nullptr && tmp->_parent->_right == tmp){
						tmp->_parent->_right = repl;
					}
					else {
						this->_root = repl;
					}
					repl->_color = color;
					this->_alloc.destroy(tmp);
					this->_alloc.deallocate(tmp, 1);
					return (1);
				}

				return (0);
			}
*/
			size_t	remove(node_type_pointer tmp){
				if (this->empty() || tmp == this->_end)
					return (0);

				node_type_pointer	child, parent;
				ft::RBT_color	color;

				if (tmp->_left != nullptr && tmp->_right != nullptr){//both childs are not NULL
					node_type_pointer	repl = tmp->_right;
					while (repl->_left != nullptr)
						repl = repl->_left;
					if (tmp->_parent != nullptr){
						if (tmp->_parent->_left == tmp)
							tmp->_parent->_left = repl;
						else
							tmp->_parent->_right = repl;
					}
					else
						this->_root = repl;
					color = repl->_color;
					parent = repl->_parent;
					child = repl->_right;

					if (parent == tmp){
						parent = repl;
					}
					else {
						if (child != nullptr)
							child->_parent = repl->_parent;
						parent->_left = child;
						repl->_right = tmp->_right;
						tmp->_right->_parent = repl;
					}
					repl->_parent = tmp->_parent;
					repl->_left = tmp->_left;
					tmp->_left->_parent = repl;
					repl->_color = tmp->_color;

					if (color == black && child != nullptr && parent != nullptr){
						remove_fix(child, parent);
					}
					this->_end->_parent = this->_root; // maybe was change after fix
					this->_alloc.destroy(tmp);
					this->_alloc.deallocate(tmp, 1);
					return (1);
				}

				if (tmp->_left != nullptr)
					child = tmp->_left;
				else
					child = tmp->_right;	
				parent = tmp->_parent;
				color = tmp->_color;
				if (child != nullptr)
					child->_parent = parent;
				if (parent != nullptr){
					if (parent->_left == tmp)
						parent->_left = child;
					else
						parent->_right = child;
				}
				else
					this->_root = child;
				if (this->_root == nullptr)
					this->_root = this->_end;
				if (color == black && child != nullptr && parent != nullptr){
					remove_fix(child, parent);
				}
				this->_end->_parent = this->_root; // maybe was change after fix
				this->_alloc.destroy(tmp);
				this->_alloc.deallocate(tmp, 1);
				return (1);	
			}

	//do balance after remove
			void	remove_fix(node_type_pointer child, node_type_pointer parent){
				node_type_pointer	tmp;

				while ((!child) || child->_color == black && child != this->_root){
					if (parent->_left == child){
						tmp = parent->_right;
						if (tmp->_color == red){
							tmp->_color = black;
							parent->_color = red;
							this->rotate_left(parent);
							tmp = parent->_right;
						}
						else {
							if (!(tmp->_right) || tmp->_right->_color == black){
								tmp->_left->_color = black;
								tmp->_color = red;
								this->rotate_right(tmp);
								tmp = parent->_right;
							}
							tmp->_color = parent->_color;
							parent->_color = black;
							tmp->_right->_color = black;
							this->rotate_left(parent);
							child = this->_root;
							break;
						}
					}
					else {
						tmp = parent->_left;
						if (tmp->_color == red){
							tmp->_color = black;
							parent->_color = red;
							this->rotate_right(parent);
							tmp = parent->_left;
						}
						if ((!tmp->_left || tmp->_left->_color == black) && (!tmp->_right || tmp->_right->_color == black)){
							tmp->_color = red;
							child = parent;
							parent = child->_parent;
						}
						else {
							if (!(tmp->_left) || tmp->_left->_color == black){
								tmp->_right->_color = black;
								tmp->_color = red;
								this->rotate_left(tmp);
								tmp = parent->_left;
							}
							tmp->_color = parent->_color;
							parent->_color = black;
							tmp->_left->_color = black;
							this->rotate_right(parent);
							child = this->_root;
							break;
						}
					}
				}
				if (child)
					child->_color = black;
			}

			node_type_pointer	min_elem() const{
				if (this->empty())
					return (this->_end);
				node_type_pointer	tmp = this->_root;
				return (left_go(tmp));
			}

			node_type_pointer	max_elem() const{
				if (this->empty())
					return (this->_end);
				node_type_pointer	tmp = this->_root;
				return (right_go(tmp));
			}

			node_type_pointer	left_go(node_type_pointer	cur) const {
				if (cur->_left != nullptr)
					cur = left_go(cur->_left);
				return (cur);
			}

			node_type_pointer	right_go(node_type_pointer	cur) const {
				if (cur->_right != nullptr)
					cur = right_go(cur->_right);
				return (cur);
			}

			node_type_pointer	pre_elem(const T key) const {
				node_type_pointer tmp = this->find_elem(key);
				if (tmp == this->min_elem())
					return (nullptr);
				if (tmp->_left == nullptr && tmp->_parent == nullptr)
					return (nullptr);
				else if ((tmp->_left == nullptr) && (tmp->_parent != nullptr)){
					if (tmp == tmp->_parent->_left){
						return (tmp->_parent->_parent);
					}
					else {
						return (tmp->_parent);
					}
				} else if ((tmp->_left != nullptr)){
					tmp = tmp->_left;
					return (this->right_go(tmp));
				}
				return (nullptr);
			}

			node_type_pointer	post_elem(const T key) const{
				node_type_pointer tmp = this->find_elem(key);
				if (tmp == this->max_elem())
					return (nullptr);
				if (tmp->_right == nullptr && tmp->_parent == nullptr)
					return (nullptr);
				else if ((tmp->_right == nullptr) && (tmp->_parent != nullptr)){
					if (tmp == tmp->_parent->_right){
						tmp = tmp->_parent;
					}
					else {
						return (tmp->_parent);
					}
				} else if ((tmp->_right != nullptr)){
					tmp = tmp->_right;
					return (this->left_go(tmp));
				}
				return (nullptr);
			}

			void	print_tree(node_type_pointer tmp, size_t n){
				if (tmp == nullptr)
					return ;
			//	std::cout << "here " << tmp->_key.second << std::endl;

				int	m = n;
				print_tree(tmp->_right, n + 3);
				while (m-- > 0)
					std::cout << "|";
				if (tmp->_color == black)
					std::cout << BLACK_COLOR;
				else
					std::cout << RED_COLOR;
				if (tmp->_parent == nullptr)
					std::cout << "!";
				std::cout << tmp->_key.second << RESET_COLOR << std::endl;
				print_tree(tmp->_left, n + 3);
			}

			bool	empty(void) const{
				return (this->_root == this->_end);
			}

			size_t	size() const{
				if (this->empty())
					return (0);
				return (this->size(this->_root));
			}

			size_t	size(node_type_pointer	tmp) const{
				size_t	left = 0, right = 0;
				if (tmp->_left != nullptr)
					left = size(tmp->_left);
				if (tmp->_right != nullptr)
					right = size(tmp->_right);
				return (left + right + 1);
			}

			T	pre_value(const T& key) const{
				node_type_pointer	res = this->pre_elem(key);

				if (res)
					return (res->_key);
				else
					return (key);
			}

			T	post_value(const T& key) const{
				node_type_pointer	res = this->post_elem(key);

				if (res)
					return (res->_key);
				else
					return (key);
			}

		//rotate
			void	rotate_left(node_type_pointer n){
				node_type_pointer	tmp = n->_right;

				//std::cout << "left_rotate: " << n->_key.second << std::endl;

				tmp->_parent = n->_parent;
				if (n->_parent != nullptr){
					if (n == n->_parent->_left){
						tmp->_parent->_left = tmp;
					} else {
						tmp->_parent->_right = tmp;
					}
				} else {
					this->_root = tmp;
				}

				n->_right = tmp->_left;
				if (tmp->_left != nullptr)
					tmp->_left->_parent = n;
				
				n->_parent = tmp;
				tmp->_left = n;
			};

			void	rotate_right(node_type_pointer n){
				node_type_pointer	tmp = n->_left;

				//std::cout << "right_rotate: " << n->_key.second << std::endl;
				tmp->_parent = n->_parent;
				if (n->_parent != nullptr){
					if (n == n->_parent->_left){
						tmp->_parent->_left = tmp;
					} else {
						tmp->_parent->_right = tmp;
					}
				} else {
					this->_root = tmp;
				}

				n->_left = tmp->_right;
				if (tmp->_right != nullptr)
					tmp->_right->_parent = n;
				
				n->_parent = tmp;
				tmp->_right = n;
			};
	};







}



#endif