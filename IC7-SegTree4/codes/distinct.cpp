#include <bits/stdc++.h>
using namespace std;

vector<  pair<int, int>  > buckets[200000+5];       /// (L, i)

/// bucket[r] =
int ans[200000+5];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

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

    map<int, int> last;     /// last[x] = last occurence of x
    for(int r = 1; r<=n; r++){
        /// update the segment tree
        update(r, +1);

        if(last.count(input[r]) > 0)
            update(last[input[r]], -1);
        last[input[r]] = r;

        /// query processing

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

