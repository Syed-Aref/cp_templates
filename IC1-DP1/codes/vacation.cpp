# include <bits/stdc++.h>
using namespace std;
const int nmax = 1e5+10;


/// CODE IS INCOMPLETE, TRY TO FINISH IT YOURSELF

int A[nmax];
int B[nmax];
int C[nmax];

/// 0-A, 1-B, 2-C

long long int memo[nmax][3];

long long int dp(int n, int last){
    if(n == 1){
        if(last == 0) return A[1];
        else if(last == 1) return B[1];
        else if(last == 2) return C[1];
    }

    if(memo[n][last] != -1) return memo[n][last];


    if(last == 0)
        memo[n][last] = A[n] + max(dp(n-1, 1), dp(n-1, 2));
    else
        /// more  stuff
}


/// O(3n * 1) = O(n)

int main(){

    memset(memo, -1, sizeof(memo));


    /// input--


    int ans = -1e9;


    ans = max(ans, dp(n, 0));
    ans = max(ans, dp(n, 1));
    ans = max(ans, dp(n, 2));

    cout<<ans<<endl;

}



