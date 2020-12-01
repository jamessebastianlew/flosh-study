#include <bits/stdc++.h>

using namespace std;

const int mxn = 1e5+5;
int lps[mxn];

int main() {
    string s;
    cin >> s;
    const int n = s.size();

    lps[0] = 0;
    int len = 0;
    int cnt = 0;
    for(int i=1; i<n; ++i) {
        while(len > 0 and s[len] != s[i]) len = lps[len-1];
        if(s[i] == s[len]) ++len;
        lps[i] = len;
    }

    for(int i=0; i<n; ++i) cout << lps[i] << ' '; cout << endl;

    return 0;
}


