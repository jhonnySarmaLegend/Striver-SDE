// https://www.geeksforgeeks.org/problems/range-sum-of-bst/1

class Solution {
public:
    int nodeSum(Node* root, int l, int r) {
        // Base case: if the node is null, return 0
        if (!root) return 0;

        int sum = 0;

        // If the current node's data is within the range
        if (root->data >= l && root->data <= r) {
            sum += root->data; // Add the current node's data to sum
        }

        // If current node's data is greater than l, then explore left subtree
        if (root->data > l) {
            sum += nodeSum(root->left, l, r);
        }

        // If current node's data is less than r, then explore right subtree
        if (root->data < r) {
            sum += nodeSum(root->right, l, r);
        }

        return sum; // Return the total sum
    }
};
