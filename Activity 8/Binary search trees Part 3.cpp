#include <iostream>
#include <stdexcept>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

int findMaxValue(TreeNode* root) {
    if (root == nullptr) {
        throw invalid_argument("Tree is empty.");
    }

    TreeNode* current = root;

    while (current->right != nullptr) {
        current = current->right;
    }

    return current->val;
}

int main() {

    TreeNode* root = new TreeNode(20);
    root->left = new TreeNode(10);
    root->right = new TreeNode(30);
    root->right->left = new TreeNode(25);
    root->right->right = new TreeNode(500);

    try {
        cout << "Greatest value in BST: " << findMaxValue(root) << endl;
    }
    catch (const exception& e) {
        cerr << e.what() << endl;
    }

    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
