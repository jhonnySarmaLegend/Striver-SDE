//Question Link --> https://www.geeksforgeeks.org/problems/kth-smallest-number-in-multiplication-table/1

//BRUTE TLE -->PQ
int kthSmallest(int m, int n, int k) {
        code here
        priority_queue<int,vector<int>,greater<int>> pq;
        
        for(int i=1;i<=m;i++){
             for(int j=1;j<=n;j++)pq.push(i*j);
        }
        k--;
        while(k--)pq.pop();
        
        return pq.top();
}

//OPTIMAL Binary Search -->  T.C. = O(M*log(M*N))

// Count how many numbers in the multiplication table are less than or equal to val
    int count(int val, int m, int n) {
        int cnt = 0;
        for (int i = 1; i <= m; ++i) {
            cnt += min(val / i, n); // Number of elements <= val in row i
        }
        return cnt;
    }

    int kthSmallest(int m, int n, int k) {
        int l = 1, h = m * n;
        int ans = 0; // Initialize ans
        
        // Binary search to find the kth smallest number
        while (l <= h) {
            int mid = (l + h) / 2;
            if (count(mid, m, n) < k) {
                l = mid + 1; // Move to higher values
            } else {
                ans = mid;    // Potential answer
                h = mid - 1;  // Move to lower values
            }
        }

        // Return the kth smallest number
        return ans; 
    }
