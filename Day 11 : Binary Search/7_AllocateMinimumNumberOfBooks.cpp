//Question Link  -->   https://www.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1


//T.C. =O(NLogN) S.C.=O(1)

 // Function to check if it's possible to allocate books such that the maximum number of pages
 // assigned to a student is no more than 'mid'.
bool isPossible(vector<int>& arr, int k, int barrier) { //T.C.=O(N)
  int studentCount = 1;
  int pageSum = 0;
  for (int i = 0; i < arr.size(); i++) {
  if (pageSum + arr[i] <= barrier) {
  pageSum += arr[i];
  }
  else {
  studentCount++;
  if (studentCount > k || arr[i] > barrier) {
  return false;
  }
  pageSum = arr[i]; // Assign the current book to the new student
  }
  }
  return true;
 }
 
 // Function to find the minimum number of pages that should be allocated such that no student
 // exceeds that limit and all books are allocated.
 int allocateMinimumPages(vector<int>& arr, int k) {
  if (k > arr.size()) {
  return -1; // Not possible to allocate if number of students is greater than number of books
  }
 
  int start = *max_element(arr.begin(), arr.end());
  int end = accumulate(arr.begin(), arr.end(), 0); // Sum of all pages
  int ans = -1;
 
  while (start <= end) {//T.C.=O(LogN)
  int mid = start + (end - start) / 2; // To prevent integer overflow
 
  if (isPossible(arr, k, mid)) {
  ans = mid;  // Potential answer, try to minimize further
  end = mid - 1; // Look for a smaller value in the left half
  } else {
  start = mid + 1; // Need to increase the 'mid' value, search in the right half
  }
  }
  return ans;
 }
