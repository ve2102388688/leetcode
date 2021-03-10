#include <bits/stdc++.h>
#include "mycommon.hpp"
using namespace std;

/** \brief      helper  辅助函数
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-17
 * 
 *  \param[in] preorder 输入preorder数组
 *  \param[in] preLow   输入preorder左闭
 *  \param[in] preHigh  输入preorder右闭
 *  \param[in] inorder  输入inorder数组
 *  \param[in] inLow    输入inorder左闭
 *  \param[in] inHigh   输入inorder右闭
 *  \param[in] inMap    输入中序遍历的hash表
 *  \return             返回二叉树
 */
TreeNode* helper(vector<int>& preorder, int preLow, int preHigh, vector<int>& inorder, int inLow, int inHigh, unordered_map<int, int>& inMap) {
    /**<一定要想清楚base case */
    if(preLow > preHigh || inLow > inHigh)                  /**<无效下标 */
        return nullptr;

    TreeNode* root = new TreeNode(preorder[preLow]);        /**<创建根节点 */
    int indexInInorder = inMap[preorder[preLow]];           /**<查找根节点在中序中的位置 */
    int numsOfLeft = indexInInorder - inLow;                /**<左子树的元素个数 */

    root->left = helper(preorder, preLow + 1, preLow+numsOfLeft, inorder, inLow, indexInInorder - 1, inMap);
    root->right = helper(preorder, preLow+numsOfLeft+1, preHigh, inorder, indexInInorder+1, inHigh, inMap);
    return root;
}

/** \brief      buildTree  105. 从前序与中序遍历序列构造二叉树
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-17
 * 
 *  \param[in] preorder 输入先序遍历数组
 *  \param[in] inorder  输入中序遍历数组
 *  \return             返回二叉树
 */
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    unordered_map<int, int> inMap;                      /**<将中序遍历结果压入Hash，节省查找时间，前提假定二叉树元素没有重复 */
    int size = inorder.size();
    for (int i = 0; i < size; ++i)
        inMap[inorder[i]] = i;

    return helper(preorder, 0, preorder.size() - 1, preorder, 0, inorder.size() - 1, inMap);
}

int main(int argc, char *argv[])
{
    std::vector<int> preorder = {3,9,20,15,7};
    std::vector<int> inorder = {9,3,15,20,7};
    TreeNode *tree = buildTree(preorder, inorder);

    printTree(tree);
    std::cout << '\n';

    freeTree(tree);
    return 0;
}

