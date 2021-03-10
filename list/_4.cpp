#include <bits/stdc++.h>
#include "mycommon.hpp"
using namespace std;

/** \brief      mergeTwoLists  合并两个有序链表
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-13
 * 
 *  \param[in] s 输入字符串
 *  \return      返回最长回文子串
 */
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    /**<为什么要额外定义一个dummy，如果不，那么真正工作的p的初始值是NULL，定义指针都需要初始化，导致下面在拼接的时候p->next直接异常，访问空指针 */
    ListNode *dummy = new ListNode(-1);                 
    ListNode *p = dummy;

    while (l1 != NULL && l2 != NULL) {
        if(l1->val <= l2->val){
            p->next = l1;
            l1 = l1->next;                                  /**<l1较小已经加入，则l1向下移动一位 */
        } else {
            p->next = l2;
            l2 = l2->next;
        }

        p = p->next;                                        /**<尾部拼接，要有一个指针始终指向末尾 */
    }

    p->next = (l1 != NULL) ? l1 : l2;

    ListNode* ans = dummy->next;                            /**<注意delete和返回的顺序，因此有一个临时变量 */
    delete dummy;   
    return ans;
}

int main(int argc, char *argv[])
{
    vector<int> s1 = {1, 2, 3, 4, 5};
    vector<int> s2 = {2, 2, 4, 7, 9};
    ListNode *list1 = creatList(s1);
    ListNode *list2 = creatList(s2);

    ListNode *list = mergeTwoLists(list1, list2);              /**<do some job */

    printList(list);
    return 0;
}