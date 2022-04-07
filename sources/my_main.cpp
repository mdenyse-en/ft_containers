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
#include "../includes/map.hpp"
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

void	print_maps(std::map<int, int> map_std, ft::map<int, int> map_ft){

//	std::cout <<  FT_PR_COLOR << " FT map check END == BEGIN: " << (map_ft.begin() == map_ft.end() )<< std::endl;


	std::cout << STD_PR_COLOR << "STD map output by iterator:" << std::endl;

	std::map<int, int>::iterator	it_map_std;
	for (it_map_std = map_std.begin(); it_map_std != map_std.end(); it_map_std++){
		std::cout << (*it_map_std).second << " ";
	}
	std::cout << FT_PR_COLOR << std::endl;


	//map_ft.print();
	std::cout <<  FT_PR_COLOR << " FT map output by iterator:" << std::endl;

	ft::map<int, int>::iterator	it_map_ft;
	for (it_map_ft = map_ft.begin(); it_map_ft != map_ft.end(); it_map_ft++){
		std::cout << (*it_map_ft).second << " ";
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

	//ft::vector<int>::const_iterator	it_vec_ft_const = vec_ft.begin();



/////////////////////////////////////////////////////////////////// __  __    _    __
///////////////////////////// MAP ///////////////////////////////// | \/ |   /-\   |_)
/////////////////////////////////////////////////////////////////// |    |  /   \  |

	std::cout << RESET_COLOR << "\n" << L_CELLS << " MAP " << R_CELLS << std::endl;


	std::map<int, int>	map_std;
	ft::map<int, int>	map_ft;

	std::cout <<  FT_PR_COLOR << " FT map check END == BEGIN: " << (map_ft.begin() == map_ft.end() )<< std::endl;


	print_maps(map_std, map_ft);


	std::cout << STD_PR_COLOR << "STD map check EMPTY: " << map_std.empty() << std::endl;
	std::cout <<  FT_PR_COLOR << " FT map check EMPTY: " << map_ft.empty() << std::endl;

	map_std.insert(std::make_pair(-11,-11));
	map_std.insert(std::make_pair(11,11));
	map_std.insert(std::make_pair(5, 5));
	map_std.insert(std::make_pair(3, 3));
	map_std.insert(std::make_pair(7, 7));
	map_std.insert(std::make_pair(18, 18));
	map_std.insert(std::make_pair(18, 10));
//	map_std.insert(std::make_pair(7, 7));
//	map_std.insert(std::make_pair(-3, -3));

	map_ft.insert(ft::make_pair(-11,-11));
	map_ft.insert(ft::make_pair(11, 11));
	map_ft.insert(ft::make_pair(5, 5));
	map_ft.insert(ft::make_pair(3, 3));
	map_ft.insert(ft::make_pair(7, 7));
	map_ft.insert(ft::make_pair(18, 18));
	map_ft.insert(ft::make_pair(18, 10));
//	map_ft.insert(ft::make_pair(7, 7));

	print_maps(map_std, map_ft);


	std::cout << STD_PR_COLOR << "STD map check EMPTY after insert: " << map_std.empty() << std::endl;
	std::cout <<  FT_PR_COLOR << " FT map check EMPTY after insert: " << map_ft.empty() << std::endl;

	std::cout << STD_PR_COLOR << "STD map SIZE: " << map_std.size() << std::endl;
	std::cout <<  FT_PR_COLOR << " FT map SIZE: " << map_ft.size() << std::endl;


	int	map_el = 9;
	std::cout << STD_PR_COLOR << "STD map el[" << map_el << "]: " << map_std[map_el] << std::endl;
//	std::cout << "try some" << std::endl;
	std::cout <<  FT_PR_COLOR << " FT map el[" << map_el << "]: " << map_ft[map_el] << std::endl;


//	map_std[7] = 77;
//	std::cout << map_std[7] << std::endl;
	std::cout << STD_PR_COLOR << "STD map SIZE: " << map_std.size() << std::endl;
	std::cout <<  FT_PR_COLOR << " FT map SIZE: " << map_ft.size() << std::endl;

	print_maps(map_std, map_ft);

	map_std[15] = 15;
	map_std[6] = 6;
	map_std[4] = 4;
	map_std[28] = 28;
	map_std[9] = 9;
	map_ft[15] = 15;
	map_ft[6] = 6;
	map_ft[4] = 4;
	map_ft[28] = 28;
	map_ft[9] = 9;

	print_maps(map_std, map_ft);

	std::cout << STD_PR_COLOR << "STD map MIN: " << (map_std.begin())->second << std::endl;
	std::cout <<  FT_PR_COLOR << " FT map MIN: " << map_ft.begin()->second << std::endl;

	std::map<int, int>::iterator	it_map_std =  map_std.begin();
	ft::map<int, int>::iterator	it_map_ft =  map_ft.begin();
	
	it_map_std++;
	it_map_std++;
	it_map_std++;
	it_map_std++;
	it_map_std++;
	it_map_std++;
	it_map_std++;
	it_map_std++;
	it_map_std++;
	it_map_std++;
	++it_map_ft;
	++it_map_ft;
	++it_map_ft;
	++it_map_ft;
	++it_map_ft;
	++it_map_ft;
	++it_map_ft;
	++it_map_ft;
	++it_map_ft;
	++it_map_ft;
	//it_map_ft = it_map_ft + 3;

	std::cout << STD_PR_COLOR << "STD map output by iterator ++: " << std::endl;
	for (it_map_std = map_std.begin(); it_map_std != map_std.end(); ++it_map_std){
		std::cout << it_map_std->second << " ";
	}
	std::cout << std::endl;

	std::cout <<  FT_PR_COLOR << " FT map output by iterator ++: " << std::endl;
	for (it_map_ft = map_ft.begin(); it_map_ft != map_ft.end(); ++it_map_ft){
		std::cout << it_map_ft->second << " ";
	}
	std::cout << std::endl;


	std::cout << STD_PR_COLOR << "STD map BEGIN() iterator ++: " << map_std.begin()->second << std::endl;
	std::cout <<  FT_PR_COLOR << " FT map BEGIN() iterator ++: " << map_ft.begin()->second << std::endl;

	--it_map_std;
	--it_map_std;
	--it_map_std;
	--it_map_std;
	--it_map_std;
	--it_map_std;
	--it_map_std;
	--it_map_std;
	--it_map_std;
	--it_map_std;
	--it_map_ft;
	--it_map_ft;
	--it_map_ft;
	--it_map_ft;
	--it_map_ft;
	--it_map_ft;
	--it_map_ft;
	--it_map_ft;
	--it_map_ft;
	--it_map_ft;

	std::cout << STD_PR_COLOR << "STD map BEGIN() iterator --: " << it_map_std->second << std::endl;
	std::cout <<  FT_PR_COLOR << " FT map BEGIN() iterator --: " << it_map_ft->second << std::endl;

	std::cout << STD_PR_COLOR << "STD map MAX: " << (--map_std.end())->second << std::endl;
	std::cout <<  FT_PR_COLOR << " FT map MAX: " << (--map_ft.end())->second << std::endl;

	std::cout << STD_PR_COLOR << "STD map PRE elem 8: " << map_std.lower_bound(8)->second << std::endl;
	std::cout <<  FT_PR_COLOR << " FT map PRE elem 8: " << map_ft.lower_bound(8)->second << std::endl;


	std::map<int, int>	map_std2;
	ft::map<int, int>	map_ft2;

	map_std2.insert(std::make_pair(-11, -11));
	map_ft2.insert(ft::make_pair(-11, -11));

	std::cout << STD_PR_COLOR << "STD map END() == another STD map END(): " << (map_std.end() == map_std2.end()) << std::endl;
	std::cout <<  FT_PR_COLOR << " FT map END() == another STD map END(): " << (map_ft.end() == map_ft2.end()) << std::endl;

	print_maps(map_std2, map_ft2);

std::cout <<	map_std2.erase(-11) << std::endl;
std::cout <<	map_std2.erase(-11) << std::endl;
std::cout <<	map_ft2.erase(-11)  << std::endl;
std::cout <<	map_ft2.erase(-11) << std::endl;

	map_ft2[30];
	map_ft2[33] = 33;

	map_ft2.erase(33);
	map_ft2.erase(30);

	std::cout << STD_PR_COLOR << "STD map END() == another STD map END(): " << &(*map_std2.begin()) << " " << &(*map_std2.end()) << std::endl;
	std::cout <<  FT_PR_COLOR << " FT map END() == another STD map END(): " << &(*map_ft2.begin()) << " " << &(*map_ft2.end())  << std::endl;

	print_maps(map_std2, map_ft2);


	int	n_map_find = 7;
//	std::cout << STD_PR_COLOR << "STD map FIND(" << n_map_find << "): " << &(*map_ft.find(n_map_find)) << std::endl;

	std::cout << STD_PR_COLOR << "STD map FIND(" << n_map_find << "): " << (map_std.find(n_map_find)->second) << std::endl;
	std::cout <<  FT_PR_COLOR << " FT map FIND(" << n_map_find << "): " << (map_ft.find(n_map_find)->second) << std::endl;


	n_map_find = 8;
//	std::cout << STD_PR_COLOR << "STD map FIND(" << n_map_find << "): " << &(*map_ft.find(n_map_find)) << std::endl;

	std::cout << STD_PR_COLOR << "STD map FIND(" << n_map_find << ") == END(): " << (map_std.find(n_map_find) == map_std.end()) << std::endl;
	std::cout <<  FT_PR_COLOR << " FT map FIND(" << n_map_find << ") == END(): " << (map_ft.find(n_map_find) == map_ft.end()) << std::endl;

	print_maps(map_std, map_ft);

	int	n_map_at = 9;
	std::cout << STD_PR_COLOR << "STD map AT(" << n_map_at << "): " << map_std.at(n_map_at) << std::endl;
	std::cout <<  FT_PR_COLOR << " FT map AT(" << n_map_at << "): " << map_ft.at(n_map_at) << std::endl;

	try{
		std::cout << STD_PR_COLOR << "STD map AT(" << -20 << "): " << map_std.at(-20) << std::endl;
	}
	catch (std::exception& ex){
		std::cout << ex.what() << std::endl;
	}

	try{
		std::cout << STD_PR_COLOR << " FT map AT(" << -20 << "): " << map_ft.at(-20) << std::endl;
	}
	catch (std::exception& ex){
		std::cout << ex.what() << std::endl;
	}

	std::cout << "tree output:" << std::endl;
	map_ft.print();

	print_maps(map_std, map_ft);


	std::map<int, int>	map_std3 = map_std;
	ft::map<int, int>	map_ft3 = map_ft;

	print_maps(map_std3, map_ft3);

	map_ft3.print();

	std::map<int, int>	map_std4(map_std);
	ft::map<int, int>	map_ft4(map_ft);

	map_std4[9] = 999;
	map_ft4[9] = 999;

	map_ft4.print();

	print_maps(map_std4, map_ft4);
	print_maps(map_std, map_ft);


	std::map<int, int>	map_std5(map_std.begin(), map_std.end());
	ft::map<int, int>	map_ft5(map_ft.begin(), map_ft.end());

	map_ft5.print();

	print_maps(map_std5, map_ft5);
	print_maps(map_std, map_ft);


	map_std.clear();
	map_ft.clear();


	std::cout << STD_PR_COLOR << "STD SIZE after CLEAR: " << map_std.size() << std::endl;
	std::cout <<  FT_PR_COLOR << " FT SIZE after CLEAR: " << map_ft.size() << std::endl;

	print_maps(map_std, map_ft);


	std::pair<std::map<int, int>::iterator, bool>	para_std = map_std.insert(std::make_pair(4, 4));
	ft::pair<ft::map<int, int>::iterator, bool>	para_ft = map_ft.insert(ft::make_pair(4, 4));

	para_std = map_std.insert(std::make_pair(4, 44));
	para_ft = map_ft.insert(ft::make_pair(4, 44));

	std::cout << STD_PR_COLOR << "STD INSERT return: " << (para_std.first)->second << " " << para_std.second << std::endl;
	std::cout <<  FT_PR_COLOR << " FT INSERT return: " << (para_ft.first)->second << " " << para_ft.second << std::endl;

	std::cout << STD_PR_COLOR << "STD SIZE after CLEAR: " << map_std.size() << std::endl;
	std::cout <<  FT_PR_COLOR << " FT SIZE after CLEAR: " << map_ft.size() << std::endl;


	map_std.swap(map_std4);
	map_ft.swap(map_ft4);

	print_maps(map_std, map_ft);

	std::cout << STD_PR_COLOR << "STD LOWER_BOUND (10): " << map_std.lower_bound(10)->second << std::endl;
	std::cout <<  FT_PR_COLOR << " FT LOWER_BOUND (10): " << map_ft.lower_bound(10)->second << std::endl;

	std::cout << STD_PR_COLOR << "STD UPPER_BOUND (15): " << map_std.upper_bound(15)->second << std::endl;
	std::cout <<  FT_PR_COLOR << " FT UPPER_BOUND (15): " << map_ft.upper_bound(15)->second << std::endl;

	print_maps(map_std, map_ft);

	std::cout << STD_PR_COLOR << "STD EQUAL_RANGE (15): " << map_std.equal_range(15).first->second << " - " << map_std.equal_range(15).second->second << std::endl;
	std::cout <<  FT_PR_COLOR << " FT EQUAL_RANGE (15): " << map_ft.equal_range(15).first->second << " - " << map_ft.equal_range(15).second->second << std::endl;


	std::map<int, int>::const_iterator	it_map_std_const = map_std.begin();
//	ft::map<int, int>::const_iterator	it_map_ft_const = map_ft.begin();

	// std::cout << STD_PR_COLOR << "STD const_iterator BEGIN(): " << it_map_std_const->second << std::endl;
	// std::cout <<  FT_PR_COLOR << " FT const_iterator BEGIN(): " << it_map_ft_const->second << std::endl;

	// it_map_std_const++;
//	it_map_std_const->second = 5;

	// std::cout << STD_PR_COLOR << "STD const_iterator BEGIN(): " << it_map_std_const->second << std::endl;
	// std::cout <<  FT_PR_COLOR << " FT const_iterator BEGIN(): " << it_map_ft_const->second << std::endl;


	while(1);
}