/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: robijnvanhouts <robijnvanhouts@student.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/23 13:22:00 by robijnvanho   #+#    #+#                 */
/*   Updated: 2021/03/31 12:41:26 by robijnvanho   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include "utils/RandomAccessIterator.hpp"
# include "utils/traits.hpp"
# include <limits>
# include <memory>

namespace ft {

template<class T, class Alloc = std::allocator<T> >
class vector {
	public:
		// ALL TYPES
		typedef RandomAccessIterator<T>	iterator;
        typedef ConstRandomAccessIterator<T>	const_iterator;
        typedef RevRandomAccessIterator<T>	reverse_iterator;
        typedef ConstRevRandomAccessIterator<T>	const_reverse_iterator;
	
	private:
		T*		_container;
		Alloc	_allocator;
		size_t	_size;
		size_t	_capacity;
	
		void	realloc(size_t size) { // reallocate Vector of size amount
			T* tmp = _allocator.allocate(size);
			// T* tmp = new T[size];
			for (size_t i = 0; i < _size; i++)
				tmp[i] = _container[i];
			_capacity = size;
			delete[] _container;
			_container = tmp;
		}
		size_t	distance(iterator first, iterator second) { // returns dist between first and sec ptr
			size_t n = 0;
			for (iterator it = first; it != second; it++)
				n++;
			return n;
		}
	
	public:
		// CONSTRUCTORS
		explicit	vector(const Alloc& alloc = Alloc()) : // constructs empty vector, no elements
			_container(NULL),
			_allocator(alloc),
			_size(0),
			_capacity(0) {}
		explicit	vector(size_t n, T const& val = T(), Alloc const& alloc = Alloc()) : // constructs vector with n elements of value
			_allocator(alloc),
			_size(0),
			_capacity(n) {
				_container = _allocator.allocate(n);
				// _container = new T[n];
				assign(n, val);
			}
		// vector(iterator first, iterator last, Alloc const& alloc = Alloc()) :  // constructs vector of first-last elements
		template<class InputIterator>
		vector(typename enable_if<is_input_iterator<InputIterator>::value, InputIterator>::type first, InputIterator last, Alloc const& alloc = Alloc()) :  // constructs vector of first-last elements
			_allocator(alloc),
			_size(0),
			_capacity(0) {
				assign(first, last);
				shrink_to_fit();
			}
		vector(vector const& other) : // constructs vector with copy of each elemant in other
			_allocator(other._allocator),
			_size(0),
			_capacity(other._capacity) {
				// _container = new T[other._capacity];
				_container = _allocator.allocate(other._capacity);
				assign(other.begin(), other.end());
			}
		// DESTRUCTOR
		~vector() { // destroys
			if (_capacity)
				delete[] _container;
		}
		// ASSIGNATION OPERATOR
		vector&	operator=(vector const& other) {
			delete[] _container;
			// _container = new T[other._capacity];
			_container = _allocator.allocate(other._capacity);
			_allocator = other._allocator;
			_size = other._size;
			_capacity = other._capacity;
			assign(other.begin(), other.end());
			return *this;
		}
		// ITERATORS
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
		// CAPACITY
		size_t	size() const { // returns size (nb of elements)
			return _size;
		}
		size_t	max_size() const { // returns max nb of elements possible
			return (std::numeric_limits<size_t>::max() / sizeof(T));
		}
		void	resize(size_t n, T val = T()) { // resize vector to contain n elements
			if (n < _size)
				_size -= (_size - n);
			while (n > _size)
				push_back(val);
		}
		size_t	capacity() const  { // returns size of allocated space
			return _capacity;
		}
		bool	empty() const { // returns whether vector is empty
			return (_size == 0);
		}
		void	reserve(size_t n) { // vector capacity at least enough for n elements
			if (n > _capacity)
				realloc(n);
		}
		void	shrink_to_fit() { // reduce capacity to fit size
			if (_capacity > _size)
				realloc(_size);
		}
		// ELEMENT ACCESS
		T&	operator[](size_t n) { // returns ref to element at position n in vector
			return (_container[n]);
		}
		T const&	operator[](size_t n) const {
			return (_container[n]);
		}
		T&	at(size_t n) { // checks bounds and returns ref to element at position n in vector
			if (n < _size)
				return _container[n];
			throw (std::out_of_range("Index out of range"));
		}
		T const&	at(size_t n) const {
			if (n < _size)
				return _container[n];
			throw (std::out_of_range("Index out of range"));
		}
		T&	front() { // returns ref to first element in vector
			return _container[0];
		}
		T const& front() const {
			return _container[0];
		}
		T&	back() { // returns ref to last element in vector
			return _container[_size - 1];
		}
		T const&	back() const {
			return _container[_size - 1];
		}
		// MODIFIERS
  		// void	assign(iterator first, iterator last) {
		template <class InputIterator>
        void assign (typename enable_if<is_input_iterator<InputIterator>::value, InputIterator>::type first, InputIterator last) {
			clear();
			for (; first != last; first++)
				push_back(*first);
		}
		void	assign(const_iterator first, const_iterator last) {
			clear();
			for (; first != last; first++)
				push_back(*first);
		}
		void	assign(size_t n, T const& val) { // new contents are n elements, each initialized to a copy of value
			clear();
			for (size_t i = 0; i < n; i++) {
				push_back(val);
			}
		}
		void	push_back(T const& val) { // adds new element at end of vector
			if (_capacity == 0) {
				// _container = new T[1];
				_container = _allocator.allocate(1);
				_capacity = 1;
			}
			if (_capacity == _size)
				realloc((2 * _capacity));
			_container[_size] = val;
			_size += 1;
		}
		void	pop_back() { // removes last element in vector
			_size--;
		}
		iterator	insert(iterator position, T const& val) {
			size_t n = distance(begin(), position);
			insert(position, 1, val);
			return (iterator(&_container[n]));
		}
		void	insert(iterator position, size_t n, T const& val) {
			vector tmp(position, end());
			_size = distance(begin(), position);
			for (size_t i = 0; i < n; i++)
				push_back(val);
			for (iterator it = tmp.begin(); it != tmp.end(); it++)
				push_back(*it);
		}
		// void	insert(iterator position, iterator first, iterator last) {
		template <class InputIterator>
        void insert (iterator position, typename enable_if<is_input_iterator<InputIterator>::value, InputIterator>::type first, InputIterator last) {
			vector tmp(position, end());
			_size = distance(begin(), position);
            for (iterator it = first; it < last; it++)
                push_back(*it);
            for (iterator it = tmp.begin(); it != tmp.end(); it++)
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
		void	swap(vector& other) { // swaps vectors
			vector tmp(*this);
			*this = other;
			other = tmp;
		}
		void	clear() { // removes all elements from vector
			_size = 0;
		}
	}; // class vector
}

#endif
