#include <bits/stdc++.h>

using namespace std;

const int mxN = 1e5+5;
int aa[mxN];
int countsort[mxN];

int main() {

    int n, a, len=0;
    cin >> n;
    for(int i=0; i<n; ++i) cin >> a, assert(a>=0 && a<mxN), ++countsort[a];
    for(int i=0; i<mxN; ++i) while(countsort[i]--) aa[len++]=i;
    for(int i=0; i<len; ++i) cout << aa[i] << endl;

    return 0;
}
