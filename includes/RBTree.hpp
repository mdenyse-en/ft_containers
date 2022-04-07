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

	template<class T, class Compare = ft::less<T>, class Node = ft::RBTNode<T>, class Allocator = std::allocator<Node> >
	class RBTree{
		public:
			typedef	T			key_type;
			typedef	T*			key_pointer;
			typedef	T&			key_reference;
			typedef	RBTNode<T>	node_type;
			typedef	RBTNode<T>*	node_type_pointer;

		public:
			node_type_pointer	_root;
			node_type_pointer	_end;
			Compare				_comp;
			Allocator			_alloc;

		public:
			RBTree(Compare comp = Compare(), Allocator alloc = Allocator()): _comp(comp), _alloc(alloc){
				this->_end = _alloc.allocate(1);
				_alloc.construct(this->_end, node_type(key_type(), black, nullptr));
				this->_root = this->_end;
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
				this->_alloc.construct(this->_end, node_type(key_type(), black, nullptr));
				this->_root = this->_end;
				if (!other.empty())
					this->copy_tree(&(this->_root), other._root, nullptr);

				return (*this);
			}

			void	copy_tree(node_type_pointer* this_cur, node_type_pointer other_cur, node_type_pointer parent){
				if (other_cur == nullptr)
					return ;
				
				*this_cur = this->_alloc.allocate(1);
				this->_alloc.construct(*this_cur, node_type(*other_cur));
				(*this_cur)->_parent = parent;
				

				//std::cout << "_____" << (*this_cur)->_key.second << std::endl;

				//*this_cur->_parent = parent;

				// if (parent != nullptr){
				// 	if (parent->_key < this_cur._key)
				// 		parent->_left = this_cur;
				// 	else
				// 		parent->_right = this_cur;
				// }
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
			}

			node_type_pointer	insert(T key){
				if (this->_root == this->_end){
					//this->_root = new node_type(key, red);
					this->_root = _alloc.allocate(1);
					_alloc.construct(this->_root, node_type(key, red));
					this->_end->_parent = this->_root;
					// _alloc.construct(this->_end, node_type(T(), black, this->_root));
					return (this->_root);
				}

				node_type_pointer	tmp = this->_root;
				while (tmp){
					if (key < tmp->_key){
						if (tmp->_left == nullptr){
							tmp->_left = _alloc.allocate(1);
							_alloc.construct(tmp->_left, node_type(key, red, tmp));
							return (tmp->_left);
						}
						else
							tmp = tmp->_left;
					}
					else if (tmp->_key < key){
						if (tmp->_right == nullptr){
							tmp->_right = _alloc.allocate(1);
							_alloc.construct(tmp->_right, node_type(key, red, tmp));
							return (tmp->_right);
						}
						else
							tmp = tmp->_right;
					}
				}
				return (this->_end);
			};

			void	replace(T key){
				node_type_pointer	tmp = this->_root;

				while (tmp->_key.first != key.first){
					if (key.first < tmp->_key.first)
						tmp = tmp->_left;
					else
						tmp = tmp->_right;
				}
				tmp->_key.second = key.second;
			}

			node_type_pointer	find_elem(const T key) const{
				node_type_pointer	tmp = this->_root;
				while (tmp){
					if (key.first < tmp->_key.first){
						tmp = tmp->_left;
					}
					else if (tmp->_key.first < key.first){
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
					if (key.first == tmp->_key.first)
						return (1);
					if (key < tmp->_key)
						tmp = tmp->_left;
					else
						tmp = tmp->_right;
				}
				return (0);
			}

			size_t	remove(T key){
				if (this->empty())
					return (0);
				node_type_pointer	tmp = find_elem(key);
				if (tmp == this->_root){
					this->_alloc.destroy(tmp);
					this->_alloc.deallocate(tmp, 1);
					this->_root = this->_end;
					//this->_end->_parent = nullptr;
					return (1);
				}

				if (tmp->_left == nullptr && tmp->_right == nullptr){
					if (tmp->_parent && tmp->_parent->_left == tmp){
						tmp->_parent->_left = nullptr;
						this->_alloc.destroy(tmp);
						this->_alloc.deallocate(tmp, 1);
						return (1);
					}
					else if (tmp->_parent && tmp->_parent->_right == tmp){
						tmp->_parent->_right = nullptr;
						this->_alloc.destroy(tmp);
						this->_alloc.deallocate(tmp, 1);
						return (1);
					}
				}

				// if (tmp->left == nullptr && tmp == tmp->_parent->_right){
				// 	tmp->_parent->_right = 
				// }

				return (0);
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

	};

}

#endif