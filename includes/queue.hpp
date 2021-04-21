/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   queue.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: robijnvanhouts <robijnvanhouts@student.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/19 12:58:02 by robijnvanho   #+#    #+#                 */
/*   Updated: 2021/04/21 12:06:11 by robijnvanho   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_HPP
# define QUEUE_HPP

# include "utils/utils.hpp"
# include <deque>
// # include <iostream> // to print

namespace ft {

template<class T, class Container = std::deque<T> >
class queue {
	public:
		typedef Container										container_type;

	protected:
		container_type	_container; // protected because friend relational operators

	public:
		// CONSTRUCTOR
		explicit	queue(container_type const& ctnr = container_type()) : // constructs queue container adaptor object type ctnr
			_container(ctnr) {
		}
		// MEMBER FUNCTIONS
		bool	empty() const { // returns whether queue is empty
			return (_container.size() == 0);
		}
		size_t	size() const { // returns size (nb of elements)
			return (_container.size());
		}
		T&	front() { // calls front()
			return (_container.front());
		}
		T const&	front() const {
			return (_container.front());
		}
		T&	back() { // calls back()
			return (_container.back());
		}
		T const&	back() const {
			return (_container.back());
		}
		void	push(T const& val) { // calls push_back()
			_container.push_back(val);
		}
		void	pop() { // calls pop_front()
			_container.pop_front();
		}
		// RELATIONAL OPERATORS
		template <class T2, class Contain>
		friend bool	operator==(const queue<T2,Contain>& lhs, const queue<T2,Contain>& rhs);
		template <class T2, class Contain>
		friend bool	operator<(const queue<T2,Contain>& lhs, const queue<T2,Contain>& rhs);
	}; // class queue
	
	// RELATIONAL OPERATORS
	template <class T, class Container>
	bool	operator==(const queue<T,Container>& lhs, const queue<T,Container>& rhs)  {
		return (lhs._container == rhs._container);
	}
	template <class T, class Container>
	bool	operator!=(const queue<T,Container>& lhs, const queue<T,Container>& rhs) {
		return (!(lhs == rhs));
	}
	template <class T, class Container>
	bool	operator<(const queue<T,Container>& lhs, const queue<T,Container>& rhs) {
		return (lhs._container < rhs._container);
	}
	template <class T, class Container>
	bool	operator<=(const queue<T,Container>& lhs, const queue<T,Container>& rhs) {
		return (lhs < rhs || lhs == rhs);
	}
	template <class T, class Container>
	bool	operator>(const queue<T,Container>& lhs, const queue<T,Container>& rhs) {
		return (!(lhs <= rhs));
	}
	template <class T, class Container>
	bool	operator>=(const queue<T,Container>& lhs, const queue<T,Container>& rhs) {
		return (!(lhs < rhs));
	}
} // namespace ft

#endif