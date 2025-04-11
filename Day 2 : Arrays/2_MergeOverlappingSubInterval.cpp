/*
   Question Link --> https://leetcode.com/problems/merge-intervals/description/
*/
//T.C. = O(N) , S.C. = O(1)  & not O(N^2) since ans is used to return the req value , not used for computation
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());

        for(int i=0;i<intervals.size();i++){
                // 1st element pushback & 2nd condition
                if(ans.empty()||intervals[i][0]>ans.back()[1]){
                    ans.push_back(intervals[i]);
                }
                else{
                    ans.back()[1]=max(ans.back()[1],intervals[i][1]);
                }
        }

        return ans;        
    }
};
