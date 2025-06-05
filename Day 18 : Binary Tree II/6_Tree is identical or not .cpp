//Question Link --> https://leetcode.com/problems/same-tree/description/
//Any traversal --> pre, in, post or level order traversal of both tress will have same value

    bool isSameTree(TreeNode* p, TreeNode* q) {
        // If both nodes are NULL,they are identical
        if(p == NULL && q == NULL){
            return true;
        }
        // If only one of the nodes is NULL, they are not identical
        if( p== NULL || q==NULL){
            return false;
        }
        // Check if the current nodes have the same data value
        // and recursively check their left and right subtrees
        return ((p->val == q->val)
            && isSameTree(p->left, q->left)
                && isSameTree(p->right, q->right));
    }


/*
Time Complexity: O(N+M) where N is the number of nodes in the first Binary Tree and M is the
number of nodes in the second Binary Tree. This complexity arises from visiting each node of the
two binary nodes during their comparison.

Space Complexity: O(1) as no additional space or data structures is created that is proportiona
l to the input size of the tree. O(H) Recursive Stack Auxiliary Space : The recursion stack space is
determined by the maximum depth of the recursion, which is the height of the binary tree denoted as H. 
In the balanced case it is log2N and in the worst case (its N).
*/
