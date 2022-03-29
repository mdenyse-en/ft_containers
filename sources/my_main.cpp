#include <iostream>
#include <string>
#include <deque>
//#if 1 //CREATE A MY EXAMPLE
//	#include <map.hpp>
	// #include <stack.hpp>
	// #include <vector.hpp>
	// namespace std = ft;
//#else
	#include <map>
	#include <stack>
	#include <vector>
//	namespace ft = std;
//#endif

#include "../includes/stack.hpp"
#include "../includes/vector.hpp"
#include <stdlib.h>

#define STD_PR_COLOR "\x1b[32m"
#define FT_PR_COLOR "\x1b[34m"
#define RESET_COLOR "\x1b[0m"
#define L_CELLS "--------------------"
#define R_CELLS "--------------------"


//template<class T>
void	print_vectors(std::vector<int>& std_v, ft::vector<int>& ft_v){
	std::cout << STD_PR_COLOR << "STD vector: ";

	int i = 0;
	std::vector<int>::iterator	std_it;
	for (std_it = std_v.begin(); std_it != std_v.end(); std_it++){
		std::cout << "[" << i++ << "]=" << *std_it << " ";
	}
	std::cout << std::endl;
	std::cout << FT_PR_COLOR << " FT vector: ";

	i = 0;
	ft::vector<int>::iterator		ft_it;
	for (ft_it = ft_v.begin(); ft_it != ft_v.end(); ft_it++){
		std::cout << "[" << i++ << "]=" << *ft_it <<" ";
	}
	std::cout << std::endl;
}

