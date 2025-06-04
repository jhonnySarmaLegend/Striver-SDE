//Question Link --> https://leetcode.com/problems/maximum-depth-of-binary-tree/description/
//T.C.=O(N) traverse all nodes
//S.C.=O(N) auxillary space in call stack
    int maxDepth(TreeNode* root) {
        if(root==NULL)return 0;

        int lh=maxDepth(root->left);
        int rh=maxDepth(root->right);

        return 1+max(lh,rh);
    }
