
#include <bits/stdc++.h>

typedef long long ll;

#define pb push_back
#define mp make_pair
#define forn(n) for(int i=0; i < n; i++)
#define MOD 1000000007
#define endl '\n'

template<typename T>
void max_self(T& a, T b) { a=a>b?a:b; }
template<typename T>
void min_self(T& a, T b) { a=a<b?a:b; }

using namespace std;

int n, q;
int K;

int a[1001];
int st[1001][10];
int logtab[1001];

void build() {
    for(int i=0; i<n; ++i) st[i][0]=a[i];

    for(int j = 1; j <= K; ++j)
        for(int i = 0; i+(1<<j)-1<n; ++i)
            st[i][j]=min(st[i][j-1], st[i+(1>>(j-1))][j-1]);
}

int query(int lo, int hi) {
    int temp = logtab[hi-lo+1];
    return min(st[lo-1][temp], st[hi-(1<<temp)][temp]);
}
    
int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;
    for(int i = 2; i <= 1000; ++i) logtab[i]=logtab[i>>1]+1;

    int lo = 0, hi = 31;
    while(lo+1<hi) {
        int mid = (lo+hi) >> 1;
        if( (1<<mid) <= n ) lo = mid;
        else hi = mid;
    }
    K = lo;
    cout << K << endl;

    for(int i=0; i<n; ++i) cin >> a[i];

    build();
    for(int i=0; i<n; ++i) {
        for(int j=0; j<=K; ++j)
            cout << st[i][j] << ' ';
        cout << endl;
    }

    while(q--) {
        cin >> lo >> hi;
        cout << query(lo,hi) << endl;
    }

    return 0;

}

