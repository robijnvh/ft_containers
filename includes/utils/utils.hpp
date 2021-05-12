/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-hou <rvan-hou@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/19 12:21:26 by robijnvanho   #+#    #+#                 */
/*   Updated: 2021/05/12 15:44:10 by rvan-hou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP
# include "utils/traits.hpp"
# include <exception>
# include <iostream>

namespace ft {
	template <class InputIterator1, class InputIterator2>
	bool	lexicographical_compare(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2) {
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
	
	template <class T>
	class allocator {
		public:
			typedef T	value_type;
			typedef T*	pointer;
			typedef T&	reference;
			typedef const T	const_pointer;
			typedef const T&	const_reference;
			typedef size_t	size_type;
			typedef long int	difference_type;

		// COPLIEN
		allocator() throw() {
		}
		allocator(const allocator&) throw() {
		}
		template <class U>
		allocator(const allocator<U>&) throw() {
		}
		~allocator() throw() {
		}
		// MEMBER FUNCTIONS
		pointer	address(reference x) const {
			return &x;
		}
		const_pointer	address(const_reference x) const {
			return &x;
		}
		pointer	allocate(size_type n) {
			pointer ret;
			size_t size = n * sizeof(value_type);
			try {
				ret = reinterpret_cast<pointer>(::operator new(size));
			}
			catch(const std::exception& e) {
				std::cerr << e.what() << '\n';
			}
			return ret;
		}
		void	deallocate(pointer p, size_type n) {
			(void)n;
			::operator delete(p);
		}
		void	construct(pointer p, const T& v) {
			new((void*)p)T(v);
		}
		void	destroy(pointer p) {
			p->~T();
		}
	}; // allocator
} // namespace ft


#endif