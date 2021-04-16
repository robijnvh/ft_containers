#include "catch.hpp"

#include <list>
#include <string>
#include "../includes/list.hpp"
#include <iostream> // to print

// predicate function
bool single_digit(const int& value) { return (value<10); }
// predicate class
struct is_odd {
bool operator()(const int& value) { return (value%2)==1; }
};
// binary predicate function
bool same_integral_part(double first, double second)
{ return ( int(first)==int(second) ); }
// binary predicate class:
struct is_near {
  bool operator()(double first, double second)
  { return (fabs(first-second)<5.0); }
};
// compare only integral part:
bool compare1(double first, double second)
{ return ( int(first)<int(second) ); }

// COPLIEN
TEST_CASE( "list - default constructor", "[list]" ) {
    ft::list<int> ft_list;
    std::list<int> std_list;
    REQUIRE(ft_list.size() == std_list.size()); // empty list
}
TEST_CASE( "list - fill constructor", "[list]" ) {
    // ft::list<int> ft_list(5, 100);
    // std::list<int> std_list(5, 100);
    // REQUIRE(ft_list.size() == std_list.size()); // list with n amount of value
    ft::list<std::string> ft_list2(5, "xp");
    std::list<std::string> std_list2(5, "xp");
    REQUIRE(ft_list2.size() == std_list2.size()); // list with n amount of value
    // REQUIRE(ft_list2.empty() == std_list2.empty());
}
TEST_CASE( "list - range constructor", "[list]" ) {
    ft::list<int> ft_test(5, 100);
    ft::list<int> ft_list(ft_test.begin(), ft_test.end());
    REQUIRE(ft_list.size() == ft_test.size()); // list first-last range
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
    REQUIRE(*ft_it == *std_it); // it_ptr to _next first element
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
    REQUIRE(*ft_it == *std_it); // it_ptr to element preceding _last
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
    REQUIRE(*ft_it == *std_it); // it_ptr to element preceding _first
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
    REQUIRE(ft_list.front() == std_list.front()); // ref to first excisting element
}
TEST_CASE( "list - const front", "[list]") {
	ft::list<int> const ft_list(3, 3);
    std::list<int> const std_list(3, 3);
    REQUIRE(ft_list.front() == std_list.front()); // ref to first excisting element
}
TEST_CASE( "list - back", "[list]") {
	ft::list<int> ft_list(3, 3);
    std::list<int> std_list(3, 3);
    REQUIRE(ft_list.back() == std_list.back()); // ref to last excisting element
}
TEST_CASE( "list - const back", "[list]") {
	ft::list<int> const ft_list(3, 3);
    std::list<int> const std_list(3, 3);
    REQUIRE(ft_list.back() == std_list.back()); // ref to last excisting element
}
// MODIIFIERS
TEST_CASE( "list - assign(first, last)", "[list]") { // klopt nog niet helemaal!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    // INT
    ft::list<int> ft_list(3, 3);
	ft::list<int> ft_test(2, 2);
    std::list<int> std_list(3, 3);
    std::list<int> std_test(2, 2);
	ft::list<int>::iterator ft_first = ft_test.begin();
    std::list<int>::iterator std_first = std_test.begin();
	ft::list<int>::iterator ft_last = ft_test.end();
    std::list<int>::iterator std_last = std_test.end();
    ft_last--;
    std_last--;
	ft_list.assign(ft_first, ft_last); // assign range of int
	std_list.assign(std_first, std_last);
    REQUIRE(ft_test.size() == std_test.size()); // check size
    REQUIRE(ft_test.empty() == std_test.empty()); // check empty
	REQUIRE(ft_test.front() == std_test.front()); // check first element
	REQUIRE(ft_test.back() == std_test.back()); // check last element
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
    // INT
	ft::list<int> ft_list(3, 3);
    std::list<int> std_list(3, 3);
	ft_list.assign(5, 5);
	std_list.assign(5, 5); // assign n amount of value (int)
    REQUIRE(ft_list.size() == std_list.size()); // check size
    REQUIRE(ft_list.empty() == std_list.empty()); // check if empty
	REQUIRE(ft_list.front() == std_list.front()); // check if first elements are equal
	REQUIRE(ft_list.back() == std_list.back()); // check if last elements are equal
    // CHAR
    ft::list<char> ft_chr_list(3, '!');
    std::list<char> std_chr_list(3, '!');
	ft_chr_list.assign(5, '5');
	std_chr_list.assign(5, '5'); /// assign n amoutn of val (char)
    REQUIRE(ft_chr_list.size() == std_chr_list.size()); // check size
    REQUIRE(ft_chr_list.empty() == std_chr_list.empty()); // check if empty
	REQUIRE(ft_chr_list.front() == std_chr_list.front()); // check if first elements are equal
	REQUIRE(ft_chr_list.back() == std_chr_list.back()); // check if last elements are equal
}
TEST_CASE( "list - push_front", "[list]") {
    // INT
	ft::list<int> ft_list;
    std::list<int> std_list;
	for (int i = 1; i <= 5; i++) ft_list.push_front(i); // push_front int
    for (int i = 1; i <= 5; i++) std_list.push_front(i);
    REQUIRE(ft_list.size() == std_list.size()); // check size
    REQUIRE(ft_list.empty() == std_list.empty()); // check if empty
	REQUIRE(ft_list.front() == std_list.front()); // check if first element are equal
	REQUIRE(ft_list.back() == std_list.back()); // check if last element are equal
    // CHAR
    ft::list<char> ft_chr_list;
    std::list<char> std_chr_list;
    ft_chr_list.push_front('B'); // push_front char
    std_chr_list.push_front('B');
    ft_chr_list.push_front('A');
    std_chr_list.push_front('A');
    REQUIRE(ft_chr_list.size() == std_chr_list.size()); // check size
    REQUIRE(ft_chr_list.empty() == std_chr_list.empty()); // check if empty
	REQUIRE(ft_chr_list.front() == std_chr_list.front()); // check if first elements are equal
	REQUIRE(ft_chr_list.back() == std_chr_list.back()); // check if last elements are equal
}
TEST_CASE( "list - pop_front", "[list]") {
	ft::list<int> ft_list;
    std::list<int> std_list;
	for (int i = 1; i <= 5; i++) ft_list.push_front(i); // push_front int
    for (int i = 1; i <= 5; i++) std_list.push_front(i);
    REQUIRE(ft_list.size() == std_list.size()); // check size
    REQUIRE(ft_list.empty() == std_list.empty()); // check if empty
	REQUIRE(ft_list.front() == std_list.front()); // check if first element are equal
	REQUIRE(ft_list.back() == std_list.back()); // check if last element are equal
	ft_list.pop_front(); // pop_front element
	std_list.pop_front();
    REQUIRE(ft_list.size() == std_list.size()); // check size
    REQUIRE(ft_list.empty() == std_list.empty()); // check if empty
	REQUIRE(ft_list.front() == std_list.front()); // check if first element are equal
	REQUIRE(ft_list.back() == std_list.back()); // check if last element are equal
}
TEST_CASE( "list - push_back", "[list]") {
    // INT
	ft::list<int> ft_list;
    std::list<int> std_list;
	for (int i = 1; i <= 5; i++) ft_list.push_back(i);  // push_back int
    for (int i = 1; i <= 5; i++) std_list.push_back(i);
    REQUIRE(ft_list.size() == std_list.size()); // check size
    REQUIRE(ft_list.empty() == std_list.empty()); // check if empty
	REQUIRE(ft_list.front() == std_list.front()); // check if firstelement are equal
	REQUIRE(ft_list.back() == std_list.back()); // check if last element are equal
    // CHAR
    ft::list<char> ft_chr_list;
    std::list<char> std_chr_list;
    ft_chr_list.push_back('A'); // push_back char
    std_chr_list.push_back('A');
    ft_chr_list.push_back('B');
    std_chr_list.push_back('B');
    REQUIRE(ft_chr_list.size() == std_chr_list.size()); // check size
    REQUIRE(ft_chr_list.empty() == std_chr_list.empty()); // check if empty
	REQUIRE(ft_chr_list.front() == std_chr_list.front()); // check if first elements are equal
	REQUIRE(ft_chr_list.back() == std_chr_list.back()); // check if last elements are equal
}
TEST_CASE( "list - pop_back", "[list]") {
	ft::list<int> ft_list;
    std::list<int> std_list;
	for (int i = 1; i <= 5; i++) ft_list.push_back(i); // push_back int
    for (int i = 1; i <= 5; i++) std_list.push_back(i);
    REQUIRE(ft_list.size() == std_list.size()); // check size
    REQUIRE(ft_list.empty() == std_list.empty()); // check if empty
	REQUIRE(ft_list.back() == std_list.back()); // check if last element are equal
	ft_list.pop_back(); // pop_back last element
	std_list.pop_back();
    REQUIRE(ft_list.size() == std_list.size()); // check size
    REQUIRE(ft_list.empty() == std_list.empty()); // check if empty
	REQUIRE(ft_list.back() == std_list.back()); // check if last element are equal
}
TEST_CASE( "list - insert(position, val)", "[list]") {
	ft::list<int> ft_list(3, 3);
    std::list<int> std_list(3, 3);
	ft::list<int>::iterator ft_it = ft_list.begin();
    std::list<int>::iterator std_it = std_list.begin();
    ft::list<int>::iterator ft_check;
    std::list<int>::iterator std_check;
	ft_check = ft_list.insert(ft_it, 1);
	std_check = std_list.insert(std_it, 1);
    REQUIRE(*ft_check == 1); // check return
    REQUIRE(*std_check == 1); // check return
    REQUIRE(ft_list.size() == std_list.size()); // check size
    REQUIRE(ft_list.empty() == std_list.empty()); // check if empty
	REQUIRE(ft_list.front() == std_list.front()); // check if firstelement are equal
	REQUIRE(ft_list.back() == std_list.back()); // check if last element are equal
}
TEST_CASE( "list - insert(position, n, value)", "[list]") {
	ft::list<int> ft_list(3, 3);
    std::list<int> std_list(3, 3);
	ft::list<int>::iterator ft_it = ft_list.begin();
    std::list<int>::iterator std_it = std_list.begin();
	ft_list.insert(ft_it, 2, 1);
	std_list.insert(std_it, 2, 1);
    ft_it = ft_list.begin();
    std_it = std_list.begin();
    REQUIRE(*ft_it == 1); // check val 1
    REQUIRE(*std_it == 1); // check val 1
    ft_it++;
    std_it++;
    REQUIRE(*ft_it == 1); // check val 1
    REQUIRE(*std_it == 1); // check val 1
    ft_it++;
    std_it++;
    REQUIRE(*ft_it == 3); // check val 3
    REQUIRE(*std_it == 3); // check val 3
    REQUIRE(ft_list.size() == std_list.size()); // check size
    REQUIRE(ft_list.empty() == std_list.empty()); // check if empty
	REQUIRE(ft_list.front() == std_list.front()); // check if firstelement are equal
	REQUIRE(ft_list.back() == std_list.back()); // check if last element are equal
}
TEST_CASE( "list - insert(pos, first, last)", "[list]") {
	ft::list<int> ft_list(3, 3);
	ft::list<int> ft_test(2, 1);
    std::list<int> std_list(3, 3);
    std::list<int> std_test(2, 1);
	ft::list<int>::iterator ft_pos = ft_list.begin();
    std::list<int>::iterator std_pos = std_list.begin();
	ft::list<int>::iterator ft_first = ft_test.begin();
    std::list<int>::iterator std_first = std_test.begin();
	ft::list<int>::iterator ft_last = ft_test.end();
    std::list<int>::iterator std_last = std_test.end();
	ft_list.insert(ft_pos, ft_first, ft_last);
	std_list.insert(std_pos, std_first, std_last);
    ft_pos = ft_list.begin();
    std_pos = std_list.begin();
    REQUIRE(*ft_pos == 1); // check val 1
    REQUIRE(*std_pos == 1); // check val 1
    ft_pos++;
    std_pos++;
    REQUIRE(*ft_pos == 1); // check val 1
    REQUIRE(*std_pos == 1); // check val 1
    ft_pos++;
    std_pos++;
    REQUIRE(*ft_pos == 3); // check val 3
    REQUIRE(*std_pos == 3); // check val 3
    REQUIRE(ft_list.size() == std_list.size()); // check size
    REQUIRE(ft_list.empty() == std_list.empty()); // check if empty
	REQUIRE(ft_list.front() == std_list.front()); // check if firstelement are equal
	REQUIRE(ft_list.back() == std_list.back()); // check if last element are equal
}
TEST_CASE( "list - erase(pos)", "[list]") {
	ft::list<int> ft_list;
    std::list<int> std_list;
	for (int i = 1; i <= 5; i++) ft_list.push_back(i);
    for (int i = 1; i <= 5; i++) std_list.push_back(i);
	ft::list<int>::iterator ft_pos = ft_list.begin();
    std::list<int>::iterator std_pos = std_list.begin();
    REQUIRE(*ft_pos == 1); // check val 1
    REQUIRE(*std_pos == 1); // check val 1
	ft_list.erase(ft_pos);
	std_list.erase(std_pos);
    REQUIRE(*(ft_list.begin()) != 1); // check val != 1
    REQUIRE(*(std_list.begin()) != 1); // check val != 1
    REQUIRE(ft_list.size() == std_list.size()); // check size
    REQUIRE(ft_list.empty() == std_list.empty()); // check if empty
	REQUIRE(ft_list.front() == std_list.front()); // check if firstelement are equal
	REQUIRE(ft_list.back() == std_list.back()); // check if last element are equal
    // erase last element!!!!!!
    // ft_pos = ft_list.end();
    // std_pos = std_list.end();
    // ft_list.erase(ft_pos);
	// std_list.erase(std_pos);
    // REQUIRE(ft_list.size() == std_list.size()); // check size
    // REQUIRE(ft_list.empty() == std_list.empty()); // check if empty
	// REQUIRE(ft_list.front() == std_list.front()); // check if firstelement are equal
	// REQUIRE(ft_list.back() == std_list.back()); // check if last element are equal
}
TEST_CASE( "list - erase(first, last)", "[list]") {
	ft::list<int> ft_list;
    std::list<int> std_list;
	for (int i = 1; i <= 5; i++) ft_list.push_back(i);
    for (int i = 1; i <= 5; i++) std_list.push_back(i);
	ft::list<int>::iterator ft_first = ft_list.begin();
    std::list<int>::iterator std_first = std_list.begin();
	ft::list<int>::iterator ft_last = ft_list.end();
    std::list<int>::iterator std_last = std_list.end();
    ft_last--;
    std_last--;
    REQUIRE(*ft_first == 1); // check val 1
    REQUIRE(*std_first == 1); // check val 1
	ft_list.erase(ft_first, ft_last);
	std_list.erase(std_first, std_last);
    ft_first = ft_list.begin();
    std_first = std_list.begin();
    REQUIRE(*ft_first == 5); // check val 5
    REQUIRE(*std_first == 5); // check val 5
    REQUIRE(ft_list.size() == std_list.size()); // check size
    REQUIRE(ft_list.empty() == std_list.empty()); // check if empty
	REQUIRE(ft_list.front() == std_list.front()); // check if firstelement are equal
	REQUIRE(ft_list.back() == std_list.back()); // check if last element are equal
}
TEST_CASE( "list - swap", "[list]") {
	ft::list<int> ft_list;
    std::list<int> std_list;
	for (int i = 1; i <= 5; i++) ft_list.push_back(i);
    for (int i = 1; i <= 5; i++) std_list.push_back(i);
	ft::list<int> ft_list2;
    std::list<int> std_list2;
	ft_list.swap(ft_list2);
	std_list.swap(std_list2);
    REQUIRE(ft_list.size() == std_list.size()); // check size
    REQUIRE(ft_list.empty() == std_list.empty()); // check if empty
	REQUIRE(ft_list.front() == std_list.front()); // check if firstelement are equal
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
// OPERATIONS
TEST_CASE( "list - splice(position, x)", "[list]") {
    ft::list<int> ft_list;
    std::list<int> std_list;
	for (int i = 1; i <= 5; i++) ft_list.push_back(i);
    for (int i = 1; i <= 5; i++) std_list.push_back(i);
	ft::list<int> ft_list2;
    std::list<int> std_list2;
    for (int i = 6; i <= 8; i++) ft_list2.push_back(i);
    for (int i = 6; i <= 8; i++) std_list2.push_back(i);
	ft_list.splice(ft_list.end(), ft_list2);
	std_list.splice(std_list.end(), std_list2);
    ft::list<int>::iterator ft_it = ft_list.begin();
    std::list<int>::iterator std_it = std_list.begin();
    REQUIRE(*ft_it == 1); // check if 1
    REQUIRE(*std_it == 1);
    ft_it = ft_list.end();
    std_it = std_list.end();
    ft_it--;
    std_it--;
    REQUIRE(*ft_it == 8); // check if 8
    REQUIRE(*std_it == 8);
    REQUIRE(ft_list.size() == std_list.size()); // check size
    REQUIRE(ft_list.empty() == std_list.empty()); // check if empty
	REQUIRE(ft_list.front() == std_list.front()); // check if firstelement are equal
	REQUIRE(ft_list.back() == std_list.back()); // check if last element are equal
}
TEST_CASE( "list - splice(position, x, i)", "[list]") {
    ft::list<int> ft_list;
    std::list<int> std_list;
	for (int i = 1; i <= 5; i++) ft_list.push_back(i);
    for (int i = 1; i <= 5; i++) std_list.push_back(i);
	ft::list<int> ft_list2;
    std::list<int> std_list2;
    for (int i = 6; i <= 8; i++) ft_list2.push_back(i);
    for (int i = 6; i <= 8; i++) std_list2.push_back(i);
    ft::list<int>::iterator ft_it = ft_list2.begin();
    std::list<int>::iterator std_it = std_list2.begin();
	ft_list.splice(ft_list.end(), ft_list2, ft_it);
	std_list.splice(std_list.end(), std_list2, std_it);
    ft_it = ft_list.begin();
    std_it = std_list.begin();
    REQUIRE(*ft_it == 1); // check if 1
    REQUIRE(*std_it == 1);
    ft_it = ft_list.end();
    std_it = std_list.end();
    ft_it--;
    std_it--;
    REQUIRE(*ft_it == 6); // check if 6
    REQUIRE(*std_it == 6);
    REQUIRE(ft_list.size() == std_list.size()); // check size
    REQUIRE(ft_list.empty() == std_list.empty()); // check if empty
	REQUIRE(ft_list.front() == std_list.front()); // check if firstelement are equal
	REQUIRE(ft_list.back() == std_list.back()); // check if last element are equal
}
TEST_CASE( "list - splice(position, x, first, last)", "[list]") {
    ft::list<int> ft_list;
    std::list<int> std_list;
	for (int i = 1; i <= 5; i++) ft_list.push_back(i);
    for (int i = 1; i <= 5; i++) std_list.push_back(i);
	ft::list<int> ft_list2;
    std::list<int> std_list2;
    for (int i = 6; i <= 8; i++) ft_list2.push_back(i);
    for (int i = 6; i <= 8; i++) std_list2.push_back(i);
    ft::list<int>::iterator ft_first = ft_list2.begin();
    std::list<int>::iterator std_first = std_list2.begin();
    ft::list<int>::iterator ft_last = ft_list2.end();
    std::list<int>::iterator std_last = std_list2.end();
	ft_list.splice(ft_list.end(), ft_list2, ft_first, ft_last);
	std_list.splice(std_list.end(), std_list2, std_first, std_last);
    ft::list<int>::iterator ft_it = ft_list.begin();
    std::list<int>::iterator std_it = std_list.begin();
    REQUIRE(*ft_it == 1); // check if 1
    REQUIRE(*std_it == 1);
    ft_it = ft_list.end();
    std_it = std_list.end();
    ft_it--;
    std_it--;
    REQUIRE(*ft_it == 8); // check if 8
    REQUIRE(*std_it == 8);
    REQUIRE(ft_list.size() == std_list.size()); // check size
    REQUIRE(ft_list.empty() == std_list.empty()); // check if empty
	REQUIRE(ft_list.front() == std_list.front()); // check if firstelement are equal
	REQUIRE(ft_list.back() == std_list.back()); // check if last element are equal
}
TEST_CASE( "list - remove", "[list]") {
	ft::list<int> ft_list;
    std::list<int> std_list;
    for (int i = 0; i < 3; i++) {
        ft_list.push_back(1);
        std_list.push_back(1);
        ft_list.push_back(2);
        std_list.push_back(2);
    }
	ft::list<int>::iterator ft_pos = ft_list.begin();
    std::list<int>::iterator std_pos = std_list.begin();
    REQUIRE(*ft_pos == 1); // check val 1
    REQUIRE(*std_pos == 1); // check val 1
	ft_list.remove(1);
	std_list.remove(1);
    REQUIRE(*(ft_list.begin()) != 1); // check val != 1
    REQUIRE(*(std_list.begin()) != 1); // check val != 1
    REQUIRE(ft_list.size() == std_list.size()); // check size
    REQUIRE(ft_list.empty() == std_list.empty()); // check if empty
	REQUIRE(ft_list.front() == std_list.front()); // check if firstelement are equal
	REQUIRE(ft_list.back() == std_list.back()); // check if last element are equal
}
TEST_CASE( "list - remove_if", "[list]") {
    // find pred at top of file
	ft::list<int> ft_list;
    std::list<int> std_list;
	for (int i = 7; i <= 17; i++) ft_list.push_back(i);
    for (int i = 7; i <= 17; i++) std_list.push_back(i);
	ft_list.remove_if(single_digit);
	std_list.remove_if(single_digit);
    REQUIRE(*(ft_list.end()--) != 17); // check val != 17
    REQUIRE(*(std_list.end()--) != 17); // check val != 17
    REQUIRE(ft_list.size() == std_list.size()); // check size
    REQUIRE(ft_list.empty() == std_list.empty()); // check if empty
	REQUIRE(ft_list.front() == std_list.front()); // check if firstelement are equal
	REQUIRE(ft_list.back() == std_list.back()); // check if last element are equal
    // class
    ft_list.remove_if(is_odd());
	std_list.remove_if(is_odd());
    REQUIRE(*(ft_list.end()--) != 9); // check val != 9
    REQUIRE(*(std_list.end()--) != 9); // check val != 9
    REQUIRE(ft_list.size() == std_list.size()); // check size
    REQUIRE(ft_list.empty() == std_list.empty()); // check if empty
	REQUIRE(ft_list.front() == std_list.front()); // check if firstelement are equal
	REQUIRE(ft_list.back() == std_list.back()); // check if last element are equal
}
TEST_CASE( "list - unique", "[list]") {
	ft::list<int> ft_list;
    std::list<int> std_list;
    ft_list.push_back(1);
    ft_list.push_back(1);
    ft_list.push_back(1);
    ft_list.push_back(2);
    ft_list.push_back(2);
    ft_list.push_back(2);
    std_list.push_back(1);
    std_list.push_back(1);
    std_list.push_back(1);
    std_list.push_back(2);
    std_list.push_back(2);
    std_list.push_back(2);
	ft::list<int>::iterator ft_pos = ft_list.begin();
    std::list<int>::iterator std_pos = std_list.begin();
    REQUIRE(*ft_pos == 1);
    ft_pos++;
    REQUIRE(*ft_pos == 1); // check 1st && 2nd val 1
    REQUIRE(*std_pos == 1);
    std_pos++;
    REQUIRE(*std_pos== 1); // check 1st && 2nd val 1
	ft_list.unique();
	std_list.unique();
    ft_pos = ft_list.begin();
    std_pos = std_list.begin();
    REQUIRE(*ft_pos == 1);
    ft_pos++;
    REQUIRE(*ft_pos != 1); // check 1st 1 && 2nd val != 1
    REQUIRE(*std_pos == 1);
    std_pos++;
    REQUIRE(*std_pos != 1); // check 1st 1 && 2nd val != 1
    REQUIRE(ft_list.size() == std_list.size()); // check size
    REQUIRE(ft_list.empty() == std_list.empty()); // check if empty
	REQUIRE(ft_list.front() == std_list.front()); // check if firstelement are equal
	REQUIRE(ft_list.back() == std_list.back()); // check if last element are equal
}
TEST_CASE( "list - unique(binary_pred)", "[list]") {
    // find pred at top of file
	ft::list<int> ft_list;
    std::list<int> std_list;
    ft_list.push_back(1);
    ft_list.push_back(1);
    ft_list.push_back(1);
    ft_list.push_back(2);
    ft_list.push_back(2);
    ft_list.push_back(2);
    std_list.push_back(1);
    std_list.push_back(1);
    std_list.push_back(1);
    std_list.push_back(2);
    std_list.push_back(2);
    std_list.push_back(2);
	ft_list.unique(same_integral_part);
	std_list.unique(same_integral_part);
    ft::list<int>::iterator ft_pos = ft_list.begin();
    std::list<int>::iterator std_pos = std_list.begin();
    REQUIRE(*ft_pos == 1);
    ft_pos++;
    REQUIRE(*ft_pos != 1); // check 1st 1 && 2nd val != 1
    REQUIRE(*std_pos == 1);
    std_pos++;
    REQUIRE(*std_pos != 1); // check 1st 1 && 2nd val != 1
    REQUIRE(ft_list.size() == std_list.size()); // check size
    REQUIRE(ft_list.empty() == std_list.empty()); // check if empty
	REQUIRE(ft_list.front() == std_list.front()); // check if firstelement are equal
	REQUIRE(ft_list.back() == std_list.back()); // check if last element are equal
    // class
    ft_list.clear();
    std_list.clear();
    ft_list.push_back(1);
    ft_list.push_back(2);
    ft_list.push_back(3);
    std_list.push_back(1);
    std_list.push_back(2);
    std_list.push_back(3);
    ft_list.unique(is_near()); // within 5
	std_list.unique(is_near()); // within 5
    REQUIRE(ft_list.size() == std_list.size()); // check size
    REQUIRE(ft_list.empty() == std_list.empty()); // check if empty
	REQUIRE(ft_list.front() == std_list.front()); // check if firstelement are equal
	REQUIRE(ft_list.back() == std_list.back()); // check if last element are equal
}
TEST_CASE( "list - merge", "[list]") {
    // <
	ft::list<int> ft_list;
    std::list<int> std_list;
    ft::list<int> ft_list2;
    std::list<int> std_list2;
	for (int i = 0; i != 10; i++) {
        if (i % 2 == 0) {
            ft_list.push_back(i);
            std_list.push_back(i);
        }
        else {
            ft_list2.push_back(i);
            std_list.push_back(i);
        }
    }
	ft_list.merge(ft_list2);
	std_list.merge(std_list2);
    REQUIRE(ft_list.size() == std_list.size()); // check size
    REQUIRE(ft_list.empty() == std_list.empty()); // check if empty
	REQUIRE(ft_list.front() == std_list.front()); // check if firstelement are equal
	REQUIRE(ft_list.back() == std_list.back()); // check if last element are equal
    ft_list.clear();
    std_list.clear();
    // Comp
    for (int i = 0; i != 10; i++) {
        if (i % 2 == 0) {
            ft_list.push_back(i);
            std_list.push_back(i);
        }
        else {
            ft_list2.push_back(i);
            std_list.push_back(i);
        }
    }
	ft_list.merge(ft_list2, compare1);
	std_list.merge(std_list2, compare1);
    REQUIRE(ft_list.size() == std_list.size()); // check size
    REQUIRE(ft_list.empty() == std_list.empty()); // check if empty
	REQUIRE(ft_list.front() == std_list.front()); // check if firstelement are equal
	REQUIRE(ft_list.back() == std_list.back()); // check if last element are equal
}
TEST_CASE( "list - sort", "[list]") {
    // <
	ft::list<int> ft_list;
    std::list<int> std_list;
    ft::list<int> ft_list2;
    std::list<int> std_list2;
	for (int i = 0; i != 20; i++) {
        if (i % 2 == 0) {
            ft_list.push_back(i);
            std_list.push_back(i);
        }
        else {
            ft_list2.push_back(i);
            std_list.push_back(i);
        }
    }
	ft_list.splice(ft_list.begin(), ft_list2);
	std_list.splice(std_list.begin(), std_list2);
    ft_list.sort();
    std_list.sort();
    REQUIRE(ft_list.size() == std_list.size()); // check size
    REQUIRE(ft_list.empty() == std_list.empty()); // check if empty
	REQUIRE(ft_list.front() == std_list.front()); // check if firstelement are equal
	REQUIRE(ft_list.back() == std_list.back()); // check if last element are equal
    // comp
    ft_list.clear();
    ft_list2.clear();
    std_list.clear();
    std_list2.clear();
	for (int i = 0; i != 20; i++) {
        if (i % 2 == 0) {
            ft_list.push_back(i);
            std_list.push_back(i);
        }
        else {
            ft_list2.push_back(i);
            std_list.push_back(i);
        }
    }
    ft_list.splice(ft_list.begin(), ft_list2);
	std_list.splice(std_list.begin(), std_list2);
    ft_list.sort(compare1);
    std_list.sort(compare1);
    REQUIRE(ft_list.size() == std_list.size()); // check size
    REQUIRE(ft_list.empty() == std_list.empty()); // check if empty
	REQUIRE(ft_list.front() == std_list.front()); // check if firstelement are equal
	REQUIRE(ft_list.back() == std_list.back()); // check if last element are equal
}
TEST_CASE( "list - reverse", "[list]") {
    ft::list<int> ft_list;
    std::list<int> std_list;
	for (int i = 1; i <= 17; i++) ft_list.push_back(i);
    for (int i = 1; i <= 17; i++) std_list.push_back(i);
    ft_list.reverse();
    std_list.reverse();
    REQUIRE(ft_list.size() == std_list.size()); // check size
    REQUIRE(ft_list.empty() == std_list.empty()); // check if empty
	REQUIRE(ft_list.front() == std_list.front()); // check if firstelement are equal
	REQUIRE(ft_list.back() == std_list.back()); // check if last element are equal
}
// OBSERVERS
TEST_CASE("list - get_allocator", "[list]")
{
	ft::list<int> ft_list;
	std::list<int> std_list;
	int *p_ft_list;
	int *p_std_list;
	bool ft_list_return = false;
	bool std_list_return = false;
	// allocate for 5 elements using list's allocator:
  	p_ft_list = ft_list.get_allocator().allocate(5);
  	p_std_list = std_list.get_allocator().allocate(5);
	if (!p_ft_list)
		ft_list_return = false;
	else
		ft_list_return = true;
	if (!p_std_list)
		std_list_return = false;
	else
		std_list_return = true;
	REQUIRE(ft_list_return == std_list_return);
}
// RELATIONAL OPERATORS
TEST_CASE("list - relational operators", "[list]")
{
	ft::list<int> ft_list(4, 200);
	ft::list<int> ft_list2(4, 100);
	ft::list<int> ft_list3(4, 200);
	std::list<int> std_list(4, 200);
	std::list<int> std_list2(4, 100);
	std::list<int> std_list3(4, 200);
	REQUIRE((ft_list == ft_list3) == true); // ==
	REQUIRE((ft_list == ft_list2) == false);
	REQUIRE((std_list == std_list3) == true);
	REQUIRE((std_list == std_list2) == false);
	REQUIRE((ft_list != ft_list3) == false); // !=
	REQUIRE((ft_list != ft_list2) == true);
	REQUIRE((std_list != std_list3) == false);
	REQUIRE((std_list != std_list2) == true);
	REQUIRE((ft_list < ft_list2) == false); // <
	REQUIRE((ft_list2 < ft_list3) == true);
	REQUIRE((std_list < std_list2) == false);
	REQUIRE((std_list2 < std_list3) == true);
	REQUIRE((ft_list < ft_list3) == false);
	REQUIRE((ft_list <= ft_list3) == true); // <=
	REQUIRE((std_list < std_list3) == false);
	REQUIRE((std_list <= std_list3) == true);
	REQUIRE((ft_list > ft_list2) == true); // >
	REQUIRE((ft_list2 > ft_list3) == false);
	REQUIRE((std_list > std_list2) == true);
	REQUIRE((std_list2 > std_list3) == false);
	REQUIRE((ft_list > ft_list3) == false);
	REQUIRE((ft_list >= ft_list3) == true);  // >=
	REQUIRE((std_list > std_list3) == false);
	REQUIRE((std_list >= std_list3) == true);
}
// SWAP
TEST_CASE("list - swap(x, y)", "[list]")
{
    ft::list<int> ft_list;
    std::list<int> std_list;
    ft::list<int> ft_check;
    std::list<int> std_check;
	for (int i = 1; i <= 5; i++) ft_list.push_back(i);
    for (int i = 1; i <= 5; i++) std_list.push_back(i);
    ft_check = ft_list;
    std_check = std_list;
	ft::list<int> ft_list2;
    std::list<int> std_list2;
	ft::swap(ft_list, ft_list2);
    std::swap(std_list, std_list2);
	REQUIRE(ft_list.size() == std_list.size()); // check if size equal
	REQUIRE(ft_list2 == ft_check); // check if equal
	REQUIRE(std_list2 == std_check); // check if equal
}