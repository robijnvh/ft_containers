#ifndef VECTOR_TEST_HPP
#define VECTOR_TEST_HPP

#include <stdio.h> //REMOVE

#include <algorithm>
#include <cstddef>
#include <memory>
#include <limits>

#include "UTILS/RandomAccessIterator.hpp"
#include "UTILS/Traits.hpp"

namespace ft {

    template<class T, class Alloc = std::allocator<T> >
    class vector {

    public:
        // MEMBER TYPES
        typedef T                                   value_type;
        typedef Alloc                               allocator_type;
        typedef T&                                  reference;
        typedef const T&                            const_reference;
        typedef T*                                  pointer;
        typedef const T*                            const_pointer;
        typedef RandomAccessIterator<T>             iterator;
        typedef ConstRandomAccesIterator<T>         const_iterator;
        typedef RevRandomAccesIterator<T>           reverse_iterator;
        typedef ConstRevRandomAccesIterator<T>      const_reverse_iterator;
        typedef std::ptrdiff_t                      difference_type;
        typedef size_t                              size_type;

    private:
        pointer         _array;
        allocator_type  _allocator;
        size_type       _used;
        size_type       _capacity;

        void reallocation(size_type size)
        {
            pointer temp = new value_type[size];
            for (size_type i = 0; i < _used; i++)
                temp[i] = _array[i];
            _capacity = size;
            delete[] _array;
            _array = temp;
        }

        size_t distance(iterator first, iterator second) {
            size_t n = 0;
            for (iterator it = first; it != second; it++)
                n++;
            return (n);
        }

    public:
        // ----------------------------------------- CONSTRUCTOR / DESTRUCTOR ------------------------------------------
        //-> Constructs an empty container, with no elements.
        explicit vector (const allocator_type& alloc = allocator_type()) : _array(NULL), _allocator(alloc), _used(0), _capacity(0) {};

        //-> Constructs a container with n elements. Each element is a copy of val.
        explicit vector (size_type n, const value_type& val = value_type(),
                         const allocator_type& alloc = allocator_type()) : _allocator(alloc), _used(0), _capacity(n) {
            _array = new value_type[n];
            assign(n, val);
        };

        //-> Constructs a container with as many elements as the range [first,last), with each element
        //   constructed from its corresponding element in that range, in the same order.
        template <class InputIterator>
        vector (typename enable_if<is_input_iterator<InputIterator>::value, InputIterator>::type first, InputIterator last,
                const allocator_type& alloc = allocator_type()) : _allocator(alloc), _used(0), _capacity(0) {
            assign(first, last);
            shrink_to_fit();
        };

        //-> Constructs a container with a copy of each of the elements in x, in the same order.
        vector (const vector& x) : _allocator(x._allocator), _used(0), _capacity(x._capacity) {
            _array = new value_type[x._capacity];
            assign(x.begin(), x.end());
        };

        //-> Destroys the container object.
        ~vector() {
            if (_capacity)
                delete[] _array;
        };

        //-> Assigns new contents to the container, replacing its current contents, and modifying its size accordingly.
        vector& operator= (const vector& x) {
            delete[] _array;
            _array = new value_type[x._capacity];
            _allocator = x._allocator;
            _used = 0;
            _capacity = x._capacity;
            assign(x.begin(), x.end());
            return (*this);
        };

        // ------------------------------------------------- ITERATORS -------------------------------------------------
        //-> Returns an iterator pointing to the first element in the vector.
        iterator begin() {return iterator(_array);};
        const_iterator begin() const {return const_iterator(_array);};

        //-> Returns an iterator referring to the past-the-end element in the vector container.
        //iterator end() {return iterator(&_array[_used]);};
        iterator end() {return iterator(&_array[_used]);};
        const_iterator end() const {return const_iterator(&_array[_used]);};

        //-> Returns a reverse iterator pointing to the last element in the vector.
        reverse_iterator rbegin() {return reverse_iterator(&_array[_used - 1]);};
        const_reverse_iterator rbegin() const {return const_reverse_iterator (&_array[_used - 1]);};

        //-> Returns a reverse iterator pointing to the theoretical element preceding the first element in the vector.
        reverse_iterator rend() {return reverse_iterator(_array - 1);};
        const_reverse_iterator rend() const {return const_reverse_iterator (_array - 1);};


        // -------------------------------------------------- CAPACITY -------------------------------------------------
        //-> Returns the number of elements in the vector.
        size_type size() const {return (_used);};

        //-> Returns the maximum number of elements that the vector can hold.
        size_type max_size() const {return((std::numeric_limits<size_type>::max() / sizeof(value_type)));};

        //-> Resizes the container so that it contains n elements.
        void resize (size_type n, value_type val = value_type()) {
            if (n < _used)
                _used -= (_used - n);
            while (n > _used)
                push_back(val);
        };

        //-> Returns the size of the storage space currently allocated for the vector, expressed in terms of elements.
        size_type capacity() const { return (_capacity);};

        //-> Returns whether the vector is empty
        bool empty() const {return (_used == 0);};

        //-> Requests that the vector capacity be at least enough to contain n elements.
        void reserve (size_type n) {
            if (n > _capacity)
                reallocation(n);
        };

        //-> Requests the container to reduce its capacity to fit its size.
        void shrink_to_fit() {
            if (_capacity > _used)
                reallocation(_used);
        };


