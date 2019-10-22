#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
int countOne(int n){
    int cnt=0;
    while(n){
        n = n & (n-1);
        cnt++;
    }
    return cnt%2==0?1:0;
}
int sumDigits(int n)
{
    int sum = 0;
    while (n != 0) {
        sum += n % 10;
        n /= 10;
    }

    return sum;
}

// Driver Code
int main()
{
    int arr[] = { 4, 9, 15 };

    int n = sizeof(arr) / sizeof(arr[0]);
    int total_sum = 0;

    // Iterate through the array
    for (int i = 0; i < n; i++) {
        if (countOne(arr[i]))
            total_sum += sumDigits(arr[i]);
    }

    cout << total_sum << '\n';

    return 0;
}
