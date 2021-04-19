/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-hou <rvan-hou@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/23 13:22:00 by robijnvanho   #+#    #+#                 */
/*   Updated: 2021/04/19 12:37:28 by robijnvanho   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include "utils/RandomAccessIterator.hpp"
# include "utils/traits.hpp"
# include "utils/utils.hpp"
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
			if (size == 0)
				size = 1;
			T* tmp = _allocator.allocate(size);
			for (size_t i = 0; i < _size; i++) {
				this->_allocator.construct(tmp + i, this->_container[i]);
				this->_allocator.destroy(this->_container + i);
			}
			this->_allocator.deallocate(this->_container, this->capacity());
			_capacity = size;
			_container = tmp;
		}
		template <class InputIterator>
		size_t	distance(InputIterator first, InputIterator second) { // returns dist between first and sec ptr
			size_t n = 0;
			for (InputIterator it = first; it != second; it++)
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
			_size(n),
			_capacity(n) {
				_container = _allocator.allocate(n);
				assign(n, val);
			}
		template<class InputIterator>
		vector(typename enable_if<is_input_iterator<InputIterator>::value, InputIterator>::type first, InputIterator last, Alloc const& alloc = Alloc()) :  // constructs vector of first-last elements
			_allocator(alloc) {
				_size = distance(first, last);
				_capacity= distance(first, last);
				_container = _allocator.allocate(_capacity);
				for (size_t i = 0; i < size(); ++i) {
					_allocator.construct(_container + i, *first);
					++first;
				}
			}
		vector(vector const& other) : // constructs vector with copy of each elemant in other
			_allocator(other._allocator),
			_size(other._size),
			_capacity(other._capacity) {
				_container = _allocator.allocate(other._capacity);
				for (size_t i = 0; i < other._size; i++)
					_container[i] = other._container[i];
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
		iterator	begin() { // returns it-ptr to first element
			return iterator(_container);
		}
		const_iterator begin() const {
			return const_iterator(_container);
		}
		iterator end() { // returns it-ptr to pst-the-end element of vector
			return iterator(&(_container[_size]));
		}
		const_iterator end() const {
			return const_iterator(&(_container[_size]));
		}
		reverse_iterator rbegin() { // returns reverse it-ptr to last element in vector
			return reverse_iterator(&_container[_size - 1]);
		}
		const_reverse_iterator rbegin() const {
			return const_reverse_iterator(&_container[_size - 1]);
		}
      	reverse_iterator rend() { // returns reverse it-ptr to the theoretical element preceding first in vector
			  return reverse_iterator(_container - 1);
		  }
		const_reverse_iterator rend() const {
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
			else if (n > _size) {
				reserve(n);
				for (; n > _size; _size++)
					_container[_size] = val;
			}
		}
		size_t	capacity() const  { // returns size of allocated space
			return _capacity;
		}
		bool	empty() const { // returns whether vector is empty
			return (_size == 0);
		}
		void	reserve(size_t n) { // vector capacity at least enough for n elements
			if (n > max_size())
				throw length_error();
			else if (n > _capacity) {
				T* tmp;
				tmp = _allocator.allocate(n + 1);
				if (_size > 0) {
					for (size_t i = 0; i < _size; i++)
						tmp[i] = _container[i];
					tmp[n] = T();
					_allocator.deallocate(_container, _capacity);
				}
				_container = tmp;
				_capacity = n;
			}
			return ;
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
		template <class InputIterator>
		void assign (typename enable_if<is_input_iterator<InputIterator>::value, InputIterator>::type first, InputIterator last) {
			size_t i = distance(first, last);
			clear();
			reserve(i);
			for (; first != last; first++)
				push_back(*first);
		}
		void	assign(size_t n, T const& val) { // new contents are n elements, each initialized to a copy of value
			clear();
			reserve(n);
			_size = n;
			for (size_t i = 0; i < _size; i++) {
				_container[i] = val;
			}
		}
		void	push_back(T const& val) { // adds new element at end of vector
			if (_capacity == 0) {
				_container = _allocator.allocate(1);
				_capacity = 1;
			}
			else if (_size >= _capacity)
				realloc((2 * _capacity));
			_container[_size] = val;
			_size += 1;
		}
		void	pop_back() { // removes last element in vector
			_size--;
			_allocator.destroy(_container + _size);
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
			for (size_t i = 0; i < this->size(); i++)
				_allocator.destroy(&this->_container[i]);
			this->_size = 0;
		}
		// GET ALLOCATOR
		Alloc	get_allocator() const {
			return this->_allocator;
		}
		// EXCEPTIONS
		class length_error : public std::exception {
			virtual const char*	what() const throw() {
				return "allocator<T>::allocate(size_t n) 'n' exceeds maximum supported size";
			}
		};
	}; // class vector

	// RELATIONAL OPERATORS
	template <class T, class Alloc>
	bool	operator==(ft::vector<T, Alloc> const& lhs, ft::vector<T, Alloc> const& rhs) {
		return (lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}
	template <class T, class Alloc>
	bool	operator!=(ft::vector<T, Alloc> const& lhs, ft::vector<T, Alloc> const& rhs) {
		return !(lhs == rhs);
	}
	template <class T, class Alloc>
	bool	operator<(ft::vector<T, Alloc> const& lhs, ft::vector<T, Alloc> const& rhs) {
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}
	template <class T, class Alloc>
	bool	operator<=(ft::vector<T, Alloc> const& lhs, ft::vector<T, Alloc> const& rhs) {
		return !(rhs < lhs);
	}
	template <class T, class Alloc>
	bool	operator>(ft::vector<T, Alloc> const& lhs, ft::vector<T, Alloc> const& rhs) {
		return (rhs < lhs);
	}
	template <class T, class Alloc>
	bool	operator>=(ft::vector<T, Alloc> const& lhs, ft::vector<T, Alloc> const& rhs) {
		return !(lhs < rhs);
	}

	// SWAP
	template <typename T>
	void swap(vector<T> &x, vector<T> &y) {
		vector<T> tmp(y);
		y = x;
		x = tmp;
	}
} // namespace ft
#endif
