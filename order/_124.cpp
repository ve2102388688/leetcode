#include <bits/stdc++.h>
#include "mycommon.hpp"
using namespace std;

/** \brief      maxPathSum 二叉树的最小深度 111
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-18
 *  \remark     这里有两种基本情况。1. 经过父结点 2. 不经过父结点
 * 
 *  \param[in] root 输入二叉树根结点
 *  \return         返回最小深度
 */
int g_maxSum = INT_MIN;
int oneSideMax(TreeNode* root) {
    if(root == nullptr) 
        return 0;

    int maxLeft = max(oneSideMax(root->left), 0);            /**<计算左子树的最大值 */
    int maxRight = max(oneSideMax(root->right), 0);          /**<计算右子树的最大值 */

    g_maxSum = max(g_maxSum, maxLeft+maxRight+root->val);    /**<这里是最有意思的，全局变量g_maxSum比较两种方式最大值，见上 */   

    return max(maxLeft, maxRight) + root->val;               /**<返回单侧最大值 */
}


/** \brief      maxPathSum 二叉树的最小深度 111
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-18
 * 
 *  \param[in] root 输入二叉树根结点
 *  \return         返回最小深度
 */
int maxPathSum(TreeNode* root) {
    oneSideMax(root);
    return g_maxSum;
}

int main(int argc, char *argv[])
{
    std::vector<int> nums1 = {-10,9,20,-1,-1,15,7};
    TreeNode *tree = creatTree(nums1, 0);

    int output = maxPathSum(tree);
    std::cout << output << '\n';

    freeTree(tree);
    return 0;
}