/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   BidirectionalIterator.hpp                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-hou <rvan-hou@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/07 13:33:51 by robijnvanho   #+#    #+#                 */
/*   Updated: 2021/04/20 14:24:06 by rvan-hou      ########   odam.nl         */
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
		typedef std::bidirectional_iterator_tag	iterator_category;
		typedef Node	*iterator_type;
	private:
		Node*	_ptr;
	public:
		// COPLIEN
		BidirectionalIterator() :
			_ptr(NULL) {}
		explicit BidirectionalIterator(iterator_type it) :
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
		iterator_type const&	get_ptr() const {
			return _ptr;
		}
}; // class BidirectionalIterator

template<typename T, typename Node>
class ConstBidirectionalIterator {
	public:
		typedef std::bidirectional_iterator_tag		iterator_category;
		typedef Node								*iterator_type;
	private:
		Node*	_ptr;
	public:
		// COPLIEN
		ConstBidirectionalIterator() :
			_ptr(NULL) {}
		explicit ConstBidirectionalIterator(iterator_type it) :
			_ptr(it) {}
		ConstBidirectionalIterator(BidirectionalIterator<T, Node> const& other) {
			_ptr = other.get_ptr();
		}
		ConstBidirectionalIterator&	operator=(ConstBidirectionalIterator const& other) {
			if (this != &other)
				_ptr = other._ptr;
			return *this;
		}
		~ConstBidirectionalIterator() {}
		// OPERATORS - DEREFERENCE
		T const&	operator*() {
			return _ptr->_data;
		}
		T const*	operator->() {
			return &_ptr->_data;
		}
		ConstBidirectionalIterator&	operator++() {
			_ptr = _ptr->getNext();
			return (*this);
		}
		ConstBidirectionalIterator	operator++(int) {
			ConstBidirectionalIterator tmp(*this);
			_ptr = _ptr->getNext();
			return tmp;
		}
		ConstBidirectionalIterator&	operator--() {
			_ptr = _ptr->getPrev();
			return (*this);
		}
		ConstBidirectionalIterator	operator--(int) {
			ConstBidirectionalIterator tmp(*this);
			_ptr = _ptr->getPrev();
			return (tmp);
		}
		// OPERATORS - COMPARING		
		friend bool	operator==(ConstBidirectionalIterator const& lhs, ConstBidirectionalIterator const& rhs) {
			return (lhs._ptr == rhs._ptr);
		}
		friend bool	operator!=(ConstBidirectionalIterator const& lhs, ConstBidirectionalIterator const& rhs) {
			return !(lhs == rhs);
		}
}; // class ConstBidirectionalIterator

template<typename T, typename Node>
class RevBidirectionalIterator {
	public:
		typedef std::bidirectional_iterator_tag		iterator_category;
		typedef Node								*iterator_type;
	private:
		Node*	_ptr;
	public:
		// COPLIEN
		RevBidirectionalIterator() :
			_ptr(NULL) {}
		explicit RevBidirectionalIterator(iterator_type it) :
			_ptr(it) {}
		RevBidirectionalIterator(RevBidirectionalIterator const& other) {
			*this = other;
		}
		RevBidirectionalIterator&	operator=(RevBidirectionalIterator const& other) {
			if (this != &other)
				_ptr = other._ptr;
			return *this;
		}
		~RevBidirectionalIterator() {}
		// OPERATORS - DEREFERENCE
		T&	operator*() {
			return _ptr->_data;
		}
		T*	operator->() {
			return &_ptr->_data;
		}
		RevBidirectionalIterator&	operator++() {
			_ptr = _ptr->getPrev();
			return (*this);
		}
		RevBidirectionalIterator	operator++(int) {
			RevBidirectionalIterator tmp(*this);
			_ptr = _ptr->getPrev();
			return tmp;
		}
		RevBidirectionalIterator&	operator--() {
			_ptr = _ptr->getNext();
			return (*this);
		}
		RevBidirectionalIterator	operator--(int) {
			RevBidirectionalIterator tmp(*this);
			_ptr = _ptr->getNext();
			return (tmp);
		}
		// OPERATORS - COMPARING
		friend bool	operator==(RevBidirectionalIterator const& lhs, RevBidirectionalIterator const& rhs) {
			return (lhs._ptr == rhs._ptr);
		}
		friend bool	operator!=(RevBidirectionalIterator const& lhs, RevBidirectionalIterator const& rhs) {
			return !(lhs == rhs);
		}
		// GETTER
		Node* const&	get_ptr() const {
			return _ptr;
		}
}; // class RevBidirectionalIterator

template<typename T, typename Node>
class ConstRevBidirectionalIterator {
	public:
		typedef std::bidirectional_iterator_tag		iterator_category;
		typedef Node								*iterator_type;
	private:
		Node*	_ptr;
	public:
		// COPLIEN
		ConstRevBidirectionalIterator() :
			_ptr(NULL) {}
		explicit ConstRevBidirectionalIterator(iterator_type it) :
			_ptr(it) {}
		ConstRevBidirectionalIterator(RevBidirectionalIterator<T, Node> const& other) {
			_ptr = other.get_ptr();
		}
		ConstRevBidirectionalIterator&	operator=(ConstRevBidirectionalIterator const& other) {
			if (this != &other)
				_ptr = other._ptr;
			return *this;
		}
		~ConstRevBidirectionalIterator() {}
		// OPERATORS - DEREFERENCE
		T&	operator*() {
			return _ptr->_data;
		}
		T*	operator->() {
			return &_ptr->_data;
		}
		ConstRevBidirectionalIterator&	operator++() {
			_ptr = _ptr->getPrev();
			return (*this);
		}
		ConstRevBidirectionalIterator	operator++(int) {
			ConstRevBidirectionalIterator tmp(*this);
			_ptr = _ptr->getPrev();
			return tmp;
		}
		ConstRevBidirectionalIterator&	operator--() {
			_ptr = _ptr->getNext();
			return (*this);
		}
		ConstRevBidirectionalIterator	operator--(int) {
			ConstRevBidirectionalIterator tmp(*this);
			_ptr = _ptr->getNext();
			return (tmp);
		}
		// OPERATORS - COMPARING
		friend bool	operator==(ConstRevBidirectionalIterator const& lhs, ConstRevBidirectionalIterator const& rhs) {
			return (lhs._ptr == rhs._ptr);
		}
		friend bool	operator!=(ConstRevBidirectionalIterator const& lhs, ConstRevBidirectionalIterator const& rhs) {
			return !(lhs == rhs);
		}
}; // class ConstRevBidirectionalIterator
} // namespace

#endif