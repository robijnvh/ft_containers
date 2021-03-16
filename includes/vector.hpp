#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <stdlib.h> // remove
#include <cstddef>
# include <memory>
# include <algorithm>
# include <limits>

# include "utils/RandomAccessIterator.hpp"
# include "utils/traits.hpp"

namespace ft {

template<class T, class Alloc = std::allocator<T> >
class Vector {
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

		void	reallocation(size_type size) {
			pointer tmp = new value_type[size];
			for (size_type i = 0; i < _size; i++)
				tmp[i] = _container[i];
			_capacity = size;
			delete[] _container;
			_container = tmp;
		}
		size_t	distance(iterator first, iterator second) { // distance between first and second ptr
			size_t n = 0;
			for (iterator it = first; it != second; it++)
				n++;
			return (n);
		}

	public:
		// CONSTRUCTORS  -------------------------------------------------------------------------------------------
		explicit	Vector(allocator_type const& alloc = allocator_type()) : // constructs empty vector, no elements
			_container(NULL),
			_allocator(alloc),
			_size(0),
			_capacity(0) {}
		explicit	Vector(size_type n, value_type const& value = value_type(), allocator_type const& alloc = allocator_type()) : // constructs vector with n elemnts (copy of value)
			_allocator(alloc),
			_size(0),
			_capacity(n) {
				_container = new value_type[n];
				assign(n, value);
			}
		template<class InputIterator>
		Vector(typename enable_if<is_input_iterator<InputIterator>::value, InputIterator>::type first, InputIterator last, allocator_type const& alloc = allocator_type()) : // constructs vector with as many elements as first-last, from corresponding element
			_allocator(alloc),
			_size(0),
			_capacity(0) {
				assign(first, last);
				shrink_to_fit();
			}
		Vector(Vector const& other) : // constructs vector with copy of each elemant in other, in the same order
			_allocator(other._allocator),
			_size(0),
			_capacity(other._capacity) {
				_container = new value_type[other._capacity];
				assign(other.begin(), other.end());
			}
		// DESTRUCTORS --------
		~Vector() { // destroys
			if (_capacity)
				delete[] _container;
		}
		// OPERATORS ---------------------------
		Vector&	operator=(Vector const& other) {
			delete[] _container;
			_container = new value_type[other._capacity];
			_allocator = other._allocator;
			_size = other._size;
			_capacity = other._capacity;
			assign(other.begin(), other.end());
			return (*this);
		}
		// ITERATORS -----------------------------------------------
		iterator	begin(void) { // returns it-ptr to first element
			return iterator(_container);
		}
		const_iterator begin(void) const {
			return const_iterator(_container);
		}
		iterator end(void) { // returns it-ptr to pst-the-end element of vector
			return iterator(&(_container[_size]));
		}
		const_iterator end(void) const {
			return const_iterator(&(_container[_size]));
		}
		reverse_iterator rbegin(void) { // returns reverse it-ptr to last element in vector
			return reverse_iterator(&_container[_size - 1]);
		}
		const_reverse_iterator rbegin(void) const {
			return const_reverse_iterator(&_container[_size - 1]);
		}
      	reverse_iterator rend(void) { // returns reverse it-ptr to the theoretical element preceding first in vector
			  return reverse_iterator(_container - 1);
		  }
		const_reverse_iterator rend(void) const {
			return const_reverse_iterator(_container - 1);
		}
		// CAPACITY-----------------------------------------
		size_type	size() const { // returns nb of elements
			return (_size);
		}
		size_type	max_size() const { // returns max nb of elements
			return ((std::numeric_limits<size_type>::max() / sizeof(value_type)));
		}
		void	resize(size_type n, value_type val = value_type()) { // rezises so vector contains n elements
			if (n < _size)
				_size -= (_size - n);
			while (n > _size)
				push_back(val);
		}
		size_type	capacity() const { // returns size of storage space (allocated)
			return (_capacity);
		}
		bool	empty() const { // returns whether vector is empty
			return (_size == 0);
		}
		void	reserve(size_type n) { // vector capacity at least enugh for n elements
			if (n > _capacity)
				reallocation(n);
		}
		void	shrink_to_fit() { // reduce capacity to fit size
			if (_capacity > _size)
				reallocation(_size);
		}
		// ELEMENT ACCESS -------------------------------------------------------------------
		reference operator[](size_type n) {  // returns & to element at position n in vector
			return reference(_container[n]);
		}
		const_reference operator[](size_type n) const {
			return const_reference(_container[n]);
		}
		reference at(size_type n) { // returns & to element at position n in vector
			if (n < _size)
				return (reference(_container[n]));
			throw (std::out_of_range("Index out of range"));
		}
		const_reference at(size_type n) const { // returns & to element at position n in vector
			if (n < _size)
				return (const_reference(_container[n]));
			throw (std::out_of_range("Index out of range"));
		}
		reference front() { // returns & to the first element in vector
			return reference(_container[0]);
		}
		const_reference front() const {
			return const_reference(_container[0]);
		}
		reference back() { // returns & to the last element in vector
			return reference(_container[_size - 1]);
		}
		const_reference back() const {
			return const_reference(_container[_size - 1]);
		}
		// MODIFIERS -------------------------------------------------------------
		template <class InputIterator>
		void	assign(typename enable_if<is_input_iterator<InputIterator>::value, InputIterator>::type first, InputIterator last) {
			clear();
			while (first != last) {
				push_back(*first);
				first++;
			}
		}
		void	assign(const_iterator first, const_iterator last) {
			clear();
			while (first != last) {
				push_back(*first);
				first++;
			}
		}
		void	assign(size_type n, value_type const& value) { // new contents are n elements, each initialized to a copy of value
			clear();
			for (size_type i = 0; i < n; i++) {
				push_back(value);
			}
		}
		void	push_back(value_type const& value) { // adds new element at end of vector
			if (_capacity == 0) {
				_container = new value_type[1];
				_capacity = 1;
			}
			if (_capacity == _size)
				reallocation((2 * _capacity));
			_container[_size] = value;
			_size += 1;
		}
		void	pop_back() { // removes last elements in vector
			_size--;
		}
		iterator	insert(iterator position, value_type const& value) { // insert element at specified position
			size_t n = distance(begin(), position);
			insert(position, 1, value);
			return (iterator(&_container[n]));
		}
		void	insert(iterator position, size_type n, value_type const& value) {
			Vector temp(position, end());
			_size = distance(begin(), position);
			for (size_t i = 0; i < n; i++)
				push_back(value);
			for (iterator it = temp.begin(); it != temp.end(); it++)
				push_back(*it);
		}
        template <class InputIterator>
		void	insert(iterator position, typename enable_if<is_input_iterator<InputIterator>::value, InputIterator>::type first, InputIterator last) {
			Vector temp(position, end());
			_size = distance(begin(), position);
            for (iterator it = first; it < last; it++)
                push_back(*it);
            for (iterator it = temp.begin(); it != temp.end(); it++)
                push_back(*it);
		}
		iterator	erase(iterator position) { // removes single element from vector
			iterator ret(position);
			for (; position != end()-1; position++)
				*position = *(position + 1);
			_size -= 1;
			return (ret);
		}
		iterator	erase(iterator first, iterator last) { // removes range of elements from vector
			iterator ret(first);
			for (; last != end(); last++) {
				*first = *last;
				first++;
			}
			_size -= distance(first, last);
			return (ret);
		}
		void	swap(Vector& other) { // Swaps vectors content
			Vector temp(*this);
			*this = other;
			other = temp;
		}
		void	clear() { // removes all elemets from vector
			_size = 0;
		}
	};

