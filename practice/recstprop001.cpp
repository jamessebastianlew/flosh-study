#include <bits/stdc++.h>

using namespace std;

const int mxN = 1e5+5;

int n;
int q;
int aa[mxN];
int dd[4*mxN];
int st[4*mxN];

//range plus query and addition
void build(int id = 1, int l=0, int r=n) {
    if(r-l<2) {st[id] = aa[l]; return;}
    int mid = (l+r)>>1;
    build(id<<1, l, mid); build(id<<1|1, mid, r);
    st[id]=st[id<<1]+st[id<<1|1];
}

void update(int lo, int hi, int val, int id=1, int l=0, int r=n) {
    if( r<=lo || l>=hi) return;
    if( l>=lo && r<=hi) { dd[id]+=val; return; }
    st[id] += (min(r, hi) - max(l, lo))*val;
    int mid = (l+r)>>1;
    update(lo,hi,val,id<<1,l,mid); update(lo,hi,val,id<<1|1,mid,r);
}

int query(int lo, int hi, int id=1, int l=0, int r=n) {
    if( r<=lo || l>=hi ) return 0;
    if( l>=lo && r<=hi ) return st[id]+dd[id]*(r-l);
    st[id]+=dd[id]*(r-l);
    dd[id<<1]+=dd[id], dd[id<<1|1]+=dd[id]; dd[id]=0;
    int mid = (l+r)>>1;
    return query(lo,hi,id<<1,l,mid)+query(lo,hi,id<<1|1,mid,r);
}

int main() {

    cin >> n >> q;
    for(int i=0; i<n; ++i) cin >> aa[i];
    build();

    int type, val, lo, hi;
    while(q--) {
        cin >> type >> lo >> hi;
        if(type==1) cout << query(lo-1, hi) << endl;
        else cin >> val, update(lo-1, hi, val);
    }

    return 0;
}
