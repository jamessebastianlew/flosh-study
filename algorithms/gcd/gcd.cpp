#include <bits/stdc++.h>

using namespace std;

int a, b;

int gcd(int a, int b) {
    while(b) {
        int temp = a%b;
        a = b;
        b = temp;
    }
    return a;
}

int main() {
    cin >> a >> b;
    cout << gcd(a, b) << endl;
}
