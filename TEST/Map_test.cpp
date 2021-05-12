/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Map_test.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: timvancitters <timvancitters@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/23 10:10:11 by timvancitte   #+#    #+#                 */
/*   Updated: 2021/05/07 13:28:31 by robijnvanho   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "catch.hpp"
#include <map>
#include <iostream>

#include "../includes/map.hpp"

/*-----------------MEMBER FUNCTIONS-----------------*/
TEST_CASE("map-Empty container constructor", "[map]")
{
	ft::map<int, int>	own;
	std::map<int, int>	real;

	REQUIRE(own.size() == real.size());
	REQUIRE(own.empty() == real.empty());
}

TEST_CASE("map-Range constructor", "[map]")
{
	ft::map<int, int>	own;
	std::map<int, int>	real;

	int sum = 1;
	for (int i = 0; i < 6; ++i)
	{
		own.insert(ft::pair<int, int>(sum, sum));
		real.insert(std::pair<int, int>(sum, sum));
		sum += 1;
	}
	
	REQUIRE(own.size() == real.size());
	REQUIRE(own.empty() == real.empty());
	
	std::map<int, int>::iterator	real_it = real.begin();
	ft::map<int, int>::iterator		own_it = own.begin();
	
	while (own_it != own.end())
	{
		REQUIRE(own_it->first == real_it->first);
		REQUIRE(own_it->second == real_it->second);
		++own_it;
		++real_it;
	}
	
	std::map<int, int>	real2(real.begin(), real.end());
	ft::map<int, int>	own2(own.begin(), own.end());
	
	REQUIRE(own2.size() == real2.size());
	REQUIRE(own2.empty() == real2.empty());
	
	real_it = real2.begin();
	own_it = own2.begin();
	while (own_it != own2.end())
	{
		REQUIRE(own_it->first == real_it->first);
		REQUIRE(own_it->second == real_it->second);
		++own_it;
		++real_it;
	}
}

TEST_CASE("map-copy constructor", "[map]")
{
	ft::map<int, int>	own;
	std::map<int, int>	real;

	int sum = 1;
	for (int i = 0; i < 6; ++i)
	{
		own.insert(ft::pair<int, int>(sum, sum));
		real.insert(std::pair<int, int>(sum, sum));
		sum += 1;
	}
	
	REQUIRE(own.size() == real.size());
	REQUIRE(own.empty() == real.empty());
	
	std::map<int, int>::iterator	real_it = real.begin();
	ft::map<int, int>::iterator		own_it = own.begin();
	
	while (own_it != own.end())
	{
		REQUIRE(own_it->first == real_it->first);
		REQUIRE(own_it->second == real_it->second);
		++own_it;
		++real_it;
	}
	
	std::map<int, int>	real2(real);
	ft::map<int, int>	own2(own);
	
	REQUIRE(own2.size() == real2.size());
	REQUIRE(own2.empty() == real2.empty());
	
	real_it = real2.begin();
	own_it = own2.begin();
	while (own_it != own2.end())
	{
		REQUIRE(own_it->first == real_it->first);
		REQUIRE(own_it->second == real_it->second);
		++own_it;
		++real_it;
	}
}

TEST_CASE("map-assign content", "[map]")
{
	ft::map<int, int>	own;
	std::map<int, int>	real;

	int sum = 1;
	for (int i = 0; i < 6; ++i)
	{
		own.insert(ft::pair<int, int>(sum, sum));
		real.insert(std::pair<int, int>(sum, sum));
		sum += 1;
	}
	
	REQUIRE(own.size() == real.size());
	REQUIRE(own.empty() == real.empty());
	
	std::map<int, int>::iterator	real_it = real.begin();
	ft::map<int, int>::iterator		own_it = own.begin();
	
	while (own_it != own.end())
	{
		REQUIRE(own_it->first == real_it->first);
		REQUIRE(own_it->second == real_it->second);
		++own_it;
		++real_it;
	}
	
	std::map<int, int>	real2;
	ft::map<int, int>	own2;

	own2 = own;
	real2 = real;
	
	REQUIRE(own2.size() == real2.size());
	REQUIRE(own2.empty() == real2.empty());
	
	real_it = real2.begin();
	own_it = own2.begin();
	while (own_it != own2.end())
	{
		REQUIRE(own_it->first == real_it->first);
		REQUIRE(own_it->second == real_it->second);
		++own_it;
		++real_it;
	}
}

