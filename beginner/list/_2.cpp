#include <bits/stdc++.h>
#include "mycommon.hpp"
using namespace std;

/** \brief      removeNthFromEnd  删除链表的倒数第N个节点
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-12
 * 
 *  \param[in] head 输入链表
 *  \param[in] n    第N个节点
 *  \return         返回删除倒数第N个节点后的链表
 */
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode *dummy = new ListNode(0, head);                /**<创建一个临时头，主要是本来就一个元素删除后就没了 */
    ListNode *preN = dummy;
    int i = 1;                                              /**<表示第一个节点，注意没有第0个说法 */
    for (ListNode* p = head; p != NULL; p=p->next) {
        if(i++ > n)
            preN = preN->next;
    }

    ListNode *temp = preN->next->next;
    delete preN->next;                                      /**>删除后继 */
    preN->next = temp;                                      /**<由于我们是从头开始走的，因此preN是目标元素的前驱 */

    ListNode *ans = dummy->next;                            /**<注意delete和返回的顺序，因此有一个临时变量 */
    delete dummy;   
    return ans;
}

int main(int argc, char *argv[])
{
    /**<创建链表 */
    vector<int> s = {1,2,3,4,5,6};
    ListNode *list = creatList(s);

    list = removeNthFromEnd(list, 4);       /**<do some job */

    printList(list);
    std::cout << "\n";

     /**<删除链表 */
    freeList(list);
    delete list;                           
    return 0;
}