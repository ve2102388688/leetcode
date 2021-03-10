#include <bits/stdc++.h>
#include "mycommon.hpp"
using namespace std;

/** \brief      helper 辅助函数
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-19
 * 
 *  \param[in] nums 输入有序数组
 *  \param[in] low  输入下界-闭区间
 *  \param[in] high 输入上界-闭区间
 *  \return         返回BST
 */
TreeNode* helper(vector<int>& nums, int low, int high) {
    if(low > high)                                  /**<无效区间 */
        return nullptr;

    int mid = low + (high - low) / 2;               /**<每次取区间中点作为根结点 */
    TreeNode *root = new TreeNode(nums[mid]);
    root->left = helper(nums, low, mid-1);
    root->right = helper(nums, mid+1, high);
    return root;
}

/** \brief      sortedArrayToBST 将有序数组转换为二叉搜索树 108
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-19
 * 
 *  \param[in] nums 输入有序数组
 *  \return         返回BST
 */
TreeNode* sortedArrayToBST(vector<int>& nums) {
    return helper(nums, 0, nums.size() - 1);
}

int main(int argc, char *argv[])
{
    std::vector<int> nums1 = {-10,-3,0,5,9};
    TreeNode *tree = sortedArrayToBST(nums1);

    printTree(tree);
    std::cout << '\n';

    freeTree(tree);
    return 0;
}