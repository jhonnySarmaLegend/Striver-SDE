//Question --> https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words/description/?envType=daily-question&envId=2025-05-26

    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> freq;
        int res = 0;

      //Step 1: Use a HashMap to Track Frequencies
      //Step 2: Greedily Pair Words and Their Reverses
        for (string &word : words) {
            string rev = string() + word[1] + word[0];
            if (freq[rev] > 0) {
                res += 4;
                freq[rev]--;
            } else {
                freq[word]++;
            }
        }
   
      //Step 3: Handle the Center (If Any Palindromic Word Left)
        for (auto it : freq) {
            if (it.first[0] == it.first[1] && it.second > 0) {
                res += 2;
                break;
            }
        }

        return res;
    }   


//T.C.= O(N), S.C.= O(N)
