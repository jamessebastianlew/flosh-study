#include <bits/stdc++.h>

using namespace std;

const int mxV = 1e5+5;

struct Node;
typedef struct Node Node;

struct Node {
    int x, y;
    Node *left, *right;
};

Node* rr(Node* root) {
    Node* l = root->left->right;
    Node* nw = root->left;
    root->left->right = root;
    root->left = l;
    return nw;
}

Node* lr(Node* root) {
    Node* r = root->left->right;
    Node* nw = root->right;
    root->right->left = root;
    root->right = r;
    return nw;
}

void merge(Node* root1, Node* root2) {
    if(!root1) return root2;
    if(!root2) return root1;
    if(root1->y > root2->y) {
        root1->right = merge(root1->right, root2)
        return root1;
    } else {
        root2->left = merge(root1, root2->left)
        return root2;
    }
}

void split(Node* root, int x, Node* &l, Node* &r) {
    if(!root) l=r=null;
    else if(x < root->key)
        split(root->left, x, l, root->left), r=root;
    else
        split(root->right, x, root->right, r), l=root;
}

bool find(Node* root, int need) {
    while(root && root->x != need) {
        if(root->x > need) root = root->left;
        else root = root->right;
    }
    return root?true:false;
}


int main() {
    cin >> V;
    for(int i=0; i<V; ++i) cin >> temp, insert(root);

    return 0;
}
