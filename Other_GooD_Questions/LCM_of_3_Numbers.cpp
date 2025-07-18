/*  Question Link --> https://www.geeksforgeeks.org/problems/lcm-triplet1501/1


//T.C.=S.C.=O(N) Pattern Based
[Efficient Approach] Pattern-Based Conditional Optimization - O(1) Time and O(1) Space
This approach uses pattern-based conditional checks to find the maximum LCM for any three numbers ≤  n.
If n is odd, then n*(n-1)*(n-2) yields the highest LCM. If n is even and not divisible by 3, the optimal
triplet is n*(n-1)*(n-3). Otherwise, we use (n-1)*(n-2)*(n-3) to avoid common divisors. This avoids computing
actual LCMs by relying on mathematical patterns for efficiency.
*/


int lcmTriplets(int n){
    
    int ans;
    if(n < 3) ans = n;
    
    // If n is odd, the product of the top 3 numbers gives maximum LCM
    else if(n % 2){
        ans = n * (n - 1) * (n - 2);
    }
    
    // If n is even and not divisible by 3, use n, n-1, n-3
    else if(n % 3){
        ans = n * (n - 1) * (n - 3);
    }
    
    // If n is even and divisible by 3, use n-1, n-2, n-3 to avoid common divisors
    else{
        ans = (n - 1) * (n - 2) * (n - 3);
    }

    return ans;
}



//BRUTE FORCE
// using Euclidean Algorithm
int gcd(int a, int b) {
    if (a == 0) return b;
    return gcd(b % a, a);
}

// Function to compute LCM 
// (Least Common Multiple) of two numbers
int lcm(int a, int b) {
    int product = a * b;
    return product / gcd(a, b);
}

// Function to compute the maximum LCM among all triplets 
// (i, j, k) such that 1 <= i <= j <= k <= n
int lcmTriplets(int n) {
    
    int maxLCM = 1;

    // Iterate over all combinations of triplets (i, j, k)
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            for (int k = j; k <= n; k++) {
                
                // Calculate LCM of the triplet and update maximum
                int currentLCM = lcm(lcm(i, j), k);
                maxLCM = max(maxLCM, currentLCM);
            }
        }
    }

    return maxLCM;
}
