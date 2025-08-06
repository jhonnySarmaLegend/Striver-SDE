
// LINK --> https://leetcode.com/problems/minimum-elements-to-add-to-form-a-given-sum/

// Can be solved using DYNAMIC PROGRAMMING --> But we will use Maths LOGIC



// Using inbuilt functions
// instead of double if long long used error will come as 5/4 in int will round of automatically to down , but 5.0/4.0 won't
    int minElements(vector<int>& nums, int limit, int goal) {
         double sum=accumulate(nums.begin(),nums.end(),0.0);
         double req = abs(sum - goal);
         return ceil(req/limit);
    }




// simple approach
class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        long long sum = 0;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            sum = sum + nums[i];
        }

        long req = abs(sum - goal);

        if(req%limit){// if limit is divisible by req or will have remainders
            return (req/limit)+1; // ceil if fractional number
        }
        return req/limit;  // whole number
    }
};


