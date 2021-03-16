#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <stdlib.h> // remove
# include <string>
# include <memory>
# include <algorithm>
# include <limits>
# include "Iterator.hpp"
// # include <memory>
// # include <cstddef>

namespace ft {

template<typename T>
class VectorIterator : IteratorTrait {
	public:
		typedef T value_type;
		typedef value_type* pointer;
		typedef value_type const* const_pointer;
		typedef value_type& reference;
		typedef value_type const& const_reference;
		typedef std::ptrdiff_t difference_type;
	
	protected:
		pointer p;
	
	public:
		VectorIterator() : p(nullptr) {}
		VectorIterator(pointer _p) : p(_p) {}
		VectorIterator(VectorIterator const& obj) : p(obj.p) {}
		virtual ~VectorIterator() {}

		VectorIterator& operator=(VectorIterator const& obj) {
			this->p = obj.p;
			return (*this);
		}
		reference operator*() {
			return (*this->p);
		}
		const_reference operator*() const {
			return (*this->p);
		}
		pointer operator->() {
			return (this->p);
		}
		const_pointer operator->() const {
			return (this->p);
		}
		reference operator[](int value) {
			return (*(this->p + value));
		}
		const_reference operator[](int value) const {
			return (*(this->p + value));
		}

		VectorIterator operator++(int) {
			VectorIterator tmp(*this);
			++this->p;
			return (tmp);
		}
		VectorIterator& operator++() {
			++this->p;
			return (*this);
		}
		VectorIterator operator--(int) {
			VectorIterator tmp(*this);
			--this->p;
			return (tmp);
		}
		VectorIterator& operator--() {
			--this->p;
			return (*this);
		}
		VectorIterator& operator+=(int value) {
			this->p += value;
			return (*this);
		}
		VectorIterator operator+(int value) const {
			VectorIterator tmp(*this);
			return (tmp += value);
		}
		VectorIterator& operator-=(int value) {
			this->p -= value;
			return (*this);
		}
		VectorIterator operator-(int value) const {
			VectorIterator tmp(*this);
			return (tmp -= value);
		}
		difference_type operator-(VectorIterator const& obj) const {
			return (this->p - obj.p);
		}
		bool operator==(VectorIterator const& obj) const {
			return (this->p == obj.p);
		}
		bool operator!=(VectorIterator const& obj) const {
			return (this->p != obj.p);
		}
		bool operator<(VectorIterator const& obj) const {
			return (this->p < obj.p);
		}
		bool operator<=(VectorIterator const& obj) const {
			return (this->p <= obj.p);
		}
		bool operator>(VectorIterator const& obj) const {
			return (this->p > obj.p);
		}
		bool operator>=(VectorIterator const& obj) const {
			return (this->p >= obj.p);
		}
};

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
		typedef VectorIterator<value_type> iterator;
		typedef VectorIterator<value_type const> const_iterator;
		typedef ReverseIterator<iterator> reverse_iterator;
		typedef ReverseIterator<const_iterator> const_reverse_iterator;

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
		Vector(iterator first, iterator last, allocator_type const& allocator_type()) : // constructs vector with as many elements as first-last, from corresponding element
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
			_container = new value_type[other.capacity];
			_allocator = other._allocator;
			_size = other._size;
			_capacity = other._capacity;
			assign(other.begin(), other.end());
			return (*this);
		}
		// ITERATORS -----------------------------------------------
		iterator	begin(void) { // returns it-ptr to first element
			return (iterator(this->_container));
		}
		const_iterator begin(void) const {
			return (const_iterator(this->_container));
		}
		iterator end(void) { // returns it-ptr to pst-the-end element of vector
			return (iterator(&(this->_container[this->_size])));
		}
		const_iterator end(void) const {
			return (const_iterator(&(this->_container[this->_size])));
		}
		reverse_iterator rbegin(void) { // returns reverse it-ptr to last element in vector
			return (reverse_iterator(this->end()));
		}
		const_reverse_iterator rbegin(void) const {
			return (const_reverse_iterator(this->end()));
		}
      	reverse_iterator rend(void) { // returns reverse it-ptr to the theoretical element preceding first in vector
			  return(reverse_iterator(this->begin()));
		  }
		const_reverse_iterator rend(void) const {
			return(const_reverse_iterator(this->begin()));
		}
		// CAPACITY-----------------------------------------
		size_type	size() const { // returns nb of elements
			return (_size);
		}
		size_type	max_size() const { // returns max nb of elements
			return ((std::numeric_limits<size_type>::max() / sizeof(value_ttype)));
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
		void	assign(typename enable_if::value, iterator first, iterator last) {
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
			return (iterator(&_container[n]))
		}
		void	insert(iterator position, size_type n, value_type const& value) {
			vector temp(position, end());
			_size = distance(begin(), position);
			for (size_t i = 0; i < n; i++)
				push_back(value);
			for (iterator it = temp.begin(); it != temp.end(), it++)
				push_back(*it);
		}
		void	insert(iterator position, iterator first, iterator last) {
			vector temp(position, end());
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
		void	swap(vector& other) { // Swaps vectors content
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


}

#endif
