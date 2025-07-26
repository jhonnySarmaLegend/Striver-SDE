//https://leetcode.com/problems/roman-to-integer/

class Solution {
public:
    int romanToInt(string s) {
        int ans=0;
        unordered_map <char,int> mp{
        {'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};

    for(int i=0;i<s.size();i++){
        if(mp[s[i]]<mp[s[i+1]]){
            //for cases such as IV,CM, XL, etc...
            ans=ans-mp[s[i]];
        }
        else{
            ans=ans+mp[s[i]];
        }
    }
        return ans;
    }
};





// Integer to Roman --> different map set
class Solution {
public:
    string intToRoman(int num) {
        // Mapping of integer values to Roman numerals
        unordered_map<int, string> valueSymbols = {
            {1000, "M"}, 
            {900, "CM"}, 
            {500, "D"}, 
            {400, "CD"}, 
            {100, "C"}, 
            {90, "XC"}, 
            {50, "L"}, 
            {40, "XL"}, 
            {10, "X"}, 
            {9, "IX"}, 
            {5, "V"}, 
            {4, "IV"}, 
            {1, "I"}
        };

        string result = "";

        // Since maps are unordered, we need to iterate in descending order
        // Instead, we manually create a sorted list of keys
        vector<int> values = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

        // Iterate through the sorted keys
        for (int value : values) {
            // Append the symbol while the value can be subtracted from num
            while (num >= value) {
                result += valueSymbols[value];
                num -= value;
            }
        }

        return result;
    }
};
