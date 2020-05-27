#include <bits/stdc++.h>

using namespace std;

int bit[1001];
int n, q;
int a, b;

void build() {
    for(int i=1; i<=n; ++i) {
        int temp = i+(i&-i);
        if(temp<=n) bit[temp]+=bit[i];
    }
}

void update(int x, int val) {
    for(; x<=n; x+=x&-x) bit[x]+=val;
}

int query(int x) {
    int res = 0;
    for(; x>0; x-=x&-x) res+=bit[x];
    return res;
}

int rangequery(int L, int R) {
    return query(R) - query(L-1);
}

int main() {

    cin >> n >> q;
    for(int i=1; i<=n; ++i) cin >> bit[i];
    build();

    while(q--) {
        cin >> a >> b;
        cout << rangequery(a, b) << endl;
    }

    return 0;
}
