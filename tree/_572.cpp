#include <bits/stdc++.h>
#include "mycommon.hpp"
using namespace std;

/** \brief      preSerialization 前序序列化
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-4-8
 * 
 *  \param[in] root      输入二叉树根结点
 *  \param[in] serialize 序列化值
 *  \return              void
 */
void preSerialization(TreeNode *root, vector<int>& serialize) {
    if (root == nullptr)
        return ;
    
    serialize.push_back(root->val);
    if (root->left)
        preSerialization(root->left, serialize);
    else
        serialize.push_back(INT_MIN);                       /**<左空记录成INT_MIN */
    
    if (root->right)
        preSerialization(root->right, serialize);
    else
        serialize.push_back(INT_MAX);                       /**<左空记录成INT_MAX */
}


void getNext(int *next, vector<int>& pattern) {
    int j = 0;
    next[j] = 0;
    
    int size = pattern.size();
    for (int i = 1; i < size; ++i) {
        while(j>0 && pattern[i]!=pattern[j])
            j = next[j-1];                                  /**<从j-1的回退值开始回退 */
        if(pattern[i] == pattern[j])
            ++j;
        next[i] = j;
    }
}

/** \brief      kmp 字符串匹配
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-4-8
 * 
 *  \param[in] s       源串
 *  \param[in] pattern 模式串
 *  \return            是否存在
 */
bool kmp(vector<int>&s, vector<int>& pattern) {
    int size = pattern.size();
    if (size == 0)
        return false;
    
    int next[size];
    getNext(next, pattern);                     /**<最长相等前后缀 */
    
    int j = 0;
    for (int i = 0; i < s.size(); ++i) {
        while (j>0 && s[i] != pattern[j])
            j = next[j-1];
        if (s[i] == pattern[j])
            ++j;
        if (j == size)
            return true; 
    }
    return false;
}

bool isSubtree(TreeNode* s, TreeNode* t)  {
    vector<int> serialize1;
    vector<int> serialize2;
    preSerialization(s, serialize1);            /**>前序序列化 */
    preSerialization(t, serialize2);
    return kmp(serialize1, serialize2);
}


int main(int argc, char *argv[])
{
    std::vector<int> nums = {1,2,3,4,5};
    TreeNode *tree = creatTree(nums, 0);
    std::vector<int> nums2 = {2,4,5};
    TreeNode *tree2 = creatTree(nums2, 0);

    bool output = isSubtree(tree, tree2);
    std::cout << output << '\n';

    freeTree(tree);
    freeTree(tree2);
    return 0;
}