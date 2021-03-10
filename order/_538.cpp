#include <bits/stdc++.h>
#include "mycommon.hpp"
using namespace std;

/** \brief      help  辅助函数
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-21
 * 
 *  \param[in] root 输入二叉树根结点
 *  \return         void
 */
int lastSum = 0;                    /**<上次结点的值 */
void help(TreeNode *root) {
    if(root == nullptr) return ;
    help(root->right);
    root->val += lastSum;
    lastSum = root->val;            /**<记录上一次结点的值 */
    help(root->left);
}

/** \brief      convertBST  把二叉搜索树转换为累加树 538/1038
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-21
 * 
 *  \param[in] root 输入二叉树根结点
 *  \return         返回累加树
 */
TreeNode *convertBST(TreeNode *root) {
    help(root);
    return root;
}

int main(int argc, char *argv[])
{
    std::vector<int> nums = {4,1,6,0,2,5,7,-1,-1,-1,3,-1,-1,-1,8};
    TreeNode *tree = creatTree(nums, 0);

    tree = convertBST(tree);
    printTree(tree);
    std::cout << '\n';

    freeTree(tree);
    return 0;
}