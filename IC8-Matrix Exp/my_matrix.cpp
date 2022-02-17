#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

#define mpr make_pair
#define pbk push_back
#define psh push
#define fir first
#define sec second
#define line "\n"

lli inf = 1e9+17;
const int nmax = 10;
lli mod = 1e9+7;



struct matrix{
    int mat[nmax+10][nmax+10];
    int row , col;

    matrix(int r_,int c_){
        row = r_;
        col = c_;

        for(int i = 0;i<=row+2;i++){
            for(int j = 0;j<=col+2;j++) {
                mat[i][j] = 0;
            }
        }
    }


    matrix operator*(matrix other){
        matrix result(row, other.col); /// O(nmax*nmax)

        for(int i = 0; i<row; i++){
            for(int j = 0; j<other.col; j++){
                for(int k = 0; k<col; k++){
                    result.mat[i][j] =  ( result.mat[i][j] +( ( (mat[i][k])%mod * (other.mat[k][j])%mod )%mod ) )%mod;

                    ///if( result.mat[i][j] < 0 ) result.mat[i][j]+=mod;
                }
            }
        }
        return result;
    }

    void print(){
        for(int r = 0;r<row;r++){
            for(int c = 0;c<col;c++){
                cout << mat[r][c] << " ";
            }
            cout << endl;
        }
    }

};




matrix Matexpo(matrix X, long long int n){
    matrix Y(X.row, X.col);

    /// cout<<n<<endl;

    if(n == 0){
        for(int i = 0; i<X.row; i++)
            Y.mat[i][i] = 1;

        return Y;
    }
    Y = Matexpo(X, n/2);
    Y = Y * Y;

    if(n % 2 == 1){
        Y = Y * X;
    }

    return Y;
}


/***
Highest value of nmax(nmax = n = m = q = r = c) = 100
Initializing matrix = 100*100 + r*c  = 100*100 = 1e4(apprx)
matrix multiplication : 1e4 + n*m*q
// A(n*m) X B(p*q) where m=p

matrix exponentiation : logN*(1e4+n*n*n)
// N = power

***/

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    matrix a(2,2);

    a.mat[0][0] = 4; a.mat[0][1] = -5;
    a.mat[1][0] = 2; a.mat[1][1] = -3;

    matrix f(2,1);
    f.mat[0][0] = -2;
    f.mat[1][0] = 1;

    f = a*f;

    cout << f.mat[0][0] << endl;
    cout << f.mat[1][0] << endl;


}
