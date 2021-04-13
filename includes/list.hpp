/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-hou <rvan-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 15:43:58 by rvan-hou          #+#    #+#             */
/*   Updated: 2021/04/13 16:17:46 by rvan-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
# define LIST_HPP

# include "utils/listNode.hpp"
# include "utils/BidirectionalIterator.hpp"
# include "utils/traits.hpp"
# include <memory>
# include <limits>

#include <iostream>


namespace ft {

template<class T, class Alloc = std::allocator<T> >
class list {
	public:
	    typedef listNode<T>*										node_pointer;
        typedef listNode<T>											node;
	    typedef BidirectionalIterator<T, node>						iterator;
        typedef ConstBidirectionalIterator<T, node>					const_iterator;
        typedef RevBidirectionalIterator<T, node>					reverse_iterator;
        typedef ConstRevBidirectionalIterator<T, node>				const_reverse_iterator;
	private:
		Alloc			_allocator;
		size_t			_size;
		node_pointer	_first;
		node_pointer	_last;

		template <class InputIterator>
		size_t	distance(InputIterator first, InputIterator second) { // returns dist between first and sec ptr
			size_t n = 0;
			for (InputIterator it = first; it != second; it++)
				n++;
			return n;
		}
	
	public:
		// CONSTRUCTORS
		explicit	list(Alloc const& alloc = Alloc()) : // constructs empty list, no elements
			_allocator(alloc),
			_size(0) {
				_first = new node();
				_last = new node();
				_first->_next = _last;
				_last->_prev = _first;
			}
		explicit	list(size_t n, T const& val = T(), Alloc const& alloc = Alloc()) :
			_allocator(alloc),
			_size(0) {
				_first = new node();
				_last = new node();
				_first->_next = _last;
				_last->_prev = _first;
				for (size_t i = 0; i < n; i++) {
					push_back(val);
				}
			}
		template <class InputIterator>
		list(typename enable_if<is_input_iterator<InputIterator>::value, InputIterator>::type first, InputIterator last, const Alloc& alloc = Alloc()) :
			_allocator(alloc),
			_size(0) {
				_first = new node();
				_last = new node();
				_first->_next = _last;
				_last->_prev = _first;
				assign(first, last);
			}
		list(list const& other) : // copy contructor
			_allocator(other._allocator),
			_size(0) {
				_first = new node();
				_last = new node();
				_first->_next = _last;
				_last->_prev = _first;
				assign(other.begin(), other.end());
			}
		// DESTRUCTORS
		~list() { // detroys
			clear();
			delete _first;
			delete _last;
		}
		// ASSIGNATION OPERATOR
		list&	operator=(list const& other) {
			clear();
			_allocator = other._allocator;
			_size = 0;
			_first = new node();
			_last = new node();
			_first->_next = _last;
			_last->_prev = _first;
			assign(other.begin(), other.end());
			return *this;
		}
		// ITERATORS
		iterator begin() {
			return (iterator(_first->_next));
		}
		const_iterator begin() const {
			return (const_iterator(_first->_next));
		}
		iterator end() { 
			return (iterator(_last));
		}
		const_iterator end() const { 
			return (const_iterator(_last));
		}
		reverse_iterator rbegin() {
			return (reverse_iterator(_last->_prev));
		}
		const_reverse_iterator rbegin() const {
			return (const_reverse_iterator(_last->_prev));
		}
		reverse_iterator rend() { 
			return (reverse_iterator(_first));
		}
		const_reverse_iterator rend() const { 
			return (const_reverse_iterator(_first));
		}
		// CAPACITY
		size_t	size() const {
			return _size;
		}
		size_t	max_size() const {
			return (std::numeric_limits<size_t>::max() / sizeof(listNode<T>));
		}
		bool	empty() const {
			return (_size == 0);
		}
		// ELEMENT ACCESS
		T&	front() {
			return (_first->_next->_data);
		}
		T const&	front() const {
			return (_first->_next->_data);
		}
		T&	back() {
			return (_last->_prev->_data);
		}
		T const&	back() const {
			return (_last->_prev->_data);
		}
		// MODIFIERS
		template <class InputIterator>
		void	assign(typename enable_if<is_input_iterator<InputIterator>::value, InputIterator>::type first, InputIterator last) {
			clear();
			for (; first != last; first++)
				push_back(*first);
		}
		void	assign(size_t n, T const& val) {
			clear();
			for (size_t i = 0; i < n; i++)
				push_back(val);
		}
		void	push_front(T const& val) {
			listNode<T>* tmp = new listNode<T>(val);
			tmp->_prev = _first;
			_first->_next->_prev = tmp;
			tmp->_next = _first->_next;
			_first->_next = tmp;
			_size += 1;
		}
		void	pop_front() {
			if (_size) {
				listNode<T>* tmp = _first->_next;
				_first->_next->_next->_prev = _first;
				_first->_next = _first->_next->_next;
				_size -= 1;
				delete tmp;
			}
		}
		void	push_back(T const& val) {
			listNode<T>* tmp = new listNode<T>(val);
			tmp->_next = _last;
			_last->_prev->_next = tmp;
			tmp->_prev = _last->_prev;
			_last->_prev = tmp;
			_size += 1;
		}
		void	pop_back() {
			if (_size) {
				listNode<T>* tmp = _last->_prev;
				_last->_prev->_prev->_next = _last;
				_last->_prev = _last->_prev->_prev;
				_size -= 1;
				delete tmp;
			}
		}
		iterator	insert(iterator position, T const& val) {
			listNode<T>* tmp = new listNode<T>(val);
			tmp->_next = position.get_ptr();
			position.get_ptr()->_prev->_next = tmp;
			tmp->_prev = position.get_ptr()->_prev;
			position.get_ptr()->_prev = tmp;
			_size += 1;
			return iterator(tmp);
		}
		void	insert(iterator position, size_t n, T const& val) {
			for (; n > 0; n--)
				insert(position, val);
		}
		template <class InputIterator>
		void	insert(iterator position, typename enable_if<is_input_iterator<InputIterator>::value, InputIterator>::type first, InputIterator last) {
			for (; first != last; first++)
				insert(position, *first);
		}
		iterator	erase(iterator position) {
			if (position == end()) // not sure
				return position;
			listNode<T>* tmp = position.get_ptr();
			tmp->_prev->_next = tmp->_next;
			tmp->_next->_prev = tmp->_prev;
			position++;
			_size -= 1;
			delete tmp;
			return position;
		}
		iterator	erase(iterator first, iterator last) {
			iterator ret(first);
			for (; first != last; first++) {
				erase(first);
			}
			return ret;
		}
		void	swap(list& other) { // swap lists
			list tmp(*this);
			*this = other;
			other = tmp;
		}
		void	resize(size_t n, T val = T()) {
			if (n < _size)
				_size -= (_size - n);
			while (n > _size)
				push_back(val);
		}
		void	clear() {
			for (; _size != 0;) {
				pop_back();
			}
		}
		// OPERATIONS
		// OBSERVERS
}; // class list

// template <class T, class Alloc>
// bool operator==(const ft::list<T,Alloc>& lhs, const ft::list<T,Alloc>& rhs) {
// 	return (lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
// }

} // namespace

#endif
