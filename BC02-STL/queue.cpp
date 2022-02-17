#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    queue<int> q;

    for(int i = 10;i<=15;i++) q.push(i);

    cout << "Size:" << q.size() << endl;
    cout << "At top: " << q.front() << endl;
    cout << "At back: " << q.back() << endl;

    while(q.size()!=0) q.pop() ;
    cout << "Size:" << q.size() << endl;
    cout <<  q.empty() << endl;


}
