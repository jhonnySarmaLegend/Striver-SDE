// Link --> https://leetcode.com/problems/generate-parentheses/description/


class Solution {
public:
    void helper(vector<string>&ans ,int op,int cp,int n ,string s)
    {
        if(op==n && cp==n)
        {
            ans.push_back(s);
            return ;
        }
        if(op<n)
            helper(ans,op+1,cp,n,s+"(");
        if(cp<op)
            helper(ans,op,cp+1,n,s+")");
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        int op=0,cp=0;
        helper(ans,op,cp,n,"");
        return ans;
        
    }
};







//COMMENTED CODE
class Solution {
public:
    // Recursive helper function to generate valid parentheses
    void helper(vector<string>& ans, int op, int cp, int n, string s) {
        // Base case: if both opening and closing parentheses count reaches n, 
        // we have a valid combination. Add it to the result.
        if (op == n && cp == n) {
            ans.push_back(s);
            return;
        }

        // If the number of opening parentheses is less than n, 
        // add '(' and recurse with op + 1.
        if (op < n)
            helper(ans, op + 1, cp, n, s + "(");

        // If the number of closing parentheses is less than the number of opening parentheses, 
        // add ')' and recurse with cp + 1.
        if (cp < op)
            helper(ans, op, cp + 1, n, s + ")");
    }

    vector<string> generateParenthesis(int n) {
        // Initialize the result vector to store valid combinations
        vector<string> ans;

        // Initialize counters for opening and closing parentheses
        int op = 0, cp = 0;

        // Start the recursive process with an empty string
        helper(ans, op, cp, n, "");

        // Return the result
        return ans;
    }
};
