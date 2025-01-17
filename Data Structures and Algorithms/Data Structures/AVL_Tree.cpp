#include <iostream>
using namespace std;

class Node
{
public:
    int key;
    int height;
    Node *left;
    Node *right;

    Node(int key) : key(key), height(1), left(nullptr), right(nullptr) {}
};

class AVL
{
public:
    Node *root;

    AVL() : root(nullptr) {}

    int height(Node *node)
    {
        if (node == NULL)
        {
            return 0;
        }
        return node->height;
    }

    int getBalance(Node *node)
    {
        if (node == NULL)
        {
            return 0;
        }
        return height(node->left) - height(node->right);
    }

    // l = left, r = right
    Node *rightRotate(Node *r)
    {
        Node *l = r->left;
        Node *temp = l->right;

        /*
                r
               /
              l
               \
                temp
        */

        // Rotation
        l->right = r;
        r->left = temp;
        r->height = getMax(getHeight(r->left), getHeight(r->right)) + 1;
        l->height = getMax(getHeight(l->left), getHeight(l->right)) + 1;

        return l;
    }
    // l = left, r = right
    Node *leftRotate(Node *l)
    {
        Node *r = l->right;
        Node *temp = r->left;

        /*
                l
                 \
                  r
                /
            temp
        */

        // Rotation
        r->left = l;
        l->right = temp;
        r->height = getMax(getHeight(r->left), getHeight(r->right)) + 1;
        l->height = getMax(getHeight(l->left), getHeight(l->right)) + 1;

        return r;
    }

    void insert(int key)
    {
        root = insert(root, key);
    }
    Node *insert(Node *node, int key)
    {
        if (node == NULL)
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
        else
        {
            return node; // Equal keys are not allowed
        }

        node->height = 1 + max(height(node->left), height(node->right));
        int balance = getBalance(node);

        // Left Left Case
        if (balance > 1 && node->left->key > key)
        {
            return rightRotate(node);
        }

        // Right Right Case
        if (balance < -1 && node->right->key < key)
        {
            return leftRotate(node);
        }

        // Left Right Case
        if (balance > 1 && node->left->key < key)
        {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        // Right Left Case
        if (balance < -1 && node->right->key > key)
        {
            node->right = rightRotate(node->right);
            return leftRotate(node);
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
    void deleteNode(int key)
    {
        root = deleteNode(root, key);
    }
    Node *deleteNode(Node *node, int key)
    {
        if (root == NULL)
        {
            return root;
        }

        if (node->key > key)
        {
            node->left = deleteNode(node->left, key);
        }
        else if (node->key < key)
        {
            node->right = deleteNode(node->right, key);
        }
        else
        {
            if (node->left == NULL && node->right == NULL)
            {
                delete node;
                node = NULL;
            }
            else if (node->left == NULL)
            {
                Node *temp = node->right;
                *node = *temp;
                delete temp;
            }
            else if (node->right == NULL)
            {
                Node *temp = node->left;
                *node = *temp;
                delete temp;
            }
            else
            {
                Node *temp = findMin(node->right);
                node->key = temp->key;
                node->right = deleteNode(node->right, temp->key);
            }
        }

        if (node == NULL)
        {
            return node;
        }

        node->height = 1 + max(height(node->left), height(node->right));
        int balance = getBalance(node);

        // Left Left Case
        if (balance > 1 && getBalance(node->left) >= 0)
        {
            return rightRotate(node);
        }

        // Right Right Case
        if (balance < -1 && getBalance(node->right) <= 0)
        {
            return leftRotate(node);
        }

        // Left Right Case
        if (balance > 1 && getBalance(node->left) < 0)
        {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // Right Left Case
        if (balance < -1 && getBalance(node->right) > 0)
        {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }
};
