#include <bits/stdc++.h>

using namespace std;

const int mxN = 1e5+5;
int bit[mxN];
int a, b, n, q;

#define lsb(x) (x&-x)
void build() {
    for(int i=1; i<=n; ++i)
        if(i+lsb(i)<=n) bit[i+lsb(i)]+=bit[i];
}

void update(int x, int val) {
    for(; x<=n; x+=lsb(x)) bit[x]+=val;
}

int query(int x) {
    int res = 0;
    for(; x>0; x-=lsb(x)) res+=bit[x];
    return res;
}

int main() {
    cin >> n >> q;
    for(int i=1; i<=n; ++i) cin >> bit[i];
    build();

    while(q--) {
        cin >> a >> b;
        cout << query(b)-query(a-1) << endl;
    }

    return 0;
}
