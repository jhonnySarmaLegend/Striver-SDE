//BRUTE

// inorder --> LNR == sorted ascending
// reverse inorder --> RNL == sorted descending
class Solution {

public:

    // Helper function for inorder traversal to store elements in a vector

    void inorder_traverse_and_store(TreeNode* node, std::vector<int>& elements) {

        // Base case
        if (node==NULL)return;
        
        // Traverse right subtree
        inorder_traverse_and_store(node->right, elements);

         // Visit current node: Add node's value to the vector
        elements.push_back(node->val);

         // Traverse left subtree
        inorder_traverse_and_store(node->left, elements);

    }

    int kthLargest(TreeNode* root, int k) {

        vector<int> reverse_sorted_elements; // Vector to store inorder traversal

        // Perform inorder traversal and populate the vector
        inorder_traverse_and_store(root, reverse_sorted_elements);

        // The k-th largest element will be at index k-1 in the reverse sorted vector
        // Since k is 1-indexed and vector is 0-indexed
        return reverse_sorted_elements[k - 1];

    }

};

