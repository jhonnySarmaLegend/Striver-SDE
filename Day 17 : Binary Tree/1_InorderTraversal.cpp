/*
  Question Link --> https://leetcode.com/problems/binary-tree-inorder-traversal/description/
*/

class Solution {
public:
    void Inorder(TreeNode* root, vector<int> &ans){
        if(root==NULL)return;

         Inorder(root->left,ans);
         ans.push_back(root->val);
         Inorder(root->right,ans);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        Inorder(root,ans);
        return ans;
    }
};

/*
  Time Complexity: O(N) where N is the number of nodes in the binary tree as each node of the binary tree is visited exactly once.

Space Complexity: O(N) where N is the number of nodes in the binary tree. This is because the recursive stack uses an auxiliary space
which can potentially hold all nodes in the tree when dealing with a skewed tree (all nodes have only one child), consuming space 
proportional to the number of nodes.In the average case or for a balanced tree, the maximum number of nodes that could be in the stack
at any given time would be roughly the height of the tree hence O(log2N).
*/
