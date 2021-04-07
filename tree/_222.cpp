#include <bits/stdc++.h>
#include "mycommon.hpp"
using namespace std;


/** \brief      countNodes 完全二叉树的节点个数 222
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-21
 * 
 *  \param[in] root 输入二叉树根结点
 *  \return         返回查找结点
 */
int countNodes(TreeNode* root) {
    if(root ==  nullptr)    return 0;

    /**<计算左子树的高度 */
    int hl = 0; TreeNode* p = root;
    while ( p != nullptr) {
        ++hl;
        p = p->left;
    }
    /**<计算右子树的高度 */
    int hr = 0; TreeNode* q = root;
    while ( q != nullptr) {
        ++hr;
        q = q->right;
    }
    /**<相等就是满二叉树，直接用公式计算 */
    if(hl == hr)
        return static_cast<int>(pow(2, hl) - 1);

    return 1 + countNodes(root->left) + countNodes(root->right);    /**<递归只会执行一次，因为完全二叉树必有一棵子树是完全二叉树 */
}

int main(int argc, char *argv[])
{
    std::vector<int> nums = {1,2,3,4,5,6};
    TreeNode *tree = creatTree(nums, 0);

    int output = countNodes(tree);
    std::cout << output << '\n';

    freeTree(tree);
    return 0;
}