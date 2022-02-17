#include <bits/stdc++.h>
using namespace std;


int occur[1000];
int cnt[1000];

void recf(int level , int n)
{
    if( level>=n )
    {
        for(int i = 0;i<n;i++)
        {
            for(int j = 1;j<=cnt[i];j++) cout << i << " ";
        }
        cout << endl;
        return;
    }
    for(int i = 0;i<=occur[level];i++)
    {
        cnt[level] = i;
        recf(level + 1 , n);
        cnt[level] = 0;
    }

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
        for(int i = 0;i<1000;i++)
        {
            occur[i] = cnt[i] = 0;
        }
        int n;
        cin >> n;
        vector<int> v(n);
        int nmax = -1;
        for(int i = 0;i<n;i++)
        {
            cin >> v[i];
            if( v[i] > nmax ) nmax = v[i];
            occur[ v[i] ]++;
        }
        recf(0,nmax+1);

    }
}
