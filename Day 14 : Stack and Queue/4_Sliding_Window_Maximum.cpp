//Question Link --> https://leetcode.com/problems/sliding-window-maximum/description/

//BRUTE FORCE --> 2 loops
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
      int n=nums.size();
      vector<int> ans;
      for(int i=0;i<=n-k;i++){
        int maxi=nums[i];
        for(int j=i;j<i+k;j++){
            maxi=max(maxi,nums[j]);
        }
        ans.push_back(maxi);
      }
      return ans;

    }
};

//OPTIMAL --> Dequeue
class Solution {
public:
vector < int > maxSlidingWindow(vector < int > & nums, int k) {
  deque < int > dq; // Initialize a double-ended queue (deque) to store indices. 
                    // This deque will maintain indices of elements in descending order of their values.
                    // The front of the deque will always hold the index of the maximum element in the current window.
  
  vector < int > ans; // Initialize a vector to store the maximum value of each sliding window.

  // Iterate through the input array 'nums' with index 'i'.
  // This loop processes each element, effectively simulating the sliding window moving one step at a time.
  for (int i = 0; i < nums.size(); i++) {
    // Check if the front element of the deque is out of the current window.
    // An element at dq.front() is no longer in the window if its index is 'i - k'.
    // If it's out of bounds, remove it from the front of the deque.
    if (!dq.empty() && dq.front() == i - k) {
      dq.pop_front(); 
    }

    // While the deque is not empty and the element at the back of the deque is less than or equal to the current element (nums[i]),
    // remove elements from the back. This ensures that the deque always stores indices of elements
    // in decreasing order of their values. If a new element is greater, previous smaller elements become irrelevant for being the maximum.
    while (!dq.empty() && nums[dq.back()] <= nums[i]) { // Changed < to <= for strict decreasing order, although < also works for correctness.
                                                       // <= is generally preferred as it removes equal elements earlier, keeping only the rightmost equal element if multiple exist.
      dq.pop_back(); 
    }

    // Add the current element's index to the back of the deque.
    dq.push_back(i);

    // Once the window has processed at least 'k' elements (i.e., 'i' is 'k-1' or greater),
    // the first valid window has been formed.
    // The maximum element for the current window is always the element at the index stored at the front of the deque.
    if (i >= k - 1) {
      ans.push_back(nums[dq.front()]); // Add this maximum value to our result vector.
    }
  }
  
  return ans; // Return the vector containing the maximums of all sliding windows.
}
};
