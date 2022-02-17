#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

#define mpr make_pair
#define pbk push_back
#define psh push
#define fir first
#define sec second
#define line "\n"

const  int nmax = 1e5+10;
int n = 0 , m = 0;

vector<int> adj[nmax];
vector<int> topsort;
int indeg[nmax];

bool bfs( ){
    queue<int> q;

    for(int i = 1;i<=n;i++){
        if( indeg[i] == 0 ) q.push( i );
    }

    while(q.size()!=0){
        auto u = q.front();
        q.pop();

        for(auto v  :adj[u]){
            indeg[v]--;
            if( indeg[v] == 0 ) q.push(v);
        }
        topsort.push_back(u);
    }
    if(n == (int)topsort.size()) return 1;
    else return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;

    while(t-->0){

        cin >> n >> m;

        for(int i  =0;i<=n+2;i++){
            adj[i].clear();
            indeg[i] = 0;
        }
        topsort.clear();

        for(int i = 0;i<m;i++){
            int ui,vi;
            cin >> ui >> vi;

            adj[ui].push_back(vi);
            indeg[vi]++;
        }
        /// call bfs()
        bool isPossible = bfs();

        if(isPossible){
            for(auto u : topsort)cout<< u << " ";
            cout << endl;
        }
        else cout << "IMPOSSIBLE" << endl;


    }


}
