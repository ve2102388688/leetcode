#include <bits/stdc++.h>
#include "mycommon.hpp"
using namespace std;

/** \brief      swapPairs 两两交换链表中的节点 24
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-29
 * 
 *  \param[in] head 输入链表
 *  \return         返回没有重复的数字
 */
ListNode* swapPairs(ListNode* head) {
    if(head == nullptr || head->next == nullptr)        /**<只有一个结点不用交换 */
        return head;
    
    ListNode *dummy = new ListNode(-1, head);
    ListNode *p = dummy;                                /**<工作指针 */
    ListNode *first = head;                             /**<交换第一个结点 */
    ListNode *second = head->next;                      /**<交换第二个结点 */

    while(first != nullptr && second != nullptr) {
        /**<缓存下一次的值 */
        ListNode *temp1 = first->next->next;
        ListNode *temp2 = nullptr;
        if (temp1 != nullptr)                           /**<每次移动两个，前面为空，后面就不用看了 */
            temp2 = second->next->next;

        p->next = second;                               /**<交换*/
        second->next = first;

        p = p->next->next;                               /**<工作指针后移 */
        p->next = nullptr;                               /**<不置空是死循环 */

        first = temp1;                                  /**<恢复，相等于++i */
        second = temp2;
    }
    p->next = first;                                    /**<要么为空，或者奇数 */

    ListNode *temp = dummy->next;
    delete dummy;
    return temp;
}

int main(int argc, char *argv[])
{
    /**<创建链表 */
    vector<int> s = {1,2,3,4,5};
    ListNode *list = creatList(s);

    list = swapPairs(list);       /**<do some job */

    printList(list);
    std::cout << "\n";

    freeList(list);
    delete list;                            /**<删除链表 */
    return 0;
}