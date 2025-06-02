/*
  Question Link --> https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
*/

/*
To imagine the Binary Tree from above, we visualise vertical lines passing through the tree. Each vertical 
line represents a unique vertical position. Nodes to the right of the tree’s centre are assigned positive 
vertical indexes. As we move to the right, the vertical index increases. Nodes to the left of the tree’s 
centre are assigned negative vertical indexes. As we move to the left, the vertical index decreases
*/

// METHOD 1 - using hashmap
class Solution {
public:
// T.C. = O(N^2) , S.C. = O(N)
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int maxi=0;
        for(int i=0;i<n;i++){
            int hash[256]={0};
            for(int j=i;j<n;j++){
                if(hash[s[j]]==1)break;
                maxi=max(maxi,j-i+1);
                hash[s[j]]=1;
            }
        }
        return maxi;
    }
};

// METHOD 2 - using set
class Solution {
public:
    // Function to find the length of the longest substring without repeating characters.
    // T.C. (Time Complexity) = O(N), where N is the length of the string.
    // S.C. (Space Complexity) = O(256), since we are using a fixed-size array for ASCII characters.
    int lengthOfLongestSubstring(string s) {
        // Create a vector to store the last index of each character.
        // We initialize it to -1, indicating that the character has not been seen yet.
        vector<int> mpp(256, -1);

        // Initialize two pointers for the sliding window.
        int left = 0;  // Left boundary of the current substring.
        int right = 0; // Right boundary (current character we are examining).
        int n = s.size(); // Get the length of the input string.
        int len = 0; // Variable to keep track of the maximum length found.

        // Use a while loop to iterate through the string using the right pointer.
        while (right < n) {
            // Check if the current character has been seen before:
            if (mpp[s[right]] != -1) {
                // If it has been seen, update the left pointer.
                // We use max to ensure we don't move it backwards.
                left = max(mpp[s[right]] + 1, left);
            }

            // Update the last seen index of the current character to the current right pointer.
            mpp[s[right]] = right;

            // Calculate the length of the current substring
            // which is (right - left + 1).
            // Update the maximum length found.
            len = max(len, right - left + 1);

            // Move the right pointer forward to examine the next character.
            right++;
        }

        // After the loop, return the maximum length found.
        return len;
    }
};

