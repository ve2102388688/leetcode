#include <bits/stdc++.h>
#include "mycommon.hpp"
using namespace std;

/** \brief      levelOrder  二叉树的层序遍历 II
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-18
 * 
 *  \param[in] root 输入二叉树根节点
 *  \return         返回层序遍历
 */
vector<vector<int>> levelOrder(TreeNode* root) {
    if(root == nullptr)
        return {};

    vector<vector<int>> res;
    queue<TreeNode*> Q;
    Q.push(root);

    while (!Q.empty()) {
        vector<int> temp;                               /**二维vector需要先把数据放进一维里面 */
        int size = Q.size();

        for (int i = 0; i < size; ++i) {          
            TreeNode* node = Q.front(); Q.pop();
            temp.push_back(node->val);
            if (node->left) Q.push(node->left);
            if (node->right)  Q.push(node->right);
        }
        res.push_back(temp);
    }
    reverse(res.begin(), res.end());
    return res;
}


int main(int argc, char *argv[])
{
    std::vector<int> nums = {3, 9, 20, -1, -1, 15, 7};
    TreeNode *tree = creatTree(nums, 0);

    vector<vector<int>> output = levelOrder(tree);
    for(const auto& e : output){
        for(const auto& i : e)
            std::cout << i << ' ';
        std::cout << '\n';
    }


    freeTree(tree);
    return 0;
}