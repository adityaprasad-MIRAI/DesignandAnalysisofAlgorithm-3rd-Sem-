#include "standard.h"
#include "BinaryTree.h"

using namespace std;

int main()
{
    // Use the shared tree setup from the header file.
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

    cout << "Height of the tree: " << height(root) << endl;

    return 0;
}