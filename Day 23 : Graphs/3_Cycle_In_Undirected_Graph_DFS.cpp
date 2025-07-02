// https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

// curr node already visited and not parent node 

class Solution {
  public:
    vector<vector<int>> constructadj(int V, vector<vector<int>> &edges){
    //bi-directional or undirectional graph
    vector<vector<int>> adj(V);
    for (auto it : edges)
    {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    return adj;
  }
  
    bool dfs(int node, vector<int> &visited, vector<vector<int>> &adjList, int parent) {
        visited[node] = 1;
        for (auto it: adjList[node]) {
            if (!visited[it]){
                if(dfs(it, visited, adjList, node))
                return true;
            } else if (it!= parent) {
                return true;
            }
        }
        return false;
    }
    
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adjList=constructadj(V,edges);
        
        vector<int> visited(V, 0);
        
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                // dfs(startingNode, visitedArray, adjList, parentNode)
                if (dfs(i, visited, adjList, -1)) {
                    return true;
                }
            }
        }
        
        return false;
    }
};





// COMMENTED CODE
class Solution {
public:
    // Function to construct an adjacency list from the given edges.
    // This creates an undirected graph where each edge connects two nodes bidirectionally.
    vector<vector<int>> constructadj(int V, vector<vector<int>>& edges) {
        // Initialize an adjacency list with V empty vectors.
        vector<vector<int>> adj(V);
        // Iterate through each edge in the input 'edges' vector.
        for (auto it : edges) {
            // Add the connection from the first node to the second.
            adj[it[0]].push_back(it[1]);
            // Add the connection from the second node to the first, as it's an undirected graph.
            adj[it[1]].push_back(it[0]);
        }
        return adj;
    }

    // Depth-First Search (DFS) function to detect cycles in the graph.
    // 'node': The current node being visited.
    // 'visited': A vector to keep track of visited nodes (0 for unvisited, 1 for visited).
    // 'adjList': The adjacency list representing the graph.
    // 'parent': The parent of the current node in the DFS tree, used to avoid going back to the immediate parent.
    bool dfs(int node, vector<int>& visited, vector<vector<int>>& adjList, int parent) {
        // Mark the current node as visited.
        visited[node] = 1;

        // Iterate through all neighbors of the current node.
        for (auto it : adjList[node]) {
            // If the neighbor has not been visited yet,
            if (!visited[it]) {
                // Recursively call DFS for the neighbor, passing the current node as its parent.
                if (dfs(it, visited, adjList, node)) {
                    return true; // If a cycle is found in the recursive call, propagate true.
                }
            }
            // If the neighbor has been visited and is not the parent of the current node,
            // then a cycle is detected.
            else if (it != parent) {
                return true;
            }
        }
        return false; // No cycle found from this node's path.
    }

    // Main function to check if the graph contains a cycle.
    // 'V': The number of vertices in the graph.
    // 'edges': A list of edges representing the graph.
    bool isCycle(int V, vector<vector<int>>& edges) {
        // First, construct the adjacency list from the given edges.
        vector<vector<int>> adjList = constructadj(V, edges);
        // Initialize a 'visited' array for all vertices to keep track of visited nodes during DFS.
        // All nodes are initially unvisited (0).
        vector<int> visited(V, 0);

        // Iterate through all vertices to handle disconnected components of the graph.
        for (int i = 0; i < V; i++) {
            // If the current node has not been visited, start a DFS from it.
            if (!visited[i]) {
                // Call the DFS function. If it returns true, a cycle is found.
                // The parent of the starting node of a DFS traversal is -1 (or any value indicating no parent).
                if (dfs(i, visited, adjList, -1)) {
                    return true; // If a cycle is found, immediately return true.
                }
            }
        }
        return false; // No cycle found in the entire graph.
    }
};
