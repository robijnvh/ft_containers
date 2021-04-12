#include "catch.hpp"

#include <list>
#include "../includes/list.hpp"
#include <iostream>

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
    REQUIRE(ft_list.empty() == ft_test.empty());
	REQUIRE(ft_list.front() == ft_test.front());
	REQUIRE(ft_list.back() == ft_test.back());
}
TEST_CASE( "list - copy constructor", "[list]" ) {
    ft::list<int> ft_test(5, 100);
    ft::list<int> ft_list(ft_test);
    REQUIRE(ft_test.size() == ft_list.size()); // list copied from excisting
    REQUIRE(ft_list.empty() == ft_test.empty()); 
	REQUIRE(ft_list.front() == ft_test.front());
	REQUIRE(ft_list.back() == ft_test.back());
}
TEST_CASE( "list - assignation operator", "[list]" ) {
    ft::list<int> ft_test(5, 100);
    ft::list<int> ft_list;
    ft_list = ft_test;
    REQUIRE(ft_list.size() == ft_test.size()); // list set from excisting
    REQUIRE(ft_list.empty() == ft_test.empty()); 
	REQUIRE(ft_list.front() == ft_test.front());
	REQUIRE(ft_list.back() == ft_test.back());
}
// ITERATORS
TEST_CASE( "list - begin", "[list]" ) {
    ft::list<int> ft_list;
    std::list<int> std_list;
	for (int i = 1; i <= 7; i++) ft_list.push_back(i);
    for (int i = 1; i <= 7; i++) std_list.push_back(i);
    REQUIRE(*ft_list.begin() == *std_list.begin()); // it_ptr to _next first element
}
TEST_CASE( "list - const begin", "[list]" ) {
    ft::list<int> ft_list;
    std::list<int> std_list;
	for (int i = 1; i <= 7; i++) ft_list.push_back(i);
    for (int i = 1; i <= 7; i++) std_list.push_back(i);
	ft::list<int>::const_iterator ft_it = ft_list.begin();
	std::list<int>::const_iterator std_it = std_list.begin();
    REQUIRE(*ft_it == *std_it); // it_ptr to first element
}
TEST_CASE( "list - end", "[list]" ) {
    ft::list<int> ft_list;
    std::list<int> std_list;
	for (int i = 1; i <= 7; i++) ft_list.push_back(i);
    for (int i = 1; i <= 7; i++) std_list.push_back(i);
    ft::list<int>::iterator ft_it = ft_list.end();
	std::list<int>::iterator std_it = std_list.end();
    ft_it--;
    std_it--;
    REQUIRE(*(ft_it) == *(std_it)); // it_ptr to element preceding .end()
}
TEST_CASE( "list - const end", "[list]" ) {
    ft::list<int> ft_list;
    std::list<int> std_list;
	for (int i = 1; i <= 7; i++) ft_list.push_back(i);
    for (int i = 1; i <= 7; i++) std_list.push_back(i);
	ft::list<int>::const_iterator ft_it = ft_list.end();
	std::list<int>::const_iterator std_it = std_list.end();
	ft_it--;
	std_it--;
    REQUIRE(*ft_it == *std_it); // it_ptr to element preceding .end()
}
TEST_CASE( "list - rbegin", "[list]" ) {
    ft::list<int> ft_list;
    std::list<int> std_list;
	for (int i = 1; i <= 7; i++) ft_list.push_back(i);
    for (int i = 1; i <= 7; i++) std_list.push_back(i);
    REQUIRE(*ft_list.rbegin() == *std_list.rbegin()); // it_ptr to element preceding _last
}
TEST_CASE( "list - const rbegin", "[list]" ) {
    ft::list<int> ft_list;
    std::list<int> std_list;
	for (int i = 1; i <= 7; i++) ft_list.push_back(i);
    for (int i = 1; i <= 7; i++) std_list.push_back(i);
	ft::list<int>::const_reverse_iterator ft_it = ft_list.rbegin();
	std::list<int>::const_reverse_iterator std_it = std_list.rbegin();
    REQUIRE(*ft_it == *std_it); 
}
TEST_CASE( "list - rend", "[list]" ) {
    ft::list<int> ft_list;
    std::list<int> std_list;
	for (int i = 1; i <= 7; i++) ft_list.push_back(i);
    for (int i = 1; i <= 7; i++) std_list.push_back(i);
    ft::list<int>::reverse_iterator ft_it = ft_list.rend();
	std::list<int>::reverse_iterator std_it = std_list.rend();
    ft_it--;
    std_it--;
    REQUIRE(*(ft_it) == *(std_it)); // it_ptr to element preceding _first
}
TEST_CASE( "list - const rend", "[list]" ) {
    ft::list<int> ft_list;
    std::list<int> std_list;
	for (int i = 1; i <= 7; i++) ft_list.push_back(i);
    for (int i = 1; i <= 7; i++) std_list.push_back(i);
	ft::list<int>::const_reverse_iterator ft_it = ft_list.rend();
	std::list<int>::const_reverse_iterator std_it = std_list.rend();
	ft_it--;
	std_it--;
    REQUIRE(*ft_it == *std_it);
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
TEST_CASE( "list - empty", "[list]" ) {
    ft::list<int> ft_list;
    std::list<int> std_list;
    REQUIRE(ft_list.empty() == std_list.empty()); // true
    for (int i = 1; i <= 5; i++) ft_list.push_back(i);
    for (int i = 1; i <= 5; i++) std_list.push_back(i);
    REQUIRE(ft_list.empty() == std_list.empty()); // false
}
// ELEMENT ACCESS
TEST_CASE( "list - front", "[list]") {
	ft::list<int> ft_list(3, 3);
    std::list<int> std_list(3, 3);
    REQUIRE(ft_list.front() == std_list.front()); // ref to first element
}
TEST_CASE( "list - const front", "[list]") {
	ft::list<int> const ft_list(3, 3);
    std::list<int> const std_list(3, 3);
    REQUIRE(ft_list.front() == std_list.front()); // ref to first element
}
TEST_CASE( "list - back", "[list]") {
	ft::list<int> ft_list(3, 3);
    std::list<int> std_list(3, 3);
    REQUIRE(ft_list.back() == std_list.back()); // ref to last element
}
TEST_CASE( "list - const back", "[list]") {
	ft::list<int> const ft_list(3, 3);
    std::list<int> const std_list(3, 3);
    REQUIRE(ft_list.back() == std_list.back()); // ref to last element
}
// MODIIFIERS
TEST_CASE( "list - assign(first, last)", "[list]") { // klopt nog niet helemaal!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    // INT
git 
    // STRING
    // std::cout << "TEST0" << std::endl;
    // ft::list<std::string> ft_list2;
    // std::list<std::string> std_list2;
    // std::cout << "TEST1" << std::endl;
    // ft_list2.push_back("Hello");
    // ft_list2.push_back("World");
    // ft_list2.push_back("Bye");
    // ft_list2.push_back("!");
    // std_list2.push_back("Hello");
    // std_list2.push_back("World");
    // std_list2.push_back("Bye");
    // std_list2.push_back("!");
    // std::cout << "TEST2" << std::endl;
    // ft::list<std::string>::iterator ft_first2 = ft_list2.begin();
    // std::list<std::string>::iterator std_first2 = std_list2.begin();
	// ft::list<std::string>::iterator ft_last2 = ft_list2.end();
    // std::list<std::string>::iterator std_last2 = std_list2.end();
    // std::cout << "TEST3" << std::endl;
    // ft_last2--;
    // std_last2--;
	// ft::list<std::string> ft_test2;
    // std::list<std::string> std_test2;
	// ft_test2.assign(ft_first2, ft_last2);
	// std_test2.assign(std_first2, std_last2);
    // std::cout << "TEST4" << std::endl;
    // REQUIRE(ft_test2.size() == std_test2.size());
    // REQUIRE(ft_test2.empty() == std_test2.empty());
	// REQUIRE(ft_test2.front() == std_test2.front());
	// REQUIRE(ft_test2.back() == std_test2.back());
}
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