//Question link --> https://www.geeksforgeeks.org/problems/maximum-sum-combination/1

//BRUTE FORCE
//T.C.==S.C.==O(N^2)
    vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B) {
        vector<int>v;
        for(int i = 0; i<N; i++){
            for(int j = 0; j<N; j++){
                v.push_back(A[i]+B[j]);
            }
        }  
        sort(v.begin(),v.end(),greater<int>());  
        vector<int>ans;
        for(int i = 0; i<K; i++)ans.push_back(v[i]); 
      
        return ans; 
    }

//OPTIMAL
/*
Time Complexity: O(NlogN), As we are sorting the array whose complexity is O(NlogN) and
we are also running a loop of size K and inside it we insert and take the element out 
from the priority queue and set whose complexity is O(logN), so total complexity becomes O(NlogN).
Space Complexity: O(N), As we have use priority queue, set and the ans vector to store 
the answer, So total space complexity becomes O(N).
*/
 vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B) {
        // code here
               // Sort both A and B
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        
        // Add sum and coordinates of their last element into maxH
        priority_queue<pair<int, pair<int, int>>> pq;
        pq.push({A[N-1] + B[N-1], {N - 1, N - 1}});
        
        // Visited set to avoid redundant iterations
        set<pair<int, int>> st;
        st.insert({N - 1, N - 1});
        
        // Generate k sum pairs and store
        vector<int> ans;
        while(K--){
            
            int sum = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            pq.pop();
            
            ans.push_back(sum);
            
            // Add Sum of diagonals
            if(st.find({i - 1, j}) == st.end()){
                pq.push({A[i - 1] + B[j], {i - 1, j}});
                st.insert({i - 1, j});
            }
            
            if(st.find({i, j - 1}) == st.end()){
                pq.push({A[i] + B[j - 1], {i, j - 1}});
                st.insert({i, j - 1});
            }
         
        }
        return ans;
    }
