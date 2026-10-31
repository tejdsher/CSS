#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

Node* createNode(int x) {
    Node* newNode = new Node;
    newNode->data = x;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int x) {
    if (root == NULL)
        return createNode(x);

    if (x < root->data)
        root->left = insert(root->left, x);
    else
        root->right = insert(root->right, x);

    return root;
}

bool search(Node* root, int x) {
    if (root == NULL)
        return false;

    if (root->data == x)
        return true;

    if (x < root->data)
        return search(root->left, x);

    return search(root->right, x);
}

Node* findMin(Node* root) {
    while (root->left != NULL)
        root = root->left;

    return root;
}

Node* deleteNode(Node* root, int x) {
    if (root == NULL)
        return NULL;

    if (x < root->data)
        root->left = deleteNode(root->left, x);

    else if (x > root->data)
        root->right = deleteNode(root->right, x);

    else {
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }

        if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* temp = findMin(root->right);
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

int depth(Node* root) {
    if (root == NULL)
        return 0;

    int leftDepth = depth(root->left);
    int rightDepth = depth(root->right);

    return 1 + max(leftDepth, rightDepth);
}

void mirror(Node* root) {
    if (root == NULL)
        return;

    swap(root->left, root->right);

    mirror(root->left);
    mirror(root->right);
}

Node* copyTree(Node* root) {
    if (root == NULL)
        return NULL;

    Node* newNode = createNode(root->data);

    newNode->left = copyTree(root->left);
    newNode->right = copyTree(root->right);

    return newNode;
}

void displayParents(Node* root) {
    if (root == NULL)
        return;

    if (root->left != NULL)
        cout << root->data << " -> " << root->left->data << endl;

    if (root->right != NULL)
        cout << root->data << " -> " << root->right->data << endl;

    displayParents(root->left);
    displayParents(root->right);
}

void displayLeaves(Node* root) {
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL)
        cout << root->data << " ";

    displayLeaves(root->left);
    displayLeaves(root->right);
}

void levelOrder(Node* root) {
    if (root == NULL)
        return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        cout << temp->data << " ";

        if (temp->left != NULL)
            q.push(temp->left);

        if (temp->right != NULL)
            q.push(temp->right);
    }
}

int main() {
    Node* root = NULL;
    Node* copiedRoot = NULL;
    int choice, x;

    do {
        cout << "\n\n1. Insert";
        cout << "\n2. Delete";
        cout << "\n3. Search";
        cout << "\n4. Inorder";
        cout << "\n5. Preorder";
        cout << "\n6. Postorder";
        cout << "\n7. Display Depth";
        cout << "\n8. Mirror Tree";
        cout << "\n9. Create and Display Copy";
        cout << "\n10. Display Parent-Child";
        cout << "\n11. Display Leaf Nodes";
        cout << "\n12. Level Order Display";
        cout << "\n13. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> x;
                root = insert(root, x);
                break;

            case 2:
                cout << "Enter value to delete: ";
                cin >> x;
                root = deleteNode(root, x);
                break;

            case 3:
                cout << "Enter value to search: ";
                cin >> x;

                if (search(root, x))
                    cout << "Element Found\n";
                else
                    cout << "Element Not Found\n";
                break;

            case 4:
                inorder(root);
                break;

            case 5:
                preorder(root);
                break;

            case 6:
                postorder(root);
                break;

            case 7:
                cout << "Depth: " << depth(root) << endl;
                break;

            case 8:
                mirror(root);
                cout << "Tree Mirrored\n";
                break;

            case 9:
                copiedRoot = copyTree(root);
                cout << "Copied Tree: ";
                inorder(copiedRoot);
                break;

            case 10:
                displayParents(root);
                break;

            case 11:
                cout << "Leaf Nodes: ";
                displayLeaves(root);
                break;

            case 12:
                cout << "Level Order: ";
                levelOrder(root);
                break;

            case 13:
                cout << "Exiting\n";
                break;

            default:
                cout << "Invalid choice\n";
        }

    } while (choice != 13);

    return 0;
}