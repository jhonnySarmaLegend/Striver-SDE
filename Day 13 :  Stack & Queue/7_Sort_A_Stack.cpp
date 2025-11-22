// Variation 1 --> https://www.geeksforgeeks.org/problems/sort-a-stack/1
/*
Given a stack, the task is to sort it using recursion.

Example: 

Input: [3 2 1]
Output: [3 2 1]
Explanation: The given stack is sorted know 3 > 2 > 1

Input: [11 2 32 3 41]
Output: [41 32 11 3 2]
*/
// Using PQ

/*The structure of the class is
class SortedStack{
public:
    stack<int> s;
    void sort();
};
*/

/* The below method sorts the stack s
you are required to complete the below method */
void SortedStack ::sort() {
    // Your code he
    priority_queue<int,vector<int>,greater<int>> pq;//(s.begin(),s.end());--> no begin() end() function for stack
    
    while(!s.empty()){
        pq.push(s.top());
        s.pop();
    }
    
    while(!pq.empty()){
        s.push(pq.top());
        pq.pop();
    }
}

//USING RECURSION --> T.C. = O(N^2) , S.C.=O(N)
// Refer Love babbar video --> https://www.youtube.com/watch?v=BmZnJehDzyU&t=3175s - 50min around
void sortedInsert(stack<int> &s, int x) {
    if (s.empty() ||  s.top()<x) {
        s.push(x);
        return;
    }
    int temp = s.top();
    s.pop();
    sortedInsert(s, x);
    s.push(temp);
}

void sort(stack<int> &s) {
    if (!s.empty()) {
        int x = s.top();
        s.pop();
        sort(s);
        sortedInsert(s, x);
    }
}

/* REVERSE A stack  */ --> T.C. = O(N^2) , S.C.=O(N)
void insertBottom(stack<int> &st,int ele){
        if(st.empty()){  //base case
            st.push(ele);
            return;
        }
        
        int num=st.top();st.pop();
        insertBottom(st,ele);
        st.push(num); 
    }
  
    void Reverse(stack<int> &st) {
        if(st.empty())return;//base case
        
        int num=st.top();st.pop();
        Reverse(st);
        insertBottom(st,num);
    }

// SORT A STACK USING STACK--> --> T.C. = O(N) , S.C.=O(N) --> MOST OPTIMAL
void sortStack(stack<int> &s) {
    stack<int> auxStack; // Auxiliary stack

    while (!s.empty()) {
        int temp = s.top(); // Pop from the original stack
        s.pop();

        // Move elements from auxiliary stack back to original stack
        // until the correct position for `temp` is found
        while (!auxStack.empty() && auxStack.top() > temp) {
            s.push(auxStack.top());
            auxStack.pop();
        }

        // Push `temp` into the auxiliary stack
        auxStack.push(temp);
    }

    // Transfer elements from auxiliary stack back to original stack
    // to get sorted order (largest at the top)
    while (!auxStack.empty()) {
        s.push(auxStack.top());
        auxStack.pop();
    }
}
