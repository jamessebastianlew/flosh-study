
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

const int mxN = 1001;
int bit[mxN];

void build() {
    for(int i=0; i<n; ++i)
        if(i+(i&-i) < mxN) bit[i+(i&-i)]+=bit[i];
}
void update(int x, int val) {
    for(; x < N; x+=x&-x) bit[x]+=val;
}
int query(int x) {
    int res = 0;
    for(; x > 0; x-=x&-x ) res+=bit[x];
    return res;
}


int n;

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    


    return 0;

}

