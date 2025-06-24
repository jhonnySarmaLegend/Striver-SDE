//Question Link --> https://leetcode.com/problems/validate-binary-search-tree/description/

//Property - Inorder traversal of BST is sorted
// T.C. = O(N) , S.C. = O(N)

bool isValidBST(TreeNode* root) {
    vector<int> inorderValues;
    inorderTraversal(root, inorderValues);
    
    // Check if the inorder values are sorted
    for (int i = 1; i < inorderValues.size(); ++i) {
        if (inorderValues[i] <= inorderValues[i - 1]) {
            return false;
        }
    }
    
    return true;
}

void inorderTraversal(TreeNode* node, vector<int>& inorderValues) {
    if (node == nullptr) {
        return;
    }
    
    // Traverse left subtree
    inorderTraversal(node->left, inorderValues);
    
    // Visit the node
    inorderValues.push_back(node->val);
    
    // Traverse right subtree
    inorderTraversal(node->right, inorderValues);
}


// Approach 2 - using the range for parent and child  nodes
// T.C.= O(N) , S.C.=O(1)
bool solve(TreeNode *root, long long rStart, long long rEnd) {
    if (root == NULL) {
        return true;  // Base case for recursion
    }

    // Recursive call for the left and right subtrees with updated bounds
    bool ans1 = solve(root->left, rStart, root->val);
    bool ans2 = solve(root->right, root->val, rEnd);
    
    // Check the current node's value against the bounds
    if (root->val > rStart && root->val < rEnd) {
        return ans1 && ans2; // Both children must also be valid
    }
    return false; // The current node value is out of bounds
}

bool isValidBST(TreeNode* root) {
    long long rStart = LLONG_MIN;  // Start boundary (range)
    long long rEnd = LLONG_MAX;    // End boundary (range)
    return solve(root, rStart, rEnd); // Start the recursion
}
