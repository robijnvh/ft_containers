/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   listNode.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-hou <rvan-hou@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/06 16:01:46 by rvan-hou      #+#    #+#                 */
/*   Updated: 2021/04/09 12:12:37 by robijnvanho   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LISTNODE_HPP
# define LISTNODE_HPP

namespace ft {

template<typename T>
class listNode {
	public:
		listNode*	_prev;
		listNode*	_next;
		T			_data;

		explicit listNode() : // constructs empty node
			_prev(0),
			_next(0),
			_data(0) {}
		explicit listNode(const T &data) : // constructs node with data
			_prev(0), 
			_next(0),
			_data(data) {}
		~listNode() {
		} // destructor
        listNode& operator=(listNode const &other) {
            if (this != other) {
                this->_prev = other._prev;
                this->_next = other._next;
                this->_data = other._data;
            }
            return (*this);
        }
        listNode *getNext() {
			return (this->_next);
		}
        listNode *getPrev() {
			return (this->_prev);
		}
    }; // class listNode
} // namespace

#endif
