/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-hou <rvan-hou@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/06 15:43:58 by rvan-hou      #+#    #+#                 */
/*   Updated: 2021/04/16 14:09:06 by robijnvanho   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
# define LIST_HPP

# include "utils/listNode.hpp"
# include "utils/BidirectionalIterator.hpp"
# include "utils/traits.hpp"
# include <memory>
# include <limits>
# include <cstddef>
# include <iostream> // to print


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

		void	move(iterator it_list, iterator it_add) { // move element from other list into current list without copy
			listNode<T>* list = it_list.get_ptr();
			listNode<T>* add = it_add.get_ptr();
			add->_prev->_next = add->_next;
			add->_next->_prev = add->_prev;
			
			add->_prev = list->_prev;
			add->_next = list;
			list->_prev->_next = add;
			list->_prev = add;
		}
		void	swap_nodes(listNode<T>* it) {
			listNode<T>* zero = it->_prev->_prev;
			listNode<T>* first = it->_prev;
			listNode<T>* second = it;
			listNode<T>* third = it->_next;

			zero->_next = second;
			first->_next = third;
			first->_prev = second;
			second->_next = first;
			second->_prev = zero;
			third->_prev = first;
		}
		void	print(void) {
			iterator it = begin();
			std::cout << "List:";
			while (it != end()) {
				std::cout << " " << *it;
				it++;
			}
			std::cout << std::endl;
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
			// if (position == end()) // not sure
			// 	return position;
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
		void	splice(iterator position, list& x) { // takes all elements from x into list
			for (; x._size != 0; x._size--) {
				move(position, x.begin());
				_size++;
			}
		}	
		void	splice(iterator position, list& x, iterator i) { // takes single element i from x and moves into current list
			move(position, i);
			_size++;
			x._size--;
		}
		void	splice(iterator position, list& x, iterator first, iterator last) { // takes range of elements from x into current list
			list tmp(first, last);
			splice(position, tmp);
			_size += tmp._size;
			x._size -= tmp._size;
		}
		void	remove(T const& val) { // removes elements based on value
			iterator it = begin();
			while (it != end()) {
				if (*it == val)
					erase(it);
				it++;
			}
		}
		template <class Predicate>
		void 	remove_if(Predicate pred) { // removes if pred returns true
			iterator it = begin();
			while (it != end()) {
				if (pred(*it))
					erase(it);
				it++;
			}
		}
		void	unique(void) { // removes all but the first element in a direct row of equal elements
			iterator it = begin();
			it++;
			while (it != end()) {
				if (*it == it.get_ptr()->_prev->_data)
					it = erase(it);
				else
					it++;
			}
		}
		template <class BinaryPredicate>
		void	unique(BinaryPredicate binary_pred) { // removes if bin_pred returns true
			iterator it = begin();
			it++;
			while (it != end()) {
				if (binary_pred(*it, it.get_ptr()->_prev->_data) == true)
					it = erase(it);
				else
					it++;
			}
		}
		void	merge(list& x) { // merge two lists and sort <
			if (*this != x) {
				splice(begin(), x);
				sort();
			}
		}
		template <class Compare>
		void	merge(list& x, Compare comp) { // merge two lists based on comp
			if (*this != x) {
				splice(begin(), x);
				sort(comp);
			}	
		}
		void	sort(void) { // sort based on operator<
			iterator it = begin();
			it++;
			while (it != end()) {
				if (*it < it.get_ptr()->_prev->_data) {
					swap_nodes(it.get_ptr());
					it = begin();
				}
				it++;
			}
		}
		template <class Compare>
		void	sort(Compare comp) { // sort based on comp
			iterator it = begin();
			it++;
			while (it != end()) {
				if (comp(*it, it.get_ptr()->_prev->_data) == true) {
					swap_nodes(it.get_ptr());
					it = begin();
				}
				it++;
			}
		}
		void	reverse() { // reverses list
			listNode<T>* current = _first;
			listNode<T>* tmp;
			while (current != NULL) {
				tmp = current->_next;
				current->_next = current->_prev;
				current->_prev = tmp;
				current = tmp;
			}
			tmp = _first;
			_first = _last;
			_last = tmp;
		}
		// OBSERVERS
		Alloc	get_allocator() const {
			return this->_allocator;
		}
	}; // class list

	template <class InputIterator1, class InputIterator2>
	bool	lexicographical_compare_list(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2) {
		while (first1!=last1) {
			if (first2==last2 || *first2<*first1) return false;
			else if (*first1<*first2) return true;
			++first1; ++first2;
		}
		return (first2!=last2);
	}

	template <class InputIterator1, class InputIterator2>
	bool	equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2) {
		while (first1!=last1) {
			if (!(*first1 == *first2))
				return false;
			++first1;
			++first2;
		}
		return true;
	}

	// RELATIONAL OPERATORS
	template <class T, class Alloc>
	bool	operator==(const ft::list<T,Alloc>& lhs, const ft::list<T,Alloc>& rhs) {
		return (lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}
	template <class T, class Alloc>
	bool	operator!=(const ft::list<T,Alloc>& lhs, const ft::list<T,Alloc>& rhs) {
		return !(lhs == rhs);
	}
	template <class T, class Alloc>
	bool	operator<(const ft::list<T,Alloc>& lhs, const ft::list<T,Alloc>& rhs) {
		return (ft::lexicographical_compare_list(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}
	template <class T, class Alloc>
	bool	operator<=(const ft::list<T,Alloc>& lhs, const ft::list<T,Alloc>& rhs) {
		return !(rhs < lhs);
	}
	template <class T, class Alloc>
	bool	operator>(const ft::list<T,Alloc>& lhs, const ft::list<T,Alloc>& rhs) {
		return (rhs < lhs);
	}
	template <class T, class Alloc>
	bool	operator>=(const ft::list<T,Alloc>& lhs, const ft::list<T,Alloc>& rhs) {
		return !(lhs < rhs);
	}

	// SWAP 
	template <class T, class Alloc>
	void	swap(list<T,Alloc>& x, list<T,Alloc>& y) {
		list<T, Alloc> tmp(y);
		y = x;
		x = tmp;
	}
} // namespace

#endif
