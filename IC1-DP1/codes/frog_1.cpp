# include <bits/stdc++.h>
using namespace std;
const int nmax = 1e5+10;
int heights[nmax];

long long int memo[nmax];

long long int dp(int n){
    if(n == 1) return 0;
    if(n == 2) return abs(heights[1] - heights[2]);

    if(memo[n] != -1) return memo[n];


    /// loop for i = 1 to k, dp(n-i) + abs(heights[i] - heights[n])

    /// careful n-i > 0

    memo[n] = min(dp(n-1) + abs(heights[n] - heights[n-1]), dp(n-2) + abs(heights[n] - heights[n-2]));

    return memo[n];
}

/// O(n * 1) = O(n)

int main(){

    memset(memo, -1, sizeof(memo));

    int n;
    cin>>n;

    for(int i = 1; i<=n; i++) cin>>heights[i];

    cout<<dp(n)<<endl;
}


