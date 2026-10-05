#include "standard.h"
#include "BinaryTree.h"

using namespace std;

int main()
{
    Node *root = buildSampleTree();
    vector<vector<int>> result = levelOrder(root);

    cout << "Level-order traversal:" << endl;
    for (const auto &level : result)
    {
        for (int value : level)
        {
            cout << value << " ";
        }
        cout << endl;
    }

    return 0;
}