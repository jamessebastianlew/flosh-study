#include <bits/stdc++.h>

using namespace std;

const int mxN = 1e5+5;

int V,E,a,b,x;
int in[mxN];
vector<int> ts, adj[mxN];

int main() {

    cin >> V >> E;
    for(int i=0; i<E; ++i) 
        cin >> a >> b, adj[a].push_back(b), ++in[b];

    queue<int> qq;
    for(int i=1; i<=V; ++i) if(!in[i]) qq.push(i);

    while(!qq.empty()) {
        int u = qq.front(); qq.pop();
        for(int v : adj[u]) if(!(--in[v])) qq.push(v);
        ts.push_back(u);
    }

    for(int v : ts) cout << v << ' ';
    cout << endl;

    return 0;
}
