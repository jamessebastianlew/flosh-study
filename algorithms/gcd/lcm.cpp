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

int lcm(int a, int b) {
    return a*b/gcd(a,b);
}

int main() {
    cin >> a >> b;
    cout << lcm(a, b) << endl;

    return 0;
}
