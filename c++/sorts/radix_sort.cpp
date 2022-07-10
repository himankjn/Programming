#include <iostream>  
#include<math.h>
  
using namespace std;  
  
int getMax(int a[], int n) {  
   int max = a[0];  
   for(int i = 1; i<n; i++) {  
      if(a[i] > max)  
         max = a[i];  
   }  
   return max; //maximum element from the array  
}  
  
void countingSort(int a[], int n, int place) // function to implement counting sort  
{  
  int output[n + 1];  
  int count[10] = {0};    
  
  // Calculate count of elements  
  for (int i = 0; i < n; i++)  
    count[(a[i] / place) % 10]++;  
      
  // Calculate cumulative frequency  
  for (int i = 1; i < 10; i++)  
    count[i] += count[i - 1];  
  
  // Place the elements in sorted order  
  for (int i = n - 1; i >= 0; i--) {  
    output[count[(a[i] / place) % 10] - 1] = a[i];  
    count[(a[i] / place) % 10]--;  
  }  
  
  for (int i = 0; i < n; i++)  
    a[i] = output[i];  
}  
  
// function to implement radix sort  
void radixsort(int a[], int n) {  
   
  // get maximum element from array  
    int max = getMax(a, n);  
    
    //get max num of digits;
    int total_d=0;
    while(max){
        total_d++;
        max=max/10;
    }

    //count sort based on places;
    for (int d=0;d<=total_d;d++)  {
        int place=pow(10,d);
        countingSort(a, n, place);  
    }  
}
// function to print array elements  
void printArray(int a[], int n) {  
  for (int i = 0; i < n; ++i)   
    cout<<a[i]<<" ";  
}  
  
int main() {  
  int a[] = {171, 279, 380, 111, 135, 726, 504, 871, 112};  
  int n = sizeof(a) / sizeof(a[0]);
  radixsort(a, n);    
  printArray(a, n);  
  return 0;  
}  