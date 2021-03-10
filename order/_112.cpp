#include <bits/stdc++.h>
#include "mycommon.hpp"
using namespace std;


/** \brief      hasPathSum 路径总和 112
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-18
 * 
 *  \param[in] root 输入二叉树根节点
 *  \param[in] sum  目标和
 *  \return         返回是否存在路径和为sum
 */
bool hasPathSum(TreeNode* root, int sum) {
    if(root == nullptr)
        return false;
    if(root->left == nullptr && root->right == nullptr)     /**<叶子结点 */
        return sum == root->val;
    
    return hasPathSum(root->left, sum-root->val) || hasPathSum(root->right, sum-root->val);
}

int main(int argc, char *argv[])
{
    std::vector<int> nums1 = {5,4,8,11,-1,13,4,7,2,-1,-1,-1,-1,-1,1};
    TreeNode *tree = creatTree(nums1, 0);

    bool output = hasPathSum(tree, 22);
    std::cout << output << '\n';

    freeTree(tree);
    return 0;
}