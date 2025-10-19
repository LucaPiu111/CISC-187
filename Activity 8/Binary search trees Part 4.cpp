#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

Node* insert(Node* root, int val) {
    if (root == nullptr) {
        return new Node(val);
    }

    if (val < root->data) {
        root->left = insert(root->left, val);
    }
    else {
        root->right = insert(root->right, val);
    }

    return root;
}

void inorder(Node* root) {
    if (root == nullptr)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    int arr[] = { 1, 11, 9, 2, 4, 10, 6, 3, 8 };
    int size = sizeof(arr) / sizeof(arr[0]);

    Node* root = nullptr;

    for (int i = 0; i < size; ++i) {
        root = insert(root, arr[i]);
    }

    cout << "In-order Traversal of BST: ";
    inorder(root);
    cout << endl;

    return 0;
}