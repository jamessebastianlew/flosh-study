#include <bits/stdc++.h>

using namespace std;

const int mxV = 1e5+5;
const int mxE = 1e5+5;

int V, E, a, b, x;
array<int, 3> edges[mxE]; // {weight, u, v}

//disjoint set
int uf[mxV];
inline void ms(int u) { uf[u] = u; }
int find(int u) {
    return uf[u]==u?u:uf[u]=find(uf[u]);
}
void un(int u, int v) { uf[find(u)] = uf[v]; }

int len = 0;
array<int, 3> mst[mxE];

int main() {

    cin >> V >> E;
    for(int i=0; i<E; ++i)
        cin >> edges[i][1] >> edges[i][2] >> edges[i][0];

    for(int i=1; i<=V; ++i) ms(i);

    sort(edges, edges+E);
    for(int i=0; i<E; ++i)
        if(find(edges[i][1]) != find(edges[i][2]))
            un(edges[i][1], edges[i][2]), mst[len++] = edges[i];


    cout << endl << "mst: " << endl;
    for(int i=0; i<len; ++i) {
        cout << mst[i][1] << ' ' << mst[i][2] << endl;
        cout << mst[i][0] << endl;
    }

    return 0;
}
