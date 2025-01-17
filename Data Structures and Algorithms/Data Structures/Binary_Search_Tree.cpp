#include <iostream>
using namespace std;

class Node
{
public:
    int key;
    Node *left;
    Node *right;
    Node(int key) : key(key), left(nullptr), right(nullptr) {}
};

class BinarySearchTree
{
public:
    Node *root;

    BinarySearchTree() : root(nullptr) {}

    void insert(int key)
    {
        root = insert(root, key);
    }
    Node *insert(Node *node, int key)
    {
        if (node == nullptr)
        {
            return new Node(key);
        }

        if (node->key > key)
        {
            node->left = insert(node->left, key);
        }
        else if (node->key < key)
        {
            node->right = insert(node->right, key);
        }
        return node;
    }

    Node *findMin(Node *node)
    {
        if (node->left == NULL)
        {
            return node;
        }
        return findMin(node->left);
    }
    Node *findMax(Node *node)
    {
        if (node->right == NULL)
        {
            return node;
        }
        return findMax(node->right);
    }

    Node *findSuccessor(Node *node)
    {
        return findMin(node->right);
    }
    Node *findPredecessor(Node *node)
    {
        return findMax(node->left);
    }

    void deleteNode(int key)
    {
        root = deleteNode(root, key);
    }
    Node *deleteNode(Node *node, int key)
    {
        if (node == NULL)
        {
            return node;
        }
        if (node->key > key)
        {
            return deleteNode(node->left, key);
        }
        else if (node->key < key)
        {
            return deleteNode(node->right, key);
        }
        else
        {
            if (node->left == NULL)
            {
                Node *temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == NULL)
            {
                Node *temp = node->left;
                delete node;
                return temp;
            }

            Node *temp = findMin(node->right);
            node->key = temp->key;
            node->right = deleteNode(node->right, temp->key);
        }
        return node;
    }

    Node *search(Node *node, int key)
    {
        if (node == NULL)
        {
            return NULL;
        }
        if (node->key < key)
        {
            return search(node->right, key);
        }
        else if (node->key > key)
        {
            return search(node->left, key);
        }
        return node;
    }

    void secondLargest(Node *node, Node *&prev, Node *&cur)
    {
        if (node == NULL)
            return;

        secondLargest(node->left, prev, cur);
        prev = cur;
        cur = node;
        secondLargest(node->right, prev, cur);
    }

    int getHeight(Node *node)
    {
        if (node == NULL)
        {
            return 0;
        }
        return 1 + max(getHeight(node->left), getHeight(node->right));
    }
    int getSize(Node *node)
    {
        if (node == NULL)
            return 0;
        return 1 + getSize(node->left) + getSize(node->right);
    }

    void printInternalNodes(Node *node)
    {
        if (node == NULL)
            return;
        if (node->left != NULL || node->right != NULL)
        {
            cout << node->key << " ";
        }
        printInternalNodes(node->left);
        printInternalNodes(node->right);
    }
    void printLeafNodes(Node *node)
    {
        if (node == NULL)
        {
            return;
        }
        if (node->left == NULL && node->right == NULL)
        {
            cout << node->key << " ";
        }
        printLeafNodes(node->left);
        printLeafNodes(node->right);
    }

    void inorder(Node *node)
    {
        if (node == NULL)
            return;
        inorder(node->left);
        cout << node->key << " ";
        inorder(node->right);
    }
    void preorder(Node *node)
    {
        if (node == NULL)
            return;
        cout << node->key << " ";
        preorder(node->left);
        preorder(node->right);
    }
    void postorder(Node *node)
    {
        if (node == NULL)
            return;
        postorder(node->left);
        postorder(node->right);
        cout << node->key << " ";
    }
};
