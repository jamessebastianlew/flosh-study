#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
//defining a tree that can be indexed like an array

int main() {
	indexed_set s;
	s.insert(2);
	s.insert(3);
	s.insert(7);
	s.insert(9);

	//returning an iterator to the element at a given position
	auto x = s.find_by_order(2);
	auto y = s.order_of_key(7);
	cout << x << ' ' << y;

}


