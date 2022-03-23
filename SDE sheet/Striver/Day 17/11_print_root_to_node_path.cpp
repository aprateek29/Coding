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

bool solveUtil(Node* root, Node* n, vector<int> &v, bool &flag) {
    if (root) {
        v.push_back(root->data);
        if (root == n) {
            return true;
        }
        if (solveUtil(root->left, n, v, flag) || solveUtil(root->right, n, v, flag)) {
            return true;
        }
        v.pop_back();
        return false;
    }
}

void solve(Node* root, Node* n) {
    vector<int> v;
    bool flag = false;
    solveUtil(root, n, v, flag);
    for (auto i : v) {
        cout << i << " ";
    }

}


int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Node* given = root->left->right;
    solve(root, given);
    return 0;
}