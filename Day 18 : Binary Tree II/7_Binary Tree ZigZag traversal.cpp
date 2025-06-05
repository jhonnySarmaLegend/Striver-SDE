//Question Link --> https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/

// Equivalent to level order traversal , just need to reverse alternate rows (using a flag variable)

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
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL)return ans;//edge case
        queue<TreeNode*> q;
        q.push(root);
        bool flag=true;//flag variable initialization
        while(!q.empty()){
            int n=q.size();
            
            vector<int> row;
            for(int i=0;i<n;i++){
                TreeNode* node=q.front();
                q.pop();

                row.push_back(node->val);

                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);

                
            }

            if(flag)ans.push_back(row);//flag variable condition
            else{
                reverse(row.begin(),row.end());
                ans.push_back(row);
            }
           
            flag=!flag;//flag variable updation
        }
        return ans;
    }
};
