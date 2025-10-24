//Question Link --> https://www.geeksforgeeks.org/problems/top-view-of-binary-tree/1

// First Node of every LINE -- Level order traversal

    // top view of the binary tree


vector<int> topView(Node* root){
        vector<int> ans;
        if(root == NULL)return ans;
        
        map<int, int> mpp;
        queue<pair<Node*, int>> q;
        q.push({root, 0});
    
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            Node* node = it.first;
            int line = it.second;
            
            if(mpp.find(line) == mpp.end())mpp[line] = node->data;//First Occurence
            
            if(node->left != NULL)q.push({node->left, line - 1});
            
            if(node->right != NULL)q.push({node->right, line + 1}); 
        }
    
        for(auto it : mpp)ans.push_back(it.second);
    
        return ans;
    }












//COMMENTED
    vector<int> topView(Node* root){
        // Vector to store the result
        vector<int> ans;
        
        // Check if the tree is empty
        if(root == NULL){
            return ans;
        }
        
        // Map to store the top view nodes
        // based on their vertical positions
        map<int, int> mpp;
        
        // Queue for BFS traversal, each element
        // is a pair containing node 
        // and its vertical position
        queue<pair<Node*, int>> q;
        
        // Push the root node with its vertical
        // position (0) into the queue
        q.push({root, 0});
        
        // BFS traversal
        while(!q.empty()){
            // Retrieve the node and its vertical
            // position from the front of the queue
            auto it = q.front();
            q.pop();
            Node* node = it.first;
            int line = it.second;
            
            // If the vertical position is not already
            // in the map, add the node's data to the map
            if(mpp.find(line) == mpp.end()){
                mpp[line] = node->data;
            }
            
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
