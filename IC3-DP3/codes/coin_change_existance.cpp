#include <bits/stdc++.h>
using namespace std;
int n;
int coins[100];
int memo[100000];

/// 1 - true
/// 0 - false

int dp(int s){
    if( s== 0) return true;

    if(memo[s] != -1) return memo[s];

    int ret = 0;
    for(int i = 0; i<n; i++){
        if(s-coins[i] >= 0){
            ret |= dp(s-coins[i]);
        }
    }

    memo[s] = ret;
    return ret;
}

int main(){

    memset(memo, -1, sizeof(memo));
    cin>>n;
    for(int i = 0; i<n; i++) cin>>coins[i];


    int s;
    cin>>s;
    if(dp(s) == 1){
        cout<<s<<" can be made"<<endl;
    }
    else{
        cout<<s<<" cannot be made"<<endl;
    }
}
