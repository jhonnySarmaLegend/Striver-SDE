/*
Approach: The problem can be solved using only one stack. The idea is to mark each node of the
binary tree by assigning a value, called status code with each node such that value 1 represents
that the node is currently visiting in preorder traversal, value 2 represents the nodes is currently
visiting in inorder traversal and value 3 represents the node is visiting in the postorder traversal.

Initialize a stack < pair < Node*, int>> say S.
Push the root node in the stack with status as 1, i.e {root, 1}.

Initialize three vectors of integers say preorder, inorder, and postorder.

Traverse the stack until the stack is empty and check for the following conditions:
If the status of the top node of the stack is 1 then update the status of the top node of the stack to 2 
and push the top node in the vector preorder and insert the left child of the top node if it is not NULL in the stack S.
If the status of the top node of the stack is 2 then update the status of the top node of the stack to 3
and push the top node in the vector inorder and insert the right child of the top node if it is not NULL in the stack S.
If the status of the top node of the stack is 3 then push the top node in vector postorder and then pop the top element.
Finally, print vectors preorder, inorder, and postorder.
*/


// Function to get the Preorder,
// Inorder and Postorder traversal
// Of Binary Tree in One traversal
vector<vector<int>> preInPostTraversal(Node* root) {
    // Vectors to store traversals
    vector<int> pre, in, post;

    // If the tree is empty,
    // return empty traversals
    if (root == NULL) {
        return {};
    }

    // Stack to maintain nodes
    // and their traversal state
    stack<pair<Node*, int>> st;

    // Start with the root node
    // and state 1 (preorder)
    st.push({root, 1});

    while (!st.empty()) {
        auto it = st.top();
        st.pop();

        // this is part of pre
        if (it.second == 1) {
            // Store the node's data
            // in the preorder traversal
            pre.push_back(it.first->data);
            // Move to state 2
            // (inorder) for this node
            it.second = 2;
            // Push the updated state
            // back onto the stack
            st.push(it); 

            // Push left child onto
            // the stack for processing
            if (it.first->left != NULL) {
                st.push({it.first->left, 1});
            }
        }

        // this is a part of in
        else if (it.second == 2) {
            // Store the node's data
            // in the inorder traversal
            in.push_back(it.first->data);
            // Move to state 3
            // (postorder) for this node
            it.second = 3;
            // Push the updated state
            // back onto the stack
            st.push(it); 

            // Push right child onto
            // the stack for processing
            if (it.first->right != NULL) {
                st.push({it.first->right, 1});
            }
        }

        // this is part of post
        else {
            // Store the node's data
            // in the postorder traversal
            post.push_back(it.first->data);
        }
    }

    // Returning the traversals
    vector<vector<int>> result;
    result.push_back(pre);
    result.push_back(in);
    result.push_back(post);
    return result;
}
