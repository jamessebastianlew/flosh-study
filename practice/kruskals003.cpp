#include <bits/stdc++.h>

using namespace std;

int V, E, a,b,x;
const int mxV = 1e5+5;
const int mxE = 1e5+5;

int uf[mxV];
int find(int x) { return uf[x]==x?x:uf[x]=find(uf[x]); }
void un(int u, int v) { uf[find(u)] = v; }

array<int,3> edges[mxV];
vector<array<int,3>> mst;

int main() {
    cin >> V >> E;
    for(int i=0; i<E; ++i) 
        cin >> edges[i][1] >> edges[i][2] >> edges[i][0];

    for(int i=1; i<=V; ++i) uf[i]=i;
    sort(edges, edges+E);

    for(array<int, 3> e : edges)
        if(find(e[1])!=find(e[2])) mst.push_back(e), un(e[1], e[2]);

    cout << endl;
    for(array<int,3> e : mst) {
        for(int i=0; i<3; ++i)
            cout << e[i] << ' ';
        cout << endl;
    }

    return 0;
}
