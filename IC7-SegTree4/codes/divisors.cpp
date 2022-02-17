#include <bits/stdc++.h>
using namespace std;

vector<  pair<int, int>  > buckets[200000+5];       /// (L, i)

/// bucket[r] =
int ans[200000+5];

vector<int> multiples[nmax];
vector<int> divisors[nmax];

void sieve(){
    for(int i = 1; i<200000+5; i++){
        for(int j = i; j<200000+5; j+=i){
            /// j's are multiple of i
            divisors[j].push_back(i);
            if(i != j)
                multiples[i].push_back(j);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    sieve();

    int n, q;
    cin>>n>>q;

    vector<int> input(n+1);

    for(int i = 1; i<=n; i++){
        cin>>input[i];
    }

    for(int i = 0; i<q; i++){
        int l, r;
        cin>>l>>r;

        bucket[r].push_back(make_pair(l, i));
    }

    build(n);       /// add

    vector<int> occurences(n+1);

    map<int, int> last;     /// last[x] = last occurence of x
    for(int r = 1; r<=n; r++){
        /// update
        int x = input[r];

        occurences[x] = r;
        for(int y : divisors[x]){
            if(occurences[y] == 0) continue;
            update(occurences[y], +1);
        }

        for(int y : multiples[x]){
            if(occurences[y] == 0) continue;
            update(occurences[y], +1);
        }


        /// query

        for(auto p : buckets[r]){
            int l = p.first;
            int i = p.second;
            ans[i] = query(l, r);
        }
    }

    for(int i = 0; i<q; i++){
        cout<<ans[i]<<"\n";
    }


}


