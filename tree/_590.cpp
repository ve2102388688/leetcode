#include <bits/stdc++.h>
#include "mycommon.hpp"
using namespace std;

/** \brief      help 辅助函数
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-2-4
 * 
 *  \param[in] root 输入N叉树根结点
 *  \return         void
 */
vector<int> g_res;
void help(Node *root) {
    if(root == nullptr)
        return ;
    for (const auto &e : root->children)
        help(e);
    g_res.push_back(root->val);
}

/** \brief      postorder N叉树的后序遍历 590
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-2-4
 * 
 *  \param[in] root 输入N叉树根结点
 *  \return         N叉树的后序遍历
 */
vector<int> postorder(Node* root) {
    help(root);
    return g_res;
}

int main(int argc, char *argv[])
{
    // std::vector<int> nums = {1,2,3,-1,5,-1,4};
    // TreeNode *tree = creatTree(nums, 0);

    // vector<vector<int>> output = levelOrder(tree);
    // for(const auto& e :output) {
    //     for (const auto& i :e)
    //         std::cout << i << std::endl;
    //     std::cout << '\n';
    // }

    // freeTree(tree);
    return 0;
}