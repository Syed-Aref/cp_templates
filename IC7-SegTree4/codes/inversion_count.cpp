#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;

    vector<int> input(n);

    for(int i= 0; i<n; i++){
        cin>>input[i];
    }

    ///-----------------
    map<int, int> mapped;
    for(int x : input){
        mapped[x] = x;
    }

    vector<int> revmap(mapped.size()+1);
    int last = 0;
    for(auto p : mapped){
        last++;
        int x = p.first;
        mapped[x] = last;
        revmap[last] = x;
    }



    for(int i = 0; i<n; i++){
        input[i] = mapped[input[i]];
    }
    ///-----------------

    for(int x : input){
        cout<<x<<endl;
    }

    cout<<endl;

    for(int x : input){
        int y = revmap[x];
        cout<<y<<endl;
    }


    build(values.size());

    long long int ans = 0;
    for(int i = 0; i<n; i++){
        int x = input[i];
        ans += query(x+1, values.size());

        update(x, 1);

    }

    /// segment tree size is not necessarily n, but it is mapped.size()
    return 0;
}
