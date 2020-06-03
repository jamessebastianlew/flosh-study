#include <bits/stdc++.h>

using namespace std;

const int mxN = 1e5+5;

int len;
int hp[mxN]; // heap

void shiftup(int u) {
    for(; u>1 && hp[u] < hp[u>>1]; u>>=1)
        swap(hp[u], hp[u>>1]);
}

void shiftdown(int u) {
    for(int x=u<<1; x<=len; x=u<<1) {
        int mn = x+1<=len? hp[x]<hp[x+1]?x:x+1 :x;
        if(hp[u] > hp[mn])
            swap(hp[u], hp[mn]), u = mn;
        else break;
    }
}

int get_min(int u) {
    return (u<<1|1)<=len? hp[u<<1]<hp[u<<1|1]?u<<1:u<<1|1 : u<<1;
}

void shiftdown2(int u) {
    int x; while((x=get_min(u))<=len && hp[u]>hp[x])
        swap(hp[u], hp[x]), u=x;
}

void insert(int x) {
    hp[++len] = x;
    shiftup(len);
}

int pop() {
    int x = hp[1];
    hp[1] = hp[len--], shiftdown2(1);
    return x;
}

int main() {

    int n, a;
    cin >> n;
    for(int i=0; i<n; ++i)
        cin >> a, insert(a);

    while(n--)
        cout << pop() << ' ';
    cout << endl;

    return 0;
}
