#include <bits/stdc++.h>
#include "mycommon.hpp"
using namespace std;

// /** \brief      detectCycle  反转链表II 92
//  *  \author     wzk
//  *  \copyright  GNU Public License
//  *  \version    1.0 
//  *  \date       2020-1-14
//  * 
//  *  \param[in] head 输入链表
//  *  \param[in] m    起点
//  *  \param[in] n    终点
//  *  \return         返回反转后的链表
//  */
// ListNode* reverseBetween(ListNode* head, int m, int n) {
//     /**区间反转，要先记住m的前面mthPre，第n个点nth*/
//     ListNode *p = head;
//     ListNode *mthPre = head;
//     for (int i = 1; i < m; ++i){                 /**<链表都是从1开始的 */
//         mthPre = p;
//         p = p->next;
//     }

//     /**<链表反转代码。简要修改，将工作指针p放置开头 */
//     ListNode *nth = p;
//     ListNode *newHead = NULL;
//     for (int i = 0; i < n-m+1; ++i) {
//         ListNode *temp = p->next;               /**<这里要临时转存下p->next,最后又恢复给p  */

//         p->next = newHead;
//         newHead = p;

//         p = temp;
//     }

//     /**<区间反转后，和两边的相连接 */
//     if(m == 1)
//         head = newHead;                         /**<由于第一个点的前驱不存在，即1thPre不存在，直接赋值即可 */
//     else
//         mthPre->next = newHead;

//     nth->next = p;                              /**<由于反转链表代码中的p其实是一个逾后位置，就是nth的后面 */

//     return head;
// }


/** \brief      reverseList  链表反序前N个
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-15
 *  \remark     递归方式
 * 
 *  \param[in] head 输入链表
 *  \param[in] n    前N个反序
 *  \return         返回反序的链表
 */
ListNode *mySuccessor = NULL;
ListNode* reverseListN(ListNode* head, int n) {
    if(n == 1){                                 /**<只有一个元素时直接返回本身即可，这是需要记住它的next */
        mySuccessor = head->next;
        return head;
    }
    ListNode *last = reverseListN(head->next, n-1);
    head->next->next = head;
    head->next = mySuccessor;                     /**<将之前记住的恢复出来 */

    return last;
}


/** \brief      reverseList  链表反序前N个
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-15
 *  \remark     递归方式
 * 
 *  \param[in] head 输入链表
 *  \param[in] n    前N个反序
 *  \return         返回反序的链表
 */
ListNode *successor = NULL;
ListNode* reverseBetween(ListNode* head, int m, int n) {
    if(m == 1)
        return reverseListN(head, n);                       /**<m=1,相当于反转前面N个*/
    
    /**<这里的head在不断靠近m位置，直到head->next是m，*/
    /**<这类一个很重要的问题？反转区间链表，其他区间不变，对吧？这里的递归就是不断前进到需要反序的区间进行反序，之后在原路返回 */
    /**<其实它什么都没干,只干了反序，也就是m==1 */
    head->next = reverseBetween(head->next, m - 1, n - 1);
    return head;
}

int main(int argc, char *argv[])
{
    /**<创建链表 */
    vector<int> s = {1,2,3,4,5};
    ListNode *list = creatList(s);

    list = reverseBetween(list, 3, 4);              /**<do some job */
    // list = reverseListN(list, 5);              /**<do some job */
    printList(list);

    return 0;
}