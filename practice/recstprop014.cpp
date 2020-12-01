
#include <bits/stdc++.h>

typedef long long ll;

using namespace std;
int n;

const int mxn = 1e5+5;
int aa[mxn];
int st[4*mxn];
int dd[4*mxn];

#define lc (id<<1)
#define rc (id<<1|1)

void push(int id) {
    st[lc] += dd[id]; st[rc] += dd[id];
    dd[lc] += dd[id]; dd[rc] += dd[id];
    dd[id] = 0;
}

void calc_node(int id) {
    st[id] = st[lc] + st[rc];
}

void build(int id=1, int l=0, int r=n) {
    if(l+1 == r) { st[id] = aa[l]; return; }
    int mid = (l+r) >> 1;
    build(lc, l, mid); build(rc, mid, r);
    calc_node(id);
}

int query(int lo, int hi, int id=1, int l=0, int r=n) {
    if(l >= hi || r <= lo) return 0;
    if(lo <= l && r <= hi) return st[id];
    int mid = (l+r)>>1;
    push(id);
    return query(lo,hi,lc,l,mid) + query(lo,hi,rc,mid,r);
}

void update(int lo, int hi, int val, int id=1, int l=0, int r=n) {
    if(l >= hi || r <= lo) return;
    if(lo <= l && r <= hi) { st[id] += val; dd[id] += val; return; }
    int mid = (l+r) >> 1;
    update(lo,hi,val,lc,l,mid); update(lo,hi,val,rc,mid,r);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i=0; i<n; ++i) cin >> aa[i];
    build();

    return 0;
}
