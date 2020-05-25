#include <bits/stdc++.h>

using namespace std;

// we can generate each subset by recursively choosing
// and not choosing elements
//
// since we only ever process one permutation at a time
// we only ever need to store a single permuation stack

int n;

void perm_rec(vector<int> &perm_arr, int curr_item, vector<int> &items) {
	if(curr_item == n) {
		for(int i = 0; i < perm_arr.size(); i++)
			cout << perm_arr[i] << ' ';
		cout << endl;
		return;
	}
	
	
	perm_arr.push_back(items[curr_item]);
	perm_rec(perm_arr, curr_item+1, items);
	perm_arr.pop_back();
	perm_rec(perm_arr, curr_item+1, items);
}

int main() {
	vector<int> items = {7, 1, 12, 11};
	n = items.size();

	vector<int> perm_arr;
	perm_rec(perm_arr, 0, items);

	return 0;
}
