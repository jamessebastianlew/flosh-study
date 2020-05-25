
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

int n, k;
int K;
const int mxN = 1e5+5;
const int mxK = 30;

int log_table[mxN];
int st[mxN][mxK];

//read into st[i][0]
void init() {
    for(int k = 1; k <= K; ++k)
        for(int i=0; i+(1<<k)-1 < n; ++i)
            st[i][k] = min(st[i][k-1], st[i+(1<<(k-1))][k-1]);
}
int query(int a, int b) {
    int temp = log_table[b-a+1];
    return min(st[a][temp], st[b-(1<<temp)+1][temp]);
}

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;
    for(int i=2; i<mxN; ++i) log_table[i]=log_table[i>>1]+1;
    K = log_table[n];

    init();


    

    


    return 0;

}

