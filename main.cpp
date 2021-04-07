// #include "includes/utils/RandomAccessIterator.hpp"
#include "includes/list.hpp"
#include "includes/vector.hpp"
#include <list>
#include <vector>
#include <iostream>

int	main() {
	ft::list<int> ft_list;
	std::list<int> std_list;

	std::cout << ft_list.size() << std::endl;
	std::cout << std_list.size() << std::endl;
}

#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include "listNode.hpp"

namespace ft {

    template<typename T, typename Node>
    class BidirectionalIterator {

    public:
        // MEMBER TYPES
        typedef std::bidirectional_iterator_tag         iterator_category;
        typedef Node                                    *iterator_type;
        typedef T                                       value_type;
        typedef std::ptrdiff_t                          difference_type;
        typedef T                                       *pointer;
        typedef T                                       &reference;

    private:
        iterator_type   _ptr;

    public:
        // MEMBER FUNCTIONS
        // ----------------------------------------- CONSTRUCTOR / DESTRUCTOR -----------------------------------------
        BidirectionalIterator() : _ptr(NULL) {};
        explicit BidirectionalIterator (iterator_type it) : _ptr(it) {};
        BidirectionalIterator (const BidirectionalIterator& it) {*this = it;};
        BidirectionalIterator & operator=(const BidirectionalIterator& rhs) {
            if (this != &rhs)
                _ptr = rhs._ptr;
            return (*this);
        };

        ~BidirectionalIterator() {};

        // --------------------------------------------- * OPERATOR ---------------------------------------------------
        reference operator*() {return(_ptr->_data);};

        // --------------------------------------------- -> OPERATOR ---------------------------------------------------
        pointer operator->() {return(&_ptr->_data);};

        // --------------------------------------------- ++ OPERATOR ---------------------------------------------------
        BidirectionalIterator& operator++() {_ptr = _ptr->getNext(); return (*this);};

        BidirectionalIterator  operator++(int) {
            BidirectionalIterator temp(*this);

            _ptr = _ptr->getNext();
            return (temp);
        };

        // --------------------------------------------- -- OPERATOR ---------------------------------------------------
        BidirectionalIterator& operator--() {_ptr = _ptr->getPrev(); return (*this);};

        BidirectionalIterator  operator--(int) {
            BidirectionalIterator temp(*this);

            _ptr = _ptr->getPrev();
            return (temp);
        };

        // ----------------------------------------- RELATIONAL OPERATORS  ---------------------------------------------
        template<typename T2, typename Node2>
        friend bool operator== (const BidirectionalIterator<T2, Node2>& lhs, const BidirectionalIterator<T2, Node2>& rhs) {return (lhs._ptr == rhs._ptr);};

        template<typename T2, typename Node2>
        friend bool operator!= (const BidirectionalIterator<T2, Node2>& lhs, const BidirectionalIterator<T2, Node2>& rhs) {return !(lhs == rhs);;};

        // -----------------------------------------------  GETTER  ---------------------------------------------------
        const iterator_type&   get_ptr() const {return (_ptr);};
    };