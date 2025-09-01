// LINK --> https://leetcode.com/problems/permutation-in-string/description/

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int len1 = s1.length();
        int len2 = s2.length();
        
        // If s1 is longer than s2, s2 cannot contain a permutation of s1
        if (len1 > len2) return false;
        
        // Frequency arrays for characters in s1 and the current window in s2
        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);
        
        // Initialize frequency arrays for the first window in s2
        for (int i = 0; i < len1; i++) {
            freq1[s1[i] - 'a']++;
            freq2[s2[i] - 'a']++;
        }
        
        // If the frequency arrays match, return true
        if (freq1 == freq2) return true;
        
        // Slide the window through s2
        for (int i = len1; i < len2; i++) {
            // Add the new character to the window
            freq2[s2[i] - 'a']++;
            // Remove the old character from the window
            freq2[s2[i - len1] - 'a']--;
            
            // If the frequency arrays match after sliding the window, return true
            if (freq1 == freq2) return true;
        }
        
        // No permutation found
        return false;
    }
};
