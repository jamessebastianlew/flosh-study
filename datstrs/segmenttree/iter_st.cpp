#include <bits/stdc++.h>
using namespace std;

const int MAX_N=100001;

int st[MAX_N*2];
int n, q;
int l, r;
int type, ind, value;

void build() {
    for(int i=n-1;i>0;i--)
        st[i]=max(st[i<<1],st[i<<1|1]);
}

int query(int l, int r) {
    int temp = 0;
    for(l+=n, r+=n; l < r; l>>=1, r>>=1) {
        if(l&1) temp=max(temp,st[l++]);
        if(r&1) temp=max(temp,st[--r]);
    }
    return temp;
}

void update(int ind, int v) {
    for(st[ind+=n]=v; ind>0; ind>>=1)
        st[ind]=max(st[ind],v);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> q;

    for(int i=n; i<2*n; i++)
        cin >> st[i];
    
    build();
    for(int i=0; i<q; i++) {
        cin >> type;
        if(type==1) {
            cin >> l >> r;
            l--,r--;
            cout << query(l,r+1) << '\n';
        }
        if(type==2) {
            cin >> ind >> value;
            update(ind, value);
        }
    }

    return 0;

}

