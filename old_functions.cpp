
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

// BALANCE
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
				if (balance < -1 || balance > 1) {
					std::cout << "imblance at node: " << move->_data.first << " balance_factor: " << balance << std::endl;
					if (balance > 1 && getBalance(move->_left) > 0) {
						std::cout << "left_heavy" << std::endl;
						// rotateRightDouble(move->_left);
						rotateRight(_root, move);
					}
					else if (balance < -1 && getBalance(move->_right) < 0) {
						std::cout << "right_heavy" << std::endl;
						// rotateLeftDouble(move->_right);
						rotateLeft(_root, move);
					}
					else if (balance < -1 && getBalance(move->_right) >= 0) {
						std::cout << "right_heavy" << std::endl;
						// rotateRight(move->_right);
						// rotateLeftDouble(move->_right);
						rotateRight(_root, move->_right);
						rotateLeft(_root, move);
					}
					else if (balance > 1 && getBalance(move->_left) <= 0) {
						std::cout << "left_heavy" << std::endl;
						// rotateLeft(move->_left);
						// rotateRightDouble(move->_left);
						rotateLeft(_root, move->_left);
						rotateRight(_root, move);
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