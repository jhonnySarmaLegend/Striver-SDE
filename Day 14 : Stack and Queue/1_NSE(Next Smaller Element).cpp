//NSE --> loop right to left

vector<int> findNextSmallerElement(const vector<int>& arr) {
    int n = arr.size();
    vector<int> result(n);
    stack<int> s;
    // Iterate from right to left
    for (int i = n - 1; i >= 0; --i) {
        // While the stack is not empty and the top element is greater than or equal to the current element
        while (!s.empty() && s.top() >= arr[i]) { //similar to NGE >= changed with <=
            s.pop();
        }
        // If the stack becomes empty, there is no smaller element to the right
        if (s.empty()) {
            result[i] = -1; // Or some other indicator for no smaller element
        } else {
            // The top of the stack is the next smaller element to the right
            result[i] = s.top();
        }
        // Push the current element onto the stack
        s.push(arr[i]);
    }
    return result;
}


//PSE --> loop left to right
vector<int> findPreviousSmallerElement(const vector<int>& arr) {
    int n = arr.size();
    vector<int> result(n);
    stack<int> s;

    // Iterate from left to right
    for (int i = 0; i < n; ++i) {
        // While the stack is not empty and the top element is greater than or equal to the current element
        while (!s.empty() && s.top() >= arr[i]) {
            s.pop();
        }

        // If the stack becomes empty, there is no smaller element to the left
        if (s.empty()) {
            result[i] = -1; // Or some other indicator for no smaller element
        } else {
            // The top of the stack is the previous smaller element to the left
            result[i] = s.top();
        }

        // Push the current element onto the stack
        s.push(arr[i]);
    }

    return result;
}
