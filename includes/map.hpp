/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-hou <rvan-hou@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/19 14:31:50 by robijnvanho   #+#    #+#                 */
/*   Updated: 2021/04/21 16:52:40 by robijnvanho   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include "utils/traits.hpp"
# include "utils/utils.hpp"
# include "utils/mapNode.hpp"
# include "utils/pair.hpp"
# include "utils/BidirectionalIterator.hpp"
# include <memory>
# include <limits>
# include <iostream> // to print

namespace ft {
template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<pair<const Key,T> > >
class map {
	public:
		// TYPES
		typedef ft::pair<const Key, T>                              value_type;
		typedef mapNode<value_type>*	node_pointer;
		typedef mapNode<value_type>	node;
		typedef BidirectionalIterator<T, node>	iterator;
		typedef ConstBidirectionalIterator<T, node>	const_iterator;
		typedef RevBidirectionalIterator<T, node>	reverse_iterator;
		typedef ConstRevBidirectionalIterator<T, node>	const_reverse_iterator;

	private:
		node_pointer	_root;
		node_pointer	_first;
		node_pointer	_last;
		Alloc			_allocator;
		size_t			_size;
		Compare			_comp;

		void    set_limits() {
            node_pointer temp = _root;
            while (temp->_left != NULL)
                temp = temp->_left;
            temp->_left = _first;
            _first->_parent = temp;

            temp = _root;
            while (temp->_right != NULL)
                temp = temp->_right;
            temp->_right = _last;
            _last->_parent = temp;
        }
		node_pointer insert_left(const value_type& val, node_pointer position) {
            node_pointer new_leaf = new node(val);

            new_leaf->_parent = position;
            position->_left = new_leaf;
            _size++;
            set_limits();
            return (new_leaf);
        }
        node_pointer insert_right(const value_type & val, node_pointer position) {
            node_pointer new_leaf = new node(val);

            new_leaf->_parent = position;
            position->_right = new_leaf;
            _size++;
            set_limits();
            return (new_leaf);
        }
	public:
			// PRINT
		void                print_node(std::string root_path)
		{
			node_pointer tmp = _root;
			std::cout << ".";
			for (int i = 0; root_path[i]; ++i){
				if (root_path[i] == 'L'){
					if (tmp->_left == NULL)
						return ;
					tmp = tmp->_left;
				}
				if (root_path[i] == 'R'){
					if (tmp->_right == NULL)
						return ;
					tmp = tmp->_right;
				}
			}
			// if (tmp->data.first){
			// 	if (tmp->color)
			// 		std::cout << CRED << tmp->data.first << CRESET;
			// 	else
			// 		std::cout << CYELLOW << tmp->data.first << CRESET;
			// }
		}
		void                print_tree()
		{
			std::string root_path;
			int layer = 0;
			root_path = "";
			int starting_tabs = 16;
			int starting_gap = 16;
			while (layer < 5)
			{
				root_path.clear();
				int tmp_tabs = starting_tabs;
				int tmp_gap = starting_gap;
				for (int tmp_layer = layer; tmp_layer; --tmp_layer)
				{
					root_path.append("L");
					tmp_gap = tmp_gap / 2;
					tmp_tabs -= tmp_gap;
				}
				while (root_path.find('L') != std::string::npos){
					if (root_path.find('R') == std::string::npos)
						for (; tmp_tabs; --tmp_tabs)
							std::cout << "   ";
					else
						for (int tmp_gap2 = tmp_gap * 2; tmp_gap2; --tmp_gap2)
							std::cout << "   ";
					print_node(root_path);
					size_t L_found = root_path.find_last_of('L');
					root_path[L_found] = 'R';
					++L_found;
					for (;L_found != root_path.size(); ++L_found){
						root_path[L_found] = 'L';
					}
				}
				if (root_path.find('R') == std::string::npos)
					for (; tmp_tabs; --tmp_tabs)
						std::cout << "   ";
				else
					for (int tmp_gap2 = tmp_gap * 2; tmp_gap2; --tmp_gap2)
						std::cout << "   ";
				print_node(root_path);
				std::cout << std::endl << std::endl << std::endl;
				layer++;
			}
		}
		// VALUE_COMPARE
		class value_compare {
			friend class map;
			protected:
				Compare comp;
				value_compare (Compare c) : comp(c) {}
			public:
				bool operator() (const value_type & x, const value_type & y) const {
					return comp(x.first, y.first);
				}
		};
		// CONSTRUCTORS
		explicit	map(const Compare& comp = Compare(), const Alloc& alloc = Alloc()) : // empty
			_allocator(alloc),
			_size(0),
			_comp(comp) {
				_root = new node();
				_first = new node();
				_last = new node();
				_first->_parent = _root;
				_last->_parent = _root;
				_root->_left = _first;
				_root->_right = _last;
			}	
		// template <class InputIterator>
		// map(typename enable_if<is_input_iterator<InputIterator>::value, InputIterator>::type first, InputIterator last, const Key& comp = Key(), const Alloc& alloc = Alloc()) : // fill with range
		// 	_allocator(alloc),
		// 	_size(0),
		// 	_comp(comp) {
		// 		_root = new node();
		// 		_first = new node();
		// 		_last = new node();
		// 		_first->_parent = _root;
		// 		_last->_parent = _root;
		// 		_root->_left = _first;
		// 		_root->_right = _last;
		// 		// insert(first, last);
		// 	}	
		// map(const map& x) : // copy
		// 	_allocator(x._allocator),
		// 	_size(x._size),
		// 	_comp(x._comp) {
		// 		_root = new node();
		// 		_first = new node();
		// 		_last = new node();
		// 		_first->_parent = _root;
		// 		_last->_parent = _root;
		// 		_root->_left = _first;
		// 		_root->_right = _last;
		// 		// insert(x.begin(), x.end());
		// 	}
		// DESTRUCTORS
		~map() {
			// clear();
			delete _root;
			delete _first;
			delete _last;
		}
		// ASSIGNATION OPERATOR
		map&	operator=(map const& other) {
			// clear();
			_allocator = other._allocator;
			_size = 0;
			_root = new node();
			_first = new node();
			_last = new node();
			_first->_parent = _root;
			_last->_parent = _root;
			_root->_left = _first;
			_root->_right = _last;;
			// insert(other.begin(), other.end());
			return *this;
		}
		// ITERATORS
		iterator begin() {
			return (iterator(_first->_parent));
		}
		const_iterator begin() const {
			return (const_iterator(_first->_parent));
		}
		iterator end() {
			return (iterator(_last));
		}
		const_iterator end() const {
			return (const_iterator(_last));
		}
		reverse_iterator rbegin() {
			return (reverse_iterator(_last->_parent));
		}
		const_reverse_iterator rbegin() const {
			return (const_reverse_iterator(_last));
		}
		reverse_iterator rend() {
			return (reverse_iterator(_first));
		}
		const_reverse_iterator rend() const {
			return (const_reverse_iterator(_first));
		}
		// CAPACITY
		bool	empty() const {
			return (_size == 0);
		}
		size_t	size() const {
			return _size;
		}
		size_t	max_size() const {
			return (std::numeric_limits<size_t>::max() / sizeof(mapNode<value_type>));
		}
		// MODIFIERS
		pair<iterator,bool>	insert(const value_type & val) {
			if (_size == 0) {
				delete _root; // delete old
				_root = new node(val); // create root with val
				_size++; // plus size
				node_pointer temp = _root; // set tmp
				while (temp->_left != NULL) // set limits
					temp = temp->_left;
				temp->_left = _first;
				_first->_parent = temp;
				temp = _root;
				while (temp->_right != NULL)
					temp = temp->_right;
				temp->_right = _last;
				_last->_parent = temp;
				return (ft::make_pair(iterator(_root), true)); // return pair made of root
			}
			mapNode<value_type>* move = _root;
			while (move->_left || move->_right) {
				if (move->_data.first == val.first) {
					node_pointer temp = _root; // set tmp
					while (temp->_left != NULL) // set limits
						temp = temp->_left;
					temp->_left = _first;
					_first->_parent = temp;
					temp = _root;
					while (temp->_right != NULL)
						temp = temp->_right;
					temp->_right = _last;
					_last->_parent = temp;
					return (ft::make_pair(iterator(move), false));
                }
                if (value_compare(_comp)(val, move->_data)) {
                    if (move->_left != NULL)
                        move = move->_left;
                    else
                        break;
                }
                else {
                    if (move->_right != NULL)
                        move = move->_right;
                    else
                        break;
                }
            }
            if (move->_data.first == val.first) {
                	node_pointer temp = _root; // set tmp
					while (temp->_left != NULL) // set limits
						temp = temp->_left;
					temp->_left = _first;
					_first->_parent = temp;
					temp = _root;
					while (temp->_right != NULL)
						temp = temp->_right;
					temp->_right = _last;
					_last->_parent = temp;
                return (ft::make_pair(iterator(move), false));
            }
            if (value_compare(_comp)( val, move->_data))
                move = insert_left(val, move);
            else
                move = insert_right(val, move);
            return (ft::make_pair(iterator(move), true));
		}
	}; // class map
} // namespace ft

#endif