#include<bits/stdc++.h>
using namespace std;

int main(){

    map<string, int> m;
    m["hello"] = 100;
    cout<<m["hello"]<<endl;


    m["program"] = 100;
    cout<<m["program"]<<endl;


    m["program"] = 200;
    cout<<m["program"]<<endl;


    m["abc"];
    cout<<m["abc"]<<endl;


    for(auto p : m){
        cout<<p.first<<" "<<p.second<<endl;
    }


    cout<<m.count("bubble")<<endl;
    cout<<m.count("abc")<<endl;


    auto it = m.lower_bound("bubble");
    cout<<(*it).first<<endl;
    cout<<(*it).second<<endl;


    cout<<(*m.begin()).first<<endl;
    cout<<(*m.begin()).second<<endl;

    ///
    m.insert( make_pair("wfwokf",89) );
    for(auto p : m){
        cout << p.first << " => " << p.second << endl;
    }

    it = m.find("fsnfsk");

    if( it == m.end() ) cout << "Doesn't exist" << endl;
    else cout << "Does exist" << endl;

    int exists = m.count( "qdfwr" );
    cout << exists << endl;

    return 0;
}
