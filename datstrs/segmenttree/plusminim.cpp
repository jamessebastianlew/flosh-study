#include <bits/stdc++.h>

using namespace std;

const int mxN = 1e5+5;

int n, q;
int st[4*mxN];
int dd[4*mxN];
int aa[mxN];

#define lc id<<1
#define rc id<<1|1

void push(int id) {
    st[lc]+=dd[id]; st[rc]+=dd[id];
    dd[lc]+=dd[id]; dd[rc]+=dd[id];
    dd[id] = 0;
}

void build(int id=1, int l=0, int r=n) {
    if(r-l<2) { st[id] = aa[l]; return; }
    int mid = (l+r)>>1;
    build(lc,l,mid); build(rc,mid,r);
    st[id]=min(st[lc],st[rc]);
}

void update(int lo, int hi, int val, int id=1, int l=0, int r=n) {
    if(r<=lo || l>=hi) return;
    if(l>=lo && r<=hi) { st[id]+=val; dd[id]+=val; return;}
    int mid = (l+r)>>1;
    update(lo,hi,val,lc,l,mid); update(lo,hi,val,rc,mid,r);
    st[id] = min(st[lc], st[rc]);
}

int query(int lo, int hi, int id=1, int l=0, int r=n) {
    if(r<=lo || l>=hi) return 0x3f3f3f3f;
    if(l>=lo && r<=hi) return st[id];
    push(id); int mid = (l+r)>>1;
    return min(query(lo,hi,lc,l,mid), query(lo,hi,rc,mid,r));
}

int main() {
    cin >> n >> q;
    for(int i=0; i<n; ++i) cin >> aa[i];
    build();

    int type, val, a, b;
    while(q--) {
        cin >> type >> a >> b;
        if(type==1) cout << query(a-1, b) << endl;
        else cin >> val, update(a-1, b, val);
    }

    return 0;
}
