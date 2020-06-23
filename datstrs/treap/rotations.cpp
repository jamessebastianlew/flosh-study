#include <bits/stdc++.h>

using namespace std;

struct Node;
typedef struct Node Node;

struct Node {
    int x, y;
    Node *left, *right;
};

Node* left_rotate(Node* root) {
    Node* r = root->right->left;
    Node* olr = root->right;
    root->right->left = root;
    root->right = r;
    return olr;
}

Node* right_rotate(Node* root) {
    Node* l = root->left->right;
    Node* oll = root->left;
    root->left->right = root;
    root->left = l;
    return oll;
}


int main() {


    return 0;
}
