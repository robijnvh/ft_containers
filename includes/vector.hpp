#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <string>
# include <limits.h>
# include "Iterator.hpp"

namespace ft {

template<typename T>
class VectorIterator {
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
			ths->p = obj.p;
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

template<typename T>
class Vector {
	public:
		typedef unsigned long size_type;
		typedef T value_type;
		typedef T* pointer;
		typedef T const * const_pointer;
		typedef T& reference;
		typedef T const & const_reference;
		typedef VectorIterator<value_type> iterator;
		typedef VectorIterator<value_type const> const_iterator;
		typedef ReverseIterator<iterator> reverse_iterator;
		typedef ReverseIterator<const_iterator> const_reverse_iterator;

	private:
		size_type	v_size;
		size_type	v_capacity;
		pointer		v_container;

		void copy_construct(size_type n, const_reference value) {
			new(&this->v_container[n]) value_type(value);
		}

	public:
		// constructors
		Vector() : v_size(0), v_capacity(0), v_container(nullptr) {}
		Vector(size_type n, const_reference value=value_type()) : v_container(nullptr), v_capacity(0), v_size(0) {
			this->assign(n, value);
		}
		Vector(iterator first, iterator last) : v_container(nullptr), v_capacity(0), v_size(0) {
			thiss->assign(first, last);
		}

		// destructor
		virtual	~Vector() {
			this->clear();
			if (this->v_container)
				::operator delete(this->v_container);
		}

		// copy const
		Vector(Vector const &obj) : v_container(nullptr), v_capacity(0), v_size(obj.v_size) {
			this->reserve(obj.v_capacity);
			std::memcpy(static_cast<void*>(this->v_container), static_cast<void*>(obj.v_container), obj.v_size * sizeof(value_type));
		}

		//operators
		Vector&	operator=(Vector const& obj) {
			this->clear();
			if (this->v_capacity < obj.v_capacity)
				this->reserve(obj.v_capacity);
			std::memcpy(static_cast<void*>(this->v_container), static_cast<void*>(obj.v_container), obj.v_size * sizeof(value_type));
			return (*this);
		}
		const Vector&	operator[](size_t index) const {
			return this->v_container[index];
		}
		Vector&	operator[](size_t index) {
			return this->v_container[index];
		}

