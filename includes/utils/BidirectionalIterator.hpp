/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   BiDirectionalIterator.hpp                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: robijnvanhouts <robijnvanhouts@student.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/07 13:33:51 by robijnvanho   #+#    #+#                 */
/*   Updated: 2021/04/09 12:44:08 by robijnvanho   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIDIRECTIONALITERATOR_HPP
# define BIDIRECTIONALITERATOR_HPP
# include "listNode.hpp"
# include <cstddef>

namespace ft {

template<typename T, typename Node>
class BidirectionalIterator {
	public:
		typedef std::bidirectional_iterator_tag		iterator_category;
	private:
		Node*	_ptr;
	public:
		// COPLIEN
		BidirectionalIterator() :
			_ptr(NULL) {}
		explicit BidirectionalIterator(Node it) :
			_ptr(it) {}
		BidirectionalIterator(BidirectionalIterator const& other) {
			*this = other;
		}
		BidirectionalIterator&	operator=(BidirectionalIterator const& other) {
			if (this != &other)
				_ptr = other._ptr;
			return *this;
		}
		~BidirectionalIterator() {}
		// OPERATORS - DEREFERENCE
		T&	operator*() {
			return _ptr->_data;
		}
		T*	operator->() {
			return &_ptr->_data;
		}
		BidirectionalIterator&	operator++() {
			_ptr = _ptr->getNext();
			return (*this);
		}
		BidirectionalIterator	operator++(int) {
			BidirectionalIterator tmp(*this);
			_ptr = _ptr->getNext();
			return tmp;
		}
		BidirectionalIterator&	operator--() {
			_ptr = _ptr->getPrev();
			return (*this);
		}
		BidirectionalIterator	operator--(int) {
			BidirectionalIterator tmp(*this);
			_ptr = _ptr->getPrev();
			return (tmp);
		}
		// OPERATORS - COMPARING
		friend bool	operator==(BidirectionalIterator const& lhs, BidirectionalIterator const& rhs) {
			return (lhs._ptr == rhs._ptr);
		}
		friend bool	operator!=(BidirectionalIterator const& lhs, BidirectionalIterator const& rhs) {
			return !(lhs == rhs);
		}
		// GETTER
		T* const&	get_ptr() const {
			return _ptr;
		}
}; // class BidirectionalIterator

} // namespace


#endif
