#include <bits/stdc++.h>

using namespace std;

typedef struct Node {
    int x,y,dd,num_nodes;
    Node *left, *right;
public:
    Node(int key) : x(key) { y = rand(); left = right = dd = 0; }
    int get_left() { return left?left->num_nodes:0; }
    int get_right() { return right?right->num_nodes:0; }
    void calc_nodes() { num_nodes = get_left() + get_right() + 1; }
    void push() {
        if(left) left->dd += dd, left->x += dd;
        if(right) right->dd += dd, right->x += dd;
        dd = 0;
    }
}

array<Node*, 2> split(Node* root, int ind) {
    if(!root) return {nullptr, nullptr};
    array<Node*, 2> temp;
    root->push();
    if(ind > root->get_left()) {
        temp = split(root->right, ind-(root->get_left()+1));
        root->right = temp[0];
        root->calc_nodes();
        temp[0] = root;
    } else {
        temp = split(root->left, ind);
        root->left = temp[1];
        root->calc_nodes();
        temp[1] = root;
    }
    return temp;
}

Node* merge(Node* root1, Node* root2) {
    if(!(root1&&root2)) return root1?root1:root2;
    if(root1->y > root2->y) {
        root1->push();
        root1->right = merge(root1->right, root2);
        root1->calc_nodes();
        return root1;
    } else {
        root2->push();
        root2->left = merge(root1, root2->left);
        root2->calc_nodes();
        return root2;
    }
    return nullptr;
}

void add_section(int l, int r 

int main() {

    return 0;
}
