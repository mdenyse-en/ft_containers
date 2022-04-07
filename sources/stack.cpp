#include "../includes/stack.hpp"

stack::stack(const container_type& cont = Container()): _c(cont){}
stack::stack(const stack& other);
stack::~stack();

stack&	ft::stack::operator=(const stack& other) {_c = other._c;}

//element access
T&			ft::stack::top(void) {return (_c.back());}
const T&	ft::stack::top(void) const {return (_c.back());}

//capacity
bool	ft::stack::empty(void) const {return (_c.empty());}
size_t	ft::stack::size(void) const {return (_c.size());}

//modifiers
void	ft::stack::push(const value_type& value) {_c.push_back(value);}
void	ft::stack::pop(void) {_c.pop_back();}