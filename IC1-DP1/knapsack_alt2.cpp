#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

#define mpr make_pair
#define pbk push_back
#define psh push
#define fir first
#define sec second
#define line "\n"

const int maxn = 100 , maxw = 100000;

lli v[maxn+5];
int w[maxw+5];
lli ans[maxn+5][maxw+5];

lli inf = (lli)(1e15);

lli dp(int i , int rem)
{

    if(i==0)
    {
        return 0;
    }
    if( ans[i][rem] != 0  ) return ans[i][rem];

    lli cand1 = dp(i-1,rem);
    lli cand2;
    if( rem-w[i] >=0 ){
        cand2 = v[i] + dp(i-1,rem-w[i]);
        ans[i][rem] = max(cand1,cand2);
    }
    else ans[i][rem] = cand1;
    return ans[i][rem];
}

/// Time Complexity: O(N*W)

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,wm;
    cin >> n >> wm;

    for(int i = 1;i<=n;i++) cin >> w[i] >> v[i];

    lli out = dp(n,wm);

    cout << out << endl;

}
