#include <bits/stdc++.h>
using namespace std;

const int mxn = 1e3 + 1;
const int mxk = 10 + 1;

int order[mxk][mxn];

int* calc_order(string s) {

    // initialise order
    s.push_back('\0');
    const int n = s.size();
    memset(order, 0, sizeof(order));

    for(int j=0; j<n; ++j) order[0][j] = (int) s[j];

    int aux[n];

    int last = 0;
    // sort substring of size 2**i
    for(int i=1; (1 << (i - 1)) < n; ++i) {
        for(int j=0; j<n; ++j) aux[j] = j;

        sort(aux, aux + n, [&](int a, int b){
            if(order[i-1][a] == order[i-1][b])
                return max(a, b) + (1 << (i-1)) < n && order[i-1][a + (1 << (i-1))] < order[i-1][b + (1 << (i-1))];
            else if(order[i-1][a] == order[i-1][b] && max(a, b) + (1 << (i-1)) >= n)
                return a < b;
            return order[i-1][a] < order[i-1][b];
        });

        int curr_pos = 0;
        for(int j=1; j<n; ++j) {
            if(order[i-1][aux[j]] == order[i-1][aux[j - 1]]
                    && max(aux[j], aux[j-1]) + (1 << (i-1)) < n
                    && order[i-1][aux[j] + (1<<(i-1))] == order[i-1][aux[j-1] + (1<<(i-1))]) {
                curr_pos = curr_pos;
            } else {
                ++curr_pos;
            }
            order[i][aux[j]] = curr_pos;
        }
        last = i;
    }


    // return the output
    int* output = new int[n];

    for(int i=0; i<n; ++i) output[i] = i;
    sort(output, output + n, [&](int a, int b){
        return order[last][a] < order[last][b];
    });

    return output;

}

int main() {
    string s;
    cin >> s;
    const int n = s.size();
    


    int* output = calc_order(s);

    for(int i=0; i<n + 1; ++i) cout << s.substr(output[i]) << endl;

    delete[] output;

    return 0;
}
