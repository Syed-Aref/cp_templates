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
const int nmax = 1e6;
int n;
string s;

lli h[nmax+10];
lli power[3*nmax+10];
vector<lli> factor[nmax+10];
int index1[nmax+10];

void calc_hash(){
    /// cout << s << " will be calculated now" << endl;
    int i = 1;
    for(auto character : s){
        h[i] = (h[i-1]*x) % p;
        h[i] = (h[i]+character)%p;
        i++;
    }
}

void reset(){
    for(int i = 0;i<=n+2;i++) index1[i] = 0;
}

void calc_power(){

    power[0] = 1;
    for(int i = 1;i<=3*nmax;i++) power[i] = (power[i-1]*x)%p;

}

void calc_factor(){
    factor[0] = {};
    for(int i = 1;i<=nmax;i++){
        factor[i] = {0,1};
        for(int j = 2,k = i;j<=nmax && k<=nmax;j++,k+=i) {
            factor[i].push_back( (factor[i][factor[i].size()-1] + power[k])%p );
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    calc_power();
    calc_factor();

    /**
    for(int i = 1;i<=3;i++){
        cout << "#" << i << ":";
        for(int j = 1;j<=5;j++) cout << " " << factor[i][j];
        cout << endl;
    }
    **/

    h[0] = 0;

    int cases;
    cin >> cases;

    for(int tc = 1;tc<=cases;tc++){
        cin >> n >> s;

        calc_hash();
        reset();

        for(int i = 1;i<=n;i++){
            for(int j = 2*i;j<=n;j+=i){
                if(index1[j] != 0) continue;
                if( h[j] == ((h[i]*factor[i][(j/i)])%p) ) index1[j] = j/i;
            }
        }

        if(tc > 1) cout << line;
        cout << "Test case #" << tc << line;
        for(int i = 1;i<=n;i++){
            if(index1[i] != 0) cout << i << " " << index1[i] << line;
        }

    }

}
