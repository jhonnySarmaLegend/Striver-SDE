// 1. Heapify the array  --> 2. HeapSort  by plcing largest element at last decrement the size and againg heapify and repeat

void heapify(int arr[],int n,int i){
          int largest=i;
          int leftIndex=2*i;
          int rightIndex=2*i + 1;
          
          if(leftIndex<=n && arr[largest]<arr[leftIndex])largest=leftIndex;
          
          if(rightIndex<=n && arr[largest]<arr[rightIndex])largest=rightIndex;
          
          if(largest!=i){
              swap(arr[largest],arr[i]);
              heapify(arr,n,largest);
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
