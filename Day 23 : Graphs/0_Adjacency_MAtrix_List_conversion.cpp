// 1.Adjacency Matrix to List


// Determine the number of vertices (nodes) from the size of the adjacency matrix.
    int v = adjMatrix.size(); 

    // Step 1: Convert Adjacency Matrix to Adjacency List
    // Create an adjacency list representation.
    // adjList[i] will store a list of all nodes directly connected to node 'i'.
    vector<vector<int>> adjList(v); 
    for (int i = 0; i < v; ++i) {
        for (int j = 0; j < v; ++j) {
            // If there's an edge from node 'i' to node 'j' (adjMatrix[i][j] == 1)
            if (adjMatrix[i][j] == 1) {
                // Add 'j' to the list of neighbors for node 'i'.
                adjList[i].push_back(j);
            }
        }
    }



// 2.Adjacency List to Matrix 

// Determine the number of vertices (nodes) from the size of the adjacency list.
    int v = adjList.size();

    // Create an adjacency matrix initialized with zeros.
    // adjMatrix[i][j] will be 1 if there's an edge from i to j, 0 otherwise.
    vector<vector<int>> adjMatrix(v, vector<int>(v, 0));

    // Iterate through each node 'i' in the adjacency list.
    for (int i = 0; i < v; ++i) {
        // For each node 'i', iterate through its list of neighbors.
        // 'neighbor' is a node directly connected to 'i'.
        for (int neighbor : adjList[i]) {
            // Set the corresponding entry in the adjacency matrix to 1,
            // indicating an edge from 'i' to 'neighbor'.
            adjMatrix[i][neighbor] = 1;
        }
    }

    // Return the newly created adjacency matrix.
    return adjMatrix;
