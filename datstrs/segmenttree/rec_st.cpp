#include <bits/stdc++.h>

typedef long long ll;
#define endl '\n'

using namespace std;

int n;
const int mxN = 10001;

int values[mxN];
int st_min[4*mxN+1];

void build(int id=1, int l=0, int r=n) {
    if (r-l<2) {
        st_min[id]=values[l];
        return;
    }

    int mid = (r+l)/2;
    build(2*id, l, mid);
    build(2*id+1, mid, r);
    st_min[id]=min(st_min[2*id], st_min[2*id+1]);
}

int min_query(int lo, int hi, int id=1, int l=0, int r=n) {
    if(r <= lo || l >= hi)
        return INT_MAX;
    if(l >= lo && r <=hi)
        return st_min[id];
    
    int mid = (l+r)/2;
    int min_left = min_query(lo, hi, 2*id, l, mid);
    int min_right = min_query(lo, hi, 2*id+1, mid, r);
    return min(min_left, min_right);
}

void update(int x, int val, int id=1, int l=0, int r=n) {
    if( r <= x || l > x ) return;
    if( r-l<2 ) {
        st_min[id]=val;
        return;
    }
    
    int mid = (l+r)/2;

    update(x, val, 2*id, l, mid);
    update(x, val, 2*id, mid, r);
    st_min[id]=min(st_min[2*id], st_min[2*id+1]);
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> n >> q;

    for(int i=0; i<n; i++) cin >> values[i];
    
    build();
    
    int left, right;
    int type;
    for(int i=0; i<q; i++) {
        cin >> type >> left >> right;
        if(type==1)
            update(left-1, right);
        else
            cout << min_query(left-1, right) << endl;
    }

    return 0;
}

