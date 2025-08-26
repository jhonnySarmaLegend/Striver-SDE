// Link --> https://leetcode.com/problems/kth-largest-element-in-a-stream/description/

class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>>pq;// min heap --> at kth place will be kth largest element
    int K=0;// global variable to pass k
    KthLargest(int k, vector<int>& nums) {
        K=k;
        for(auto it:nums){
            pq.push(it);
            if(pq.size()>k)pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>K)pq.pop();// global variable to pass k here
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
