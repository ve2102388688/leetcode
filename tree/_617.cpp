#include <bits/stdc++.h>
#include "mycommon.hpp"
using namespace std;


/** \brief      help 辅助函数
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-24
 * 
 *  \param[in] root 输入二叉树根结点
 *  \return         返回二叉树的结点和
 */
int ans = 0;
int help(TreeNode *root) {
    if(root == nullptr)
        return 0;

    int L = help(root->left);
    int R = help(root->right);
    ans += abs(L - R);                      /**<左右差的绝对值 */
    return L + R + root->val;               /**<二叉树的结点和 */
}

/** \brief      mergeTrees  合并二叉树 617
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-24
 * 
 *  \param[in] root 输入二叉树根结点
 *  \return         返回合并二叉树
 */
// TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
//     if(t1 == nullptr && t2 == nullptr)
//         return nullptr;

//     int sum = 0;
//     TreeNode *myT1Left = nullptr;            /**<当节点中任意为空，都需要特殊处理 */
//     TreeNode *myT1Right = nullptr;
//     TreeNode *myT2Left = nullptr;
//     TreeNode *myT2Right = nullptr;
//     if (t1 != nullptr){
//         sum += t1->val;
//         myT1Left = t1->left;
//         myT1Right = t1->right;
//     }
//     if(t2 != nullptr) {
//         sum += t2->val;
//         myT2Left = t2->left;
//         myT2Right = t2->right;
//     }

//     TreeNode *root = new TreeNode(sum);
//     root->left = mergeTrees(myT1Left, myT2Left);
//     root->right = mergeTrees(myT1Right, myT2Right);
//     return root;
// }

TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
    if(t1 ==nullptr && t2 == nullptr)                   /**<两边的结点都是空，直接返回 */
        return nullptr;
    if (t1 == nullptr)                                  /**<任意结点为空，返回另外一侧 */
        return new TreeNode(t2);
    if(t2 == nullptr)
        return new TreeNode(t1);

    TreeNode *root = new TreeNode(t1->val+t2->val);
    root->left = mergeTrees(t1->left, t2->left);
    root->right = mergeTrees(t1->right, t2->right);
    return root;
}

int main(int argc, char *argv[])
{
    std::vector<int> nums = {1,3,2,5};
    TreeNode *tree = creatTree(nums, 0);
    std::vector<int> nums2 = {2,1,3,-1,4,-1,7};
    TreeNode *tree2 = creatTree(nums2, 0);

    TreeNode* output = mergeTrees(tree, tree2);
    printTree(output);
    std::cout << '\n';

    freeTree(tree2);
    freeTree(tree);
    freeTree(output);
    return 0;
}