#include <bits/stdc++.h>

using namespace std;

const int mxn = 1e5+5;
int aa[mxn];

typedef struct node {
    node *left, *right;
    int L, R;
    int mn;
    node(int lo, int hi) {
        L = lo, R = hi;
        if(lo+1 == hi) { left = right = nullptr; mn = aa[lo]; return; }
        int mid = (lo+hi)>>1;
        left = new node(lo, mid); right = new node(mid, hi);
        mn = min(left->mn, right->mn);
    }
    ~node() {
        if(L+1==R) return;
        delete left;
        delete right;
    }
    void inorder() {
        if(L+1==R) { cout << mn << ' '; return; }
        left->inorder();
        cout << mn << ' ';
        right->inorder();
    }
} node;

int n;
int main() {
    cin >> n;
    for(int i=0; i<n; ++i) cin >> aa[i];
    auto something = node(0, n);
    something.inorder();
    return 0;
}


