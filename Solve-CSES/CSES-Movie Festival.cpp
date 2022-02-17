#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

bool sort_f( pair<lli,lli> p1,pair<lli,lli> p2 )
{
    return p1.second < p2.second;
}

int main()
{
    int n;
    cin >> n;

    lli x1,x2;

    vector< pair<lli,lli> > v;
    for(int i = 0;i<n;i++)
    {
        cin >> x1 >> x2;
        v.push_back( make_pair(x1,x2) );
    }

    sort( v.begin(),v.end(),sort_f );

    lli time = v[0].second;
    int cnt = 1;
    for(int i = 1;i<n;i++)
    {
        if( v[i].first < time )
            continue;
        time = v[i].second;
        cnt++;
    }

    cout << cnt << endl;
}
