#include <bits/stdc++.h>
#include "mycommon.hpp"
using namespace std;


/** \brief      help 辅助函数
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-24
 * 
 *  \param[in] root 输入二叉树根结点
 *  \return         返回二叉树的结点和
 */
int ans = 0;
int help(TreeNode *root) {
    if(root == nullptr)
        return 0;

    int L = help(root->left);
    int R = help(root->right);
    ans += abs(L - R);                      /**<左右差的绝对值 */
    return L + R + root->val;               /**<二叉树的结点和 */
}

/** \brief      findTilt 二叉树的坡度 563
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-24
 * 
 *  \param[in] root 输入二叉树根结点
 *  \return         返回二叉树的坡度
 */
int findTilt(TreeNode* root) {
    help(root);
    return ans;
}

int main(int argc, char *argv[])
{
    std::vector<int> nums = {1,2,3};
    TreeNode *tree = creatTree(nums, 0);

    int output = findTilt(tree);
    std::cout << output << '\n';

    freeTree(tree);
    return 0;
}