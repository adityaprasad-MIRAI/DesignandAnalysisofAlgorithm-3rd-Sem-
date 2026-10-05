#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// A node in a binary tree contains:
// 1. data -> value stored in the node
// 2. left -> pointer to the left child
// 3. right -> pointer to the right child
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    // Default constructor: creates an empty node
    Node() : data(0), left(nullptr), right(nullptr) {}

    // Parameterized constructor: creates a node with a given value
    Node(int d) : data(d), left(nullptr), right(nullptr) {}
};

// This function creates a small sample tree:
//        1
//       / \
//      2   3
//     / \
//    4   5
inline Node *buildSampleTree()
{
    Node *root = new Node(1);
    Node *left = new Node(2);
    Node *right = new Node(3);
    Node *leftLeft = new Node(4);
    Node *leftRight = new Node(5);

    root->left = left;
    root->right = right;
    left->left = leftLeft;
    left->right = leftRight;

    return root;
}

// Inorder traversal: Left -> Root -> Right
// If the tree is a BST, this prints values in sorted order.
inline void inorder(Node *root)
{
    if (root == nullptr)
    {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Preorder traversal: Root -> Left -> Right
// The current node is processed before its children.
inline void preorder(Node *root)
{
    if (root == nullptr)
    {
        return;
    }

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Postorder traversal: Left -> Right -> Root
// A node is processed only after its children are done.
inline void postorder(Node *root)
{
    if (root == nullptr)
    {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

// Height of a binary tree = number of levels in the tree.
// Example: a single-node tree has height 1.
inline int height(Node *root)
{
    if (root == nullptr)
    {
        return 0;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return max(leftHeight, rightHeight) + 1;
}

// Level-order traversal visits nodes by levels.
// It is useful for BFS-like tree processing.
inline vector<vector<int>> levelOrder(Node *root)
{
    vector<vector<int>> answer;

    if (root == nullptr)
    {
        return answer;
    }

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int size = q.size();
        vector<int> currentLevel;

        for (int i = 0; i < size; i++)
        {
            Node *temp = q.front();
            q.pop();
            currentLevel.push_back(temp->data);

            if (temp->left != nullptr)
                q.push(temp->left);
            if (temp->right != nullptr)
                q.push(temp->right);
        }

        answer.push_back(currentLevel);
    }

    return answer;
}

#endif