// /*-----------------ITERATORS-----------------*/
TEST_CASE("map-begin function", "[map]")
{
	ft::map<int, int>	own;
	std::map<int, int>	real;

	int sum = 1;
	for (int i = 0; i < 6; ++i)
	{
		own.insert(ft::pair<int, int>(sum, sum));
		real.insert(std::pair<int, int>(sum, sum));
		sum += 1;
	}
	
	REQUIRE(own.size() == real.size());
	REQUIRE(own.empty() == real.empty());
	
	std::map<int, int>::iterator	real_it = real.begin();
	ft::map<int, int>::iterator		own_it = own.begin();
	
	while (own_it != own.end())
	{
		REQUIRE(own_it->first == real_it->first);
		REQUIRE(own_it->second == real_it->second);
		++own_it;
		++real_it;
	}
}

TEST_CASE("map-end function", "[map]")
{
	ft::map<int, int>	own;
	std::map<int, int>	real;

	int sum = 1;
	int random = 1;
	for (int i = 0; i < 6; ++i)
	{
		own.insert(ft::pair<int, int>(random, sum));
		real.insert(std::pair<int, int>(random, sum));
		sum += 1;
		random % 2 == 0 ? random += 4 : random *= 2;
	}
	
	REQUIRE(own.size() == real.size());
	REQUIRE(own.empty() == real.empty());
	
	std::map<int, int>::iterator	real_it = real.begin();
	ft::map<int, int>::iterator		own_it = own.begin();
	
	while (own_it != own.end())
	{
		REQUIRE(own_it->first == real_it->first);
		REQUIRE(own_it->second == real_it->second);
		++own_it;
		++real_it;
	}

	std::map<int, int>::iterator	real_ite = real.end();
	ft::map<int, int>::iterator		own_ite = own.end();
	
	--real_ite;
	--own_ite;
	--real_ite;
	--own_ite;
	own_it = own.begin();
	real_it = real.begin();
	while (real_it != real_ite)
	{
		REQUIRE(own_it->first == real_it->first);
		REQUIRE(own_it->second == real_it->second);
		++own_it;
		++real_it;
	}
}

TEST_CASE("map-rbegin function", "[map]")
{
	ft::map<int, int>	own;
	std::map<int, int>	real;

	int sum = 1;
	for (int i = 0; i < 6; ++i)
	{
		own.insert(ft::pair<int, int>(sum, sum));
		real.insert(std::pair<int, int>(sum, sum));
		sum += 1;
	}
	
	REQUIRE(own.size() == real.size());
	REQUIRE(own.empty() == real.empty());
	
	std::map<int, int>::reverse_iterator	real_it = real.rbegin();
	ft::map<int, int>::reverse_iterator		own_it = own.rbegin();
	
	++real_it;
	++own_it;
	REQUIRE(real_it->first == own_it->first);
	REQUIRE(real_it->second == own_it->second);
	
	while (own_it != own.rend())
	{
		REQUIRE(own_it->first == real_it->first);
		REQUIRE(own_it->second == real_it->second);
		++own_it;
		++real_it;
	}
}

TEST_CASE("map-rend function", "[map]")
{
	ft::map<int, int>	own;
	std::map<int, int>	real;

	int sum = 1;
	int random = 1;
	for (int i = 0; i < 6; ++i)
	{
		own.insert(ft::pair<int, int>(random, sum));
		real.insert(std::pair<int, int>(random, sum));
		sum += 1;
		random % 2 == 0 ? random += 4 : random *= 2;
	}
	
	REQUIRE(own.size() == real.size());
	REQUIRE(own.empty() == real.empty());
	
	std::map<int, int>::reverse_iterator	real_it = real.rbegin();
	ft::map<int, int>::reverse_iterator		own_it = own.rbegin();
	
	while (own_it != own.rend())
	{
		REQUIRE(own_it->first == real_it->first);
		REQUIRE(own_it->second == real_it->second);
		++own_it;
		++real_it;
	}

	std::map<int, int>::reverse_iterator	real_ite = real.rend();
	ft::map<int, int>::reverse_iterator		own_ite = own.rend();
	
	--real_ite;
	--own_ite;
	--real_ite;
	--own_ite;
	own_it = own.rbegin();
	real_it = real.rbegin();
	while (real_it != real_ite)
	{
		REQUIRE(own_it->first == real_it->first);
		REQUIRE(own_it->second == real_it->second);
		++own_it;
		++real_it;
	}
}

