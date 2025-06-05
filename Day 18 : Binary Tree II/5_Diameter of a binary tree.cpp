//Question Link --> https://leetcode.com/problems/diameter-of-binary-tree/description/

//USING GLOBAL VARIABLE
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
    int maxi=0; // Global Variable
    int findMax(TreeNode* node) {
        if (node == NULL) return 0; // Base case: return 0 for null nodes

        int lh = findMax(node->left);// Recurse on the left and right children
        int rh = findMax(node->right);
       
        maxi = max(maxi, lh + rh); // Update the maximum diameter found
        
        return 1 + max(lh, rh); // Height of the current node  // Return the height of the node
    }
    int diameterOfBinaryTree(TreeNode* root) {
        findMax(root);
        return maxi;
    }
};



//USING LOCAL VARIABLE PASSED IN THE FUNCTION
    int findMax(TreeNode* node, int &maxi) {
        if (node == NULL) return 0; // Base case: return 0 for null nodes

        int lh = findMax(node->left,maxi);// Recurse on the left and right children
        int rh = findMax(node->right,maxi);
       
        maxi = max(maxi, lh + rh); // Update the maximum diameter found
        
        return 1 + max(lh, rh); // Height of the current node  // Return the height of the node
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi=0; // local Variable
        findMax(root,maxi);
        return maxi;
    }
