// ceil(x) > = x  --> smallest value > x

//ITERATIVE
int ceilInBST(TreeNode *root,int key){
 int ceil=-1;
  while(root){
    if(root->val == key){
     ceil=root->val;
     return ceil;
    }
     else if(root->val > key){
     ceil=root->val;
     root=root->left;
    }
    else{
     root=root->right;
    }
  }
 return ceil;
}


//RECURSIVE

    // Function to find the smallest value larger than the key (Successor)
    // Pass 'suc' by reference so it can be updated
    void findLarge(Node* root, int key, Node*& suc) {
        if (root == nullptr) return;

        if (root->data > key) {
            suc = root; // Update successor
            findLarge(root->left, key, suc); // Look for a smaller successor in the left subtree
        } else {
            // If current node's data <= key, move right to find larger values
            findLarge(root->right, key, suc);
        }
    }
