/*
  Question Link --> https://www.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1

  [Expected Approach] Greedy Approach, Sorting and Priority Queue – O(n * log(n)) Time and O(n) Space
  
  Step by Step implementation:

Store jobs as pairs of (Deadline, Profit).
Sort Jobs Based on Deadline: We sort the jobs array in ascending order of deadline so that we prioritize jobs with earlier deadlines are considered first.
For each job (deadline, profit) in the sorted list:
If the job can be scheduled within its deadline (i.e., the number of jobs scheduled so far is less than the deadline), push its profit into the heap.
If the heap is full (equal to deadline), replace the existing lowest profit job with the current job if it has a higher profit.
This ensures that we always keep the most profitable jobs within the available slots.
Traverse through the heap and store the total profit and the count of jobs.

*/

    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
         int n = deadline.size();
    vector<int> ans = {0, 0};

    // pair the profit and deadline of
    // all the jos together
    vector<pair<int, int>> jobs;
    for (int i = 0; i < n; i++) {
        jobs.push_back({deadline[i], profit[i]});
    }

    // sort the jobs based on deadline
    // in ascending order
    sort(jobs.begin(), jobs.end());

    // to maintain the scheduled jobs based on profit (min heap)
    priority_queue<int, vector<int>, greater<int>> pq;

    for (const auto &job : jobs) {
        
        // if job can be scheduled within its deadline --> different deadline
        if (job.first > pq.size())
            pq.push(job.second);
        
        // Replace the job with the lowest profit --> same deadline
        else if (!pq.empty() && pq.top() < job.second) {
            pq.pop();
            pq.push(job.second);
        }
    }

    while (!pq.empty()) {
        ans[1] += pq.top();
        pq.pop();
        ans[0]++;
    }

    return ans;
    }
