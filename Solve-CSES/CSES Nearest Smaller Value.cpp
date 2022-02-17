#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);



    vector< pair<int,int> > v;
    v.push_back( make_pair(0,0) );
    int n;
    cin >> n;
    int x;

    for(int i = 1;i<=n;i++)
    {
        auto pi = v[v.size()-1];
        cin >> x;
        while( x<=pi.first )
        {
            v.pop_back();
            pi = v[v.size()-1];
        }
        cout << pi.second << " " ;
        v.push_back( make_pair(x,i) );
    }

    cout << endl;
}
