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
    REQUIRE(ft_map.empty() == true); // empty map
    // ft::pair<ft::iterator,bool> test = ft::make_pair(1, 2);
    // std::cout << test.first << std::endl;
    // std::map<char, int> std_map;
    // REQUIRE(ft_map.size() == std_map.size()); // empty map
    // TEST1
    // ft_map.insert(ft::pair<int,int>(8,800));
    // // ft_map.print_tree();
    // ft_map.insert(ft::pair<int,int>(5,500));
    // // ft_map.print_tree();
    // ft_map.insert(ft::pair<int,int>(10,1000));
    // // ft_map.print_tree();
    // ft_map.insert(ft::pair<int,int>(6,600));
    // // ft_map.print_tree();
    // ft_map.insert(ft::pair<int,int>(2,200));
    // ft_map.print_tree();
    // std::cout << "Insert 1 to cause imbalance:" << std::endl;
    // ft_map.insert(ft::pair<int,int>(1,100));
    // ft_map.print_tree();
    // TEST2
    // ft_map.insert(ft::pair<int,int>(28,2800));
    // // ft_map.print_tree();
    // ft_map.insert(ft::pair<int,int>(30,3000));
    // // ft_map.print_tree();
    // ft_map.insert(ft::pair<int,int>(16,1600));
    // ft_map.insert(ft::pair<int,int>(18,1800));
    // ft_map.print_tree();
    // ft_map.print_tree();
    // std::cout << "Insert 10 to cause imbalance:" << std::endl;
    // ft_map.insert(ft::pair<int,int>(19,1900));
    // ft_map.insert(ft::pair<int,int>(50,5000));
    // ft_map.insert(ft::pair<int,int>(10,1000));
    // ft_map.insert(ft::pair<int,int>(2,200));
    // ft_map.insert(ft::pair<int,int>(17,1700));
    // ft_map.insert(ft::pair<int,int>(20,2000));
    // ft_map.print_tree();
    // TEST4
    // ft_map.insert(ft::pair<int,int>(4,400));
    // ft_map.insert(ft::pair<int,int>(2,200));
    // ft_map.insert(ft::pair<int,int>(5,500));
    // ft_map.insert(ft::pair<int,int>(8,800));
    // // ft_map.insert(ft::pair<int,int>(7,700));
    // std::cout << "Insert 10 to cause imbalance:" << std::endl;
    // ft_map.insert(ft::pair<int,int>(10,1000));
    // ft_map.print_tree();
}
TEST_CASE( "map - range constructor", "[map]" ) {
  ft::map<int, int> ft_test;
  for (int i = 0; i != 10; i++) ft_test.insert(ft::pair<int,int>(i,1));
  ft::map<int, int> ft_map(ft_test.begin(), ft_test.end());
  REQUIRE(ft_map.empty() == ft_test.empty());
  REQUIRE(ft_map.size() == ft_test.size());
}
TEST_CASE( "map - copy constructor", "[map]" ) {
  ft::map<int, int> ft_test2;
  for (int i = 0; i != 10; i++) ft_test2.insert(ft::pair<int,int>(i,1));
  ft::map<int, int> ft_map(ft_test2);
  REQUIRE(ft_test2.size() == ft_map.size()); // map copied from excisting
  REQUIRE(ft_map.empty() == ft_test2.empty()); 
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
	for (int i = 1; i <= 7; i++) ft_map.insert(ft::pair<int,int>(i,1));
  // REQUIRE(*ft_map.begin() == ); // it_ptr to _next first element
}
TEST_CASE( "map - const begin", "[map]" ) {
  ft::map<int, int> ft_map;
	for (int i = 1; i <= 7; i++) ft_map.insert(ft::pair<int,int>(i,1));
	ft::map<int, int>::const_iterator ft_it = ft_map.begin();
  // REQUIRE(*ft_it == *std_it); // it_ptr to _next first element
}
TEST_CASE( "map - end", "[map]" ) {
  ft::map<int, int> ft_map;
	for (int i = 1; i <= 7; i++) ft_map.insert(ft::pair<int,int>(i,1));
  ft::map<int, int>::iterator ft_it = ft_map.end();
  ft_it--;
  // REQUIRE(*(ft_it) == *(std_it)); // it_ptr to element preceding .end()
}
TEST_CASE( "map - const end", "[map]" ) {
  ft::map<int, int> ft_map;
	for (int i = 1; i <= 7; i++) ft_map.insert(ft::pair<int,int>(i,1));
	ft::map<int, int>::const_iterator ft_it = ft_map.end();
	ft_it--;
  // REQUIRE(*ft_it == *std_it); // it_ptr to element preceding .end()
}
// TEST_CASE( "map - rbegin", "[map]" ) {
//     ft::map<int, int> ft_map;
//     std::map<int, int> std_map;
//     for (int i = 1; i <= 7; i++) ft_map.insert(ft::pair<int,int>(i,1));
//     for (int i = 1; i <= 7; i++) std_map.insert(std::pair<int,int>(i,1));
//     REQUIRE(*ft_map.rbegin() == *std_map.rbegin()); // it_ptr to element preceding _last
// }
// TEST_CASE( "map - const rbegin", "[map]" ) {
//     ft::map<int, int> ft_map;
//     std::map<int, int> std_map;
// 	for (int i = 1; i <= 7; i++) ft_map.push_back(i);
//     for (int i = 1; i <= 7; i++) std_map.push_back(i);
// 	ft::map<int, int>::const_reverse_iterator ft_it = ft_map.rbegin();
// 	std::map<int, int>::const_reverse_iterator std_it = std_map.rbegin();
//     REQUIRE(*ft_it == *std_it); // it_ptr to element preceding _last
// }
// TEST_CASE( "map - rend", "[map]" ) {
//     ft::map<int, int> ft_map;
//     std::map<int, int> std_map;
// 	for (int i = 1; i <= 7; i++) ft_map.push_back(i);
//     for (int i = 1; i <= 7; i++) std_map.push_back(i);
//     ft::map<int, int>::reverse_iterator ft_it = ft_map.rend();
// 	std::map<int, int>::reverse_iterator std_it = std_map.rend();
//     ft_it--;
//     std_it--;
//     REQUIRE(*(ft_it) == *(std_it)); // it_ptr to element preceding _first
// }
// TEST_CASE( "map - const rend", "[map]" ) {
//     ft::map<int, int> ft_map;
//     std::map<int, int> std_map;
// 	for (int i = 1; i <= 7; i++) ft_map.push_back(i);
//     for (int i = 1; i <= 7; i++) std_map.push_back(i);
// 	ft::map<int, int>::const_reverse_iterator ft_it = ft_map.rend();
// 	std::map<int, int>::const_reverse_iterator std_it = std_map.rend();
// 	ft_it--;
// 	std_it--;
//     REQUIRE(*ft_it == *std_it); // it_ptr to element preceding _first
// }
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
TEST_CASE( "map - max_size", "[map]" ) {
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
  ft_map.print_tree();
  REQUIRE(ft_map[10] == std_map[10]);
  ft_map.print_tree();
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
    REQUIRE(ft_map.empty() == std_map.empty());
    REQUIRE(ft_map.size() == std_map.size());
  }
  // check double
  SECTION ("check double") {
    ft_map.insert(ft::pair<int,int>(40,1));
    std_map.insert(std::pair<int,int>(40,1));
    ft_map.print_tree();
    ft_map.insert(ft::pair<int,int>(40,300));
    std_map.insert(std::pair<int,int>(40,300));
    ft_map.print_tree();
    REQUIRE(ft_map.size() == std_map.size()); // size
    REQUIRE(ft_map.empty() == std_map.empty()); // empty
	}
}

