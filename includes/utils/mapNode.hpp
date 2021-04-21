/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mapNode.hpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-hou <rvan-hou@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/20 12:15:30 by rvan-hou      #+#    #+#                 */
/*   Updated: 2021/04/21 16:40:35 by robijnvanho   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPNODE_HPP
# define MAPNODE_HPP

namespace ft {

template<typename T>
class mapNode {
	public:
		mapNode*	_parent;
		mapNode*	_left;
		mapNode*	_right;
		T			_data;

		explicit mapNode() : // constructs empty node
			_parent(NULL),
			_left(NULL),
			_right(NULL),
			_data() {}
		explicit mapNode(const T &data) : // constructs node with data
			_parent(NULL),
			_left(NULL),
			_right(NULL),
			_data(data) {}
		mapNode(const mapNode &other) : // constructs node as copy of other
			_parent(other._parent),
			_left(other._left),
			_right(other._right),
			_data(other._data) {}
		~mapNode() {
		} // destructor
        mapNode& operator=(mapNode const& other) {
            if (this != other) {
                this->_parent = other._parent;
                this->_left = other._next;
                this->_right = other._right;
                this->_data = other._data;
            }
            return (*this);
        }
		mapNode*	getNext() {
			mapNode*	tmp;
			mapNode*	move;

			move = this;
			if (move->_right) { // one step right and left as far as possible
				move = move->_right;
				while (move->_left)
					move = move->_left;
				return (move);
			}
			tmp = move->_parent;
			while (tmp && move == tmp->_right) { // 
				move = tmp;
				tmp = tmp->_parent;
			}
			if (!tmp) {
				while (move->_left != NULL)
					move = move->_left;
				tmp = move->_left;
			}
			return (tmp);
		}
		mapNode*	getPrev() {
			mapNode*	tmp;
			mapNode*	move;

			move = this;
			if (move->_left) { // one step left and right as far as possible
				move = move->_left;
				while (move->_right)
					move = move->_right;
				return (move);
			}
			tmp = move->_parent;
			while (tmp && move == tmp->_left) { // 
				move = tmp;
				tmp = tmp->_parent;
			}
			if (!tmp) {
				while (move->_right != NULL)
					move = move->_right;
				tmp = move->_right;
			}
			return (tmp);
		}
    }; // class mapNode
} // namespace

#endif