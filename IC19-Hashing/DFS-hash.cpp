#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

#define mpr make_pair
#define pbk push_back
#define psh push
#define fir first
#define sec second
#define line "\n"

const lli p = 1e9+9;
const lli x = 1e5;
const int nmax = 1e5;
lli rollingPattern = 0;
int patternsz = 0;
int cnt = 0;

vector<int> adj[nmax+10];
string s1[nmax+10];
lli pfh[3*nmax+10];
lli power[3*nmax+10];



void dfs(int node,int parNode,int start){
    if(parNode==-1){
        for(auto v : adj[node]) dfs(v,node,start);
        return;
    }

    for(int i = 0;i<s1[node].length();i++){
        start++;
        pfh[start] = ( (pfh[start-1]*x)%p + (lli)s1[node][i] )%p;
        if(start<patternsz) continue;
        lli x = ( pfh[start] - (pfh[start-patternsz]*power[patternsz])%p )%p;
        if(x < 0) x+=p;
        if(x == rollingPattern) cnt++;

    }

    for(auto v : adj[node]) dfs(v,node,start);
}

lli calc_rolling_pattern(string& pattern) {

    lli ret = 0;
    bool first = 1;
    for(auto c : pattern){
        if(first){
            ret += c;
            first = false;
        }
        else{
            ret = (ret*x)%p;
            ret = (ret+c)%p;
        }
    }
    return ret;
}

void calcPower(){
    power[0] = 1;
    for(int i = 1;i<=3*nmax;i++) power[i] = (power[i-1]*x) % p;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    calcPower();

    int n , pvi;
    cin >> n;

    for(int vi = 2;vi<=n;vi++){
        cin >> pvi >> s1[vi];
        adj[pvi].push_back(vi);
    }

    string pattern;
    cin >> pattern;

    patternsz = pattern.length();

    rollingPattern = calc_rolling_pattern(pattern);

    pfh[0] = 0;
    dfs(1,-1,0);

    cout << cnt << endl;

}
