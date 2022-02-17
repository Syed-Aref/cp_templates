#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

string s, t;

int memo[3000+5][3000+5];
pair<int, int> link[3000+5][3000+5];

int dp(int a, int b){
    if(a == 0 || b== 0) return 0;

    if(memo[a][b] != -1) return memo[a][b];

    int ret = dp(a-1, b);
    link[a][b] = {a-1, b};

    if(dp(a, b-1) > ret){
        ret = dp(a, b-1);
        link[a][b] = {a, b-1};
    }

    if(s[a-1] == t[b-1]){
        if(dp(a-1, b-1) + 1 > ret){
            ret = dp(a-1, b-1) + 1;
            link[a][b] = {a-1, b-1};
        }
    }

    memo[a][b] = ret;
    return ret;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(memo, -1, sizeof(memo));

    cin>>s;
    cin>>t;

    int ans = dp(s.size(), t.size());

//    cout<<ans<<endl;

    int a = s.size();
    int b = t.size();

    string lcs;

    while(a > 0 && b > 0){
        int c = link[a][b].first;
        int d = link[a][b].second;

        if(c == a-1 && d == b-1){
            lcs.push_back(s[a-1]);
        }

        a = c;
        b = d;
    }

    reverse(lcs.begin(), lcs.end());

    cout<<lcs<<endl;


}



