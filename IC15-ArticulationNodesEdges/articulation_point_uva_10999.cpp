#include <bits/stdc++.h>
using namespace std;


typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<int,lli> pil;

#define mpr make_pair
#define pbk push_back
#define psh push
#define fir first
#define sec second
#define line "\n"

const int nmax = 1e5 + 10;
int n = 0;int m = 0;
int clk = 0;int childForRoot = 0;

vector< int > adj[nmax]; ///(node)
bool visited[nmax];
int low[nmax];
int st[nmax];
int adjcopm[nmax];
map<string,int> mp;
map<int,string> revmp;

/// This solution may/may not handle same edges

void dfs(int u,int par){
    ///cout << "At dfs(" << u << "," << par << ")" << endl;
    ++clk;
    low[u] = st[u] = clk;
    visited[u] = 1;
    for(auto p : adj[u]) {

        int v = p;

        if(v==par) continue;
        if( visited[v] ){
            low[u] = min( low[u] , st[v] );
        }
        else{
            dfs(v,u);
            low[u] = min(low[u],low[v]);
            if( par==-1 ) childForRoot++;
            else {
                if( low[v] >= st[u]  ) adjcopm[u]++;
            }
        }
    }
    if(par==-1){
        if( childForRoot > 1 ) adjcopm[u] = childForRoot-1;
    }

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int cities = 1;
    while(cin >> n){
        /// cin >> n;
        if(n==0) break;

        for(int i = 0;i<=n+2;i++) {
            adj[i].clear();
            visited[i] = 0;
            low[i] = -1;
            st[i] = -1;
            adjcopm[i] = 0;
        }
        clk = 0;
        childForRoot = 0;
        mp.clear();

        for(int i = 1;i<=n;i++){
            string s;
            cin >> s;
            mp[s] = i;
            revmp[i] = s;
        }

        cin >> m;


        for(int i = 0;i<m;i++) {
            string s1,s2;
            cin >> s1 >> s2;
            adj[ mp[s1] ].pbk( mp[s2] );
            adj[ mp[s2] ].pbk( mp[s1] );
        }
        for(int i = 1;i<=n;i++) {
            if( visited[i]==0 ){
                childForRoot = 0;
                dfs(i,-1);
            }
        }
        vector<string> vs;
        for(int i = 1;i<=n;i++){
            if( adjcopm[i] > 0 ) vs.pbk( revmp[i] );
        }
        sort( vs.begin() , vs.end() );
        if(cities > 1) cout << endl;
        cout << "City map #" << cities << ": ";
        cout << (int)vs.size();
        cout << " camera(s) found" << endl;
        for(auto ele : vs) cout << ele << endl;
        cities++;
    }


}
