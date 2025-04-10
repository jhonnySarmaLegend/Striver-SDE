/* 
   Question Link --> https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
*/

// T.C. = O(N) , S.C. = O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size(); 
        int minBuy=INT_MAX;
        int maxPro=INT_MIN;

        for(int i=0;i<n;i++){
            minBuy=min(minBuy,prices[i]);
            maxPro=max(maxPro,prices[i]-minBuy);
        }

        return maxPro;
    }
};
