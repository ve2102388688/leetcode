#include <bits/stdc++.h>
#include "mycommon.hpp"
using namespace std;

/** \brief      searchBST 二叉搜索树中的搜索 700
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-21
 * 
 *  \param[in] root 输入二叉树根结点
 *  \param[in] val  待查找的值
 *  \return         返回查找结点
 */
TreeNode* searchBST(TreeNode* root, int val) {
    if(root == nullptr) return nullptr;

    if(root->val == val)                        /**<查找成功 */
        return root;
    return (root->val < val) ? searchBST(root->right, val) : searchBST(root->left, val);
}

int main(int argc, char *argv[])
{
    std::vector<int> nums = {4,2,7,1,3};
    TreeNode *tree = creatTree(nums, 0);

    TreeNode *output = searchBST(tree, 2);
    printTree(output);
    std::cout << '\n';

    freeTree(tree);
    return 0;
}