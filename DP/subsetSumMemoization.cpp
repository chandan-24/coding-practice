#include <bits/stdc++.h>
using namespace std;

int DP[1002][1002];
int g=0;

int isSubset(int num[], int n, int sum) {
    if (DP[n][sum] != -1) {
        return DP[n][sum];
    }
    if (sum == 0) {
        return 1;
    }
    if (n == 0 && sum != 0) {
        return 0;
    }

    if (num[n-1] <= sum) {
        return DP[n][sum] = isSubset(num, n-1, sum-num[n-1]) || isSubset(num, n-1, sum);
    } else {
        return DP[n][sum] = isSubset(num, n-1, sum);
    }
}

int main() {
    memset(DP, -1, sizeof DP); 
    int num[] = {13,32,1,5,7,2};
    int sum = 20;
    int n = sizeof num / sizeof num[0];
    cout<< "IS SUBSET: " << isSubset(num, n, sum);
	return 0;
}