TEST_CASE( "map - erase(key)", "[map]" ) {
  ft::map<int, int> ft_map;
  std::map<int, int> std_map;

  SECTION ("del _root only") {
    ft_map.insert(ft::pair<int,int>(40,1));
    std_map.insert(std::pair<int,int>(40,1));
    ft_map.print_tree();
    ft_map.erase(40);
    std_map.erase(40);
    ft_map.print_tree();
    REQUIRE(ft_map.size() == std_map.size()); // size
    REQUIRE(ft_map.empty() == std_map.empty()); // empty
	}

  SECTION ("del _root with left_heavy") {
    ft_map.insert(ft::pair<int,int>(40,1));
    std_map.insert(std::pair<int,int>(40,1));
    ft_map.insert(ft::pair<int,int>(20,1));
    std_map.insert(std::pair<int,int>(20,1));
    ft_map.print_tree();
    ft_map.erase(40);
    std_map.erase(40);
    ft_map.print_tree();
    REQUIRE(ft_map.size() == std_map.size()); // size
    REQUIRE(ft_map.empty() == std_map.empty()); // empty
	}

  SECTION ("del _root with right_heavy") {
    ft_map.insert(ft::pair<int,int>(40,1));
    std_map.insert(std::pair<int,int>(40,1));
    ft_map.insert(ft::pair<int,int>(60,1));
    std_map.insert(std::pair<int,int>(60,1));
    ft_map.print_tree();
    ft_map.erase(40);
    std_map.erase(40);
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
    ft_map.print_tree();
    ft_map.erase(40);
    std_map.erase(40);
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
    ft_map.print_tree();
    // del LEAF ll
    ft_map.erase(5);
    std_map.erase(5);
    ft_map.print_tree();
    REQUIRE(ft_map.size() == std_map.size()); // size
    REQUIRE(ft_map.empty() == std_map.empty()); // empty
    // del LEAF lr
    ft_map.erase(30);
    std_map.erase(30);
    ft_map.print_tree();
    REQUIRE(ft_map.size() == std_map.size()); // size
    REQUIRE(ft_map.empty() == std_map.empty()); // empty
    // del LEAF rr
    ft_map.erase(75);
    std_map.erase(75);
    ft_map.print_tree();
    REQUIRE(ft_map.size() == std_map.size()); // size
    REQUIRE(ft_map.empty() == std_map.empty()); // empty
    // del LEAF rl
    ft_map.erase(50);
    std_map.erase(50);
    ft_map.print_tree();
    REQUIRE(ft_map.size() == std_map.size()); // size
    REQUIRE(ft_map.empty() == std_map.empty()); // empty
    // del node with both sides children
    ft_map.erase(20);
    std_map.erase(20);
    ft_map.print_tree();
    REQUIRE(ft_map.size() == std_map.size()); // size
    REQUIRE(ft_map.empty() == std_map.empty()); // empty
    // del node with right child
    ft_map.erase(10);
    std_map.erase(10);
    ft_map.print_tree();
    REQUIRE(ft_map.size() == std_map.size()); // size
    REQUIRE(ft_map.empty() == std_map.empty()); // empty
    // del LEAF rr
    ft_map.erase(70);
    std_map.erase(70);
    ft_map.print_tree();
    REQUIRE(ft_map.size() == std_map.size()); // size
    REQUIRE(ft_map.empty() == std_map.empty()); // empty
    // del node with left child
    ft_map.erase(60);
    std_map.erase(60);
    ft_map.print_tree();
    REQUIRE(ft_map.size() == std_map.size()); // size
    REQUIRE(ft_map.empty() == std_map.empty()); // empty
    // system("leaks ft_containers");
	}
}

