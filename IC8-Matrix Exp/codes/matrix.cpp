#include <bits/stdc++.h>
using namespace std;


/// The problem was of stack overflow, local machines do not allow much stack memory
/// But do not worry about it for online judge, in fact I ran the code at codeforces
/// and it ran fine

const int nmax = 100+5;
const long long int mod = 1e9+7;

struct Matrix{
    /// after constructing val contains garbage
    long long int val[nmax][nmax];
    int row, col;

    Matrix(int _r, int _c){
        row = _r;
        col = _c;

        /* memset */
        for(int i = 0; i<row; i++)
            for(int j = 0; j<col; j++)
                val[i][j] = 0;
    }

    Matrix operator*(Matrix other){
        Matrix result(row, other.col); /// O(nmax*nmax)

        for(int i = 0; i<row; i++){
            for(int j = 0; j<other.col; j++){
                for(int k = 0; k<col; k++){
                    result.val[i][j] += val[i][k] * other.val[k][j];
                    result.val[i][j] %= mod;
                }
            }
        }
        /// O(row * col * other.col)

        return result;  /// O(nmax*nmax)
    }

    void print(){
        for(int i = 0; i<row; i++){
            for(int j = 0; j<col; j++){
                cout<<val[i][j]<<" ";
            }
            cout<<endl;
        }
    }
};

/// X^n
Matrix Matexpo(Matrix X, long long int n){
    Matrix Y(X.row, X.col);

    cout<<n<<endl;

    if(n == 0){
        for(int i = 0; i<X.row; i++)
            Y.val[i][i] = 1;

        return Y;
    }
    Y = Matexpo(X, n/2);
    Y = Y * Y;

    if(n % 2 == 1){
        Y = Y * X;
    }

    return Y;
}

int main(){

    long long int n;
    cin>>n;

    Matrix F(2, 1);

    F.val[0][0] = 0;
    F.val[1][0] = 1;


    Matrix M(2, 2);
    M.val[0][0] = 0, M.val[0][1] = 1;
    M.val[1][0] = 1, M.val[1][1] = 1;

    M = Matexpo(M, n);

//    M.print();

    F = M * F;

//    F.print();

    cout<<F.val[0][0]<<endl;

    return 0;
}
