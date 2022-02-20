#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

class BinarySearchTree
{
private:
    Node *root;

    Node *createNode(int value)
    {
        Node *newNode = new Node;
        newNode->data = value;
        newNode->left = newNode->right = NULL;
        return newNode;
    }

    Node *noChild(Node *iter)
    {
        delete iter;
        return iter = NULL;
    }

    Node *oneChild(Node *iter)
    {
        Node *returningNode = NULL;

        if (iter->left)
            returningNode = iter->left;

        else if (iter->right)
            returningNode = iter->right;

        delete iter;
        iter = NULL;
        return returningNode;
    }

    Node *findSecondSuccessor(Node *iter)
    {
        if (!iter->right->left)
            return NULL;

        iter = iter->right;

        while (iter->left->left != NULL)
            iter = iter->left;

        return iter;
    }

    Node *twoChildren(Node *iter)
    {
        Node *secondSuccessor = findSecondSuccessor(iter);
        Node *firstSuccessor = NULL;

        if (!secondSuccessor)
        {
            firstSuccessor = iter->right;
            iter->right = firstSuccessor->right;
        }
        else
        {
            firstSuccessor = secondSuccessor->left;
            secondSuccessor->left = firstSuccessor->right;
        }

        iter->data = firstSuccessor->data;
        delete firstSuccessor;
        return iter;
    }

public:
    BinarySearchTree() : root(NULL) {}

    Node *getRoot()
    {
        return root;
    }

    Node *insert(Node *iter, int value)
    {
        if (iter == NULL)
        {
            if (!root)
                return root = createNode(value);
            return createNode(value);
        }

        if (value < iter->data)
            iter->left = insert(iter->left, value);

        else if (value > iter->data)
            iter->right = insert(iter->right, value);

        return iter;
    }

    Node *remove(Node *iter, int key)
    {
        if (iter == NULL)
            return NULL;

        if (key < iter->data)
            iter->left = remove(iter->left, key);

        else if (key > iter->data)
            iter->right = remove(iter->right, key);

        //key == iter->data
        else
        {
            if (!iter->left && !iter->right)
            {
                if (root == iter)
                    return root = noChild(iter);
                return noChild(iter);
            }

            else if (!iter->left || !iter->right)
            {
                if (root == iter)
                    return root = oneChild(iter);
                return oneChild(iter);
            }

            else if (iter->left && iter->right)
                return twoChildren(iter);
        }

        return iter;
    }

    void inOrder(Node *iter)
    {
        if (iter == NULL)
            return;

        inOrder(iter->left);
        cout << iter->data << " ";
        inOrder(iter->right);
    }

    void preOrder(Node *iter)
    {
        if (iter == NULL)
            return;

        cout << iter->data << " ";
        preOrder(iter->left);
        preOrder(iter->right);
    }

    void postOrder(Node *iter)
    {
        if (iter == NULL)
            return;

        postOrder(iter->left);
        postOrder(iter->right);
        cout << iter->data << " ";
    }

    void postorder(Node *head)
    {
        if (head == NULL)
        {
            return;
        }
        stack<Node *> s;
        s.push(head);

        while (!s.empty())
        {
            Node *next = s.top();

            bool finishedSubtrees = (next->right == head || next->left == head);
            bool isLeaf = (next->left == NULL && next->right == NULL);
            if (finishedSubtrees || isLeaf)
            {
                s.pop();
                cout << next->data << " ";
                head = next;
            }
            else
            {
                if (next->right != NULL)
                {
                    s.push(next->right);
                }
                if (next->left != NULL)
                {
                    s.push(next->left);
                }
            }
        }
    }
};

int main()
{
    BinarySearchTree BST;
    BST.insert(BST.getRoot(), 9);
    BST.insert(BST.getRoot(), 45);
    BST.insert(BST.getRoot(), 14);
    BST.insert(BST.getRoot(), 6);
    BST.insert(BST.getRoot(), 32);
    BST.insert(BST.getRoot(), 54);
    BST.insert(BST.getRoot(), 3);
    BST.insert(BST.getRoot(), 8);
    BST.insert(BST.getRoot(), 25);
    BST.insert(BST.getRoot(), 1);
    BST.insert(BST.getRoot(), 7);
    BST.insert(BST.getRoot(), 39);

    cout << "InOrder:" << endl;
    BST.inOrder(BST.getRoot());
    cout << endl;

    cout << "PreOrder:" << endl;
    BST.preOrder(BST.getRoot());
    cout << endl;

    cout << "PostOrder:" << endl;
    BST.postOrder(BST.getRoot());
    cout << endl;

    BST.postorder(BST.getRoot());

    return 0;
}