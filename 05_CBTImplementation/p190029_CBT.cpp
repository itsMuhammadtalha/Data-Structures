#include <iostream>
#include <cmath>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

class CompleteBinaryTree
{
private:
    Node *root;

    Node *createNode(int value)
    {
        Node *create = new Node;
        create->data = value;
        create->left = create->right = NULL;
        return create;
    }

public:
    CompleteBinaryTree() : root(NULL) {}

    Node *getRoot()
    {
        return root;
    }

    int findHeight(Node *iter)
    {
        if (iter == NULL)
            return 0;

        int heightCount = 0;
        while (iter->left != NULL)
        {
            iter = iter->left;
            heightCount++;
        }
        return heightCount;
    }

    int countNodes(Node *iter)
    {
        if (iter == NULL)
            return 0;

        int count = 0;
        count += countNodes(iter->left);
        count++;
        count += countNodes(iter->right);
        return count;
    }

    Node *insert(Node *iter, int value)
    {
        if (iter == NULL)
        {
            if (!root)
                return root = createNode(value);
            return createNode(value);
        }

        int height = findHeight(iter);
        int expectedNode = pow(2, height) - 1;
        int leftTreeNodeCount = countNodes(iter->left);
        int rightTreeNodeCount = countNodes(iter->right);

        if (leftTreeNodeCount == rightTreeNodeCount || expectedNode != leftTreeNodeCount)
            iter->left = insert(iter->left, value);
        else
            iter->right = insert(iter->right, value);

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
};

int main()
{
    CompleteBinaryTree CBT;
    CBT.insert(CBT.getRoot(), 1);
    CBT.insert(CBT.getRoot(), 2);
    CBT.insert(CBT.getRoot(), 3);
    CBT.insert(CBT.getRoot(), 4);
    CBT.insert(CBT.getRoot(), 5);
    CBT.insert(CBT.getRoot(), 6);
    CBT.insert(CBT.getRoot(), 7);
    CBT.insert(CBT.getRoot(), 8);
    CBT.insert(CBT.getRoot(), 9);
    CBT.insert(CBT.getRoot(), 10);
    CBT.insert(CBT.getRoot(), 11);
    CBT.insert(CBT.getRoot(), 12);
    CBT.insert(CBT.getRoot(), 13);
    CBT.insert(CBT.getRoot(), 14);
    CBT.insert(CBT.getRoot(), 15);

    CBT.inOrder(CBT.getRoot());
    return 0;
}