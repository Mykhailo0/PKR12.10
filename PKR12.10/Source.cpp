#include <iostream>
#include <queue>
#include <algorithm>
#include <limits.h>

using namespace std;

// ���������� ��������� ����� �������� ������
struct Node
{
    int data;
    Node* left, * right;

    Node(int value)
    {
        data = value;
        left = right = nullptr;
    }
};

// ������� ��� ������� ������ �������� � ������
Node* insert(Node* root, int value)
{
    if (root == nullptr)
    {
        return new Node(value);
    }

    if (value < root->data)
    {
        root->left = insert(root->left, value);
    }
    else
    {
        root->right = insert(root->right, value);
    }

    return root;
}

// ������� ��� ����������� ���������� �������� �� ���� ����
void findMaxElement(Node* root, int& maxVal, int& maxLevel, int currentLevel)
{
    if (root == nullptr)
    {
        return;
    }

    // ���� ������� ����� ��������� �������, ��������� maxVal � maxLevel
    if (root->data > maxVal)
    {
        maxVal = root->data;
        maxLevel = currentLevel;
    }

    // ���������� ��������� ��� �� ����� ��������
    findMaxElement(root->left, maxVal, maxLevel, currentLevel + 1);
    findMaxElement(root->right, maxVal, maxLevel, currentLevel + 1);
}

int main()
{
    Node* root = nullptr;

    // ������� �������� � ������ ������
    int value;
    do
    {
        cout << "enter the value to insert into the tree (-1 - end of input) ";
        cin >> value;
        if (value < 0) break;
        root = insert(root, value);
    } while (true);

    int maxVal = INT_MIN;
    int maxLevel = -1;

    // ����������� ���������� �������� �� ���� ����
    findMaxElement(root, maxVal, maxLevel, 0);

    // ���� ����������
    cout << "The largest element: " << maxVal << endl;
    cout << "The level on which it is located: " << maxLevel << endl;

    return 0;
}