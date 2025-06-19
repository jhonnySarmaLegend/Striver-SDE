//Question Link --> https://leetcode.com/problems/search-in-a-binary-search-tree/description/


// 1. ITERATIVE
 TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* current = root;
    while (current!=NULL) {
        if (current->val == val) {
            return current; // Found the node
        } else if (val < current->val) {
            current = current->left; // Move to the left child
        } else {
            current = current->right; // Move to the right child
        }
    }
    return nullptr; // Node with the specified value not found

    }


//2. RECURSIVE
    TreeNode* searchBST(TreeNode* root, int val) {
          
        //base condition
        if(root == NULL)return NULL;
        
        //condn 1
        if(root -> val == val) return root;
        
        //condn 2
        else if(val < root -> val)return searchBST(root -> left, val);

        //condn 3
        else return searchBST(root -> right, val);
    }
