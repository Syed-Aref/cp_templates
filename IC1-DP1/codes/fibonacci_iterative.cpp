# include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;
int memo[100];

int fib(int n){
    for(int i = 0; i<=n; i++){
        if(i == 0) memo[0] = 0;
        else if(i == 1) memo[1] = 1;
        else{
            memo[i] = (memo[i-1] + memo[i-2]) % mod;
        }
    }

    return memo[n];
}

/// O(n * 1) = O(n)

int main(){


    int n;
    cin>>n;

    cout<<fib(n)<<endl;
}

