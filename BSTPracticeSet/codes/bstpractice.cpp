#include <iostream>
using namespace std;

struct node
{
    int data;
    int repetitionCount = 0;
    node *left;
    node *right;
};

class BinarySearchTree
{

private:
    node *findSecondSuccessor(node *temp)
    {
        if (temp->right->left == NULL)
            return temp;

        temp = temp->right;

        while (temp->left->left != NULL)
            temp = temp->left;

        return temp;
    }

    void deletionCaseThree(node *temp)
    {
        node *swapNode = findSecondSuccessor(temp);
        if (swapNode == temp)
        {
            node *temp1 = temp->right;
            temp->data = temp1->data;
            temp->right = temp1->right;
            delete temp1;
            return;
        }
        temp->data = swapNode->left->data;
        node *temp1 = swapNode->left;
        swapNode->left = temp1->right;
        delete temp1;
        return;
    }

    void destroyRecursive(node *temp)
    {
        if (temp)
        {
            destroyRecursive(temp->left);
            destroyRecursive(temp->right);
            delete temp;
        }
    }

public:
    node *root;

    BinarySearchTree() : root(NULL) {}
    ~BinarySearchTree() { destroyRecursive(root); }

    void insertNode(node *temp, int number)
    {
        if (root == NULL)
        {
            root = new node;
            root->data = number;
            root->left = NULL;
            root->right = NULL;
            return;
        }

        if (number == temp->data)
        {
            cout << "The number is already present" << endl;
            temp->repetitionCount++;
            return;
        }

        if (number < temp->data)
        {
            if (temp->left != NULL)
            {
                insertNode(temp->left, number);
                return;
            }

            else
            {
                temp->left = new node;
                temp->left->data = number;
                temp->left->left = NULL;
                temp->left->right = NULL;
                return;
            }
        }

        if (number > temp->data)
        {
            if (temp->right != NULL)
            {
                insertNode(temp->right, number);
                return;
            }

            else
            {
                temp->right = new node;
                temp->right->data = number;
                temp->right->left = NULL;
                temp->right->right = NULL;
                return;
            }
        }
    }

    void removeNode(node *temp, int key)
    {
        if (root == NULL)
        {
            cout << "Tree is empty" << endl;
            return;
        }

        //DELETING ROOT
        if (key == temp->data)
        {
            if (temp->right == NULL && temp->left == NULL)
            {
                delete temp;
                temp = root = NULL;
                return;
            }

            if (temp->right == NULL || temp->left == NULL)
            {
                if (temp->right != NULL)
                {
                    temp = temp->right;
                    delete root;
                    root = temp;
                    return;
                }
                else
                {
                    temp = temp->left;
                    delete root;
                    root = temp;
                    return;
                }
            }
            if (temp->right != NULL && temp->left != NULL)
            {
                deletionCaseThree(temp);
                return;
            }
        }

        //DELETING NODE FROM LEFT SUB TREE OF ROOT
        if (key < temp->data)
        {
            if (temp->left->data == key)
            {
                if (temp->left->left == NULL && temp->left->right == NULL)
                {
                    delete temp->left;
                    temp->left = NULL;
                    return;
                }

                if (temp->left->left == NULL || temp->left->right == NULL)
                {
                    if (temp->left->left != NULL)
                    {
                        node *temp1 = temp->left->left;
                        delete temp->left;
                        temp->left = temp1;
                        return;
                    }
                    else
                    {
                        node *temp1 = temp->left->right;
                        delete temp->left;
                        temp->left = temp1;
                        return;
                    }
                }

                if (temp->left->left != NULL && temp->left->right != NULL)
                {
                    temp = temp->left;
                    deletionCaseThree(temp);
                    return;
                }
            }

            else
            {
                removeNode(temp->left, key);
                return;
            }
        }

        //DELETING NODE FROM RIGHT SUBTREE OF ROOT
        if (key > temp->data)
        {
            if (temp->right->data == key)
            {
                if (temp->right->left == NULL && temp->right->right == NULL)
                {
                    delete temp->right;
                    temp->right = NULL;
                    return;
                }

                if (temp->right->left == NULL || temp->right->right == NULL)
                {
                    if (temp->right->left != NULL)
                    {
                        node *temp1 = temp->right->left;
                        delete temp->right;
                        temp->right = temp1;
                        return;
                    }
                    else
                    {
                        node *temp1 = temp->right->right;
                        delete temp->right;
                        temp->right = temp1;
                        return;
                    }
                }

                if (temp->right->left != NULL && temp->right->right != NULL)
                {
                    temp = temp->right;
                    deletionCaseThree(temp);
                    return;
                }
            }

            else
            {
                removeNode(temp->right, key);
                return;
            }
        }
    }

    void inOrder(node *temp)
    {
        if (root == NULL)
        {
            cout << "Tree is empty" << endl;
            return;
        }

        if (temp->left != NULL)
            inOrder(temp->left);

        cout << temp->data << " ";

        if (temp->right != NULL)
            inOrder(temp->right);

        return;
    }

