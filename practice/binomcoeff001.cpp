#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9+7;
const int mxN = 1e5+5;

int n, k;
int bin[mxN];

int main() {
    cin >> n >> k;
    
    bin[n] = 1;
    for(int i=n; i; --i) for(int j=1; j<=n; ++j)
        bin[j] = (bin[j+1] + bin[j]) % mod;

    cout << bin[k] << '\n';

    return 0;
}
