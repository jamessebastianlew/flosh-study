#include <bits/stdc++.h>

using namespace std;

int n;

bitset<100> a;
int alternative;

int main() {
    
    cin >> n;

    int temp;
    for(int i=0; i<n; ++i) {
        cin >> temp;
        //either
        a[temp] = 1;
        //or
        alternative |= (1<<temp);
    }

    return 0;
}


