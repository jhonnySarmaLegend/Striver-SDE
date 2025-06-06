//Question Link --> https://leetcode.com/problems/implement-queue-using-stacks/description/

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
        int element = 0;
        if(output.empty() == false)     
        {

        element = output.top(); 
         output.pop();

        }
        else
        {
            while(input.empty() == false)
            {
            output.push(input.top());
            input.pop();
            }
            element = output.top();
            output.pop();
        } 

        return element;
    }
    
    int peek() {
        // here also similarly for top stack
        // if output not empty 
        // return output ka top
        // else khali h toh saara input daalne ka phir return maarne ka 
        if(output.empty() == false)
        {
            return output.top();
        }
        else
        {
            while(input.empty() == false)
            {
                output.push(input.top());
                input.pop();
            }
            return output.top();
        }
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
 */
