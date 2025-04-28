/*
  Question Link --> https://www.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1
 
  Approach:

An efficient solution is to use the Greedy approach. 

The basic idea of the greedy approach is to calculate the ratio profit/weight for each item and sort the item on the basis of this ratio. Then take the item with the highest ratio and add them as much as we can (can be the whole element or a fraction of it).


This will always give the maximum profit because, in each step it adds an element such that this is the maximum possible profit for that much weight.

T.C.=O(NLogN) , S.C. =O(N)

*/

 public:
       // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // vector<pair<value, weight>> items;
        vector<pair<int, int>> items;
        for (int index = 0; index < val.size(); index++)
        {
            items.push_back({val[index], wt[index]});
        }
        sort(items.begin(), items.end(), customComparator);
        int currentWeight = 0;
        double finalValue = 0.0;
        for (int index = 0; index < val.size(); index++)
        {
            if (currentWeight + items[index].second <= capacity)
            {
                currentWeight += items[index].second;
                finalValue += items[index].first;
            }
            else
            {
                int remain = capacity - currentWeight;
                finalValue += (items[index].first / (double)items[index].second) * (double)remain;
                break;
            }
        }
        return finalValue;
    }
    // based on val/wt ratio descending 
    bool static customComparator(pair<int, int> &a, pair<int, int> &b)
    {
        double result1 = (double)a.first / (double)a.second;
        double result2 = (double)b.first / (double)b.second;
        return result1 > result2;
    }
