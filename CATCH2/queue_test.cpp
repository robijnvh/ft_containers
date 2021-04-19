#include "catch.hpp"

#include <queue>
#include <string>
#include <list>
#include "../includes/queue.hpp"
// #include <iostream> // to print

TEST_CASE( "queue", "[queue]" ) {
	std::deque<int> mydeque(5, 100);
	std::list<int> mylist;
	for (int i = 0;  i < 10; i++) mylist.push_back(i);

    ft::queue<int> ft_queue1; // init empty
    std::queue<int> std_queue1; /// init empty

	ft::queue<int> ft_queue2(mydeque); // init as copy
    std::queue<int> std_queue2(mydeque); // init as copy

	ft::queue<int, std::list<int>> ft_queue3(mylist); // init as copy
    std::queue<int, std::list<int>> std_queue3(mylist); // init as copy

	SECTION("default constructor") {
		REQUIRE(ft_queue1.empty() == std_queue1.empty()); // empty queue
		REQUIRE(ft_queue2.empty() == std_queue2.empty()); // deque queue
		REQUIRE(ft_queue3.empty() == std_queue3.empty()); // list queue
	}
	SECTION("empty") {
		REQUIRE(ft_queue1.empty() == std_queue1.empty());
		REQUIRE(ft_queue2.empty() == std_queue2.empty()); // check empty
		REQUIRE(ft_queue3.empty() == std_queue3.empty()); // check empty
	}
	SECTION("size") {
		REQUIRE(ft_queue1.size() == std_queue1.size());
    	REQUIRE(ft_queue2.size() == std_queue2.size()); // check size
    	REQUIRE(ft_queue3.size() == std_queue3.size()); // check size
	}
	SECTION("front") {
		// REQUIRE(ft_queue1.front() == std_queue1.front()); // sigsegv on empty queue
		REQUIRE(ft_queue2.front() == std_queue2.front()); // check deque front
    	REQUIRE(ft_queue3.front() == std_queue3.front()); // check list front
	}
	SECTION("back") {
		// REQUIRE(ft_queue1.back() == std_queue1.back()); // sigsegv on empty queue
		REQUIRE(ft_queue2.back() == std_queue2.back()); // check deque back
    	REQUIRE(ft_queue3.back() == std_queue3.back()); // check list back
	}
	SECTION("push") {
		ft_queue1.push(7);
		std_queue1.push(7);
		ft_queue2.push(7);
		std_queue2.push(7);
		ft_queue3.push(7);
		std_queue3.push(7);
		REQUIRE(ft_queue1.size() == std_queue1.size());
    	REQUIRE(ft_queue2.size() == std_queue2.size()); // check size
    	REQUIRE(ft_queue3.size() == std_queue3.size()); // check size
		REQUIRE(ft_queue1.front() == std_queue1.front());
		REQUIRE(ft_queue1.back() == std_queue1.back());
		REQUIRE(ft_queue2.front() == std_queue2.front()); // check deque front
		REQUIRE(ft_queue2.back() == std_queue2.back()); // check deque back
    	REQUIRE(ft_queue3.front() == std_queue3.front()); // check list front
    	REQUIRE(ft_queue3.back() == std_queue3.back()); // check list back
	}
	SECTION("pop") {
		// ft_queue1.pop(); // sigsegv on empty queue
		// std_queue1.pop();
		ft_queue2.pop();
		std_queue2.pop();
		ft_queue3.pop();
		std_queue3.pop();
    	REQUIRE(ft_queue2.size() == std_queue2.size()); // check size
    	REQUIRE(ft_queue3.size() == std_queue3.size()); // check size
		REQUIRE(ft_queue2.front() == std_queue2.front()); // check deque front
		REQUIRE(ft_queue2.back() == std_queue2.back()); // check deque back
    	REQUIRE(ft_queue3.front() == std_queue3.front()); // check list front
    	REQUIRE(ft_queue3.back() == std_queue3.back()); // check list back
	}
	SECTION("relational operators") {
		std::deque<int> mydeque(5, 100);
		std::deque<int> mydeque2(4, 100);
		ft::queue<int> ft_queue(mydeque);
		ft::queue<int> ft_queue2(mydeque2);
		ft::queue<int> ft_queue3(mydeque);
		std::queue<int> std_queue(mydeque);
		std::queue<int> std_queue2(mydeque2);
		std::queue<int> std_queue3(mydeque);
		REQUIRE((ft_queue == ft_queue3) == true); // ==
		REQUIRE((ft_queue == ft_queue2) == false);
		REQUIRE((std_queue == std_queue3) == true);
		REQUIRE((std_queue == std_queue2) == false);
		REQUIRE((ft_queue != ft_queue3) == false); // !=
		REQUIRE((ft_queue != ft_queue2) == true);
		REQUIRE((std_queue != std_queue3) == false);
		REQUIRE((std_queue != std_queue2) == true);
		REQUIRE((ft_queue < ft_queue2) == false); // <
		REQUIRE((ft_queue2 < ft_queue3) == true);
		REQUIRE((std_queue < std_queue2) == false);
		REQUIRE((std_queue2 < std_queue3) == true);
		REQUIRE((ft_queue < ft_queue3) == false);
		REQUIRE((ft_queue <= ft_queue3) == true); // <=
		REQUIRE((std_queue < std_queue3) == false);
		REQUIRE((std_queue <= std_queue3) == true);
		REQUIRE((ft_queue > ft_queue2) == true); // >
		REQUIRE((ft_queue2 > ft_queue3) == false);
		REQUIRE((std_queue > std_queue2) == true);
		REQUIRE((std_queue2 > std_queue3) == false);
		REQUIRE((ft_queue > ft_queue3) == false);
		REQUIRE((ft_queue >= ft_queue3) == true);  // >=
		REQUIRE((std_queue > std_queue3) == false);
		REQUIRE((std_queue >= std_queue3) == true);
	}
	// SECTION("test std::string") {
	// 	std::list<std::string> mylist2;
	// 	ft::queue<std::string> ft_queue(mylist2);
	// 	std::queue<std::string> std_queue(mylist2);
	// 	ft_queue.push("hi");
	// 	ft_queue.push("how");
	// 	ft_queue.push("are");
	// 	ft_queue.push("you");
	// 	std_queue.push("hi");
	// 	std_queue.push("how");
	// 	std_queue.push("are");
	// 	std_queue.push("you");
	// 	REQUIRE(ft_queue.empty() == std_queue.empty());
	// 	REQUIRE(ft_queue.size() == std_queue.size());
	// 	REQUIRE(ft_queue.top() == std_queue.top());
	// 	ft_queue.push("good!");
	// 	std_queue.push("good!");
	// 	REQUIRE(ft_queue.top() == "good!");
	// 	REQUIRE(ft_queue.top() == std_queue.top());
	// 	ft_queue.pop();
	// 	std_queue.pop();
	// 	REQUIRE(ft_queue.top() != "good!");
	// 	REQUIRE(ft_queue.top() == std_queue.top());
	// }
}
