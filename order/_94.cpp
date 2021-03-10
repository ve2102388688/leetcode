#include <bits/stdc++.h>
#include "mycommon.hpp"
using namespace std;

vector<int> res;
/** \brief      helper2 辅助函数
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0
 *  \date       2020-1-18
 *  \remark     中序遍历
 * 
 *  \param[in] root 输入二叉树根节点
 *  \return         返回中序遍历
 */
void helper(TreeNode *root) {
    if(root == nullptr)
        return;

    helper(root->left);
    res.push_back(root->val);
    helper(root->right);
}

/** \brief      helper2 辅助函数
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0
 *  \date       2020-1-18
 *  \remark     栈
 * 
 *  \param[in] root 输入二叉树根节点
 *  \return         返回中序遍历
 */
void helper2(TreeNode* root) {
    if(root == nullptr)
        return ;
    
    stack<TreeNode*> sta;
    TreeNode *p = root;

    while (!sta.empty() || p) {                          /**<什么时候栈空了但是p不空？根节点遍历完成即将遍历根的右子树 */
        while(p) {                                       /**<一直向左走到底，先压入根结点再向左走 */
            sta.push(p);
            p = p->left;
        }

        p = sta.top(); sta.pop();                        /**<弹出的是根结点 */
        res.push_back(p->val);
        p = p->right;                                    /**<处理右子树 */
    }
}


/** \brief      inorderTraversal  二叉树的中序遍历 94 
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-18
 *  \remark     中序递归
 * 
 *  \param[in] root 输入二叉树根节点
 *  \return         返回中序遍历
 */
vector<int>& inorderTraversal(TreeNode* root) {
    helper2(root);
    return res;
}


int main(int argc, char *argv[])
{
    std::vector<int> nums = {3, 9, 20, -1, -1, 15, 7};
    TreeNode *tree = creatTree(nums, 0);

    std::vector<int> output = inorderTraversal(tree);
    for(const auto& e : output)
        std::cout << e << " ";
    std::cout << "\n";

    freeTree(tree);
    return 0;
}