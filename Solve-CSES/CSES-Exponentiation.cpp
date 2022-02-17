#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
const lli mod = 1e9+7;

lli modexpo(lli a,lli n,lli m)
{
    lli ans = 1;
    while(n>0)
    {
        if(n%2==1){
            ans = (ans*a)%m;
            n--;

        }
        a = (a*a)%m;
        n = n/2;

    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while(t-->0)
    {
        lli a , n;
        cin >> a >> n;

        cout <<modexpo(a,n,mod)<< endl;
    }
}
