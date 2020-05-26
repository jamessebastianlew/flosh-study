#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int mxN =1e5+5;
int siv[mxN];


int main() {

    for(int i=2; i<mxN; ++i)
        if(!siv[i]) for(ll pwr=i; pwr<mxN; pwr*=i)
            for(int temp=pwr; temp<mxN; temp+=pwr)
                ++siv[temp];

    // printing the number of prime factors
    for(int i=1; i<=50; ++i)
        cout << setw(2) << i << setw(0) << ": " << siv[i] << '\n';

    return 0;
}