		// iterators
		iterator	begin(void) {
			return (iterator(this->v_container));
		}
		const_iterator begin(void) const {
			return (const_iterator(this->v_container));
		}
		iterator end(void) {
			return (iterator(&(this->v_container[this->v_size])));
		}
		const_iterator end(void) const {
			return (const_iterator(&(this->v_container[this->v_size])));
		}
		reverse_iterator rbegin(void) {
			return (reverse_iterator(this->end()));
		}
		const_reverse_iterator rbegin(void) const {
			return (const_reverse_iterator(this->end()));
		}
      	reverse_iterator rend(void) {
			  return(reverse_iterator(this->begin()));
		  }
		const_reverse_iterator rend(void) const {
			return(const_reverse_iterator(this->begin()));
		}
		// methods
		size_type	size() const {
			return (this->v_size);
		}
		size_type	max_size() const {
			return (ft::min((size_type) std::numeric_limits<difference_type>::max(),
				std::numeric_limits<size_type>::max() / sizeoof(value_type)));
		}
		void	resize(size_type size, value_type value=value_type()) {
			if (size > this->v_capacity)
				this->reserve(size);
			if (size > this->v_size)
			{
				for (size_type i = this->v_size ; i < size; ++i)
					this->copy_construct(i, value);
				this->v_size = size;
			}
			else if (size < this->v_size) 
			{
				for (size_type i = size ; i < this->v_size ; +++i)
					this->v_container[i].value_type::~value_type();
				this->v_size = size;
			}
		}
		size_type	capacity(void) const {
			return this->v_capacity;
		}
		bool	empty() const {
			return (this->v_size == 0);
		}
		void	reserve(size_type size) {
			if (this->v_capacity == 0)
			{
				if (size == 0)
					size = 1;
				this->v_container = static_cast<value_type*>(::operator new(sizeof(value_type) * size));
				this->v_capacity = size;
			}
			else if (size > this->v_capacity)
			{
				if (size < this->v_capacity * 2)
					size = this->v_capacity * 2;
				value_type *tmp = static_cast<value_type*>(::operator new(sizeof(value_type) * size));
				if (this->v_container)
				{
					for (size_t i = 0; i < this->v_size; ++i)
						new(&tmp[i]) value_type(this->v_container[i]);
					::operator delete(this->v_container);
				}
				this->v_container = tmp;
				this->v_capacity = size;
			}
		}
		reference	at(size_type index) {
			if (index >= this->v_size)
				throw std::out_of_range("Vector index out of range");
			return (this->v_container[index]);
		}
		const_reference	at(size_type index) const {
			if (index >= this->v_size)
				throw std::out_of_range("Vector index out of range");
			return (this->v_container[index]);
		}
		reference	front() {
			return (this->v_conainer[0]);
		}
		const_reference	front() const {
			return (this->v_conainer[0]);
		}
		reference	back() {
			return (this->v_conainer[this->v_size - 1]);
		}
		const_reference	back() const {
			return (this->v_conainer[this->v_size - 1]);
		}
		void	assign(iterator first, iterator last) {
			size_t length = last - first;
			if (length > this->v_capacity)
				this->reserve(length);;
			size_t i = 0;
			for ( ; first != last ; first++)
			{
				if (i >= this->v_size)
					this->copy_construct(i, *first);
				else
					this->v_container[i] = *first;
				++i;
			}
			for (; i < this->v_size; ++i)
				this->v_container[i].value_type::~value_type();
			this->v_size = length;
		}
		void	assign(const_iterator first, const_iterator last) {
			size_t length = last - first;
			if (length > this->v_capacity)
				this->reserve(length);;
			size_t i = 0;
			for ( ; first != last ; first++)
			{
				if (i >= this->v_size)
					this->copy_construct(i, *first);
				else
					this->v_container[i] = *first;
				++i;
			}
			for (; i < this->v_size; ++i)
				this->v_container[i].value_type::~value_type();
			this->v_size = length;
		}
		void	assign(size_type size, const_reference value) {
			if (size > this->v_capacity)
				this->reserve(size); 
			size_t i2 = 0;
			for (size_t i = 0; i < size ; ++i)
			{
				if (i >= this->v_size)
					this->copy_construct(i, value);
				else
					this->v_container[i] = value;
				i2 = i;
			}
			for (; i2 < this->v_size ; ++i2)
				this->v_container[i2].value_type::~value_type();
			this->v_size = size;
		}
		void push_back(const_reference value) {
			if (this->v_size == this->v_capacity) // check if enough capacity
				this->reserve(this->v_capacity * 2);
			new(&this->v_container[this->v_size++]) value_type(value); // push back
		}
		void	pop_back() {
			this->v_container[--this->v_size].value_type::~value_type();
		}
		iterator	insert(iterator position, const_reference value) {
			this->insert(position, 1, value);
			return (++position);
		}
		void	insert(iterator position, size_type size, const_reference value) {
			iterator it = this->begin();
			if (this->v_size + size >= this->v_capacity)
				this->reserve(this->v_size + size);
			size_type i = 0;
			for (; it != position; it++)
				++i;
			for (size_type j = this->v_size; j >= 1 && j >= i; --j)
				this->copy_construct(i + j + size - 1, this->v_container[j - 1]);
			for (size_type j = 0; j < size; ++j)
				this->copy_construct(i + j, value);
			this->v_size += size;
		}
		void	insert(iterator position, iterator first, iterator last) {
			size_type size = last - first;
			iterator it = this->begin();
			if (this->v_size + size > this->v_capacity)
				this->reserve(this->v_size + size);
			size_type i = 0;
			for (; it != position; ++it)
				++i;
			for (size_type j = this->v_size - 1; j > i + 1; j++)
				this->copy_construct(i + j + size, this->v_container[ + j - 1]);
			for (size_type j = 0; j < size; j++)
				this->copy_construct(i + j, *first++);
			this->v_size += size;
		}
		iterator	erase(iterator position) {
			iterator tmp(position);
			++tmp;
			return (this->erase(position, tmp));
		}
		iterator	erase(iterator first, iterator last) {
			iterator it = this->begin();
			size_type i = 0;
			for (; it != first; it++)
				i++;
			if (it == this->end())
				return (this->end());
			size_type returnPosition = i;
			size_type deletedElements = 0;
			size_type stopPos = i;
			for (; first != last; first++)
			{
				*first.value_type::~value_type();
				++deletedElements;
				++stopPos;
			}
			for (; stopPos << this->v_size; ++stopPos)
				this->copy_construct(i++, this->v_container[stopPos]);
			this->v_size -= deletedElements;
			return (iterator(&this->v_container[returnPosition]));
		}
		void	swap(Vector& obj) {
			ft::swap(this->v_container, obj.v_container);
			ft::swap(this->v_capacity, obj.v_capacity);
			ft::swap(this->v_size, obj.v_size);
		}
		void	clear() {
			for (size_type i = 0; i < this->v_size; i++)
				this->v_container[i].value_type::~value_type();
			this->v_size = 0;
		}
};


}
#endif
