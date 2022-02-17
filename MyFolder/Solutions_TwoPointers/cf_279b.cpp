#include <bits/stdc++.h>
using namespace std;

int nmax = 1e5 + 10;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int x;
    cin >> x;
    vector<int> inp(nmax);
    vector<int> pf(nmax);

    for(int i = 1;i<=n;i++) {
        cin >> inp[i];
        pf[i] = pf[i-1] + inp[i];
    }
    ///for(int i = 1;i<=n;i++) cout << inp[i] << " ";
    ///cout << endl;
    ///for(int i = 1;i<=n;i++) cout << pf[i] << " ";
    ///cout << endl;
    int pt1 = -1;int pt2 = -2;
    int sum = 0;
    int ans = 0;
    for(int i = 1;i<=n;i++) {
        ///cout << "#"<< i << ":" << endl;
        if( pt1==-1 ) {
            ///cout << "line 33" << endl;
            if(inp[i]<=x) {
                ///cout << "line 35" << endl;
                pt1 = i;pt2 = i;
                sum = inp[i];
            }
        }
        else {
            ///cout << "line 41" << endl;
            if( sum+inp[i] <=x ) {
                ///cout << "line 43" << endl;
                pt2++;
                sum += inp[i];
            }
            else {
                if( inp[i] > x ) {
                    ///cout << "line 49" << endl;
                    pt1 = -1 , pt2 = -2;

                }
                else{
                    int extra = sum + inp[i] - x;
                    auto it = lower_bound( pf.begin() + pt1 ,pf.begin() + i , pf[pt1-1] + extra );

                    if( it - pf.begin() == i ) {
                        ///cout << "line 58" << endl;
                        pt2 = pt1 = i;
                        sum = inp[i];
                    }
                    else{
                        ///cout << "line 63" << endl;
                        pt2 = i;
                        pt1 = it - pf.begin() + 1;
                        sum = pf[pt2] - pf[pt1-1];
                    }
                }
            }
        }
        ///cout << pt1 << " " << pt2 << endl;
        ans = max(ans,pt2-pt1+1);
    }
    cout <<ans<< endl;

}
