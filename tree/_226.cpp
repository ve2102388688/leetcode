#include <bits/stdc++.h>
#include "mycommon.hpp"
using namespace std;


/** \brief      invertTree  翻转二叉树
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-16
 * 
 *  \param[in] root 输入二叉树根节点
 *  \return         返回翻转二叉树
 */
TreeNode* invertTree(TreeNode* root) {
    /**<前序或者后序遍历都可以完成， 中序遍历不可完成 */
    /**<base case */
    if(root == nullptr) return nullptr;

    TreeNode *temp = root->left;
    root->left = root->right;
    root->right = temp;

    invertTree(root->left);
    invertTree(root->right);

    return root;
}

int main(int argc, char *argv[])
{
    std::vector<int> nums = {4,2,7,1,3,6,9, 1,2,3,4,5,6,7,8};
    TreeNode *tree = creatTree(nums, 0);

    tree = invertTree(tree);
    printTree(tree);
    std::cout << '\n';

    freeTree(tree);
    return 0;
}