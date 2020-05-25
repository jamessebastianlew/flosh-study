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

int n;
int a, b, q;
int temp;
int bit[1001];

//intialisation in O(N)
void init() {
    int j;
    for(int i = 1; i<=n; ++i ) { 
        j=i+(i&-i);
        if(j <= n) bit[j]+=bit[i];
    }
}

void update(int x, int val) {
    for(; x<=n; x+=x&-x) bit[x]+=val;
}

int query(int x) {
    int res = 0;
    for(; x>0; x-=x&-x) res+=bit[x];
    return res;
}

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;

    for(int i=1; i<=n; ++i)
        cin >> bit[i];

    init();

    for(int i=0; i<q; ++i) {
        cin >> a >> b;
        cout << (query(b)-query(a-1)) << endl;
    }

    return 0;
}

