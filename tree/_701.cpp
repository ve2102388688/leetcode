#include <bits/stdc++.h>
#include "mycommon.hpp"
using namespace std;

/** \brief      insertIntoBST 二叉搜索树中的插入操作 701
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-21
 * 
 *  \param[in] root 输入二叉树根结点
 *  \param[in] val  插入值
 *  \return         返回查找结点
 */
TreeNode* insertIntoBST(TreeNode* root, int val) {
    if(root == nullptr) 
        return new TreeNode(val);                           /**<为空，找到目标位置 */

    if(root->val < val)
        root->right = insertIntoBST(root->right, val);      /**<在右子树上插图并修改右子树 */
    if(root->val > val)
        root->left = insertIntoBST(root->left, val);        /**<在左子树上插图并修改左子树 */
    return root;
}

int main(int argc, char *argv[])
{
    std::vector<int> nums = {4,2,7,1,3};
    TreeNode *tree = creatTree(nums, 0);

    TreeNode *output = insertIntoBST(tree, 5);
    printTree(output);
    std::cout << '\n';

    freeTree(tree);
    return 0;
}