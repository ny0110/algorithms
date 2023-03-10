#include <iostream>
#include <cstdlib>
using namespace std;

class Node {
public:
    int value;
    Node* left;
    Node* right;
    Node(int value) {
        this->value = value;
        left = NULL;
        right = NULL;
    }
};

class BinarySearchTree {
public:
    Node* root;
    BinarySearchTree() {
        root = NULL;
    }
    void insert(int value) {
        if (root == NULL) {
            root = new Node(value);
            return;
        }
        Node* current = root;
        while (true) {
            if (value < current->value) {
                if (current->left == NULL) {
                    current->left = new Node(value);
                    break;
                }
                current = current->left;
            }
            else {
                if (current->right == NULL) {
                    current->right = new Node(value);
                    break;
                }
                current = current->right;
            }
        }
    }

    void traverseInOrder(Node* node) {
        if (node != NULL) {
            traverseInOrder(node->left);
            cout << node->value << " ";
            traverseInOrder(node->right);
        }
    }

    void traversePreOrder(Node* node) {
        if (node != NULL) {
            cout << node->value << " ";
            traversePreOrder(node->left);
            traversePreOrder(node->right);
        }
    }

    void traversePostOrder(Node* node) {
        if (node != NULL) {
            traversePostOrder(node->left);
            traversePostOrder(node->right);
            cout << node->value << " ";
        }
    }

    bool search(int value) {
        Node* current = root;
        while (current != NULL) {
            if (current->value == value) {
                return true;
            }
            else if (current->value > value) {
                current = current->left;
            }
            else {
                current = current->right;
            }
        }
        return false;
    }

    int depth(Node* node) {
        if (node == NULL) {
            return 0;
        }
        int leftDepth = depth(node->left);
        int rightDepth = depth(node->right);
        return max(leftDepth, rightDepth) + 1;
    }

    Node* findMin(Node* node) {
        while (node->left != NULL) {
            node = node->left;
        }
        return node;
    }

    Node* deleteNode(Node* node, int value) {
        if (node == NULL) {
            return NULL;
        }
        if (value < node->value) {
            node->left = deleteNode(node->left, value);
        }
        else if (value > node->value) {
            node->right = deleteNode(node->right, value);
        }
        else {
            if (node->left == NULL && node->right == NULL) {
                delete node;
                node = NULL;
            }
            else if (node->left == NULL) {
                Node* temp = node;
                node = node->right;
                delete temp;
            }
            else if (node->right == NULL) {
                Node* temp = node;
                node = node->left;
                delete temp;
            }
            else {
                Node* temp = findMin(node->right);
                node->value = temp->value;
                node->right = deleteNode(node->right, temp->value);
            }
        }
        return node;
    }
};


int main() {
    BinarySearchTree tree;
    int numElements;
    cout << "?????????????? ???????????????????? ??????????????????: ";
    cin >> numElements;
    for (int i = 0; i < numElements; i++) {
        int value = rand() % 100 + 1; // generate a random integer between 1 and 100
        tree.insert(value);
    }
    cout << "?????????? ???? ??????????????: ";
    tree.traverseInOrder(tree.root);
    cout << endl;

    cout << "?????????????????????????????? ??????????: ";
    tree.traversePreOrder(tree.root);
    cout << endl;

    cout << "???????????????? ??????????: ";
    tree.traversePostOrder(tree.root);
    cout << endl;

    cout << "?????????????? ????????????: " << tree.depth(tree.root) << endl;

    int searchValue;
    cout << "?????????????? ???????????????? ?????? ????????????: ";
    cin >> searchValue;
    if (tree.search(searchValue)) {
        cout << "???????????????? ?????????????? ?? ????????????." << endl;
    }
    else {
        cout << "???????????????? ???? ?????????????? ?? ????????????." << endl;
    }

    int deleteValue;
    cout << "?????????????? ???????????????? ?????? ????????????????: ";
    cin >> deleteValue;
    tree.deleteNode(tree.root, deleteValue);
    cout << "?????????? ???? ?????????????? ?????????? ???????????????? " << deleteValue << ": ";
    tree.traverseInOrder(tree.root);
    cout << endl;

    return 0;
}