// /*-----------------CAPACITY-----------------*/
TEST_CASE("map-empty function", "[map]")
{
	ft::map<std::string, int>	own;
	std::map<std::string, int>	real;

	REQUIRE(own.empty() == real.empty());

	own.insert(ft::pair<std::string, int>("test", 1));
	real.insert(std::pair<std::string, int>("test", 1));

	REQUIRE(own.empty() == real.empty());
}

TEST_CASE("map-size function", "[map]")
{
	ft::map<std::string, int>	own;
	std::map<std::string, int>	real;

	own.insert(ft::pair<std::string, int>("try", 1));
	own.insert(ft::pair<std::string, int>("to", 1));
	own.insert(ft::pair<std::string, int>("do", 1));
	own.insert(ft::pair<std::string, int>("this", 1));

	real.insert(std::pair<std::string, int>("try", 1));
	real.insert(std::pair<std::string, int>("to", 1));
	real.insert(std::pair<std::string, int>("do", 1));
	real.insert(std::pair<std::string, int>("this", 1));
	
	REQUIRE(own.size() == real.size());

	std::map<std::string, int>::iterator	real_it = real.begin();
	ft::map<std::string, int>::iterator		own_it = own.begin();
	
	while (own_it != own.end())
	{
		REQUIRE(own_it->first == real_it->first);
		REQUIRE(own_it->second == real_it->second);
		++own_it;
		++real_it;
	}
	
	own.erase("try");
	real.erase("try");

	REQUIRE(own.size() == real.size());

	own.erase("to");
	real.erase("to");

	REQUIRE(own.size() == real.size());

	own.erase("do");
	real.erase("do");

	REQUIRE(own.size() == real.size());

	own.erase("this");
	real.erase("this");

	REQUIRE(own.size() == real.size());
	REQUIRE(own.empty() == real.empty());

}

TEST_CASE("map-max_size function", "[map]")
{
	ft::map<int, int>	own;
	std::map<int, int>	real;

	// REQUIRE(own.max_size() == real.max_size());
}


// /*-----------------ELEMENT ACCES-----------------*/
// TEST_CASE("map-operator[] function", "[map]")
// {
	
// }


// /*-----------------INSERT-----------------*/
// TEST_CASE("map-insert function", "[map]")
// {
	
// }

// TEST_CASE("map-erase function version 1", "[map]")
// {

// }

// TEST_CASE("map-erase function version 2", "[map]")
// {
// 	ft::map<int, int>	own;
// 	std::map<int, int>	real;

// 	REQUIRE(own.size() == real.size());
// 	REQUIRE(own.empty() == real.empty());

// 	// Delete only root
// 	own.insert(ft::pair<int, int>(6, 8));
// 	real.insert(std::pair<int, int>(6, 8));
// 	REQUIRE(own.size() == real.size());
// 	REQUIRE(own.empty() == real.empty());
// 	own.print_tree(own.getRoot());
// 	own.erase(6);
// 	real.erase(6);
// 	own.print_tree(own.getRoot());
// 	REQUIRE(own.size() == real.size());
// 	REQUIRE(own.empty() == real.empty());

// 	// Delete root with one right child
// 	own.insert(ft::pair<int, int>(6, 8));
// 	own.insert(ft::pair<int, int>(10, 8));
// 	real.insert(std::pair<int, int>(6, 8));
// 	real.insert(std::pair<int, int>(10, 8));
// 	REQUIRE(own.size() == real.size());
// 	REQUIRE(own.empty() == real.empty());
// 	own.print_tree(own.getRoot());
// 	own.erase(6);
// 	real.erase(6);
// 	own.print_tree(own.getRoot());
	
// 	std::cout << "Root: " << own.getRoot()->data.first << std::endl;

// 	REQUIRE(own.size() == real.size());
// 	REQUIRE(own.empty() == real.empty());
// 	own.erase(10);
// 	real.erase(10);

// 	// Delete root with one left Child
// 	own.insert(ft::pair<int, int>(6, 8));
// 	real.insert(std::pair<int, int>(6, 8));
// 	own.insert(ft::pair<int, int>(4, 8));
// 	real.insert(std::pair<int, int>(4, 8));
// 	REQUIRE(own.size() == real.size());
// 	REQUIRE(own.empty() == real.empty());
// 	own.print_tree(own.getRoot());
// 	own.erase(6);
// 	real.erase(6);
// 	own.print_tree(own.getRoot());

// 	std::cout << "Root: " << own.getRoot()->data.first << std::endl;

