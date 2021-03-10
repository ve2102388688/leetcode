#include <bits/stdc++.h>
#include "mycommon.hpp"
using namespace std;


/** \brief      connect  填充每个节点的下一个右侧节点指针II 117
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-19
 * 
 *  \param[in] root 输入二叉树根节点
 *  \return         返回填充后的二叉树
 */
Node* connect(Node* root) {
    if(root == nullptr) return nullptr;

    queue<Node*> Q;
    Q.push(root);

    while (!Q.empty()) {
        int size = Q.size();
        Node *head = nullptr;
        while (size > 0) {
            Node *node = Q.front(); Q.pop();
            /**<尾插 */
            node->next = head;
            head = node;

            /**<注意：从右到左 */
            if (node->right != nullptr)  Q.push(node->right);
            if(node->left != nullptr)  Q.push(node->left);
            --size;
        }
    }
    return root;
}

int main(int argc, char *argv[])
{
    std::vector<int> nums = {4,2,7,1,3,6,9, 1,2,3,4,5,6,7,8};
    TreeNode *tree = creatTree(nums, 0);

    printTree(tree);
    std::cout << '\n';

    freeTree(tree);
    return 0;
}