//Question Link --> https://leetcode.com/problems/kth-largest-element-in-an-array/description/

int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(),nums.end()); // maxheap
        for(int i=1;i<k;i++)pq.pop();
        return pq.top();
    }
