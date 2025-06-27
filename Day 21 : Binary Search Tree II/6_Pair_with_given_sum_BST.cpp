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





//OPTIMIZED
/*
Time complexity: O(1)
Space complexity: 2 * O(h) - one for next and one for before so twice of height
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class BSTIterator {   
public:
    stack<TreeNode*>stackNext;
    stack<TreeNode*>stackBefore;

    BSTIterator(TreeNode* root) {
        pushAllNext(root);
        pushAllBefore(root);
    }
    
    int next() {
        TreeNode* curr=stackNext.top();
        stackNext.pop();
        pushAllNext(curr->right);
        return curr->val;  
    }

    int before() {
        TreeNode* curr=stackBefore.top();
        stackBefore.pop();
        pushAllBefore(curr->left);
        return curr->val;  
    }
    
    void pushAllNext(TreeNode* node){
        while(node!=NULL){
            stackNext.push(node);
            node=node->left;
        }
    }

    void pushAllBefore(TreeNode* node){
        while(node!=NULL){
            stackBefore.push(node);
            node=node->right;
        }
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        BSTIterator a(root);
        int i=a.next();
        int j=a.before();
        while (i < j){
            int total = i+j;
            if(total == k){
                return true;
            }else if (total > k){
                j=a.before();
            }else{
                i=a.next();
            }
        }
        return false;
    }
};
