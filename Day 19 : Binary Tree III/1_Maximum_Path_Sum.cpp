//Question Link --> https://leetcode.com/problems/binary-tree-maximum-path-sum/description/

   int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN;
        maxpathdown (root,maxi);
        return maxi;
      }
    int maxpathdown(TreeNode* root,int &maxi)
   {   
       if(root==NULL) return 0;
       int left = max(0,maxpathdown(root->left,maxi)); // compare with 0 , to ignore path with 0 sum
       int right = max(0,maxpathdown(root->right,maxi));
       maxi=max(maxi,left+right+root->val);

       return root->val+max(left,right);
   }    
      



// VARIATION 2 - MAX Path SUm from ROOT
void dfs(TreeNode* root, int curSum,int &maxSum){
  if(root==NULL)return;

  curSum+=root->val;

  maxSum=max(maxSum,curSum);

  dfs(root->left,curSum,maxSum);
  dfs(root->right,curSum,maxSum);
}

int rootPathMaxSum(TreeNode* root) {
    int maxi=INT_MIN;
   if(root==NULL)return maxi;

   dfs(root,0,maxi);
   return maxi;
}
