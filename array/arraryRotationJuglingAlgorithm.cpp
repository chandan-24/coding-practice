/*
* This program accept size of the array(n) in the first line.
* Then total of n numbers and then the unit of rotation(d).
* This is jugling algorithm of array left rotation.
*/

#include <bits/stdc++.h> 
using namespace std;

int gcd(int a, int b){
  if(b == 0)
    return a;
  else
    return gcd(b, a % b);
}

void rotateArray(int a[], int n, int d){
  int g = gcd(d,n);
  for(int i = 0; i < g; i++){
    int j = i;
    int temp = a[i];

    while(1){
      int k = j+d;
      if(k >=n )
        k = k - n;
      if(k == i)
        break;
      a[j] = a[k];
      j = k;
    }
    a[j] = temp;
  }
}

void printArray(int a[], int size){
for(int i = 0; i < size; i++){
    cout << a[i] << " ";
  }
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