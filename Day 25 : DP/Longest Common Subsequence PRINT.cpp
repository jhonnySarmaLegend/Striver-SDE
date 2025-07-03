#include <iostream>
#include <vector>
#include <string>
using namespace std;

string getLCS(const string& text1, const string& text2) {
    int m = text1.size(), n = text2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Build the DP table
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (text1[i - 1] == text2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    // Reconstruct the LCS string from the table
    int i = m, j = n;
    string lcs;
    while (i > 0 && j > 0) {
        if (text1[i - 1] == text2[j - 1]) {
            lcs.push_back(text1[i - 1]);
            --i;
            --j;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            --i;
        } else {
            --j;
        }
    }
    // The string is built backward, so reverse it
    reverse(lcs.begin(), lcs.end());
    return lcs;
}

int main() {
    string text1 = "abcde";
    string text2 = "ace";
    string lcs = getLCS(text1, text2);
    cout << "Longest Common Subsequence: " << lcs << endl;
    return 0;
}
