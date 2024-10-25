#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

class BST {
public:
    Node* root;

    BST() : root(NULL) {}

    Node* insert(Node* node, int val) {
        if (node == NULL) {
            return new Node(val);
        }
        if (val < node->data) {
            node->left = insert(node->left, val);
        } else {
            node->right = insert(node->right, val);
        }
        return node;
    }

    Node* search(Node* node, int val) {
        if (node == NULL || node->data == val) {
            return node;
        }
        if (val < node->data) {
            return search(node->left, val);
        } else {
            return search(node->right, val);
        }
    }

    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current && current->left != NULL) {
            current = current->left;
        }
        return current;
    }

    Node* deleteNode(Node* root, int val) {
        if (root == NULL) return root;

        if (val < root->data) {
            root->left = deleteNode(root->left, val);
        } else if (val > root->data) {
            root->right = deleteNode(root->right, val);
        } else {
            if (root->left == NULL) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == NULL) {
                Node* temp = root->left;
                delete root;
                return temp;
            }

            Node* temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
        return root;
    }

    void inorder(Node* root) {
        if (root != NULL) {
            inorder(root->left);
            cout << root->data << " ";
            inorder(root->right);
        }
    }

    void preorder(Node* root) {
        if (root != NULL) {
            cout << root->data << " ";
            preorder(root->left);
            preorder(root->right);
        }
    }

    void postorder(Node* root) {
        if (root != NULL) {
            postorder(root->left);
            postorder(root->right);
            cout << root->data << " ";
        }
    }
};

int main() {
    BST bst;
    bst.root = bst.insert(bst.root, 50);
    bst.insert(bst.root, 30);
    bst.insert(bst.root, 70);
    bst.insert(bst.root, 20);
    bst.insert(bst.root, 40);
    bst.insert(bst.root, 60);
    bst.insert(bst.root, 80);

    cout << "Inorder traversal: ";
    bst.inorder(bst.root);
    cout << endl;

    cout << "Preorder traversal: ";
    bst.preorder(bst.root);
    cout << endl;

    cout << "Postorder traversal: ";
    bst.postorder(bst.root);
    cout << endl;

    Node* searchResult = bst.search(bst.root, 90);
    if (searchResult != NULL) {
        cout << "Node 90 found in the tree" << endl;
    } else {
        cout << "Node 90 not found in the tree" << endl;
    }

    bst.root = bst.deleteNode(bst.root, 20);
    cout << "Inorder traversal after deleting 20: ";
    bst.inorder(bst.root);
    cout << endl;
    
     bst.root = bst.insert(bst.root, 90);
    cout << "Inorder traversal after inserting 90: ";
    bst.inorder(bst.root);
    cout << endl;
    
     Node* search = bst.search(bst.root, 90);
    if (search != NULL) {
        cout << "Node 90 found in the tree" << endl;
    } else {
        cout << "Node 90 not found in the tree" << endl;
    }

    return 0;
}
