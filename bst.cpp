#include <iostream>
using namespace std;

// Definition of a BST Node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Insert a value into the BST
Node* insert(Node* root, int val) {
    if (!root) {
        return new Node(val); // Create a new node if root is null
    }
    if (val < root->data) {
        root->left = insert(root->left, val); // Insert in the left subtree
    } else if (val > root->data) {
        root->right = insert(root->right, val); // Insert in the right subtree
    }
    return root;
}

// Search for a value in the BST
bool search(Node* root, int val) {
    if (!root) {
        return false; // Value not found
    }
    if (root->data == val) {
        return true; // Value found
    }
    if (val < root->data) {
        return search(root->left, val); // Search in the left subtree
    }
    return search(root->right, val); // Search in the right subtree
}

// Find the minimum value node in a BST (helper for deletion)
Node* findMin(Node* root) {
    while (root && root->left) {
        root = root->left;
    }
    return root;
}

// Delete a value from the BST
Node* deleteNode(Node* root, int val) {
    if (!root) {
        return root; // Value not found
    }
    if (val < root->data) {
        root->left = deleteNode(root->left, val); // Delete from the left subtree
    } else if (val > root->data) {
        root->right = deleteNode(root->right, val); // Delete from the right subtree
    } else {
        // Node to be deleted is found
        if (!root->left) {
            Node* temp = root->right;
            delete root;
            return temp; // Replace with right child
        } else if (!root->right) {
            Node* temp = root->left;
            delete root;
            return temp; // Replace with left child
        }

        // Node with two children
        Node* temp = findMin(root->right); // Find the in-order successor
        root->data = temp->data; // Replace the value
        root->right = deleteNode(root->right, temp->data); // Delete the successor
    }
    return root;
}

// In-order traversal of the BST
void inOrder(Node* root) {
    if (root) {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}

// Driver code
int main() {
    Node* root = nullptr;

    // Inserting values into the BST
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    cout << "In-order traversal: ";
    inOrder(root);
    cout << endl;

    // Searching for values
    cout << "Search 40: " << (search(root, 40) ? "Found" : "Not Found") << endl;
    cout << "Search 90: " << (search(root, 90) ? "Found" : "Not Found") << endl;

    // Deleting a value
    cout << "Deleting 20\n";
    root = deleteNode(root, 20);

    cout << "In-order traversal after deletion: ";
    inOrder(root);
    cout << endl;

    return 0;
}
