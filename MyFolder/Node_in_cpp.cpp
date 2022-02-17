#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int val;
        Node* nxt;

        Node(int n_) {
            val = n_;
            nxt = NULL;
        }

};



void pushf(Node* h,int v) {
            Node* t1 = h;
            while(t1->nxt != NULL) t1 = t1->nxt;
            t1->nxt = new Node(v);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Node* head = new Node(78);

    pushf(head,56);

    Node* t1 = head;
    while(t1 != NULL) {
        cout << t1->val << endl;
        t1 = t1->nxt;
    }


}
