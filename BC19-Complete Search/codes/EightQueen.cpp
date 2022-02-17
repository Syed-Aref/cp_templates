#include <bits/stdc++.h>
using namespace std;

int arr[10][10];
map<int,int> row;
map<int,int> col;
map<int,int> di45;
map<int,int> di135;
void set_eight_queenf()
{
    for(int i = 0;i<10;i++)
    {
        for(int j = 0;j<10;j++) arr[i][j] = 0;
    }
    for(int i = 1;i<=8;i++)
    {
        row[i] = 0;
        col[i] = 0;
    }
    for(int i = 2;i<=16;i++) di45[i] = 0;
    for(int i = -7;i<=7;i++) di135[i] = 0;
}
int cnt = 0;
int totalcnt = 0;
int mistaken = 0;
void rec_(int x,int y)
{
    if( x<1 || x>8 || y<1 || y>8 || row[x]==1 || col[y]==1 || di45[x+y]==1 || di135[x-y]==1 ){
        ///cout << "returning 29" << endl;
        return;
    }
    if( arr[x][y]!=0 ){
        ///cout << "returning 32" << endl;
        return;
    }

    cnt++;
    arr[x][y] = cnt;

    if( cnt==8 )
    {
        totalcnt++;
        /// //////
        vector<pair<int,int>> vp;
        for(int i = 1;i<=8;i++)
        {
            for(int j = 1;j<=8;j++)
            {
                if( arr[i][j]!=0 ) vp.push_back( make_pair(i,j) );
            }
        }
        int wrong = 0;
        for(auto i_ : vp)
        {

            int x = i_.first;
            int y = i_.second;
            int inrow = 0 , incol = 0;
            int di = 0;
            for(int i= 1;i<=8;i++)
            {
                if( arr[x][i]!=0 ) inrow++;
            }
            for(int i= 1;i<=8;i++)
            {
                if( arr[i][y]!=0 ) incol++;
            }
            for(int i = x+1,j=y+1;i>=1 && i<=8 && j>=1 && j<=8;i++ , j++ )
            {
                if( arr[i][j]!=0 ) di++;
            }
            for(int i = x+1,j=y-1;i>=1 && i<=8 && j>=1 && j<=8;i++ , j-- )
            {
                if( arr[i][j]!=0 ) di++;
            }
            for(int i = x-1,j=y+1;i>=1 && i<=8 && j>=1 && j<=8;i-- , j++ )
            {
                if( arr[i][j]!=0 ) di++;
            }
            for(int i = x-1,j=y-1;i>=1 && i<=8 && j>=1 && j<=8;i-- , j-- )
            {
                if( arr[i][j]!=0 ) di++;
            }
            if( inrow==1 && incol==1 && di==0 ) {}
            else{
                wrong = 1;
                break;
            }


        }
        if(wrong)
        {
            cout << "you made error" << endl;
            mistaken++;
        }
        /// //////
        for(int i = 1;i<=8;i++)
        {
            for(int j = 1;j<=8;j++)
            {

                if(arr[i][j]==0 ) cout << ".";
                else cout << "*";
            }
            cout << endl;

        }
        cout << "**************************" << endl;
        arr[x][y] = 0;
        cnt--;
        ///cout << "returning 46" << endl;
        return;
    }
    row[x] = 1 , col[y] = 1 , di45[x+y] = 1 , di135[x-y] = 1;
    for(int x = 1;x<=8;x++)
    {
        rec_(x,y+1);
    }
    row[x] = 0 , col[y] = 0 , di45[x+y] = 0 , di135[x-y] = 0;
    arr[x][y] = 0;
    cnt--;
    ///cout << "returning 57" << endl;
    return;

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    set_eight_queenf();

    for(int x = 1;x<=8;x++){
        ///cout << "chceking from main : (" << i << "," << j << ")" << endl;
        rec_(x,1);
    }

    cout << totalcnt << endl;
    cout << mistaken << endl;
}
