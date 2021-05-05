#include "catch.hpp"

#include <map>
#include <string>
#include "../includes/map.hpp"
#include <iostream> // to print

// compare function
bool fncomp (char lhs, char rhs) {return lhs<rhs;}
// compare class
struct classcomp {
  bool operator() (const char& lhs, const char& rhs) const
  {return lhs<rhs;}
};
// COPLIEN
TEST_CASE( "map - default constructor", "[map]" ) {
  ft::map<int, int> ft_map;
  std::map<int, int> std_map;
  REQUIRE(ft_map.empty() == true); // empty map
  REQUIRE(ft_map.empty() == std_map.empty());
  REQUIRE(ft_map.size() == std_map.size()); // check size
}
TEST_CASE( "map - range constructor", "[map]" ) {
  ft::map<int, int> ft_test;
  std::map<int, int> std_test;
  for (int i = 0; i != 10; i++) ft_test.insert(ft::pair<int,int>(i,1));
  for (int i = 0; i != 10; i++) std_test.insert(std::pair<int,int>(i,1));
  ft::map<int, int> ft_map(ft_test.begin(), ft_test.end());
  std::map<int, int> std_map(std_test.begin(), std_test.end());
  REQUIRE(ft_map.empty() == std_map.empty());
  REQUIRE(ft_map.size() == std_map.size());
}
TEST_CASE( "map - copy constructor", "[map]" ) {
  ft::map<int, int> ft_test2;
  std::map<int, int> std_test2;
  for (int i = 0; i != 10; i++) ft_test2.insert(ft::pair<int,int>(i,1));
  for (int i = 0; i != 10; i++) std_test2.insert(std::pair<int,int>(i,1));
  ft::map<int, int> ft_map(ft_test2);
  std::map<int, int> std_map(std_test2);
  REQUIRE(ft_map.size() == std_map.size()); // map copied from excisting
  REQUIRE(ft_map.empty() == std_map.empty()); 
}
TEST_CASE( "map - assignation operator", "[map]" ) {
  ft::map<int, int> ft_test;
  for (int i = 0; i != 10; i++) ft_test.insert(ft::pair<int,int>(i,1));
  ft::map<int, int> ft_map;
  ft_map = ft_test;
  REQUIRE(ft_map.size() == ft_test.size()); // map set from excisting
  REQUIRE(ft_map.empty() == ft_test.empty()); 
}
// ITERATORS
TEST_CASE( "map - begin", "[map]" ) {
  ft::map<int, int> ft_map;
  std::map<int, int> std_map;
	for (int i = 1; i <= 7; i++) ft_map.insert(ft::pair<int,int>(i,1));
	for (int i = 1; i <= 7; i++) std_map.insert(std::pair<int,int>(i,1));
  ft::map<int, int>::iterator ft_it = ft_map.begin();
  std::map<int, int>::iterator std_it = std_map.begin();
  REQUIRE(ft_it->first == std_it->first); // first element
}
TEST_CASE( "map - const begin", "[map]" ) {
  ft::map<int, int> ft_map;
  std::map<int, int> std_map;
	for (int i = 1; i <= 7; i++) ft_map.insert(ft::pair<int,int>(i,1));
	for (int i = 1; i <= 7; i++) std_map.insert(std::pair<int,int>(i,1));
  ft::map<int, int>::const_iterator ft_it = ft_map.begin();
  std::map<int, int>::const_iterator std_it = std_map.begin();
  REQUIRE(ft_it->first == std_it->first); // first element
}
TEST_CASE( "map - end", "[map]" ) {
  ft::map<int, int> ft_map;
  std::map<int, int> std_map;
	for (int i = 1; i <= 7; i++) ft_map.insert(ft::pair<int,int>(i,1));
	for (int i = 1; i <= 7; i++) std_map.insert(std::pair<int,int>(i,1));
  ft::map<int, int>::iterator ft_it = ft_map.end();
  std::map<int, int>::iterator std_it = std_map.end();
  ft_it--;
  std_it--;
  REQUIRE(ft_it->first == std_it->first); // prev last element
}
TEST_CASE( "map - const end", "[map]" ) {
  ft::map<int, int> ft_map;
  std::map<int, int> std_map;
	for (int i = 1; i <= 7; i++) ft_map.insert(ft::pair<int,int>(i,1));
	for (int i = 1; i <= 7; i++) std_map.insert(std::pair<int,int>(i,1));
  ft::map<int, int>::const_iterator ft_it = ft_map.end();
  std::map<int, int>::const_iterator std_it = std_map.end();
  ft_it--;
  std_it--;
  REQUIRE(ft_it->first == std_it->first); // prev last element
}
TEST_CASE( "map - rbegin", "[map]" ) {
  ft::map<int, int> ft_map;
  std::map<int, int> std_map;
	for (int i = 1; i <= 7; i++) ft_map.insert(ft::pair<int,int>(i,1));
	for (int i = 1; i <= 7; i++) std_map.insert(std::pair<int,int>(i,1));
  ft::map<int, int>::reverse_iterator ft_it = ft_map.rbegin();
  std::map<int, int>::reverse_iterator std_it = std_map.rbegin();
  REQUIRE(ft_it->first == std_it->first); // last element
}
TEST_CASE( "map - const rbegin", "[map]" ) {
  ft::map<int, int> ft_map;
  std::map<int, int> std_map;
	for (int i = 1; i <= 7; i++) ft_map.insert(ft::pair<int,int>(i,1));
	for (int i = 1; i <= 7; i++) std_map.insert(std::pair<int,int>(i,1));
  ft::map<int, int>::const_reverse_iterator ft_it = ft_map.rbegin();
  std::map<int, int>::const_reverse_iterator std_it = std_map.rbegin();
  REQUIRE(ft_it->first == std_it->first); // last element
}
TEST_CASE( "map - rend", "[map]" ) {
  ft::map<int, int> ft_map;
  std::map<int, int> std_map;
	for (int i = 1; i <= 7; i++) ft_map.insert(ft::pair<int,int>(i,1));
	for (int i = 1; i <= 7; i++) std_map.insert(std::pair<int,int>(i,1));
  ft::map<int, int>::reverse_iterator ft_it = ft_map.rend();
  std::map<int, int>::reverse_iterator std_it = std_map.rend();
  ft_it--;
  std_it--;
  REQUIRE(ft_it->first == std_it->first); // first element
}
TEST_CASE( "map - const rend", "[map]" ) {
  ft::map<int, int> ft_map;
  std::map<int, int> std_map;
	for (int i = 1; i <= 7; i++) ft_map.insert(ft::pair<int,int>(i,1));
	for (int i = 1; i <= 7; i++) std_map.insert(std::pair<int,int>(i,1));
  ft::map<int, int>::const_reverse_iterator ft_it = ft_map.rend();
  std::map<int, int>::const_reverse_iterator std_it = std_map.rend();
  ft_it--;
  std_it--;
  REQUIRE(ft_it->first == std_it->first); // first element
}
// CAPACITY
TEST_CASE( "map - empty", "[map]" ) {
  ft::map<int, int> ft_map;
  std::map<int, int> std_map;
  REQUIRE(ft_map.empty() == std_map.empty()); // true
  for (int i = 0; i != 10; i++) ft_map.insert(ft::pair<int,int>(i,1));
  for (int i = 0; i != 10; i++) std_map.insert(std::pair<int,int>(i,1));
  REQUIRE(ft_map.empty() == std_map.empty()); // false
}
TEST_CASE( "map - size", "[map]" ) {
  ft::map<int, int> ft_map;
  std::map<int, int> std_map;
  REQUIRE(ft_map.size() == std_map.size()); // 0
  for (int i = 0; i != 10; i++) ft_map.insert(ft::pair<int,int>(i,1));
  for (int i = 0; i != 10; i++) std_map.insert(std::pair<int,int>(i,1));
  REQUIRE(ft_map.size() == std_map.size()); // 10
}
TEST_CASE( "map - max_size", "[map]" ) { // !!!!!!!!!!!!!!!!!!!!!!!!
  ft::map<int, int> ft_map;
  std::map<int, int> std_map;
  REQUIRE(ft_map.max_size() != 0); // 10
  // REQUIRE(ft_map.max_size() == std_map.max_size()); // 10
}
// ELEMENT ACCESS
TEST_CASE( "map - operator[]", "[map]" ) {
  ft::map<int, int> ft_map;
  std::map<int, int> std_map;
  REQUIRE(ft_map.empty() == std_map.empty()); // true
  for (int i = 0; i != 10; i++) ft_map.insert(ft::pair<int,int>(i,1));
  for (int i = 0; i != 10; i++) std_map.insert(std::pair<int,int>(i,1));
  REQUIRE(ft_map.empty() == std_map.empty()); // false
  REQUIRE(ft_map[1] == std_map[1]);
  REQUIRE(ft_map[6] == std_map[6]);
  REQUIRE(ft_map[9] == std_map[9]);
  // ft_map.print_tree();
  REQUIRE(ft_map[10] == std_map[10]);
  REQUIRE(ft_map.size() == std_map.size());
}
// MODIFIERS
TEST_CASE( "map - insert(val)", "[map]" ) {
  // MY MAP
  ft::map<int, int> ft_map;
  std::map<int, int> std_map;

  SECTION ("tests") {
    ft_map.insert(ft::pair<int,int>(3,300));
    ft_map.insert(ft::pair<int,int>(1,100));
    ft_map.insert(ft::pair<int,int>(8,800));
    ft_map.insert(ft::pair<int,int>(5,500));
    ft_map.insert(ft::pair<int,int>(9,900));
    ft_map.insert(ft::pair<int,int>(10,1000));
    ft_map.insert(ft::pair<int,int>(2,200));
    ft_map.insert(ft::pair<int,int>(6,600));
    ft_map.print_tree();
    std::cout << "Insert 7 to cause imbalance:" << std::endl;
    ft_map.insert(ft::pair<int,int>(7,700));
    ft_map.print_tree();
    std::cout << "Insert 11 to cause imbalance:" << std::endl;
    ft_map.print_tree();
    ft_map.insert(ft::pair<int,int>(11,1100));
    ft_map.print_tree();
    ft_map.insert(ft::pair<int,int>(12,1200));
    std::cout << "Insert 13 to cause imbalance:" << std::endl;
    ft_map.print_tree();
    ft_map.insert(ft::pair<int,int>(13,1300));
    ft_map.print_tree();
    // STD MAP
    std::map<int, int> std_map;
    std_map.insert(std::pair<int,int>(3,300));
    std_map.insert(std::pair<int,int>(1,100));
    std_map.insert(std::pair<int,int>(8,800));
    std_map.insert(std::pair<int,int>(5,500));
    std_map.insert(std::pair<int,int>(9,900));
    std_map.insert(std::pair<int,int>(10,1000));
    std_map.insert(std::pair<int,int>(2,200));
    std_map.insert(std::pair<int,int>(6,600));
    std_map.insert(std::pair<int,int>(7,700));
    std_map.insert(std::pair<int,int>(11,1100));
    std_map.insert(std::pair<int,int>(12,1200));
    std_map.insert(std::pair<int,int>(13,1300));
    std::cout << "Insert AVL tree:" << std::endl;
    REQUIRE(ft_map.empty() == std_map.empty());
    REQUIRE(ft_map.size() == std_map.size());
  }
  // check double
  SECTION ("check double") {
    ft_map.insert(ft::pair<int,int>(40,1));
    std_map.insert(std::pair<int,int>(40,1));
    ft_map.print_tree();
    std::cout << "Insert AVL tree:" << std::endl;
    ft_map.insert(ft::pair<int,int>(40,300));
    std_map.insert(std::pair<int,int>(40,300));
    std::cout << "Inserting 40 again to check for double:" << std::endl;
    ft_map.print_tree();
    REQUIRE(ft_map.size() == std_map.size()); // size
    REQUIRE(ft_map.empty() == std_map.empty()); // empty
	}
}
TEST_CASE( "map - erase(position)", "[map]" ) { // ptr becomes invalid
  ft::map<int, int> ft_map;
  std::map<int, int> std_map;
  for (int i = 0; i <= 10; i++) ft_map.insert(ft::pair<int,int>(i,1));
	for (int i = 0; i <= 10; i++) std_map.insert(std::pair<int,int>(i,1));
  ft::map<int, int>::iterator ft_it = ft_map.begin();
  ft::map<int, int>::iterator ft_it_end = ft_map.end();
  std::map<int, int>::iterator std_it = std_map.begin();
  std::map<int, int>::iterator std_it_end = std_map.end();
  std::cout << "Insert AVL tree:" << std::endl;
  ft_map.print_tree();
  ft_map.erase(ft_it);
  std_map.erase(std_it);
  std::cout << "Erase pos:" << std::endl;
  ft_map.print_tree();
  ft_it_end--;
  ft_it_end--;
  ft_it_end--;
  std_it_end--;
  std_it_end--;
  std_it_end--;
  ft_map.erase(ft_it_end);
  std_map.erase(std_it_end);
  std::cout << "Erase pos:" << std::endl;
  ft_map.print_tree();
  REQUIRE(ft_map.size() == std_map.size()); // size
  REQUIRE(ft_map.empty() == std_map.empty()); // empty
}
TEST_CASE( "map - erase(key)", "[map]" ) {
  ft::map<int, int> ft_map;
  std::map<int, int> std_map;

  SECTION ("del _root only") {
    ft_map.insert(ft::pair<int,int>(40,1));
    std_map.insert(std::pair<int,int>(40,1));
    std::cout << "Insert AVL tree:" << std::endl;
    ft_map.print_tree();
    ft_map.erase(40);
    std_map.erase(40);
    std::cout << "Erase _root with no child -> 40:" << std::endl;
    ft_map.print_tree();
    REQUIRE(ft_map.size() == std_map.size()); // size
    REQUIRE(ft_map.empty() == std_map.empty()); // empty
	}
  SECTION ("del _root with left_heavy") {
    ft_map.insert(ft::pair<int,int>(40,1));
    std_map.insert(std::pair<int,int>(40,1));
    ft_map.insert(ft::pair<int,int>(20,1));
    std_map.insert(std::pair<int,int>(20,1));
    std::cout << "Insert AVL tree:" << std::endl;
    ft_map.print_tree();
    ft_map.erase(40);
    std_map.erase(40);
    std::cout << "Erase _root with left child only -> 40:" << std::endl;
    ft_map.print_tree();
    REQUIRE(ft_map.size() == std_map.size()); // size
    REQUIRE(ft_map.empty() == std_map.empty()); // empty
	}
  SECTION ("del _root with right_heavy") {
    ft_map.insert(ft::pair<int,int>(40,1));
    std_map.insert(std::pair<int,int>(40,1));
    ft_map.insert(ft::pair<int,int>(60,1));
    std_map.insert(std::pair<int,int>(60,1));
    std::cout << "Insert AVL tree:" << std::endl;
    ft_map.print_tree();
    ft_map.erase(40);
    std_map.erase(40);
    std::cout << "Erase _root with right child only -> 40:" << std::endl;
    ft_map.print_tree();
    REQUIRE(ft_map.size() == std_map.size()); // size
    REQUIRE(ft_map.empty() == std_map.empty()); // empty
	}
  SECTION ("del _root both") {
    ft_map.insert(ft::pair<int,int>(40,1));
    std_map.insert(std::pair<int,int>(40,1));
    ft_map.insert(ft::pair<int,int>(20,1));
    std_map.insert(std::pair<int,int>(20,1));
    ft_map.insert(ft::pair<int,int>(60,1));
    std_map.insert(std::pair<int,int>(60,1));
    std::cout << "Insert AVL tree:" << std::endl;
    ft_map.print_tree();
    ft_map.erase(40);
    std_map.erase(40);
    std::cout << "Erase _root with children on both sides -> 40:" << std::endl;
    ft_map.print_tree();
    REQUIRE(ft_map.size() == std_map.size()); // size
    REQUIRE(ft_map.empty() == std_map.empty()); // empty
	}
  SECTION ("del LEAF node") {
    ft_map.insert(ft::pair<int,int>(40,1));
    std_map.insert(std::pair<int,int>(40,1));
    ft_map.insert(ft::pair<int,int>(20,1));
    std_map.insert(std::pair<int,int>(20,1));
    ft_map.insert(ft::pair<int,int>(60,1));
    std_map.insert(std::pair<int,int>(60,1));
    ft_map.insert(ft::pair<int,int>(10,1));
    std_map.insert(std::pair<int,int>(10,1));
    ft_map.insert(ft::pair<int,int>(70,1));
    std_map.insert(std::pair<int,int>(70,1));
    ft_map.insert(ft::pair<int,int>(25,1));
    std_map.insert(std::pair<int,int>(25,1));
    ft_map.insert(ft::pair<int,int>(55,1));
    std_map.insert(std::pair<int,int>(55,1));
    ft_map.insert(ft::pair<int,int>(5,1));
    std_map.insert(std::pair<int,int>(5,1));
    ft_map.insert(ft::pair<int,int>(30,1));
    std_map.insert(std::pair<int,int>(30,1));
    ft_map.insert(ft::pair<int,int>(50,1));
    std_map.insert(std::pair<int,int>(50,1));
    ft_map.insert(ft::pair<int,int>(75,1));
    std_map.insert(std::pair<int,int>(75,1));
    std::cout << "Insert AVL tree:" << std::endl;
    ft_map.print_tree();
    // del LEAF ll
    ft_map.erase(5);
    std_map.erase(5);
    std::cout << "Erase LEAF ll -> 5:" << std::endl;
    ft_map.print_tree();
    REQUIRE(ft_map.size() == std_map.size()); // size
    REQUIRE(ft_map.empty() == std_map.empty()); // empty
    // del LEAF lr
    ft_map.erase(30);
    std_map.erase(30);
    std::cout << "Erase LEAF lr -> 30:" << std::endl;
    ft_map.print_tree();
    REQUIRE(ft_map.size() == std_map.size()); // size
    REQUIRE(ft_map.empty() == std_map.empty()); // empty
    // del LEAF rr
    ft_map.erase(75);
    std_map.erase(75);
    std::cout << "Erase LEAF rr -> 75:" << std::endl;
    ft_map.print_tree();
    REQUIRE(ft_map.size() == std_map.size()); // size
    REQUIRE(ft_map.empty() == std_map.empty()); // empty
    // del LEAF rl
    ft_map.erase(50);
    std_map.erase(50);
    std::cout << "Erase LEAF rl -> 50:" << std::endl;
    ft_map.print_tree();
    REQUIRE(ft_map.size() == std_map.size()); // size
    REQUIRE(ft_map.empty() == std_map.empty()); // empty
    // del node with both sides children
    ft_map.erase(20);
    std_map.erase(20);
    std::cout << "Erase node with both sides children -> 20:" << std::endl;
    ft_map.print_tree();
    REQUIRE(ft_map.size() == std_map.size()); // size
    REQUIRE(ft_map.empty() == std_map.empty()); // empty
    // del node with right child
    ft_map.erase(10);
    std_map.erase(10);
    std::cout << "Erase node with right child -> 10:" << std::endl;
    ft_map.print_tree();
    REQUIRE(ft_map.size() == std_map.size()); // size
    REQUIRE(ft_map.empty() == std_map.empty()); // empty
    // del LEAF rr
    ft_map.erase(70);
    std_map.erase(70);
    std::cout << "Erase LEAF rr -> 70:" << std::endl;
    ft_map.print_tree();
    REQUIRE(ft_map.size() == std_map.size()); // size
    REQUIRE(ft_map.empty() == std_map.empty()); // empty
    // del node with left child
    ft_map.erase(60);
    std_map.erase(60);
    std::cout << "Erase node with left child -> 60:" << std::endl;
    ft_map.print_tree();
    REQUIRE(ft_map.size() == std_map.size()); // size
    REQUIRE(ft_map.empty() == std_map.empty()); // empty
    // system("leaks ft_containers");
	}
  // del BIG test
  SECTION ("del BIG test") {
  	for (int i = 1; i <= 20; i++) ft_map.insert(ft::pair<int,int>(i,1));
	  for (int i = 1; i <= 20; i++) std_map.insert(std::pair<int,int>(i,1));
    std::cout << "Insert 1-20:" << std::endl;
    ft_map.print_tree();
  	for (int i = 21; i <= 40; i++) ft_map.insert(ft::pair<int,int>(i,1));
	  for (int i = 21; i <= 40; i++) std_map.insert(std::pair<int,int>(i,1));
    std::cout << "Insert 21-40:" << std::endl;
    ft_map.print_tree();
  	for (int i = 41; i <= 60; i++) ft_map.insert(ft::pair<int,int>(i,1));
	  for (int i = 41; i <= 60; i++) std_map.insert(std::pair<int,int>(i,1));
    std::cout << "Insert 41-60:" << std::endl;
    ft_map.print_tree();
    for (int i = 1; i <= 20; i++) ft_map.erase(i);
	  for (int i = 1; i <= 20; i++) std_map.erase(i);
    std::cout << "Erase 1-20:" << std::endl;
    ft_map.print_tree();
    for (int i = 60; i >= 41; i--) ft_map.erase(i);
	  for (int i = 60; i >= 41; i--) std_map.erase(i);
    std::cout << "Erase 41-60:" << std::endl;
    ft_map.print_tree();
  }
  SECTION ("erase all") {
  	for (int i = 1; i <= 3; i++) ft_map.insert(ft::pair<int,int>(i,1));
	  for (int i = 1; i <= 3; i++) std_map.insert(std::pair<int,int>(i,1));
    ft_map.print_tree();
	  for (int i = 1; i <= 3; i++) ft_map.erase(i);
	  for (int i = 1; i <= 3; i++) std_map.erase(i);
  std::cout << "Erase 1, 2, 3:" << std::endl;
    ft_map.print_tree();
    REQUIRE(ft_map.size() == std_map.size()); // size
    REQUIRE(ft_map.empty() == std_map.empty()); // empty
  }
}
TEST_CASE( "map - erase(first - last)", "[map]" ) {
  ft::map<int, int> ft_map;
  std::map<int, int> std_map;

  for (int i = 1; i <= 20; i++) ft_map.insert(ft::pair<int,int>(i,1));
	for (int i = 1; i <= 20; i++) std_map.insert(std::pair<int,int>(i,1));
  ft_map.print_tree();
  ft::map<int, int>::iterator ft_it_begin = ft_map.begin();
  std::map<int, int>::iterator std_it_begin = std_map.begin();
  ft::map<int, int>::iterator ft_it_end = ft_map.end();
  std::map<int, int>::iterator std_it_end = std_map.end();
  ft_it_begin++;
  std_it_begin++;
  ft_it_end--;
  std_it_end--;
  ft_map.erase(ft_it_begin, ft_it_end);
  std_map.erase(std_it_begin, std_it_end);
  std::cout << "Erase range:" << std::endl;
  ft_map.print_tree();
  REQUIRE(ft_map.size() == std_map.size()); // size
  REQUIRE(ft_map.empty() == std_map.empty()); // empty
}
TEST_CASE( "map - swap(x)", "[map]" ) {
  ft::map<int, char> ft_map;
  std::map<int, char> std_map;

  for (int i = 1; i <= 20; i++) ft_map.insert(ft::pair<int,char>(i,1));
	for (int i = 1; i <= 20; i++) std_map.insert(std::pair<int,char>(i,1));

  ft::map<int, char> ft_save;
  std::map<int, char> std_save;
  ft_save = ft_map;
  std_save = std_map;

  ft::map<int, char> ft_switch;
  std::map<int, char> std_switch;
  for (int i = 1; i <= 7; i++) ft_map.insert(ft::pair<int,char>(i,'A'));
	for (int i = 1; i <= 7; i++) std_map.insert(std::pair<int,char>(i,'A'));
  ft_map.swap(ft_switch);
  std_map.swap(std_switch);
  REQUIRE(ft_save.size() == ft_switch.size()); // size of og and new
  REQUIRE(ft_save.size() == std_save.size()); // size
  REQUIRE(ft_map.size() == std_map.size()); // size
  REQUIRE(ft_switch.size() == std_switch.size()); // size
}
TEST_CASE( "map - clear", "[map]" ) {
  ft::map<char, char> ft_map;
  std::map<char, char> std_map;

  ft_map.insert(ft::pair<char,char>('A','a'));
	std_map.insert(std::pair<char,char>('A','a'));
  ft_map.insert(ft::pair<char,char>('B','b'));
	std_map.insert(std::pair<char,char>('B','b'));
  ft_map.insert(ft::pair<char,char>('C','c'));
	std_map.insert(std::pair<char,char>('C','c'));
  ft_map.insert(ft::pair<char,char>('D','d'));
	std_map.insert(std::pair<char,char>('D','d'));
  ft_map.print_tree();
  REQUIRE(ft_map.size() == std_map.size()); // size
  REQUIRE(ft_map.empty() == std_map.empty()); // empty
  ft_map.clear();
  std_map.clear();
  std::cout << "Clear tree:" << std::endl;
  ft_map.print_tree();
  REQUIRE(ft_map.size() == std_map.size()); // size
  REQUIRE(ft_map.empty() == std_map.empty()); // empty
}
// OBSERVERS
// TEST_CASE("map - key compare", "[map]") {
//     ft::map<char,int> ft_map;

