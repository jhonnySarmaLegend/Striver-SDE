// Array to heap array
// 1 based indexing where arr[0]=-1
// leaf node --> (n/2)+1  to n  index


// MAX Heap --> 1 based indexing

void heapify(int arr[],int n,int i){
          int largest=i;
          int leftIndex=2*i; 
          int rightIndex=2*i + 1;
          
          if(leftIndex<=n && arr[largest]<arr[leftIndex])largest=leftIndex; // for min heap  arr[smallest]>arr[leftIndex]
          
          if(rightIndex<=n && arr[largest]<arr[rightIndex])largest=rightIndex; // for min heap  arr[smallest]>arr[rightIndex]
          
          if(largest!=i){
              swap(arr[largest],arr[i]);
              heapify(arr,n,largest);
          }
          
          
      }

void main(){

int arr[6]={-1,2,9,7,4,1};
    int n=5;
// For each leaf node in the heap
    for(int i=n/2;i>0;i--){
        heapify(arr,n,i);
    }

}


// 1-based indexing --> 2*i , 2*i + 1  for 0-based indexing 2*i + 1, 2*i + 2

// min heap left<n


