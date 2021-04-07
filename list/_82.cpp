#include <bits/stdc++.h>
#include "mycommon.hpp"
using namespace std;

ListNode* deleteElem(ListNode *left, ListNode *right) {
    while (left != right) {
        ListNode *temp = left;
        left = left->next;
        delete temp;
    }
    return right;
}

/** \brief      deleteDuplicates 删除排序链表中的重复元素II  82
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-28
 * 
 *  \param[in] head 输入链表
 *  \return         返回没有重复的数字
 */
ListNode* deleteDuplicates(ListNode* head) {
    if(head == nullptr)
        return nullptr;

    ListNode *dummy = new ListNode(INT_MIN, head);
    ListNode *replace = dummy;
    ListNode *left = head;                              /**<只要有相同的元素，则left和right就不相等 */
    ListNode *right = head;

    while (right != nullptr) {
        /**<寻找相同元素*/  
        while(right->next != nullptr && right->next->val == left->val)
            right = right->next;

        if(left == right){                      /**<不同元素，加入replace不动 */
            replace->next = right;
            replace = replace->next;
            left = right = right->next;             /**<不管有没有重复元素，都会处理下一个right->next */
        }else
            left = right = deleteElem(left, right->next);            /**释放内存，从left到right*/
        
    }
    replace->next = nullptr;

    ListNode *temp = dummy->next;
    delete dummy;
    return temp;
}

int main(int argc, char *argv[])
{
    /**<创建链表 */
    vector<int> s = {1,2,3,3,4,4,5};
    ListNode *list = creatList(s);

    ListNode *output = deleteDuplicates(list);       /**<do some job */

    printList(output);
    std::cout << "\n";

    freeList(list);
    delete list;                            /**<删除链表 */
    return 0;
}