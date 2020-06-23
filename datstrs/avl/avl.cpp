#include <bits/stdc++.h>

using namespace std;

typedef struct Node {
    int val, nm_left, nm_right;
    Node *left, *right;
    Node(int v) {
        val = v; left = right = nullptr;
        nm_left = nm_right = 0;
    }
} Node;

class avltree {
    Node* root;

    void rr(Node* curr) {
        Node* lr = curr->left->right;
        Node* rt = curr;


    }
    void lr(Node* curr) {

    }

    // invariant, number of children in the left subtree = right+1 or right
    void fix(Node* broken) {
        if(broken->nm_left > nm_right+1) rr(broken);
        else if(broken->nm_left < nm_right) lr(broken);
    }

public:
    avltree() {
        root = nullptr;
    }

    ~avltree() {
        vector<Node*> stk;
        stk.push_back(root);

        while(!stk.empty()) {
            Node* curr = stk.back(); stk.pop_back();
            if(curr->left) stk.push_back(curr->left);
            else if(curr->right) stk.push_back(curr->right);

            delete curr;
        }
    }

    void insert(int val) {
        if(!root) { root = new Node(val); return; }

        Node* temp_root = root, *prev;
        while(temp_root) {
            prev = temp_root;
            if(val > temp_root->val) temp_root = temp_root->right;
            else temp_root = temp_root->left;
        }
        
        Node* temp = new Node(val);
        if(val > prev->val) prev->right = temp, ++prev->nm_right;
        else prev->left = temp, ++prev->nm_left;
    }

    Node* search(int val) {
        Node *temp_root = root;
        while(temp_root) {
            if(temp_root->val==val) return temp_root;
            if(val > temp_root->val) temp_root = temp_root->right;
            else temp_root = temp_root->left;
        }
        return nullptr;
    }
};

int main () {
    avltree T;

    int q, type, val;
    cin >> q;

    while(q--) {
        cin >> type >> val;
        if(type==1) {
            if(T.search(val)) cout << "found" << endl;
            else cout << "not found" << endl;
         } else T.insert(val);
    }

    return 0;
}
