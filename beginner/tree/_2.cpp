#include <bits/stdc++.h>
#include "mycommon.hpp"
using namespace std;

/** \brief      helper  辅助函数
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-16
 * 
 *  \param[in] root  输入二叉树根节点
 *  \param[in] lower lower < 左子树 < root
 *  \param[in] upper root < 右子树 < upper
 *  \return          返回是否是BST
 */
bool helper(TreeNode* root, long long int lower, long long int upper){
    if(root == nullptr) return true;
    if(root->val <= lower || root->val >= upper)        /**<不符合的BST */
        return false;

    return helper(root->left, lower, root->val) && helper(root->right, root->val, upper);
}


/** \brief      isValidBST  验证二叉搜索树
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-15
 *  \remark     先序递归
 * 
 *  \param[in] root 输入二叉树根节点
 *  \return         返回是否是BST
 */
bool isValidBST(TreeNode* root) {
    return helper(root, LONG_MIN, LONG_MAX);
}


/** \brief      isValidBST2  验证二叉搜索树
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-16
 *  \remark     栈的方式迭代
 * 
 *  \param[in] root 输入二叉树根节点
 *  \return         返回是否是BST
 */
bool isValidBST2(TreeNode* root) {
    if(root == nullptr) return true;
    stack<TreeNode*> sta;
    TreeNode* p = root;                                 /**<注意：不要修改根节点 */
    long long int inorder = (long long)INT_MIN - 1;     

    while(!sta.empty() || p) {                          /**<什么时候栈空了但是p不空？根节点遍历完成即将遍历根的右子树 */
        while (p) {                                     /**<一直向左走到底，先压入根结点再向左走 */
           sta.push(p);
           p = p->left;
        }

        p = sta.top(); sta.pop();                       /**<弹出的是根结点 */
        if(p->val <= inorder)                           /**<根结点应该大于上次的根结点 */
            return false;
        
        inorder = p->val;                               /**<始终保证inorder是前驱的值 */
        p = p->right;                                   /**<处理右子树 */
    }
    return true;
}

int main(int argc, char *argv[])
{
    std::vector<int> nums = {2,5,3};
    TreeNode *tree = creatTree(nums, 0);

    // bool output = isValidBST(tree);
    bool output = isValidBST2(tree);
    std::cout << output << std::endl;

    freeTree(tree);
    return 0;
}