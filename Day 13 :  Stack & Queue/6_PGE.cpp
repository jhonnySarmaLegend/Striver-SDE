//Previous greater element
vector<int> previousGreaterElement(vector<int> &arr) {
    int n = arr.size();
    vector<int> res(n, -1); // Initialize result with -1
    stack<int> stk;

    // Traverse the array from left to right
    for (int i = 0; i < n; i++) {

        // Pop elements from the stack that are less than or equal to the current element
        while (!stk.empty() && arr[i] >= stk.top()) {
            stk.pop();
        }

        // If the stack is not empty, the top element is the previous greater element
        if (!stk.empty()) {
            res[i] = stk.top();
        }

        // Push the current element onto the stack
        stk.push(arr[i]);
    }

    return res;
}
