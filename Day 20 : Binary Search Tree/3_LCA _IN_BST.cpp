//Question Link --> https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


// RECURSIVE
//T.C.= O(N) , S.C.=O(N) (recursion stack space)

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Get the values for easier comparison
        int root_val = root->val;
        int p_val = p->val;
        int q_val = q->val;
        // If both p and q are in the left subtree
        if (p_val < root_val && q_val < root_val) {
            return lowestCommonAncestor(root->left, p, q);
        }
        // If both p and q are in the right subtree
        else if (p_val > root_val && q_val > root_val) {
            return lowestCommonAncestor(root->right, p, q);
        }
        // If the current root is between p and q (meaning p is in one subtree and q in the other),
        // or if the current root is p or q itself, then the current root is the LCA.
        else {
            return root;
        }
    }
};



// ITERATIVE   --> from root --> 1st vale v , such that     p->data  < val < q->data
//T.C.= O(N) , S.C.=O(1)
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            while(root) {
            if(root->val > p->val && root->val > q->val) {
                root = root->left;
            }
            else if(root->val <p->val && root->val < q->val) {
                root = root->right;
            } else {
                return root;
            }
        }

        return NULL;
    }
