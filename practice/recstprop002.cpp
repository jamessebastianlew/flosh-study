#include <bits/stdc++.h>

using namespace std;

const int mxN = 1e5+5;
//just remember the children don't know anything about
//the parents
//
//also when you update the bottom, what nodes are you
//updating

int n, q;
int st[4*mxN];
int dd[4*mxN];
int aa[mxN];

void build(int id=1, int l=0, int r=n) {
    if(r-l<2) { st[id]=aa[l]; return; }
    int mid = (l+r)>>1;
    build(id<<1,l,mid); build(id<<1|1,mid,r);
    st[id] = st[id<<1] + st[id<<1|1];
}

void update(int lo, int hi, int val, int id=1, int l=0, int r=n) {
    if( r<=lo || l>=hi ) return;
    if( l>=lo && r<=hi) { dd[id]+=val; return; }
    st[id] += (min(r, hi)-max(l,lo))*val;
    int mid = (l+r)>>1;
    update(lo,hi,val,id<<1,l,mid); update(lo,hi,val,id<<1|1,mid,r);
}

int query(int lo, int hi, int id=1, int l=0, int r=n) {
    if( r<=lo || l>=hi ) return 0;
    if( l>=lo && r<=hi ) return st[id] + dd[id]*(r-l);
    st[id]+=dd[id]*(r-l);
    dd[id<<1]+=dd[id], dd[id<<1|1]+=dd[id];
    dd[id]=0;
    int mid = (l+r)>>1;
    return query(lo,hi,id<<1,l,mid)+query(lo,hi,id<<1|1,mid,r);
}

int main() {

    cin >> n >> q;
    for(int i=0; i<n; ++i) cin >> aa[i];
    build();

    int type, val, a,b,x;
    while(q--) {
        cin >> type >> a >> b;
        if(type==1) cout << query(a-1, b) << endl;
        else cin >> val, update(a-1, b, val);
    }

    return 0;
}
