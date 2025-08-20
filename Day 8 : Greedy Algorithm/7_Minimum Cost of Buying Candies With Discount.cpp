// Link --> https://leetcode.com/problems/minimum-cost-of-buying-candies-with-discount/description/

// T.c.=O(nlogn) , S.C.=O(1)

class Solution {
public:
    int minimumCost(vector<int>& cost) {
        // Step 1: Sort the array in descending order
        sort(cost.begin(), cost.end(),greater<int>());
        int totalCost = 0;

        // Step 2: Iterate through the array in groups of three
        for (int i = 0; i < cost.size(); ++i) {
            // For every two candies, skip the third one (it's free)
            if ((i + 1) % 3 != 0) {
                totalCost += cost[i];
            }
        }
        return totalCost;
    }
};
