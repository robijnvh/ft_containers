#include "vector.hpp"
#include <iostream>
#include <cstddef>
#include <vector>

int main() {
	ft::vector<int> test2;
	ft::vector<int> test(1, 3);
	ft::vector<int> stdvec(1, 4);

	ft::vector<int>::iterator it;
	ft::vector<int>::iterator stdit;
	ft::vector<int>::iterator stdit2;
	ft::vector<int>::iterator pos;

	stdit = stdvec.begin();
	stdit2 = stdvec.end();

	it = test.begin();

	std::cout << "--------------" << std::endl;
	std::cout << "CAPACITY:" << std::endl;
	std::cout << "--------------" << std::endl;
	std::cout << "size: " << test.size() << std::endl;
	std::cout << "max_size: " << test.max_size() << std::endl;
	std::cout << "resize: " << test.size();
	test.resize(3, 0);
	std::cout << " -> " << test.size() << std::endl;
	std::cout << "capacity: " << test.capacity() << std::endl;
	if (test.empty())
		std::cout << "empty: true" << std::endl;
	else
		std::cout << "empty: false" << std::endl;
	std::cout << "reserve: " << test.capacity();
	test.reserve(10);
	std::cout << " -> " << test.capacity() << std::endl;
	std::cout << "shrink_to_fit: " << test.capacity();
	test.shrink_to_fit();
	std::cout << " -> " << test.capacity() << std::endl;
	std::cout << "--------------" << std::endl;
	std::cout << "MODIFIERS:" << std::endl;
	std::cout << "--------------" << std::endl;
	std::cout << "assign(n, val): " << test[0];
	test.assign(1, 7);
	std::cout << " -> " << test[0] << std::endl;
	std::cout << "push_back: [" << test[0] << " - " << test[1];
	test.push_back(8);
	std::cout <<  "] -> [" << test[0] << " - " << test[1] << "]" << std::endl;
	std::cout << "clear: [" << test[0] << " - " << test[1] << "] " << test.size();
	test.clear();
	std::cout <<  " -> [" << test[0] << " - " << test[1] << "] " << test.size() << std::endl;
	std::cout << "insert: [" << test[0] << " - " << test[1] << "] " << test.size();
	test.insert(it, 1);
	it++;
	test.insert(it, 1);
	std::cout <<  " -> [" << test[0] << " - " << test[1] << "] " << test.size() << std::endl;
	// std::cout << "assign(first, last): " << test[0];
	// test.assign(stdit, stdit2);
	// std::cout << " -> " << test[0] << " size: " << test.size() << std::endl;
	pos = test.begin();
	std::cout << "erase(pos): " << test[0];
	test.erase(pos);
	std::cout << " -> " << test[0] << std::endl;
	return 0;
}