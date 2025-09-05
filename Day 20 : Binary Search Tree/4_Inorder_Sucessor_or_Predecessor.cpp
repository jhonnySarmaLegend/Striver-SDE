// inorder of bst = sorted
// 1,2,3,4,5,6,7,8 
// Inorder_Predecessor of 5 is 4
// Inorder_Sucessor of 5 is 6


// Desired Code
class Solution {
public:
    void findSmall(Node* root, int key, Node*& pre) {
        if (root == nullptr) return;
        if (root->data < key) {
            pre = root;
            findSmall(root->right, key, pre);
        } else {
            findSmall(root->left, key, pre);
        }
    }

    void findLarge(Node* root, int key, Node*& suc) {
        if (root == nullptr) return;
        if (root->data > key) {
            suc = root;
            findLarge(root->left, key, suc);
        } else {
            findLarge(root->right, key, suc);
        }
    }

    vector<Node*> findPreSuc(Node* root, int key) {
        Node* pre = nullptr;
        Node* suc = nullptr;
        findSmall(root, key, pre);
        findLarge(root, key, suc);
        return {pre, suc};
    }
};






//Brute force --> store inorder of BST in array and return successor(1 value >key>) or predecessor(last value <key>) according to the question
// T.C. = O(2N) inorder+loop , S.C. = O(N) 
/* BST Node
class Node
{
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
  public:
  void inOrderTraversal(Node* root, vector<Node*>& nodes) {
    if (root == nullptr) {
        return;
    }
    inOrderTraversal(root->left, nodes);
    nodes.push_back(root); // Store the actual Node* pointer
    inOrderTraversal(root->right, nodes);
}
 vector<Node*> findPreSuc(Node* root, int key) {
  vector<Node*> inorder_nodes;
  inOrderTraversal(root, inorder_nodes);
  Node* pre = nullptr;
  Node* suc = nullptr;
  int key_index = -1; // To store the index of the key if found
    
        for (int i = 0; i < inorder_nodes.size(); ++i) {
        if (inorder_nodes[i]->data < key) {
            // This node is smaller than key, so it's a candidate for predecessor
            pre = inorder_nodes[i];
        } else if (inorder_nodes[i]->data > key) {
            // This node is greater than key, so it's a candidate for successor
            // Since we're iterating in order, the first one we find is the smallest such value.
            suc = inorder_nodes[i];
            break; // Found the successor (or the first element > key), can stop
        } else { // inorder_nodes[i]->data == key
            // Key is found.
            // Predecessor is the element before it (if exists)
            if (i > 0) {
                pre = inorder_nodes[i - 1];
            }
            // Successor is the element after it (if exists)
            if (i < inorder_nodes.size() - 1) {
                suc = inorder_nodes[i + 1];
            }
            break; // Key found and pre/suc set, can stop
        }
    }
    vector<Node*> result;
    result.push_back(pre);
    result.push_back(suc);
    return result;
    }
};


//OPTIMIZED --> T.C.=O(H) , S.C.=O(1) --> With comments
// successor > key so on right subtree   && predecessor < key so on left subtree
/*
Follow the steps below to solve the problem:

If root is NULL then return.
if key is found then
If its left subtree is not null, then predecessor will be the right most child of left subtree or left child itself.
If its right subtree is not null Then The successor will be the left most child of right subtree or right child itself.
If key is smaller than root node set the successor as root search recursively into left subtree.
Otherwise set the predecessor as root search recursively into right subtree.
*/

/* BST Node

class Node
{
   public:
    int data;
    Node *left;
    Node *right;
    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
public:
    // Function to find the largest value smaller than the key (Predecessor)
    // Pass 'pre' by reference so it can be updated
    void findSmall(Node* root, int key, Node*& pre) {
        if (root == nullptr) return;

        if (root->data < key) {
            pre = root; // Update predecessor
            findSmall(root->right, key, pre); // Look for a larger predecessor in the right subtree
        } else {
            // If current node's data >= key, move left to find smaller values
            findSmall(root->left, key, pre);
        }
    }

    // Function to find the smallest value larger than the key (Successor)
    // Pass 'suc' by reference so it can be updated
    void findLarge(Node* root, int key, Node*& suc) {
        if (root == nullptr) return;

        if (root->data > key) {
            suc = root; // Update successor
            findLarge(root->left, key, suc); // Look for a smaller successor in the left subtree
        } else {
            // If current node's data <= key, move right to find larger values
            findLarge(root->right, key, suc);
        }
    }

    // Main function to find predecessor and successor
    vector<Node*> findPreSuc(Node* root, int key) {
        Node* pre = nullptr; // Local variable for predecessor
        Node* suc = nullptr; // Local variable for successor

        findSmall(root, key, pre); // Pass 'pre' by reference
        findLarge(root, key, suc); // Pass 'suc' by reference

        return {pre, suc}; // Return both as a vector
    }
};
