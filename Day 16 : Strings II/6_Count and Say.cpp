/*  Link --> https://leetcode.com/problems/count-and-say/description/  


     series
     1       1
     11     in uuper layer once 1
     21     in upper layer twice 1
     1211   in upper layer once 2 once 1
     112121 in upper layer oncce 1 once 2 twice 1
     .
     .
     .
*/

class Solution {
public:
    string countAndSay(int n) {
        if(n==1)return "1";

        string say=countAndSay(n-1);

        //processing
        string res="";
        for(int i=0;i<say.size();i++){
           char ch=say[i];
           int count=1;
           while(i<say.size()-1 && say[i]==say[i+1]){
            count++;
            i++;
            }

            res+= to_string(count) + string(1,ch); // char to string in c++
        }
        return res;
    }
};
