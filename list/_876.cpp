#include <bits/stdc++.h>
#include "mycommon.hpp"
using namespace std;

/** \brief      middleNode  链表的中间结点  876
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-28
 * 
 *  \param[in] head 输入链表
 *  \return         返回中间结点
 */
ListNode* middleNode(ListNode* head) {
    ListNode* fast = head;
    ListNode* slow = head;

    while(fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

int main(int argc, char *argv[])
{
    /**<创建链表 */
    vector<int> s = {1,2,3,4,5};
    ListNode *list = creatList(s);

    ListNode *output = middleNode(list);       /**<do some job */

    printList(list);
    std::cout << "\n";

    freeList(list);                             /**<删除链表 */
    return 0;
}