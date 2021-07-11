#include <bits/stdc++.h>

typedef long long ll;

#define cio() ios::sync_with_stdio(0); cin.tie(0);
#ifndef FLOSH
    #define fio(in, out) freopen(in, "r", stdin); freopen(out, "w", stdout);
#else
    #define fio(in, out) cio()
#endif
#define endl '\n'

const int mod = 1e9+7;
template<typename T>
void amax(T& a, T b) { a=a>b?a:b; }
template<typename T>
void amin(T& a, T b) { a=a<b?a:b; }
template<typename T>
void amod(T a, T b) { return a>=b?a-b:a; }

using namespace std;

const int mxn = 1e3+1;

bool vis[mxn];
int id[mxn];
bool in_stk[mxn];

vector<int> adj[mxn];
vector<int> stk;

int V,E,a,b,x;

int cnt = 0;

void calc_scc(int u) {
    vis[u] = true, in_stk[u] = true, id[u] = cnt++;
    stk.push_back(u);
    for(int v : adj[u]) {
        if(!vis[v]) calc_scc(v);
        if(in_stk[v]) id[u] = min(id[v], id[u]);
    }
    if(id[u] == u) {
        while(stk.back() != u)
            in_stk[stk.back()] = false, stk.pop_back();
    }
}


int main() {
    cio();
    cin >> V >> E;
    memset(in_stk, 0x01, sizeof(in_stk));
    for(int i=0; i<E; ++i) {
        cin >> a >> b;
        adj[a].push_back(b);
    }

    for(int u=0; u<V; ++u) if(!vis[u]) calc_scc(u);

    for(int i=0; i<V; ++i) cout << i << ' '; cout << endl;
    for(int i=0; i<V; ++i) cout << id[i] << ' '; cout << endl;
    return 0;
}
