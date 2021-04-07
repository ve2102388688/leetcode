#include <bits/stdc++.h>
#include "mycommon.hpp"
using namespace std;

/** \brief      getNext 寻找node的后继
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-21
 * 
 *  \param[in] node 输入二叉树结点
 *  \return         返回node的后继
 */
TreeNode* getNext(TreeNode* node) {
    while (node->left != nullptr)
        node = node->left;
    return node;
}

/** \brief      deleteNode 删除二叉搜索树中的节点 450
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-21
 * 
 *  \param[in] root 输入二叉树根结点
 *  \param[in] key  删除值
 *  \return         返回查找结点
 */
TreeNode* deleteNode(TreeNode* root, int key) {
    if(root == nullptr)  return nullptr;

    if(root->val == key) {
        if(root->left == nullptr){                          /**<左子树上为空，直接返回右子树，同时释放内存 */
            TreeNode *temp = root->right;
            delete root;
            return temp;
        }
        if(root->right == nullptr){                          /**<右子树上为空，直接返回左子树，同时释放内存 */
            TreeNode *temp = root->left;
            delete root;
            return temp;
        }
        /**<左右子树都不空，寻找后继，替换后，删除后继 */
        TreeNode *next = getNext(root->right);
        root->val = next->val;
        root->right = deleteNode(root->right, next->val);
    }
    else if (root->val < key)                               /**<在右子树上查找 */
        root->right = deleteNode(root->right, key);
    else if(root->val > key)                                /**<在左子树上查找 */
        root->left = deleteNode(root->left, key);

    return root;
}

int main(int argc, char *argv[])
{
    std::vector<int> nums = {5,3,6,2,4,-1,7};
    TreeNode *tree = creatTree(nums, 0);

    TreeNode *output = deleteNode(tree, 3);
    printTree(output);
    std::cout << '\n';

    freeTree(tree);
    return 0;
}