TEST_CASE( "map - go crazy", "[map]" ) {
  ft::map<int, int> ft_map;
  std::map<int, int> std_map;
  // ft_map.insert(ft::pair<int,int>(40,1));
  // std_map.insert(std::pair<int,int>(40,1));
  // ft_map.insert(ft::pair<int,int>(20,1));
  // std_map.insert(std::pair<int,int>(20,1));
  // ft_map.insert(ft::pair<int,int>(60,1));
  // std_map.insert(std::pair<int,int>(60,1));
  // ft_map.insert(ft::pair<int,int>(10,1));
  // std_map.insert(std::pair<int,int>(10,1));
  // ft_map.insert(ft::pair<int,int>(70,1));
  // std_map.insert(std::pair<int,int>(70,1));
  // ft_map.insert(ft::pair<int,int>(25,1));
  // std_map.insert(std::pair<int,int>(25,1));
  // ft_map.insert(ft::pair<int,int>(55,1));
  // std_map.insert(std::pair<int,int>(55,1));
  // ft_map.insert(ft::pair<int,int>(5,1));
  // std_map.insert(std::pair<int,int>(5,1));
  // ft_map.insert(ft::pair<int,int>(30,1));
  // std_map.insert(std::pair<int,int>(30,1));
  // ft_map.insert(ft::pair<int,int>(50,1));
  // std_map.insert(std::pair<int,int>(50,1));
  // ft_map.insert(ft::pair<int,int>(75,1));
  // std_map.insert(std::pair<int,int>(75,1));
  // ft_map.print_tree();
  // REQUIRE(ft_map.size() == std_map.size()); // size
  // REQUIRE(ft_map.empty() == std_map.empty()); // empty

  // ft_map.insert(ft::pair<int,int>(21,1));
  // std_map.insert(std::pair<int,int>(21,1));
  // ft_map.insert(ft::pair<int,int>(5,1));
  // std_map.insert(std::pair<int,int>(5,1));
  // ft_map.insert(ft::pair<int,int>(77,1));
  // std_map.insert(std::pair<int,int>(77,1));
  // ft_map.insert(ft::pair<int,int>(56,1));
  // std_map.insert(std::pair<int,int>(56,1));
  // ft_map.insert(ft::pair<int,int>(61,1));
  // std_map.insert(std::pair<int,int>(61,1));
  // ft_map.print_tree();
  // REQUIRE(ft_map.size() == std_map.size()); // size
  // REQUIRE(ft_map.empty() == std_map.empty()); // empty

  // ft_map.erase(20);
  // std_map.erase(20);
  // ft_map.print_tree();
  // REQUIRE(ft_map.size() == std_map.size()); // size
  // REQUIRE(ft_map.empty() == std_map.empty()); // empty
  // ft_map.erase(25);
  // std_map.erase(25);
  // ft_map.print_tree();
  // REQUIRE(ft_map.size() == std_map.size()); // size
  // REQUIRE(ft_map.empty() == std_map.empty()); // empty
  // ft_map.erase(30);
  // std_map.erase(30);
  // ft_map.print_tree();
  // REQUIRE(ft_map.size() == std_map.size()); // size
  // REQUIRE(ft_map.empty() == std_map.empty()); // empty

  // PART TWO
  // for (int i = 0; i != 31; i++) ft_map.insert(ft::pair<int,int>(i,1));
  // for (int i = 0; i != 31; i++) std_map.insert(std::pair<int,int>(i,1));
  // ft_map.print_tree();

  ft::map<int, int>  own;
    int sum = 1;
    for (int i = 0; i < 6; ++i)
    {
        own.insert(ft::pair<int, int>(sum, sum));
        sum += 1;
    }
    own.print_tree();
    ft::map<int, int>::iterator it = own.begin();
    ft::map<int, int>::iterator ite = own.end();
    while(it != own.end())
    {
        // std::cout << it->first << std::endl;
        ++it;
    }

}
