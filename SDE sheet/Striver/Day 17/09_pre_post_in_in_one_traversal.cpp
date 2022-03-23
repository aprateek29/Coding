#include <iostream>
#include <stack>
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


void solve(Node* root) {
    stack<pair<Node*, int>> s;
    s.push({root, 1});

    vector<int> postorder;
    vector<int> preorder;
    vector<int> inorder;

    while (!s.empty()) {
        pair<Node*, int> p = s.top();
        s.pop();

        Node* t = p.first;
        int times = p.second;

        if (times == 1) {
            preorder.push_back(t->data);
            s.push({t, times+1});
            if (t->left)
                s.push({t->left, 1});
        } else if (times == 2) {
            inorder.push_back(t->data);
            s.push({t, times+1});
            if (t->right)
                s.push({t->right, 1});
        } else {
            postorder.push_back(t->data);
        }
    }

    for (auto i : preorder) 
        cout << i << " ";
    cout << endl;

    for (auto i : inorder)
        cout << i << " ";
    cout << endl;

    for (auto i : postorder)
        cout << i << " ";
}


int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    solve(root);
    return 0;
}