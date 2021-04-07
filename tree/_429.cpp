#include <bits/stdc++.h>
#include "mycommon.hpp"
using namespace std;

/** \brief      levelOrder  N叉树的层序遍历 429 
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-20
 * 
 *  \param[in] root 输入N叉树根节点
 *  \return         N叉树的层序遍历
 */
vector<vector<int>> levelOrder(Node* root) {
    if(root == nullptr) return {};
    vector<vector<int>> res;
    queue<Node*> Q;                                                 /**<核心数据结构--队列 */
    Q.push(root);

    while (!Q.empty()) {
        vector<int> temp;
        int size = Q.size();
        while (size > 0) {                                          /**<遍历当前层 */
            Node *node = Q.front(); Q.pop();
            temp.push_back(node->val);
            for(const auto& e : node->children)                     /**<压入下一层  */
                Q.push(e);
            --size;
        }
        res.push_back(temp);
    }
    return res;
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