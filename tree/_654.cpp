#include <bits/stdc++.h>
#include "mycommon.hpp"
using namespace std;

/** \brief      helper  辅助函数
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-17
 * 
 *  \param[in] nums 输入数组
 *  \param[in] low  输入左闭
 *  \param[in] high 输入右闭
 *  \return         返回二叉树
 */
TreeNode* helper(vector<int>& nums, int low, int high) {
    /**<一定要想清楚base case */
    if(low > high)
        return nullptr;

    /**<寻找最大值和下标 */
    int maxVal = nums[low];                         /**<由于low,high都是可达区间，即至少一个元素，不妨记low为最大值下标 */
    int maxIndex = low;
    for (int i = low + 1; i <= high; ++i) {
        if(maxVal < nums[i]){
            maxVal = nums[i];
            maxIndex = i;
        }
    }
    TreeNode *root = new TreeNode(maxVal);
    root->left = helper(nums, low, maxIndex - 1);
    root->right = helper(nums, maxIndex + 1, high);

    return root;
}

/** \brief      constructMaximumBinaryTree  654. 最大二叉树
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-17
 * 
 *  \param[in] nums 输入数组
 *  \return         返回二叉树
 */
TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    return helper(nums, 0, nums.size() - 1);
}

int main(int argc, char *argv[])
{
    std::vector<int> nums = {3,2,1,6,0,5};
    TreeNode *tree = constructMaximumBinaryTree(nums);

    printTree(tree);
    std::cout << '\n';

    freeTree(tree);
    return 0;
}

