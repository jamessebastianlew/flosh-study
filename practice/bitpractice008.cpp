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

const int mxN = 1001;
int bit[mxN];

void init() {
    for(int i=1; i<mxN; ++i) {
        int temp = i+(i&-i);
        if(temp<mxN) bit[temp]+=bit[i];
    }
}

void update(int x, int val) {
    for(; x<mxN; x+=x&-x) bit[x]+=val;
}

int query(int x) {
    int res = 0;
    for(; x>0; x-=x&-x) res+=bit[x];
    return res;
}



int n;

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    


    return 0;

}

