#include <bits/stdc++.h>

using namespace std;

const int mxN =1e5+5;

int n,q,k;
int bin[mxN];

int main() {
    cin >> n >> k; 
    bin[0] = 1;
    for(int i=1; i<=n; ++i) for(int j=i; j; --j)
        bin[j] = bin[j] + bin[j-1];

    for(int i=0; i<=n; ++i) cout << bin[i] << ' ';
    cout << endl;

    return 0;
}
