#include <bits/stdc++.h>
#include "mycommon.hpp"
using namespace std;

/** \brief      removeElements 移除链表元素 203
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-28
 * 
 *  \param[in] head 输入链表
 *  \param[in] val  删除元素
 *  \return         返回删除val后的链表元素
 */
ListNode* removeElements(ListNode* head, int val) {
    ListNode *dummy = new ListNode(INT_MIN, head);

    ListNode *pre = dummy;
    for(ListNode *p = head; p != nullptr; p = p->next) {
        if(p->val == val) {
            pre->next = p->next;
        }else
            pre = pre->next;
    }

    ListNode *temp = dummy->next;
    delete dummy;
    return temp;
}

int main(int argc, char *argv[])
{
    /**<创建链表 */
    vector<int> s = {1,2,6,3,4,5,6};
    ListNode *list = creatList(s);

    list = removeElements(list, 6);       /**<do some job */

    printList(list);
    std::cout << "\n";

    freeList(list);                      /**<删除链表 */
    return 0;
}