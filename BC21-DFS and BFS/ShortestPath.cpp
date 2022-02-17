#include <bits/stdc++.h>
using namespace std;

const int nmax = 100000+10;

vector<int> adjlist[nmax];
bool visited[nmax];
int dist[nmax];
int par[nmax];

void bfs(int U){
    queue<int> q;
    q.push(U);
    visited[U] = true;
    dist[U] = 0;
    par[U] = -1;

    while(!q.empty()){
        int u = q.front();
        q.pop();
        cout<<"bfs at "<<u<<" distance = "<<dist[u]<<endl;

        for(int v : adjlist[u]){
            if(!visited[v]){
                q.push(v);
                visited[v] = true;
                dist[v] = dist[u] + 1;
                par[v] = u;
            }
        }
    }
}
///Time complexity: O(|V| + |E|)

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int V, E;
    cin>>V>>E;
    for(int i = 0; i<E; i++){
        int u, v;
        cin>>u>>v;

        /// store
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }

//    for(int i = 1; i<=v; i++){
//        if(!visited[i]){
//            cout<<"Calling bfs "<<i<<endl;
//            bfs(i);
//        }
//    }
    for(int i = 1;i<=V;i++)
    {
        if( visited[i]==0 ) bfs(i);
    }

    int source , target;
    cin >> source >> target;
    while(source!=-1 && target!=-1)
    {
        vector<int> v;
        v.push_back(target);

        while(target!=source || target!=-1)
        {
            target = par[target];
            v.push_back(target);

        }
        if(target==source)
        {
            cout << "Path exists" << endl;
        }
        else
        {
            v.clear();

            int temp = source;
            source = target;
            target = temp;

            v.push_back(target);
            while(target!=source || target!=-1)
            {
                target = par[target];
                v.push_back(target);

            }

            if(target==source)
            {
                cout << "Path exists" << endl;
            }
            else cout << "Path doesnot exist" << endl;

        }
        cin >> source >> target;
    }
}

