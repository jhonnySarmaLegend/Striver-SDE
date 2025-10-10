// Link -->  https://leetcode.com/problems/longest-palindromic-substring/description/


// Brute Force
class Solution {
public:
    bool check(string &s, int i, int j){
        while(i<j){
            if(s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }            
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int starting_index = 0;
        int max_len = 0;
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                if(check(s, i, j)){
                    if(j-i+1 > max_len){
                        max_len = j-i+1;
                        starting_index = i;
                    }
                }
            }
        }
        return s.substr(starting_index, max_len);
    }
};



//OPTIMIZED
class Solution {
private:
    // Helper function to expand around center
    void expand(int l, int r, string &s, int &maxLen, string &res) {
        int n = s.size();
        while (l >= 0 && r < n && s[l] == s[r]) {
            int len = r - l + 1;
            if (len > maxLen) {
                maxLen = len;
                res = s.substr(l, len);
            }
            l--;
            r++;
        }
    }

public:
    string longestPalindrome(string s) {
        int n = s.size();
        int maxLen = 0;
        string res;

        // Check each character as center
        for (int i = 0; i < n; i++) {
            // Odd length palindrome
            expand(i, i, s, maxLen, res); // i as center
            // Even length palindrome
            expand(i, i + 1, s, maxLen, res); // i,i+1 as center
        }

        return res;
    }
};
