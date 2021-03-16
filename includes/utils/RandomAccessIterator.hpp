/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   randomAccessIterator.hpp                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-hou <rvan-hou@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/16 11:52:52 by rvan-hou      #+#    #+#                 */
/*   Updated: 2021/03/16 13:53:28 by rvan-hou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOMACCESSITERATOR_HPP
# define RANDOMACCESSITERATOR_HPP


// RandomAccessIterator + ConstRandomAccessIterator + RevRandomAccessIterator + ConstRevRandomAccessIterator
namespace ft {
	template<typename T>
	class RandomAccessIterator {
		public:
			typedef std::random_access_iterator_tag	iterator_category;
			typedef T	value_type;
			typedef std::ptrdiff_t	difference_type;
			typedef T*	pointer;
			typedef T&	reference;	

		private:
			pointer	_ptr;
		
		public:
			// CONSTRUCTORS --------
			RandomAccessIterator() :
				_ptr(NULL) {}
			explicit RandomAccessIterator(pointer it) :
				_ptr(it) {};
			RandomAccessIterator(const RandomAccessIterator &it) {
				*this = it;
			}
			RandomAccessIterator &operator=(const RandomAccessIterator &rhs) {
				if (this != &rhs)
					_ptr = rhs._ptr;
				return (*this);
			};
			// DESTRUCTOR ------------
			~RandomAccessIterator() {}
			// OPERATORS ----------
			reference operator*() {
				return (*_ptr);
			}
			pointer operator->() {
				return (_ptr);
			}
			reference operator[](const difference_type &off) {
				return (_ptr[off]);
			}
			RandomAccessIterator &operator++() {
				_ptr++;
				return (*this);
			}
			RandomAccessIterator operator++(int) {
				RandomAccessIterator temp(*this);
				_ptr++;
				return (temp);
			}
			RandomAccessIterator &operator--() {
				_ptr--;
				return (*this);
			}
			RandomAccessIterator operator--(int) {
				RandomAccessIterator temp(*this);
				_ptr--;
				return (temp);
			}
			// ARITHMETIC OPERATORS  --------------------------------------
			difference_type operator+(const RandomAccessIterator<T> &rhs) {
				return (_ptr + rhs._ptr);
			}
			RandomAccessIterator operator+(const difference_type &off) {
				return RandomAccessIterator<T>(_ptr + off);
			}
			difference_type operator-(const RandomAccessIterator<T> &rhs) {
				return (_ptr - rhs._ptr);
			}
			RandomAccessIterator operator-(const difference_type &off) {
				return RandomAccessIterator<T>(_ptr - off);
			}
			RandomAccessIterator &operator+=(const difference_type &off) {
				_ptr += off;
				return (*this);
			}
			RandomAccessIterator &operator-=(const difference_type &off) {
				_ptr -= off;
				return (*this);
			}
			// RELATIONAL OPERATORS  ------------------------------------------------------------------------
			template<typename T2>
			friend bool operator<(const RandomAccessIterator<T2> &lhs, const RandomAccessIterator<T2> &rhs) {
				return (lhs._ptr < rhs._ptr);
			}
			template<typename T2>
			friend bool operator>(const RandomAccessIterator<T2> &lhs, const RandomAccessIterator<T2> &rhs) {
				return (rhs < lhs);
			}
			template<typename T2>
			friend bool operator<=(const RandomAccessIterator<T2> &lhs, const RandomAccessIterator<T2> &rhs) {
				return !(rhs < lhs);
			}
			template<typename T2>
			friend bool operator>=(const RandomAccessIterator<T2> &lhs, const RandomAccessIterator<T2> &rhs) {
				return !(lhs < rhs);
			}
			template<typename T2>
			friend bool operator==(const RandomAccessIterator<T2> &lhs, const RandomAccessIterator<T2> &rhs) {
				return (lhs._ptr == rhs._ptr);
			}
			template<typename T2>
			friend bool operator!=(const RandomAccessIterator<T2> &lhs, const RandomAccessIterator<T2> &rhs) {
				return !(lhs == rhs);
			}
			// GETTER  ---------------------
			const pointer &get_ptr() const {
				return (_ptr);
			}
	};
	
	template<typename T>
	class ConstRandomAccessIterator {
		public:
			typedef std::random_access_iterator_tag	iterator_category;
			typedef T	value_type;
			typedef std::ptrdiff_t	difference_type;
			typedef T	*pointer;
			typedef T	&reference;
			typedef const T	*const_pointer;
			typedef const T	&const_reference;

		private:
			pointer	_ptr;
		
		public:
			// CONSTRUCTORS --------
			ConstRandomAccessIterator() :
				_ptr(NULL) {}
			explicit ConstRandomAccessIterator(pointer it) :
				_ptr(it) {};
			ConstRandomAccessIterator(const ConstRandomAccessIterator &it) {
				*this = it;
			}
			ConstRandomAccessIterator &operator=(const ConstRandomAccessIterator &rhs) {
				if (this != &rhs)
					_ptr = rhs._ptr;
				return (*this);
			};
			// DESTRUCTOR ------------
			~ConstRandomAccessIterator() {}
			// OPERATORS ----------
			const_reference operator*() {
				return (*_ptr);
			}
			const_pointer operator->() {
				return (_ptr);
			}
			const_reference operator[](const difference_type &off) {
				return (_ptr[off]);
			}
			ConstRandomAccessIterator &operator++() {
				_ptr++;
				return (*this);
			}
			ConstRandomAccessIterator operator++(int) {
				ConstRandomAccessIterator temp(*this);
				_ptr++;
				return (temp);
			}
			ConstRandomAccessIterator &operator--() {
				_ptr--;
				return (*this);
			}
			ConstRandomAccessIterator operator--(int) {
				ConstRandomAccessIterator temp(*this);
				_ptr--;
				return (temp);
			}
			// ARITHMETIC OPERATORS  --------------------------------------
			difference_type operator+(const ConstRandomAccessIterator<T> &rhs) {
				return (_ptr + rhs._ptr);
			}
			ConstRandomAccessIterator operator+(const difference_type &off) {
				return ConstRandomAccessIterator<T>(_ptr + off);
			}
			difference_type operator-(const ConstRandomAccessIterator<T> &rhs) {
				return (_ptr - rhs._ptr);
			}
			ConstRandomAccessIterator operator-(const difference_type &off) {
				return ConstRandomAccessIterator<T>(_ptr - off);
			}
			ConstRandomAccessIterator &operator+=(const difference_type &off) {
				_ptr += off;
				return (*this);
			}
			ConstRandomAccessIterator &operator-=(const difference_type &off) {
				_ptr -= off;
				return (*this);
			}
			// RELATIONAL OPERATORS  ------------------------------------------------------------------------
			template<typename T2>
			friend bool operator<(const ConstRandomAccessIterator<T2> &lhs, const ConstRandomAccessIterator<T2> &rhs) {
				return (lhs._ptr < rhs._ptr);
			}
			template<typename T2>
			friend bool operator>(const ConstRandomAccessIterator<T2> &lhs, const ConstRandomAccessIterator<T2> &rhs) {
				return (rhs < lhs);
			}
			template<typename T2>
			friend bool operator<=(const ConstRandomAccessIterator<T2> &lhs, const ConstRandomAccessIterator<T2> &rhs) {
				return !(rhs < lhs);
			}
			template<typename T2>
			friend bool operator>=(const ConstRandomAccessIterator<T2> &lhs, const ConstRandomAccessIterator<T2> &rhs) {
				return !(lhs < rhs);
			}
			template<typename T2>
			friend bool operator==(const ConstRandomAccessIterator<T2> &lhs, const ConstRandomAccessIterator<T2> &rhs) {
				return (lhs._ptr == rhs._ptr);
			}
			template<typename T2>
			friend bool operator!=(const ConstRandomAccessIterator<T2> &lhs, const ConstRandomAccessIterator<T2> &rhs) {
				return !(lhs == rhs);
			}
			// GETTER  ---------------------
			const pointer &get_ptr() const {
				return (_ptr);
			}
	};

	template<typename T>
	class RevRandomAccessIterator {
		public:
			typedef std::random_access_iterator_tag	iterator_category;
			typedef T	value_type;
			typedef std::ptrdiff_t	difference_type;
			typedef T*	pointer;
			typedef T&	reference;	

		private:
			pointer	_ptr;

		public:
			// CONSTRUCTORS --------
			RevRandomAccessIterator() :
				_ptr(NULL) {}
			explicit RevRandomAccessIterator(pointer it) :
				_ptr(it) {};
			RevRandomAccessIterator(const RevRandomAccessIterator &it) {
				*this = it;
			}
			RevRandomAccessIterator &operator=(const RevRandomAccessIterator &rhs) {
				if (this != &rhs)
					_ptr = rhs._ptr;
				return (*this);
			};
			// DESTRUCTOR ------------
			~RevRandomAccessIterator() {}
			// OPERATORS ----------
			reference operator*() {
				return (*_ptr);
			}
			pointer operator->() {
				return (_ptr);
			}
			reference operator[](const difference_type &off) {
				return (_ptr[-off]);
			}
			RevRandomAccessIterator &operator++() {
				_ptr--;
				return (*this);
			}
			RevRandomAccessIterator operator++(int) {
				RevRandomAccessIterator temp(*this);
				_ptr--;
				return (temp);
			}
			RevRandomAccessIterator &operator--() {
				_ptr++;
				return (*this);
			}
			RevRandomAccessIterator operator--(int) {
				RevRandomAccessIterator temp(*this);
				_ptr++;
				return (temp);
			}
			// ARITHMETIC OPERATORS  --------------------------------------
			difference_type operator+(const RevRandomAccessIterator<T> &rhs) {
				return (_ptr - rhs._ptr);
			}
			RevRandomAccessIterator operator+(const difference_type &off) {
				return RevRandomAccessIterator<T>(_ptr - off);
			}
			difference_type operator-(const RevRandomAccessIterator<T> &rhs) {
				return (_ptr + rhs._ptr);
			}
			RevRandomAccessIterator operator-(const difference_type &off) {
				return RevRandomAccessIterator<T>(_ptr + off);
			}
			RevRandomAccessIterator &operator+=(const difference_type &off) {
				_ptr -= off;
				return (*this);
			}
			RevRandomAccessIterator &operator-=(const difference_type &off) {
				_ptr += off;
				return (*this);
			}
			// RELATIONAL OPERATORS  ------------------------------------------------------------------------
			template<typename T2>
			friend bool operator<(const RevRandomAccessIterator<T2> &lhs, const RevRandomAccessIterator<T2> &rhs) {
				return (lhs._ptr < rhs._ptr);
			}
			template<typename T2>
			friend bool operator>(const RevRandomAccessIterator<T2> &lhs, const RevRandomAccessIterator<T2> &rhs) {
				return (rhs < lhs);
			}
			template<typename T2>
			friend bool operator<=(const RevRandomAccessIterator<T2> &lhs, const RevRandomAccessIterator<T2> &rhs) {
				return !(rhs < lhs);
			}
			template<typename T2>
			friend bool operator>=(const RevRandomAccessIterator<T2> &lhs, const RevRandomAccessIterator<T2> &rhs) {
				return !(lhs < rhs);
			}
			template<typename T2>
			friend bool operator==(const RevRandomAccessIterator<T2> &lhs, const RevRandomAccessIterator<T2> &rhs) {
				return (lhs._ptr == rhs._ptr);
			}
			template<typename T2>
			friend bool operator!=(const RevRandomAccessIterator<T2> &lhs, const RevRandomAccessIterator<T2> &rhs) {
				return !(lhs == rhs);
			}
			// GETTER  ---------------------
			const pointer &get_ptr() const {
				return (_ptr);
			}
	};

	template<typename T>
	class ConstRevRandomAccessIterator {
		public:
			typedef std::random_access_iterator_tag	iterator_category;
			typedef T	value_type;
			typedef std::ptrdiff_t	difference_type;
			typedef T	*pointer;
			typedef T	&reference;
			typedef const T	*const_pointer;
			typedef const T	&const_reference;

		private:
			pointer	_ptr;

		public:
			// CONSTRUCTORS --------
			ConstRevRandomAccessIterator() :
				_ptr(NULL) {}
			explicit ConstRevRandomAccessIterator(pointer it) :
				_ptr(it) {};
			ConstRevRandomAccessIterator(const ConstRevRandomAccessIterator &it) {
				*this = it;
			}
			ConstRevRandomAccessIterator &operator=(const ConstRevRandomAccessIterator &rhs) {
				if (this != &rhs)
					_ptr = rhs._ptr;
				return (*this);
			};
			// DESTRUCTOR ------------
			~ConstRevRandomAccessIterator() {}
			// OPERATORS ----------
			const_reference operator*() {
				return (*_ptr);
			}
			const_pointer operator->() {
				return (_ptr);
			}
			const_reference operator[](const difference_type &off) {
				return (_ptr[-off]);
			}
			ConstRevRandomAccessIterator &operator++() {
				_ptr--;
				return (*this);
			}
			ConstRevRandomAccessIterator operator++(int) {
				ConstRevRandomAccessIterator temp(*this);
				_ptr--;
				return (temp);
			}
			ConstRevRandomAccessIterator &operator--() {
				_ptr++;
				return (*this);
			}
			ConstRevRandomAccessIterator operator--(int) {
				ConstRevRandomAccessIterator temp(*this);
				_ptr++;
				return (temp);
			}
			// ARITHMETIC OPERATORS  --------------------------------------
			difference_type operator+(const ConstRevRandomAccessIterator<T> &rhs) {
				return (_ptr - rhs._ptr);
			}
			ConstRevRandomAccessIterator operator+(const difference_type &off) {
				return ConstRevRandomAccessIterator<T>(_ptr - off);
			}
			difference_type operator-(const ConstRevRandomAccessIterator<T> &rhs) {
				return (_ptr + rhs._ptr);
			}
			ConstRevRandomAccessIterator operator-(const difference_type &off) {
				return ConstRevRandomAccessIterator<T>(_ptr + off);
			}
			ConstRevRandomAccessIterator &operator+=(const difference_type &off) {
				_ptr -= off;
				return (*this);
			}
			ConstRevRandomAccessIterator &operator-=(const difference_type &off) {
				_ptr += off;
				return (*this);
			}
			// RELATIONAL OPERATORS  ------------------------------------------------------------------------
			template<typename T2>
			friend bool operator<(const ConstRevRandomAccessIterator<T2> &lhs, const ConstRevRandomAccessIterator<T2> &rhs) {
				return (lhs._ptr < rhs._ptr);
			}
			template<typename T2>
			friend bool operator>(const ConstRevRandomAccessIterator<T2> &lhs, const ConstRevRandomAccessIterator<T2> &rhs) {
				return (rhs < lhs);
			}
			template<typename T2>
			friend bool operator<=(const ConstRevRandomAccessIterator<T2> &lhs, const ConstRevRandomAccessIterator<T2> &rhs) {
				return !(rhs < lhs);
			}
			template<typename T2>
			friend bool operator>=(const ConstRevRandomAccessIterator<T2> &lhs, const ConstRevRandomAccessIterator<T2> &rhs) {
				return !(lhs < rhs);
			}
			template<typename T2>
			friend bool operator==(const ConstRevRandomAccessIterator<T2> &lhs, const ConstRevRandomAccessIterator<T2> &rhs) {
				return (lhs._ptr == rhs._ptr);
			}
			template<typename T2>
			friend bool operator!=(const ConstRevRandomAccessIterator<T2> &lhs, const ConstRevRandomAccessIterator<T2> &rhs) {
				return !(lhs == rhs);
			}
			// GETTER  ---------------------
			const pointer &get_ptr() const {
				return (_ptr);
			}
	};
} // namespace ft

#endif
