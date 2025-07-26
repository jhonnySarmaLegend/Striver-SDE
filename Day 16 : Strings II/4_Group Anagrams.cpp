// Link --> https://leetcode.com/problems/group-anagrams/description/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& str) {
        vector<vector<string>>ans;

        unordered_map<string,vector<string>>mp;

        for( auto it : str)
        {
            string s = it;
            sort(s.begin(),s.end());
            
            mp[s].push_back(it);
        }

        for(auto x :mp)ans.push_back(x.second);
        
        
        return ans;
    }
};
