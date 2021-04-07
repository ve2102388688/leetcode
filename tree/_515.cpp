#include <bits/stdc++.h>
#include "mycommon.hpp"
using namespace std;

/** \brief      largestValues  在每个树行中找最大值 515
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-20
 * 
 *  \param[in] root 输入二叉树根节点
 *  \return         二叉树的层最大值
 */
vector<int> largestValues(TreeNode* root) {
    if(root == nullptr) return {};
    vector<int> res;
    queue<TreeNode*> Q;                                                 /**<核心数据结构--队列 */
    Q.push(root);

    while (!Q.empty()) {
        int size = Q.size();
        int maxValue = INT_MIN;                                         /**<寻找最大值先赋值最小值 */
        while (size > 0) {
            TreeNode* node = Q.front(); Q.pop();
            maxValue = node->val >= maxValue ? node->val : maxValue;    /**<寻找层最大值 */ 
            if(node->left != nullptr)   Q.push(node->left);
            if(node->right != nullptr)   Q.push(node->right);
            --size;
        }
        res.push_back(maxValue);
    }
    return res;
}

int main(int argc, char *argv[])
{
    std::vector<int> nums = {1, 3, 2, 5, 3, -1, 9};
    TreeNode *tree = creatTree(nums, 0);

    vector<int> output = largestValues(tree);
    for(const auto& e :output)
        std::cout << e << std::endl;
    std::cout << '\n';

    freeTree(tree);
    return 0;
}