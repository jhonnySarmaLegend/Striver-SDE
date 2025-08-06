// https://leetcode.com/problems/min-cost-climbing-stairs/


// MOST OPTIMIZED --> T.C.= O(N) , S.C. = O(1)
class Solution {
public:
    int minCostClimbingStairs(vector<int> cost) {
        int n = cost.size();

        int prev2 = cost[0];
        int prev1 = cost[1];

        for(int i=2; i<n; i++) {
            int curr = min(prev1, prev2) + cost[i];
            prev2 = prev1;
            prev1 = curr;
        }
        
        return min(prev1, prev2);
    }
};



// 1. recursion --> tle
//Recursive	t.c-O(2ⁿ)	s.c.-O(n)	-->Exponential recursion depth
class Solution {
public:
    int wrapperFunc(vector<int> &cost, int n){
        //Step1 Or Step2 (base case)
        if(n == 0 || n == 1)
            return 0;

        return min(cost[n-1]+wrapperFunc(cost, n-1), cost[n-2]+wrapperFunc(cost, n-2));
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        return wrapperFunc(cost, n);
    }
};


// Memoization
// t.c.= O(N)  s.c.=O(N) stack+ O(N) dp array == O(N)
class Solution {
public:
    // Memoization helper
    int memoizedFunc(int n, vector<int>& cost, vector<int>& dp) {
        if (n == 0 || n == 1) 
            return 0;  // Base case: no cost to stay at step 0 or 1

        if (dp[n] != -1) 
            return dp[n];  // Return cached result

        // Compute and cache
        // Cost of step n-1 + steps before it ,Cost of step n-2 + steps before it
        dp[n] = min(cost[n-1] + memoizedFunc(n-1, cost, dp), cost[n-2] + memoizedFunc(n-2, cost, dp));

        return dp[n];
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1, -1);  // DP table initialized to -1
        return memoizedFunc(n, cost, dp);
    }
};


// Tabulation
// t.c.= O(N)  s.c.=O(N)
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1, -1);

        dp[0] = 0;
        dp[1] = 0;
        for(int i=2; i<=n; i++)
            dp[i] = min(cost[i-1]+dp[i-1], cost[i-2]+dp[i-2]);

        return dp[n];
    }
};
