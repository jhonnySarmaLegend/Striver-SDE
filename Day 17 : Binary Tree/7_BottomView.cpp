//Question Link --> https://www.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1

/*
To imagine the Binary Tree from above, we visualise vertical lines passing through the tree. Each vertical 
line represents a unique vertical position. Nodes to the right of the tree’s centre are assigned positive 
vertical indexes. As we move to the right, the vertical index increases. Nodes to the left of the tree’s 
centre are assigned negative vertical indexes. As we move to the left, the vertical index decreases
*/

//LAST NODE OF EVERY LINE - LEVEL ORDER TRAVERSAL

vector<int> bottomView(Node* root){
        // Vector to store the result
        vector<int> ans;
        
        // Check if the tree is empty
        if(root == NULL){
            return ans;
        }
        
        // Map to store the bottom view nodes
        // based on their vertical positions
        map<int, int> mpp;
        
        // Queue for BFS traversal, each
        // element is a pair containing node
        // and its vertical position
        queue<pair<Node*, int>> q;
        
        // Push the root node with its vertical
        // position (0) into the queue
        q.push({root, 0});
        
        // BFS traversal --> Level order traversal
        while(!q.empty()){
            // Retrieve the node and its vertical
            // position from the front of the queue
            auto it = q.front();
            q.pop();
            Node* node = it.first;
            int line = it.second;
            
            // Update the map with the node's data
            // for the current vertical position
            mpp[line] = node->data;
            
            // Process left child
            if(node->left != NULL){
                // Push the left child with a decreased
                // vertical position into the queue
                q.push({node->left, line - 1});
            }
            
            // Process right child
            if(node->right != NULL){
                // Push the right child with an increased
                // vertical position into the queue
                q.push({node->right, line + 1});
            }
        }
        
        // Transfer values from the
        // map to the result vector
        for(auto it : mpp){
            ans.push_back(it.second);
        }
        
        return ans;
    }
