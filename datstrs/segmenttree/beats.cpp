#include <bits/stdc++.h>

using namespace std;

const int mxN = 1e5+5;
const int INF = 0x3f3f3f3f;
int n, q;


int st[4*mxN];
int firstmax[4*mxN];
int secondmax[4*mxN];
int frequency[4*mxN];
int dd[4*mxN];
int aa[mxN];

#define lc id<<1
#define rc id<<1|1

void smx(int &a, array<int,3> b) {
    for(x

void build(int id=1, int l=0, int r=n) {
    if(r-l<2) {
        st[id] = aa[l]; 
        secondmax[id] = -INF;
        firstmax[id]= aa[l];
        return;
    }
    int mid = (l+r)>>1;
    build(lc,l,mid); build(rc,mid,r);
    st[id] = st[lc]+st[rc];
    firstmax[id] = max(firstmax[lc], firstmax[rc]);



int main() {
    cin >> n >> q; 
    for(int i=0; i<n; ++i)
        cin >> aa[i];
