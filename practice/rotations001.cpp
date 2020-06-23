#include <bits/stdc++.h>

using namespace std;

typedef struct Node {
    int x,y;
    Node *left, *right;
} Node;

Node* rr(Node* root) {
    Node* l = root->left->right;
    Node* nw = root->left;
    root->left->right = root;
    root->left = l;
    return nw;
}

Node* lr(Node* root) {
    Node* r = root->right->left;
    Node* nw = root->right;
    root->right->left = root;
    root->right = r;
    return nw;
}

int main() {

    return 0;
}
