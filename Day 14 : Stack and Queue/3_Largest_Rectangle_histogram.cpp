//Question Link --> https://leetcode.com/problems/largest-rectangle-in-histogram/description/

//T.C.=O(5N) , S.C.=O(3N)
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) 
    {
        int n=heights.size();
        stack<int>st;
        vector<int>pse(n);
        vector<int>nse(n);

        for(int i=0;i<n;i++)//PSE for element index
        {
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            pse[i]=st.empty()?-1:st.top(); // deafult --> -1 on left side
            st.push(i);
        }
        while(!st.empty()) st.pop();

        for(int i=n-1;i>=0;i--)//NSE for element index
        {
            while(!st.empty() && heights[st.top()]>=heights[i]) st.pop();
            nse[i]=st.empty()?n:st.top();  // deafult --> N on right side
            st.push(i);
        }

        int maxi=0;
        for(int i=0;i<n;i++)
        {
            maxi=max(maxi,heights[i]*(nse[i]-pse[i]-1)); // height * width
        }
        return maxi;
    }
};
