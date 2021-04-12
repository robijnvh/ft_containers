#include "catch.hpp"

#include <list>
#include "../includes/list.hpp"

// COPLIEN
TEST_CASE( "list - default constructor", "[list]" ) {
    ft::list<int> ft_list;
    std::list<int> std_list;
    REQUIRE(ft_list.size() == std_list.size()); // empty list
}
TEST_CASE( "list - fill constructor", "[list]" ) {
    ft::list<int> ft_list(5, 100);
    std::list<int> std_list(5, 100);
    REQUIRE(ft_list.size() == std_list.size()); // list with n amount of value
}
TEST_CASE( "list - range constructor", "[list]" ) {
    ft::list<int> ft_test(5, 100);
    ft::list<int> ft_list(ft_test.begin(), ft_test.end());
    REQUIRE(ft_list.size() == ft_test.size()); // list first-last
}
// CAPACITY
TEST_CASE( "list - size", "[list]" ) {
    ft::list<int> ft_list;
    std::list<int> std_list;
    REQUIRE(ft_list.size() == std_list.size()); // non excisting size
    for (int i = 1; i <= 7; i++) ft_list.push_back(i);
    for (int i = 1; i <= 7; i++) std_list.push_back(i);
    REQUIRE(ft_list.size() == std_list.size()); // excisting size
}
TEST_CASE( "list - max_size", "[list]" ) {
    ft::list<int> ft_list;
    std::list<int> std_list;
    REQUIRE(ft_list.max_size() == std_list.max_size()); // check max_size
}

// MODIIFIERS
// TEST_CASE( "list - assign(first, last)", "[list]") { // klopt nog niet helemaal!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//     // INT
// 	ft::list<int> ft_list(3, 3);
// 	ft::list<int> ft_test(2, 2);
//     std::list<int> std_list(3, 3);
//     std::list<int> std_test(2, 2);
// 	ft::list<int>::iterator ft_first = ft_test.begin();
//     std::list<int>::iterator std_first = std_test.begin();
// 	ft::list<int>::iterator ft_last = ft_test.end() - 1;
//     std::list<int>::iterator std_last = std_test.end() - 1;
// 	ft_list.assign(ft_first, ft_last);
// 	std_list.assign(std_first, std_last);
// 	REQUIRE(ft_list[0] != 3); // check if assigned
// 	REQUIRE(ft_list[0] == std_list[0]); // check if elements are equal
// 	REQUIRE(ft_list[1] == std_list[1]); // check if elements are equal
//     // STRING
//     // ft::list<std::string> ft_list;
//     // std::list<std::string> std_list;
//     // ft_list.push_back("Hello");
//     // ft_list.push_back("World");
//     // ft_list.push_back("Bye");
//     // ft_list.push_back("!");
//     // std_list.push_back("Hello");
//     // std_list.push_back("World");
//     // std_list.push_back("Bye");
//     // std_list.push_back("!");
//     // ft::list<std::string>::iterator ft_first = ft_list.begin();
//     // std::list<std::string>::iterator std_first = std_list.begin();
// 	// ft::list<std::string>::iterator ft_last = ft_list.end() - 1;
//     // std::list<std::string>::iterator std_last = std_list.end() - 1;
// 	// ft::list<std::string> ft_test;
//     // std::list<std::string> std_test;
// 	// ft_test.assign(ft_first, ft_last);
// 	// std_test.assign(std_first, std_last);
//     // REQUIRE(ft_test.size() != 0); // check if assigned
//     // REQUIRE(ft_test[0] == std_test[0]); // check if elements equal 0
//     // REQUIRE(ft_test[1] == std_test[1]); // check if elements equal 1
//     // REQUIRE(ft_test[3] == std_test[3]); // check if elements equal 3
// }
TEST_CASE( "list - assign(n, value)", "[list]") {
	ft::list<int> ft_list(3, 3);
    std::list<int> std_list(3, 3);
	ft_list.assign(5, 5);
	std_list.assign(5, 5);
	REQUIRE(ft_list.front() == std_list.front()); // check if firstelement are equal
	REQUIRE(ft_list.back() == std_list.back()); // check if last element are equal
}
TEST_CASE( "list - push_front", "[list]") {
	ft::list<int> ft_list;
    std::list<int> std_list;
	for (int i = 1; i <= 5; i++) ft_list.push_front(i);
    for (int i = 1; i <= 5; i++) std_list.push_front(i);
	REQUIRE(ft_list.front() == std_list.front()); // check if firstelement are equal
	REQUIRE(ft_list.front() == std_list.front()); // check if last element are equal
}
TEST_CASE( "list - pop_front", "[list]") {
	ft::list<int> ft_list;
    std::list<int> std_list;
	for (int i = 1; i <= 5; i++) ft_list.push_front(i);
    for (int i = 1; i <= 5; i++) std_list.push_front(i);
	REQUIRE(ft_list.front() == std_list.front()); // check if last element are equal
	ft_list.pop_front();
	std_list.pop_front();
	REQUIRE(ft_list.front() == std_list.front()); // check if last element are equal
}
TEST_CASE( "list - push_back", "[list]") {
	ft::list<int> ft_list;
    std::list<int> std_list;
	for (int i = 1; i <= 5; i++) ft_list.push_back(i);
    for (int i = 1; i <= 5; i++) std_list.push_back(i);
	REQUIRE(ft_list.front() == std_list.front()); // check if firstelement are equal
	REQUIRE(ft_list.back() == std_list.back()); // check if last element are equal
}
TEST_CASE( "list - pop_back", "[list]") {
	ft::list<int> ft_list;
    std::list<int> std_list;
	for (int i = 1; i <= 5; i++) ft_list.push_back(i);
    for (int i = 1; i <= 5; i++) std_list.push_back(i);
	REQUIRE(ft_list.back() == std_list.back()); // check if last element are equal
	ft_list.pop_back();
	std_list.pop_back();
	REQUIRE(ft_list.back() == std_list.back()); // check if last element are equal
}
TEST_CASE( "list - resize", "[list]" ) {
    ft::list<int> ft_list;
    for (int i = 1; i <= 20; i++) ft_list.push_back(i);
    ft_list.resize(20);
    REQUIRE(ft_list.size() == 20); // equal
    ft_list.resize(10);
    REQUIRE(ft_list.size() == 10); // less
    ft_list.resize(15);
    REQUIRE(ft_list.size() == 15); // more
    ft_list.resize(1);
    REQUIRE(ft_list.size() == 1); // less
}
TEST_CASE( "list - clear", "[list]") {
	ft::list<int> ft_list(10, 1);
    std::list<int> std_list(10, 1);
	ft_list.clear();
	std_list.clear();
	REQUIRE(ft_list.size() == std_list.size()); // check if size equal
}