//     ft::map<char,int>::Compare mycomp = mymap.key_comp();

//     mymap['a']=100;
//     mymap['b']=200;
//     mymap['c']=300;

//     char highest = mymap.rbegin()->first;     // key value of last element

//     REQUIRE(mycomp(mymap.begin()->first, highest) == true );
// }
TEST_CASE("map - value_comp)", "[map]") {
  ft::map<char,int> ft_map;

  ft_map['x']=1001;
  ft_map['y']=2002;
  ft_map['z']=3003;
  ft::pair<char,int> highest = *ft_map.rbegin(); // last element
  ft::map<char,int>::iterator it = ft_map.begin();
  REQUIRE(ft_map.value_comp()(*it, highest) == true);
}
// OPERATIONS
TEST_CASE("map - find", "[map]") {
  ft::map<char,int> ft_map;
  ft::map<char,int>::iterator ft_it;
  ft::map<char,int>::const_iterator const_ft_it;
  std::map<char,int> std_map;
  std::map<char,int>::iterator std_it;
  std::map<char,int>::const_iterator const_std_it;

  ft_map['a']=50;
  ft_map['b']=100;
  ft_map['c']=150;
  ft_map['d']=200;
  std_map['a']=50;
  std_map['b']=100;
  std_map['c']=150;
  std_map['d']=200;
  ft_it = ft_map.find('b');
  std_it = std_map.find('b');
  const_ft_it = ft_map.find('b');
  const_std_it = std_map.find('b');
  REQUIRE(ft_it->second == 100);
  REQUIRE(std_it->second == 100);
  REQUIRE(std_it->second == ft_it->second);
  REQUIRE(const_std_it->second == const_ft_it->second);
  ft_it = ft_map.find('z');
  std_it = std_map.find('z');
  REQUIRE(ft_it->second == ft_map.end()->second);
  REQUIRE(std_it->second == std_map.end()->second);
}
TEST_CASE("map - count", "[map]") {
  ft::map<char,int> ft_map;
  char a = 'a';
  char b = 'z';

  ft_map ['a']=101;
  ft_map ['c']=202;
  ft_map ['f']=303;
  REQUIRE(ft_map.count(a) == 1);
  REQUIRE(ft_map.count(b) == 0);
}
TEST_CASE("map - lower_bound", "[map]") {
  ft::map<char,int> ft_map;
  ft::map<char,int>::iterator itlow, itup;

  ft_map['a']=20;
  ft_map['b']=40;
  ft_map['c']=60;
  ft_map['d']=80;
  ft_map['e']=100;
  itlow = ft_map.lower_bound ('b');  // itlow points to b
  REQUIRE(itlow->second == 40);
  ft_map.erase(itlow);
  itlow = ft_map.lower_bound ('b');  // itlow points to c
  REQUIRE(itlow->second == 60);
}
TEST_CASE("map - upper_bound", "[map]") {
  ft::map<char,int> ft_map;
  ft::map<char,int>::iterator itlow,itup;

  ft_map['a']=20;
  ft_map['b']=40;
  ft_map['c']=60;
  ft_map['d']=80;
  ft_map['e']=100;

  itup = ft_map.upper_bound('c');  // itup points to d
  REQUIRE(itup->second == 80);
  ft_map.erase(itup);
  itup = ft_map.upper_bound('d');  // itlow points to e
  REQUIRE(itup->second == 100);
}
TEST_CASE("map - equal_range", "[map]") {
  ft::map<char,int> ft_map;

  ft_map['a']=10;
  ft_map['b']=20;
  ft_map['c']=30;

  ft::pair<ft::map<char,int>::iterator,ft::map<char,int>::iterator> ret;
  ret = ft_map.equal_range('b');

  REQUIRE(ret.first->first == 'b');
  REQUIRE(ret.second->first == 'c');
}
TEST_CASE( "map - go crazy", "[map]" ) {
  ft::map<int, int> ft_map;
  std::map<int, int> std_map;
  ft_map.insert(ft::pair<int,int>(40,1));
  std_map.insert(std::pair<int,int>(40,1));
  ft_map.insert(ft::pair<int,int>(20,1));
  std_map.insert(std::pair<int,int>(20,1));
  ft_map.insert(ft::pair<int,int>(60,1));
  std_map.insert(std::pair<int,int>(60,1));
  ft_map.insert(ft::pair<int,int>(10,1));
  std_map.insert(std::pair<int,int>(10,1));
  ft_map.insert(ft::pair<int,int>(70,1));
  std_map.insert(std::pair<int,int>(70,1));
  ft_map.insert(ft::pair<int,int>(25,1));
  std_map.insert(std::pair<int,int>(25,1));
  ft_map.insert(ft::pair<int,int>(55,1));
  std_map.insert(std::pair<int,int>(55,1));
  ft_map.insert(ft::pair<int,int>(5,1));
  std_map.insert(std::pair<int,int>(5,1));
  ft_map.insert(ft::pair<int,int>(30,1));
  std_map.insert(std::pair<int,int>(30,1));
  ft_map.insert(ft::pair<int,int>(50,1));
  std_map.insert(std::pair<int,int>(50,1));
  ft_map.insert(ft::pair<int,int>(75,1));
  std_map.insert(std::pair<int,int>(75,1));
  std::cout << "Create AVL tree:" << std::endl;
  ft_map.print_tree();
  REQUIRE(ft_map.size() == std_map.size()); // size
  REQUIRE(ft_map.empty() == std_map.empty()); // empty

  ft_map.insert(ft::pair<int,int>(21,1));
  std_map.insert(std::pair<int,int>(21,1));
  ft_map.insert(ft::pair<int,int>(5,1));
  std_map.insert(std::pair<int,int>(5,1));
  ft_map.insert(ft::pair<int,int>(77,1));
  std_map.insert(std::pair<int,int>(77,1));
  ft_map.insert(ft::pair<int,int>(56,1));
  std_map.insert(std::pair<int,int>(56,1));
  ft_map.insert(ft::pair<int,int>(61,1));
  std_map.insert(std::pair<int,int>(61,1));
  std::cout << "Insert extra:" << std::endl;
  ft_map.print_tree();
  REQUIRE(ft_map.size() == std_map.size()); // size
  REQUIRE(ft_map.empty() == std_map.empty()); // empty

  ft_map.erase(20);
  std_map.erase(20);
  std::cout << "Erase 20:" << std::endl;
  ft_map.print_tree();
  REQUIRE(ft_map.size() == std_map.size()); // size
  REQUIRE(ft_map.empty() == std_map.empty()); // empty
  ft_map.erase(25);
  std_map.erase(25);
  std::cout << "Erase 25:" << std::endl;
  ft_map.print_tree();
  REQUIRE(ft_map.size() == std_map.size()); // size
  REQUIRE(ft_map.empty() == std_map.empty()); // empty
  ft_map.erase(30);
  std_map.erase(30);
  std::cout << "Erase 30:" << std::endl;
  ft_map.print_tree();
  REQUIRE(ft_map.size() == std_map.size()); // size
  REQUIRE(ft_map.empty() == std_map.empty()); // empty
}
