int lengthOfLongestSubstringKDistinct(string s, int k) {
unordered_map<char,int> charCount;
int left = 0;
int maxLen = 0;
int right = 0; // Initialize the right index

// SLIDING WINDOW
while (right < s.size()) {
    charCount[s[right]]++;
    
    // Shrink the window if the number of unique characters exceeds k
    while (charCount.size() > k) {
        charCount[s[left]]--;
        if (charCount[s[left]] == 0) {
            charCount.erase(s[left]);
        }
        left++;
    }

    // Update the maximum length
    maxLen = max(maxLen, right - left + 1);
    
    // Move the right index to the next position
    right++;
}

return maxLen;
}




/* Longest substring with  distinct characters
 vector < int > mpp(256, -1);

      int left = 0, right = 0;
      int n = s.size();
      int len = 0;
      while (right < n) {
        if (mpp[s[right]] != -1)left = max(mpp[s[right]] + 1, left);//encountered early --> for vector index 

        mpp[s[right]] = right;

        len = max(len, right - left + 1);
        right++;
      }
      return len
          */
