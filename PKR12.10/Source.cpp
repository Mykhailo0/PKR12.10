#include <iostream>
#include <queue>
#include <algorithm>
#include <limits.h>

using namespace std;

// Визначення структури вузла бінарного дерева
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

// Функція для вставки нового елемента у дерево
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

// Функція для знаходження найбільшого елемента та його рівня
void findMaxElement(Node* root, int& maxVal, int& maxLevel, int currentLevel)
{
    if (root == nullptr)
    {
        return;
    }

    // Якщо знайшли новий найбільший елемент, оновлюємо maxVal і maxLevel
    if (root->data > maxVal)
    {
        maxVal = root->data;
        maxLevel = currentLevel;
    }

    // Рекурсивно проходимо ліве та праве піддерева
    findMaxElement(root->left, maxVal, maxLevel, currentLevel + 1);
    findMaxElement(root->right, maxVal, maxLevel, currentLevel + 1);
}

int main()
{
    Node* root = nullptr;

    // Вставка елементів у бінарне дерево
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

    // Знаходження найбільшого елемента та його рівня
    findMaxElement(root, maxVal, maxLevel, 0);

    // Друк результату
    cout << "The largest element: " << maxVal << endl;
    cout << "The level on which it is located: " << maxLevel << endl;

    return 0;
}