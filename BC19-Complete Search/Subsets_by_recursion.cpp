#include <bits/stdc++.h>
using namespace std;

bool taken[1050];

void recf(int level , int n)
{
    if( level >=n )
    {
        for(int i = 0;i<n;i++)
        {
            if( taken[i]==true ) cout << i << " ";
        }
        cout << endl;
        return;
    }
    recf(level+1 , n);
    taken[level] = true;
    recf(level+1 , n);
    taken[level] = false;
}



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 100;
    while( t-->0 )
    {
        int n;
        cin >> n;
        recf(0 , n);
    }
}
