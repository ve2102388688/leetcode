#include <bits/stdc++.h>
#include "mycommon.hpp"
using namespace std;

/** \brief      minDepth 二叉树的最小深度 111
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-18
 * 
 *  \param[in] root 输入二叉树根节点
 *  \return         返回最小深度
 */
int minDepth(TreeNode* root) {
    if(root == nullptr) 
        return 0;
    if(root->left == nullptr && root->right == nullptr)        /**<到达叶子节点 */
        return 1;

    /**<特殊情况：单支树 */
    int min_depth = INT_MAX;
    if (root->left != nullptr)
        min_depth =  min(minDepth(root->left), min_depth);
    if(root->right != nullptr)
        min_depth = min(minDepth(root->right), min_depth);
    return min_depth + 1;
}


/** \brief      minDepth2 二叉树的最小深度 111
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-18
 *  \remark     BFS注定适用与最短问题，只要到达叶子节点，一定是最短的
 * 
 *  \param[in] root 输入二叉树根节点
 *  \return         返回最小深度
 */
int minDepth2(TreeNode* root) {
    if(root == nullptr)
        return 0;

    queue<TreeNode*> Q;
    Q.push(root);
    int depth = 1;                                                      /**<层数为1 */

    while (!Q.empty()) {
        int size = Q.size();
        while (size > 0) {
            TreeNode* node = Q.front(); Q.pop();
            if (node->left == nullptr && node->right == nullptr)        /**<到达叶子节点，最小深度，直接返回 */
                return depth;
            if(node->left != nullptr)                                   /**<不空进入队列 */
                Q.push(node->left);
            if(node->right != nullptr)
                Q.push(node->right);
            --size;
        }
        ++depth;
    }
    return depth;
}

int main(int argc, char *argv[])
{
    std::vector<int> nums1 = {3,9,20,-1,-1,15,7};
    TreeNode *tree = creatTree(nums1, 0);

    int output = minDepth2(tree);
    std::cout << output << '\n';

    freeTree(tree);
    return 0;
}