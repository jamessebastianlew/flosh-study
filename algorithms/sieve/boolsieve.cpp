#include <bits/stdc++.h>

using namespace std;

const int mxN = 1e5+5;
bool siv[mxN];

int main() {

    for(int i=2; i*i<mxN; ++i)
        if(!siv[i]) for(int j=i*i; j<mxN; j+=i)
            siv[j] = true;
    
    // printing the first 100 prime numbers
    for(int i=2; i<=100; ++i)
        if(!siv[i]) cout << i << endl;

    return 0;
}
