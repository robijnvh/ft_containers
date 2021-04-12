/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list_test.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: timvancitters <timvancitters@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/09 13:31:52 by timvancitte   #+#    #+#                 */
/*   Updated: 2021/04/12 12:08:36 by timvancitte   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "catch.hpp"
#include <list>

#include "../INCLUDES/ft_list.hpp"

/*-----------------CONSTRUCTORS-----------------*/
TEST_CASE("Empty container constructor", "[list]")
{
	ft::list<int>	own;
	std::list<int>	real;

	REQUIRE(own.size() == real.size());
	REQUIRE(own.empty() == real.empty());
}

TEST_CASE("Fill constructor", "[list]")
{
	ft::list<int>	own(5, 100);
	std::list<int>	real(5, 100);

	REQUIRE(own.size() == real.size());
	REQUIRE(own.empty() == real.empty());
	REQUIRE(own.front() == real.front());
	REQUIRE(own.back() == real.back());
}

// TEST_CASE("Range constructor", "[list]")
// {
	
// }

// TEST_CASE("Copy constructor", "[list]")
// {
// 	ft::list<int>		own(6, 100);
// 	ft::list<int>		own2(own);
// 	std::list<int>		real(6, 100);
// 	std::list<int>		real2(real);


	
// 	REQUIRE(own2.size() == real2.size());
// 	REQUIRE(own2.empty() == real2.empty());
// 	REQUIRE(own2.front() == real2.front());
// 	REQUIRE(own2.back() == real2.back());
// }