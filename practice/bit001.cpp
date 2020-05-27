
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

int bit[101];

void update(int x, int value) {
    while(x <= n)
        bit[x]+=value, x+=x&-x;
}

int query(int end) {
    int res = 0;
    while(end>0)
        res+=bit[end], end-=end&-end;
    return res;
}


int n;


int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    


    return 0;

}

