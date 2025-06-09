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

//USING RECURSION
// Refer Love babbar video --> https://www.youtube.com/watch?v=BmZnJehDzyU&t=3175s - 50min around
void sortedInsert(stack<int> &s, int x) {
    if (s.empty() || x > s.top()) {
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
