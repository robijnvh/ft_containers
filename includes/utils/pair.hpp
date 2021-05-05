/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pair.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-hou <rvan-hou@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/20 14:08:18 by rvan-hou      #+#    #+#                 */
/*   Updated: 2021/05/05 11:41:47 by robijnvanho   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
# define PAIR_HPP

# include "utils.hpp"

namespace ft {

template<class T1, class T2>
struct pair {
	// member types
	T1 first;
	T2 second;

	// DEFAULT
	pair() : // constructs empty pair
		first(T1()),
		second(T2()) {}
	// COPY
	template< class U, class V > // constructs from U and V MINE
	pair(const pair<U, V>& p) :
		first(p.first),
		second(p.second) {}
	template< class U, class V > // constructs from U and V REAL
	pair(pair<U, V>& p) :
		first(p.first),
		second(p.second) {}
	pair(const pair &p) :
		first(p.first),
		second(p.second) {}
	// CONSTRUCTOR
	pair(const T1& x, const T2& y) : // constructs from x and y
		first(x),
		second(y) {}
	// OPERATOR=
	pair& operator=( const pair& other ) { // assignation operator
		if (&other != this) {
			first = other.first;
			second = other.second;
		}
		return (*this);
	}
}; // struct pair

// MAKE PAIR
template<class T1, class T2>
pair<T1, T2> make_pair(T1 x, T2 y) {
	pair<T1, T2> new_pair;

	new_pair.first = x;
	new_pair.second = y;
	return (new_pair);
}

// RELATIONAL OPERATORS
template <class T1, class T2>
bool	operator==(ft::pair<T1, T2> const& lhs, ft::pair<T1, T2> const& rhs) {
	return (lhs.first == rhs.first && lhs.second == rhs.second);
}
template <class T1, class T2>
bool	operator<(ft::pair<T1, T2> const& lhs, ft::pair<T1, T2> const& rhs) {
	return (lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second));
}
template <class T1, class T2>
bool	operator!=(ft::pair<T1, T2> const& lhs, ft::pair<T1, T2> const& rhs) {
	return !(lhs == rhs);
}
template <class T1, class T2>
bool	operator<=(ft::pair<T1, T2> const& lhs, ft::pair<T1, T2> const& rhs) {
	return !(rhs < lhs);
}
template <class T1, class T2>
bool	operator>(ft::pair<T1, T2> const& lhs, ft::pair<T1, T2> const& rhs) {
	return (rhs < lhs);
}
template <class T1, class T2>
bool	operator>=(ft::pair<T1, T2> const& lhs, ft::pair<T1, T2> const& rhs) {
	return !(lhs < rhs);
}

} // namespace ft
#endif