#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

#define mpr make_pair
#define pbk push_back
#define psh push
#define fir first
#define sec second
#define line "\n"



const int nmax = 1e5;

/**
int subtree[nmax+10];
int height[nmax+10];
int depth[nmax+10];
**/

vector<int> adj[nmax+10];
int depth[nmax+10];
int farthest = 0;
void bfs(int s,int n){

    for(int i = 0;i<=n+2;i++) depth[i] = -1;

    queue<int> q;

    depth[s] = 0;
    q.push( s );

    while(q.size()!=0){

        int u = q.front();
        q.pop();

        farthest = u;

        for(auto v : adj[u]){
            if(depth[v]!=-1) continue;

            depth[v] = depth[u]+1;
            q.push(v);
        }

    }

}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int ui,vi;
    for(int i = 1;i<=n-1;i++){
        cin >> ui >> vi;
        adj[ui].pbk(vi);
        adj[vi].pbk(ui);
    }

    bfs(1,n);
    int start = farthest;
    bfs(start,n);
    int last = farthest;
    cout << depth[last] << endl;
    cout << start << " " << last << endl;


}
