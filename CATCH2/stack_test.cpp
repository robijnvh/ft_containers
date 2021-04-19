#include "catch.hpp"

#include <stack>
#include <string>
#include <vector>
#include "../includes/stack.hpp"
// #include <iostream> // to print

TEST_CASE( "stack", "[stack]" ) {
	std::deque<int> mydeque(5, 100);
	std::vector<int> myvector;
	for (int i = 0;  i < 10; i++) myvector.push_back(i);

    ft::stack<int> ft_stack1; // init empty
    std::stack<int> std_stack1; /// init empty

	ft::stack<int> ft_stack2(mydeque); // init as copy
    std::stack<int> std_stack2(mydeque); // init as copy

	ft::stack<int, std::vector<int>> ft_stack3(myvector); // init as copy
    std::stack<int, std::vector<int>> std_stack3(myvector); // init as copy

	SECTION("default constructor") {
		REQUIRE(ft_stack1.empty() == std_stack1.empty()); // empty stack
		REQUIRE(ft_stack2.empty() == std_stack2.empty()); // deque stack
		REQUIRE(ft_stack3.empty() == std_stack3.empty()); // vector stack
	}
	SECTION("empty") {
		REQUIRE(ft_stack1.empty() == std_stack1.empty());
		REQUIRE(ft_stack2.empty() == std_stack2.empty()); // check empty
		REQUIRE(ft_stack3.empty() == std_stack3.empty()); // check empty
	}
	SECTION("size") {
		REQUIRE(ft_stack1.size() == std_stack1.size());
    	REQUIRE(ft_stack2.size() == std_stack2.size()); // check size
    	REQUIRE(ft_stack3.size() == std_stack3.size()); // check size
	}
	SECTION("top") {
		// REQUIRE(ft_stack1.top() == std_stack1.top()); // sigsegv on empty stack
		REQUIRE(ft_stack2.top() == std_stack2.top()); // check deque top
    	REQUIRE(ft_stack3.top() == std_stack3.top()); // check vector top
	}
	SECTION("push") {
		ft_stack1.push(7);
		std_stack1.push(7);
		ft_stack2.push(7);
		std_stack2.push(7);
		ft_stack3.push(7);
		std_stack3.push(7);
		REQUIRE(ft_stack1.size() == std_stack1.size());
    	REQUIRE(ft_stack2.size() == std_stack2.size()); // check size
    	REQUIRE(ft_stack3.size() == std_stack3.size()); // check size
		REQUIRE(ft_stack1.top() == std_stack1.top());
		REQUIRE(ft_stack2.top() == std_stack2.top()); // check deque top
    	REQUIRE(ft_stack3.top() == std_stack3.top()); // check vector top
	}
	SECTION("pop") {
		// ft_stack1.pop(); // sigsegv on empty stack
		// std_stack1.pop();
		ft_stack2.pop();
		std_stack2.pop();
		ft_stack3.pop();
		std_stack3.pop();
    	REQUIRE(ft_stack2.size() == std_stack2.size()); // check size
    	REQUIRE(ft_stack3.size() == std_stack3.size()); // check size
		REQUIRE(ft_stack2.top() == std_stack2.top()); // check deque top
    	REQUIRE(ft_stack3.top() == std_stack3.top()); // check vector top
	}
	SECTION("relational operators") {
		std::deque<int> mydeque(5, 100);
		std::deque<int> mydeque2(4, 100);
		ft::stack<int> ft_stack(mydeque);
		ft::stack<int> ft_stack2(mydeque2);
		ft::stack<int> ft_stack3(mydeque);
		std::stack<int> std_stack(mydeque);
		std::stack<int> std_stack2(mydeque2);
		std::stack<int> std_stack3(mydeque);
		REQUIRE((ft_stack == ft_stack3) == true); // ==
		REQUIRE((ft_stack == ft_stack2) == false);
		REQUIRE((std_stack == std_stack3) == true);
		REQUIRE((std_stack == std_stack2) == false);
		REQUIRE((ft_stack != ft_stack3) == false); // !=
		REQUIRE((ft_stack != ft_stack2) == true);
		REQUIRE((std_stack != std_stack3) == false);
		REQUIRE((std_stack != std_stack2) == true);
		REQUIRE((ft_stack < ft_stack2) == false); // <
		REQUIRE((ft_stack2 < ft_stack3) == true);
		REQUIRE((std_stack < std_stack2) == false);
		REQUIRE((std_stack2 < std_stack3) == true);
		REQUIRE((ft_stack < ft_stack3) == false);
		REQUIRE((ft_stack <= ft_stack3) == true); // <=
		REQUIRE((std_stack < std_stack3) == false);
		REQUIRE((std_stack <= std_stack3) == true);
		REQUIRE((ft_stack > ft_stack2) == true); // >
		REQUIRE((ft_stack2 > ft_stack3) == false);
		REQUIRE((std_stack > std_stack2) == true);
		REQUIRE((std_stack2 > std_stack3) == false);
		REQUIRE((ft_stack > ft_stack3) == false);
		REQUIRE((ft_stack >= ft_stack3) == true);  // >=
		REQUIRE((std_stack > std_stack3) == false);
		REQUIRE((std_stack >= std_stack3) == true);
	}
	// SECTION("test std::string") {
	// 	std::vector<std::string> myvector2;
	// 	ft::stack<std::string> ft_stack(myvector2);
	// 	std::stack<std::string> std_stack(myvector2);
	// 	ft_stack.push("hi");
	// 	ft_stack.push("how");
	// 	ft_stack.push("are");
	// 	ft_stack.push("you");
	// 	std_stack.push("hi");
	// 	std_stack.push("how");
	// 	std_stack.push("are");
	// 	std_stack.push("you");
	// 	REQUIRE(ft_stack.empty() == std_stack.empty());
	// 	REQUIRE(ft_stack.size() == std_stack.size());
	// 	REQUIRE(ft_stack.top() == std_stack.top());
	// 	ft_stack.push("good!");
	// 	std_stack.push("good!");
	// 	REQUIRE(ft_stack.top() == "good!");
	// 	REQUIRE(ft_stack.top() == std_stack.top());
	// 	ft_stack.pop();
	// 	std_stack.pop();
	// 	REQUIRE(ft_stack.top() != "good!");
	// 	REQUIRE(ft_stack.top() == std_stack.top());
	// }
}
