#include <bits/stdc++.h>

typedef long long ll;

#define pb push_back
#define mp make_pair
#define poiu(n) for(int i=0; i < n; i++)
#define MOD 1000000007
#define endl '\n'

template<typename T>
void max_self(T& a, T b) { a=a>b?a:b; }
template<typename T>
void min_self(T& a, T b) { a=a<b?a:b; }

using namespace std;

const int mxN = 2005;

int n, K, q;
int temp_one, temp_two;

int a[mxN];
int st[mxN][20];
int logtable[mxN+1];

void initialise() {
    for(int i=0; i<n; ++i)
        st[i][0]=a[i];

    for(int j=1; j<=K; ++j)
        for(int i=0; i+(1<<j)<=n; ++i)
            st[i][j]=min(st[i][j-1], st[i+(1<<(j-1))][j-1]);
}

int query(int L, int R) {
    int temp = logtable[R-L+1];
    return min(st[L][temp], st[R-(1<<temp)+1][temp]);
}


int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> q;

    for(int i=2; i<=n; ++i)
        logtable[i]=logtable[i>>1]+1;

    K=1;
    while(1<<(K+1)<=n)
        K+=1;

    for(int i=0; i<n; ++i)
        cin>>a[i];

    initialise();

    for(int i=0; i<q; ++i) {
        cin >> temp_one >> temp_two;
        cout << query(temp_one, temp_two) << endl;
    }

    return 0;

}

