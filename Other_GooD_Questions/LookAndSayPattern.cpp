//Question Link -> https://www.geeksforgeeks.org/problems/decode-the-pattern1138/1
#include <bits/stdc++.h>
using namespace std;

// Helper function to generate the next term 
// in the sequence from the previous one
string nextTerm(string& prev) {
    string curr = "";
    int count = 1;
    
    for (int i = 1; i < prev.length(); i++) {
        
        // Keep Counting while same
        if (prev[i] == prev[i - 1]) {
            count++;
            
        // If a different character found, appemd
        // the count of previous character along
        // with the character itself
        } else {
            curr += to_string(count) + prev[i - 1];
            count = 1;
        }
    }
    
    // Append the last character's count and the
    // last character
    curr += to_string(count) + prev.back();
    
    return curr;
}

// Recursive function to return the nth term
string countAndSay(int n) {
    
    // Base case
    if (n == 1)
        return "1";
    
    // Recursively get the previous term
    string prev = countAndSay(n - 1);
    
    // Get the n-th term using (n-1)th
    return nextTerm(prev);
}

// Driver code
int main() {
    int n = 5;
    cout << countAndSay(n) << endl;
    return 0;
}
