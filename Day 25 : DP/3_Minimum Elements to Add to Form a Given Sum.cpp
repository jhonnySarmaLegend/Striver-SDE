
// LINK --> https://leetcode.com/problems/minimum-elements-to-add-to-form-a-given-sum/

// Can be solved using DYNAMIC PROGRAMMING --> But we will use Maths LOGIC


class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        long long sum = 0;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            sum = sum + nums[i];
        }

        long req = abs(sum - goal);

        if(req%limit){
            return (req/limit)+1; // ceil if fractional number
        }
        return req/limit;  // whole number
    }
};