// 	REQUIRE(own.size() == real.size());
// 	REQUIRE(own.empty() == real.empty());
// 	own.erase(4);
// 	real.erase(4);
	
// 	own.print_tree(own.getRoot());

// 	// Delete Root with 2 children
// 	std::cout << "Delete Root with 2 children" << std::endl;
// 	own.insert(ft::pair<int, int>(15, 15));
// 	own.insert(ft::pair<int, int>(10, 10));
// 	own.insert(ft::pair<int, int>(20, 20));
// 	own.insert(ft::pair<int, int>(5, 5));
// 	own.insert(ft::pair<int, int>(19, 19));
// 	own.insert(ft::pair<int, int>(25, 25));
// 	own.insert(ft::pair<int, int>(13, 13));

// 	real.insert(std::pair<int, int>(15, 15));
// 	real.insert(std::pair<int, int>(10, 10));
// 	real.insert(std::pair<int, int>(20, 20));
// 	real.insert(std::pair<int, int>(5, 5));
// 	real.insert(std::pair<int, int>(19, 19));
// 	real.insert(std::pair<int, int>(25, 25));
// 	real.insert(std::pair<int, int>(13, 13));
	
// 	own.print_tree(own.getRoot());
// 	REQUIRE(own.size() == real.size());
// 	REQUIRE(own.empty() == real.empty());
// 	own.erase(6);
// 	real.erase(6);
// 	own.print_tree(own.getRoot());

// 	REQUIRE(own.size() == real.size());
// 	REQUIRE(own.empty() == real.empty());

// 	// Delete a Leaf Node Max
// 	own.erase(25);
// 	real.erase(25);
// 	own.print_tree(own.getRoot());
// 	REQUIRE(own.size() == real.size());
// 	REQUIRE(own.empty() == real.empty());

// 	// Delete a Leaf Node Min
// 	own.erase(5);
// 	real.erase(5);
// 	own.print_tree(own.getRoot());
// 	REQUIRE(own.size() == real.size());
// 	REQUIRE(own.empty() == real.empty());

// 	// Delete with only one Son and is the Min Node
// 	own.erase(10);
// 	real.erase(10);
// 	own.print_tree(own.getRoot());
// 	REQUIRE(own.size() == real.size());
// 	REQUIRE(own.empty() == real.empty());

// 	// Delete with only one Son and is the Max Node
// 	own.erase(20);
// 	real.erase(20);
// 	own.print_tree(own.getRoot());
// 	REQUIRE(own.size() == real.size());
// 	REQUIRE(own.empty() == real.empty());

// 	own.insert(ft::pair<int, int>(15, 15));
// 	own.insert(ft::pair<int, int>(10, 10));
// 	own.insert(ft::pair<int, int>(20, 20));
// 	own.insert(ft::pair<int, int>(5, 5));
// 	own.insert(ft::pair<int, int>(19, 19));
// 	own.insert(ft::pair<int, int>(25, 25));
// 	own.insert(ft::pair<int, int>(13, 13));

// 	real.insert(std::pair<int, int>(15, 15));
// 	real.insert(std::pair<int, int>(10, 10));
// 	real.insert(std::pair<int, int>(20, 20));
// 	real.insert(std::pair<int, int>(5, 5));
// 	real.insert(std::pair<int, int>(19, 19));
// 	real.insert(std::pair<int, int>(25, 25));
// 	real.insert(std::pair<int, int>(13, 13));

// 	// Delete a node which has two sons
// 	own.erase(20);
// 	real.erase(20);
// 	own.print_tree(own.getRoot());
// 	REQUIRE(own.size() == real.size());
// 	REQUIRE(own.empty() == real.empty());
// }

// TEST_CASE("map-erase function version 3", "[map]")
// {

// }

// TEST_CASE("map-swap function", "[map]")
// {
	
// }

// TEST_CASE("map-clear function", "[map]")
// {
	
// }

// /*-----------------OBSERVERS-----------------*/
// TEST_CASE("map-key_comp function", "[map]")
// {
	
// }

// TEST_CASE("map-value_comp function", "[map]")
// {
	
// }

// /*-----------------OPERATIONS-----------------*/
// TEST_CASE("map-find function", "[map]")
// {
	
// }

// TEST_CASE("map-count function", "[map]")
// {
	
// }

// TEST_CASE("map-lower_bound function", "[map]")
// {
	
// }

// TEST_CASE("map-upper_bound function", "[map]")
// {
	
// }

// TEST_CASE("map-equal range function", "[map]")
// {
	
// }

