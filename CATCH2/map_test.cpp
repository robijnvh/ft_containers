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
    ft::map<char, int> ft_map;
    // std::map<char, int> std_map;
    // REQUIRE(ft_map.size() == std_map.size()); // empty map
    REQUIRE(ft_map.empty() == true); // empty map
    ft_map.insert(ft::make_pair(1, 2));
    REQUIRE(ft_map.size() == 1); // empty map
    ft_map.insert(ft::make_pair(3, 4));
    REQUIRE(ft_map.size() == 2); // empty map
    ft_map.print_tree();
}

