#include <bits/stdc++.h>

using namespace std;

const int mxN = 1e5+5;

void amin(int& a, int b) { a=a<b?a:b; }

int n, q;
int st[4*mxN];
int dd[4*mxN];
int aa[mxN];

void build(int id=1, int l=0, int r=n) {
    if(r-l<2) { st[id] = aa[l]; return; }
    int mid = (l+r)>>1;
    build(id<<1, l, mid); build(id<<1|1, mid, r);
    st[id]=min(st[id<<1], st[id<<1|1]);
}

void update(int lo, int hi, int val, int id=1, int l=0, int r=n) {
    if( r<=lo || l>=hi ) return;
    if( l>=lo && r<=hi ) { amin(dd[id], val); return; }
    st[id] = min(st[id], val);
    amin(dd[id<<1], val); amin(dd[id<<1|1], val);
    int mid = (l+r)>>1;
    update(lo,hi,val,id<<1,l,mid); update(lo,hi,val,id<<1|1,mid,r);
}

int query(int lo, int hi, int id=1, int l=0, int r=n) {
    if( r<=lo || l>=hi ) return 0x3f3f3f3f;
    if( l>=lo && r<=hi ) return min(st[id], dd[id]);
    amin(dd[id<<1], dd[id]); amin(dd[id<<1|1], dd[id]);
    int mid = (l+r)>>1;
    return min(query(lo,hi,id<<1,l,mid), query(lo,hi,id<<1|1,mid,r));
}

int main() {
    cin >> n >> q;
    for(int i=0; i<n; ++i) cin >> aa[i];
    build();

    memset(dd, 0x3f, sizeof(dd));

    int type, val, lo, hi;
    while(q--) {
        cin >> type >> lo >> hi;
        if(type==1) cout << query(lo-1, hi) << endl;
        else cin >> val, update(lo-1, hi, val);
    }
    return 0;
}
