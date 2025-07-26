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
public:
    // Expands around the “center” defined by indices i and j,
    // returning the length of the longest palindromic substring found.
    // When i == j → odd-length center (e.g. “racecar” center at ‘e’)
    // When j == i + 1 → even-length center (e.g. “abba” center between the two b’s)
    int ExpandFromCenter(const string& s, int i, int j) {
        // Expand outward as long as we haven’t run off the ends
        // and the characters still match.
        while (i >= 0 && j < (int)s.size() && s[i] == s[j]) {
            i--;
            j++;
        }
        // After the loop, i and j have stepped one too far:
        // length = (j - 1) − (i + 1) + 1 = j − i − 1
        return j - i - 1;
    }

    string longestPalindrome(string s) {
        if (s.empty()) return "";

        int start = 0, end = 0;
        // For each character (and each gap), try to expand around it
        for (int i = 0; i < (int)s.size(); i++) {
            // Even-length palindromes (center between i and i+1)
            int lenEven = ExpandFromCenter(s, i, i + 1);
            // Odd-length palindromes (center at i)
            int lenOdd  = ExpandFromCenter(s, i, i);
            // Take the longer of the two
            int len = max(lenEven, lenOdd);

            // If this palindrome is longer than any we've seen, update bounds
            if (len > end - start + 1) {
                // For a palindrome of length len centered at i:
                // new start = i − (len − 1) / 2
                // new end   = i + len / 2
                start = i - (len - 1) / 2;
                end   = i +  len      / 2;
            }
        }

        // substr takes (start index, length)
        return s.substr(start, end - start + 1);
    }
};
