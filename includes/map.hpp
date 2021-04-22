/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-hou <rvan-hou@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/19 14:31:50 by robijnvanho   #+#    #+#                 */
/*   Updated: 2021/04/22 23:45:07 by robijnvanho   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include "utils/traits.hpp"
# include "utils/utils.hpp"
# include "utils/mapNode.hpp"
# include "utils/pair.hpp"
# include "utils/BidirectionalIterator.hpp"
# include <string>
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

		void	set_limits() {
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
			// balance(new_leaf->_parent, new_leaf); // pos of leaf?
			return (new_leaf);
		}
		node_pointer insert_right(const value_type& val, node_pointer position) {
			node_pointer new_leaf = new node(val);
			new_leaf->_parent = position;
			position->_right = new_leaf;
			_size++;
			set_limits();
			// balance(new_leaf->_parent, new_leaf); // pos of leaf?
			return (new_leaf);
		}
		// ROTATIONS
		void	rotateLeft(node_pointer& parent) {
			std::cout << "rotateleft" << std::endl << std::endl;
			node_pointer child = parent->_right;
			node_pointer GP = parent->_parent;
			std::cout << "child: " << child->_data.first << std::endl;
			std::cout << "parent: " << parent->_data.first << std::endl;
			if (parent != _root)
				std::cout << "GP: " << GP->_data.first << std::endl;
			if (_root == GP) {
				GP->_parent = parent;
				GP->_right = NULL;
				parent->_left = GP;
				parent->_parent = NULL;
				_root = parent;
			}
			else {
				parent->_parent = GP->_parent;
				GP->_parent->_right = parent;
				GP->_parent = parent;
				parent->_left = GP;
				GP->_right = NULL;
			}
		}
		void	rotateLeftDouble(node_pointer& parent) {
			std::cout << "rotateLeftDouble" << std::endl << std::endl;
			node_pointer child = parent->_right;
			node_pointer GP = parent->_parent;
			std::cout << "child: " << child->_data.first << std::endl;
			std::cout << "parent: " << parent->_data.first << std::endl;
			std::cout << "GP: " << GP->_data.first << std::endl;
			
			parent->_parent = GP->_parent; // 2 -> 8
			if (GP->_parent)
				GP->_parent->_right = parent; // 8 -> 2
				
			GP->_parent = parent;
			GP->_right = parent->_left;
			
			parent->_left->_parent = GP;
			parent->_left = GP;

			if (_root == GP)
				_root = parent;
		}
		void	rotateRightDouble(node_pointer& parent){
			std::cout << "rotateRightDouble" << std::endl << std::endl;
			node_pointer child = parent->_left;
			node_pointer GP = parent->_parent;
			std::cout << "child: " << child->_data.first << std::endl;
			std::cout << "parent: " << parent->_data.first << std::endl;
			std::cout << "GP: " << GP->_data.first << std::endl;
			
			parent->_parent = GP->_parent; // 2 -> 8
			if (GP->_parent)
				GP->_parent->_left = parent; // 8 -> 2
				
			GP->_parent = parent;
			GP->_left = parent->_right;
			
			parent->_right->_parent = GP;
			parent->_right = GP;

			if (_root == GP)
				_root = parent;
		}
		void	rotateRight(node_pointer& parent) {
			std::cout << "rotateright" << std::endl << std::endl;
			node_pointer child = parent->_left;
			node_pointer GP = parent->_parent;
			std::cout << "child: " << child->_data.first << std::endl;
			std::cout << "parent: " << parent->_data.first << std::endl;
			if (parent != _root)
				std::cout << "GP: " << GP->_data.first << std::endl;
			if (_root == GP) {
				GP->_parent = parent;
				GP->_left = NULL;
				parent->_right = GP;
				parent->_parent = NULL;
				_root = parent;
			}
			else {
				parent->_parent = GP->_parent;
				GP->_parent->_left = parent;
				GP->_parent = parent;
				parent->_right = GP;
				GP->_left = NULL;
			}
		}
		// BALANCING
		int height(node_pointer tmp) { // returns height from node
			int left;
			int right;

			if (tmp == NULL)
				return 0;
			left = height(tmp->_left);
			right = height(tmp->_right);
			if (left > right)
				return left + 1;
			else
				return right + 1;
		}
		int getBalance(node_pointer node) { // calculates balance factor of tree
			int ret;

			ret = (height(node->_left) - height(node->_right));
			return ret;
		}
		// BALANCE!
		void	balance(node_pointer parent, node_pointer newNode) { // balances tree
			int B;

			(void)newNode;
			B = getBalance(_root);
			std::cout << B << std::endl;
			if (B >= -1 && B <= 1) {
				std::cout << "balanced" << std::endl;
				return; // balanced
			}
			else {
				if (B == -2) { // < -1
					std::cout << "right_heavy" << std::endl;
					if (getBalance(parent->_parent) == 0) {
						std::cout << "node: " << parent->_parent->_data.first << std::endl;
						rotateLeft(parent->_parent);
					}
					else
						rotateLeftDouble(parent);
				}
				else if (B == 2) { // > 1
					std::cout << "left_heavy" << std::endl;
					// if (newNode->_data.first < parent->_data.first) {
					if (getBalance(parent->_parent) == 0) { // right_exists
						std::cout << "node: " << parent->_parent->_data.first << std::endl;
						rotateRightDouble(parent->_parent);
					}
					else
						rotateRight(parent);
				}
			}
		}
	public:
		// PRINT
		void	print_node(std::string root_path) {
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
			if (tmp->_data.first)
				std::cout << "\033[1;37m" << tmp->_data.first << "\033[0m";
		}
		void	print_tree() {
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
	// public:
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
		pair<iterator,bool>	insert(const value_type& val) {
			_first->_parent->_left = NULL;
			_last->_parent->_right = NULL;
			if (_size == 0) {
				delete _root; // delete old
				_root = new node(val); // create root with val
				_size++; // plus size
				set_limits();
				// balance(_root);
				return (ft::make_pair(iterator(_root), true)); // return pair made of root
			}
			mapNode<value_type>* move = _root;
			while (move->_left || move->_right) {
				if (move->_data.first == val.first) {
					set_limits();
					// balance(move->_parent, move);
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
				set_limits();
				// balance(move->_parent, move);
				return (ft::make_pair(iterator(move), false));
			}
			if (value_compare(_comp)( val, move->_data)) {
				move = insert_left(val, move);
				balance(move->_parent, move);
			}
			else {
				move = insert_right(val, move);
				balance(move->_parent, move);
			}
			return (ft::make_pair(iterator(move), true));
		}
	}; // class map
} // namespace ft

#endif