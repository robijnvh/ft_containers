#ifndef FT_VECTOR_HPP
# define FT_VECTOR_HPP

# include <iostream>
# include <string>
# include <stdlib.h>
# include <memory>
# include <algorithm>
# include "ft_RandomAccessIterator.hpp"
# include "Type_Traits.hpp"

namespace ft
{
	template < class T, class Alloc = std::allocator<T> > 
	class vector
	{
		public:
			
			typedef random_access_iterator<T>				iterator;
			typedef const_random_access_iterator<T>			const_iterator;
			typedef reverse_random_access_iterator<T>		reverse_iterator;
			typedef const_reverse_random_access_iterator<T>	const_reverse_iterator;
			typedef std::ptrdiff_t                      	difference_type;
			typedef size_t                              	size_type;
			typedef Alloc                               	allocator_type;
			typedef T                                   	value_type;
			typedef T&                                  	reference;
			typedef const T&                            	const_reference;
			typedef T*                                  	pointer;
			typedef const T*                            	const_pointer;

		private:

			T*		_data;
			size_t	_capacity;
			size_t	_size;
			Alloc	_allocator;
			
			void	reallocate(size_t NewCapacity)
			{
				if (NewCapacity == 0)
					NewCapacity = 1;
				T*	new_data = this->_allocator.allocate(NewCapacity);
				for (size_t i = 0; i < this->size(); ++i)
				{
					this->_allocator.construct(new_data + i, this->_data[i]);
					this->_allocator.destroy(this->_data + i);
				}
				this->_allocator.deallocate(this->_data, this->capacity());
				this->_data = new_data;
				this->_capacity = NewCapacity;
			}
			
			template <class InputIterator>
			size_t	distance(InputIterator first, InputIterator second)
			{
				size_t i = 0;
				for (InputIterator it = first; it != second; ++it)
					i++;
				return i;
			}

		public:
		 
		/* ------------ MEMBER FUNCTIONS ------------ */
		 
		/* EMPTY CONTAINER CONSTRUCTOR--> Constructs an empty 
		container, with no elements. */
		explicit vector(const Alloc& alloc = Alloc()) : 
			_data(NULL), 
			_capacity(0),
			_size(0), 
			_allocator(alloc) {}
			
		/* FILL CONSTRUCTOR--> Constructs a container 
		with n elements. Each element is a copy of val. */
		explicit vector(size_t n, const T& val = T(), const Alloc& alloc = Alloc()) : 
			_capacity(n), 
			_size(n), 
			_allocator(alloc)
		{
			_data = _allocator.allocate(n);
			for (size_t i = 0; i < n ; i++)
				_data[i] = val;
		} 
		
		/* RANGE CONSTRUCTOR--> Constructs a container with 
		as many elements as the range [first,last), with each 
		element constructed from its corresponding element in that 
		range, in the same order.*/
		template <class InputIterator>
        vector (typename enable_if<is_input_iterator<InputIterator>::value, InputIterator>::type first, InputIterator last, const Alloc& alloc = Alloc()) : _data(NULL), _allocator(alloc)
		{
			this->_size = this->distance(first, last);
			this->_capacity= this->distance(first, last);
			this->_data = this->_allocator.allocate(this->_capacity);
			for (size_t i = 0; i < this->size(); ++i)
			{
				this->_allocator.construct(this->_data + i, *first);
				++first;
			}
		}

		/* COPY CONSTRUCTOR--> Constructs a container with a 
		copy of each of the elements in x, in the same order. */
		vector(const vector& x) : 
			_capacity(x._capacity), 
			_size(x._size), 
			_allocator(x._allocator) 
		{
			this->_data = _allocator.allocate(x._capacity);
			for (size_t i = 0; i < x._size; i++)
				this->_data[i] = x._data[i];
		}

		/* DESTRUCTOR--> Vector Destructor */ 
		~vector()
		{
			_allocator.deallocate(_data, _capacity);
			return;
		}
		
		/* OPERATOR= FUNCTION --> Assign content */ 
		vector& operator= (const vector& obj)
		{
			if (this != &obj)
			{
				this->clear();
				this->_allocator = obj._allocator;
				this->assign(obj.begin(), obj.end());
			}
			return *this;
		}
		
		/* ------------ ITERATORS ------------ */
		
		/* BEGIN--> Return Iterator to beginning of array */ 
		iterator begin() { return iterator(_data); }
		const_iterator begin() const { return const_iterator(_data); }
		
