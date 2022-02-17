# include <bits/stdc++.h>
using namespace std;
const int nmax = 1e5+10;
const long long int inf = 1e15;

int weight[nmax];
long long int value[nmax];

long long int memo[105][nmax];

long long int dp(int n, int taken){
    if(n == 0){
        if(taken == 0) return 0;
        else return -inf;
    }

    if(memo[n][taken] != -1) return memo[n][taken];


    memo[n][taken] = dp(n-1, taken);     /// not taking nth item

    if(taken >= weight[n])
        memo[n][taken] = max(memo[n][taken], dp(n-1, taken-weight[n]) + value[n]);

    return memo[n][taken];
}

/// O(N * W)

int main(){

    memset(memo, -1, sizeof(memo));


    int n, W;
    cin>>n>>W;

    for(int i= 1; i<=n; i++){
        cin>>weight[i]>>value[i];
    }

    long long int ans = -inf;

    for(int w = 0; w <= W; w++){
        ans = max(ans, dp(n, w));
    }

    cout<<ans<<endl;


}




