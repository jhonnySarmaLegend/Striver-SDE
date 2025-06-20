//Question Link --> https://leetcode.com/problems/largest-rectangle-in-histogram/description/

//T.C.=O(5N) , S.C.=O(3N)
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) 
    {
        int n=heights.size();
        stack<int>st;
        vector<int>pse(n);
        vector<int>nse(n);

        for(int i=0;i<n;i++)//PSE for element index
        {
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            pse[i]=st.empty()?-1:st.top(); // deafult --> -1 on left side
            st.push(i);
        }
        while(!st.empty()) st.pop();

        for(int i=n-1;i>=0;i--)//NSE for element index
        {
            while(!st.empty() && heights[st.top()]>=heights[i]) st.pop();
            nse[i]=st.empty()?n:st.top();  // deafult --> N on right side
            st.push(i);
        }

        int maxi=0;
        for(int i=0;i<n;i++)
        {
            maxi=max(maxi,heights[i]*(nse[i]-pse[i]-1)); // height * width
        }
        return maxi;
    }
};



//OPTIMAL APPROACH 2 --> STRIVER
int largestRectangleArea(vector < int > & histo) { // Function definition: Takes a reference to a vector of integers (histo), which represents the heights of the histogram bars. It returns an integer, which will be the maximum area found.
      stack < int > st; // Declares a stack of integers. This stack will store indices of histogram bars.
      int maxA = 0; // Initializes an integer variable 'maxA' to 0. This variable will store the maximum area found so far.
      int n = histo.size(); // Stores the number of bars in the histogram in integer 'n'.
      for (int i = 0; i <= n; i++) { // Loops through the histogram bars from index 0 up to and including 'n' (one past the last actual bar).
        while (!st.empty() && (i == n || histo[st.top()] >= histo[i])) { // Inner loop: Continues as long as the stack is not empty AND (we are at the end of the histogram OR the current bar's height is less than or equal to the height of the bar at the top of the stack).
          int height = histo[st.top()]; // Gets the height of the bar at the top of the stack (the bar being considered for an area calculation).
          st.pop(); // Removes the top element from the stack.
          int width; // Declares an integer variable 'width' to store the calculated width of the rectangle.
          if (st.empty()) // If the stack becomes empty after popping the top element.
            width = i; // The width extends from index 0 up to the current index 'i' (since there are no bars to its left that could limit it).
          else // If the stack is not empty after popping.
            width = i - st.top() - 1; // The width extends from the index of the new top of the stack + 1, up to the current index 'i' - 1. (i - (st.top() + 1)) = i - st.top() - 1
          maxA = max(maxA, width * height); // Updates 'maxA' if the newly calculated area (width * height) is greater than the current 'maxA'.
        } // End of while loop (processing popped bars).
        st.push(i); // Pushes the current bar's index 'i' onto the stack.
      } // End of for loop.
      return maxA; // Returns the maximum area found after processing all bars.
    }
