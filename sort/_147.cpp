#include <bits/stdc++.h>
#include "../order/mycommon.hpp"
using namespace std;

/** \brief      insertionSortList 对链表进行插入排序 147
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-3-11
 * 
 *  \param[in] head  dummy结点
 *  \return          返回插入点
 */
ListNode* findInsertPos(ListNode* head, int val) {
    if (head->next->val > val)
        return head;
    ListNode *pre = head;
    for (ListNode *p = head->next; p != nullptr; p = p->next){
        if (p->val > val)
            return pre;
        pre = pre->next;
    }
}


ListNode* insertionSortList(ListNode* head) {
    if (head == nullptr || head->next == nullptr)
        return head;
    
    ListNode *dummy = new ListNode(INT_MIN, head);
    ListNode *pre = dummy;

    for (ListNode *p = head; p != nullptr;) {
        if (p->next != nullptr && p->val>p->next->val) {
            /**<找到插入点 */
            // pre = pre->next;
            // p = p->next;
            ListNode *pos = head;
            ListNode *posPre = dummy;
            for (; pos!=nullptr; pos=pos->next) {
                if(pos->val > p->next->val)
                    break;
                posPre = posPre->next;
            }

            ListNode *pNext = p->next;
            posPre->next = p;
            p->next = pos;
            pre->next = pNext;

        } else {
            pre = pre->next;
            p = p->next;
        }
    }

    ListNode *temp = dummy->next;
    delete dummy;
    return temp;
}



int main(int argc, char *argv[])
{
    vector<int> nums = {-2,5,3,4,0};
    // vector<int> nums = {1,2,3,4,5};
    ListNode *list = creatList(nums);

    ListNode *output = insertionSortList(list);
    printList(output);

    std::cout  << '\n';
    return 0;
}