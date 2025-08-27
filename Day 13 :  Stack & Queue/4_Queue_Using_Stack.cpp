//Question Link --> https://leetcode.com/problems/implement-queue-using-stacks/description/

//USING 1 Stack + 1 temp stack 
#include <stack>
using namespace std;

class MyQueue {
private:
    stack<int> st;

public:
    MyQueue() {}

    // Expensive push operation: O(n)
    void push(int x) {
        if (st.empty()) {
            st.push(x); // If the stack is empty, push directly
        } else {
                        stack<int> temp;
            // Move all elements from the main stack to the auxiliary stack
            while (!st.empty()) {
                temp.push(st.top());
                st.pop();
            }
            // Push the new element to the main stack (now at the bottom)
            st.push(x);
            // Move all elements back from the auxiliary stack to the main stack
            while (!temp.empty()) {
                st.push(temp.top());
                temp.pop();
            }

        }
    }

    // O(1) pop operation
    int pop() {
        if (st.empty()) return -1;
        int x = st.top();
        st.pop();
        return x;
    }

    // O(1) peek operation
    int peek() {
        if (st.empty()) return -1;
        return st.top();
    }

    // O(1) empty operation
    bool empty() {
        return st.empty();
    }
};


// USING 1 Stack + Auxillary Recursive SPACE
#include <stack>
using namespace std;

class MyQueue {
private:
    stack<int> st;

public:
    MyQueue() {}

    // Expensive push operation: O(n)
    void push(int x) {
        if (st.empty()) {
            st.push(x); // If the stack is empty, push directly
        } else {
            // Pop the top element, push the new element to the bottom, and restore the stack
            int top = st.top();
            st.pop();
            push(x); // Recursively push to the bottom
            st.push(top); // Restore the elements as we unwind
        }
    }

    // O(1) pop operation
    int pop() {
        if (st.empty()) return -1;
        int x = st.top();
        st.pop();
        return x;
    }

    // O(1) peek operation
    int peek() {
        if (st.empty()) return -1;
        return st.top();
    }

    // O(1) empty operation
    bool empty() {
        return st.empty();
    }
};





//USING TWO STACK
class MyQueue {
public:
    
        stack<int> input;
        stack<int> output;
    MyQueue() {
    }
    
    void push(int x) {
        // add element x to the input stack
        input.push(x);
    }
    
    int pop() { //making pop costly
        // if output not empty toh pop krdo directly
        // aur agar khali h toh wha input stack ka saman bhar do phir pop kro 
        
        if(output.empty()) // output array is empty
        {
            while(input.empty() == false)
            {
            output.push(input.top());
            input.pop();
            }
            
        } 

        //pop logic
        int  element = output.top();
        output.pop();

        return element;
    }
    
    int peek() {
        // here also similarly for top stack
        // if output not empty 
        // return output ka top
        // else khali h toh saara input daalne ka phir return maarne ka 
        
        if(output.empty())
        {
            while(input.empty() == false)
            {
                output.push(input.top());
                input.pop();
            }
            
        }

        return output.top();
    }
    
    bool empty() {
        // to check if any element present check both stacks
        // if they are empty or not 
        if(output.empty() == true && input.empty()) return true;
        else return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