        // ----------------------------------------------- ELEMENT ACCESS ----------------------------------------------
        //-> Returns a reference to the element at position n in the vector container.
        reference operator[] (size_type n) {return reference(_array[n]);};

        const_reference operator[] (size_type n) const {return const_reference(_array[n]);};

        //-> Returns a reference to the element at position n in the vector.
        reference at (size_type n) {
            if (n < _used)
                return reference(_array[n]);
            throw (std::out_of_range("Index out of range"));
        };

        const_reference at (size_type n) const {
            if (n < _used)
                return const_reference(_array[n]);
            throw (std::out_of_range("Index out of range"));
        };

        //-> Returns a reference to the first element in the vector.
        reference front() {return reference(_array[0]);};
        const_reference front() const {return const_reference(_array[0]);};

        //-> Returns a reference to the last element in the vector.
        reference back() {return reference(_array[_used - 1]);};
        const_reference back() const {return const_reference(_array[_used - 1]);};


        // ------------------------------------------------- MODIFIERS -------------------------------------------------
        //->  the new contents are elements constructed from each of the elements in the range between first and
        //    last, in the same order.
        template <class InputIterator>
        void assign (typename enable_if<is_input_iterator<InputIterator>::value, InputIterator>::type first, InputIterator last) {
            clear();
            while (first != last) {
                push_back(*first);
                first++;
            }
        };

        //-> the new contents are n elements, each initialized to a copy of val.
        void assign (size_type n, const value_type& val) {
            clear();
            for (size_type i = 0; i < n; i++)
                push_back(val);
        };

        //-> Adds a new element at the end of the vector, after its current last element.
        void push_back (const value_type& val) {
            if (_capacity == 0){
                _array = new value_type [1];
                _capacity = 1;
            }
            if (_capacity == _used)
                reallocation((2 * _capacity));
            _array[_used] = val;
            _used += 1;
        };

        //-> Removes the last element in the vector, effectively reducing the container size by one.
        void pop_back() {
            _used--;
        };

        //->The vector is extended by inserting new elements before the element at the specified position.
        iterator insert (iterator position, const value_type& val) {
            size_t n = distance(begin(), position);
            insert(position, 1, val);
            return (iterator(&_array[n]));
        };

        void insert (iterator position, size_type n, const value_type& val) {
            vector temp(position, end());
            _used = distance(begin(), position);

            for (size_t i = 0; i < n; i++)
                push_back(val);
            for (iterator it = temp.begin(); it != temp.end(); it++)
                push_back(*it);
        };

        template <class InputIterator>
        void insert (iterator position, typename enable_if<is_input_iterator<InputIterator>::value, InputIterator>::type first, InputIterator last) {
            vector temp(position, end());
            _used = distance(begin(), position);

            for (iterator it = first; it < last; it++)
                push_back(*it);
            for (iterator it = temp.begin(); it != temp.end(); it++)
                push_back(*it);
        };

        //-> Removes from the vector either a single element (position) or a range of elements ([first,last)).
        iterator erase (iterator position) {
            iterator ret(position);

            while (position != end()-1) {
                *position = *(position + 1);
                position++;
            }
            _used -= 1;
            return (ret);
        };

        iterator erase (iterator first, iterator last) {
            iterator ret(first);

            while (last != end()) {
                *first = *last;
                first++;
                last++;
            }
            _used -= distance(first, last);
            return (ret);
        };

        //-> Exchanges the content of the container by the content of x, which is another vector object of the same type.
        //   Sizes may differ.
        void swap (vector& x) {
            vector temp(*this);

            *this = x;
            x = temp;
        };

        //-> Removes all elements from the vector (which are destroyed), leaving the container with a size of 0.
        void clear() {
            _used = 0;
        };

    };

    template <typename T>
    void swap(vector<T> &x, vector<T> &y)
    {
        vector<T> temp(y);
        y = x;
        x = temp;
    }

    // -------------------------------------------- RELATION OPERATORS  --------------------------------------------
    template <class value_type, class allocator_type>
    bool operator== (const vector<value_type,allocator_type>& lhs, const vector<value_type,allocator_type>& rhs) {
        typename ft::vector<value_type>::const_iterator it_lhs = lhs.begin();
        typename ft::vector<value_type>::const_iterator it_rhs = rhs.begin();

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
    bool operator!= (const vector<value_type,allocator_type>& lhs, const vector<value_type,allocator_type>& rhs) {return !(lhs == rhs);}

    template <class value_type, class allocator_type>
    bool operator< (const vector<value_type,allocator_type>& lhs, const vector<value_type,allocator_type>& rhs) {
        return (std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));}

    template <class value_type, class allocator_type>
    bool operator<= (const vector<value_type,allocator_type>& lhs, const vector<value_type,allocator_type>& rhs) {return !(rhs < lhs);}

    template <class value_type, class allocator_type>
    bool operator>  (const vector<value_type,allocator_type>& lhs, const vector<value_type,allocator_type>& rhs) {return (rhs<lhs);}

    template <class value_type, class allocator_type>
    bool operator>= (const vector<value_type,allocator_type>& lhs, const vector<value_type,allocator_type>& rhs) {return !(lhs < rhs);}

};

#endif //FT_CONTAINERS_VECTOR_HPP