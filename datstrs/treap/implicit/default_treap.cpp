#include <bits/stdc++.h>

using namespace std;

typedef struct Node {
    int x,y;
    int num_nodes;
    Node *left, *right;
public:
    Node(int key) : x(key) {
        y = rand();
        num_nodes = 1;
        left = right = nullptr;
    }
    int get_left() { return left?left->num_nodes:0; }
    int get_right() { return right?right->num_nodes:0; }
} Node;

void calc_nodes(Node* root) {
    root->num_nodes = root->get_left() + root->get_right() + 1;
}

array<Node*, 2> split(Node* root, int ind) {
    if(!root) return {nullptr, nullptr};
    array<Node*, 2> temp;
    if(ind > root->get_left()) {
        temp = split(root->right, ind-(root->get_left()+1));
        root->right = temp[0];
        temp[0] = root;
    } else {
        temp = split(root->left, ind);
        root->left = temp[1];
        temp[1] = root;
    }
    return temp;
}

Node* merge(Node* left, Node* right) {
    if(!(left && right)) return left?left:right;
    if(left->y > right->y) {
        left->right = merge(left->right, right);
        calc_nodes(left);
        return left;
    } else {
        right->left = merge(right->left, left);
        calc_nodes(right);
        return right;
    }
    return nullptr;
}

void insert(Node*& root, int ind, int val) {
    auto temp = split(root, ind);
    temp[0] = merge(temp[0], new Node(val));
    root = merge(temp[0], temp[1]);
}

void begin(Node*& root, int n) {
    int val;
    for(int i=0; i<n; ++i) cin >> val, insert(root,i,val);
}

void inorder_print(Node* root) {
    if(!root) return;
    inorder_print(root->left);
    cout << root->x << ' ';
    inorder_print(root->right);
}

void destroy(Node* root) {
    if(!root) return;
    destroy(root->left); destroy(root->right);
    delete root;
}

int main() {
    Node* root = nullptr;
    begin(root, 10);
    inorder_print(root);

    destroy(root);
    return 0;
}
