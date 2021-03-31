/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   nodeList.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: robijnvanhouts <robijnvanhouts@student.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/18 14:55:07 by robijnvanho   #+#    #+#                 */
/*   Updated: 2021/03/18 15:01:17 by robijnvanho   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODELIST_HPP
#define NODELIST_HPP

namespace ft {

template<typename T>
class listNode {
	public:
		listNode*	_prev;
		listNode*	_next;
		T			_data;

		// COPLIEN
		explicit listNode() :
			_prev(NULL),
			_next(NULL),
			_data() {}
		explicit listNode(T const& data) :
			_prev(NULL),
			_next(NULL),
			_data(data) {}
		~listNode() {}
		listNode&	operator=(listNode const& other) {
			if (this != other) {
				_prev = other._prev;
				_next = other._next;
				_data = other._data;
			}
			return *this;
		}
		// GETTERS
		listNode*	getNext() {
			return _next;
		}
		listNode*	getPrev() {
			return _prev;
		}
};
}

#endif
