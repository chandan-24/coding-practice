/* C++ Program to search an element 
* in a sorted and pivoted array
*/

#include <bits/stdc++.h> 
using namespace std;

/* Function to get pivot. 
*  For array 3, 4, 5, 6, 1, 2, it returns 3 (index of 6) 
*/
int findPivot(int a[], int l, int h){
  if(h < l)
    return -1;
  if(h == l)
    return l;
  int m = (l+h)/2;
  if(m < h && a[m]>a[m+1])
    return m;
  if(l < m && a[m] < a[m-1])
    return m-1;
  if(a[l] >= a[m])
    return findPivot(a, l, m-1);
  return findPivot(a, m+1, h);
}

int binarySearch(int a[], int l, int h, int key){
  if(h<l)
    return -1;
  int m = (l+h)/2;
  if(a[m] == key)
    return m;
  if(a[m] > key)
    return binarySearch(a, l, m-1, key);
  return binarySearch(a, m+1, h, key);
}

int findKey(int a[], int n, int key){
  int pivot = findPivot(a, 0, n-1);
  if(key >= a[0])
    return binarySearch(a, 0, pivot, key);
  return binarySearch(a, pivot+1, n-1, key);
}


int main() 
{ 
  int n;
  cin>> n;

  int a[n];
  for(int i =0; i<n; i++){
    cin >> a[i];
  }

  int key;
  cin>> key;

  cout << findKey(a, n, key);
  return 0; 
} 