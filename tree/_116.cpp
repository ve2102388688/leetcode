#include <bits/stdc++.h>
#include "mycommon.hpp"
using namespace std;

/** \brief      connectTwoNode  连接两个结点
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-16
 * 
 *  \param[in] node1 输入结点1
 *  \param[in] node2 输入结点2
 *  \return          void
 */
void connectTwoNode(Node* node1, Node* node2) {
    if(node1 == nullptr || node2 == nullptr)
        return ;
    
    node1->next = node2;
    connectTwoNode(node1->left, node1->right);              /**<左侧区域内连接 */
    connectTwoNode(node2->left, node2->right);              /**<右侧区域内连接 */
    connectTwoNode(node1->right, node2->left);              /**<左侧连接到右侧 */
}

/** \brief      connect  填充每个节点的下一个右侧节点指针
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-16
 *  \remark     完美二叉树
 * 
 *  \param[in] root 输入二叉树根节点
 *  \return         返回填充后的二叉树
 */
Node* connect(Node* root) {
    if(root == nullptr) return nullptr;

    connectTwoNode(root->left, root->right);
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