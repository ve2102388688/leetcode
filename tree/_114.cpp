#include <bits/stdc++.h>
#include "mycommon.hpp"
using namespace std;

/** \brief      flatten  114. 二叉树展开为链表(好像先序遍历)
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-16
 * 
 *  \param[in] root 输入二叉树根节点
 *  \return         返回链表
 */
void flatten(TreeNode* root) {
    /**<先序、后序都可以做，但是先序不太好理解 */
    if(root == nullptr) return ;

    /**<左子树和右子树分别拉直 */
    flatten(root->left);
    flatten(root->right);

    TreeNode *rootLeft = root->left;        /**<缓存左侧flatten */
    TreeNode *rootRight = root->right;      /**<缓存右侧flatten */
    root->left = nullptr;
    root->right = rootLeft;
    
    TreeNode* p = root;
    while(p->right != nullptr)               /**<走到底 */
        p = p->right;
    p->right = rootRight;                   /**<到底直接连上原来的rootRight */
}

int main(int argc, char *argv[])
{
    std::vector<int> nums = {4,2,7,1,3,6,9, 1,2,3,4,5,6,7,8};
    TreeNode *tree = creatTree(nums, 0);

    flatten(tree);
    printTree(tree);
    std::cout << '\n';

    freeTree(tree);
    return 0;
}