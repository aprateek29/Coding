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

int findMid(vector<int> inOrder, int ele, int inS, int inE) {
    for (int i = inS; i < inE; i++) {
        if (inOrder[i] == ele)
            return i;
    }
}

Node *solve(vector<int> preOrder, vector<int> inOrder, int &start, int inS, int inE) {
    if (inE < inS) return NULL;

    Node* root = new Node(preOrder[start]);
    int mid = findMid(inOrder, preOrder[start], inS, inE);
    start++;

    root->left = solve(preOrder, inOrder, start, inS, mid - 1);
    root->right = solve(preOrder, inOrder, start, mid + 1, inE);

    return root;
}

void inorderOfTree (Node* root) {
    if (!root) return;
    inorderOfTree(root->left);
    cout << root->data << " ";
    inorderOfTree(root->right);
}

int main() {

    vector<int> inorder;
    inorder.push_back(1);
    inorder.push_back(2);
    inorder.push_back(4);
    inorder.push_back(5);
    inorder.push_back(3);
    inorder.push_back(7);

    vector<int> preorder;
    preorder.push_back(4);
    preorder.push_back(2);
    preorder.push_back(5);
    preorder.push_back(1);
    preorder.push_back(3);
    preorder.push_back(7);

    int start = 0;
    int inS = 0;
    int inE = preorder.size()-1;

    Node* root = solve(preorder, inorder, start, inS, inE);

    inorderOfTree(root);

    return 0;
}