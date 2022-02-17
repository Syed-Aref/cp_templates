#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<char> v = {'A','B','C','D'};
    sort( v.begin() , v.end() );

    /**
        next_permutation( v.begin() , v.end() );
        /// If the elements are in lexicographically largest permutation, then elements are sorted into
        /// the lexicographically smallest permutation and returns false;

        /// Else, the elements are arranged in next lexicographically larger permutation and the method
        returns true;

        /// Complexity: O(N)
        /// N = size of vector
    **/

    do
    {
        for(auto i : v) cout << i << " ";
        cout << endl;
    }
    while( next_permutation( v.begin() , v.end() ) );
    /// Time complexity: O(N!*N)

    cout << "==============" << endl;
    for(auto i : v) cout << i << " ";
        cout << endl;

}
/**

*) Follows lexicography order
*) Returns false when the new permutation is lexicography smallest

**/
