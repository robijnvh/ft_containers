/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-hou <rvan-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 15:43:58 by rvan-hou          #+#    #+#             */
/*   Updated: 2021/04/06 16:15:56 by rvan-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
# define LIST_HPP

# include "utils/listNode.hpp"
# include "utils/traits.hpp"

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
		explicit	list(const Alloc& alloc = Alloc()) : // constructs empty list, no elements
			_allocator(alloc),
			_size(0) {
				_first = new listNode<T>();
				_last = new listNode<T>();
				_first->_next = _last;
				_last->_prev = _first;
			}
		explicit	list(size_t n, const T& val = T(), const Alloc& alloc = Alloc()) :
			_allocator(alloc),
			_size(0) {
				_first = new listNode<T>();
				_last = new listNode<T>();
				_first->_next = _last;
				_last->_prev = _first;
				assign(n, val);
			}
		template <class InputIterator>
		list(typename enable_if<is_input_iterator<InputIterator>::value, InputIterator>::type first, InputIterator last, const Alloc& alloc = Alloc()) :
			_allocator(alloc),
			_size(0) {
				_first = new listNode<T>();
				_last = new listNode<T>();
				_first->_next = _last;
				_last->_prev = _first;
				assign(first, last);
			}
		list(const list& other) :
			_allocator(other._allocator),
			_size(0) {
				assign(other.begin(), other.end());
			}
		~list() {
			// destroy
		}
}

} // namespace

#endif
