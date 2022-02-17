#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

#define mpr make_pair
#define pbk push_back
#define psh push
#define fir first
#define sec second
#define line "\n"


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<lli> tri(3);

    cin >> tri[0] >> tri[1] >> tri[2];

    if( tri[0]==tri[1] && tri[1]==tri[2] ) cout << "Equilateral Triangle" << endl;
    else if( tri[0]==tri[1] ) cout << "Isosceles Triangle" << endl;
    else cout <<"Bad Triangle"<<endl;
}
