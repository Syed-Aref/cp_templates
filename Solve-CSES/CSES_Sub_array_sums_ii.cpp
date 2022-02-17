#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n,x;
    cin >> n >> x;


    vector< long long int > prf(n+1);
    prf[0] = 0;

    int x1;
    for(int i = 1;i<=n;i++)
    {
        cin >> x1;

        prf[i] = prf[i-1] + (long long int)x1;
    }
    map< long long int,long long int > m;
    m[0]++;
    long long int srch;
    long long int count = 0;
    for(int i = 1;i<=n;i++)
    {
        srch = prf[i] - (long long int)x;
        if( m.count(srch)==1 )
            count += m[srch];
        long long int k = prf[i];
        m[k]++;
    }
    cout << count << "\n";
}
