#include <bits/stdc++.h>
#include "mycommon.hpp"
using namespace std;

/** \brief      rob 打家劫舍 337
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-2-10
 * 
 *  \param[in] root 输入二叉树根结点
 *  \return         偷窃的最大金额
 */
unordered_map<TreeNode*, int> memo;
int rob(TreeNode* root) {
    if (root == nullptr)
        return 0;
    if (memo.count(root))            /**<已经计算过，直接使用 */
        return memo[root];

    int do_rob = root->val +
        ((root->left == nullptr) ? 0 : rob(root->left->left) + rob(root->left->right)) +    /**<注意有大括号 */
        ((root->right == nullptr) ? 0 : rob(root->right->left) + rob(root->right->right));
    int not_rob = rob(root->left) + rob(root->right);

    int res = max(do_rob, not_rob);
    memo[root] = res;               /**<保存进备忘录 */
    return res;
}

int main(int argc, char *argv[])
{
    vector<int> nums = {3,4,5,1,3,-1,1};
    TreeNode *tree = creatTree(nums, 0);

    int output = rob(tree);
    std::cout << output << std::endl;

    freeTree(tree);
    return 0;
}