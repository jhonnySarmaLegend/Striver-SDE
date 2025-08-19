// Leetcode --> https://leetcode.com/problems/reverse-words-in-a-string/description/


// OPTIMAL --> T.C.=O(N), S.C.=O(1)
string reverseWords(string s) {
    int n = s.size();

    // Step 1: Reverse the entire string.
    reverse(s.begin(), s.end());

    // Step 2: Reverse words individually.
    int start = 0, end = 0;
    while (end < n) {
        // Skip leading spaces to find the start of a word.
        while (start < n && s[start] == ' ')++start;

        end = start;

        // Find the boundary of the word.
        while (end < n && s[end] != ' ')++end;

        // Reverse the word.
        reverse(s.begin() + start, s.begin() + end);

        // Move to the next word.
        start = end;
    }

    // Step 3: Clean up extra spaces in-place.
    int read = 0, write = 0;

    // Skip leading spaces.
    while (read < n && s[read] == ' ')++read;

    while (read < n) {
        // Copy the word.
        while (read < n && s[read] != ' ')
            s[write++] = s[read++];

        // Skip multiple spaces.
        while (read < n && s[read] == ' ')++read;

        // Add a single space if more content exists.
        if (read < n)s[write++] = ' ';
    }

    // Return the trimmed result.
    return s.substr(0, write);
}






//T.C.= O(N),S.C.=O(N)
string reverseWords(string s) {
    reverse(s.begin(), s.end());
    string ans;
    int n = s.length();
    
    for (int i = 0; i < n; ++i) {
        // skip any spaces
        if (s[i] == ' ') continue;
        
        // collect the next word in reversed s
        string word;
        while (i < n && s[i] != ' ') {
            word += s[i++];
        }
        
        // reverse it back
        reverse(word.begin(), word.end());
        
        // append (with leading space if ans not empty) // space between two words 
        if (!ans.empty())ans += ' ';
        ans += word;
    }
    
    return ans;
}

// Using stack --> O(N) , O(N)
class Solution {
public:
    string reverseWords(string s) {
      stack<string>st;
      string res="";
      
      for(int i=0;i<s.length();i++)
      {
          if(s[i]!=' ') res+=s[i];
          
          else // s[i]==' '
          {
              if(res.length()>0)
              st.push(res);
              res="";
          }
      }
      
      if(res.length()>0)st.push(res);
      
      res="";
      while(!st.empty())
      {     res+=st.top();
            st.pop();
            if(!st.empty())res+=" "; // not add space after last element 
      }
     
      return res;
        
    }
};




// OPTIMIZED  --> O(N) , O(1)
class Solution {
public:
    string reverseWords(string s) {
        int left = 0;
        int right = s.length() - 1; // 'right' is used for the loop boundary check

        string temp = ""; // Stores characters of the current word being built
        string ans = "";  // Stores the final reversed sentence

        // Iterate through the string from left to right
        // The goal is to form individual words and then prepend them to 'ans'.
        while (left <= right) {
            char ch = s[left];

            if (ch != ' ') {
                // If the character is not a space, it's part of the current word
                temp += ch; // Append character to the 'temp' word
            } else { // if (ch == ' ')
                // If a space is encountered, it signifies the end of a word (or multiple spaces)

                // This condition is crucial for handling multiple spaces between words
                // and leading spaces. If 'temp' is empty, it means we've just seen
                // one or more consecutive spaces, so we don't form an empty word.
                if (temp != "") {
                    // If 'ans' already contains words, prepend the current 'temp' word
                    // with a space separator.
                    if (ans != "") {
                        ans = temp + " " + ans;
                    }
                    // If 'ans' is empty, this is the first word being added.
                    else {
                        ans = temp;
                    }
                    temp = ""; // Reset 'temp' to start building the next word
                }
                // If temp is empty here, it means 'ch' was a space, but 'temp'
                // was already empty (e.g., "  word", or "word  word").
                // In this case, we simply do nothing and continue, effectively
                // consuming the extra space.
            }
            left++; // Move to the next character
        }

        // After the loop, 'temp' might contain the last word of the string
        // (if the string doesn't end with a space).
        // This block handles appending that final word to 'ans'.
        if (temp != "") {
            // Same logic as inside the loop's 'else if (ch == ' ')' block:
            // Prepend the last word to 'ans' with a space if 'ans' already has content.
            if (ans != "") {
                ans = temp + " " + ans;
            }
            // If 'ans' is still empty (e.g., input was "singleword"),
            // then 'ans' simply becomes the last word.
            else {
                ans = temp;
            }
        }

        return ans; // Return the string with words reversed
    }
};



// OPTIMIZED
