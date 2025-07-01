//Question Link --> https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1

//Adjacency List


// T.C. = O(N) + O(2E) , S.C. = O(3N) [ vis,q,ans] ~ O(N)
vector<int> bfs(vector<vector<int>> &adj) {
int v = adj.size(); 
vector<int> vis(v, 0);
queue<int> q; 

q.push(0); 
vis[0] = 1; 

vector<int> ans; 

while (!q.empty()) {
    int node = q.front(); 
    q.pop(); 
    ans.push_back(node); 
    for (auto it : adj[node]) { 
        if (!vis[it]) { 
            vis[it] = 1; 
            q.push(it); 
        }
    }
}
return ans;
}

