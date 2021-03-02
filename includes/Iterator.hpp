/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Iterator.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-hou <rvan-hou@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/02 11:29:42 by rvan-hou      #+#    #+#                 */
/*   Updated: 2021/03/02 11:42:40 by rvan-hou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

// # include "Node.hpp"

namespace ft {

template<typename It>
class ReverseIterator : public It {
	public:
		using typename It::value_type;
		using typename It::pointer;
		using typename It::const_pointer;
		using typename It::reference;
		using typename It::const_reference;
		using typename It::difference_type;

		ReverseIterator() : It() {}
		ReverseIterator(It const &obj) : It(obj) {}
		ReverseIterator(ReverseIterator const &obj) : It(obj.p) {}
		ReverseIterator& operator=(ReverseIterator const &obj) {
			this->p = obj.p;
			return (*this);
		}

		reference operator*() {
			It tmp(*this);
			return (*--tmp);
		}
		const_reference operator*() const {
			It tmp(*this);
			return (*--tmp);
		}
		pointer operator->() {
			It tmp(*this);
			return (&*--tmp);
		}
		const_pointer operator->() const {
			It tmp(*this);
			return (&*--tmp);
		}
		ReverseIterator operator++(int) {
			ReverseIterator tmp(*this);
			operator++();
			return (tmp);
		}
		It& operator++() {
			return (this->It::operator--());
		}
		ReverseIterator operator--(int) {
			ReverseIterator tmp(*this);
			operator--();
			return (tmp);
		}
		It& operator--() {
			return (this>It::operatoor++());
		}
};
}

#endif
