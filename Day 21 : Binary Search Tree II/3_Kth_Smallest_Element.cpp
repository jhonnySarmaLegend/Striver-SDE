//Question Link --> https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/

//Brute 
// T.C. =O(N) , S.C.=O(N)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // Helper function for inorder traversal to store elements in a vector
    void inorder_traverse_and_store(TreeNode* node, std::vector<int>& elements) {
        // Base case
        if (node==NULL) {
            return;
        }

        // Traverse left subtree
        inorder_traverse_and_store(node->left, elements);

        // Visit current node: Add node's value to the vector
        elements.push_back(node->val);

        // Traverse right subtree
        inorder_traverse_and_store(node->right, elements);
    }

    int kthSmallest(TreeNode* root, int k) {
        vector<int> sorted_elements; // Vector to store inorder traversal

        // Perform inorder traversal and populate the vector
        inorder_traverse_and_store(root, sorted_elements);

        // The k-th smallest element will be at index k-1 in the sorted vector
        // Since k is 1-indexed and vector is 0-indexed
        return sorted_elements[k - 1];
    }
};


//OPTIMAL
// T.C. = O(N), S.C.=O(H) --> recursion stack space
  
class Solution {
public:
void helper(TreeNode* root,int k,int& target,int& ans){
    if(root==nullptr){
        return ;
    }
    helper(root->left,k,target,ans);

    target=target+1;
    if(target==k){
        ans=root->val;
        return;
    }

    helper(root->right,k,target,ans);
    


}
    int kthSmallest(TreeNode* root, int k) {
        int target=0;
        int ans=-1;
        helper(root,k,target,ans);//inorder
        return ans;
    }
};
