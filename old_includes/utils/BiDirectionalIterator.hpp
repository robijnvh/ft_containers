/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   BiDirectionalIterator.hpp                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: robijnvanhouts <robijnvanhouts@student.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/18 14:49:33 by robijnvanho   #+#    #+#                 */
/*   Updated: 2021/03/18 15:02:01 by robijnvanho   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIDIRECTIONALITERATOR_HPP
# define BIDIRECTIONALITERATOR_HPP

# include "nodeList.hpp"

namespace ft {

template<typename T, typename Node>
class BiDirectionalIterator {
	public:
		// ALL TYPES
		typedef std::bidirectional_iterator_tag         iterator_category;
        typedef Node                                    *iterator_type;
        typedef T                                       value_type;
        typedef std::ptrdiff_t                          difference_type;
        typedef T                                       *pointer;
        typedef T                                       &reference;
	
	private:
		iterator_type	_ptr;
	
	public:
		
};

}

#endif
