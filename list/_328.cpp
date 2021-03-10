#include <bits/stdc++.h>
#include "mycommon.hpp"
using namespace std;

/** \brief      oddEvenList 奇偶链表 328
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-29
 *  \remark     奇数先开始，必定先结束，判断用奇头，注意&&
 * 
 *  \param[in] head 输入链表
 *  \return         返回没有重复的数字
 */
ListNode* oddEvenList(ListNode* head) {
    if(head == nullptr || head->next == nullptr || head->next->next == nullptr)
        return head;

    ListNode *headEven = head->next;                /**<偶数链表的头 */
    /**<奇偶工作指针 */
    ListNode *pOdd = head;
    ListNode *pEven = head->next;
    while (pOdd->next != nullptr && pOdd->next->next != nullptr) {
        pOdd->next = pOdd->next->next;
        pEven->next = pEven->next->next;

        /**<while语句标配 */
        pOdd = pOdd->next;
        pEven = pEven->next;
    }
    pOdd->next = headEven;                        /**<奇数链表的头 */
    return head;
}

int main(int argc, char *argv[])
{
    /**<创建链表 */
    vector<int> s = {1,2,3,4};
    ListNode *list = creatList(s);

    list = oddEvenList(list);       /**<do some job */

    printList(list);
    std::cout << "\n";

    freeList(list);
    delete list;                            /**<删除链表 */
    return 0;
}