 // in B.T. nodes at each level is in power of 2
 // do level order and check at each level if size not in power of 2 at that level
    bool PerfectBinaryTree(TreeNode* root) {
           if (!root) {
        return true; // An empty tree is balanced
    }

   queue<TreeNode*> q;
    q.push(root);
    int level = 0;

    while (!q.empty()) {
        int levelSize = q.size();
        // Check if the number of nodes at this level is a power of 2
        if (levelSize != (1 << level)) { // equivalent to 2^level
            return false;
        }

        for (int i = 0; i < levelSize; ++i) {
            TreeNode* node = q.front();
            q.pop();
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        level++;
    }
    
    return true;
    }
    /*  perfect Binary Tree all levels filled completely 
                1
            /      \
           2        3
          /  \      /  \
        4     5     6   7
    */
