#include <bits/stdc++.h>
#include "mycommon.hpp"
using namespace std;

/** \brief      maxDepth  二叉树的最大深度
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-15
 *  \remark     先序递归
 * 
 *  \param[in] s 输入二叉树根节点
 *  \return      返回树高
 */
int maxDepth(TreeNode* root) {
    if(root == nullptr)
        return 0;
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    return (leftDepth >= rightDepth) ? leftDepth + 1 : rightDepth + 1;
}


/** \brief      maxDepth2  二叉树的最大深度
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-15
 *  \remark     BFS
 * 
 *  \param[in] root 输入二叉树根节点
 *  \return         返回树高
 */
int maxDepth2(TreeNode* root) {
    if(root == nullptr)
        return 0;
    
    int depth = 0;
    queue<TreeNode*> Q;
    Q.push(root);
    while (!Q.empty()) {
        int size = Q.size();
        while (size > 0) {
            TreeNode *node = Q.front(); Q.pop();
            if(node->left)  Q.push(node->left);
            if(node->right)  Q.push(node->right);
            --size;
        }
        ++depth;
    }
    return depth;
}

int main(int argc, char *argv[])
{
    std::vector<int> nums = {3, 9, 20, -1, -1, 15, 7};
    TreeNode *tree = creatTree(nums, 0);
    traverseIn(tree);
    std::cout << '\n';

    int depth = maxDepth2(tree);
    std::cout << depth << std::endl;

    freeTree(tree);
    return 0;
}