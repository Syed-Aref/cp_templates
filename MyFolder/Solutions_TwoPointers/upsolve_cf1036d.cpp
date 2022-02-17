#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

lli a[300000+5] , b[300000+5];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m;
    lli suma = 0;lli sumb = 0;

    cin >> n;
    for(int i = 1;i<=n;i++) {
        cin >> a[i];
        suma += a[i];
    }

    cin >> m;
    for(int i = 1;i<=m;i++) {
        cin >> b[i];
        sumb += b[i];
    }

    if(suma != sumb) {
        cout << -1 << endl;
        return 0;
    }

    int len= 0;
    int ia = 1 ;int ib = 1;
    suma = 0;sumb = 0;

    while(ia<=n && ib<=m) {
        suma = a[ia];
        sumb = b[ib];

        while( suma!=sumb ) {
            if(suma < sumb) suma += a[++ia];
            else sumb += b[++ib];
        }
        ++ia;
        ++ib;
        ++len;
    }
    cout << len << endl;

}
