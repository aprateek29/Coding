// Serialization is done when we want to transfer tree data;
// We can send tree as it is but it will take - 2*N + 2*N*pointer
// We can use two traveral like pre and in but will take - 2*N + 2*N
// 
// Best way to convert it into a string or array and add -1 or NULL when
// encountered null in a tree;

#include <iostream>
#include <vector>
#include <string>
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


void solve(Node* root, vector<string> &s) {

    if (!root) {
        s.push_back("*");
        return;
    }
    s.push_back(to_string(root->data));
    solve(root->left, s);
    solve(root->right, s);
}


int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    vector<string> s;
    solve(root, s);
    for (auto i : s) {
        cout << i << "";
    }
    return 0;
}