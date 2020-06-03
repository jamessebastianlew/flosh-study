#include <bits/stdc++.h>

using namespace std;

const int mxN = 1e5+5;

int n, q;

int uf[mxN];

void ms(int x) { uf[x]=x; }
int find(int x) { return uf[x]==x?x:uf[x]=find(uf[x]); }
void uni(int a, int b) { uf[find(a)] = b; }

int main() {

    cin >> n >> q;
    for(int i=1; i<=n; ++i) ms(i);

    int type, a, b;
    while(q--) {
        cin >> type >> a;
        if(type==1) cout << find(a) << endl;
        else cin >> b, uni(a, b);
    }

    return 0;
}
