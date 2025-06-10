/*
A binary tree is symmetric if it is a mirror image of itself around its center.

Question Link --> https://leetcode.com/problems/symmetric-tree/description/
*/


  bool check(TreeNode* r1, TreeNode* r2){
        // Base case: If either r1 or r2 is NULL, return true only if both are NULL.
        // This handles the cases where one or both subtrees are empty.
        if(r1==NULL || r2==NULL) return r1==r2;
    
        // If the values of the nodes are different, the subtrees are not symmetric.
        if(r1->val != r2->val) return false;
    
        // Recursively check if the left subtree of r1 is symmetric to the right subtree of r2
        // AND if the right subtree of r1 is symmetric to the left subtree of r2.
        return check(r1->left,r2->right) && check(r1->right,r2->left);
    }

    bool isSymmetric(TreeNode* root) {
         // Base case: An empty tree is considered symmetric.
        if(root==NULL) return true;
      
        // Call the helper function to check if the left and right subtrees are symmetric.
        return check(root->left,root->right);
    }
