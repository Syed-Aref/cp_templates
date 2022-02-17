
#include <bits/stdc++.h>

using namespace std;


bool hasArrayTwoCandidates(int arr[], int n, int x) {
    sort(arr , arr+n);
    int pt1 =  0;
    int pt2 = n-1;
    while(pt1 < pt2) {
        int sum = arr[pt1] + arr[pt2];
        if( sum == x ) return true;
        else if(sum < x) pt1++;
        else pt2--;
    }
    return false;
}


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        auto ans = hasArrayTwoCandidates(arr, n, x);
        cout << (ans ? "Yes\n" : "No\n");
    }
    return 0;
}

