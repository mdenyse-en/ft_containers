#include <stdlib.h>
#include <iostream>
#include <string>
#include <deque>
#include <set>

#include "../includes/set.hpp"


#define STD_PR_COLOR "\x1b[32m"
#define FT_PR_COLOR "\x1b[34m"
#define RESET_COLOR "\x1b[0m"
#define L_CELLS "--------------------"
#define R_CELLS "--------------------"


//template<class T>

void	print_sets(std::set<int> set_std, ft::set<int> set_ft){

//	std::cout <<  FT_PR_COLOR << " FT set check END == BEGIN: " << (set_ft.begin() == set_ft.end() )<< std::endl;


	std::cout << STD_PR_COLOR << "STD set output by iterator:" << std::endl;

	std::set<int>::iterator	it_set_std;
	for (it_set_std = set_std.begin(); it_set_std != set_std.end(); it_set_std++){
		std::cout << (*it_set_std) << " ";
	}
	std::cout << FT_PR_COLOR << std::endl;


	//set_ft.print();
	std::cout <<  FT_PR_COLOR << " FT set output by iterator:" << std::endl;

	ft::set<int, int>::iterator	it_set_ft;
	for (it_set_ft = set_ft.begin(); it_set_ft != set_ft.end(); it_set_ft++){
		std::cout << (*it_set_ft)<< " ";
	}
	std::cout << std::endl;
}

