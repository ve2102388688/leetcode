#include <bits/stdc++.h>
#include "mycommon.hpp"
using namespace std;


/** \brief      serialize 二叉树的序列化与反序列化 297
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-30
 *  \remark     先序序列化
 * 
 *  \param[in] root 输入二叉树根节点
 *  \return         返回序列化的值
 */
string serialize(TreeNode* root) {
    if(root == nullptr)
        return "#";
    return to_string(root->val) + ',' + serialize(root->left) + ',' + serialize(root->right);
}


/** \brief      split 分割字符串
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-30
 * 
 *  \param[in] str      输入字符串
 *  \param[in] pattern  分隔符
 *  \return             返分割后的字符串
 */
queue<string> split(const string& str, const string& pattern) {
    /**<const char*转char* */
    const char *cstr = str.c_str();                         /**<由于c_str返回const,这里要修改，所以要转成char* */
    char *s = new char[strlen(cstr) + 1];
    strcpy(s, cstr);

    queue<string> res;
    char *tempStr = strtok(s, pattern.c_str());             /**<分割字符串函数strtok */
    while (tempStr != NULL) {
        res.push(string(tempStr));
        tempStr = strtok(NULL, pattern.c_str());            /**<第一个参数要改成NULL */
    }

    delete[] s;
    return res;
}


/** \brief      helper 辅助函数
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-30
 * 
 *  \param[in] node 输入序列化字符串
 *  \return         返回树的根结点
 */
TreeNode *helper(queue<string>& node) {
    if(node.empty())
        return nullptr;

    string first = node.front(); node.pop();                /**<第一个结点就是根结点 */
    if(first == "#")                                        /**<#就是空指针 */
        return nullptr;

    TreeNode *root = new TreeNode(atoi(first.c_str()));
    root->left = helper(node);
    root->right = helper(node);
    return root;
}


/** \brief      deserialize 二叉树的序列化与反序列化 297
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-30
 * 
 *  \param[in] data 输入序列化字符串
 *  \return         返回树的根结点
 */
const string pattern = ",";
TreeNode *deserialize(string data) {
    if(data.empty())
        return nullptr;

    /**<分割字符串 */
    queue<string> res = split(data, pattern);

    return helper(res);
}


int main(int argc, char *argv[])
{
    std::vector<int> nums1 = {1, 2, 3, -1, -1, 4, 5};
    TreeNode *tree = creatTree(nums1, 0);

    string output = serialize(tree);
    std::cout << output << '\n';
    freeTree(tree);

    tree = deserialize(output);
    printTree(tree);
    std::cout << '\n';
    freeTree(tree);

    return 0;
}