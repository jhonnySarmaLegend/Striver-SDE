// T.C. = O(N) , S.C. = O(1) FOR ALL 


/* 
   Question Link --> https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

  Variation 1 -> Only  1 transaction allowed
*/


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



/*
Question Link --> https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/

Variation 3->  Multiple transactions allowed
*/
   int maxProfit(vector<int>& prices) {
        int profit = 0;

        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > prices[i-1]) {
                profit += prices[i] - prices[i-1];
            }
        }
        return profit;
    }



/*
Question Link --> 

Variation 3-> Only  2 transactions allowed
*/
int maxProfit(vector<int>& prices) {
        if(!prices.size())
            return 0;
        int buy1    = INT_MAX;
        int profit1 = INT_MIN;
        int buy2    = INT_MAX;
        int profit2 = INT_MIN;
        for(int i = 0; i < prices.size(); i++){
            buy1    = min(buy1, prices[i]);
            profit1 = max(profit1, prices[i] - buy1);
            buy2    = min(buy2, prices[i] - profit1);
            profit2 = max(profit2, prices[i] - buy2);
        }
        return profit2;
    }
