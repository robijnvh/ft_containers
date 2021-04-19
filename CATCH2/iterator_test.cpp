#include "catch.hpp"

#include <string>
#include <vector>
#include <list>
#include "../includes/vector.hpp" 
#include "../includes/list.hpp"

// RANDOM ACCESS
TEST_CASE( "RandomAccessIterator", "[iterator]" ) {
	ft::vector<int> ft_vector;
    std::vector<int> std_vector;
	for (int i = 1; i <= 10; i++) ft_vector.push_back(i);
    for (int i = 1; i <= 10; i++) std_vector.push_back(i);
    // ft::vector<std::string> ft_vector2;
    // std::vector<std::string> std_vector2;
    // ft_vector2.push_back("hi");
    // std_vector2.push_back("hi");
    // ft_vector2.push_back("hi");
    // std_vector2.push_back("hi");
    // ft_vector2.push_back("hi");
    // std_vector2.push_back("hi");
	ft::vector<int>::iterator ft_it_begin = ft_vector.begin();
	std::vector<int>::iterator std_it_begin = std_vector.begin();
    // ft::vector<std::string>::iterator ft_it2 = ft_vector2.begin();
	// std::vector<std::string>::iterator std_it2 = std_vector2.begin();
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
	// 	ft_it2++;
	// 	std_it2++;
	// 	REQUIRE(*ft_it2->data() == *std_it2->data());
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
        ft_check--;
        std_check--;
        ft_check--;
        std_check--;
        REQUIRE(*ft_it_end == *std_it_end);
        REQUIRE(*ft_check == *std_check);
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
// BIDIRECTIONAL
TEST_CASE( "BidirectionalIterator", "[iterator]") {
	ft::list<int> ft_list;
    std::list<int> std_list;
	for (int i = 1; i <= 10; i++) ft_list.push_back(i);
    for (int i = 1; i <= 10; i++) std_list.push_back(i);
    ft::list<std::string> ft_list2(2, "xp");
    std::list<std::string> std_list2(2, "xp");
	ft::list<int>::iterator ft_it_begin = ft_list.begin();
	std::list<int>::iterator std_it_begin = std_list.begin();
	ft::list<int>::iterator ft_it_end = ft_list.end();
	std::list<int>::iterator std_it_end = std_list.end();
	ft::list<int>::iterator ft_check = ft_list.begin();
    ft_check++;
	std::list<int>::iterator std_check = std_list.begin();
    std_check++;
    SECTION ("default constructor") {
        ft::list<std::string>::iterator ft_it;
        REQUIRE(ft_it.get_ptr() == NULL);
	}
    SECTION("copy constructor") {
	    ft::list<int> ft_list;
	    for (int i = 1; i <= 10; i++) ft_list.push_back(i);
        ft::list<int>::iterator ft_it = ft_list.begin();
        ft::list<int>::iterator ft_it_test = ft_it;
        REQUIRE(*ft_it == *ft_it_test);
	}
    SECTION("assignation operator") {
        ft::list<int> ft_list;
	    for (int i = 1; i <= 10; i++) ft_list.push_back(i);
        ft::list<int>::iterator ft_it = ft_list.begin();
        ft::list<int>::iterator ft_it_test;
        ft_it_test = ft_it;
        REQUIRE(*ft_it == *ft_it_test);
	}
    SECTION("*") {
        REQUIRE(*ft_list2.begin()->data() == *std_list2.begin()->data());
    }
    SECTION("-> overload") {
        ft::list<std::string>::iterator ft_it = ft_list2.begin();
	    std::list<std::string>::iterator std_it = std_list2.begin();
        ft_it--;
        std_it--;
		REQUIRE(*ft_it->data() == *std_it->data());
    }
	SECTION("++ prefix and postfix") {
		ft::list<int>::iterator ft_check;
		std::list<int>::iterator std_check;
        REQUIRE(*ft_it_begin == *std_it_begin);
        ft_check = ft_it_begin++;
        std_check = std_it_begin++;
        REQUIRE(*ft_check == *std_check);
        ++ft_it_begin;
        ++std_it_begin;
        REQUIRE(*ft_it_begin == *std_it_begin);
    }
    SECTION("-- prefix and postfix") {
		ft::list<int>::iterator ft_check;
		std::list<int>::iterator std_check;
        ft_check = ft_it_end--;
        std_check = std_it_end--;
        ft_check--;
        std_check--;
        ft_check--;
        std_check--;
        REQUIRE(*ft_it_end == *std_it_end);
        REQUIRE(*ft_check == *std_check);
        --ft_it_end;
        --std_it_end;
        REQUIRE(*ft_it_end == *std_it_end);
    }
    ft_it_begin = ft_list.begin();
    ft_it_begin++;
	ft_it_end = ft_list.begin();
    ft_it_end++; ft_it_end++;
	std_it_begin = std_list.begin();
    std_it_begin++;
	std_it_end = std_list.begin();
    std_it_end++; std_it_end++;
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