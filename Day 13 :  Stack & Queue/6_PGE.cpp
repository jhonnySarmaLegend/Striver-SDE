//Previous greater element
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
