//Link --> https://leetcode.com/problems/string-compression/description/

// TWO POINTERS
class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int write = 0;   // position to write the compressed character or digit
        int read = 0;    // position to read the original characters
        while (read < n) {
            char current = chars[read];
            int start = read;
            // count how many times current repeats
            while (read < n && chars[read] == current) {
                read++;
            }
            int count = read - start;
            // write the character
            chars[write++] = current;
            // if repeated more than once, write the count digits
            if (count > 1) {
                string cntStr = to_string(count);
                for (char c : cntStr) {
                    chars[write++] = c;
                }
            }
        }
        // write is the new length after in-place compression
        return write;


    }
};
