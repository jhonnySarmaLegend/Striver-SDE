//Question Link  --> https://leetcode.com/problems/longest-common-subsequence/description

/*
               ApproachTime                 ComplexitySpace Complexity
  Method    Brute-force Rec.O(2^max(m, n))  O(max(m, n))       Pure Recursion
             Memoized DPO(m * n)            O(m * n)           Top-down (your code)
*/

// Recursion (TLE)
class Solution {
public:
    int lcs(string& s1, string& s2, int i, int j) {
    if (i < 0 || j < 0) return 0;

    if (s1[i] == s2[j])
        return 1 + lcs(s1, s2, i - 1, j - 1);
    else
        return max(lcs(s1, s2, i - 1, j), lcs(s1, s2, i, j - 1));
}

    int longestCommonSubsequence(string text1, string text2) {
         int m=text1.size(), n=text2.size();

        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));

        return lcs(text1, text2, m-1, n-1);
    }
};



// DP (Memoization)  --> Accepted
class Solution {
public:
    int lcs(string& s1, string& s2, int i, int j, vector<vector<int>>& dp){
        if(i<0||j<0) return 0;
    
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(s1[i]==s2[j]) return dp[i][j]=1+lcs(s1, s2, i-1, j-1, dp);
        
        return dp[i][j]=max(lcs(s1, s2, i-1, j, dp), lcs(s1, s2, i, j-1, dp));
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.size(), n=text2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        return lcs(text1, text2, m-1, n-1, dp);
    }
};


//DP (Tabulation)  --> Accepted
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        // dp[i][j] = LCS length for text1[0...i-1], text2[0...j-1]
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // Build the table from the bottom up
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (text1[i - 1] == text2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        return dp[m][n];
    }
};
