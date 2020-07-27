#include <bits/stdc++.h>

using namespace std;

const int mxn = 1e5+5;

int first_half(int val, int u) {
    return val>>(u>>1);
}

int second_half(int val, int u) {
    return val^(val>>(u>>1)<<(u>>1));
}

typedef struct node {
    int u, num_elem, max_elem;
    node* pred_key;
    unordered_map<int, node*> children;
    node(int sz) : u(sz) { num_elem = max_elem = 0; }
} node;


void insert(node* root, int val) {
    if(root->u == 0) root->max_elem = val, root->num_elem = 1;
    int key = first_half(val, root->u);
    if(!root->children[key]) root->children[key] = new node(root->u >> 1);
    insert(root->children[key], second_half(val));
}

int query(node* root, int val) {
    int key = first_half(val);
    if(!root->key
}
void insert(node* root, int val) {

}
int main() {
    return 0;
}
