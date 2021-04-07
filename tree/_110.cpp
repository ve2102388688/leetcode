#include <bits/stdc++.h>
#include "mycommon.hpp"
using namespace std;

/** \brief      depth 二叉树的高度
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-18
 * 
 *  \param[in] root 输入二叉树根节点
 *  \return         二叉树的高度
 */
int depth(TreeNode* root) {
    if(root == nullptr)
        return 0;

    int depthLeft = depth(root->left);
    int depthRight = depth(root->right);
    /**<想清楚根结点应该做什么事情？高度差大于1返回false(-1)，并且把-1一直往上传 */
    if( depthLeft ==-1 || depthRight == -1 || abs(depthLeft - depthRight) > 1)
        return -1;
    return depthLeft >= depthRight ? depthLeft + 1 : depthRight + 1;        /**<返回树高 */
}

/** \brief      hasPathSum 验证平衡二叉树 110
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-18
 * 
 *  \param[in] root 输入二叉树根节点
 *  \param[in] sum  目标和
 *  \return         返回是否存在路径和为sum
 */
bool isBalanced(TreeNode* root) {
    return depth(root) >=0;
}

int main(int argc, char *argv[])
{
    std::vector<int> nums1 = {1,2,2,3,3,-1,-1,4,4};
    TreeNode *tree = creatTree(nums1, 0);

    bool output = isBalanced(tree);
    std::cout << output << '\n';

    freeTree(tree);
    return 0;
}