int	main(int argc, char** argv){

////////////////// STACK /////////////////////////
	{
	std::cout << RESET_COLOR << "\n" << L_CELLS << " STACK " << R_CELLS << std::endl;

	std::stack<int, std::vector<int> >	stack_int_std;
	ft::stack<int>	stack_int_ft;
	stack_int_std.push(5);
	stack_int_std.push(6);
	stack_int_std.push(7);
	
	stack_int_ft.push(5);
	stack_int_ft.push(6);
	stack_int_ft.push(7);

	std::cout << STD_PR_COLOR << "STD Stack size: " << stack_int_std.size() << std::endl;
	std::cout << FT_PR_COLOR << " FT Stack size: " << stack_int_ft.size() << std::endl;

	std::cout << STD_PR_COLOR << "STD Stack top element: " << stack_int_std.top() << std::endl;
	std::cout << FT_PR_COLOR << " FT Stack top element: " << stack_int_ft.top() << std::endl;

	std::cout << STD_PR_COLOR << "STD Stack empty?: " << stack_int_std.empty() << std::endl;
	std::cout << FT_PR_COLOR << " FT Stack empty?: " << stack_int_ft.empty() << std::endl;

	//created a copy of stacks:
	std::stack<int, std::vector<int> >	stack_int_std_cp(stack_int_std);
	ft::stack<int>	stack_int_ft_cp(stack_int_ft);

	// std::stack<int> stack_int_std_cp = stack_int_std;
	// ft::stack<int>	stack_int_ft_cp = stack_int_ft;

	std::cout << STD_PR_COLOR << "STD Stack copy size: " << stack_int_std_cp.size() << std::endl;
	std::cout << FT_PR_COLOR << " FT Stack copy size: " << stack_int_ft_cp.size() << std::endl;

	std::cout << STD_PR_COLOR << "STD Stack copy top element: " << stack_int_std_cp.top() << std::endl;
	std::cout << FT_PR_COLOR << " FT Stack copy top element: " << stack_int_ft_cp.top() << std::endl;

	std::cout << STD_PR_COLOR << "STD Stack copy empty?: " << stack_int_std_cp.empty() << std::endl;
	std::cout << FT_PR_COLOR << " FT Stack copy empty?: " << stack_int_ft_cp.empty() << std::endl;

	std::cout << STD_PR_COLOR << "STD Stack copy ==  STD Stack?: " << (stack_int_std_cp == stack_int_std) << std::endl;
	std::cout << FT_PR_COLOR << " FT Stack copy ==  FT Stack?: " << (stack_int_ft_cp == stack_int_ft) << std::endl;

	stack_int_std.pop();
	stack_int_std.pop();
	stack_int_ft.pop();
	stack_int_ft.pop();

	std::cout << STD_PR_COLOR << "STD Stack size: " << stack_int_std.size() << std::endl;
	std::cout << FT_PR_COLOR << " FT Stack size: " << stack_int_ft.size() << std::endl;

	std::cout << STD_PR_COLOR << "STD Stack empty?: " << stack_int_std.empty() << std::endl;
	std::cout << FT_PR_COLOR << " FT Stack empty?: " << stack_int_ft.empty() << std::endl;

	std::cout << STD_PR_COLOR << "STD Stack copy size: " << stack_int_std_cp.size() << std::endl;
	std::cout << FT_PR_COLOR << " FT Stack copy size: " << stack_int_ft_cp.size() << std::endl;

	// for (int i = 0; i < 10; i++)
	// {
	// 	stack_int_std.push(i + 100);
	// 		std::cout << "size: " << stack_int_std.top() << std::endl;
		
	// }

	}

////////////////// VECTOR ////////////////////////
	std::cout << RESET_COLOR << "\n" << L_CELLS << " VECTOR " << R_CELLS << std::endl;

	std::vector<int>	vector_int_std(10, 2);
	ft::vector<int>		vector_int_ft(10, 2);

	std::cout << STD_PR_COLOR << "STD Vector size: " << vector_int_std.size() << ", capacity: " << vector_int_std.capacity() << std::endl;
	std::cout <<  FT_PR_COLOR << " FT Vector size: " << vector_int_ft.size() << ", capacity: " << vector_int_ft.capacity() << std::endl;

	print_vectors(vector_int_std, vector_int_ft);

	int	n_res = 15;
	vector_int_std.reserve(n_res);
	vector_int_ft.reserve(n_res);

	std::cout << STD_PR_COLOR << "STD Vector after RESERVE(" << n_res << ") size: " << vector_int_std.size() << ", capacity: " << vector_int_std.capacity() << std::endl;
	std::cout << FT_PR_COLOR << " FT Vector after RESERVE(" << n_res << ") size: " << vector_int_ft.size() << ", capacity: " << vector_int_ft.capacity() << std::endl;

	print_vectors(vector_int_std, vector_int_ft);
//	ft::vector<long int>	b[50];

//	vector_int_ft[9] = 55;


	// int	size = vector_int_std.capacity();
	// for (int i = 0; i < 5; i++)
	// {
	// //	vec_int_std.push_back(i);
	// 	//if (size != vec_int_std.capacity())
	// 	{
	// 		size = vector_int_std.capacity();
	// 		std::cout << "size: " << vector_int_ft[48] << " capacity: " << vector_int_ft.size() << std::endl;
	// 	}
	// }

	vector_int_std.clear();
	vector_int_ft.clear();

	std::cout << STD_PR_COLOR << "STD Vector size: " << vector_int_std.size() << ", Forth element: " << vector_int_std[4] << std::endl;
	std::cout << FT_PR_COLOR << " FT Vector size: " << vector_int_ft.size() << ", Forth element: " << vector_int_ft[4] << std::endl;

	print_vectors(vector_int_std, vector_int_ft);

	std::cout << STD_PR_COLOR << "STD Vector [8] element: " << vector_int_std[8] << std::endl;
	std::cout << FT_PR_COLOR << " FT Vector [8] element: " << vector_int_ft[8] << std::endl;

	try {
		vector_int_std.at(102);
	} catch (const std::exception& ex){
		std::cout << STD_PR_COLOR << ex.what() << std::endl;
	}
	try {
		vector_int_ft.at(102);
	} catch (const std::exception& ex){
		std::cout << FT_PR_COLOR << ex.what() << std::endl;
	}

	std::cout << STD_PR_COLOR << "STD Vector size: " << vector_int_std.size() << ", First element: " << vector_int_std.front() << std::endl;
	std::cout << FT_PR_COLOR << " FT Vector size: " << vector_int_ft.size() << ", First element: " << vector_int_ft.front() << std::endl;

	std::cout << STD_PR_COLOR << "STD Vector last element: " << vector_int_std.back() << std::endl;
	std::cout << FT_PR_COLOR << " FT Vector last element: " << vector_int_ft.back() << std::endl;

	std::cout << STD_PR_COLOR << "STD Vector 2 element from data access: " << vector_int_std.data()[1] << std::endl;
	std::cout << FT_PR_COLOR << " FT Vector 2 element from data access: " << vector_int_ft.data()[1] << std::endl;

	std::vector<int>	vector_int_std_temp(10, 9);
	ft::vector<int>		vector_int_ft_temp(10, 6);

	std::cout << STD_PR_COLOR << "STD Vector before = operation capacity: " << vector_int_std.capacity() << std::endl;
	std::cout << FT_PR_COLOR << " FT Vector before = operation capacity: " << vector_int_ft.capacity() << std::endl;


//	vector_int_std_temp.push_back(8);
//	vector_int_std_temp.push_back(8);
	vector_int_std = vector_int_std_temp;

//	vector_int_ft_temp.push_back(8);
//	vector_int_ft_temp.push_back(8);
	vector_int_ft = vector_int_ft_temp;

//	std::cout << vector_int_std.data() << std::endl;

//	std::cout << vector_int_std.data() << std::endl;

//	vector_int_ft_temp.reserve(50);

	std::cout << STD_PR_COLOR << "STD Vector after = and add elems operation capacity, size: " << vector_int_std.capacity() << ", " << vector_int_std.size() << " STD Vector TEMP capacity, size: " << vector_int_std_temp.capacity() << ", " << vector_int_std_temp.size() << std::endl;
	std::cout << FT_PR_COLOR << " FT Vector after = and add elems operation capacity, size: " << vector_int_ft.capacity() << ", " << vector_int_ft.size() << "  FT Vector TEMP capacity, size: " << vector_int_ft_temp.capacity() << ", " << vector_int_ft_temp.size() << std::endl;

	print_vectors(vector_int_std, vector_int_ft);//change to not temp

	std::vector<int>	vector_int_std_temp2(15, 8);
	ft::vector<int>		vector_int_ft_temp2(15, 7);
	int	n_insert = 5;

//	vector_int_ft_temp.reserve(40);
	vector_int_std.insert(vector_int_std.begin() + n_insert, vector_int_std_temp2.begin(), vector_int_std_temp2.end());
	vector_int_ft.insert(vector_int_ft.begin() + n_insert, vector_int_ft_temp2.begin(), vector_int_ft_temp2.end());

	std::cout << STD_PR_COLOR << "STD Vector after INSERT ITERATORS from " << n_insert << " el capacity, size: " << vector_int_std.capacity() << ", " << vector_int_std.size() << std::endl;
	std::cout << FT_PR_COLOR << " FT Vector after INSERT ITERATORS from " << n_insert << " el capacity, size: " << vector_int_ft.capacity() << ", " << vector_int_ft.size() << std::endl;

	print_vectors(vector_int_std, vector_int_ft);

	int	val = 12;
	vector_int_std.insert(vector_int_std.begin() + 3, 5, 12);
	vector_int_ft.insert(vector_int_ft.begin() + 3, 5, 12);
//	vector_int_std.resize(60);
//	vector_int_ft_temp.reserve(60);
//	vector_int_ft_temp.resize(40, 13);

	std::cout << STD_PR_COLOR << "STD Vector after INSERT VALUE from " << n_insert << " el capacity, size: " << vector_int_std.capacity() << ", " << vector_int_std.size() << std::endl;
	std::cout << FT_PR_COLOR << " FT Vector after INSERT VALUE from " << n_insert << " el capacity, size: " << vector_int_ft.capacity() << ", " << vector_int_ft.size() << std::endl;


//	print_vectors(vector_int_std, vector_int_ft_temp);

	int	n_resize = 40;
	vector_int_std.resize(n_resize);
	vector_int_ft.resize(n_resize);

	std::cout << STD_PR_COLOR << "STD Vector after RESIZE (" << n_resize << "). capacity, size: " << vector_int_std.capacity() << ", " << vector_int_std.size() << std::endl;
	std::cout << FT_PR_COLOR << " FT Vector after RESIZE (" << n_resize << "). capacity, size: " << vector_int_ft.capacity() << ", " << vector_int_ft.size() << std::endl;
	print_vectors(vector_int_std, vector_int_ft);

	std::vector<int>	vector_int_std2;// = { 1, 2, 3, 4, 5, 6 };
	//std::vector<int>	vector_int_std3{ 1, 2, 3, 4, 5, 6 };
	ft::vector<int>		vector_int_ft2(5, 1);

	vector_int_std2.push_back(1);
	vector_int_std2.push_back(2);
	vector_int_std2.push_back(3);
	vector_int_std2.push_back(4);
	vector_int_std2.push_back(5);

	// vector_int_ft2.push_back(1);
	// vector_int_ft2.push_back(2);
	// vector_int_ft2.push_back(3);
	// vector_int_ft2.push_back(4);
	// vector_int_ft2.push_back(5);
	vector_int_ft2[1] = 2;
	vector_int_ft2[2] = 3;
	vector_int_ft2[3] = 4;
	vector_int_ft2[4] = 5;
	vector_int_ft2.reserve(8);


//	vector_int_std.erase(vector_int_std2.end() - 1);

	int	n_erase = 2;

	std::vector<int>::iterator	it_std_erase = vector_int_std2.erase(vector_int_std2.begin() + n_erase);//, vector_int_std2.begin() + 2);
	ft::vector<int>::iterator	it_ft_erase = vector_int_ft2.erase(vector_int_ft2.begin() + n_erase);//, vector_int_ft2.begin() + 2);

	std::cout << STD_PR_COLOR << "STD2 Vector after ERASE (" << n_erase << ") element. capacity, size: " << vector_int_std2.capacity() << ", " << vector_int_std2.size() << std::endl;
	std::cout << FT_PR_COLOR << " FT2 Vector after ERASE (" << n_erase << ") element. capacity, size: " << vector_int_ft2.capacity() << ", " << vector_int_ft2.size() << std::endl;
	print_vectors(vector_int_std2, vector_int_ft2);

	std::cout << STD_PR_COLOR << "STD Vector ITERATOR after ERASE: " << *it_std_erase << std::endl;
	std::cout << FT_PR_COLOR <<  " FT Vector ITERATOR after ERASE: " << *it_ft_erase << std::endl;


	vector_int_std.erase(vector_int_std.end() - 1);
	vector_int_ft.erase(vector_int_ft.end() - 1);

	std::cout << STD_PR_COLOR << "STD Vector after ERASE (" << n_resize << "). capacity, size: " << vector_int_std.capacity() << ", " << vector_int_std.size() << std::endl;
	std::cout << FT_PR_COLOR << " FT Vector after ERASE (" << n_resize << "). capacity, size: " << vector_int_ft.capacity() << ", " << vector_int_ft.size() << std::endl;
	print_vectors(vector_int_std, vector_int_ft);

//
	// vector_int_std_temp.reserve(50);
	// vector_int_std_temp = vector_int_std;

	// std::cout << STD_PR_COLOR << "STD Vector TEMP = STD vector capacity, size: " << vector_int_std_temp.capacity() << ", " << vector_int_std_temp.size() << std::endl;
	// std::cout << FT_PR_COLOR << " FT Vector after INSERT from " << n_insert << " el capacity, size: " << vector_int_ft.capacity() << ", " << vector_int_ft.size() << std::endl;


	std::vector<int>::iterator	it_std = vector_int_std.begin();
	std::vector<int>::iterator	it_std2 = vector_int_std.begin();

	ft::vector<int>::iterator	it_ft = vector_int_ft.begin();
	ft::vector<int>::iterator	it_ft2 = vector_int_ft.begin();

	//std::cout << "sodfsf " << (&(*it_std) - &(*it_std2)) << std::endl;

	std::cout << STD_PR_COLOR << "STD Vector::iterator BEGIN and BEGIN == : " << (it_std == it_std2) << std::endl;
	std::cout << FT_PR_COLOR << " FT Vector::iterator BEGIN and BEGIN == : " << (it_ft == it_ft2) << std::endl;

	std::vector<int>::reverse_iterator	it_std3 = vector_int_std.rend();
	ft::vector<int>::reverse_iterator	it_ft3 = vector_int_ft.rend();

	std::vector<int>::reverse_iterator	it_std4 = vector_int_std.rend();
	ft::vector<int>::reverse_iterator	it_ft4 = vector_int_ft.rend();
	std::cout << STD_PR_COLOR << "STD Vector::iterator REND and REND compare == : " << (it_std4 == it_std3) << std::endl;
	std::cout <<  FT_PR_COLOR << " FT Vector::iterator REND and REND compare == : " << (it_ft4 == it_ft3) << std::endl;


	std::cout << STD_PR_COLOR << "STD Vector::iterator REND and REND compare == : " << (it_std4 == it_std3) << std::endl;
	std::cout <<  FT_PR_COLOR << " FT Vector::iterator REND and REND compare == : " << (it_ft4 == it_ft3) << std::endl;
//


	vector_int_std = vector_int_std2;
	vector_int_ft = vector_int_ft2;

	std::cout << STD_PR_COLOR << "STD Vector after = operation capacity, size: " << vector_int_std.capacity() << ", " << vector_int_std.size() << std::endl;
	std::cout << FT_PR_COLOR << " FT Vector after = operation capacity, size: " << vector_int_ft.capacity() << ", " << vector_int_std.size() << std::endl;

	print_vectors(vector_int_std, vector_int_ft);
	

	std::cout << STD_PR_COLOR << "STD Vector max_size(): " << vector_int_std.max_size() << std::endl;
	std::cout <<  FT_PR_COLOR << " FT Vector max_size(): " << vector_int_ft.max_size() << std::endl;
	try {
		vector_int_std.reserve(4611686018427387904);
	} catch (const std::exception& ex){
		std::cout << STD_PR_COLOR << ex.what() << std::endl;
	}
	try {
		vector_int_ft.reserve(4611686018427387904);
	} catch (const std::exception& ex){
		std::cout << FT_PR_COLOR << ex.what() << std::endl;
	}

	std::vector<int>	vector_int_std_sw1, vector_int_std_sw2;// = { 1, 2, 3, 4, 5, 6 };
	ft::vector<int>		vector_int_ft_sw1(3, 1), vector_int_ft_sw2(2, 4);

	vector_int_std_sw1.push_back(1);
	vector_int_std_sw1.push_back(2);
	vector_int_std_sw1.push_back(3);

	vector_int_std_sw2.push_back(4);
	vector_int_std_sw2.push_back(5);

	// vector_int_ft2.push_back(1);
	// vector_int_ft2.push_back(2);
	// vector_int_ft2.push_back(3);
	// vector_int_ft2.push_back(4);
	// vector_int_ft2.push_back(5);
	vector_int_ft_sw1[1] = 2;
	vector_int_ft_sw1[2] = 3;

	vector_int_ft_sw2[1] = 5;


	std::vector<int>::iterator	it_std_swap1 = vector_int_std_sw1.begin() + 1;
	std::vector<int>::iterator	it_std_swap2 = vector_int_std_sw2.begin() + 1;

	ft::vector<int>::iterator	it_ft_swap1 = vector_int_ft_sw1.begin() + 1;
	ft::vector<int>::iterator	it_ft_swap2 = vector_int_ft_sw2.begin() + 1;

	int&	ref_std_sw1 = vector_int_std_sw1.front();
	int&	ref_std_sw2 = vector_int_std_sw2.front();

	int&	ref_ft_sw1 = vector_int_ft_sw1.front();
	int&	ref_ft_sw2 = vector_int_ft_sw2.front();


	std::cout << STD_PR_COLOR << "STD Vector before swap begin() + 1 ; ref to 1 elem: " << *it_std_swap1 << " " << *it_std_swap2 << "; " << ref_std_sw1 << " " << ref_std_sw2 << std::endl;
	std::cout <<  FT_PR_COLOR << " FT Vector before swap begin() + 1 ; ref to 1 elem: " << *it_ft_swap1 << " " << *it_ft_swap2 << "; " << ref_ft_sw1 << " " << ref_ft_sw2 << std::endl;

	print_vectors(vector_int_std_sw1, vector_int_ft_sw1);
	print_vectors(vector_int_std_sw2, vector_int_ft_sw2);


	vector_int_std_sw1.swap(vector_int_std_sw2);
	vector_int_ft_sw1.swap(vector_int_ft_sw2);


	std::cout << STD_PR_COLOR << "STD Vector before swap begin() + 1 ; ref to 1 elem: " << *it_std_swap1 << " " << *it_std_swap2 << "; " << ref_std_sw1 << " " << ref_std_sw2 << std::endl;
	std::cout <<  FT_PR_COLOR << " FT Vector before swap begin() + 1 ; ref to 1 elem: " << *it_ft_swap1 << " " << *it_ft_swap2 << "; " << ref_ft_sw1 << " " << ref_ft_sw2 << std::endl;

	print_vectors(vector_int_std_sw1, vector_int_ft_sw1);
	print_vectors(vector_int_std_sw2, vector_int_ft_sw2);
	// std::cout <<  FT_PR_COLOR << " FT Vector capacity, size(): " << vector_int_ft.capacity() << " ," << vector_int_ft.size() << std::endl;
	// std::cout <<  FT_PR_COLOR << " FT Vector TEMP capacity, size(): " << vector_int_ft_temp.capacity() << " ," << vector_int_ft_temp.size() << std::endl;
	// std::cout <<  FT_PR_COLOR << " FT Vector TEMP2 capacity, size(): " << vector_int_ft_temp2.capacity() << " ," << vector_int_ft_temp2.size() << std::endl;

	std::vector<int>	try_some_std(5,7);
	std::vector<int>	try_some_std2;

	ft::vector<int>	try_some(5,7);
	ft::vector<int>	try_some2;

	try_some_std.assign(11, 2);
	try_some_std2 = try_some_std;
	try_some_std.assign(13, 5);

	try_some.assign(11, 2);
	try_some2 = try_some;
	try_some.assign(13, 5);

	std::cout << STD_PR_COLOR << "STD Vector create by count: " << try_some_std.capacity() << ", " << try_some_std.size() << std::endl;
	std::cout <<  FT_PR_COLOR << " FT Vector create by count: " << try_some.capacity() << ", " << try_some.size() << std::endl;

	std::cout << "some2" << std::endl;
	print_vectors(try_some_std2, try_some2);
	std::cout << "some" << std::endl;
	print_vectors(try_some_std, try_some);


	try_some_std.assign(try_some_std2.begin(), try_some_std2.end());
	try_some.assign(try_some2.begin(), try_some2.end());
	print_vectors(try_some_std, try_some);

	std::cout << STD_PR_COLOR << "STD Vector compare: " << (try_some_std > try_some_std2) << std::endl;
	std::cout <<  FT_PR_COLOR << " FT Vector compare: " << (try_some > try_some2) << std::endl;

	std::cout << STD_PR_COLOR << "STD Vector create by count: " << try_some_std.capacity() << ", " << try_some_std.size() << std::endl;
	std::cout <<  FT_PR_COLOR << " FT Vector create by count: " << try_some.capacity() << ", " << try_some.size() << std::endl;


	try_some_std.push_back(77);
	try_some.push_back(77);
	try_some_std.push_back(88);
	try_some.push_back(88);
	try_some_std.push_back(99);
	try_some.push_back(99);

	std::cout << STD_PR_COLOR << "STD Vector create by count: " << try_some_std.capacity() << ", " << try_some_std.size() << std::endl;
	std::cout <<  FT_PR_COLOR << " FT Vector create by count: " << try_some.capacity() << ", " << try_some.size() << std::endl;
	print_vectors(try_some_std, try_some);


	std::vector<int>	vec_std(11,5);
	ft::vector<int>		vec_ft(11,5);

	std::cout << STD_PR_COLOR << "STD Vector create by count: " << vec_std.capacity() << ", " << vec_std.size() << std::endl;
	std::cout <<  FT_PR_COLOR << " FT Vector create by count: " << vec_ft.capacity() << ", " << vec_ft.size() << std::endl;

	// vec_std.assign(10,5);
	// vec_ft.assign(10,5);

	vec_std = try_some_std;
	vec_ft = try_some;

	std::cout << STD_PR_COLOR << "STD Vector create by count: " << vec_std.capacity() << ", " << vec_std.size() << std::endl;
	std::cout <<  FT_PR_COLOR << " FT Vector create by count: " << vec_ft.capacity() << ", " << vec_ft.size() << std::endl;

	vec_std.pop_back();
	vec_ft.pop_back();

	std::cout << STD_PR_COLOR << "STD Vector create by count: " << vec_std.capacity() << ", " << vec_std.size() << std::endl;
	std::cout <<  FT_PR_COLOR << " FT Vector create by count: " << vec_ft.capacity() << ", " << vec_ft.size() << std::endl;


	std::cout << sizeof(int) << std::endl;

	//while(1);
}