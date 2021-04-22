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
    // ft::pair<ft::iterator,bool> test = ft::make_pair(1, 2);
    // std::cout << test.first << std::endl;
    // std::map<char, int> std_map;
    // REQUIRE(ft_map.size() == std_map.size()); // empty map
    REQUIRE(ft_map.empty() == true); // empty map
    // TEST1
    // ft_map.insert(ft::pair<int,int>(8,800));
    // ft_map.insert(ft::pair<int,int>(5,500));
    // ft_map.insert(ft::pair<int,int>(6,600));
    // ft_map.insert(ft::pair<int,int>(10,1000));
    // ft_map.insert(ft::pair<int,int>(2,200));
    // ft_map.print_tree();
    // std::cout << "Insert 1 to cause imbalance:" << std::endl;
    // ft_map.insert(ft::pair<int,int>(1,100));
    // TEST2
    // ft_map.insert(ft::pair<int,int>(4,400));
    // ft_map.insert(ft::pair<int,int>(5,500));
    // ft_map.insert(ft::pair<int,int>(3,300));
    // ft_map.insert(ft::pair<int,int>(2,200));
    // std::cout << "Insert 1 to cause imbalance:" << std::endl;
    // ft_map.insert(ft::pair<int,int>(1,100));
    // ft_map.print_tree();
    // TEST3
    // ft_map.insert(ft::pair<int,int>(2,200));
    // ft_map.insert(ft::pair<int,int>(3,300));
    // ft_map.insert(ft::pair<int,int>(1,100));
    // ft_map.insert(ft::pair<int,int>(4,400));
    // std::cout << "Insert 5 to cause imbalance:" << std::endl;
    // ft_map.insert(ft::pair<int,int>(5,500));
    // ft_map.print_tree();
    // TEST4
    ft_map.insert(ft::pair<int,int>(4,400));
    ft_map.insert(ft::pair<int,int>(2,200));
    ft_map.insert(ft::pair<int,int>(5,500));
    ft_map.insert(ft::pair<int,int>(8,800));
    // ft_map.insert(ft::pair<int,int>(7,700));
    std::cout << "Insert 10 to cause imbalance:" << std::endl;
    ft_map.insert(ft::pair<int,int>(10,1000));
    ft_map.print_tree();
}

