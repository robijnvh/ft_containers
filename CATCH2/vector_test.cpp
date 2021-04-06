#include "catch.hpp"
 
#include <vector>
#include "../includes/vector.hpp"

// CONSTRUCTORS // COPLIEN
TEST_CASE( "vector - default constructor", "[vector]" ) {
    ft::vector<int> ft_vector;
    std::vector<int> std_vector;
    REQUIRE(ft_vector.size() == std_vector.size()); // empty vectr
}
TEST_CASE( "vector - fill constructor", "[vector]" ) {
    ft::vector<int> ft_vector(5, 100);
	std::vector<int> std_vector(5, 100);
    REQUIRE(ft_vector.size() == std_vector.size()); // vector with n amount of value
}
TEST_CASE( "vector - range constructor", "[vector]" ) {
    ft::vector<int> ft_test(5, 100);
    ft::vector<int> ft_vector(ft_test.begin(),ft_test.end());
    REQUIRE(ft_vector.size() == 5);
    REQUIRE(ft_vector.capacity() == 5); // vector first-last
}
TEST_CASE( "vector - copy constructor", "[vector]" ) {
    ft::vector<int> ft_test(5, 100);
    ft::vector<int> ft_vector(ft_test);
    REQUIRE(ft_test.size() == ft_vector.size()); // vector copied from excisting
}
TEST_CASE( "vector - assignation operator", "[vector]" ) {
    ft::vector<int> ft_test(5, 100);
    ft::vector<int> ft_vector;
    ft_vector = ft_test;
    REQUIRE(ft_vector.size() == ft_test.size()); // vector set from excisting
}
// ITERATORS
TEST_CASE( "vector - begin", "[vector]" ) {
    ft::vector<int> ft_vector;
    std::vector<int> std_vector;
	for (int i = 1; i <= 7; i++) ft_vector.push_back(i);
    for (int i = 1; i <= 7; i++) std_vector.push_back(i);
    REQUIRE(*ft_vector.begin() == *std_vector.begin()); // it_ptr to first element
}
TEST_CASE( "vector - const begin", "[vector]" ) {
    ft::vector<int> ft_vector;
    std::vector<int> std_vector;
	for (int i = 1; i <= 7; i++) ft_vector.push_back(i);
    for (int i = 1; i <= 7; i++) std_vector.push_back(i);
	ft::vector<int>::const_iterator ft_it = ft_vector.begin();
	std::vector<int>::const_iterator std_it = std_vector.begin();
    REQUIRE(*ft_it == *std_it); // it_ptr to first element 
}
TEST_CASE( "vector - end", "[vector]" ) {
    ft::vector<int> ft_vector;
    std::vector<int> std_vector;
	for (int i = 1; i <= 7; i++) ft_vector.push_back(i);
    for (int i = 1; i <= 7; i++) std_vector.push_back(i);
    REQUIRE(*(ft_vector.end() - 1) == *(std_vector.end() - 1)); // it_ptr to element preceding .end()
}
TEST_CASE( "vector - const end", "[vector]" ) {
    ft::vector<int> ft_vector;
    std::vector<int> std_vector;
	for (int i = 1; i <= 7; i++) ft_vector.push_back(i);
    for (int i = 1; i <= 7; i++) std_vector.push_back(i);
	ft::vector<int>::const_iterator ft_it = ft_vector.end();
	std::vector<int>::const_iterator std_it = std_vector.end();
	ft_it--;
	std_it--;
    REQUIRE(*ft_it == *std_it); // it_ptr to element preceding .end()
}
TEST_CASE( "vector - rbegin", "[vector]" ) {
    ft::vector<int> ft_vector;
    std::vector<int> std_vector;
	for (int i = 1; i <= 7; i++) ft_vector.push_back(i);
    for (int i = 1; i <= 7; i++) std_vector.push_back(i);
    REQUIRE(*ft_vector.rbegin() == *std_vector.rbegin()); // rev_it_ptr to last element
}
TEST_CASE( "vector - const rbegin", "[vector]" ) {
    ft::vector<int> ft_vector;
    std::vector<int> std_vector;
	for (int i = 1; i <= 7; i++) ft_vector.push_back(i);
    for (int i = 1; i <= 7; i++) std_vector.push_back(i);
	ft::vector<int>::const_reverse_iterator ft_it = ft_vector.rbegin();
	std::vector<int>::const_reverse_iterator std_it = std_vector.rbegin();
    REQUIRE(*ft_it == *std_it); // rev_it_ptr to last element
}
TEST_CASE( "vector - rend", "[vector]" ) {
    ft::vector<int> ft_vector;
    std::vector<int> std_vector;
	for (int i = 1; i <= 7; i++) ft_vector.push_back(i);
    for (int i = 1; i <= 7; i++) std_vector.push_back(i);
    REQUIRE(*(ft_vector.end() - 1) == *(std_vector.end() - 1)); // rev_it_ptr to element preceding the theoretical element
}
TEST_CASE( "vector - const rend", "[vector]" ) {
    ft::vector<int> ft_vector;
    std::vector<int> std_vector;
	for (int i = 1; i <= 7; i++) ft_vector.push_back(i);
    for (int i = 1; i <= 7; i++) std_vector.push_back(i);
	ft::vector<int>::const_reverse_iterator ft_it = ft_vector.rend();
	std::vector<int>::const_reverse_iterator std_it = std_vector.rend();
	ft_it--;
	std_it--;
    REQUIRE(*ft_it == *std_it); // rev_it_ptr to element preceding the theoretical element
}
// CAPACITY
TEST_CASE( "vector - size", "[vector]" ) {
    ft::vector<int> ft_vector;
    std::vector<int> std_vector;
    REQUIRE(ft_vector.size() == std_vector.size()); // non excisting size
    for (int i = 1; i <= 7; i++) ft_vector.push_back(i);
    for (int i = 1; i <= 7; i++) std_vector.push_back(i);
    REQUIRE(ft_vector.size() == std_vector.size()); // excisting size
}
TEST_CASE( "vector - max_size", "[vector]" ) {
    ft::vector<int> ft_vector;
    std::vector<int> std_vector;
    REQUIRE(ft_vector.max_size() == std_vector.max_size()); // check max_size
}
TEST_CASE( "vector - resize", "[vector]" ) {
    ft::vector<int> ft_vector;
    for (int i = 1; i <= 20; i++) ft_vector.push_back(i);
    ft_vector.resize(20);
    REQUIRE(ft_vector.size() == 20); // equal
    ft_vector.resize(10);
    REQUIRE(ft_vector.size() == 10); // less
    ft_vector.resize(15);
    REQUIRE(ft_vector.size() == 15); // more
    ft_vector.resize(1);
    REQUIRE(ft_vector.size() == 1); // less
}
TEST_CASE( "vector - capacity", "[vector]" ) {
    ft::vector<int> ft_vector;
    std::vector<int> std_vector;
    REQUIRE(ft_vector.capacity() == std_vector.capacity()); // non excisting capacity
    for (int i = 1; i <= 5; i++) ft_vector.push_back(i);
    for (int i = 1; i <= 5; i++) std_vector.push_back(i);
    REQUIRE(ft_vector.capacity() == std_vector.capacity()); // excisting capacity
}
TEST_CASE( "vector - empty", "[vector]" ) {
    ft::vector<int> ft_vector;
    std::vector<int> std_vector;
    REQUIRE(ft_vector.empty() == std_vector.empty()); // true
    for (int i = 1; i <= 5; i++) ft_vector.push_back(i);
    for (int i = 1; i <= 5; i++) std_vector.push_back(i);
    REQUIRE(ft_vector.empty() == std_vector.empty()); // false
}
TEST_CASE( "vector - reserve", "[vector]") {
	ft::vector<int> ft_vector;
    std::vector<int> std_vector;
	ft_vector.reserve(5);
	std_vector.reserve(5);
    REQUIRE(ft_vector.capacity() == std_vector.capacity()); // more
	ft_vector.reserve(2);
	std_vector.reserve(2);
    REQUIRE(ft_vector.capacity() == std_vector.capacity()); // less
	ft_vector.reserve(2);
	std_vector.reserve(2);
    REQUIRE(ft_vector.capacity() == std_vector.capacity()); // equal
}
TEST_CASE( "vector - shrink_to_fit", "[vector]") {
	ft::vector<int> ft_vector;
    std::vector<int> std_vector;
	ft_vector.reserve(10);
	std_vector.reserve(10);
	ft_vector.shrink_to_fit();
	std_vector.shrink_to_fit();
    REQUIRE(ft_vector.capacity() == std_vector.capacity()); // size of 0
	for (int i = 1; i <= 5; i++) ft_vector.push_back(i);
    for (int i = 1; i <= 5; i++) std_vector.push_back(i);
	ft_vector.reserve(7);
	std_vector.reserve(7);
	ft_vector.shrink_to_fit();
	std_vector.shrink_to_fit();
    REQUIRE(ft_vector.capacity() == std_vector.capacity()); // size of 5
}
// ELEMENT ACCESS
TEST_CASE( "vector - operator[]", "[vector]") {
	ft::vector<int> ft_vector;
    std::vector<int> std_vector;
	for (int i = 1; i <= 5; i++) ft_vector.push_back(i);
    for (int i = 1; i <= 5; i++) std_vector.push_back(i);
    REQUIRE(ft_vector[1] == std_vector[1]); // access element
}
TEST_CASE( "vector - const operator[]", "[vector]") {
	ft::vector<int> const ft_vector(3, 3);
    std::vector<int> const std_vector(3, 3);
    REQUIRE(ft_vector[1] == std_vector[1]); // access element
}
TEST_CASE( "vector - at", "[vector]") {
	ft::vector<int> ft_vector(3, 3);
    std::vector<int> std_vector(3, 3);
    REQUIRE(ft_vector.at(1) == std_vector.at(1)); // check bounds excisting position
    // REQUIRE(ft_vector.at(5) == std_vector.at(5)); // check bounds non excisting position
}
TEST_CASE( "vector - const at", "[vector]") {
	ft::vector<int> const ft_vector(3, 3);
    std::vector<int> const std_vector(3, 3);
    REQUIRE(ft_vector.at(1) == std_vector.at(1)); // check bounds excisting position
    // REQUIRE(ft_vector.at(5) == std_vector.at(5)); // check bounds non excisting position
}
TEST_CASE( "vector - front", "[vector]") {
	ft::vector<int> ft_vector(3, 3);
    std::vector<int> std_vector(3, 3);
    REQUIRE(ft_vector.front() == std_vector.front()); // ref to first element
}
TEST_CASE( "vector - const front", "[vector]") {
	ft::vector<int> const ft_vector(3, 3);
    std::vector<int> const std_vector(3, 3);
    REQUIRE(ft_vector.front() == std_vector.front()); // ref to first element
}
TEST_CASE( "vector - back", "[vector]") {
	ft::vector<int> ft_vector(3, 3);
    std::vector<int> std_vector(3, 3);
    REQUIRE(ft_vector.back() == std_vector.back()); // ref to last element
}
TEST_CASE( "vector - const back", "[vector]") {
	ft::vector<int> const ft_vector(3, 3);
    std::vector<int> const std_vector(3, 3);
    REQUIRE(ft_vector.back() == std_vector.back()); // ref to last element
}
// MODIFIERS
TEST_CASE( "vector - assign(first, last)", "[vector]") { // klopt nog niet helemaal!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    // INT
	ft::vector<int> ft_vector(3, 3);
	ft::vector<int> ft_test(2, 2);
    std::vector<int> std_vector(3, 3);
    std::vector<int> std_test(2, 2);
	ft::vector<int>::iterator ft_first = ft_test.begin();
    std::vector<int>::iterator std_first = std_test.begin();
	ft::vector<int>::iterator ft_last = ft_test.end() - 1;
    std::vector<int>::iterator std_last = std_test.end() - 1;
	ft_vector.assign(ft_first, ft_last);
	std_vector.assign(std_first, std_last);
	REQUIRE(ft_vector[0] != 3); // check if assigned
	REQUIRE(ft_vector[0] == std_vector[0]); // check if elements are equal
	REQUIRE(ft_vector[1] == std_vector[1]); // check if elements are equal
    // STRING
    // ft::vector<std::string> ft_vector;
    // std::vector<std::string> std_vector;
    // ft_vector.push_back("Hello");
    // ft_vector.push_back("World");
    // ft_vector.push_back("Bye");
    // ft_vector.push_back("!");
    // std_vector.push_back("Hello");
    // std_vector.push_back("World");
    // std_vector.push_back("Bye");
    // std_vector.push_back("!");
    // ft::vector<std::string>::iterator ft_first = ft_vector.begin();
    // std::vector<std::string>::iterator std_first = std_vector.begin();
	// ft::vector<std::string>::iterator ft_last = ft_vector.end() - 1;
    // std::vector<std::string>::iterator std_last = std_vector.end() - 1;
	// ft::vector<std::string> ft_test;
    // std::vector<std::string> std_test;
	// ft_test.assign(ft_first, ft_last);
	// std_test.assign(std_first, std_last);
    // REQUIRE(ft_test.size() != 0); // check if assigned
    // REQUIRE(ft_test[0] == std_test[0]); // check if elements equal 0
    // REQUIRE(ft_test[1] == std_test[1]); // check if elements equal 1
    // REQUIRE(ft_test[3] == std_test[3]); // check if elements equal 3
}
TEST_CASE( "vector - assign(const first, const last)", "[vector]") { // klopt nog niet helemaal!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	ft::vector<int> ft_vector(3, 3);
	ft::vector<int> ft_test(2, 2);
    std::vector<int> std_vector(3, 3);
    std::vector<int> std_test(2, 2);
	ft::vector<int>::const_iterator ft_first = ft_test.begin();
    std::vector<int>::const_iterator std_first = std_test.begin();
	ft::vector<int>::const_iterator ft_last = ft_test.end() - 1;
    std::vector<int>::const_iterator std_last = std_test.end() - 1;
	ft_vector.assign(ft_first, ft_last);
	std_vector.assign(std_first, std_last);
	REQUIRE(ft_vector[0] != 3); // check if assigned
	REQUIRE(ft_vector[0] == std_vector[0]); // check if elements are equal
	REQUIRE(ft_vector[1] == std_vector[1]); // check if elements are equal
}
TEST_CASE( "vector - assign(n, value)", "[vector]") {
	ft::vector<int> ft_vector(3, 3);
    std::vector<int> std_vector(3, 3);
	ft_vector.assign(5, 5);
	std_vector.assign(5, 5);
	REQUIRE(ft_vector.front() == std_vector.front()); // check if firstelement are equal
	REQUIRE(ft_vector.back() == std_vector.back()); // check if last element are equal
}
TEST_CASE( "vector - push_back", "[vector]") {
	ft::vector<int> ft_vector;
    std::vector<int> std_vector;
	for (int i = 1; i <= 5; i++) ft_vector.push_back(i);
    for (int i = 1; i <= 5; i++) std_vector.push_back(i);
	REQUIRE(ft_vector.front() == std_vector.front()); // check if firstelement are equal
	REQUIRE(ft_vector.back() == std_vector.back()); // check if last element are equal
}
TEST_CASE( "vector - pop_back", "[vector]") {
	ft::vector<int> ft_vector;
    std::vector<int> std_vector;
	for (int i = 1; i <= 5; i++) ft_vector.push_back(i);
    for (int i = 1; i <= 5; i++) std_vector.push_back(i);
	REQUIRE(ft_vector.back() == std_vector.back()); // check if last element are equal
	ft_vector.pop_back();
	std_vector.pop_back();
	REQUIRE(ft_vector.back() == std_vector.back()); // check if last element are equal
}
TEST_CASE( "vector - insert(pos, value)", "[value]") { // klopt nog niet helemaal!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	ft::vector<int> ft_vector(3, 3);
    std::vector<int> std_vector(3, 3);
	ft::vector<int>::iterator ft_it = ft_vector.begin();
    std::vector<int>::iterator std_it = std_vector.begin();
	ft_vector.insert(ft_it, 1);
	std_vector.insert(std_it, 1);
	REQUIRE(ft_vector[0] != 3); // check if inserted
	REQUIRE(ft_vector[0] == std_vector[0]); // check if elements are equal
}
TEST_CASE( "vector - insert(pos, n, value)", "[value]") { // klopt nog niet helemaal!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	ft::vector<int> ft_vector(3, 3);
    std::vector<int> std_vector(3, 3);
	ft::vector<int>::iterator ft_it = ft_vector.begin();
    std::vector<int>::iterator std_it = std_vector.begin();
	ft_vector.insert(ft_it, 2, 1);
	std_vector.insert(std_it, 2, 1);
	REQUIRE(ft_vector[0] != 3); // check if inserted
	REQUIRE(ft_vector[1] != 3); // check if inserted
	REQUIRE(ft_vector[0] == std_vector[0]); // check if elements are equal
	REQUIRE(ft_vector[1] == std_vector[1]); // check if elements are equal
}
TEST_CASE( "vector - insert(pos, first, last)", "[value]") { // klopt nog niet helemaal!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	ft::vector<int> ft_vector(3, 3);
	ft::vector<int> ft_test(2, 2);
    std::vector<int> std_vector(3, 3);
    std::vector<int> std_test(2, 2);
	ft::vector<int>::iterator ft_pos = ft_vector.begin();
    std::vector<int>::iterator std_pos = std_vector.begin();
	ft::vector<int>::iterator ft_first = ft_test.begin();
    std::vector<int>::iterator std_first = std_test.begin();
	ft::vector<int>::iterator ft_last = ft_test.end() - 1;
    std::vector<int>::iterator std_last = std_test.end() - 1;
	ft_vector.insert(ft_pos, ft_first, ft_last);
	std_vector.insert(std_pos, std_first, std_last);
	REQUIRE(ft_vector[0] != 3); // check if inserted
	REQUIRE(ft_vector[0] == std_vector[0]); // check if elements are equal
	REQUIRE(ft_vector[1] == std_vector[1]); // check if elements are equal
	REQUIRE(ft_vector[2] == std_vector[2]); // check if elements are equal
}
TEST_CASE( "vector - erase(pos)", "[value]") {
	ft::vector<int> ft_vector;
    std::vector<int> std_vector;
	for (int i = 1; i <= 5; i++) ft_vector.push_back(i);
    for (int i = 1; i <= 5; i++) std_vector.push_back(i);
	ft::vector<int>::iterator ft_pos = ft_vector.begin();
    std::vector<int>::iterator std_pos = std_vector.begin();
	ft_vector.erase(ft_pos);
	std_vector.erase(std_pos);
	REQUIRE(ft_vector[0] != 1); // check if erased
	REQUIRE(ft_vector[0] == std_vector[0]); // check if elements are equal
}
TEST_CASE( "vector - erase(first, last)", "[value]") {
	ft::vector<int> ft_vector;
    std::vector<int> std_vector;
	for (int i = 1; i <= 5; i++) ft_vector.push_back(i);
    for (int i = 1; i <= 5; i++) std_vector.push_back(i);
	ft::vector<int>::iterator ft_first = ft_vector.begin();
    std::vector<int>::iterator std_first = std_vector.begin();
	ft::vector<int>::iterator ft_last = ft_vector.end() - 2;
    std::vector<int>::iterator std_last = std_vector.end() - 2;
	ft_vector.erase(ft_first, ft_last);
	std_vector.erase(std_first, std_last);
	REQUIRE(ft_vector[0] != 1); // check if erased
	REQUIRE(ft_vector[0] == std_vector[0]); // check if elements are equal
}
TEST_CASE( "vector - swap", "[vector]") {
	ft::vector<int> ft_vector;
    std::vector<int> std_vector;
	for (int i = 1; i <= 5; i++) ft_vector.push_back(i);
    for (int i = 1; i <= 5; i++) std_vector.push_back(i);
	ft::vector<int> ft_vector2;
    std::vector<int> std_vector2;
	ft_vector.swap(ft_vector2);
	std_vector.swap(std_vector2);
	REQUIRE(ft_vector.size() == std_vector.size()); // check if size equal
}
TEST_CASE( "vector - clear", "[vector]") {
	ft::vector<int> ft_vector(10, 1);
    std::vector<int> std_vector(10, 1);
	ft_vector.clear();
	std_vector.clear();
	REQUIRE(ft_vector.size() == std_vector.size()); // check if size equal
}
