#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

int main()
{
    int n,x1,x2;
    vector< pair<int,int> > v;
    cin >> n;

    for(int i = 0;i<n;i++)
    {
        cin >> x1 >> x2;
        v.push_back( make_pair(x1,x2) );
    }

    sort( v.begin(),v.end() );
    lli bonus = 0;
    lli days = 0;
    for(auto p : v)
    {
        days = days + (lli)p.first;
        bonus += (lli)((lli)p.second - (lli)days);
    }

    cout << bonus << endl;

}
