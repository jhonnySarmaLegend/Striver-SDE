// USING RECURSION
class Solution {
public:
    void rec(int ind,vector<int>& nums,vector<int>& v,vector<vector<int>>& vect,int n)
    {
        if(ind==n)
        {
            vect.push_back(v);
            return ;
        } 

        //Pick
        v.push_back(nums[ind]);
        rec(ind+1,nums,v,vect,n);

        //no Pick
        v.pop_back();
        rec(ind+1,nums,v,vect,n);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<int>v;
        vector<vector<int>>vect;
        rec(0,nums,v,vect,n);
    return vect;
    }
};




// OPTIMAL --> using bit manipulation
class Solution {
public:
     vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>V;
        for(int i=0;i<(1<<nums.size());i++){ // 2^n -1 = total number of subset
            vector<int>a;
            for(int j=0;j<nums.size();j++){ // element of array traversal
                if(i&(1<<j)){ // pick non pick
                   a.push_back(nums[j]);
                }
            }
            V.push_back(a);
        }
        return V;
    }
};
