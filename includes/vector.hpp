#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <string>

namespace ft {

template<typename T>
class Vector {
	public:
	typedef unsigned long size_type;
	typedef T value_type;
	typedef T* pointer;
	typedef T const * const_pointer;
	typedef T& reference;
	typedef T const & const_reference;
	// typedef VectorIterator<value_type> iterator;
	// typedef VectorIterator<value_type const> const_iterator;
	// typedef ReverseIterator<iterator> reverse_iterator;
	// typedef ReverseIterator<const_iterator> const_reverse_iterator;

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
		// destructor
		virtual	~Vector() {
			this->clear();
			// if (this->container)
				// delete
		}
		// copy const
		Vector(Vector const &other) : v_container(nullptr), v_capacity(0), v_size(other.v_size) {
		 // something
		}
		//operators
		const Vector&	operator[](size_t index) const {
			return this->v_container[index];
		}
		Vector&	operator[](size_t index) {
			return this->v_container[index];
		}
		// methods
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
		void	clear(void) {
			for (size_type i = 0; i < this->v_size; i++)
				this->v_container[i].value_type::~value_type();
			this->v_size = 0;
		}
		void	assign(size_type size, const_reference value) {
			if (size > this->v_capacity)
				this->reserve(size); 
			size_t i2 = 0;
			for (size_t i = 0; i < size ; ++i) {
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
		size_type	capacity(void) const {
			return this->v_capacity;
		}
		size_type	size() const {
			return this->v_size;
		}
		void push_back(const_reference value) {
			if (this->v_size == this->v_capacity) // check if enough capacity
				this->reserve(this->v_capacity * 2);
			new(&this->v_container[this->v_size++]) value_type(value); // push back
		}
		void pop_back() {

		}
		// iterators
		// iterator	begin(void) {
		// 	return (iterator(this->v_container));
		// }
		// const_iterator begin(void) const {
		// 	return (const_iterator(this->v_container));
		// }
		// iterator end(void) {
		// 	return (iterator(&(this->v_container[this->v_size])));
		// }
		// const_iterator end(void) const {
		// 	return (const_iterator(&(this->v_container[this->v_size])));
		// }
		// reverse_iterator rbegin(void) {
		// 	return (reverse_iterator(this->end()));
		// }
		// const_reverse_iterator rbegin(void) const {
		// 	return (const_reverse_iterator(this->end()));
		// }
      	// reverse_iterator rend(void) {
		// 	  return(reverse_iterator(this->begin()));
		//   }
		// const_reverse_iterator rend(void) const {
		// 	return(const_reverse_iterator(this->begin()));
		// }
		// size_type	getArray(int n) const {
		// 	return this->v_container[n];
		// }
};
}
#endif
