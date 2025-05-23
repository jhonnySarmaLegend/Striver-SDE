//Question Link --> https://leetcode.com/problems/top-k-frequent-elements/description/

//Brute using map,pair
    vector<int> topKFrequent(vector<int>& nums, int k) {
       map<int,int> mp;
       for(int i=0;i<nums.size();i++)mp[nums[i]]++;

       vector<pair<int,int>> arr;
       for(auto it:mp){
        arr.push_back({it.second,it.first});
       }
       sort(arr.rbegin(),arr.rend());

       vector<int> ans;
       for(int i=0;i<k;i++)ans.push_back(arr[i].second);

       return ans;
    }

//OPTIMAL using heap
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
       map<int,int> mp;
       for(int i=0;i<nums.size();i++)mp[nums[i]]++;

       priority_queue<pair<int,int>> pq;
       for(auto it:mp)pq.push({it.second,it.first});

       vector<int> ans;
       while(k--){
        ans.push_back(pq.top().second);
        pq.pop();
       }
    
       return ans;
    }
};
