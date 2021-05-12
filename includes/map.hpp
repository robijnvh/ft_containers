/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-hou <rvan-hou@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/19 14:31:50 by robijnvanho   #+#    #+#                 */
/*   Updated: 2021/05/07 13:18:08 by robijnvanho   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include "utils/traits.hpp"
# include "utils/mapNode.hpp"
# include "utils/pair.hpp"
# include "utils/utils.hpp"
# include "utils/BidirectionalIterator.hpp"
# include <string>
# include <memory>
# include <limits>
# include <iostream> // to print

namespace ft {
template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key,T> > >
class map {
	public:
		// TYPES
		typedef ft::pair<const Key, T>	value_type;
		typedef mapNode<value_type>*	node_pointer;
		typedef mapNode<value_type>	node;
		typedef BidirectionalIterator<value_type, node>	iterator;
		typedef ConstBidirectionalIterator<value_type, node>	const_iterator;
		typedef RevBidirectionalIterator<value_type, node>	reverse_iterator;
		typedef ConstRevBidirectionalIterator<value_type, node>	const_reverse_iterator;

	private:
		node_pointer		_root;
		node_pointer		_first;
		node_pointer		_last;
		Alloc				_allocatorPair;
		ft::allocator<node>	_allocatorNode;
		size_t				_size;
		Compare				_comp;

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
		// DEL
		void deallocateNode(node_pointer del) {
			_allocatorPair.destroy(&del->_data);
			_allocatorNode.deallocate(del, 1);
		}
		// SWAP
		template <typename U>
		void swap(U& a, U& b) {
			U tmp = a;
			a = b;
			b = tmp;
		}
		//SEARCH
		node_pointer	searchNode(node_pointer root, Key key) const { // search specific node and ret pointer if found
			if (!root || root == _last)
				return 0;
			if (!_comp(root->_data.first, key) && !_comp(key, root->_data.first))
				return root;
			if (root->_data.first > key && root->_left && root->_left != _last)
				return searchNode(root->_left, key);
			else if (root->_data.first < key && root->_right && root->_right != _last)
				return searchNode(root->_right, key);
			return 0;
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
		void	rotateRight(node_pointer* root, node_pointer nodeDown) {
			node_pointer nodeUp = nodeDown->_left;
			nodeDown->_left = nodeUp->_right;
			if (nodeUp->_right) // in case right child NULL
				nodeUp->_right->_parent = nodeDown;
			nodeUp->_right = nodeDown;
			nodeUp->_parent = nodeDown->_parent;
			if (nodeDown->_parent && nodeDown->_parent->_left == nodeDown) // check if root and which child
				nodeDown->_parent->_left = nodeUp;
			else if (nodeDown->_parent)
				nodeDown->_parent->_right = nodeUp;
			nodeDown->_parent = nodeUp;
			if (!nodeUp->_parent) // check if root and set root
				*root = nodeUp;
			
		}
		void	rotateLeft(node_pointer* root, node_pointer nodeDown) {
			node_pointer nodeUp = nodeDown->_right;
			nodeDown->_right = nodeUp->_left;
			if (nodeUp->_left) // in case left child NULL
				nodeUp->_left->_parent = nodeDown;
			nodeUp->_left = nodeDown;
			nodeUp->_parent = nodeDown->_parent;
			if (nodeDown->_parent && nodeDown->_parent->_left == nodeDown) // check if root and which child
				nodeDown->_parent->_left = nodeUp;
			else if (nodeDown->_parent)
				nodeDown->_parent->_right = nodeUp;
			nodeDown->_parent = nodeUp;
			if (!nodeUp->_parent) // check if root and set root
				*root = nodeUp;
		}
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
			return ret;
		}
		void	balance(node_pointer* root, node_pointer move) { // finds imbalance while iterating through tree
			int	balance;
			while (move) {
				balance = getBalance(move);
				// std::cout << "imblance at node: " << move->_data.first << " balance_factor: " << balance << std::endl;
				if (balance > 1 && getBalance(move->_left) > 0) // left_heavy
					rotateRight(root, move);
				else if (balance < -1 && getBalance(move->_right) < 0) // left_heavy
					rotateLeft(root, move);
				else if (balance < -1 && getBalance(move->_right) >= 0) { // right_heavy
					rotateRight(root, move->_right);
					rotateLeft(root, move);
				}
				else if (balance > 1 && getBalance(move->_left) <= 0) { // left_heavy
					rotateLeft(root, move->_left);
					rotateRight(root, move);
				}
				move = move->_parent;
			}
		}
		// ERASE
		bool	deleteRoot(node_pointer del, node_pointer* tmp) {
			if (del->_left == _first && del->_right == _last) { // single root
				_root = new node();
				_root->_left = _first;
				_root->_right = _last;
				_first->_parent = _root;
				_last->_parent = _root;
			}
			else if (del->_left != _first && del->_right == _last) { // left_heavy
				*tmp = del->_parent;
				_root = del->_left;
				del->_left->_parent = 0;
				_last->_parent = del->_left;
				del->_left->_right = _last;
			}
			else if (del->_left == _first && del->_right != _last) { // right_heavy
				*tmp = del->_parent;
				_root = del->_right;
				del->_right->_parent = 0;
				_first->_parent = del->_right;
				del->_right->_left = _first;
			}
			return true;
		}
		bool	deleteLeafNode(node_pointer del, node_pointer* tmp) { // delete single leaf node
			*tmp = del->_parent;
			node_pointer linkToLimit = NULL;
			if (del->_left == _first || del->_right == _last) {
				if (del->_left == _first && del->_right != _last) {
					linkToLimit = _first;
				}
				else
					linkToLimit = _last;
				del->_data.first <= del->_parent->_data.first ?
					_first->_parent = del->_parent : _last->_parent = del->_parent;
			}
			del->_data.first <= del->_parent->_data.first ?
				del->_parent->_left = linkToLimit : del->_parent->_right = linkToLimit;
			return true;
		}
		bool	deleteNodeWithChildren(node_pointer del, node_pointer* tmp, node_pointer set, char side) {
			*tmp = del->_parent;
			del->_data.first <= del->_parent->_data.first ?
				del->_parent->_left = set : del->_parent->_right = set;
			set->_parent = del->_parent;
			if (side == 'L') {
				if (del->_right == _last) {
					_last->_parent = set;
					set->_right = _last;
				}
			}
			else if (side == 'R') {
				if (del->_left == _first) {
					_first->_parent = set;
					set->_left = _first;
				}
			}
			return true;
		}
		bool	deleteNode(node_pointer position, Key key) { // main deleteNode function
			node_pointer tmp = 0;
			node_pointer del = searchNode(position, key);
			if (!del)
				return false;
			if (!del->_parent) { // if del == _root
				if (del->_left == _first || del->_right == _last) // root with 0 or 1 child
					deleteRoot(del, &tmp);
				else { // both _left and _right child
					node_pointer maxNode = _root->getPrev();
					_allocatorPair.destroy(&del->_data);
					_allocatorPair.construct(&del->_data, maxNode->_data);
					return deleteNode(del->_left, maxNode->_data.first);
				}
			}
			else if ((!del->_left || del->_left == _first) && (!del->_right || del->_right == _last)) // LEAF node aka pointing to NULL or Last/First
				deleteLeafNode(del, &tmp);
			else if ((del->_left && del->_left != _first) && (!del->_right || del->_right == _last)) // no leafs but only left child
				deleteNodeWithChildren(del, &tmp, del->_left, 'L');
			else if ((!del->_left || del->_left == _first) && del->_right && del->_right != _last) // no leafs but only _right child
				deleteNodeWithChildren(del, &tmp, del->_right, 'R');
			else { // del node with children on both sides
				node_pointer maxNode = del->getPrev();
				_allocatorPair.destroy(&del->_data);
				_allocatorPair.construct(&del->_data, maxNode->_data);
				return deleteNode(del->_left, maxNode->_data.first);
			}
			balance(&_root, tmp);
			deallocateNode(del);
			return true;
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
			_allocatorPair(alloc),
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
			_allocatorPair(alloc),
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
			_allocatorPair(x._allocatorPair),
			_size(0),
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
			clear();
			_allocatorPair = other._allocatorPair;
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
			return (const_reverse_iterator(_last->_parent));
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
		// ELEMENTS ACCESS
		T& operator[] (const Key& k) { // access value or insert if not excist
			node* tmp = searchNode(_root, k);
			if (tmp)
				return tmp->_data.second;
			return insert(ft::make_pair(k, T())).first->second;
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
				balance(&_root, move);
			}
			else {
				move = insert_right(val, move);
				balance(&_root, move);
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
		void	erase(iterator position) {
			deleteNode(position.get_ptr(), position->first);
				_size -= 1;
		}
		size_t	erase(const Key& key) {
			size_t ret = deleteNode(_root, key);
			_size -= ret;
			return ret;
		}
		template <class InputIterator> 
		void	erase(typename enable_if<is_input_iterator<InputIterator>::value, InputIterator>::type first, InputIterator last) {
			while (first != last) {
				iterator tmp(first);
				++first;
				erase(tmp);
			}
		}
		void	swap(map& x) {
			swap(_root, x._root);
			swap(_last, x._last);
			swap(_size, x._size);
			swap(_comp, x._comp);
			swap(_allocatorPair, x._allocatorPair);
			swap(_allocatorNode, x._allocatorNode);
		}
		void	clear() {
			erase(begin(), end());
		}
		// OBSERVERS
		Compare	key_comp() const {
			return _comp;
		}
		value_compare	value_comp() const {
			return value_compare(_comp);
		}
		// OPERATIONS
		iterator	find(const Key& k) {
			node_pointer tmp = searchNode(_root, k);

			if (tmp)
				return iterator(tmp);
			return end();
		}
		const_iterator	find(const Key& k) const {
			node_pointer tmp = searchNode(_root, k);

			if (tmp)
				return const_iterator(tmp);
			return end();
		}
		size_t	count(const Key& k) const {
			node_pointer tmp = searchNode(_root, k);
			return tmp ? true: false;
		}
		iterator	lower_bound(const Key& k) {
			iterator it = begin();

			for (; it != end(); ++it)
				if (!_comp(it->first, k))
					break;
			return it; 
		}
		const_iterator	lower_bound(const Key& k) const {
			const_iterator it = begin();

			for (; it != end(); ++it)
				if (!_comp(it->first, k))
					break;
			return it; 
		}
		iterator	upper_bound(const Key& k) {
			iterator it = begin();

			for (; it != end(); ++it)
				if (_comp(k, it->first))
					break;
			return it; 
		}
		const_iterator	upper_bound(const Key& k) const {
			const_iterator it = begin();

			for (; it != end(); ++it)
				if (_comp(k, it->first))
					break;
			return it; 
		}
		pair<const_iterator, const_iterator>	equal_range(const Key& k) const {
			const_iterator it = upper_bound(k);

			if (it != begin()) {
				--it;
				if (_comp(it->first, k) || _comp(k, it->first))
					++it;
			}
			const_iterator next(it);
			if (it != end())
				++next;
			return make_pair<const_iterator, const_iterator>(it, next);
		}
		pair<iterator, iterator>	equal_range(const Key& k) {
			iterator it = upper_bound(k);

			if (it != begin()) {
				--it;
				if (_comp(it->first, k) || _comp(k, it->first))
					++it;
			}
			iterator next(it);
			if (it != end())
				++next;
			return make_pair<iterator, iterator>(it, next);
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