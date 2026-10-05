#include "standard.h"
#include "BinaryTree.h"

using namespace std;

int main()
{
    Node *root = buildSampleTree();

    cout << "Max depth of the tree: " << height(root) << endl;

    return 0;
}