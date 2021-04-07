/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   BiDirectionalIterator.hpp                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: robijnvanhouts <robijnvanhouts@student.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/07 13:33:51 by robijnvanho   #+#    #+#                 */
/*   Updated: 2021/04/07 13:42:10 by robijnvanho   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIDIRECTIONALITERATOR_HPP
# define BIDIRECTIONALITERATOR_HPP
# include "listNode.hpp"

namespace ft {

template<typename T, typename listNode>
class BidirectionalIterator {
	private:
		listNode	_ptr;
	public:
		// COPLIEN
		BidirectionalIterator() :
			_ptr(NULL) {}
		explicit BidirectionalIterator(listNode it) :
			_ptr(it);
		BidirectionalIterator(BidirectionalIterator const& other) {
			*this = other;
		}
		BidirectionalIterator&	operator=(BidirectionalIterator const& other) {
			if (this != &other)
				_ptr = other._ptr;
			return *this;
		}
		~BidirectionalIterator() {}
		
};

} // namespace


#endif
