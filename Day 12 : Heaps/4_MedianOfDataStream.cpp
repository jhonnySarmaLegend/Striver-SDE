//Question Link --> https://leetcode.com/problems/find-median-from-data-stream/description/

//BRUTE FORCE
class MedianFinder {
public:
    vector<int> med;

    MedianFinder() {}
    
    void addNum(int num) {
        med.push_back(num);
        sort(med.begin(), med.end());
    }
    
    double findMedian() {
        int n = med.size();
        if (n % 2 == 0) {
            return (med[n/2 - 1] + med[n/2]) / 2.0;
        } else {
            return med[n/2];
        }
    }
};

//OPTIMAL
/*
To efficiently support both the addition of numbers and the retrieval of the median,
we can utilize two heaps (priority queues):

A max-heap (to store the lower half of the numbers).
A min-heap (to store the upper half of the numbers).

The max-heap allows us to quickly access the largest element of the lower half,
while the min-heap allows us to quickly access the smallest element of the upper half.
Balancing these two heaps allows us to always retrieve the median in constant time 
after adding a new number.
*/

class MedianFinder 
{
    priority_queue<int> max_heap; // Max heap for the left half
    priority_queue<int, vector<int>, greater<int>> min_heap; // Min heap for the right half

public:
    MedianFinder() {}

    void addNum(int num) 
    {   //Initial pushing element into heaps
        if(max_heap.empty() || max_heap.top() >= num)
        {
            max_heap.push(num);
        }
        else
        {
            min_heap.push(num);
        }
        
        //Balance both heaps
        if(max_heap.size() > min_heap.size() + 1)
        {
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
        else if(min_heap.size() > max_heap.size() + 1)
        {
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
    }

    double findMedian() 
    {
        if (min_heap.size() == max_heap.size()) 
        {
            return (max_heap.top() + min_heap.top()) / 2.0; // Ensure floating-point division
        }
        return max_heap.size() > min_heap.size() ? max_heap.top() : min_heap.top();
    }
};


/*
Approach
Heap Initialization:

We initialize two heaps:
max_heap for the lower half of the numbers, implemented as a max-heap.
min_heap for the upper half of the numbers, implemented as a min-heap.
Adding a Number:

When a new number is added, we first decide whether to add it to the max_heap or min_heap:
If the max_heap is empty or the new number is less than or equal to the top of the max_heap, it should go to the max_heap.
Otherwise, it goes to the min_heap.
After adding the new number, we check the sizes of the heaps to ensure they remain balanced:
The max_heap can have at most one more element than the min_heap (the difference in size allows us to correctly calculate the median).
If the max_heap has more than one extra element, we move the top element from max_heap to min_heap.
Conversely, if the min_heap has more than one extra element, we move the top element from min_heap to max_heap.
Finding the Median:

To find the median:
If the sizes of both heaps are equal, the median is calculated as the average of the top elements from both heaps.
If max_heap has more elements, the median is simply the top element of the max_heap.
Complexity Analysis
Time Complexity:

Adding a number (addNum): O(log n), where n is the number of elements in the list. This is due to the logarithmic time for heap
insertion and possible adjustments on balance.
Finding the median (findMedian): O(1), since it only involves accessing the tops of the heaps.
Space Complexity:

O(n), where n is the number of elements added. We store all input numbers in the two heaps.
*/
