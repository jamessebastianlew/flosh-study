
#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

const int mxs = 1e3;
const int mxn = 1e6;

int n, q;
int aa[mxn];
int bb[mxs];

int query(int left, int right) {
    int start_b = left / mxs, end_b = right / mxs;
    int res = 0;
    if(start_b == end_b) for(int i=left; i<=right; ++i) res += aa[i];
    else {
        for(int i=left; i<(start_b + 1) * mxs; ++i) res += aa[i];
        for(int i=start_b+1; i<end_b-1; ++i) res += bb[i];
        for(int i=end_b * mxs; i <=right; ++i) res += aa[i];
    }
    return res;
}

void update(int x, int val) {
    aa[x] = val;
    int block = x / mxs;
    bb[block] = 0;
    for(int i = block * mxs; i < block * (mxs + 1); ++i)
        bb[block] += aa[i];
}

int main() {
    cin >> n >> q;

    for(int i=0; i<n; ++i) cin >> aa[i];

    int num_blocks = (n + mxs - 1) / mxs;
    for(int i=0; i<num_blocks; ++i) {
        int end = min(n, (i+1)*mxs);
        bb[i] = 0;
        for(int j=i*mxs; j<end; ++j) bb[i] += aa[j];
    }

    int type,a,b;
    while(q--) {
        cin >> type >> a >> b;
        if(type == 1) cout << query(a, b) << endl;
        else update(a, b);
    }
    return 0;
}


