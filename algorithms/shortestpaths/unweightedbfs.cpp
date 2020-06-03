#include <bits/stdc++.h>

using namespace std;

const int mxV = 1e5+5;
const int mxE = 1e5+5;

vector<int> adj[mxV];
bool vis[mxV];

int main() {

    int V, E, a,b,x;
    int start, end;

    cin >> V >> E;
    cin >> start >> end;
    for(int i=0; i<E; ++i)
        cin >> a >> b, adj[a].push_back(b);

    queue<array<int, 2>> qq;
    qq.push({start, 0});
    while(!qq.empty()) {
        int u=qq.front()[0], x=qq.front()[1]; qq.pop();
        if(u==end) {cout << x << endl; break;}

        for(int v : adj[u])
            if(!vis[v]) qq.push({v,x+1}), vis[v]=true;
    }

    return 0;
}
