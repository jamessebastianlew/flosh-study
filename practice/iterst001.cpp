#include <bits/stdc++.h>

using namespace std;

const int mxN = 1e5+5;

void amin(int& a, int b) { a=a<b?a:b; }

int n, q;
int st[2*mxN];
int a[mxN];

// range query and point update
void init() {
    for(int i=0; i<n; ++i)
        st[i+n] = a[i];
    for(int i=n-1; i>0; --i)
        st[i] = min(st[i<<1], st[(i<<1)^1]);
}


void update(int x, int val) {
    for(st[x+=n]=val; x>0; x>>=1)
        amin(st[x], val);
}

int query(int L, int R) {
    int res = st[L+n];
    for(L+=n, R+=n; L<R; R>>=1, L>>=1) {
        if(L&1) amin(res, st[L++]);
        if(R&1) amin(res, st[--R]);
    }
    return res;
}

int main() {

    cin >> n >> q;
    for(int i=0; i<n; ++i) cin >> a[i];
    init();

    int L, R;
    while(q--) {
        cin >> L >> R;
        cout << query(L-1, R-1) << endl;
    }
    return 0;
}
    

