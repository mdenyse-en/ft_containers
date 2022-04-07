#include "../includes/Vector.hpp"


//constractors
// ft::Vector::Vector(void): _start_cont(nullptr), _end_cont(nullptr), _end_el(nullptr)
// {
// }
ft::Vector::Vector(const Alloc& alloc = Alloc()):
	_alloc_type(alloc), _start_cont(nullptr), _end_cont(nullptr), _end_el(nullptr)
{}

ft::Vector::Vector(size_t count, const T& value = T(), const Alloc& alloc = Alloc()):
	_alloc_type(alloc), _start_cont(nullptr), _end_cont(nullptr), _end_el(nullptr)
{
	this->_start_cont = this->_alloc_type.allocate(count);
	this->_end_el = this->_start_cont + count;
	this->_end_cont = this->_start_cont;
	while (count--)
	{
		this->_alloc_type.counstruct(_end++, val);
	}
}

ft::Vector::Vector(); //some with iterators
//ft::Vector::Vector(size_t count); already exist erlier

ft::Vector::Vector(const Vector& other):
	_alloc_type(other._alloc_type), _start_cont(nullptr), _end_cont(nullptr), _end_el(nullptr)
{
	this->insert(this->begin(), other.begin(), other.end());
}

ft::Vector::~Vector(void)
{
	this->clear();
	this->_alloc.deallocate(_start_cont, this->capacity());
}

//iterators:
iterator begin(void){
	return (this->_start_cont);
}
const_iterator begin(void) const{
	return (this->_start_cont);
}
iterator end(void){
	if (this->empty())
		return (this->_start_cont);
	return (this->_end_el);
}
const_iterator end(void) const{
	if (this->empty())
		return (this->_start_cont);
	return (this->_end_el);
}
/*reverse_iterator rbegin(void){
	if (this->empty())
		return (this->_start_cont);
	return (this->_end_el);
}
const_reverse_iterator rbegin(void) const{
	if (this->empty())
		return (this->_start_cont);
	return (this->_end_el);
}
reverse_iterator rend(void){
	return (this->_start_cont);
}
const_reverse_iterator rend(void) const{
	return (this->_start_cont);
}*/

//capasity
bool	ft::Vector::empty(void){
	return (this->_start_cont == nullptr);
}
size_t	ft::Vector::size(void){
	if (this->_start_cont == nullptr)
		return (0);
	return (this->_end_el - this->_start_cont + 1);
}
size_t	ft::Vector::max_size(void){
	return (this->_alloc_type().max_size());
}
void	ft::Vector::reserve(size_t new_cap){

}
size_t	ft::Vector::capacity(void){
	if (this->size() == 0)
		return (this->size());
	else
		return (this->_end_cont - this->_end_el);
}