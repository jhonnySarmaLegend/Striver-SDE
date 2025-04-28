
/*
  Question Link --> https://leetcode.com/problems/assign-cookies/description/
*/
// T.C. = O(max(M,N)) + O(LogN) ~ O(LogN), S.C. =O(1)
int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int ans=0;
        int n=g.size(), m=s.size();
        int i=0,j=0;
        while(i<m && j<n){
            if(s[i]>=g[j]){
                ans++;i++;j++;
            }
            else{
                i++;
            }
            
        }
        return ans;
    }
