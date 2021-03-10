#include <bits/stdc++.h>
#include "mycommon.hpp"
using namespace std;

/** \brief      sortedArrayToBST  将有序数组转换为二叉搜索树
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-16
 * 
 *  \param[in] nums 输入有序数组
 *  \return         返回BST
 */
TreeNode* sortedArrayToBST(vector<int>& nums) {
    
}

int main(int argc, char *argv[])
{
    std::vector<int> nums = {3, 9, 20, -1, -1, 15, 7};

    TreeNode *tree = sortedArrayToBST(nums);

    freeTree(tree);
    return 0;
}