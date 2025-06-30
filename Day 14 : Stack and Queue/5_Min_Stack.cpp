//Question Link --> https://leetcode.com/problems/min-stack/description/

//Using 2 stacks
// T.C.=O(1) , S.C.=O(2N)
class MinStack {
private:
    stack<int> s;
    stack<int> minS;

public:
    MinStack() {}

    void push(int val) {
        s.push(val);
        if (minS.empty()) {
            minS.push(val);
        } else {
            minS.push(min(val, minS.top()));
        }
    }

    void pop() {
        s.pop();
        minS.pop();
    }

    int top() {
        return s.top();
    }

    int getMin() {
        return minS.top();
    }
};



// Do this
//Bit Optimized
// T.C.=O(1) , S.C.=O(N)
class MinStack {
public:
 stack < pair < int, int >> st;//(ele,minTillNow)
 
    MinStack() {
        
    }
   void push(int x) {
      int min;
      if (st.empty()) {
        min = x;
      } else {
        min = std::min(st.top().second, x);
      }
      st.push({x,min});
    }

  void pop() {
    st.pop();
  }

  int top() {
    return st.top().first;
  }

  int getMin() {
    return st.top().second;
  }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */


