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
    start--;

    root->right = solve(preOrder, inOrder, start, mid + 1, inE);
    root->left = solve(preOrder, inOrder, start, inS, mid - 1);

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

    vector<int> postorder;
    postorder.push_back(6);
    postorder.push_back(2);
    postorder.push_back(4);
    postorder.push_back(5);
    postorder.push_back(3);
    postorder.push_back(1);

    int start = postorder.size() - 1;
    int inS = 0;
    int inE = postorder.size()-1;

    Node* root = solve(postorder, inorder, start, inS, inE);

    inorderOfTree(root);

    return 0;
}