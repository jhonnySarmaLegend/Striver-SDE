// Link --> https://leetcode.com/problems/product-of-array-except-self/description/


// must write an algorithm that runs in O(n) time and without using the division operation.


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
      // BRUTE FORCE 
      // vector<int> ans;

        // for(int i=0;i<nums.size();i++){
        //     int mul=1;
        //     for(int j=0;j<nums.size();j++){
        //        if(i==j)continue;
        //         mul*=nums[j];
        //     }
        //     ans.push_back(mul);
        // }

        // return ans;


        //OPTIMAL      
        int n = nums.size();
        vector<int> ans(n);
        vector<int> left_Product(n);
        vector<int> right_Product(n);

        left_Product[0] = 1;
        for(int i=1; i<n; i++){
            left_Product[i] = left_Product[i-1] * nums[i-1];
        }

        right_Product[n-1] = 1;
        for(int i=n-2; i>=0; i--){
            right_Product[i] = right_Product[i+1] * nums[i+1];
        }

        for(int i=0; i<n; i++){
            ans[i] = left_Product[i] * right_Product[i];
        }
        return ans;

    }


// MORE OPTIMIZED
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);
        // 1) Build prefix products in ans:
        //    ans[i] = nums[0] * nums[1] * ... * nums[i-1]
        int prefix = 1;
        for (int i = 0; i < n; ++i) {
            ans[i] = prefix;
            prefix *= nums[i];
        }
        // 2) Multiply by suffix products on the fly:
        //    suffix = nums[i+1] * nums[i+2] * ... * nums[n-1]
        int suffix = 1;
        for (int i = n - 1; i >= 0; --i) {
            ans[i] *= suffix;
            suffix *= nums[i];
        }
        return ans;
    }
};
