//Question Link --> https://leetcode.com/problems/binary-search-tree-iterator/description/


// 1.USING PRIORITY QUEUE or min heap
// using property --> inorder of bst is sorted
class BSTIterator {
public:
    // Min-heap of all node values
    priority_queue<int, vector<int>, greater<int>> minHeap;

    // Constructor: traverse the tree and build the heap
    BSTIterator(TreeNode* root) {
        buildHeap(root);
    }

    // Returns the next smallest number
    int next() {
        int smallest = minHeap.top();
        minHeap.pop();
        return smallest;
    }

    // True if there is still an element in the heap
    bool hasNext() const {
        return !minHeap.empty();
    }

private:
    // Inorder-traverse and push values into the min-heap
    void buildHeap(TreeNode* node) {
        if (!node) return;
        buildHeap(node->left);
        minHeap.push(node->val);
        buildHeap(node->right);
    }
};






//Effectively will store inorder in stack 

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
    stack<TreeNode*> st;
    BSTIterator(TreeNode* root) {
        pushleft(root);
    }
    
    int next() {
        TreeNode* temp=st.top();
        st.pop();
        if(temp->right!=NULL) pushleft(temp->right);
        return temp->val;
    }
    
    bool hasNext() {
        return (!st.empty());
        
    }

    private:
    void pushleft(TreeNode* root){

        while(root!=NULL){
        st.push(root);
        root=root->left;
        }

    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */













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
