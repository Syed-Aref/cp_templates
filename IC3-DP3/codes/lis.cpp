#include <bits/stdc++.h>
using namespace std;

int arr[100000];
int memo[100000];

/// dp[i] = max length of LIS ending at arr[i]

int dp(int n){
    if(memo[n] != -1) return memo[n];

    int ret = 1;
    for(int i = 0; i<n; i++){
        if(arr[i] < arr[n])
            ret = max(ret, 1 + dp(i));
    }

    memo[n] = ret;

    return ret;
}

int main(){

    memset(memo, -1, sizeof(memo));
    int n;
    cin>>n;
    for(int i = 0; i<n; i++) cin>>arr[i];


    int ans = 0;

    for(int i = 0; i<n; i++)
        ans = max(ans, dp(i));

    cout<<ans<<endl;

}

