#include <bits/stdc++.h>
using namespace std;

vector<int> coins;

int memo[1000000+10];
int dp(int x){
    if(x == 0) return 0;

    if(memo[x] != -1) return memo[x];

    int ret = 1e9;
    for(int c : coins){
        if(x-c < 0) continue;
        ret = min(ret, dp(x-c));
    }

    ret += 1;

    memo[x] = ret;

    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(memo, -1, sizeof(memo));

    int n, x;

    cin>>n>>x;

    for(int i = 0; i<n; i++){
        int c;
        cin>>c;
        coins.push_back(c);
    }

//    for(int i = 0; i<=11; i++){
//        cout<<"at "<<i<<" "<<dp(i)<<endl;
//    }

    int ans = dp(x);
    if(ans >= 1e9)
        cout<<-1<<endl;
    else
        cout<<ans<<endl;

}
