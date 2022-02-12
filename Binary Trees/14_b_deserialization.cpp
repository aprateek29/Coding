#include <iostream>
using namespace std;


class Node {
    public:
        char data;
        Node* left;
        Node* right;

        Node(char d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};


Node* solve(Node* root, string s, int &i) {
    if (s[i] == '*') {
        i++;
        return NULL;
    }

    root = new Node(s[i]);
    i++;
    root->left = solve(root, s, i);
    root->right = solve(root, s, i);

    return root;
}

void inorder(Node* root) {
    if (root) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

int main() {
    Node* root = NULL;
    string s = "124**5**36***";
    int index = 0;
    root = solve(root, s, index);

    inorder(root);
    return 0;
}