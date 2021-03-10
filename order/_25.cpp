#include <bits/stdc++.h>
#include "mycommon.hpp"
using namespace std;

/** \brief      reverse  链表反序，区间[a,b)
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-15
 *  \remark     递归方式
 * 
 *  \param[in] a 左闭
 *  \param[in] b 右开
 *  \return      返回[a,b)反序链表
 */
ListNode* reverse(ListNode* a, ListNode* b) {
    ListNode *newHead = NULL;

    for (ListNode *p = a; p != b; ) {
        ListNode *temp = p->next;           /**<这里要临时转存下p->next,最后又恢复给p  */

        p->next = newHead;
        newHead = p;                        /**<反序头永远要在开头哦 */

        p = temp;
    }

    return newHead;
}

/** \brief      reverseKGroup  K个一组翻转链表
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-15
 *  \remark     递归方式
 * 
 *  \param[in] head 输入链表
 *  \param[in] k    N个一组
 *  \return         返回反序的链表
 */
ListNode* reverseKGroup(ListNode* head, int k) {
    if(head == NULL)    return head;
    /**<注意区间[a,b)中有k个元素,其实b已经是k+1个元素了 */
    ListNode *a = head;
    ListNode *b = head;
    for (int i = 0; i < k; ++i) {
        if(b == NULL)   return head;
        b = b->next;
    }

    /**<STEP1 反转k个元素 */
    ListNode *newHead = reverse(a, b);
    /**<STEP2 反转下一组k个元素并连接 */
    a->next = reverseKGroup(b, k);

    return newHead;
}

int main(int argc, char *argv[])
{
    /**<创建链表 */
    vector<int> s = {1,2,3,4,5};
    ListNode *list = creatList(s);

    ListNode *output = reverseKGroup(list, 1);              /**<do some job */
    printList(output);

    return 0;
}