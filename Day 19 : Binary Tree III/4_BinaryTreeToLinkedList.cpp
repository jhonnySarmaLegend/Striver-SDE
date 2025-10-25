// Question --> https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/
//T.C. = O(N0, S.C.=O(1)
  void flatten(TreeNode* root)
{
 TreeNode* curr = root;
    while (curr) {
        if (curr->left) {
            TreeNode* pre = curr->left;
            while (pre->right) {
                pre = pre->right;
            }
            pre->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
        }
        curr = curr->right;
    }
}

//COMMENTED CODE

//INplace , no new nodes should be created
   void flatten(TreeNode* root) {
        // Initialize a pointer'curr' to the root of the tree
        TreeNode* curr = root;

        // Iterate until 'curr'becomes NULL
        while (curr) {
           1) // Check if the current node has a left child
            if (curr->left) {
                // If yes, find the rightmost node in the left subtree
                TreeNode* pre = curr->left;
                while (pre->right) {
                    pre = pre->right;
                }

                2)// Connect the rightmost node in the left subtree to the current node's right child
                pre->right = curr->right;

                3)// Move the entire left subtree to the right child of the current node
                curr->right = curr->left;

                4)// Set the left child of the current node to NULL
                curr->left = NULL;
            }
             //#REPEAT
            // Move to the next node on the right side
            curr = curr->right;
        }
    }
