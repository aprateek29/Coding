#include <iostream>
#include <vector>
using namespace std;


class Node {
    public:
        int data;
        Node* left;
        Node* right;

        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};


void solve(Node* root, vector<int> op, vector<vector<int>> &res) {
    if (!root) {
        return;
    }
    op.push_back(root->data);
    if (!root->left && !root->right) {
        res.push_back(op);
        return;
    }
    solve(root->left, op, res);
    solve(root->right, op, res);
}


int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    vector<int> op;
    vector<vector<int>> res;

    solve(root, op, res);
    for (auto i : res) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}