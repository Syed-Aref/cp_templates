#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

#define mpr make_pair
#define pbk push_back
#define psh push
#define fir first
#define sec second
#define line "\n"

const int nmax = 3000 + 5;
int inf = 1e9;
int n = 0;

vector<int> adj[nmax];
set< tuple<int,int,int > > st;
int dist[nmax][nmax];
int link[nmax][nmax];


void bfs(int x,int y) {
    for(int i = 0;i<=n+2;i++) {
        for(int j = 0;j<=n+2;j++) dist[i][j] = inf;
    }

    queue< pair<int,int> > q;
    dist[x][y] = 0;
    link[x][y] = -1;
    q.push( mpr(x,y) );

    while(q.size()!=0) {
        auto u = q.front();

        int now = u.first;
        int prv = u.second;
        q.pop();

        for(auto u : adj[now]) {
            int nxt = u;
            /// if(u==prv) continue;
            if( st.count( make_tuple(prv,now,nxt) ) == 1 ) continue;
            if( dist[now][prv]  + 1 < dist[nxt][now]  ) {
                dist[nxt][now] = dist[now][prv] + 1;
                link[nxt][now] = prv;
                q.push( mpr(nxt,now) );
            }
        }


    }
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int m , k;
    cin >> n >> m >> k;

    for(int i = 0;i<m;i++) {
        int ui , vi;
        cin >> ui >> vi;
        adj[ui].pbk(vi);
        adj[vi].pbk(ui);
    }
    for(int i = 0;i<k;i++) {
        int a,b,c;
        cin >> a>> b >> c;
        st.insert( make_tuple(a,b,c) );
    }
    bfs(1,0);
    int ans = inf;
    int ind = 0;
    for(int i = 1;i<=n;i++) {
        if( dist[n][i] < ans ) {
            ans = dist[n][i];
            ind = i;
        }
    }
    if( ans==inf ) {
        cout << -1 << endl;

    }
    else{
        cout<< dist[n][ind] << endl;
        vector<int> path;
        path.pbk(n);
        path.pbk(ind);

        int x = n , y = ind;
        while(link[x][y] > 0) {
            int tmp = link[x][y];
            path.pbk(tmp);
            x = y;
            y = tmp;
        }
        reverse( path.begin() , path.end() );
        for(auto i : path) cout << i << " ";
        cout << endl;
    }
}
