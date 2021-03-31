#include "vector.hpp"
#include <iostream>
#include <cstddef>
#include <vector>

int main(void) {
	std::vector<int>	std_vec;
	ft::vector<int>		ft_vec;

	std::cout << "------------------" << std::endl;
	// fill
	for (size_t i = 0; i != 10; i++) {
		std_vec.push_back(i);
		ft_vec.push_back(i);
	}
	std::cout << "sVECTOR" << std::endl;
	std::cout << "------------------" << std::endl;
	// print std_vec
	std::cout << "std_vec: ";
	for (size_t i = 1; i != 10; i++) {
		std::cout << std_vec[i] << " ";
	}
	std::cout << std::endl;
	// print ft_vec
	std::cout << "ft_vec: ";
	for (size_t i = 1; i != 10; i++) {
		std::cout << ft_vec[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "------------------" << std::endl;
	// iterator
	std::cout << "ITERATOR" << std::endl;
	std::cout << "------------------" << std::endl;
	std::vector<int>::iterator std_it;
	ft::vector<int>::iterator ft_it;
	std_it = std_vec.begin();
	ft_it = ft_vec.begin();
	std::cout << "std_it.begin(): " << *std_it << std::endl;
	std::cout << "ft_it.begin(): " << *ft_it << std::endl;
	std::cout << "------------------" << std::endl;
	++std_it;
	++ft_it;
	std::cout << "++std_it: " << *std_it << std::endl;
	std::cout << "++ft_it: " << *ft_it << std::endl;
	std::cout << "------------------" << std::endl;
	// std::ptrdiff_t diff = 3;
	// std_it + diff;
	// ft_it + diff;
	// std::cout << "std_it + 1: " << *std_it << std::endl;
	// std::cout << "ft_it + 1: " << *ft_it << std::endl;
	std_it = std_vec.end();
	ft_it = ft_vec.end();
	std::cout << "std_it.end(): " << *std_it << std::endl;
	std::cout << "ft_it.end(): " << *ft_it << std::endl;
	std::cout << "------------------" << std::endl;
	--std_it;
	--ft_it;
	std::cout << "--std_it: " << *std_it << std::endl;
	std::cout << "--ft_it: " << *ft_it << std::endl;
	// if (std_it == ft_it)
	// 	std::cout << "==: true" << std::endl;
	// else
	// 	std::cout << "==: false" << std::endl;
	// capacity
	std::cout << "------------------" << std::endl;
	std::cout << "CAPACITY" << std::endl;
	std::cout << "------------------" << std::endl;
	std::cout << "size" << std::endl;
	std::cout << "std_vec: " << std_vec.size() << std::endl;
	std::cout << "ft_vec: " << ft_vec.size() << std::endl;
	std::cout << "------------------" << std::endl;
	std::cout << "max_size" << std::endl;
	std::cout << "std_vec: " << std_vec.max_size() << std::endl;
	std::cout << "ft_vec: " << ft_vec.max_size() << std::endl;
	std::cout << "------------------" << std::endl;
	// resize
	std::cout << "resize" << std::endl;
	std::cout << "std_vec: " << std_vec.size();
	std_vec.resize(12, 0);
	std::cout << " -> " << std_vec.size();
	std::cout << " std_vec: ";
	for (size_t i = 1; i != std_vec.size(); i++) {
		std::cout << std_vec[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "ft_vec: " << ft_vec.size();
	ft_vec.resize(12, 0);
	std::cout << " -> " << ft_vec.size();
	std::cout << " ft_vec: ";
	for (size_t i = 1; i != ft_vec.size(); i++) {
		std::cout << ft_vec[i] << " ";
	}
	std::cout << std::endl;
	// capacity
	std::cout << "------------------" << std::endl;
	std::cout << "capacity" << std::endl;
	std::cout << "std_vec: " << std_vec.capacity() << std::endl;
	std::cout << "ft_vec: " << ft_vec.capacity() << std::endl;
	std::cout << "------------------" << std::endl;
	// empty
	std::cout << "empty" << std::endl;
	if (std_vec.empty())
		std::cout << "std_vec: true" << std::endl;
	else
		std::cout << "std_vec: false" << std::endl;
	if (ft_vec.empty())
		std::cout << "ft_vec: true" << std::endl;
	else
		std::cout << "ft_vec: false" << std::endl;
	// reserve
	std::cout << "------------------" << std::endl;
	std::cout << "reserve" << std::endl;
	std::cout << "std_vec: " << std_vec.capacity();
	std_vec.reserve(20);
	std::cout << " -> " << std_vec.capacity() << std::endl;
	std::cout << "ft_vec: " << ft_vec.capacity();
	ft_vec.reserve(20);
	std::cout << " -> " << ft_vec.capacity() << std::endl;
	std::cout << "------------------" << std::endl;
	// shrink_to_fit
	std::cout << "shrink_to_fit" << std::endl;
	std::cout << "std_vec: " << std_vec.capacity();
	std_vec.shrink_to_fit();
	std::cout << " -> " << std_vec.capacity() << std::endl;
	std::cout << "ft_vec: " << ft_vec.capacity();
	ft_vec.shrink_to_fit();
	std::cout << " -> " << ft_vec.capacity() << std::endl;
	std::cout << "------------------" << std::endl;
	// modifiers
	std::cout << "MODIFIERS" << std::endl;
	std::cout << "------------------" << std::endl;
	// push_back
	std::cout << "push_back" << std::endl;
	std::cout << "std_vec: [";
	for (size_t i = 0; i != std_vec.size(); i++) {
		std::cout << std_vec[i] << " ";
	}
	std::cout << "] -> [";
	std_vec.push_back(77);
	for (size_t i = 0; i != std_vec.size(); i++) {
		std::cout << std_vec[i] << " ";
	}
	std::cout << "]" << std::endl;
	std::cout << "ft_vec: [";
	for (size_t i = 0; i != ft_vec.size(); i++) {
		std::cout << ft_vec[i] << " ";
	}
	std::cout << "] -> [";
	ft_vec.push_back(77);
	for (size_t i = 0; i != ft_vec.size(); i++) {
		std::cout << ft_vec[i] << " ";
	}
	std::cout << "]" << std::endl;
	std::cout << "------------------" << std::endl;
	// assign
	std::cout << "assign" << std::endl;
	std::cout << "std_vec: [";
	for (size_t i = 0; i != std_vec.size(); i++) {
		std::cout << std_vec[i] << " ";
	}
	std::cout << "] -> [";
	std_vec.assign(3, 7);
	for (size_t i = 0; i != std_vec.size(); i++) {
		std::cout << std_vec[i] << " ";
	}
	std::cout << "]" << std::endl;
	std::cout << "ft_vec: [";
	for (size_t i = 0; i != ft_vec.size(); i++) {
		std::cout << ft_vec[i] << " ";
	}
	std::cout << "] -> [";
	ft_vec.assign(3, 7);
	for (size_t i = 0; i != ft_vec.size(); i++) {
		std::cout << ft_vec[i] << " ";
	}
	std::cout << "]" << std::endl;
	std::cout << "------------------" << std::endl;
	// clear
	std::cout << "clear" << std::endl;
	std::cout << "std_vec: [";
	for (size_t i = 0; i != std_vec.size(); i++) {
		std::cout << std_vec[i] << " ";
	}
	std::cout << "] -> [";
	std_vec.clear();
	for (size_t i = 0; i != std_vec.size(); i++) {
		std::cout << std_vec[i] << " ";
	}
	std::cout << "]" << std::endl;
	std::cout << "ft_vec: [";
	for (size_t i = 0; i != ft_vec.size(); i++) {
		std::cout << ft_vec[i] << " ";
	}
	std::cout << "] -> [";
	ft_vec.clear();
	for (size_t i = 0; i != ft_vec.size(); i++) {
		std::cout << ft_vec[i] << " ";
	}
	std::cout << "]" << std::endl;
	std::cout << "------------------" << std::endl;
	// insert
	std::cout << "insert" << std::endl;
	for (size_t i = 0; i != 10; i++) {
		std_vec.push_back(i);
		ft_vec.push_back(i);
	}
	std::vector<int>::iterator it2;
	it2 = std_vec.begin();
	ft::vector<int>::iterator it;
	it = ft_vec.begin();
	std::cout << "std_vec: [";
	for (size_t i = 0; i != std_vec.size(); i++) {
		std::cout << std_vec[i] << " ";
	}
	std::cout << "] -> [";
	std_vec.insert(it2, 1);
	for (size_t i = 0; i != std_vec.size(); i++) {
		std::cout << std_vec[i] << " ";
	}
	std::cout << "]" << std::endl;
	std::cout << "ft_vec: [";
	for (size_t i = 0; i != ft_vec.size(); i++) {
		std::cout << ft_vec[i] << " ";
	}
	std::cout << "] -> [";
	ft_vec.insert(it, 1);
	for (size_t i = 0; i != ft_vec.size(); i++) {
		std::cout << ft_vec[i] << " ";
	}
	std::cout << "]" << std::endl;
	std::cout << "------------------" << std::endl;
	// erase
	std::cout << "erase" << std::endl;
	std::cout << "std_vec: [";
	for (size_t i = 0; i != std_vec.size(); i++) {
		std::cout << std_vec[i] << " ";
	}
	std::cout << "] -> [";
	std_vec.erase(it2);
	for (size_t i = 0; i != std_vec.size(); i++) {
		std::cout << std_vec[i] << " ";
	}
	std::cout << "]" << std::endl;
	std::cout << "ft_vec: [";
	for (size_t i = 0; i != ft_vec.size(); i++) {
		std::cout << ft_vec[i] << " ";
	}
	std::cout << "] -> [";
	ft_vec.erase(it);
	for (size_t i = 0; i != ft_vec.size(); i++) {
		std::cout << ft_vec[i] << " ";
	}
	std::cout << "]" << std::endl;
	std::cout << "------------------" << std::endl;
}