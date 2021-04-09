#include "catch.hpp"

#include <string>
#include <vector>
#include "../includes/vector.hpp" 

// COPLIEN
TEST_CASE( "RandomAccessIterator", "[iterator]" ) {
	ft::vector<int> ft_vector;
    std::vector<int> std_vector;
	for (int i = 1; i <= 10; i++) ft_vector.push_back(i);
    for (int i = 1; i <= 10; i++) std_vector.push_back(i);
	ft::vector<int>::iterator ft_it_begin = ft_vector.begin();
	std::vector<int>::iterator std_it_begin = std_vector.begin();
	ft::vector<int>::iterator ft_it_end = ft_vector.end();
	std::vector<int>::iterator std_it_end = std_vector.end();
	ft::vector<int>::iterator ft_check = ft_vector.begin() + 1;
	SECTION ("default constructor") {
        ft::vector<std::string>::iterator ft_it;
        REQUIRE(ft_it.get_ptr() == NULL);
	}
	SECTION("copy constructor") {
	    ft::vector<int> ft_vector;
	    for (int i = 1; i <= 10; i++) ft_vector.push_back(i);
        ft::vector<int>::iterator ft_it = ft_vector.begin();
        ft::vector<int>::iterator ft_it_test = ft_it;
        REQUIRE(*ft_it == *ft_it_test);
	}
	SECTION("assignation operator") {
        ft::vector<int> ft_vector;
	    for (int i = 1; i <= 10; i++) ft_vector.push_back(i);
        ft::vector<int>::iterator ft_it = ft_vector.begin();
        ft::vector<int>::iterator ft_it_test;
        ft_it_test = ft_it;
        REQUIRE(*ft_it == *ft_it_test);
	}
	SECTION("*") {
        ft_it_begin++;
        std_it_begin++;
        REQUIRE(*ft_it_begin == *std_it_begin);
    }
	// SECTION("-> overload") {
	// 	ft_it++;
	// 	std_it++;
	// 	REQUIRE(*ft_it == *std_it);
    // }
	SECTION("[]") {
        REQUIRE(ft_it_begin[3] == 4);
        REQUIRE(ft_it_begin[3] == std_it_begin[3]);
    }
	SECTION("++ prefix and postfix") {
		ft::vector<int>::iterator ft_check;
		std::vector<int>::iterator std_check;
        REQUIRE(*ft_it_begin == *std_it_begin);
        ft_check = ft_it_begin++;
        std_check = std_it_begin++;
        REQUIRE(*ft_check == *std_check);
        ++ft_it_begin;
        ++std_it_begin;
        REQUIRE(*ft_it_begin == *std_it_begin);
    }
    SECTION("-- prefix and postfix") {
		ft::vector<int>::iterator ft_check;
		std::vector<int>::iterator std_check;
        ft_check = ft_it_end--;
        std_check = std_it_end--;
        REQUIRE(*ft_it_end == *std_it_end);
        --ft_it_end;
        --std_it_end;
        REQUIRE(*ft_it_end == *std_it_end);
    }
	SECTION("+") {
        ft_it_begin = ft_it_begin + 2;
        std_it_begin = std_it_begin + 2;
        REQUIRE(*ft_it_begin == *std_it_begin);
        int res = *ft_it_begin + *ft_check;
        REQUIRE(res == 5);
    }
    SECTION("-") {
		ft_check = ft_vector.begin();
        ft_it_end = ft_it_end - 3;
        std_it_end = std_it_end - 3;
        REQUIRE(*ft_it_end == *std_it_end);
        int res = *ft_it_end - *ft_check;
        REQUIRE(res == 7);
    }
    SECTION("+=") {
        ft_it_begin += 2;
        std_it_begin += 2;
        REQUIRE(*ft_it_begin == *std_it_begin);
    }
    SECTION("-= overload") {
        ft_it_end -= 2;
        std_it_end -= 2;
        REQUIRE(*ft_it_end == *std_it_end);
    }
	ft_it_begin = ft_vector.begin() + 1;
	ft_it_end = ft_vector.begin() + 2;
	std_it_begin = std_vector.begin() + 1;
	std_it_end = std_vector.begin() + 2;
	SECTION("< overload") {
        bool res;
		res = *ft_it_begin < *ft_it_end;
        REQUIRE(res == true);
    }
    SECTION("> overload") {
        bool res;
		res = *ft_it_begin > *ft_it_end;
        REQUIRE(res == false);
    }
    SECTION("<= overload") {
        bool res;
		res = *ft_it_begin <= *ft_it_begin;
        REQUIRE(res == true);
        res = *ft_it_end <= *ft_it_end;
        REQUIRE(res == true);
    }
    SECTION(">= overload") {
        bool res;
		res = *ft_it_begin >= *ft_it_end;
        REQUIRE(res == false);
        res = *ft_it_begin >= *ft_it_begin;
        REQUIRE(res == true);
    }
    SECTION("== operator") {
        bool res;
        res = (*ft_it_begin == *std_it_begin);
        REQUIRE(res == true);
        ++ft_it_begin;
        res = (*ft_it_begin == *std_it_begin);
        REQUIRE(res == false);
    }
    SECTION("!= operator") {
        bool res;
        res = (*ft_it_begin != *std_it_begin);
        REQUIRE(res == false);
        ++std_it_begin;
        res = (*ft_it_begin != *std_it_begin);
        REQUIRE(res == true);
    }
}
