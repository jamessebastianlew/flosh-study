#include <bits/stdc++.h>

using namespace std;

int n, a;
const int mxN = 1e5+5;

int len;
int hp[mxN];

void shiftup(int u) {
    for(; u>1 && hp[u>>1] > hp[u]; u>>=1)
        swap(hp[u], hp[u>>1]);
}

int get_mn(int u) {
    return (u<<1|1)<=len?hp[u<<1]<hp[u<<1|1]?u<<1:u<<1|1:u<<1;
}
// new view, become the mn child and swap
void shiftdown(int u) {
    int x; while((x=get_mn(u))<=len && hp[x] < hp[u])
        swap(hp[x], hp[u]), u = x;
}

void insert(int val) {
    hp[++len] = val;
    shiftup(len);
}

int pop() {
    swap(hp[len--], hp[1]);
    shiftdown(1);
    return hp[len+1];
}

int main() {
    cin >> n;
    for(int i=0; i<n; ++i) 
        cin >> a, insert(a);

    for(int i=0; i<n; ++i)
        cout << pop() << ' ';
    cout << endl;

    return 0;
}
