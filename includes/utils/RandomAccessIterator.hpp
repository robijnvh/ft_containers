/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RandomAccessIterator.hpp                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: robijnvanhouts <robijnvanhouts@student.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/23 20:02:35 by robijnvanho   #+#    #+#                 */
/*   Updated: 2021/03/25 15:42:44 by robijnvanho   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOMACCESSITERATOR_HPP
#define RANDOMACCESSITERATOR_HPP

#include <cstddef>

namespace ft {
	
template<typename T>
class RandomAccessIterator {
	private:
		T* _ptr;
		
	public:
		// CONSTRUCTORS
		RandomAccessIterator() :
			_ptr(NULL) {}
		explicit	RandomAccessIterator(T* other) :
			_ptr(other) {}
		RandomAccessIterator(RandomAccessIterator const& other) {
			*this = other;
		}
		RandomAccessIterator&	operator=(RandomAccessIterator const& other) {
			if (this != &other)
				_ptr = other._ptr;
			return (*this);
		}
		// DESTRUCTOR
		~RandomAccessIterator() {}
		// OPERATORS - DEREFERENCE
		T&	operator*() {
			return *_ptr;
		}
		T*	operator->() {
			return _ptr;
		}
		T&	operator[](std::ptrdiff_t const& off) {
			return _ptr[off];
		}
		RandomAccessIterator&	operator++() {
			_ptr++;
			return *this;
		}
		RandomAccessIterator	operator++(int) {
			RandomAccessIterator tmp(*this);
			_ptr++;
			return tmp;
		}
		RandomAccessIterator&	operator--() {
			_ptr--;
			return *this;
		}
		RandomAccessIterator	operator--(int) {
			RandomAccessIterator tmp(*this);
			_ptr--;
			return tmp;
		}
		// OPERATORS - ARITHMETIC
		std::ptrdiff_t	operator+(RandomAccessIterator<T> const& other) {
			return _ptr + other._ptr;
		}
		RandomAccessIterator	operator+(std::ptrdiff_t const& other) {
			return _ptr + other;
		}
		std::ptrdiff_t	operator-(RandomAccessIterator<T> const& other) {
			return _ptr - other;
		}
		RandomAccessIterator	operator-(std::ptrdiff_t const& other) {
			return _ptr - other;
		}
		RandomAccessIterator&	operator+=(std::ptrdiff_t const& other) {
			_ptr += other;
			return *this;
		}
		RandomAccessIterator&	operator-=(std::ptrdiff_t const& other) {
			_ptr -= other;
			return *this;
		}
		// OPERATORS -- COMPARING
		friend bool operator<(RandomAccessIterator const& lhs, RandomAccessIterator const& rhs) {
			return (lhs._ptr < rhs._ptr);
		}
		friend bool operator>(RandomAccessIterator const& lhs, RandomAccessIterator const& rhs) {
			return (rhs < lhs);
		}
		friend bool operator<=(RandomAccessIterator const& lhs, RandomAccessIterator const& rhs) {
			return !(rhs < lhs);
		}
		friend bool operator>=(RandomAccessIterator const& lhs, RandomAccessIterator const& rhs) {
			return !(lhs < rhs);
		}
		friend bool operator==(RandomAccessIterator const& lhs, RandomAccessIterator const& rhs) {
			return (lhs._ptr == rhs._ptr);
		}
		friend bool operator!=(RandomAccessIterator const& lhs, RandomAccessIterator const& rhs) {
			return !(lhs == rhs);
		}
		// GETTER
		T* const&	get_ptr() const {
			return _ptr;
		}
	}; // class RandomAccessIterator

	template<typename T>
	class ConstRandomAccessIterator {
	private:
		T* _ptr;
		
	public:
		// CONSTRUCTORS
		ConstRandomAccessIterator() :
			_ptr(NULL) {}
		explicit	ConstRandomAccessIterator(T* other) :
			_ptr(other) {}
		ConstRandomAccessIterator(ConstRandomAccessIterator const& other) {
			*this = other;
		}
		ConstRandomAccessIterator&	operator=(ConstRandomAccessIterator const& other) {
			if (this != &other)
				_ptr = other._ptr;
			return (*this);
		}
		// DESTRUCTOR
		~ConstRandomAccessIterator() {}
		// OPERATORS - DEREFERENCE
		T const&	operator*() {
			return *_ptr;
		}
		T const*	operator->() {
			return _ptr;
		}
		T const&	operator[](std::ptrdiff_t const& off) {
			return _ptr[off];
		}
		ConstRandomAccessIterator&	operator++() {
			_ptr++;
			return *this;
		}
		ConstRandomAccessIterator	operator++(int) {
			ConstRandomAccessIterator tmp(*this);
			_ptr++;
			return tmp;
		}
		ConstRandomAccessIterator&	operator--() {
			_ptr--;
			return *this;
		}
		ConstRandomAccessIterator	operator--(int) {
			ConstRandomAccessIterator tmp(*this);
			_ptr--;
			return tmp;
		}
		// OPERATORS - ARITHMETIC
		std::ptrdiff_t	operator+(ConstRandomAccessIterator<T> const& other) {
			return _ptr + other._ptr;
		}
		ConstRandomAccessIterator	operator+(std::ptrdiff_t const& other) {
			return _ptr + other;
		}
		std::ptrdiff_t	operator-(ConstRandomAccessIterator<T> const& other) {
			return _ptr - other;
		}
		ConstRandomAccessIterator	operator-(std::ptrdiff_t const& other) {
			return _ptr - other;
		}
		ConstRandomAccessIterator&	operator+=(std::ptrdiff_t const& other) {
			_ptr += other;
			return *this;
		}
		ConstRandomAccessIterator&	operator-=(std::ptrdiff_t const& other) {
			_ptr -= other;
			return *this;
		}
		// OPERATORS -- COMPARING
		friend bool operator<(ConstRandomAccessIterator const& lhs, ConstRandomAccessIterator const& rhs) {
			return (lhs._ptr < rhs._ptr);
		}
		friend bool operator>(ConstRandomAccessIterator const& lhs, ConstRandomAccessIterator const& rhs) {
			return (rhs < lhs);
		}
		friend bool operator<=(ConstRandomAccessIterator const& lhs, ConstRandomAccessIterator const& rhs) {
			return !(rhs < lhs);
		}
		friend bool operator>=(ConstRandomAccessIterator const& lhs, ConstRandomAccessIterator const& rhs) {
			return !(lhs < rhs);
		}
		friend bool operator==(ConstRandomAccessIterator const& lhs, ConstRandomAccessIterator const& rhs) {
			return (lhs._ptr == rhs._ptr);
		}
		friend bool operator!=(ConstRandomAccessIterator const& lhs, ConstRandomAccessIterator const& rhs) {
			return !(lhs == rhs);
		}
		// GETTER
		T* const&	get_ptr() const {
			return _ptr;
		}
	}; // ConstRandomAccessIterator

	template<typename T>
	class RevRandomAccessIterator {	
	private:
		T* _ptr;
		
	public:
		// CONSTRUCTORS
		RevRandomAccessIterator() :
			_ptr(NULL) {}
		explicit	RevRandomAccessIterator(T* other) :
			_ptr(other) {}
		RevRandomAccessIterator(RevRandomAccessIterator const& other) {
			*this = other;
		}
		RevRandomAccessIterator&	operator=(RevRandomAccessIterator const& other) {
			if (this != &other)
				_ptr = other._ptr;
			return (*this);
		}
		// DESTRUCTOR
		~RevRandomAccessIterator() {}
		// OPERATORS - DEREFERENCE
		T&	operator*() {
			return *_ptr;
		}
		T*	operator->() {
			return _ptr;
		}
		T&	operator[](std::ptrdiff_t const& off) {
			return _ptr[-off];
		}
		RevRandomAccessIterator&	operator++() {
			_ptr--;
			return *this;
		}
		RevRandomAccessIterator	operator++(int) {
			RevRandomAccessIterator tmp(*this);
			_ptr--;
			return tmp;
		}
		RevRandomAccessIterator&	operator--() {
			_ptr++;
			return *this;
		}
		RevRandomAccessIterator	operator--(int) {
			RevRandomAccessIterator tmp(*this);
			_ptr++;
			return tmp;
		}
		// OPERATORS - ARITHMETIC
		std::ptrdiff_t	operator+(RevRandomAccessIterator<T> const& other) {
			return _ptr - other._ptr;
		}
		RevRandomAccessIterator	operator+(std::ptrdiff_t const& other) {
			return _ptr - other;
		}
		std::ptrdiff_t	operator-(RevRandomAccessIterator<T> const& other) {
			return _ptr + other;
		}
		RevRandomAccessIterator	operator-(std::ptrdiff_t const& other) {
			return _ptr + other;
		}
		RevRandomAccessIterator&	operator+=(std::ptrdiff_t const& other) {
			_ptr -= other;
			return *this;
		}
		RevRandomAccessIterator&	operator-=(std::ptrdiff_t const& other) {
			_ptr += other;
			return *this;
		}
		// OPERATORS -- COMPARING
		friend bool operator<(RevRandomAccessIterator const& lhs, RevRandomAccessIterator const& rhs) {
			return (lhs._ptr < rhs._ptr);
		}
		friend bool operator>(RevRandomAccessIterator const& lhs, RevRandomAccessIterator const& rhs) {
			return (rhs < lhs);
		}
		friend bool operator<=(RevRandomAccessIterator const& lhs, RevRandomAccessIterator const& rhs) {
			return !(rhs < lhs);
		}
		friend bool operator>=(RevRandomAccessIterator const& lhs, RevRandomAccessIterator const& rhs) {
			return !(lhs < rhs);
		}
		friend bool operator==(RevRandomAccessIterator const& lhs, RevRandomAccessIterator const& rhs) {
			return (lhs._ptr == rhs._ptr);
		}
		friend bool operator!=(RevRandomAccessIterator const& lhs, RevRandomAccessIterator const& rhs) {
			return !(lhs == rhs);
		}
		// GETTER
		T* const&	get_ptr() const {
			return _ptr;
		}
	}; // RevRandomAccessIterator

	template<typename T>
	class ConstRevRandomAccessIterator {	
	private:
		T* _ptr;
		
	public:
		// CONSTRUCTORS
		ConstRevRandomAccessIterator() :
			_ptr(NULL) {}
		explicit	ConstRevRandomAccessIterator(T* other) :
			_ptr(other) {}
		ConstRevRandomAccessIterator(ConstRevRandomAccessIterator const& other) {
			*this = other;
		}
		ConstRevRandomAccessIterator&	operator=(ConstRevRandomAccessIterator const& other) {
			if (this != &other)
				_ptr = other._ptr;
			return (*this);
		}
		// DESTRUCTOR
		~ConstRevRandomAccessIterator() {}
		// OPERATORS - DEREFERENCE
		T const&	operator*() {
			return *_ptr;
		}
		T const*	operator->() {
			return _ptr;
		}
		T const&	operator[](std::ptrdiff_t const& off) {
			return _ptr[-off];
		}
		ConstRevRandomAccessIterator&	operator++() {
			_ptr--;
			return *this;
		}
		ConstRevRandomAccessIterator	operator++(int) {
			ConstRevRandomAccessIterator tmp(*this);
			_ptr--;
			return tmp;
		}
		ConstRevRandomAccessIterator&	operator--() {
			_ptr++;
			return *this;
		}
		ConstRevRandomAccessIterator	operator--(int) {
			ConstRevRandomAccessIterator tmp(*this);
			_ptr++;
			return tmp;
		}
		// OPERATORS - ARITHMETIC
		std::ptrdiff_t	operator+(ConstRevRandomAccessIterator<T> const& other) {
			return _ptr - other._ptr;
		}
		ConstRevRandomAccessIterator	operator+(std::ptrdiff_t const& other) {
			return _ptr - other;
		}
		std::ptrdiff_t	operator-(ConstRevRandomAccessIterator<T> const& other) {
			return _ptr + other;
		}
		ConstRevRandomAccessIterator	operator-(std::ptrdiff_t const& other) {
			return _ptr + other;
		}
		ConstRevRandomAccessIterator&	operator+=(std::ptrdiff_t const& other) {
			_ptr -= other;
			return *this;
		}
		ConstRevRandomAccessIterator&	operator-=(std::ptrdiff_t const& other) {
			_ptr += other;
			return *this;
		}
		// OPERATORS -- COMPARING
		friend bool operator<(ConstRevRandomAccessIterator const& lhs, ConstRevRandomAccessIterator const& rhs) {
			return (lhs._ptr < rhs._ptr);
		}
		friend bool operator>(ConstRevRandomAccessIterator const& lhs, ConstRevRandomAccessIterator const& rhs) {
			return (rhs < lhs);
		}
		friend bool operator<=(ConstRevRandomAccessIterator const& lhs, ConstRevRandomAccessIterator const& rhs) {
			return !(rhs < lhs);
		}
		friend bool operator>=(ConstRevRandomAccessIterator const& lhs, ConstRevRandomAccessIterator const& rhs) {
			return !(lhs < rhs);
		}
		friend bool operator==(ConstRevRandomAccessIterator const& lhs, ConstRevRandomAccessIterator const& rhs) {
			return (lhs._ptr == rhs._ptr);
		}
		friend bool operator!=(ConstRevRandomAccessIterator const& lhs, ConstRevRandomAccessIterator const& rhs) {
			return !(lhs == rhs);
		}
		// GETTER
		T* const&	get_ptr() const {
			return _ptr;
		}
	}; // ConstRevRandomAccessIterator
} // namespace ft

#endif