	template <typename T>
	void	swap(Vector<T>& other, Vector<T>& another) {
		Vector<T> temp(another);
		another = other;
		other = temp;
	}

	// RELATION OPERATORS ---------------------------
	template <class value_type, class allocator_type>
	bool	operator==(Vector<value_type,allocator_type>const& lhs, Vector<value_type,allocator_type>const& rhs) {
		typename ft::Vector<value_type>::const_iterator it_lhs = lhs.begin();
		typename ft::Vector<value_type>::const_iterator it_rhs = rhs.begin();
		if (lhs.size() != rhs.size())
			return (false);
		while (*it_lhs != *lhs.end()) {
			if (*it_lhs != *it_rhs)
		return (false);
			it_lhs++;
			it_rhs++;
		}
		return (true);
	}

	template <class value_type, class allocator_type>
	bool operator!= (const Vector<value_type,allocator_type>& lhs, const Vector<value_type,allocator_type>& rhs) {return !(lhs == rhs);}

	template <class value_type, class allocator_type>
	bool operator< (const Vector<value_type,allocator_type>& lhs, const Vector<value_type,allocator_type>& rhs) {
		return (std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));}

	template <class value_type, class allocator_type>
	bool operator<= (const Vector<value_type,allocator_type>& lhs, const Vector<value_type,allocator_type>& rhs) {return !(rhs < lhs);}

	template <class value_type, class allocator_type>
	bool operator>  (const Vector<value_type,allocator_type>& lhs, const Vector<value_type,allocator_type>& rhs) {return (rhs<lhs);}

	template <class value_type, class allocator_type>
	bool operator>= (const Vector<value_type,allocator_type>& lhs, const Vector<value_type,allocator_type>& rhs) {return !(lhs < rhs);}
};

#endif
