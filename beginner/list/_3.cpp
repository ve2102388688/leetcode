#include <bits/stdc++.h>
#include "mycommon.hpp"
using namespace std;

/** \brief      reverseList  链表反序
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-12
 * 
 *  \param[in] head 输入链表
 *  \return         返回反序的链表
 */
ListNode* reverseList(ListNode* head) {
    ListNode *newhead = NULL;

    for(ListNode *p = head; p != NULL; ) {
        ListNode *temp = p->next;           /**<这里要临时转存下p->next,最后又恢复给p  */

        p->next = newhead;
        newhead = p;                        /**<反序头永远要在开头哦 */

        p = temp;
    }
    return newhead;
}


/** \brief      reverseList  链表反序
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-15
 *  \remark     递归方式
 * 
 *  \param[in] head 输入链表
 *  \return         返回反序的链表
 */
ListNode* reverseList2(ListNode* head) {
    if(head == NULL || head->next == NULL)          /**<只有一个元素时直接返回本身即可，当元素中只有一个节点，此时head == NULL */
        return head;
    ListNode *last = reverseList2(head->next);
    head->next->next = head;
    head->next = NULL;
    return last;
}

int main(int argc, char *argv[])
{
    /**<创建链表 */
    vector<int> s = {1, 2, 3, 4, 5};
    ListNode *list = creatList(s);

    list = reverseList2(list);              /**<do some job */

    printList(list);

    freeList(list);
    delete list;                            /**<删除链表 */
    return 0;
}