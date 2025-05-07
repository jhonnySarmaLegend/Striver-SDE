
/*
Time Complexity: O(log2N) where N is the number of nodes in the Binary Tree. This complexity arises as
we travel along the height of the Binary Tree. For a balanced binary tree, the height is log2N but in
the worst case when the tree is skewed, the complexity becomes O(N).

Space Complexity : O(log2N) where N is the number of nodes in the Binary Tree. This complexity arises
because we store the leftmost and rightmost nodes in an additional vector. The size of this result vector
is proportional to the height of the Binary Tree which will be log2N when the tree is balanced and O(N)
in the worst case of a skewed tree.

O(H): Recursive Stack Space is used to calculate the height of the tree at each node which is proportional 
to the height of the tree.
The recursive nature of the getHeight function, which incurs space on the call stack for each recursive 
call until it reaches the leaf nodes or the height of the tree.
*/

//RIGHT VIEW
   // Function to return the Right view of the binary tree
    vector<int> rightsideView(Node* root){
        // Vector to store the result
        vector<int> res;
        
        // Call the recursive function
        // to populate the right-side view
        recursionRight(root, 0, res);
        
        return res;
    }

void recursionRight(Node* root, int level, vector<int> &res){
        // Check if the current node is NULL
        if(root == NULL){
            return;
        }
        
        // Check if the size of the result vector
        // is equal to the current level
        if(res.size() == level){
            // If equal, add the value of the
            // current node to the result vector
            res.push_back(root->data);
            
            // Recursively call the function for the
            // right child with an increased level
            recursionRight(root->right, level + 1, res);
            
            // Recursively call the function for the
            // left child with an increased level
            recursionRight(root->left, level + 1, res);
        }
}


//LEFT VIEW
 // Function to return the Left view of the binary tree
    vector<int> leftsideView(Node* root){
        // Vector to store the result
        vector<int> res;
        
        // Call the recursive function
        // to populate the left-side view
        recursionLeft(root, 0, res);
        
        return res;
    }

    void recursionLeft(Node* root, int level, vector<int>& res){
        // Check if the current node is NULL
        if(root == NULL){
            return;
        }
        
        // Check if the size of the result vector
        // is equal to the current level
        if(res.size() == level){
            // If equal, add the value of the
            // current node to the result vector
            res.push_back(root->data);
        }
        
        // Recursively call the function for the
        // left child with an increased level
        recursionLeft(root->left, level + 1, res);
        
        // Recursively call the function for the
        // right child with an increased level
        recursionLeft(root->right, level + 1, res);
    }
