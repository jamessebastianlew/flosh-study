#include <bits/stdc++.h>

using namespace std;

int n, q, K;
const int mxN = 1e5+5;
const int mxK = 21;

int st[mxN][mxK];
int logtab[mxN];

void build() {
    for(int k=1; k<=K; ++k)
        for(int i=0; i+(1<<k)-1<n; ++i)
            st[i][k] = min(st[i][k-1], st[i+(1<<(k-1))][k-1]);
}

int query(int l, int r) {
    int temp = logtab[r-l+1];
    return min(st[l][temp], st[r-(1<<temp)+1][temp]);
}

int main() {
    cin >> n >> q;
    for(int i=0; i<n; ++i) cin >> st[i][0];
    for(int i=2; i<=n; ++i) logtab[i] = logtab[i>>1]+1;
    K=logtab[n];
    build();

    int a, b;
    while(q--) {
        cin >> a >> b;
        cout << query(a-1, b-1) << endl;
    }

    return 0;
}
