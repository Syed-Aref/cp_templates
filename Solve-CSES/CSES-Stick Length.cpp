#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    int x;
    vector<int> v;
    for(int i = 0;i<n;i++)
    {
        cin >> x;
        v.push_back(x);
    }
    sort( v.begin(),v.end() );
    int n_ = n/2;


    long long int cost = 0;

    for(int i = 0;i<n;i++)
    {
        cost+=(long long int)( abs(v[i]-v[n_]) );
    }

    cout << cost << endl;
}
