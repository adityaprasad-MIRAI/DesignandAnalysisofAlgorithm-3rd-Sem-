#include "standard.h"
#include "BinaryTree.h"

using namespace std;

int main()
{
    // Build the sample tree from the shared header file.
    Node *root = buildSampleTree();

    cout << "Inorder traversal: ";
    inorder(root);
    cout << endl;

    cout << "Preorder traversal: ";
    preorder(root);
    cout << endl;

    cout << "Postorder traversal: ";
    postorder(root);
    cout << endl;

    return 0;
}