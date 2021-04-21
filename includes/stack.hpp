/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: robijnvanhouts <robijnvanhouts@student.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/19 11:12:44 by robijnvanho   #+#    #+#                 */
/*   Updated: 2021/04/21 12:10:59 by robijnvanho   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

# include "utils/utils.hpp"
# include <deque>
// # include <iostream> // to print

namespace ft {

template<class T, class Container = std::deque<T> >
class stack {
	public:
		typedef Container										container_type;

	protected:
		container_type	_container; // protected because friend relational operators

	public:
		// CONSTRUCTOR
		explicit	stack(container_type const& ctnr = container_type()) : // constructs stack container adaptor object type ctnr
			_container(ctnr) {
		}
		// MEMBER FUNCTIONS
		bool	empty() const { // returns whether stack is empty
			return (_container.size() == 0);
		}
		size_t	size() const { // returns size (nb of elements)
			return (_container.size());
		}
		T&	top() { // calls back()
			return (_container.back());
		}
		T const&	top() const {
			return (_container.back());
		}
		void	push(T const& val) { // calls push_back()
			_container.push_back(val);
		}
		void	pop() { // calls pop_back()
			_container.pop_back();
		}
		// RELATIONAL OPERATORS
		template <class T2, class Contain>
		friend bool	operator==(const stack<T2,Contain>& lhs, const stack<T2,Contain>& rhs);
		template <class T2, class Contain>
		friend bool	operator<(const stack<T2,Contain>& lhs, const stack<T2,Contain>& rhs);
	}; // class stack
	
	// // RELATIONAL OPERATORS
	template <class T, class Container>
	bool	operator==(const stack<T,Container>& lhs, const stack<T,Container>& rhs)  {
		return (lhs._container == rhs._container);
	}
	template <class T, class Container>
	bool	operator!=(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return (!(lhs == rhs));
	}
	template <class T, class Container>
	bool	operator<(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return (lhs._container < rhs._container);
	}
	template <class T, class Container>
	bool	operator<=(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return (lhs < rhs || lhs == rhs);
	}
	template <class T, class Container>
	bool	operator>(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return (!(lhs <= rhs));
	}
	template <class T, class Container>
	bool	operator>=(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return (!(lhs < rhs));
	}
} // namespace ft

#endif