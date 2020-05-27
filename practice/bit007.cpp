
#include <bits/stdc++.h>

typedef long long ll;

#ifdef FLOSH
    #define debug(something) something
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

using namespace std;

int n;
const int mxN = 1e5+5;
int bit[mxN];

#define lsb(x) (x&-x)
void build() {
    for(int i=0; i<n; ++i) 
        if(i+lsb(i) < n) bit[i+lsb(i)] += bit[i];
}
void update(int x, int val) {
    for(; x < mxN; x+=lsb(x) ) bit[x]+=val;
}
int query(int x) {
    int res = 0;
    for(; x > 0; x-=lsb(x)) res+=bit[x];
    return res;
}

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    


    return 0;

}

