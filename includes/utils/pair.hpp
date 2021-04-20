/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pair.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-hou <rvan-hou@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/20 14:08:18 by rvan-hou      #+#    #+#                 */
/*   Updated: 2021/04/20 15:08:30 by rvan-hou      ########   odam.nl         */
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

	pair() : // constructs empty pair
		first(),
		second() {}
	pair(const T1& x, const T2& y) : // constructs from x and y
		first(x),
		second(y) {}
	template< class U1, class U2 > // constructs from U1 and U2 MINE
	pair(const pair<U1, U2>& p) :
		first(p.first),
		second(p.second) {}
	template< class U1, class U2 > // constructs from U1 and U2 REAL
	pair(const std::pair<U1, U2>& p) :
		first(p.first),
		second(p.second) {}
	pair& operator=( const pair& other ) { // assignation operator
		first = other.first;
		second = other.second;
		return (*this);
	}
}; // struct pair

// MAKE
template< class T1, class T2 >
pair<T1,T2>	make_pair(T1 t, T2 u) { // make pair
	pair<T1, T2> my_pair;

	my_pair.first = t;
	my_pair.second = u;
	return my_pair;
}

// RELATIONAL OPERATORS
template <class T1, class T2>
bool	operator==(ft::pair<T1, T2> const& lhs, ft::pair<T1, T2> const& rhs) {
	return (lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
}
template <class T1, class T2>
bool	operator!=(ft::pair<T1, T2> const& lhs, ft::pair<T1, T2> const& rhs) {
	return !(lhs == rhs);
}
template <class T1, class T2>
bool	operator<(ft::pair<T1, T2> const& lhs, ft::pair<T1, T2> const& rhs) {
	return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
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