//Fibonacci number

//#Recursive Solution
// Function to calculate the nth Fibonacci number recursively
int fibonacci(int n) {
    if (n <= 1) {
        return n; // Base case: return n if n is 0 or 1
    }
    return fibonacci(n - 1) + fibonacci(n - 2); // Recursive case
}

//1.Tabulation
int fibonacciTab(int n) {
    if (n <= 1) {
        return n; // Base case
    }
    vector<int> table(n + 1); // Create a table to store Fibonacci numbers
    table[0] = 0; // F(0) = 0
    table[1] = 1; // F(1) = 1

    // Build table in bottom-up manner
    for (int i = 2; i <= n; ++i) {
        table[i] = table[i - 1] + table[i - 2];
    }
    return table[n]; // Return the nth Fibonacci number
}


//2.Memoization --> define array & check if previosly solved & recursion
//store value which has already been computed to avoid repeated computation of same things which has already been computed
#include <iostream>
#include <cstring> // For memset

using namespace std;

int fibonacciMemo(int n, int dp[]) {
    if (n <= 1) {
        return n; // Base case
    }
    // Check if value is already computed
    if (dp[n] != -1) {
        return dp[n];
    }
    // Store and return the computed value
    dp[n] = fibonacciMemo(n - 1, dp) + fibonacciMemo(n - 2, dp);
    return dp[n];
}

int main() {
    int n;
    cout << "Enter a positive integer: ";
    cin >> n;

    if (n < 0) {
        cout << "Please enter a non-negative integer." << endl;
    } else {
        int dp[n + 1]; // Static array for memoization
        memset(dp, -1, sizeof dp); // Initialize all entries to -1
        
        cout << "Fibonacci number at position " << n << " is " << fibonacciMemo(n, dp) << endl;
    }

    return 0;
}



// DP as local variable pass in dp 

// Function to compute Fibonacci number using memoization (top-down DP)
// dp is now passed as a reference to a std::vector
int fibonacciMemo(int n, vector<int>& dp) {
    if (n <= 1) {
        return n; // Base case: F(0) = 0, F(1) = 1
    }
    
    // Check if value is already computed
    if (dp[n] != -1) {
        return dp[n];
    }
    
    // Store and return the computed value
    dp[n] = fibonacciMemo(n - 1, dp) + fibonacciMemo(n - 2, dp);
    return dp[n];
}

int main() {
    int n;
    cout << "Enter a non-negative integer: "; // Clarified prompt
    cin >> n;

    if (n < 0) {
        cout << "Please enter a non-negative integer." << endl;
    } else {
        // Use std::vector for dp, initialized with size n + 1 and all values to -1
        vector<int> dp(n + 1, -1); 
        
        cout << "Fibonacci number at position " << n << " is " << fibonacciMemo(n, dp) << endl;
    }

    return 0;
}


/*
memset: This is a C-style function used to initialize a block of memory with a specific byte value.

Purpose: To quickly set all bytes of a contiguous memory block to a certain value (like 0, -1, or any character representation).

Syntax: memset(pointer, value, size_in_bytes);

Limitations:

It operates on bytes. This means it's generally safe and reliable for initializing arrays of char or setting all bytes to 0 for any integer type.

For int types (or any multi-byte type) to values other than 0 or -1, memset is dangerous and incorrect. For example, memset(arr, 5, sizeof(arr)) will 
not set each integer in arr to 5. Instead, it will set each byte of each integer to 5, resulting in a very large, incorrect integer value. This is because 5 (0x05) is repeated across the bytes of an int.

It cannot initialize std::vectors directly, as std::vector is an object, not a raw C-style array. You would typically use std::fill or the constructor for std::vector.

"Passing the local variable" (specifically, passing std::vector<int>& dp)

This refers to the mechanism by which you make a local variable (like dp in main) accessible to a function (fibonacciMemo).

Purpose: To share data between different parts of your program (e.g., between main and a helper function) without making it a global variable.

Mechanism (in your Fibonacci example):

std::vector<int> dp(n + 1, -1);: Here, dp is a local variable in main. It's a std::vector object that is automatically initialized to n+1 elements, all set to -1. 
This initialization is performed by the std::vector's constructor.

fibonacciMemo(n, dp);: When you call the function, dp is passed.

int fibonacciMemo(int n, std::vector<int>& dp): The & indicates that dp is passed by reference. This means fibonacciMemo gets a direct link to the dp vector in main. Any modifications to dp inside fibonacciMemo directly affect the original dp in main. This is essential for memoization to work across recursive calls.
*/
