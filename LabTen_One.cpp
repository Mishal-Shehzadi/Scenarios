#include <iostream>
using namespace std;

struct Node {
    int id;
    Node* left;
    Node* right;
};

Node* createNode(int id) {
    Node* newNode = new Node();
    newNode->id = id;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int id) {
    if (root == NULL) return createNode(id);

    if (id < root->id)
        root->left = insert(root->left, id);
    else if (id > root->id)
        root->right = insert(root->right, id);

    return root;
}

void preOrder(Node* root) {
    if (root == NULL) return;
    cout << root->id << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node* root) {
    if (root == NULL) return;
    inOrder(root->left);
    cout << root->id << " ";
    inOrder(root->right);
}

void postOrder(Node* root) {
    if (root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->id << " ";
}

void traverse(Node* root) {
    cout << "Preorder:  ";
    preOrder(root);
    cout << "\nInorder:   ";
    inOrder(root);
    cout << "\nPostorder: ";
    postOrder(root);
    cout << endl;
}

void search(Node* root, int id) {
    while (root != NULL) {
        if (root->id == id) {
            cout << "Found" << endl;
            return;
        }
        if (id < root->id)
            root = root->left;
        else
            root = root->right;
    }
    cout << "Not found" << endl;
}

Node* findMin(Node* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

Node* deleteNode(Node* root, int id) {
    if (root == NULL) return root;

    if (id < root->id)
        root->left = deleteNode(root->left, id);
    else if (id > root->id)
        root->right = deleteNode(root->right, id);
    else {
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* temp = findMin(root->right);
        root->id = temp->id;
        root->right = deleteNode(root->right, temp->id);
    }
    return root;
}

int main() {
    Node* root = NULL;
    int books[] = { 25, 17, 38, 12, 22, 45, 32, 9, 50, 19, 28, 40 };

    for (int i = 0; i < 12; i++) {
        root = insert(root, books[i]);
    }

    traverse(root);

    cout << "\nSearching for 32: ";
    search(root, 32);

    cout << "Searching for 100: ";
    search(root, 100);

    cout << "\nDeleting 17...\n";
    root = deleteNode(root, 17);
    traverse(root);

    return 0;
}
