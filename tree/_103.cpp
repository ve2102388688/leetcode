#include <bits/stdc++.h>
#include "mycommon.hpp"
using namespace std;

/** \brief      zigzagLevelOrder 二叉树的锯齿形层序遍历 103
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-19
 * 
 *  \param[in] root 输入二叉树根结点
 *  \return         返回S型层序遍历
 */
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    if(root == nullptr)
        return {};
    
    queue<TreeNode*> Q;
    Q.push(root);
    int level = 0;                                          /**<奇偶层反序 */
    vector<vector<int>> res;

    while (!Q.empty()) {
        list<int> temp;                                     /**<list可以在尾部插入(正序)，也可以在头部插入(倒序)*/
        int size = Q.size();
        while (size > 0) {
            TreeNode* node = Q.front(); Q.pop();
            if(level % 2 == 0)                              /**<奇偶层反序 */
                temp.push_back(node->val);
            else
                temp.push_front(node->val);

            if(node->left != nullptr) Q.push(node->left);
            if(node->right != nullptr) Q.push(node->right);
            --size;
        }
        vector<int> temp2(temp.begin(), temp.end());        /**<用list构建vector */
        res.push_back(temp2);
        ++level;
    }
    return res;
}

int main(int argc, char *argv[])
{
    std::vector<int> nums1 = {3,9,20,-1,-1,15,7};
    TreeNode *tree = creatTree(nums1, 0);

    vector<vector<int>> output = zigzagLevelOrder(tree);
    for(const auto& e : output){
        for(const auto& i : e)
            std::cout << i << ' ';
        std::cout << '\n';
    }
    std::cout << '\n';

    freeTree(tree);
    return 0;
}