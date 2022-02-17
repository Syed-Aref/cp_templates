#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll mod = 1e9+7;

vector<int> coins;

ll memo[1000000+10];
//ll dp(int x, int i){
//    if(x == 0) return 1;
//    if(i == 0) return 0;
//
//    if(memo[x][i] != -1) return memo[x][i];
//
//
//    ll ret = dp(x, i-1);
//    if(x-coins[i] >= 0){
//        ret += dp(x-coins[i], i);
//        ret %= mod;
//    }
//
//    memo[x][i] = ret;
//
//    return ret;
//}


int dp(int X, int n){
    for(int i = 0; i<=n; i++){
        for(int x = 0; x <= X; x++){
            if(x == 0)
                memo[x] = 1;
            else if(i == 0)
                memo[x] = 0;
            else{
                memo[x] = memo[x];
                if(x - coins[i] >= 0)
                    memo[x] = (memo[x] + memo[x-coins[i]]) % mod;
            }
        }
    }

    return memo[X];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(memo, -1, sizeof(memo));

    int n, x;

    cin>>n>>x;

    coins.push_back(0);

    for(int i = 0; i<n; i++){
        int c;
        cin>>c;
        coins.push_back(c);
    }

    sort(coins.begin(), coins.end());

    ll ans = dp(x, n);
    cout<<ans<<endl;

}


