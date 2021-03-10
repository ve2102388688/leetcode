#include <bits/stdc++.h>
#include "mycommon.hpp"
using namespace std;

/** \brief      helper  辅助函数
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-20
 * 
 *  \param[in] root 输入二叉树根节点
 *  \param[in] k    第K小的元素
 *  \return         void
 */
int ans = 0;                            /**<结果 */
int order = 0;                          /**<顺序值 */
void helper(TreeNode *root, int k) {
    if(root == nullptr)
        return ;
    
    helper(root->left, k);

    ++order;                            /**<中序遍历（严格递增序列），每次加1 */
    if (order == k){
        ans = root->val;
        return;
    }

    helper(root->right, k);
}

/** \brief      kthSmallest  二叉搜索树中第K小的元素
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-20
 * 
 *  \param[in] root 输入二叉树根节点
 *  \param[in] k    K小
 *  \return         第K小的元素
 */
int kthSmallest(TreeNode* root, int k) {
    helper(root, k);
    return ans;
}

int main(int argc, char *argv[])
{
    std::vector<int> nums = {3,1,4,-1,2};
    TreeNode *tree = creatTree(nums, 0);

    int output = kthSmallest(tree, 1);
    std::cout << output << std::endl;

    freeTree(tree);
    return 0;
}