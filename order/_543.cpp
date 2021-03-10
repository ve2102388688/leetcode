#include <bits/stdc++.h>
#include "mycommon.hpp"
using namespace std;

/** \brief      help 辅助函数
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-23
 * 
 *  \param[in] root 输入二叉树根结点
 *  \return         返回二叉树的高度
 */
int ans = 0;
int help(TreeNode *root) {
    if(root == nullptr)
        return 0;
    int L = help(root->left);
    int R = help(root->right);
    ans = max(ans, L + R);              /**<目标是最大长度 */
    return max(L, R) + 1;               /**<二叉树的高度 */
}

/** \brief      diameterOfBinaryTree 二叉树的直径 543
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-23
 * 
 *  \param[in] root 输入二叉树根结点
 *  \return         返回二叉树的直径
 */
int diameterOfBinaryTree(TreeNode* root) {
    help(root);
    return ans;
}

int main(int argc, char *argv[])
{
    std::vector<int> nums = {1,2,3,4,5};
    TreeNode *tree = creatTree(nums, 0);

    int output = diameterOfBinaryTree(tree);
    std::cout << output << '\n';

    freeTree(tree);
    return 0;
}