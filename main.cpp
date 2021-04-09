// #include "includes/utils/RandomAccessIterator.hpp"
#include "includes/list.hpp"
#include "includes/vector.hpp"
#include <list>
#include <vector>
#include <iostream>

int	main() {
	ft::list<int> ft_list;
	std::list<int> std_list;

	std::cout << ft_list.size() << std::endl;
	std::cout << std_list.size() << std::endl;
}
