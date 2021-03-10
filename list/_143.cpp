#include <bits/stdc++.h>
#include "mycommon.hpp"
using namespace std;

/** \brief      swapPairs 两两交换链表中的节点 24
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-29
 *  \remark     
 * 
 *  \param[in] head 输入链表
 *  \return         返回没有重复的数字
 */
void reorderList(ListNode* head) {
    if(head == nullptr || head->next == nullptr)
        return ;

    /**找中点 */
    ListNode *fast = head;
    ListNode *slow = head;
    while (fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;
        slow = slow->next;
    }

    ListNode *slowNext = slow->next;                    /**<反序会导致重复中间元素，形成死循环 */
    slow->next = nullptr;

    /**<反序中点后的链表！！！ */
    ListNode *halfSecondHead = nullptr;
    while(slowNext != nullptr){
        ListNode *temp = slowNext->next;
        slowNext->next = halfSecondHead;
        halfSecondHead = slowNext;
        slowNext = temp;
    }

    /**<并归 */
    ListNode *p1 = head;
    ListNode *p2 = halfSecondHead;
    while (p1 != nullptr && p2 != nullptr) {
        ListNode *temp1 = p1->next;
        ListNode *temp2 = p2->next;

        p1->next = p2;
        p1 = temp1;

        p2->next = p1;
        p2 = temp2;
    }
}

int main(int argc, char *argv[])
{
    /**<创建链表 */
    vector<int> s = {1,2,3,4,5};
    ListNode *list = creatList(s);

    reorderList(list);       /**<do some job */

    printList(list);
    std::cout << "\n";

    freeList(list);
    delete list;                            /**<删除链表 */
    return 0;
}