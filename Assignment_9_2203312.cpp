#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Node {
    public:
        int key;
        Node* left;
        Node* right;
        Node(int val) : key(val), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int key) {
    if (root == nullptr) {
        return new Node(key);
    }
    if (key < root->key) {
        root->left = insert(root->left, key);
    } else if (key > root->key) {
        root->right = insert(root->right, key);
    }
    return root;
}

Node* createBST(const string& file_path) {
    ifstream file(file_path);
    vector<int> keys;
    int key;
    while (file >> key) {
        keys.push_back(key);
    }
    file.close();

    Node* root = nullptr;
    for (int key : keys) {
        root = insert(root, key);
    }
    return root;
}

pair<Node*, int> searchKey(Node* root, int val) {
    Node* parent = nullptr;
    int direction = 0;
    Node* current = root;
    while (current != nullptr) {
        if (current->key == val) {
            return {parent, direction};
        }
        parent = current;
        if (val < current->key) {
            current = current->left;
            direction = -1;
        } else {
            current = current->right;
            direction = 1;
        }
    }
    return {nullptr, 0};
}

Node* rotateTree(Node* parent, Node* child, int direction) {
    if (direction == -1) {
        parent->left = child->right;
        child->right = parent;
    } else {
        parent->right = child->left;
        child->left = parent;
    }
    return child;
}

int main() {
    string file_path = "input.txt"; 
    Node* root = createBST(file_path);
    int val = 10;
    pair<Node*, int> ans = searchKey(root, val);
    if (ans.first != nullptr) {
        Node* child = (ans.second == -1) ? ans.first->left : ans.first->right;
        Node* new_root = rotateTree(ans.first, child, ans.second);
        if (ans.first == root) {
            root = new_root;
        }
    }
    return 0;
}