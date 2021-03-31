/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: robijnvanhouts <robijnvanhouts@student.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/17 12:21:43 by robijnvanho   #+#    #+#                 */
/*   Updated: 2021/03/18 14:42:12 by robijnvanho   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
# define LIST_HPP

# include <memory>

# include "utils/RandomAccessIterator.hpp"
# include "utils/traits.hpp"

namespace ft
{
template<class T, class Alloc = std::allocator<T> >
class List {
	public:
		// ALL TYPES
		typedef T	value_type;
		typedef Alloc	allocator_type;
		typedef T&	reference;
		typedef const T&	const_reference;
		typedef T*	pointer;
		typedef const T*	const_pointer;
		typedef std::ptrdiff_t	difference_type;
		typedef size_t	size_type;
        typedef RandomAccessIterator<T>	iterator;
        typedef ConstRandomAccessIterator<T>	const_iterator;
        typedef RevRandomAccessIterator<T>	reverse_iterator;
        typedef ConstRevRandomAccessIterator<T>	const_reverse_iterator;
	
	private:
		pointer			_container;
		allocator_type	_allocator;
		size_type		_size;
		size_type		_capacity;
	
	public:
		// CONSTRUCTORS
		explicit	Vector(allocator_type const& alloc = allocator_type()) : // constructs empty List, no elements
			_container(NULL),
			_allocator(alloc),
			_size(0),
			_capacity(0) {}
	
	
	};
} // namespace ft


#endif
