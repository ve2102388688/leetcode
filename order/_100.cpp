#include <bits/stdc++.h>
#include "mycommon.hpp"
using namespace std;

/** \brief      levelOrder  相同的树
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-18
 * 
 *  \param[in] p 输入二叉树根节点
 *  \param[in] q 输入二叉树根节点
 *  \return      返回是否相同
 */
bool isSameTree(TreeNode* p, TreeNode* q) {
    /**<注意判断顺序 */
    if(!p && !q)    return true;                                      /**<两棵子树都为空，返回true */     
    if(!p || !q)    return false;                                     /**<一棵子树为空，返回false */
    return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

int main(int argc, char *argv[])
{
    std::vector<int> nums1 = {1,2,1};
    std::vector<int> nums2 = {1,1,2};
    TreeNode *tree1 = creatTree(nums1, 0);
    TreeNode *tree2 = creatTree(nums2, 0);

    bool output = isSameTree(tree1, tree2);
    std::cout << output << '\n';

    freeTree(tree1);
    freeTree(tree2);
    return 0;
}