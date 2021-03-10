#include <bits/stdc++.h>
#include "mycommon.hpp"
using namespace std;

vector<TreeNode *> res;             /**<结果，每一个只保存一次 */
unordered_map<string, int>  memo;   /**<子树 */          

/** \brief      helper  辅助函数
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-17
 * 
 *  \param[in] root 输入二叉树根节点
 *  \return         返回序列化
 */
string helper(TreeNode* root) {
    if(root == nullptr)
        return "#";                                         /**<这里必须用一个分隔符分割左右子树 */

    string left = helper(root->left);
    string right = helper(root->right);
    string subTree = left + right + to_string(root->val);   /**<子树序列化，描述自己 */

    if(memo[subTree]++ == 1)                                /**<重复至少是两次，也就是第二次出现的时候就应该加入结果 */
        res.push_back(root);

    return subTree;
}

/** \brief      constructMaximumBinaryTree  654. 最大二叉树
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-17
 * 
 *  \param[in] root 输入二叉树根节点
 *  \return         返回二叉树
 */
vector<TreeNode*>& findDuplicateSubtrees(TreeNode* root) {
    helper(root);
    return res;
}

int main(int argc, char *argv[])
{
    std::vector<int> nums = {1,2,3,4,-1,2,4,-1,-1,-1,-1,4};
    TreeNode *tree = creatTree(nums, 0);

    std::vector<TreeNode*> output = findDuplicateSubtrees(tree);
    for(const auto& e : output){
        printTree(e);
        std::cout << '\n';
    }

    freeTree(tree);
    return 0;
}

