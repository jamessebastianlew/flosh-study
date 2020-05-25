
#include <bits/stdc++.h>

typedef long long ll;

#define fortests(i, t) for(int i = 1; i<=t; ++i) cout << "Case " << i << ": "
#define pb push_back
#define mp make_pair
#define forn(n) for(int i=0; i < n; i++)
#define MOD 1000000007
#define poius(x) ((int)(x).size())
#define endl '\n'

template<typename T>
void amax(T& a, T b) { a=a>b?a:b; }
template<typename T>
void amin(T& a, T b) { a=a<b?a:b; }

using namespace std;

int n;

int bit[1001];

void update(int x, int value) {
    for(; x <= n; x+=(x&-x)) bit[x]+=value;
}
int query(int x) {
    int res = 0;
    for(; x > 0; x-=(x&-x)) res += bit[x];
    return res;
}

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    n = 1001;

    update(3, 2);
    update(4, 5);

    cout << query(1000) << endl;


    


    return 0;

}