		/* END--> Return Iterator to end */
		iterator end() { return iterator(&_data[_size]); }
		const_iterator end() const { return const_iterator(&_data[_size]); }
		
		/* RBEGIN--> rbegin points to the element right before the one that would be pointed to by member end. */
		reverse_iterator rbegin() { return reverse_iterator(&_data[_size - 1]); }										// Checken of het geen reference moet zijn
		const_reverse_iterator rbegin() const {return const_reverse_iterator(&_data[_size - 1]); }						// Checken of het geen reference moet zijn
		
		/* REND--> Returns a reverse iterator pointing to the theoretical element preceding the first element in the vector */ 
		reverse_iterator rend() { return reverse_iterator(_data - 1); } 												// Checken of dit goed is 
		const_reverse_iterator rend() const { return const_reverse_iterator(_data - 1); }								// Checken of dit goed is 
		
		/* ------------ CAPACITY ------------ */
		
		/* SIZE--> Return Size */
		size_t size() const { return this->_size; }
		
		/* MAX_SIZE--> Return maximum size */
		size_t max_size() const { return((std::numeric_limits<size_t>::max() / sizeof(T))); };

		/* RESIZE--> Change size */
		void resize (size_t n, T val = T ())
		{
			if (n < this->_size)
			{
				for(; n < this->_size; this->_size--)
					_allocator.destroy(&_data[_size]);

			}
			else if (n > this->_size)
			{
				reserve(n);
				for (; n > this->_size; _size++)
						_data[_size] = val;
			}
		}
		
		/* CAPACITY--> Return size of allocated storage capacity */
		size_t capacity() const { return this->_capacity; }
		
		/* EMPTY--> Test whether vector is empty */
		bool empty() const
		{
			if (this->_size == 0)
				return true;
			else
				return false;
		}
		
		/* RESERVE--> Request a change in capacity */
		void reserve(size_t n)
		{
			if (n > max_size())
				throw length_error();
			else if (n > this->_capacity)
			{
				T* tmp;
				
				tmp = _allocator.allocate(n + 1);
				if (_size > 0)
				{
					for (size_t i = 0; i < this->_size; i++)
						tmp[i]  = _data[i];
					tmp[n] = T ();
					_allocator.deallocate(_data, _capacity);
				}
				_data = tmp;
				_capacity = n;
			}
			else
				return;
		}
		
		/* ------------ ELEMENT ACCESS ------------ */
		
		/*OPERATOR[]--> Access element */
		T& operator[](size_t n) { return this->_data[n]; }
		const T& operator[] (size_t n) const { return this->_data[n]; };
				
		/* AT--> Access element */
		T& at(size_t n)
		{
			if (n < _size)
				return this->_data[n];
			else
				throw out_of_range();
		}

		const T& at(size_t n) const
		{
			if (n < _size)
				return this->_data[n];
			else
				throw out_of_range();
		}
		
		/* FRONT--> Access first element*/
		T& front() { return _data[0]; }
		const T& front() const { return _data[0]; }
		
		/* BACK--> Acces last element*/ 
		T& back() { return _data[_size - 1]; }
		const T& back() const { return _data[_size - 1]; }
		
		/* ------------ MODIFIERS ------------ */
		
		/* ASSIGN--> Assign vector content */ 
		template <class InputIterator>
  		void assign (typename enable_if<is_input_iterator<InputIterator>::value, InputIterator>::type first, InputIterator last)
		{
			size_t i = distance(first, last);
			this->clear();
			this->reserve(i);
			while (first != last)
			{
				this->push_back(*first);
				++first;
			}
		}

		void assign (size_t n, const T& val)
		{
			this->clear();
			this->reserve(n);
			this->_size = n;
			for (size_t i = 0; i < this->size(); i++)
				this->_data[i] = val;
		}
		
		/* PUSH_BACK--> Add element at the end */ 
		void push_back (const T& val)
		{
			if (this->size() >= this->capacity())
				this->reallocate(this->capacity() * 2);
			this->_allocator.construct(this->_data + this->size(), val);
			this->_size += 1;
		}
		
		/* POP_BACK--> Delete last element */ 
		void pop_back()
		{
			this->_size -= 1;
			this->_allocator.destroy(this->_data + this->_size);
		}
		
		/* INSERT--> Insert elements */ 
		iterator insert (iterator position, const T& val)
		{  
			size_t i = distance(begin(), position);
			insert(position, 1, val);
			return iterator(&this->_data[i]);
		}

