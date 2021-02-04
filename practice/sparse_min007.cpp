#include <bits/stdc++.h>

typedef long long ll;

#define fio(in, out) freopen(in, "r", stdin); freopen(out, "w", stdout);
#define cio() ios::sync_with_stdio(0); cin.tie(0);
#define endl '\n'

const int mod = 1e9+7;
template<typename T>
void amax(T& a, T b) { a=a>b?a:b; }
template<typename T>
void amin(T& a, T b) { a=a<b?a:b; }
template<typename T>
void amod(T a, T b) { return a>=b?a-b:a; }

using namespace std;

const int mxk = 14;
const int mxn = 1e5+1;

int n;
int st[mxn][mxk];
int aa[mxn];

void build() {
    for(int i=0; i<n; ++i) st[i][0] = aa[i];
    for(int j=1; j<mxk; ++j) for(int i=0; i + (1 << j) <= n; ++i)
        st[i][j] = min(st[i][j-1], st[i + (1 << (j-1))][j-1]);
}

int main() {
    cin >> n;
    for(int i=0; i<n; ++i) cin >> aa[i];
    memset(st, 0x3f, sizeof(st));
    build();
    int k = 0;
    while((1 << (k+1)) <= n) ++k;
    cout << k << endl;
    for(int j=k; j>=0; --j) { for(int i=0; i<n; ++i) cout << st[i][j] << ' '; cout << endl; }


    return 0;
}
