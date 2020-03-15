/*
* This program accept size of the array(n) in the first line.
* Then total of n numbers and then the unit of rotation(d).
* This is block swap algorithm of array left rotation.
*/

#include <bits/stdc++.h> 
using namespace std;

void printArray(int a[], int size){
  for(int i = 0; i < size; i++){
    cout << a[i] << " ";
  }
}
/*This function swaps d elements starting at index fi  
with d elements starting at index si */
void swapArrayElements(int arr[], int fi, int si, int d)  
{  
    int i, temp;  
    for(i = 0; i < d; i++)  
    {  
        temp = arr[fi + i];  
        arr[fi + i] = arr[si + i];  
        arr[si + i] = temp;  
    }  
}  

void rotateArray(int a[], int n, int d){
  if (n==d || d == 0)
    return;
  int i = d, j = n - d;
  while(i != j){
    if(i < j){
      swapArrayElements(a, i-d, j + d - i, i);
      j -= i;
    } else {
      swapArrayElements(a, d-i, d, j);
      i -= j;
    }
    printArray(a,n);
  }
  swapArrayElements(a, d-i, d, i);
}

int main() 
{ 
  int n;
  cin>> n;

  int a[n];
  for(int i =0; i<n; i++){
    cin >> a[i];
  }

  int d;
  cin >> d;

  rotateArray(a,n,d);
  printArray(a,n);
  return 0; 
} 