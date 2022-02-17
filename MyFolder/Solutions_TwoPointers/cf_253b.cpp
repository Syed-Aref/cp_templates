#include <bits/stdc++.h>
using namespace std;

int nmax = 1e5 + 10;

int cnt[5000 + 5];

int main()
{
    /**
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    **/
    for(int i = 0;i<5000 + 5;i++) cnt[i] = 0;

    ///freopen("input.txt","r",stdin);
    ///freopen("output.txt","w",stdout);

    int n;
    cin >> n;
    int x;
    for(int i = 0;i<n;i++) {
        cin >> x;
        cnt[x]++;
    }
    vector<int> vec;
    vec.push_back( 0 );
    for(int i = 1;i<=5000;i++) {
        if( cnt[i]>0 ) vec.push_back(i);
    }



    int N = n;
    n = vec.size()-1;

    //for(int i = 0;i<=n;i++) cout << vec[i] << " ";
    //cout << endl;

    //for(int i = 0;i<=n;i++) cout << cnt[vec[i]] << " ";
    //cout << endl;

    vector<int> pf(n+1);
    for(int i = 1;i<=n;i++) pf[i] = pf[i-1] + cnt[ vec[i] ];

    //for(int i = 0;i<=n;i++) cout << pf[i] << " ";
    //cout << endl;


    int ans = 1e6;
    for(int i = 1;i<=n;i++) {
        //cout << "#" << i << ":" << endl;
        int pt1 = i;
        int pt2;
        auto it = lower_bound( vec.begin()+i , vec.end(),2*vec[i] );
        if(it==vec.end()) it--;
        else if(*it > 2*vec[i]) it--;
        pt2 = it - vec.begin();
        //cout << vec[pt1] << " " << vec[pt2] << endl;
        ans = min(ans , N - ( pf[pt2]-pf[pt1-1] ) );
    }




    for(int i = n;i>=1;i--) {
        //cout << "#" << i << ":" << endl;
        int pt2 = i;
        int pt1;
        int srch = vec[i] / 2;
        if(vec[i]%2==1) srch++;
        auto it = lower_bound( vec.begin()+1 , vec.begin()+i,srch );

        pt1 = it - vec.begin();
        //cout << vec[pt2] << " " << vec[pt1] << endl;
        ans = min(ans , N - ( pf[pt2]-pf[pt1-1] ) );
    }


    cout << ans << endl;

}
