//Next Greater Element - Smaller element at stack top

//Variation 1 - 1 array (https://www.geeksforgeeks.org/problems/next-larger-element-1587115620/1)

/*
Given a circular integer array A, return the next greater element for every element in A. 
The next greater element for an element x is the first element greater than x that we come
across while traversing the array in a clockwise manner. If it doesn't exist, return -1 for this element.

Examples:

Example 1: 

Input: N = 11, A[] = {3,10,4,2,1,2,6,1,7,2,9}

Output: 10,-1,6,6,2,6,7,7,9,9,10

Explanation: For the first element in A ,i.e, 3, the greater element which comes next to it while 
traversing and is closest to it is 10. Hence,10 is present on index 0 in the resultant array. Now 
for the second element,i.e, 10, there is no greater number and hence -1 is it’s next greater element
(NGE). Similarly, we got the NGEs for all other elements present in A.  


Example 2:

Input:  N = 6, A[] = {5,7,1,7,6,0}

Output: 7,-1,7,-1,7,5
*/

/*BRUTE FORCE

//T.C.=O(N^2), S.C.=O(1)
input- arr[i
nge[n];
for(int i=0;i<n-1;i++){
 for(int j=i+1;j<n;j++){
  if(arr[j]>arr[i]){nge[i]=arr[j];break;}
  }
}
return nge;
*/

//Optimal Solution Using STACK - T.C.=O(N), S.C.=O(N)
vector<int> nextLargerElement(vector<int> &arr) {
    int n = arr.size();
    vector<int> res(n, -1);//when stack is empty puts res[n-1] as -1
    stack<int> stk;

    // Traverse the array from right to left
    for (int i = n - 1; i >= 0; i--) {

        // Pop elements from the stack that are less than or equal to the current element
        while (!stk.empty() &&  arr[i] >= stk.top()) {
            stk.pop();
        }

        // If the stack is not empty, the top element is the next greater element
        if (!stk.empty()) {
            res[i] = stk.top();
        }

        // Push the current element onto the stack
        stk.push(arr[i]);
    }

    return res;
}



//Variation 2 --> 2 Arrays  https://leetcode.com/problems/next-greater-element-i/description/
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // Map to store the next greater element for each element in nums2
        unordered_map<int, int> nextGreater;
        // Stack to keep track of the next greater element
        stack<int> st;

        // Traverse nums2 from right to left
        for (int i = nums2.size() - 1; i >= 0; --i) {
            // Pop elements from the stack that are less than or equal to the current element
            while (!st.empty() && st.top() <= nums2[i]) {
                st.pop();
            }
            // If the stack is not empty, the top element is the next greater element
            nextGreater[nums2[i]] = st.empty() ? -1 : st.top();
            // Push the current element onto the stack
            st.push(nums2[i]);
        }

        // Result vector for nums1
        vector<int> result(nums1.size());
        // Fill the result vector using the nextGreater map
        for (int i = 0; i < nums1.size(); ++i) {
            result[i] = nextGreater[nums1[i]];
        }

        return result;
    }
};


//Variation 3 - Circular array --> https://leetcode.com/problems/next-greater-element-ii/description/
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& a) {
        int n = a.size();
        vector<int>v(n,-1);

        stack<int>st;
        for(int i = 2*n - 1; i >= 0; i--)
        {
            // we pop out all elements smaller than current element
            while(!st.empty() && (a[i%n] >= st.top()))
            {
                st.pop();
            }

            // if stack is empty means no greater element is there
            // if not empty we make answer at that index equal to top element
            if(!st.empty() && (i < n))
            {
                v[i] = st.top();
            }

            st.push(a[i%n]);
        }

        return v;
    }
};
