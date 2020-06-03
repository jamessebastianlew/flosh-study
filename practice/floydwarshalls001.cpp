#include <bits/stdc++.h>

using namespace std;

void amin(int& a, int b) { a=a<b?a:b; }
const int mxV = 1e2+5;
const int mxE = 1e2+5;

int V, E, a,b,x, start;

int adj[mxV][mxV];

int main() {
    memset(adj,0x3f,sizeof(adj));
    cin >> V >> E;
    for(int i=0; i<E; ++i)
        cin >> a >> b >> x, adj[a][b] = x;

    for(int i=1; i<=V; ++i)
        adj[i][i] = 0;

    for(int k=1; k<=V; ++k)
        for(int i=1; i<=V; ++i)
            for(int j=1; j<=V; ++j)
                amin(adj[i][j], adj[i][k] + adj[k][j]);

    for(int i=1; i<=V; ++i) {
        for(int j=1; j<=V; ++j)
            cout << setw(11) << adj[i][j];
        cout << endl;
    }

    return 0;
}
