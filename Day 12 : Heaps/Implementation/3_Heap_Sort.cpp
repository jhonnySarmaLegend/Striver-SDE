// 1. Heapify the array  --> 2. HeapSort  by plcing largest element at last decrement the size and againg heapify and repeat

void heapify(int arr[], int n, int i) {
    int largest = i;
    int L = 2*i, R = 2*i + 1;

    // 1) Find the largest among i, L, R (if within [1..n])
    if (L <= n && arr[largest] < arr[L]) largest = L;
    if (R <= n && arr[largest] < arr[R]) largest = R;

    // 2) If a child is larger, swap and recurse
    if (largest != i) {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

      void heapSort(int arr[],int n){
          int size=n;
          while(size>1){
              swap(arr[size],arr[1]);// arr[1] is the max element 
              size--;
              heapify(arr,size,1);
          }
      }



void main(){


    int arr[6]={-1,2,9,7,4,1};
    int n=5;
// for each leaf node need to do heapify to make it the heap
     for(int i=n/2;i>0;i--){
         heapify(arr,n,i);
     }
   //  for(auto it:arr)cout<<it<<" ";cout<<"\n";

    heapSort(arr,n);
    
   // for(auto it:arr)cout<<it<<" ";cout<<"\n";


}