    void printRepeatedCounts(node *temp)
    {
        if (root == NULL)
        {
            cout << "Tree is empty" << endl;
            return;
        }

        if (temp->left != NULL)
            printRepeatedCounts(temp->left);

        cout << "Repeated value prompt for " << temp->data << " is " << temp->repetitionCount << endl;

        if (temp->right != NULL)
            printRepeatedCounts(temp->right);

        return;
    }

    //QUESTION-01 GOES HERE
    node *getNthMin(node *temp, int givenMin, int &c)
    {
        if (!temp)
            return temp;

        node *resultNode = NULL;
        resultNode = getNthMin(temp->left, givenMin, c);
        c++;
        if (c == givenMin)
        {
            c++;
            return temp;
        }
        if (c < givenMin)
            resultNode = getNthMin(temp->right, givenMin, c);
        return resultNode;
    }

    node *getNthMax(node *temp, int givenMax, int &c)
    {
        if (!temp)
            return temp;

        node *resultNode = NULL;
        resultNode = getNthMax(temp->right, givenMax, c);
        c++;
        if (c == givenMax)
        {
            c++;
            return temp;
        }
        if (c < givenMax)
            resultNode = getNthMax(temp->left, givenMax, c);
        return resultNode;
    }

    void find_2nd_3rd_largest_and_smallest(node *temp)
    {
        if (!root)
            return;

        int count = 0;
        node *secondMin = getNthMin(temp, 2, count = 0);
        node *thirdMin = getNthMin(temp, 3, count = 0);
        node *secondMax = getNthMax(temp, 2, count = 0);
        node *thirdMax = getNthMax(temp, 3, count = 0);

        cout << "Second minimun: " << secondMin->data << endl;
        cout << "Third minimun: " << thirdMin->data << endl;
        cout << "Second maximum: " << secondMax->data << endl;
        cout << "Third maximum " << thirdMax->data << endl;
    }

    //QUESTION-02 GOES HERE
    int find_nodes_for_sbt(node *iter)
    {
        if (!root)
            return 0;

        int count = 0;
        bool flag = false;

        if (iter->left != NULL)
        {
            flag = true;
            count += find_nodes_for_sbt(iter->left);
        }

        if (!flag)
        {
            count++;
            flag = false;
        }

        if (iter->right != NULL)
        {
            flag = true;
            count += find_nodes_for_sbt(iter->right);
        }

        if (!flag)
        {
            count++;
            flag = false;
        }
        return count;
    }

    //QUESTION-03 GOES HERE
    void print_nodes_between(node *iter, int first, int second)
    {
        if (!iter)
            return;

        if (iter->data != first)
            print_nodes_between(iter->left, first, second);

        if (iter->data > first && iter->data < second)
            cout << iter->data << " ";

        if (iter->data >= second)
            return;

        print_nodes_between(iter->right, first, second);
    }

    //QUESTION-04 GOES HERE
    int getNodesCount(node *iter)
    {
        if (!iter)
            return 0;
        int count = 0;
        count += getNodesCount(iter->left);
        count++;
        count += getNodesCount(iter->right);
        return count;
    }

    void InOrderInArray(node *iter, int *arr, int &index)
    {
        if (!iter)
            return;

        InOrderInArray(iter->left, arr, index);
        *(arr + index) = iter->data;
        index++;
        InOrderInArray(iter->right, arr, index);
    }

    void find_missing_nodes(node *iter)
    {
        int size = getNodesCount(root) - 1;
        int *arr = new int[size];
        int missingNodes[10];
        int index = 0;
        InOrderInArray(root, arr, index = 0);
        index = 0;
        int difference = 0;
        int totalMissingNodes = 0;

        for (int i = 0; i < size; i++)
        {
            difference = arr[i + 1] - arr[i] - 1;
            totalMissingNodes += difference;
            if (difference)
            {
                cout << "Element is Missing Between " << arr[i] << " and " << arr[i + 1] << endl;
                for (int j = 1; j <= difference; j++)
                {
                    missingNodes[index] = arr[i] + j;
                    index++;
                }
            }
        }

        cout << "Total " << totalMissingNodes << " nodes are missing" << endl;

        cout << "Missing nodes are ";
        for (int i = 0; i < index; i++)
            cout << missingNodes[i] << " ";

        cout << endl;
        delete[] arr;
    }
};

int main()
{
    BinarySearchTree tree;

    tree.insertNode(tree.root, 12);
    tree.insertNode(tree.root, 10);
    tree.insertNode(tree.root, 9);
    tree.insertNode(tree.root, 8);
    tree.insertNode(tree.root, 5);
    tree.insertNode(tree.root, 4);
    tree.insertNode(tree.root, 3);
    tree.insertNode(tree.root, 2);
    tree.insertNode(tree.root, 1);
    // tree.insertNode(tree.root, 9);

    tree.inOrder(tree.root);
    cout << endl;

    tree.find_2nd_3rd_largest_and_smallest(tree.root);                         //q1
    cout << "Nodes required = " << tree.find_nodes_for_sbt(tree.root) << endl; //q2
    tree.print_nodes_between(tree.root, 5, 10);                                //q3
    cout << endl;
    tree.find_missing_nodes(tree.root);
    return 0;
}