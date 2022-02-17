#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

#define mpr make_pair
#define pbk push_back
#define psh push
#define fir first
#define sec second
#define line "\n"

const int nmax = 1000000;
int memo[nmax+10];
vector<int> v;
int mod = 1e9+7;

int dp(int target)
{
    memo[0] = 1;



        for(auto j : v)
        {
            for(int i = 1;i<=target;i++)
            {
                if(i-j >= 0) memo[i] = (memo[i] + memo[i-j]) % mod;
            }
        }

    return memo[target];
}
/// Time Complexity: O(N*SUM)
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n , target , x;
    cin >> n >> target;
    /// target = desired sum of money(SUM)

    for(int i = 0;i<n;i++)
    {
        cin >> x;
        v.pbk(x);
    }
    sort(v.begin(),v.end());
    cout << dp(target) << endl;

}
