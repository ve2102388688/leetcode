#include <bits/stdc++.h>
#include "mycommon.hpp"
using namespace std;

/** \brief      deleteDuplicates  删除排序链表中的重复元素 83
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-28
 * 
 *  \param[in] head 输入链表
 *  \return         返回删除排序链表中的重复元素
 */
ListNode* deleteDuplicates(ListNode* head) {
    if(head == nullptr)                                         /**<空指针的情况*/
        return nullptr;

    ListNode *pre = head;                                       /**<只有不相等pre才前进，要先前进 */
    for (ListNode *p = head->next; p != nullptr; p = p->next) {
        if(pre->val != p->val){
            pre = pre->next;
            pre->val = p->val;
        }
    }
    freeList(pre);                                              /**<释放内存 */
    pre->next = nullptr;
    return head;
}

int main(int argc, char *argv[])
{
    /**<创建链表 */
    vector<int> s = {1,1,2,3,3};
    ListNode *list = creatList(s);

    ListNode *output = deleteDuplicates(list);       /**<do some job */

    printList(list);
    std::cout << "\n";

    freeList(list);
    delete list;                            /**<删除链表 */
    return 0;
}