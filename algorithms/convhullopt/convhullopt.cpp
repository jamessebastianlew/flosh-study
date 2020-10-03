#include <bits/stdc++.h>

using namespace std;

int mxn = 1e5+5;

array<int, 2> lines[mxn];

int len;
array<int, 2> qq[mxn];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=0; i<n; ++i) for(int j=0; j<2; ++j) cin >> lines[i][j];

    sort(lines, lines+n, [](array<int,2> a, array<int,2> b){ return a[0] > b[0]; });

    qq[len++] = lines[0];
    for(int i=0; i<n; ++i) {
        lines[i]



    return 0;
}
