//Question Link-->https://www.geeksforgeeks.org/problems/reverse-a-stack/1

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
