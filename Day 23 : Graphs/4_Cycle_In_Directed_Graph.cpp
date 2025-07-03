// Question Link --> https://leetcode.com/problems/course-schedule/description/


// Another Name --> Course Schedule


class Solution {
private:
    // Helper function for DFS-based cycle detection
    // node: current node
    // adj: adjacency list representing the graph
    // vis: array to mark visited nodes (0: unvisited, 1: visiting, 2: visited and processed)
    // pathVis: array to mark nodes currently in the recursion stack (0: not in path, 1: in path)
    bool dfsCheck(int node, vector<int> adj[], int vis[], int pathVis[]) {
        vis[node] = 1;      // Mark node as visiting
        pathVis[node] = 1;  // Mark node as part of current path

        // Traverse all adjacent nodes
        for (int neighbor : adj[node]) {
            // If the neighbor has not been visited
            if (vis[neighbor] == 0) {
                if (dfsCheck(neighbor, adj, vis, pathVis)) {
                    return true; // Cycle detected in a deeper path
                }
            }
            // If the neighbor has been visited AND is currently in the path (i.e., back-edge)
            else if (pathVis[neighbor] == 1) {
                return true; // Cycle detected
            }
        }

        pathVis[node] = 0; // Backtrack: remove node from current path
        // Optionally, you can mark vis[node] = 2 here to indicate fully processed,
        // but for just cycle detection, 0 and 1 for vis, and 0 and 1 for pathVis are sufficient.
        return false; // No cycle found in this path
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Create an adjacency list to represent the graph
        vector<int> adj[numCourses];
        for (const auto& prereq : prerequisites) {
            // A prerequisite [ai, bi] means bi must be taken before ai.
            // So, there's a directed edge from bi to ai.
            adj[prereq[1]].push_back(prereq[0]);
        }

        // vis: 0 = unvisited, 1 = visiting (in current DFS path), 2 = visited (and its sub-tree processed)
        // For this specific problem's cycle detection, 0/1 for vis and 0/1 for pathVis are enough.
        // vis array tracks overall visited status to avoid redundant DFS calls.
        // pathVis tracks nodes in the current recursion stack to detect back-edges.
        int vis[numCourses];
        int pathVis[numCourses];
        fill(vis, vis + numCourses, 0);       // Initialize all nodes as unvisited
        fill(pathVis, pathVis + numCourses, 0); // Initialize all nodes as not in current path

        // Iterate through all courses to ensure all disconnected components are checked
        for (int i = 0; i < numCourses; ++i) {
            if (vis[i] == 0) { // If the course has not been visited yet
                if (dfsCheck(i, adj, vis, pathVis)) {
                    return false; // A cycle is detected, impossible to finish all courses
                }
            }
        }

        // No cycles detected, all courses can be finished
        return true;
    }
};
