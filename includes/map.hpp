/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-hou <rvan-hou@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/19 14:31:50 by robijnvanho   #+#    #+#                 */
/*   Updated: 2021/04/26 13:05:41 by robijnvanho   ########   odam.nl         */
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
		typedef BidirectionalIterator<value_type, node>	iterator;
		typedef ConstBidirectionalIterator<value_type, node>	const_iterator;
		typedef RevBidirectionalIterator<value_type, node>	reverse_iterator;
		typedef ConstRevBidirectionalIterator<value_type, node>	const_reverse_iterator;

	private:
		node_pointer	_root;
		node_pointer	_first;
		node_pointer	_last;
		Alloc			_allocator;
		size_t			_size;
		Compare			_comp;

		// LIMITS
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
		// INSERT
		node_pointer insert_left(const value_type& val, node_pointer position) {
			node_pointer new_leaf = new node(val);
			new_leaf->_parent = position;
			position->_left = new_leaf;
			_size++;
			set_limits();
			return (new_leaf);
		}
		node_pointer insert_right(const value_type& val, node_pointer position) {
			node_pointer new_leaf = new node(val);
			new_leaf->_parent = position;
			position->_right = new_leaf;
			_size++;
			set_limits();
			return (new_leaf);
		}
		// ROTATIONS
		void	rotateLeft(node_pointer parent) {
			std::cout << "rotateleft" << std::endl << std::endl;
			node_pointer child = parent->_right;
			node_pointer GP = parent->_parent;
			// std::cout << "child: " << child->_data.first << std::endl;
			// std::cout << "parent: " << parent->_data.first << std::endl;
			// if (parent != _root)
				// std::cout << "GP: " << GP->_data.first << std::endl;
			GP->_left = child;
			child->_parent = GP;
			parent->_parent = child;
			parent->_right = NULL;
			child->_left = parent;
		}
		void	rotateLeftDouble(node_pointer parent) {
			std::cout << "rotateLeftDouble" << std::endl << std::endl;
			// node_pointer child = parent->_right;
			node_pointer GP = parent->_parent;
			// std::cout << "child: " << child->_data.first << std::endl;
			// std::cout << "parent: " << parent->_data.first << std::endl;
			// std::cout << "GP: " << GP->_data.first << std::endl;
			
			if (_root == GP)
				_root = parent;
			parent->_parent = GP->_parent; // 2 -> 8
			if (GP->_parent){
				if (GP == GP->_parent->_right)
					GP->_parent->_right = parent; // 8 -> 2
				else 
					GP->_parent->_left = parent; // 8 -> 2
			}
			GP->_parent = parent;
			GP->_right = parent->_left;
			
			if (parent->_left)
				parent->_left->_parent = GP;
			parent->_left = GP;
		}
		void	rotateRightDouble(node_pointer parent){
			std::cout << "rotateRightDouble" << std::endl << std::endl;
			// node_pointer child = parent->_left;
			node_pointer GP = parent->_parent;
			// std::cout << "root: " << _root->_data.first << std::endl;
			// std::cout << "child: " << child->_data.first << std::endl;
			// std::cout << "parent: " << parent->_data.first << std::endl;
			// std::cout << "GP: " << GP->_data.first << std::endl;
			
			if (_root == GP)
				_root = parent;
			parent->_parent = GP->_parent; // 2 -> 8
			if (GP->_parent){
				if (GP == GP->_parent->_left)
					GP->_parent->_left = parent; // 8 -> 2
				else 
					GP->_parent->_right = parent; // 8 -> 2
			}
			GP->_parent = parent;
			GP->_left = parent->_right;
			
			if (parent->_right)
				parent->_right->_parent = GP;
			parent->_right = GP;

		}
		void	rotateRight(node_pointer parent) {
			std::cout << "rotateright" << std::endl << std::endl;
			// node_pointer child = parent->_left;
			node_pointer GP = parent->_parent;
			// std::cout << "child: " << child->_data.first << std::endl;
			// std::cout << "parent: " << parent->_data.first << std::endl;
			// if (parent != _root)
				// std::cout << "GP: " << GP->_data.first << std::endl;
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
		// TEST!!!!!!!!!!!!!!!
		// node_pointer llrotation(node_pointer n){
		// 	node_pointer p;
		// 	node_pointer tp;
		// 	p = n;
		// 	tp = p->_left;

		// 	p->_left = tp->_right;
		// 	tp->_right = p;

		// 	return tp; 
		// }
		// node_pointer rrrotation(node_pointer n){
		// 	node_pointer p;
		// 	node_pointer tp;
		// 	p = n;
		// 	tp = p->_right;

		// 	p->_right = tp->_left;
		// 	tp->_left = p;

		// 	return tp; 
		// }
		// node_pointer rlrotation(node_pointer n){
		// 	node_pointer p;
		// 	node_pointer tp;
		// 	node_pointer tp2;
		// 	p = n;
		// 	tp = p->_right;
		// 	tp2 =p->_right->_left;

		// 	p -> _right = tp2->_left;
		// 	tp ->_left = tp2->_right;
		// 	tp2 ->_left = p;
		// 	tp2->_right = tp; 
			
		// 	return tp2; 
		// }
		// node_pointer lrrotation(node_pointer n){
		// 	node_pointer p;
		// 	node_pointer tp;
		// 	node_pointer tp2;
		// 	p = n;
		// 	tp = p->_left;
		// 	tp2 =p->_left->_right;

		// 	p -> _left = tp2->_right;
		// 	tp ->_right = tp2->_left;
		// 	tp2 ->_right = p;
		// 	tp2->_left = tp; 
			
		// 	return tp2; 
		// }
		// BALANCE
		int height(node_pointer tmp) { // returns height from node
			int left;
			int right;

			if (tmp == NULL || tmp == _first || tmp == _last)
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
			// std::cout << "height_left: " << height(node->_left) << " height_right: " << height(node->_right) << std::endl;
			return ret;
		}
		// BALANCE!
		int	balance(node_pointer start) { // finds imbalance while iterating through tree
			node_pointer move;
			node_pointer end;
			node_pointer begin;
			int	balance;

			std::cout << "start: " << start->_data.first << std::endl;
			if (start->_data.first < _root->_data.first) { // left
				move = _first;
				begin = _first;
				end = _last;
			}
			else {
				move = _last; // right
				begin = _last;
				end = _first;
			}
			while (move != end) {
				balance = getBalance(move);
				if (balance == -2 || balance == 2) {
					std::cout << "imblance at node: " << move->_data.first << " balance_factor: " << balance << std::endl;
					if (balance == 2 && getBalance(move->_left) > 0) {
						std::cout << "left_heavy" << std::endl;
						print_tree();
						rotateRightDouble(move->_left);
						// move = llrotation(move);
					}
					else if (balance == -2 && getBalance(move->_right) < 0) {
						std::cout << "right_heavy" << std::endl;
						print_tree();
						rotateLeftDouble(move->_right);
						// move = rrrotation(move);
					}
					else if (balance == -2 && getBalance(move->_right) > 0) {
						std::cout << "right_heavy" << std::endl;
						print_tree();
						rotateRight(move->_right);
						rotateLeftDouble(move->_right);
						// move = rlrotation(move);
					}
					else if (balance == 2 && getBalance(move->_left) < 0) {
						std::cout << "left_heavy" << std::endl;
						print_tree();
						rotateLeft(move->_left);
						rotateRightDouble(move->_left);
						// move = lrrotation(move);
					}
					move = begin;
				}
				else {
					if (start->_data.first < _root->_data.first)
						move = move->getNext();
					else
						move = move->getPrev();
				}
			}
			return (0);
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
		template <class InputIterator>
		map(typename enable_if<is_input_iterator<InputIterator>::value, InputIterator>::type first, InputIterator last, const Compare& comp = Compare(), const Alloc& alloc = Alloc()) : // fill with range
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
				insert(first, last);
			}	
		map(const map& x) : // copy
			_allocator(x._allocator),
			_size(x._size),
			_comp(x._comp) {
				_root = new node();
				_first = new node();
				_last = new node();
				_first->_parent = _root;
				_last->_parent = _root;
				_root->_left = _first;
				_root->_right = _last;
				insert(x.begin(), x.end());
			}
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
			insert(other.begin(), other.end());
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
			// return this->_allocator.max_size() / 2;
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
				return (ft::make_pair(iterator(_root), true)); // return pair made of root
			}
			mapNode<value_type>* move = _root;
			while (move->_left || move->_right) {
				if (move->_data.first == val.first) {
					set_limits();
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
				return (ft::make_pair(iterator(move), false));
			}
			if (value_compare(_comp)( val, move->_data)) {
				move = insert_left(val, move);
				balance(move);
			}
			else {
				move = insert_right(val, move);
				balance(move);
			}
			return (ft::make_pair(iterator(move), true));
		}
		iterator	insert(iterator position, const value_type& val) { // insert val with hint position
			(void)position;
			insert(val);
		}
		template <class InputIterator> 
		void insert (typename enable_if<is_input_iterator<InputIterator>::value, InputIterator>::type first, InputIterator last) { // insert range
			for (; first != last; first++)
				insert(*first);
		}
	}; // class map

