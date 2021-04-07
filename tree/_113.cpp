#include <bits/stdc++.h>
#include "mycommon.hpp"
using namespace std;

/** \brief      backtrack 回溯函数
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-18
 *  \remark     回溯法
 * 
 *  \param[in] root     输入二叉树根节点
 *  \param[in] track    选择
 *  \param[in] sum      目标和
 *  \return             void
 */
vector<vector<int>> res;                /**<结果 */
void backtrack(TreeNode* root, vector<int>& track, int sum) {
    if(root == nullptr)
        return ;

    track.push_back(root->val);                     /**<做选择 */
    if(root->left == nullptr && root->right == nullptr && sum == root->val) {
        res.push_back(track);
    }
    /**<进入下一决策 */
    backtrack(root->left, track, sum - root->val);
    backtrack(root->right, track, sum - root->val);
    track.pop_back();                               /**<撤销选择 */
}

/** \brief      pathSum 路径总和II 113 
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-18
 * 
 *  \param[in] root 输入二叉树根节点
 *  \param[in] sum  目标和
 *  \return         返回是否存在路径和为sum
 */
vector<vector<int>>& pathSum(TreeNode* root, int sum) {
    vector<int> track;                  /**<回溯法的路径数组 */
    backtrack(root, track, sum);
    return res;
}

int main(int argc, char *argv[])
{
    std::vector<int> nums1 = {5,4,8,11,-1,13,4,7,2,-1,-1,-1,-1,-1,5,1};
    TreeNode *tree = creatTree(nums1, 0);

    vector<vector<int>> output = pathSum(tree, 22);
    for(const auto& e : output){
        for(const auto& i : e)
            std::cout << i << ' ';
        std::cout << '\n';
    }

    freeTree(tree);
    return 0;
}