#include <bits/stdc++.h>
#include "mycommon.hpp"
using namespace std;


/** \brief      isUnivalTree 单值二叉树 965
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-21
 * 
 *  \param[in] root 输入二叉树根结点
 *  \return         返回是否是单值二叉树
 */
bool isUnivalTree(TreeNode* root) {
    if(root == nullptr) return true;
    
    queue<TreeNode*> Q;
    Q.push(root);
    int lastValue = root->val;

    while (!Q.empty()){
        int size = Q.size();
        while (size > 0) {
            TreeNode* node = Q.front(); Q.pop();
            if(lastValue != node->val)                      /**<发现不相等，直接返回false */
                return false;
            lastValue = node->val;
            if(node->left != nullptr)  Q.push(node->left);
            if(node->right != nullptr)  Q.push(node->right);
            --size;
        }
    }
    return true;
}

int main(int argc, char *argv[])
{
    std::vector<int> nums = {1,1,1,1,2,1};
    TreeNode *tree = creatTree(nums, 0);

    bool output = isUnivalTree(tree);
    std::cout << output << '\n';

    freeTree(tree);
    return 0;
}