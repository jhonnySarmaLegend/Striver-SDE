// Question --> https://leetcode.com/problems/longest-valid-parentheses/




// USING STACK
// https://www.youtube.com/watch?v=zhsjU1Bh9jQ
// calculate & store index of invalid parenthesis in the stack









// OPTIMAL



/*

Intuition
The problem requires finding the longest substring of valid parentheses. The first thought is to balance the parentheses by counting the number
of '(' and ')' from left to right and then from right to left. This helps capture valid parentheses sequences even if the string has unbalanced 
or nested parentheses.

Approach
Perform two passes over the string:

1.Forward Scan (Left to Right): As we traverse the string, we count the number of '(' and ')' . If the counts are equal, we update the length
of the valid substring. If at any point the number of ')' exceeds the number of '(' , it indicates an invalid sequence, and we reset the counters.

2.Backward Scan (Right to Left): This pass ensures that unmatched '(' on the left are handled by counting parentheses from the other side, similar 
to the first pass. This ensures all valid substrings, including nested and overlapping ones, are accounted for.

The maximum length from both passes is returned as the final result.

Complexity
Time complexity: O(n)
Space complexity:O(1)

*/


class Solution {
public:
    int longestValidParentheses(string s) {
        int left = 0, right = 0, max_len = 0;
        if (s.size()==0){
            return 0;
        }

        // ()) --> right orphan bracket
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') left++;
            else right++;
            if (left == right) {
                max_len = max(max_len, left + right);
            }
            else if (right > left) {
                left = 0;
                right = 0;
            }
        }
        
        left = 0;
        right = 0;
        // (() --> left orphan bracket
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == '(') left++;
            else right++;
            if (left == right) {
                max_len = max(max_len, left + right);
            }
            else if (left > right) {
                left = 0;
                right = 0;
            }
        }
        
        return max_len;
    }
};
        
  
