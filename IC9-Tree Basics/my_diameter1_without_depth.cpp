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
int farthest = 0;
void bfs(int s){

    queue< pair<int,int> > q;
    /// (node,parent_of_node)
    q.push( mpr(s,-1) );

    while(q.size()!=0){
        auto p = q.front();
        q.pop();

        int u = p.first;
        int par = p.second;
        farthest = u;

        for(auto v : adj[u]){
            if(v==par) continue;

            q.push( mpr(v,u) );
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

    bfs(1);
    int start = farthest;
    bfs(start);
    int last = farthest;
    cout << start << " " << last << endl;


}
