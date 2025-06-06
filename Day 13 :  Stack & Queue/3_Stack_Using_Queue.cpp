//Question Link --> https://leetcode.com/problems/implement-stack-using-queues/description/

class MyStack {
private:
    queue<int> q;
public:
        MyStack() {
        
    }
    
    void push(int x) {
        // Get the current size of the queue
        int s = q.size();
        
        // Push the new element to the queue
        q.push(x);
        
        // Move all previous elements to the back of the queue to maintain stack order
        for (int i = 0; i < s; i++) {
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        // Pop the front element, which is the top of the stack
        int topElement = q.front();
        q.pop();
        return topElement;
    }
    
    int top() {
        // Return the front element without removing it
        return q.front();
    }
    
    bool empty() {
        // Check if the queue is empty
        return q.empty();
    }
    
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
