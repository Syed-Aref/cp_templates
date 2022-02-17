#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,q,x;
    cin >> n >> q;
    vector<long long int> v(n+1);
    v[0] = 0;
    for(int i = 1;i<=n;i++)
    {
        cin >> x;
        v[i] = v[i-1]^x;
    }
    while(q-->0)
    {
        int l , r;
        cin >> l >> r;

        int ans = v[l-1]^v[r];
        cout << ans << "\n";
    }
}