    	void insert (iterator position, size_t n, const T& val)
		{
			vector tmp(position, this->end());
			while (position != this->end())
				this->pop_back();
			for (size_t i = 0; i < n; ++i)
				this->push_back(val);
			for (iterator it = tmp.begin(); it != tmp.end(); ++it)
				this->push_back(*it);
		}

		template <class InputIterator>
    	void insert (iterator position, typename enable_if<is_input_iterator<InputIterator>::value, InputIterator>::type first, InputIterator last)
		{
			vector tmp(position, this->end());
			while(position != this->end())
				this->pop_back();
			while (first != last)
			{
				this->push_back(*first);
				++first;
			}
			for (InputIterator it = tmp.begin(); it != tmp.end(); ++it)
				this->push_back(*it);
		}
		
		/* ERASE--> Erase elements */
		iterator erase (iterator position)
		{
			this->erase(position, position + 1);
			return position;
		}
		
		iterator erase (iterator first, iterator last)
		{
			vector tmp(last, this->end());
			while (first != this->end())
				this->pop_back();
			for (iterator it = tmp.begin(); it != tmp.end(); ++it)
				this->push_back(*it);
			return first;	
		}
		
		/* SWAP--> Swap content */
		void swap (vector& x)
		{
			vector<T> tmp(*this);

			*this = x;
			x = tmp;
		}
		
		/* CLEAR--> Clear content */
		void clear()
		{
			for (size_t i = 0; i < this->size(); i++)
				_allocator.destroy(&this->_data[i]);
			this->_size = 0;
		}

		void print()
		{
			iterator first = this->begin();
			while (first != this->end())
			{
				std::cout << " " << *first;
				++first;
			}
			std::cout << std::endl;
		}

		/* ------------ OBSERVERS ------------ */

		/* GET_ALLOCATOR--> Returns a copy of the 
		allocator object associated with the vector. */
		allocator_type get_allocator() const { return this->_allocator; }

		/* ------------ EXCEPTIONS ------------ */
		class out_of_range : public std::exception
		{
			virtual const char*	what() const throw() 
			{
				return "vector";
			}
		};
		
		class length_error : public std::exception
		{
			virtual const char*	what() const throw() 
			{
				return "allocator<T>::allocate(size_t n) 'n' exceeds maximum supported size";
			}
		};

	}; // end of VECTOR class
	
	/* ------------ RELATIONAL OPERATORS ------------ */
	template <typename T>
	void swap(vector<T> &x, vector<T> &y)
	{
		vector<T> temp(y);
		y = x;
		x = temp;
	}
	
	/* The equality comparison (operator==) is performed by first 
	comparing sizes, and if they match, the elements are compared 
	sequentially using operator==, stopping at the first mismatch 
	(as if using algorithm equal). */
	template <class T, class Alloc>
	bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		typename ft::vector<T>::const_iterator it_lhs = lhs.begin();
		typename ft::vector<T>::const_iterator it_rhs = rhs.begin();
		
		if (lhs.size() != rhs.size())
			return false;
		while (it_lhs != lhs.end())
		{
			if (*it_lhs != *it_rhs)
				return false;
			++it_lhs;
			++it_rhs;
		}
		return true;
	}
	
	// a != b <<>>  !(a == b)
	template <class T, class Alloc>
	bool operator!= (const vector<T,Alloc>& a, const vector<T,Alloc>& b)
	{
		return !(a == b);
	}

	/* The less-than comparison (operator<) behaves as if using algorithm 
	lexicographical_compare, which compares the elements sequentially 
	using operator< in a reciprocal manner (i.e., checking both a < b 
	and b < a) and stopping at the first occurrence. */
	template <class T, class Alloc>
	bool operator<  (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
	{
		return std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}
	
	// a <= b <<>>  !(b < a)
	template <class T, class Alloc>
	bool operator<= (const vector<T,Alloc>& a, const vector<T,Alloc>& b)
	{
		return !(b < a);
	}

	// a > b <<>>  b < a
	template <class T, class Alloc>
	bool operator>  (const vector<T,Alloc>& a, const vector<T,Alloc>& b)
	{
		return (b < a);
	}

	// a >= b <<>>  !(a < b)
	template <class T, class Alloc>
	bool operator>= (const vector<T,Alloc>& a, const vector<T,Alloc>& b)
	{
		return !(a < b);
	}
	
} // end of namespace ft

#endif