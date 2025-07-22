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
