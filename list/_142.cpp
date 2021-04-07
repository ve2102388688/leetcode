#include <bits/stdc++.h>
#include "mycommon.hpp"
using namespace std;

/** \brief      detectCycle  环形链表 II 142
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-13
 * 
 *  \param[in] head 输入链表
 *  \return         返回环的起点
 */
ListNode *detectCycle(ListNode *head) {
    /**<STEP1 通过快慢指针找到第一次相遇位置 */
    ListNode *fast = head;
    ListNode *slow = head;
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow)
            break;
    }
    /**<循环条件不满足，即不含环，返回NULL，注意判断的顺序 */
    if(fast == NULL || fast->next == NULL)
        return NULL;

    /**<STEP2 将快指针移到开头，以相同的速率行走，相遇则返回 */
    fast = head;
    while (fast != slow) {
        fast = fast->next;
        slow = slow->next;
    }

    return fast;
}

int main(int argc, char *argv[])
{
    /**<创建链表 */
    vector<int> s = {1};
    ListNode *list = creatList(s);

    bool output = detectCycle(list);              /**<do some job */
    std::cout << output << std::endl;

    return 0;
}