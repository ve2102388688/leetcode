#include <bits/stdc++.h>
#include "mycommon.hpp"
using namespace std;

/** \brief      averageOfLevels  二叉树的层平均值 637
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-20
 * 
 *  \param[in] root 输入二叉树根节点
 *  \return         二叉树的层平均值
 */
vector<double> averageOfLevels(TreeNode* root) {
    if(root == nullptr) return {};
    vector<double> res;
    queue<TreeNode*> Q;                                     /**<核心数据结构--队列 */
    Q.push(root);

    while (!Q.empty()) {
        int size = Q.size();
        double sum = 0;
        for (int i = 0; i < size; ++i) {
            TreeNode *node = Q.front(); Q.pop();
            sum += node->val;                               /**<每层总和 */
            if(node->left != nullptr) Q.push(node->left);
            if(node->right != nullptr) Q.push(node->right);
        }
        res.push_back(sum / size);                          /**<层平均值 */
    }
    return res;
}

int main(int argc, char *argv[])
{
    std::vector<int> nums = {3,9,20,-1,-1, 15,7};
    TreeNode *tree = creatTree(nums, 0);

    vector<double> output = averageOfLevels(tree);
    for(const auto& e :output)
        std::cout << e << std::endl;
    std::cout << '\n';

    freeTree(tree);
    return 0;
}