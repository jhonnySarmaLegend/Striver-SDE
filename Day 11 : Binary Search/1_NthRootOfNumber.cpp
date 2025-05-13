//nRoot(3,27)=3 since 3*3*3=27 , 3 root 27

//USING  Binary Search

/*
Time Complexity: O(logN), N = size of the given array.
Reason: We are basically using binary search to find the minimum.

Space Complexity: O(1)
Reason: We have not used any extra data structures, this makes space complexity, even in the worst case as O(1).
*/
#include <iostream>
using namespace std;

int nthRoot(int n, int m) {
    if (n == 1) {
        return m;
    }

    long long int low = 1LL, high = m, mid;
    long long int ans = -1;
    while (low <= high) {
        mid = (low + high) / 2;
        long long int x = mid;
        for (int i = 1; i < n; i++) {
            x *= mid;
            if (x > m * 1LL)
                break;
        }
        if (x == m * 1LL) {
            ans = mid;
            break;
        } else if (x > m)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return int(ans);
}

int main() {
    int n = 1, m = 14; 
    
    int result = nthRoot(n, m);
    
    cout << result << endl;
    
    return 0;
}
