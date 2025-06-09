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
      
