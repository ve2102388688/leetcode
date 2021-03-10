#include <bits/stdc++.h>
#include "mycommon.hpp"
using namespace std;

/** \brief      helper  辅助函数
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-17
 * 
 *  \param[in] inorder      输入inorder数组
 *  \param[in] inLow        输入inorder左闭
 *  \param[in] inHigh       输入inorder右闭
 *  \param[in] postorder    输入postorder数组
 *  \param[in] postLow      输入postorder左闭
 *  \param[in] postHigh     输入postorder右闭
 *  \param[in] inMap        输入中序遍历的hash表
 *  \return                 返回二叉树
 */
TreeNode* helper(vector<int>& inorder, int inLow, int inHigh, vector<int>& postorder, int postLow, int postHigh, unordered_map<int, int>& inMap) {
    /**<一定要想清楚base case */
    if(inLow > inHigh || postLow > postHigh)                /**<无效下标 */
        return nullptr;

    TreeNode* root = new TreeNode(postorder[postHigh]);     /**<创建根节点 */
    int indexInInorder = inMap[postorder[postHigh]];        /**<查找根节点在中序中的位置 */
    int numsOfLeft = indexInInorder - inLow;                /**<左子树的元素个数 */

    root->left = helper(inorder, inLow, indexInInorder-1, postorder, postLow, postLow+numsOfLeft-1, inMap);
    root->right = helper(inorder, indexInInorder+1, inHigh, postorder, postLow+numsOfLeft, postHigh-1, inMap);
    return root;
}

/** \brief      buildTree  106. 从中序与后序遍历序列构造二叉树
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-17
 * 
 *  \param[in] inorder   输入中序遍历数组
 *  \param[in] postorder 输入后序遍历数组
 *  \return              返回二叉树
 */
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    unordered_map<int, int> inMap;                      /**<将中序遍历结果压入Hash，节省查找时间，前提假定二叉树元素没有重复 */
    int size = inorder.size();
    for (int i = 0; i < size; ++i)
        inMap[inorder[i]] = i;

    return helper(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1, inMap);
}

int main(int argc, char *argv[])
{
    std::vector<int> inorder = {9,3,15,20,7};
    std::vector<int> postorder = {9,15,7,20,3};
    TreeNode *tree = buildTree(inorder, postorder);

    printTree(tree);
    std::cout << '\n';

    freeTree(tree);
    return 0;
}

