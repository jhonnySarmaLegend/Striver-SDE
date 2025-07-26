// Leetcode --> https://leetcode.com/problems/reverse-words-in-a-string/description/


// Using stack
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



// OPTIMIZED
