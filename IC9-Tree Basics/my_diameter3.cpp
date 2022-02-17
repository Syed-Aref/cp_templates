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

vector<int> adj[nmax+10];
pair<int,int> farthest[nmax+10][3];
/// (distance,node)

void dfs1(int s,int par){
    for(int i = 0;i<3;i++){
        farthest[s][i].first = 0;
        farthest[s][i].second = s;
    }

    for(auto v : adj[s]){
        if(v==par) continue;

        dfs1(v,s);
        farthest[s][0].first = farthest[v][2].first+1;
        farthest[s][0].second = farthest[v][2].second;
        sort(farthest[s],farthest[s]+3);
    }
}


void dfs2(int s,int par){
    if(par!=-1){
        if( farthest[s][2].second==farthest[par][2].second ){
            farthest[s][0].first = farthest[par][1].first+1;
            farthest[s][0].second = farthest[par][1].second;
        }
        else{
            farthest[s][0].first = farthest[par][2].first+1;
            farthest[s][0].second = farthest[par][2].second;
        }
        sort( farthest[s],farthest[s]+3 );
    }
    for(auto v:adj[s]){
        if(v==par) continue;
        dfs2(v,s);
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

    dfs1(1, -1);
    dfs2(1, -1);

    for(int i = 1; i<=n; i++){
        cout << "#" << i << " :" << endl;
        cout<<i<<" -> "<<farthest[i][2].second<<" "<<farthest[i][2].first<<endl;
        cout<<i<<" -> "<<farthest[i][1].second<<" "<<farthest[i][1].first<<endl;
        ///if( farthest[i][2].second==farthest[i][1].second ) cout << "Both have same distance" << endl;
    }



}
