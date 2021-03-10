#include <bits/stdc++.h>
#include "mycommon.hpp"
using namespace std;

/** \brief      largestValues  二叉树的右视图 199
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-20
 * 
 *  \param[in] root 输入二叉树根节点
 *  \return         二叉树的右视图
 */
vector<int> rightSideView(TreeNode* root) {
    if(root == nullptr) return {};
    vector<int> res;
    queue<TreeNode*> Q;                                                 /**<核心数据结构--队列 */
    Q.push(root);

    while (!Q.empty()) {
        int size = Q.size();
        for (int i = 0; i < size; ++i) {
            TreeNode* node = Q.front(); Q.pop();
            if(i == 0)  res.push_back(node->val);                       /**<右视图 */
            if(node->right != nullptr) Q.push(node->right);
            if(node->left != nullptr) Q.push(node->left);
        }
    }
    return res;
}

int main(int argc, char *argv[])
{
    std::vector<int> nums = {1,2,3,-1,5,-1,4};
    TreeNode *tree = creatTree(nums, 0);

    vector<int> output = rightSideView(tree);
    for(const auto& e :output)
        std::cout << e << std::endl;
    std::cout << '\n';

    freeTree(tree);
    return 0;
}