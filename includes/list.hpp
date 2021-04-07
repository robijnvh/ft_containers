/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-hou <rvan-hou@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/06 15:43:58 by rvan-hou      #+#    #+#                 */
/*   Updated: 2021/04/07 13:30:38 by robijnvanho   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
# define LIST_HPP

# include "utils/listNode.hpp"
// # include "utils/traits.hpp"
# include <memory>
# include <limits>

namespace ft {

template<class T, class Alloc = std::allocator<T> >
class list {
	public:
	    // typedef listNode<T>*                                    node_pointer;
        // typedef listNode<T>                                     node;
	    // typedef BidirectionalIterator<T, node>                  iterator;
        // typedef ConstBidirectionalIterator<T, node>             const_iterator;
        // typedef RevBidirectionalIterator<T, node>               reverse_iterator;
        // typedef ConstRevBidirectionalIterator<T, node>          const_reverse_iterator;
	private:
		Alloc			_allocator;
		size_t			_size;
		listNode<T>*	_first;
		listNode<T>		_last;
	
	public:
		explicit	list(Alloc const& alloc = Alloc()) : // constructs empty list, no elements
			_allocator(alloc),
			_size(0) {
				_first = new listNode<T>();
				_last = new listNode<T>();
				_first->_next = _last;
				_last->_prev = _first;
			}
		explicit	list(size_t n, T const& val = T(), Alloc const& alloc = Alloc()) :
			_allocator(alloc),
			_size(0) {
				_first = new listNode<T>();
				_last = new listNode<T>();
				_first->_next = _last;
				_last->_prev = _first;
				for (size_t i = 0; i < n; i++) {
					listNode<T>* new_node = new listNode<T>(val);
					new_node->_next = _last;
					_last->_prev->_next = new_node;
					new_node->_prev = _last->_prev;
					_last->_prev = new_node;
					_size += 1;
				}
			}
		// template <class InputIterator>
		// list(typename enable_if<is_input_iterator<InputIterator>::value, InputIterator>::type first, InputIterator last, const Alloc& alloc = Alloc()) :
		// 	_allocator(alloc),
		// 	_size(0) {
		// 		_first = new listNode<T>();
		// 		_last = new listNode<T>();
		// 		_first->_next = _last;
		// 		_last->_prev = _first;
		// 		// assign(first, last);
		// 	}
		// list(const list& other) :
		// 	_allocator(other._allocator),
		// 	_size(0) {
		// 		// assign(other.begin(), other.end());
		// 	}
		~list() {
			// destroy
		}
		// list&	operator=(list const& other) {
        //     // clear();
        //     _first->_next = _last;
        //     _last->_prev = _first;
        //     for (; first != last; first++) {
		// 		listNode<T>* new_node = new listNode<T>(*first);
		// 		new_node->_next = _last;
		// 		_last->_prev->_next = new_node;
		// 		new_node->_prev = _last->_prev;
		// 		_last->_prev = new_node;
		// 		_size += 1;
		// 	}
        //     return(*this);
        // };
		
		// ITERATORS
		
		// CAPACITY
		size_t	size() const {
			return _size;
		}
		size_t	max_size() const {
			return (std::numeric_limits<size_t>::max() / sizeof(T));
		}
		bool	empty() const {
			return (_size == 0);
		}
		// ELEMENT ACCESS
		T&	front() {
			return _first;
		}
		T const& front() const {
			return _first;
		}
		T&	back() {
			return _last;
		}
		T const&	back() const {
			return _last;
		}
		// MODIFIERS
		// OPERATIONS
		// OBSERVERS
}; // class list

} // namespace

#endif
