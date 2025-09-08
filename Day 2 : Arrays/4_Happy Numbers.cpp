//Link --> https://leetcode.com/problems/happy-number/description/


//OPTIMAL -->  tortoise method
// T.C.=O(logN), S.C.=O(1)
class Solution {
public:
    int getNext(int number) {
        int totalSum = 0;
        while (number > 0) {
            int digit = number % 10;
            totalSum += digit * digit;
            number /= 10;
        }
        return totalSum;
    }
    bool isHappy(int n) {
        int slow = n;          // Tortoise
        int fast = getNext(n); // Hare
        // Detect cycle or convergence to 1
        while (fast != 1 && slow != fast) {
            slow = getNext(slow);        // Move tortoise one step
            fast = getNext(getNext(fast)); // Move hare two steps
        }
        // If fast converges to 1, it's a happy number
        return fast == 1;
    }
};




// BRUTE FORCE
/*
Overall Time Complexity:

Each iteration calls getNext, which is O(log n).
The number of iterations is also O(log n).
Thus, the total time complexity is O(log n) * O(log n) = O((log n)^2).

S.C.=O(LogN)
*/
class Solution {
public:
       int getNext(int number) {
        int totalSum = 0;
        while (number > 0) {
            int digit = number % 10;
            totalSum += digit * digit;
            number /= 10;
        }
        return totalSum;
    }
    bool isHappy(int n) {
        unordered_set<int> seen; // To detect cycles
        while (n != 1 && seen.find(n) == seen.end()) {
            seen.insert(n);
            n = getNext(n);
        }
        return n == 1;
    }
};




