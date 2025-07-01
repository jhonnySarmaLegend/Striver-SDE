// Question Link --> https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1

/*
Time Complexity: For an undirected graph, O(N) + O(2E), For a directed graph, O(N) + O(E), 
Because for every node we are calling the recursive function once, the time taken is O(N) 
and 2E is for total degrees as we traverse for all adjacent nodes.

Space Complexity: O(3N) ~ O(N), Space for dfs stack space, visited array and an adjacency list.
*/

class Solution {
  private:
    void dfs(int node,vector<vector<int>> adj, int vis[],vector<int> &ans){
        vis[node]=1;
        ans.push_back(node);
        
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(it,adj,vis,ans);
            }
        }
    }
      
  public:
    vector<int> dfs(vector<vector<int>>& adj) {
        // adj --> adjacency list
        int v=adj.size();//no. of nodes
        int vis[v]={0};
        int start=0;
        vector<int> ans;
        dfs(start,adj,vis,ans);
        return ans;
        
    }
};
