#include <bits/stdc++.h>
#include "mycommon.hpp"
using namespace std;

/** \brief      getDecimalValue 两数相加 2
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-28
 * 
 *  \param[in] l1 输入链表1
 *  \param[in] l2 输入链表2
 *  \return       返回中间结点
 */
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *p1 = l1;
    ListNode *p2 = l2;
    int carry = 0;

    ListNode *dummy = new ListNode(0);
    ListNode *out = dummy;
    while (p1 != nullptr && p2 != nullptr) {
        int temp = carry + p1->val + p2->val;       /**<加法运算 */

        out->next = new ListNode(temp % 10);        
        carry = temp / 10;                          /**<进位 */

        p1 = p1->next;
        p2 = p2->next;
        out = out->next;
    }

    /**<处理剩下的内容 */
    while (p1 != nullptr) {
        int temp = carry + p1->val;
        
        out->next = new ListNode(temp % 10);
        carry = temp / 10;                          /**<进位 */

        p1 = p1->next;
        out = out->next;
    }
    while (p2 != nullptr) {
        int temp = carry + p2->val;
        
        out->next = new ListNode(temp % 10);
        carry = temp / 10;                          /**<进位 */

        p2 = p2->next;
        out = out->next;
    }

    /**<最后一个进位 */
    if(carry != 0)
        out->next = new ListNode(1, nullptr);
    else
        out->next = nullptr;
    
    ListNode *temp = dummy->next;
    delete dummy;
    return temp;
}

int main(int argc, char *argv[])
{
    /**<创建链表 */
    vector<int> s = {9,9,9,9,9,9,9};
    ListNode *list = creatList(s);
    vector<int> s2 = {9,9,9,9};
    ListNode *list2 = creatList(s2);

    ListNode *output = addTwoNumbers(list, list2);       /**<do some job */
    printList(output);
    std::cout << "\n";

    freeList(list);
    delete list;                            /**<删除链表 */
    freeList(list2);
    delete list2;                            /**<删除链表 */
    freeList(output);
    delete output;                            /**<删除链表 */
    return 0;
}