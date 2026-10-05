#include "standard.h"
#include "BinaryTree.h"

using namespace std;

vector<int> rightView(Node *root)
{
    vector<int> answer;
    if (root == nullptr)
    {
        return answer;
    }

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int currentLevelSize = q.size();

        for (int i = 0; i < currentLevelSize; i++)
        {
            Node *temp = q.front();
            q.pop();

            if (i == currentLevelSize - 1)
            {
                answer.push_back(temp->data);
            }

            if (temp->left != nullptr)
                q.push(temp->left);
            if (temp->right != nullptr)
                q.push(temp->right);
        }
    }

    return answer;
}

int main()
{
    Node *root = buildSampleTree();
    vector<int> result = rightView(root);

    cout << "Right view: ";
    for (int value : result)
    {
        cout << value << " ";
    }
    cout << endl;

    return 0;
}