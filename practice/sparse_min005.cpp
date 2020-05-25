#include <bits/stdc++.h>

using namespace std;

const int mxN = 1e5+5;
const int mxK = 21;

int st[mxN][mxK];
int a[mxN];
int log_table[mxN];

int n, q;
int x, y;
int K;

void build(){
    for(int i=0; i<n; ++i)
        st[i][0] = a[i];

    for(int k=1; k<=K; ++k)
        for(int i=0; i+(1<<k)-1 < n; ++i)
            st[i][k] = min(st[i][k-1], st[i+(1<<(k-1))][k-1]);
}

int query(int L, int R){
    int temp = log_table[R-L+1];
    return min(st[L][temp], st[R-(1<<temp)+1][temp]);
}

int main() {

    cin >> n >> q;

    for(int i=0; i<n; ++i) cin >> a[i];
    for(int i=2; i<=n; ++i) log_table[i] = log_table[i>>1]+1;
    K = log_table[n];
    build();

    while(q--) {
        cin >> x >> y;
        cout << query(x-1, y-1) << endl;
    }

    return 0;
}
