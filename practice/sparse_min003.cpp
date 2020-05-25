#include <bits/stdc++.h>

typedef long long ll;

#ifdef FLOSH
    #define debug(something) something
#endif
#ifndef FLOSH
    #define inout(in, out) freopen(in, "r", stdin); freopen(out, "w", stdout);
#endif
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define poius(x) ((int)(x).size())
#define endl '\n'

template<typename T>
void amax(T& a, T b) { a=a>b?a:b; }
template<typename T>
void amin(T& a, T b) { a=a<b?a:b; }
template<typename T>
void sadd(T& a, T b) { a=(a+b)%MOD; }
template<typename T>
void ssub(T& a, T b) { a=((a-b)%MOD+MOD)%MOD; }

using namespace std;

const int mxN = 100001;
const int mxK = 21;
int n, q, a, b;
int K;
int log_table[mxN];

int st[mxN][mxK];

void build() {
    for(int k=1; k<=K; ++k)
        for(int i=0; i+(1<<k)-1 < n; ++i)
            st[i][k] = min(st[i][k-1], st[i+(1<<(k-1))][k-1]);
}

int query(int L, int R) {
    int temp = log_table[R-L+1];
    return min(st[L][temp], st[R-(1<<temp)+1][temp]);
}

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;

    for(int i=2; i<=n; ++i)
        log_table[i] = log_table[i>>1]+1;

    K = log_table[n];

    for(int i=0; i<n; ++i)
        cin >> st[i][0];
    build();

    while(q--) {
        cin >> a >> b;
        cout << query(a-1, b-1) << endl;
    }

    return 0;

}

