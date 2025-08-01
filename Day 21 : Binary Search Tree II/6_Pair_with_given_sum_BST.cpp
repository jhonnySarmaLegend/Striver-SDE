//Question Link --> https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/

//BRUTE FORCE --> inorder + 2 Sum
//T.C.=O(N) , S.C.=O(N)
class Solution {
public:
    void inOrder(TreeNode* root, vector<int>& inorder) {
        if (root == NULL) return;
        inOrder(root->left, inorder);
        inorder.push_back(root->val);
        inOrder(root->right, inorder);
    }

    bool check2Sum(vector<int> inorder, int k) {
        int left = 0, right = inorder.size() - 1;
        while (left < right) {
            int temp = inorder[left] + inorder[right];
            if (temp == k) return true;
            else if (temp < k) left++;
            else right--;
        }
        return false;
    }

    bool findTarget(TreeNode* root, int k) {
        vector<int> inorder;
        inOrder(root, inorder);
        return check2Sum(inorder, k);
    }
};


