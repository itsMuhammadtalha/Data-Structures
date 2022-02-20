#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

class AVLTree
{
private:
    Node *root;

public:
    AVLTree() : root(NULL) {}
    ~AVLTree() { destructive(root); }

    void destructive(Node *iter)
    {
        if (iter == NULL)
            return;

        destructive(iter->left);
        destructive(iter->right);
        delete iter;
    }

    Node *getRoot()
    {
        return root;
    }

    Node *createNode(int value)
    {
        Node *create = new Node;
        create->data = value;
        create->left = create->right = NULL;
        return create;
    }

    int maxDepth(Node *iter)
    {
        if (iter == NULL)
            return 0;

        int leftDepth = maxDepth(iter->left);
        int rightDepth = maxDepth(iter->right);

        return (leftDepth > rightDepth) ? leftDepth + 1 : rightDepth + 1;
    }

    Node *leftRotate(Node *unbalanced)
    {
        Node *rightNode = unbalanced->right;
        unbalanced->right = rightNode->left;
        rightNode->left = unbalanced;
        return rightNode;
    }

    Node *rightRotate(Node *unbalanced)
    {
        Node *leftNode = unbalanced->left;
        unbalanced->left = leftNode->right;
        leftNode->right = unbalanced;
        return leftNode;
    }

    Node *add(Node *iter, int value)
    {
        if (iter == NULL)
        {
            if (root == NULL)
                return root = createNode(value); //if no node exists, set created node as the root
            return createNode(value);
        }

        if (value < iter->data)
            iter->left = add(iter->left, value);

        else if (value > iter->data)
            iter->right = add(iter->right, value);

        int balanceFactor = maxDepth(iter->left) - maxDepth(iter->right);

        //if balance factor is not -1, 0 ,1 => rotations required

        if (balanceFactor > 1) //node has been added to the left side
        {
            if (value > iter->left->data)
            {
                //double rotation
                iter->left = leftRotate(iter->left);
                if (root == iter)
                    return root = rightRotate(iter); //in case root is rotated, current top node becomes the root
                return rightRotate(iter);
            }
            //single rotation
            if (iter == root)
                return root = rightRotate(iter);
            return rightRotate(iter);
        }

        else if (balanceFactor < -1) //node has been added to the right side
        {
            if (value < iter->right->data)
            {
                //double rotation
                iter->right = rightRotate(iter->right);
                if (root == iter)
                    return root = leftRotate(iter);
                return leftRotate(iter);
            }
            //single rotation
            if (root == iter)
                return root = leftRotate(iter);
            return leftRotate(iter);
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
};

//tester
int main()
{
    AVLTree avl;

    avl.add(avl.getRoot(), 1);
    avl.add(avl.getRoot(), 2);
    avl.add(avl.getRoot(), 3);
    avl.add(avl.getRoot(), 4);
    avl.add(avl.getRoot(), 5);
    avl.add(avl.getRoot(), 6);
    avl.add(avl.getRoot(), 7);
    avl.add(avl.getRoot(), 16);
    avl.add(avl.getRoot(), 15);
    avl.add(avl.getRoot(), 14);
    avl.add(avl.getRoot(), 13);

    avl.inOrder(avl.getRoot());
    cout << endl;
    avl.preOrder(avl.getRoot());

    Node *rootNode = avl.getRoot();
    cout << endl
         << rootNode->data << endl;

    return 0;
}