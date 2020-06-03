#include <bits/stdc++.h>

using namespace std;

const int mxV = 1e5+5;
const int mxE = 1e5+5;

int V, E, start, a,b,x;
vector<array<int, 2>> adj[mxV];
int dists[mxV];
bool vis[mxV];

int main() {
    cin >> V >> E;
    cin >> start;
    for(int i=0; i<E; ++i)
        cin >> a >> b >> x, adj[a].push_back({x, b});
    
    priority_queue<array<int,2>, vector<array<int, 2>>, greater<array<int,2>>> qq;
    qq.push({0, start});
    while(!qq.empty()) {
        array<int, 2> u = qq.top(); qq.pop();
        if(vis[u[1]]) continue;
        vis[u[1]] = true; dists[u[1]] = u[0];
        for(array<int, 2> v : adj[u[1]])
            if(!vis[v[1]]) qq.push({u[0]+v[0], v[1]});
    }

    for(int i=1; i<=V; ++i)
        cout << dists[i] << ' ';
    cout << endl;

    return 0;
}
