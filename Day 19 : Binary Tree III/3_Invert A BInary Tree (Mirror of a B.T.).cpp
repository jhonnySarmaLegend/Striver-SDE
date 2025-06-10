//Question Link --> https://leetcode.com/problems/invert-binary-tree/description/

// visit node & swap two childrens
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL)return NULL;
        
        //swap child nodes
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        
        //recursively do same for left & right subtree
        invertTree(root->left);
        invertTree(root->right);
        
        //finally return the answer
        return root;   
    }
