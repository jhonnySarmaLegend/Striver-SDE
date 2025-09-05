// Approach 1 --> T.C.=O(2N), S.C.=O(2N) - Extra space + Auxillary space in call stack
// p= [1,2,3,4,5] path to reach p
// q=[1,2,3,9,7] path to reach q
// 3 is the common ancestor before path separation which is equivalent to last matching path
class Solution {
public:
    bool findpath(TreeNode*root,TreeNode*target,vector<TreeNode*>&path)
    {
        if (root == NULL)
        return false;
    
        // If we’re at the target, or we find it in either subtree:
       if (root == target|| findpath(root->left,  target, path)|| findpath(root->right, target, path))
      {
        // Record this node on the path, and bubble up “found”
        path.push_back(root);
        return true;
       }
    // Not found here or in subtrees
    return false;
    }
        
        
        
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*>top;
        vector<TreeNode*>toq;
        findpath(root,p,top);
        findpath(root,q,toq);
        int n=min(top.size(),toq.size());
        reverse(top.begin(),top.end());
        reverse(toq.begin(),toq.end());
        for(int i=1;i<n;i++)
        {
            if(top[i]!=toq[i])
                return toq[i-1];
        }
        return toq[n-1];
        
    }
};


//OPTIMAL 
//T.C.=O(N), S.C.=O(N) Auxillary call stack space only
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //base case
        if (root == NULL || root == p || root == q) { // leaf node , target node p or target node q
            return root;
        }
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        //result
        if(left == NULL) { 
            return right;
        }
        else if(right == NULL) {
            return left;
        }
        else { //both left and right are not null, we found our result
            return root;
        }
    }
