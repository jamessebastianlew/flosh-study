#include <bits/stdc++.h>

using namespace std;

const int mxN = 1e5+5;

int n, q;
int st[4*mxN];
int a[mxN];

void build(int id=1, int l=0, int r=n) {
    if(r-l<2) { st[id]=a[l]; cout << id << ": " << st[id] << endl; return; }
    int mid = (l+r)>>1;
    build(id<<1, l, mid); build(id<<1|1, mid, r);
    st[id]=min(st[id<<1], st[id<<1|1]);
}

int query(int lo, int hi, int id=1, int l=0, int r=n) {
    if( l>=hi || r<=lo ) return INT_MAX;
    if( l>=lo && r<=hi ) return st[id];
    int mid = (l+r)>>1;
    int left = query(lo, hi, id<<1, l, mid);
    int right = query(lo, hi, id<<1|1, mid, r);
    return min(left, right);
}

void update(int x, int val, int id=1, int l=0, int r=n) {
    if( r<=x || l > x) return;
    if(r-l < 2) { st[id] = val; return; }
    int mid = (l+r)>>1;
    if(x<mid) update(x, val, id<<1, l, mid);
    else update(x, val, id<<1|1, mid, r);
    st[id] = min(st[id<<1], st[id<<1|1]);
}

int main() {

    cin >> n >> q;
    for(int i=0; i<n; ++i) cin >> a[i];
    build();

    int l, r;
    while(q--) {
        cin >> l >> r;
        cout << query(l-1, r) << '\n';
    }

    return 0;
}
