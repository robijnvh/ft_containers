            int balanceOfSubtrees(Node* node)
            {
                if (!node)
                    return 0;
                return heightTree(node->left, 1) - heightTree(node->right, 1);
            }

            /**
            *   Does a right rotation between a node and his left child. The left child will go up
            *   and take the position of this node; and this node will become the right child of the node
            *   going up.
            *
            *   @param root             First node of the tree.
            *   @param nodeGoingDown    Rotation will occured around this node.
            */
            void rotateRight(Node** root, Node* nodeGoingDown)
            {
                //   P (nodeGoingUp) is going up and will replace Q (nodeGoingDown)
                //
                //
                //               Q                                 P              |
                //              / \     RIGHT ROTATION            / \             |
                //             P   C  ------------------->>>     A   Q            |
                //            / \                                   / \           |
                //           A   B                                 B   C          |

                Node* nodeGoingUp = nodeGoingDown->left;
                
                // Left Q' son become right P' son
                nodeGoingDown->left = nodeGoingUp->right;
                
                // Case right son is NULL to prevent segfault
                if (nodeGoingUp->right)
                    nodeGoingUp->right->parent = nodeGoingDown;
                
                // rigth P' son is Q
                nodeGoingUp->right = nodeGoingDown;
                
                // Parent P = Parent Q
                nodeGoingUp->parent = nodeGoingDown->parent;
                
                // Determinating if Q has a parent (if not, Q is root) and if it's the case,
                // determinating if it's left son or right son. Then updating Q's parent with
                // his new son, P node
                if (nodeGoingDown->parent && nodeGoingDown->parent->left == nodeGoingDown)
                    nodeGoingDown->parent->left = nodeGoingUp;
                else if (nodeGoingDown->parent)
                    nodeGoingDown->parent->right = nodeGoingUp;
                
                // Parent of Q is now P
                nodeGoingDown->parent = nodeGoingUp;

                // Updating root node if the rotation occured on root
                if (!nodeGoingUp->parent)
                    *root = nodeGoingUp;
            }

            /**
            *   Does a left rotation between a node and his right child. The right child will go up
            *   and take the position of this node; and this node will become the left child of the node
            *   going up.
            *
            *   @param root             First node of the tree.
            *   @param nodeGoingDown    Rotation will occured around this node.
            */
            void rotateLeft(Node** root, Node* nodeGoingDown)
            {
                //   Q (nodeGoingUp) is going up and will replace P (nodeGoingDown)
                //
                //
                //               Q                                 P              |
                //              / \          LEFT ROTATION        / \             |
                //             P   C    <<<-------------------   A   Q            |
                //            / \                                   / \           |
                //           A   B                                 B   C          |

                Node* nodeGoingUp = nodeGoingDown->right;
                
                // Right P' son become left Q' son
                nodeGoingDown->right = nodeGoingUp->left;

                // Case Q left son is NULL to prevent segfault
                if (nodeGoingUp->left)
                    nodeGoingUp->left->parent = nodeGoingDown;
                
                // Left Q' son is now P
                nodeGoingUp->left = nodeGoingDown;
                
                // Parent Q = Parent P
                nodeGoingUp->parent = nodeGoingDown->parent;
                
                // Determinating if P has a parent (if not, P is root) and if it's the case,
                // determinating if it's left son or right son. Then updating P's parent with
                // his new son, Q node
                if (nodeGoingDown->parent && nodeGoingDown->parent->left == nodeGoingDown)
                    nodeGoingDown->parent->left = nodeGoingUp;
                else if (nodeGoingDown->parent)
                    nodeGoingDown->parent->right = nodeGoingUp;

                // Parent of P is now Q
                nodeGoingDown->parent = nodeGoingUp;

                // Updating root node if the rotation occured on root
                if (!nodeGoingUp->parent)
                    *root = nodeGoingUp;
            }

            /**
            *   Starts from a node in the AVL tree, and will check for this node and all the parent's node
            *   until root if their balance (height of left and right subtree) is correct. If not, a rotation
            *   (left or right) around the unbalanced node will occured in order to restore tree's balance.
            *
            *   @param root First node of the tree.
            *   @param node Will check the balance's node, and will check every parent until reaching root.
            */
            void balanceTheTree(Node** root, Node* node)
            {
                // Checking balance of subtrees every parents of this node until we 
                // reach root node          
                while (node)
                {
                    int balance;
                    
                    // Right right case (right subtree is deeper, and right right subtree aswell)
                    if ((balance = balanceOfSubtrees(node)) < -1 && balanceOfSubtrees(node->right) < 0)
                        rotateLeft(root, node);

                    // Right left case (if balance of right node == 0, no difference between right 
                    // right case and and right left case)
                    else if (balance < -1 && balanceOfSubtrees(node->right) >= 0)
                    {
                        rotateRight(root, node->right);
                        rotateLeft(root, node);
                    }
                    
                    // Left left case (opposite of right right case)
                    else if (balance > 1 && balanceOfSubtrees(node->left) > 0)
                        rotateRight(root, node);

                    // Left right case (opposite of right left case)
                    else if (balance > 1 && balanceOfSubtrees(node->left) <= 0)
                    {
                        rotateLeft(root, node->left);
                        rotateRight(root, node);
                    }
                    node = node->parent;
                }
            }