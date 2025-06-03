//VARIATION 1 - total number of nodes present in between
// A queue based C++ program to find maximum width
// of a Binary Tree
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    Node(int d)
    {
        this->data = d;
        this->left = this->right = NULL;
    }
};

// Function to find the maximum width of the tree
// using level order traversal
int maxWidth(struct Node* root)
{
    // Base case
    if (root == NULL)
        return 0;

    // Initialize result
    int result = 0;

    // Do Level order traversal keeping track of number
    // of nodes at every level.
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        // Get the size of queue when the level order
        // traversal for one level finishes
        int count = q.size();

        // Update the maximum node count value
        result = max(count, result);

        // Iterate for all the nodes in the queue currently
        while (count--) {
            // Dequeue an node from queue
            Node* temp = q.front();
            q.pop();

            // Enqueue left and right children of
            // dequeued node
            if (temp->left != NULL)
                q.push(temp->left);
            if (temp->right != NULL)
                q.push(temp->right);
        }
    }

    return result;
}

// Driver code
int main()
{
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(8);
    root->right->right->left = new Node(6);
    root->right->right->right = new Node(7);

    /*   Constructed Binary tree is:
                 1
               /   \
              2      3
             /  \     \
            4    5     8
                     /   \
                    6     7    */

    // Function call
    cout << "Maximum width is " << maxWidth(root) << endl;
    return 0;
}

// This code is contributed by Nikhil Kumar
// Singh(nickzuck_007)