// RELATIONAL OPERATORS
// template < class Key, class T, class Compare, class Alloc>
// bool operator== (const ft::map<Key,T,ft::pair<const Key,T>, Compare, Alloc>& lhs, const ft::map<Key,T,ft::pair<const Key,T>, Compare, Alloc>& rhs) {
// 	return (lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
// }
// template < class Key, class T, class Compare, class Alloc>
// bool operator!= (const map<Key,T,ft::pair<const Key,T>, Compare, Alloc>& lhs, const map<Key,T,ft::pair<const Key,T>, Compare, Alloc>& rhs) {
// 	return !(lhs == rhs);
// }
// template < class Key, class T, class Compare, class Alloc>
// bool operator<  (const map<Key,T,ft::pair<const Key,T>, Compare, Alloc>& lhs, const map<Key,T,ft::pair<const Key,T>, Compare, Alloc>& rhs) {
// 	return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
// }
// template < class Key, class T, class Compare, class Alloc>
// bool operator>  (const map<Key,T,ft::pair<const Key,T>, Compare, Alloc>& lhs, const map<Key,T,ft::pair<const Key,T>, Compare, Alloc>& rhs) {
// 	return (rhs < lhs);
// }
// template < class Key, class T, class Compare, class Alloc>
// bool operator<= (const map<Key,T,ft::pair<const Key,T>, Compare, Alloc>& lhs, const map<Key,T,ft::pair<const Key,T>, Compare, Alloc>& rhs) {
// 	return !(lhs > rhs);
// }
// template < class Key, class T, class Compare, class Alloc>
// bool operator>= (const map<Key,T,ft::pair<const Key,T>, Compare, Alloc>& lhs, const map<Key,T,ft::pair<const Key,T>, Compare, Alloc>& rhs) {
// 	return !(lhs < rhs);
// }
} // namespace ft

#endif