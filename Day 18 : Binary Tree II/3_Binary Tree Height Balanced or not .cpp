//Question Link --> https://leetcode.com/problems/balanced-binary-tree/description/
//Balnced Binary Tree --> abs(height(leftsubtree)-height(rightsubtree))<=1

//BRUTE FORCE
/*
Complexity Analysis
Time Complexity: O(N2) where N is the number of nodes in the Binary Tree.This arises
as we calculate the height of each node and to calculate the height for each node, we
traverse the tree which is proportional to the number of nodes. Since this calculation
is performed for each node in the tree, the complexity becomes: O(N x N) ~ O(N2).

Space Complexity : O(1) as no additional data structures or memory is allocated.O(H): 
Recursive Stack Space is used to calculate the height of the tree at each node which is 
proportional to the height of the tree.The recursive nature of the getHeight function, 
which incurs space on the call stack for each recursive call until it reaches the leaf 
nodes or the height of the tree.
*/

 // Function to check if a binary tree is balanced
    bool isBalanced(Node* root) {
        // If the tree is empty, it's balanced
        if (root == nullptr) {
            return true;
        }

        // Calculate the height of left and right subtrees
        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);

        // Check if the absolute difference in heights
        // of left and right subtrees is <= 1
        if (abs(leftHeight - rightHeight) <= 1 &&
            isBalanced(root->left) &&
            isBalanced(root->right)) {
            return true;
        }

        // If any condition fails, the tree is unbalanced
        return false;
    }

    // Function to calculate the height of a subtree
    int getHeight(Node* root) {
        // Base case: if the current node is NULL,
        // return 0 (height of an empty tree)
        if (root == nullptr) {
            return 0;
        }

        // Recursively calculate the height
        // of left and right subtrees
        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);

        // Return the maximum height of left and right subtrees
        // plus 1 (to account for the current node)
        return max(leftHeight, rightHeight) + 1;
    }



     //Optimized
// T.C.= O(N), S.C.=O(N)

        int height(TreeNode* node)
    {
        if(node==NULL)return 0;
    
        int lh=height(node->left);
        if(lh==-1 )return -1;
        
        int rh=height(node->right);
        if(rh==-1 )return -1;
        
        if(abs(lh-rh)>1)return -1;
        
        return 1+(max(lh,rh));  
    }
    bool isBalanced(TreeNode* root) {
        return height(root)!=-1 ; 
    //   isBalanced FUNCTION WILL RETURN TRUE IF THE HEIGHT EXIST AND FALSE IF IT IS -1   
    }
