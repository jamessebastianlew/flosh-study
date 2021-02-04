#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

// come back to https://gist.github.com/markormesher/59b990fba09972b4737e7ed66912e044
// for more information and
// http://www.cs.cmu.edu/~guyb/realworld/papersS04/KaSa03.pdf
// for a healthy dose of intuition

using namespace std;

// assuming that s is composed of 'a'-'z'
// returns the suffix array

vector<int> skew(vector<int> s) {
    // construct s1 and s2
    const int n = s.size();
    s.push_back(-1); s.push_back(-1);
    const int nmod = 3 - n % 3;
    vector<array<int,3>> s1, s2;

    for(int i=0, j=0; i+1<n; i+=3, ++j) {
        s1.push_back({s[i+1], s[i+2], s[i+3]});
        s2.push_back({s[i+2], s[i+3], s[i+4]});
    }

    const int p = s1.size(), q = s2.size();

    vector<array<int,4>> s12; // combine into one list // {...s1[i], position, 1 or 2, org pos}
    for(int i=0; i<(int)s1.size(); ++i) s12.push_back({s1[i][0], s1[i][1], s1[i][2], s12.size(), 1, i});
    for(int i=0; i<(int)s2.size(); ++i) s12.push_back({s2[i][0], s2[i][1], s2[i][2], s12.size(), 2, i});

    // pretend to sort with radix sort the combined list
    // and assign a rank to each one
    sort(s12.begin(), s12.end());

    vector<int> s1_rank(p), s2_rank(q);
    for(int i=0; i<(int)s12.size(); ++i) {
        if(s12[i][4] == 1) s1_rank[s12[i][5]] = i;
        else s2_rank[s12[i][5]] = i;
    }


    // now we have made a string, and its letters have been ranked

    vector<int> mod_suf = skew(s1 + s2);
    

    return {};
};

int main() {
    string s;
    cin >> s;

    const int n = s.size();

    cout << s << endl;

    return 0;
}
