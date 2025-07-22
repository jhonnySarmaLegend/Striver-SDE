/* heap = complete binary tree + heap order property
          every level completely filled except the last level and node pushed from left to right + child value related to parent

          min heap --> parent values < child values 
          max heap --> parent values > child values 

          1 based indexing(0 index is left blank) -->  parent = i , left child = 2i , right child = 2i + 1

          lly, 0-based indexing --> 
          
          INSERTION --> add to the array last and take the element to its correct position
          DELETION  --> (delete root node always) --> put last node in first position --> delete last node --> take root node to its correct position
                        

          
*/

// Doing for MAX Heap

// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

class Heap{
    public:
    
      int arr[100];
      int size;
      
      Heap(){
          arr[0]=-1;
          size=0;
      }
      
      //T.C.=O(logN)
      void insert(int value){
          size=size+1;
          int index=size;
          arr[size]=value;
          
          while(index>1){
              int parent=index/2;
              //MAX Heap
              if(arr[parent]<arr[index]){
                  swap(arr[parent],arr[index]);
                  index=parent;
              }
              else return;
          }
      }
      
       //T.C.=O(logN)
      void deleteEle(){
          if(size==0){
              cout<<"UnderFlow!!!";
              return;
          }
          
          arr[1]=arr[size];//step1
          size--;//step2
          
          int i=1;//step 3
          while(i<size){
              int leftIndex=2*i;
              int rightIndex=(2*i) + 1;
              
              if(i<size && arr[i]<arr[leftIndex]){
                  swap(arr[i],arr[leftIndex]);
                  i=leftIndex;
              }
              
              else if(i<size && arr[i]<arr[rightIndex]){
                  swap(arr[i],arr[rightIndex]);
                  i=rightIndex;
              }
              
              else return;
              
          }
          
      }
      
      
      void print(){
          for(int i=1;i<=size;i++)cout<<arr[i]<<" ";
          cout<<endl;
      }
};

int main() {
    Heap h;
    h.insert(1);
    h.insert(5);
    h.insert(3);
    h.insert(4);
    h.insert(20);
    h.insert(21);
    h.insert(19);
    h.insert(250);

    h.print();
    
    h.deleteEle();
    h.print();


    return 0;
}
 
