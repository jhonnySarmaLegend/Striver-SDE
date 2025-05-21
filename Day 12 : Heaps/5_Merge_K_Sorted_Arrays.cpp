//Question Link --> https://www.geeksforgeeks.org/problems/merge-k-sorted-arrays/1

//BRUTE FORCE - TLE
    vector<int> mergeKArrays(vector<vector<int>> arr, int K) {
        // code here
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0;i<arr.size();i++){
            for(int j=0;j<arr[0].size();j++)pq.push(arr[i][j]);
        }
        vector<int> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }


//OPTIMAL
/*
Time Complexity: O(N log k) Here N is total number of elements in all input arrays.
Auxiliary Space: O(k)
*/
// A pair of pairs, first element is going to
// store value, second element index of array
// and third element index in the array.
typedef pair<int, pair<int, int> > ppi;

// This function takes an array of arrays as an
// argument and all arrays are assumed to be
// sorted. It merges them together and prints
// the final sorted output.
vector<int> mergeKArrays(vector<vector<int> > arr)
{
    vector<int> output;

    // Create a min heap with k heap nodes. Every
    // heap node has first element of an array
    priority_queue<ppi, vector<ppi>, greater<ppi> > pq;

    for (int i = 0; i < arr.size(); i++)
        pq.push({ arr[i][0], { i, 0 } }); // i,j

    // Now one by one get the minimum element
    // from min heap and replace it with next
    // element of its array
    while (!pq.empty()) {
        ppi curr = pq.top();
        pq.pop(); // min element out

        // i ==> Array Number
        // j ==> Index in the array number
        int i = curr.second.first; //arrayIndex 
        int j = curr.second.second;//elementIndex 

        output.push_back(curr.first);

        //  pushing next elements columnwise
        if (j + 1 < arr[i].size())
            pq.push({ arr[i][j + 1], { i, j + 1 } });
    }

    return output;
}