int	main(int argc, char** argv){

/////////////////////////////////////////////////////////////////// /-  |--  ---
///////////////////////////// SET ///////////////////////////////// \-\ |--   |
///////////////////////////////////////////////////////////////////  _/ |--   |

	std::cout << RESET_COLOR << "\n" << L_CELLS << " set " << R_CELLS << std::endl;


	std::set<int>	set_std;
	ft::set<int>	set_ft;

	std::cout <<  FT_PR_COLOR << " FT set check END == BEGIN: " << (set_ft.begin() == set_ft.end() )<< std::endl;


	print_sets(set_std, set_ft);


	std::cout << STD_PR_COLOR << "STD set check EMPTY: " << set_std.empty() << std::endl;
	std::cout <<  FT_PR_COLOR << " FT set check EMPTY: " << set_ft.empty() << std::endl;

	set_std.insert((-11));
	set_std.insert((11));
	set_std.insert((5));
	set_std.insert((3));
	set_std.insert((7));
	set_std.insert((18));
	set_std.insert((18));
//	set_std.insert((7, 7));
//	set_std.insert((-3, -3));

	set_ft.insert((-11));
	set_ft.insert((11));
//	set_ft.print();
	set_ft.insert((5));
//	set_ft.print();

	set_ft.insert((3));
//	set_ft.print();

	set_ft.insert((7));
//	set_ft.print();

	set_ft.insert((18));
//	set_ft.print();

	set_ft.insert((18));
//	set_ft.print();

//	set_ft.insert((7, 7));

	print_sets(set_std, set_ft);


	std::cout << STD_PR_COLOR << "STD set check EMPTY after insert: " << set_std.empty() << std::endl;
	std::cout <<  FT_PR_COLOR << " FT set check EMPTY after insert: " << set_ft.empty() << std::endl;

	std::cout << STD_PR_COLOR << "STD set SIZE: " << set_std.size() << std::endl;
	std::cout <<  FT_PR_COLOR << " FT set SIZE: " << set_ft.size() << std::endl;



//	set_std[7] = 77;
//	std::cout << set_std[7] << std::endl;
	std::cout << STD_PR_COLOR << "STD set SIZE: " << set_std.size() << std::endl;
	std::cout <<  FT_PR_COLOR << " FT set SIZE: " << set_ft.size() << std::endl;

	print_sets(set_std, set_ft);

	set_std.insert(15);
	set_std.insert(6);
	set_std.insert(4);
	set_std.insert(28);
	set_std.insert(9);
	set_ft.insert(15);
	set_ft.insert(6);
	set_ft.insert(4);
	set_ft.insert(28);
	set_ft.insert(9);

	print_sets(set_std, set_ft);

	std::cout << STD_PR_COLOR << "STD set MIN: " << *(set_std.begin()) << std::endl;
	std::cout <<  FT_PR_COLOR << " FT set MIN: " << *(set_ft.begin()) << std::endl;

	std::set<int>::iterator	it_set_std =  set_std.begin();
	ft::set<int>::iterator	it_set_ft =  set_ft.begin();
	
	it_set_std++;
	it_set_std++;
	it_set_std++;
	it_set_std++;
	it_set_std++;
	it_set_std++;
	it_set_std++;
	it_set_std++;
	it_set_std++;
	it_set_std++;
	++it_set_ft;
	++it_set_ft;
	++it_set_ft;
	++it_set_ft;
	++it_set_ft;
	++it_set_ft;
	++it_set_ft;
	++it_set_ft;
	++it_set_ft;
	++it_set_ft;
	//it_set_ft = it_set_ft + 3;

	std::cout << STD_PR_COLOR << "STD set output by iterator ++: " << std::endl;
	for (it_set_std = set_std.begin(); it_set_std != set_std.end(); ++it_set_std){
		std::cout << *it_set_std << " ";
	}
	std::cout << std::endl;

	std::cout <<  FT_PR_COLOR << " FT set output by iterator ++: " << std::endl;
	for (it_set_ft = set_ft.begin(); it_set_ft != set_ft.end(); ++it_set_ft){
		std::cout << *it_set_ft << " ";
	}
	std::cout << std::endl;


	std::cout << STD_PR_COLOR << "STD set BEGIN() iterator ++: " << *(set_std.begin()) << std::endl;
	std::cout <<  FT_PR_COLOR << " FT set BEGIN() iterator ++: " << *(set_ft.begin()) << std::endl;

	--it_set_std;
	--it_set_std;
	--it_set_std;
	--it_set_std;
	--it_set_std;
	--it_set_std;
	--it_set_std;
	--it_set_std;
	--it_set_std;
	--it_set_std;
	--it_set_ft;
	--it_set_ft;
	--it_set_ft;
	--it_set_ft;
	--it_set_ft;
	--it_set_ft;
	--it_set_ft;
	--it_set_ft;
	--it_set_ft;
	--it_set_ft;

	std::cout << STD_PR_COLOR << "STD set BEGIN() iterator --: " << *it_set_std << std::endl;
	std::cout <<  FT_PR_COLOR << " FT set BEGIN() iterator --: " << *it_set_ft << std::endl;

	std::cout << STD_PR_COLOR << "STD set MAX: " << *(--set_std.end()) << std::endl;
	std::cout <<  FT_PR_COLOR << " FT set MAX: " << *(--set_ft.end()) << std::endl;

	std::cout << STD_PR_COLOR << "STD set PRE elem 8: " << *(set_std.lower_bound(8)) << std::endl;
	std::cout <<  FT_PR_COLOR << " FT set PRE elem 8: " << *(set_ft.lower_bound(8)) << std::endl;


	std::set<int>	set_std2;
	ft::set<int>	set_ft2;

	set_std2.insert(-11);
	set_ft2.insert(-11);

	std::cout << STD_PR_COLOR << "STD set END() == another STD set END(): " << (set_std.end() == set_std2.end()) << std::endl;
	std::cout <<  FT_PR_COLOR << " FT set END() == another STD set END(): " << (set_ft.end() == set_ft2.end()) << std::endl;

	print_sets(set_std2, set_ft2);

	std::cout <<	set_std2.erase(-11) << std::endl;
	std::cout <<	set_std2.erase(-11) << std::endl;
	std::cout <<	set_ft2.erase(-11)  << std::endl;
	std::cout <<	set_ft2.erase(-11) << std::endl;


	// set_std2[30] = 30;
	// set_std2[33] = 33;
	// set_std2[35] = 35;

	set_ft2.insert(30);
	set_ft2.insert(33);
	set_ft2.insert(35);

	set_std2.erase(33);
	set_std2.erase(35);


//set_ft2.print();
	set_ft2.erase(33);

//set_ft2.print();
	set_ft2.erase(30);

//set_ft2.print();
	set_ft2.erase(35);

//set_ft2.print();

	print_sets(set_std2, set_ft2);

	std::cout << STD_PR_COLOR << "STD set END() == another STD set END(): " << &(*set_std2.begin()) << " " << &(*set_std2.end()) << std::endl;
	std::cout <<  FT_PR_COLOR << " FT set END() == another STD set END(): " << &(*set_ft2.begin()) << " " << &(*set_ft2.end())  << std::endl;

	print_sets(set_std2, set_ft2);


	int	n_set_find = 7;
//	std::cout << STD_PR_COLOR << "STD set FIND(" << n_set_find << "): " << &(*set_ft.find(n_set_find)) << std::endl;

	std::cout << STD_PR_COLOR << "STD set FIND(" << n_set_find << "): " << *(set_std.find(n_set_find)) << std::endl;
	std::cout <<  FT_PR_COLOR << " FT set FIND(" << n_set_find << "): " << *(set_ft.find(n_set_find)) << std::endl;


	n_set_find = 8;
//	std::cout << STD_PR_COLOR << "STD set FIND(" << n_set_find << "): " << &(*set_ft.find(n_set_find)) << std::endl;

	std::cout << STD_PR_COLOR << "STD set FIND(" << n_set_find << ") == END(): " << (set_std.find(n_set_find) == set_std.end()) << std::endl;
	std::cout <<  FT_PR_COLOR << " FT set FIND(" << n_set_find << ") == END(): " << (set_ft.find(n_set_find) == set_ft.end()) << std::endl;

	print_sets(set_std, set_ft);


	print_sets(set_std, set_ft);


	std::set<int>	set_std3 = set_std;
	ft::set<int>	set_ft3 = set_ft;

	print_sets(set_std3, set_ft3);

	std::set<int>	set_std4(set_std);
	ft::set<int>	set_ft4(set_ft);

	set_std4.insert(999);
	set_ft4.insert(999);


	print_sets(set_std4, set_ft4);
	print_sets(set_std, set_ft);


	std::set<int>	set_std5(set_std.begin(), set_std.end());
	ft::set<int>	set_ft5(set_ft.begin(), set_ft.end());

	print_sets(set_std5, set_ft5);
	print_sets(set_std, set_ft);


	set_std.clear();
	set_ft.clear();


	std::cout << STD_PR_COLOR << "STD SIZE after CLEAR: " << set_std.size() << std::endl;
	std::cout <<  FT_PR_COLOR << " FT SIZE after CLEAR: " << set_ft.size() << std::endl;

	print_sets(set_std, set_ft);


	std::pair<std::set<int>::iterator, bool>	para_std = set_std.insert(4);
	ft::pair<ft::set<int>::iterator, bool>	para_ft = set_ft.insert(4);

	// para_std = set_std.insert(44);
	// para_ft = set_ft.insert(44);

	std::cout << STD_PR_COLOR << "STD INSERT return: " << *(para_std.first) << " " << para_std.second << std::endl;
	std::cout <<  FT_PR_COLOR << " FT INSERT return: " << *(para_ft.first) << " " << para_ft.second << std::endl;

	std::cout << STD_PR_COLOR << "STD SIZE after CLEAR: " << set_std.size() << std::endl;
	std::cout <<  FT_PR_COLOR << " FT SIZE after CLEAR: " << set_ft.size() << std::endl;


	set_std.swap(set_std4);
	set_ft.swap(set_ft4);

	print_sets(set_std, set_ft);

	std::cout << STD_PR_COLOR << "STD LOWER_BOUND (10): " << *(set_std.lower_bound(10)) << std::endl;
	std::cout <<  FT_PR_COLOR << " FT LOWER_BOUND (10): " << *(set_ft.lower_bound(10)) << std::endl;

	std::cout << STD_PR_COLOR << "STD UPPER_BOUND (15): " << *(set_std.upper_bound(15)) << std::endl;
	std::cout <<  FT_PR_COLOR << " FT UPPER_BOUND (15): " << *(set_ft.upper_bound(15)) << std::endl;

	print_sets(set_std, set_ft);

	std::cout << STD_PR_COLOR << "STD EQUAL_RANGE (15): " << *(set_std.equal_range(15).first)<< " - " << *(set_std.equal_range(15).second) << std::endl;
	std::cout <<  FT_PR_COLOR << " FT EQUAL_RANGE (15): " << *(set_ft.equal_range(15).first) << " - " << *(set_ft.equal_range(15).second) << std::endl;



//CONST_ITERATORS check:
	std::set<int>::const_iterator	it_set_std_const = set_std.begin();
	ft::set<int>::const_iterator	it_set_ft_const = set_ft.begin();

	std::cout << STD_PR_COLOR << "STD const_iterator BEGIN(): " << *(it_set_std_const) << std::endl;
	std::cout <<  FT_PR_COLOR << " FT const_iterator BEGIN(): " << *(it_set_ft_const) << std::endl;

	it_set_std_const++;
	it_set_ft_const++;

	std::cout << STD_PR_COLOR << "STD const_iterator BEGIN() after ++: " << *(it_set_std_const) << std::endl;
	std::cout <<  FT_PR_COLOR << " FT const_iterator BEGIN() after ++: " << *(it_set_ft_const) << std::endl;

	// *it_set_ft_const = 3;

	std::set<int>::reverse_iterator	it_set_std2 = set_std.rbegin();
	ft::set<int>::reverse_iterator		it_set_ft2 = set_ft.rbegin();

	it_set_std2++;
	it_set_ft2++;

	std::cout << STD_PR_COLOR << "STD revers iterator REND()++ = " << *(it_set_std2) << std::endl;
	std::cout << FT_PR_COLOR << "STD revers iterator REND()++ = " << *(it_set_ft2) << std::endl;

	set_std.erase(set_std.begin(), --set_std.end());
	set_ft.erase(set_ft.begin(), --set_ft.end());
	
	// set_ft.erase(5);
	// set_ft.erase(18);
	// set_ft.erase(28);
	// set_ft.erase(9);
	// set_ft.erase(3);
	// set_ft.erase(4);
	// set_ft.erase(6);
	// set_ft.erase(11);
	// set_ft.erase(7);
	// set_ft.erase(set_ft.begin());

	// set_ft.erase(15);
	// set_ft.erase(set_ft.begin());
	// set_ft.erase(-11);

//	set_ft.erase(3);



//	set_ft.print();
	std::cout << STD_PR_COLOR << "STD SIZE() after ERASE(begin(), --end()): " << set_std.size() << std::endl;
	std::cout <<  FT_PR_COLOR << " FT SIZE() after ERASE(begin(), --end()): " << set_ft.size() << std::endl;

	print_sets(set_std, set_ft);

	std::cout << STD_PR_COLOR << "STD set == set: " << (set_std == set_std) << std::endl;
	std::cout << FT_PR_COLOR <<  " FT set == set: " << (set_ft == set_ft) << std::endl;

	std::set<int>	set_std_swap;
	ft::set<int>	set_ft_swap;

	set_std.swap(set_std_swap);
	set_ft.swap(set_ft_swap);

	print_sets(set_std, set_ft);


	std::swap(set_std, set_std_swap);
	ft::swap(set_ft, set_ft_swap);

	print_sets(set_std, set_ft);

	// while(1);
}