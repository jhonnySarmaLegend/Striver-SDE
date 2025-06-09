//Question Link-->https://www.geeksforgeeks.org/problems/reverse-a-stack/1
/*
Time Complexity: O(n*n) Since we need to call fun() and it recursively call insert_at_bottom which is again calling itself for recursion, hence O(n*n)
Space Complexity: O(1) We need no extra stack for answer , hence O(1), but for recursion calls it needs o(n) auxiliary space.
*/
void insertBottom(stack<int> &st,int ele){
        //base case
        if(st.empty()){
            st.push(ele);
            return;
        }
        
        int num=st.top();
        st.pop();
        
        insertBottom(st,ele);
        
        st.push(num);
        
    }
  
    void Reverse(stack<int> &st) {
        //base case
        if(st.empty())return;
        
        int num=st.top();
        st.pop();
        
        Reverse(st);
        
        insertBottom(st,num);
    }


//OPtimal 
//T.C.==S.C.=O(N)
  void Reverse(stack<int> &st) {
        queue<int> q;
        while(!st.empty()){
            q.push(st.top());
            st.pop();
        }
        while(!q.empty()){
            st.push(q.front());
            q.pop();
        }
  }
