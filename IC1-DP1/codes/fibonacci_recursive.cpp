# include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;
int memo[100];

int fib(int n){
    if(n == 0) return 0;
    if(n == 1) return 1;

    if(memo[n] != -1) return memo[n];

    memo[n] = (fib(n-1) + fib(n-2)) % mod;
    return memo[n];
}

/// O(n * 1) = O(n)

int main(){
    memset(memo, -1, sizeof(memo));


    int n;
    cin>>n;

    cout<<fib(n)<<endl;
}
