#include <bits/stdc++.h>

using namespace std;

//calculate n choose 1-k

const int mod = 1e9+7;
const int mxN = 1e5+5;
const int n = 2;

int dp[mxN];

int main() {
    dp[0] = 1;
    for(int i=0; i<n; ++i) for(int j=n; j; --j)
        dp[j] = (dp[j]+dp[j-1]) % mod;

    for(int i=0; i<=n; ++i)
        cout << dp[i] << ' ';
    cout << '\n';


    return 0;
}
