/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-hou <rvan-hou@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/19 14:31:50 by robijnvanho   #+#    #+#                 */
/*   Updated: 2021/04/20 15:18:06 by rvan-hou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include "utils/traits.hpp"
# include "utils/utils.hpp"
# include "utils/mapNode.hpp"
# include "utils/pair.hpp"
# include "utils/BidirectionalIterator.hpp"
# include <memory>
# include <limits>
# include <iostream> // to print

namespace ft {
template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<std::pair<const Key,T> > >
class map {
	public:
		// TYPES
		typedef mapNode<T>*	node_pointer;
		typedef mapNode<T>	node;
		typedef BidirectionalIterator<T, node>	iterator;
		typedef ConstBidirectionalIterator<T, node>	const_iterator;
		typedef RevBidirectionalIterator<T, node>	reverse_iterator;
		typedef ConstRevBidirectionalIterator<T, node>	const_reverse_iterator;

	private:
		node_pointer	_root;
		node_pointer	_first;
		node_pointer	_last;
		Alloc			_allocator;
		size_t			_size;
		Compare			_comp;

	public:
		// CONSTRUCTORS
		explicit	map(const Compare& comp = Compare(), const Alloc& alloc = Alloc()) : // empty
			_allocator(alloc),
			_size(0),
			_comp(comp) {
				_root = new node();
				_first = new node();
				_last = new node();
				_first->_parent = _root;
				_last->_parent = _root;
				_root->_left = _first;
				_root->_right = _last;
			}	
		// template <class InputIterator>
		// map(typename enable_if<is_input_iterator<InputIterator>::value, InputIterator>::type first, InputIterator last, const Key& comp = Key(), const Alloc& alloc = Alloc()) : // fill with range
		// 	_allocator(alloc),
		// 	_size(0),
		// 	_comp(comp) {
		// 		_root = new node();
		// 		_first = new node();
		// 		_last = new node();
		// 		_first->_parent = _root;
		// 		_last->_parent = _root;
		// 		_root->_left = _first;
		// 		_root->_right = _last;
		// 		// insert(first, last);
		// 	}	
		// map(const map& x) : // copy
		// 	_allocator(x._allocator),
		// 	_size(x._size),
		// 	_comp(x._comp) {
		// 		_root = new node();
		// 		_first = new node();
		// 		_last = new node();
		// 		_first->_parent = _root;
		// 		_last->_parent = _root;
		// 		_root->_left = _first;
		// 		_root->_right = _last;
		// 		// insert(x.begin(), x.end());
		// 	}
		// DESTRUCTORS
		~map() {
			// clear();
			delete _root;
			delete _first;
			delete _last;
		}
		// ASSIGNATION OPERATOR
		map&	operator=(map const& other) {
			// clear();
			_allocator = other._allocator;
			_size = 0;
			_root = new node();
			_first = new node();
			_last = new node();
			_first->_parent = _root;
			_last->_parent = _root;
			_root->_left = _first;
			_root->_right = _last;;
			// insert(other.begin(), other.end());
			return *this;
		}
		// ITERATORS
		iterator begin() {
			return (iterator(_first->_parent));
		}
		const_iterator begin() const {
			return (const_iterator(_first->_parent));
		}
		iterator end() {
			return (iterator(_last));
		}
		const_iterator end() const {
			return (const_iterator(_last));
		}
		reverse_iterator rbegin() {
			return (reverse_iterator(_last->_parent));
		}
		const_reverse_iterator rbegin() const {
			return (const_reverse_iterator(_last));
		}
		reverse_iterator rend() {
			return (reverse_iterator(_first));
		}
		const_reverse_iterator rend() const {
			return (const_reverse_iterator(_first));
		}
		// CAPACITY
		bool	empty() const {
			return (_size == 0);
		}
		size_t	size() const {
			return _size;
		}
		size_t	max_size() const {
			return (std::numeric_limits<size_t>::max() / sizeof(mapNode<T>));
		}
		// MODIFIERS
	}; // class map
} // namespace ft

#endif