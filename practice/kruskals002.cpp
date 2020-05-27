#include <bits/stdc++.h>

using namespace std;

int V, E, a,b,x;
const int mxV = 1e5+5;
const int mxE = 1e5+5;

vector<array<int,3>> edges; // weight, u, v
vector<array<int,3>> mst;

int leader[mxV];
int find(int u) { return leader[u]==u?u:leader[u]=find(leader[u]); }
void uni(int u, int v) { leader[find(u)] = v; }



int main() {

    edges.reserve(mxE);
    cin >> V >> E;
    for(int i=0; i<E; ++i)
        cin >> a >> b >> x, edges.push_back({x,a,b});
    for(int i=1; i<=V; ++i) leader[i]=i;

    sort(edges.begin(), edges.end());
    for(auto edge : edges)
        if(find(edge[0])!=find(edge[1]))
            uni(edge[0], edge[1]), mst.push_back(edge);

    return 0;
}
