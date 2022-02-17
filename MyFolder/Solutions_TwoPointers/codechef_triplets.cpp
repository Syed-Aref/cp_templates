#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
lli mod = 1e9+7;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while(t-->0) {
        int p,q,r;
        cin >> p >> q >> r;

        vector<lli> x(p+1) , y(q+1) , z(r+1);
        vector<lli> pfx(p+1) , pfy(q+1) , pfz(r+1);

        for(int i = 1;i<=p;i++) {
            cin >> x[i];
            ///pfx[i] = (pfx[i-1] + x[i]) % mod;
        }
        for(int i = 1;i<=q;i++) {
            cin >> y[i];
            ///pfy[i] = (pfy[i-1] + y[i]) % mod;
        }
        for(int i = 1;i<=r;i++) {
            cin >> z[i];
            ///pfz[i] = (pfz[i-1] + z[i]) % mod;
        }
        sort( x.begin() , x.end() );
        sort( y.begin() , y.end() );
        sort( z.begin() , z.end() );

        for(int i = 1;i<=p;i++) pfx[i] = (pfx[i-1] + x[i])%mod;
        for(int i = 1;i<=q;i++) pfy[i] = (pfy[i-1] + y[i])%mod;
        for(int i = 1;i<=r;i++) pfz[i] = (pfz[i-1] + z[i])%mod;

        vector<lli> midy(1);
        vector<lli> midsum(1);
        vector<lli> midsumpf(1);

        lli ans = 0;
        for(int i = 1;i<=q;i++) {
            auto indx = upper_bound( x.begin() , x.end() , y[i] ) - x.begin() ;
            auto indz = upper_bound( z.begin() , z.end() , y[i] ) - z.begin() ;
            indx--;indz--;
            if(indx==0 || indz==0) continue;
            lli t1 = (lli)indz * (pfx[indx]) % mod;
            t1 = (t1*y[i])%mod;

            lli t2 =  (pfx[indx]*pfz[indz]) % mod;

            lli t3 = ( (lli)indx * (lli)indz ) % mod;
            t3 = (t3*y[i]) % mod;
            t3 = (t3*y[i]);

            lli t4 = (lli)indx * (pfz[indz]) % mod;
            t4 = (t4*y[i])%mod;

            ans = (ans + t1) % mod;ans = (ans+t2)%mod;ans = (ans+t3)%mod;ans = (ans+t4)%mod;
        }
        cout << ans << endl;
    }


}
