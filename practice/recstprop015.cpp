#include <bits/stdc++.h>

using namespace std;

const int mxn = 1e5+1;
int n;
int aa[mxn];
int st[4 * mxn][2]; // [id][value or delta]

#define lc id << 1
#define rc (id << 1) | 1

void prop(int id, int l, int r) {
    int mid = (l+r) >> 1;
    st[lc][1] += st[id][1]; st[rc][1] += st[id][1];
    st[lc][0] += st[id][1] * (mid - l); st[rc][0] += st[id][1] * (r-mid);
    st[id][1] = 0;
}

void build(int l=0, int r=n, int id=1) {
    st[id][1] = 0;
    if(r-l == 1) { st[id][0] = aa[l]; return; }
    int mid = (l+r) >> 1;
    build(l, mid, lc); build(mid, r, rc);
    st[id][0] = st[lc][0] + st[rc][0];
}

void update(int lo, int hi, int val, int id=1, int l=0, int r=n) {
    if(lo <= l && r <= hi) { st[id][0] += val * (r-l); st[id][1] += val; return; }
    if(r <= lo || hi <= l) return;
    int mid = (l+r) >> 1;
    prop(id, l, r);
    update(lo, hi, val, lc, l, mid); update(lo, hi, val, rc, mid, r);
    st[id][0] = st[lc][0] + st[rc][0];
}

int query(int lo, int hi, int id=1, int l=0, int r=n) {
    if(lo <= l && r <= hi) return st[id][0];
    if(r <= lo || hi <= l) return 0;
    int mid = (l+r) >> 1;
    prop(id, l, r);
    return query(lo, hi, lc, l, mid) + query(lo, hi, rc, mid, r);
}

int main() {
    cin >> n;
    for(int i=0; i<n; ++i) cin >> aa[i];
    build();
    cout << query(0, 10) << endl;
    update(0, 3, 2);
    cout << query(1, 5) << endl;
    for(int i=0; i<n; ++i) cout << query(i, i+1) << ' '; cout << endl;


    return 0;
}

