#include <bits/stdc++.h>
#include "mycommon.hpp"
using namespace std;

/************************************ method1  *************************************************/
/** \brief      getMid 寻找链表的中点
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-19
 * 
 *  \param[in] low  输入下界-闭区间
 *  \param[in] high 输入上界-开区间，注意！！！
 *  \return         返回BST
 */
ListNode* getMid(ListNode* low, ListNode* high) {
    ListNode* fast = low;
    ListNode* slow = low;
    while(fast != high && fast->next != high) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;                /**<链表中点，偶数个中间偏右 */
}

/** \brief      helper2 辅助函数
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-19
 * 
 *  \param[in] low  输入下界-闭区间
 *  \param[in] high 输入上界-开区间，注意！！！
 *  \return         返回BST
 */
TreeNode* helper2(ListNode* low, ListNode* high) {
    if(high == low)             /**<由于是左闭右开，所以两者相等，则退出 */
        return nullptr;

    ListNode *mid = getMid(low, high);
    TreeNode *root = new TreeNode(mid->val);
    /**<注意：左闭右开 */
    root->left = helper2(low, mid);
    root->right = helper2(mid->next, high);
    return root;
}

/** \brief      sortedListToBST 有序链表转换二叉搜索树109
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-19
 * 
 *  \param[in] head 输入有序链表
 *  \return         返回BST
 */
TreeNode* sortedListToBST2(ListNode* head) {
    return helper2(head, nullptr);      /**<注意：左闭右开，右侧直接给空指针即可 */
}


/************************************ method2  *************************************************/

/** \brief      helper 辅助函数
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-19
 * 
 *  \param[in] nums 输入有序数组
 *  \param[in] low  输入下界-闭区间
 *  \param[in] high 输入上界-闭区间
 *  \return         返回BST
 */
TreeNode* helper(vector<int>& nums, int low, int high) {
    if(low > high)                                  /**<无效区间 */
        return nullptr;

    int mid = low + (high - low) / 2;               /**<每次取区间中点作为根结点 */
    TreeNode *root = new TreeNode(nums[mid]);
    root->left = helper(nums, low, mid-1);
    root->right = helper(nums, mid+1, high);
    return root;
}

/** \brief      sortedListToBST 有序链表转换二叉搜索树109
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-19
 * 
 *  \param[in] head 输入有序链表
 *  \return         返回BST
 */
TreeNode* sortedListToBST(ListNode* head) {
    vector<int> nums;
    for (ListNode *p = head; p != nullptr; p = p->next)
        nums.push_back(p->val);

    return helper(nums, 0, nums.size() - 1);
}


int main(int argc, char *argv[])
{
    std::vector<int> nums1 = {-10,-3,0,5,9};
    ListNode *list = creatList(nums1);

    TreeNode* tree = sortedListToBST2(list);
    printTree(tree);
    std::cout << '\n';

    freeTree(tree);
    return 0;
}