#include <bits/stdc++.h>
#include "mycommon.hpp"
using namespace std;

/** \brief      helper  检查两颗子树是否对称
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-16
 *  \remark     先序递归
 * 
 *  \param[in] p 输入二叉树根节点
 *  \param[in] q 输入二叉树根节点
 *  \return      返回是否对称
 */
bool helper(TreeNode* p, TreeNode* q) {
    /**<注意判断顺序 */
    if(!p && !q)  return true;                                      /**<两棵子树都为空，返回true */          
    if(!p || !q)  return false;                                     /**<一棵子树为空，返回false */
    /**<p左走q右走；p右走q左走 */    
    return (p->val == q->val) && helper(p->left, q->right) && helper(p->right, q->left);
}

/** \brief      isSymmetric  对称二叉树
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-16
 *  \remark     先序递归
 * 
 *  \param[in] root 输入二叉树根节点
 *  \return         返回是否是对称二叉树
 */
bool isSymmetric(TreeNode* root) {
    return helper(root, root);
}

int main(int argc, char *argv[])
{
    std::vector<int> nums = {1,2,2,3,4,4,3};
    TreeNode *tree = creatTree(nums, 0);

    bool output = isSymmetric(tree);
    std::cout << output << std::endl;

    freeTree(tree);
    return 0;
}