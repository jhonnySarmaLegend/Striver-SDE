//
// floor(x) <= x --> greatest value < x



//ITERATIVE APPROACH
int floorInBST(TreeNode *root,int key){
 int floor=-1;
  while(root){
    if(root->val == key){
     floor=root->val;
     return floor;
    }
     else if(root->val < key){
     floor=root->val;
     root=root->right;
    }
    else{
     root=root->left;
    }
  }
 return floor;
}


//  RECURSIVE APPROACH
// Function to find the largest value smaller than the key (Predecessor)
    // Pass 'pre' by reference so it can be updated
    void findSmall(Node* root, int key, Node*& pre) {
        if (root == nullptr) return;

        if (root->data < key) {
            pre = root; // Update predecessor
            findSmall(root->right, key, pre); // Look for a larger predecessor in the right subtree
        } else {
            // If current node's data >= key, move left to find smaller values
            findSmall(root->left, key, pre);
        }
    }
