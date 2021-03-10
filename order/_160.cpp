#include <bits/stdc++.h>
#include "mycommon.hpp"
using namespace std;

/** \brief      getIntersectionNode 相交链表 160 
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-28
 * 
 *  \param[in] head 输入链表
 *  \return         返回删除排序链表中的重复元素
 */
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if(headA == nullptr || headB == nullptr)
        return nullptr;

    ListNode *pa = headA;
    ListNode *pb = headB;                           /**<pa和pb走了相同的路程 */
    while (pa != pb) {
        pa = (pa == nullptr) ? headB : pa->next;
        pb = (pb == nullptr) ? headA : pb->next;
    }

    return pa;
}

int main(int argc, char *argv[])
{
    return 0;
}