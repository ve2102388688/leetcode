#ifndef MYCOMMON_H_
#define MYCOMMON_H_
#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


/** \brief      creatList  创建链表
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-12
 * 
 *  \param[in] s 输入数组
 *  \return      返回链表
 */
ListNode* creatList(std::vector<int> s){
    ListNode *dummy = new ListNode(0);           /**<要保证正序，需要一个head来记住，创建完成后直接返回head->next*/
    ListNode *p = dummy;

    /**<正序创建链表 */
    for (int i = 0; i < s.size(); ++i){
        ListNode *t = new ListNode(s[i]);
        p->next = t;
        p = t;
    }
    p->next = NULL;

    ListNode* ans = dummy->next;                /**<注意delete和返回的顺序，因此有一个临时变量 */
    delete dummy;
    return ans;
}


/** \brief      printList  输出链表
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-12
 * 
 *  \param[in] head 输入链表
 *  \return         void
 */
void printList(ListNode* head){
    
    for (ListNode* p = head; p != NULL; p = p->next) 
        std::cout << p->val << " -> ";
}


/** \brief      printReverseList  反序输出链表
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-13
 *  \remark     使用递归
 * 
 *  \param[in] head 输入链表
 *  \return         void
 */
void printReverseList(ListNode* head){
    if(head == NULL)
        return;
    printReverseList(head->next);
    std::cout << head->val << " -> ";
}


/** \brief      reverseList  链表反序
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-12
 * 
 *  \param[in] head 输入链表
 *  \return         返回反序的链表
 */
ListNode* reverseList(ListNode* head) {
    ListNode *newhead = NULL;

    for(ListNode *p = head; p != NULL; ) {
        ListNode *temp = p->next;           /**<这里要临时转存下p->next,最后又恢复给p  */

        p->next = newhead;
        newhead = p;                        /**<反序头永远要在开头哦 */

        p = temp;
    }
    return newhead;
}


/** \brief      freeList  释放链表内存
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-13
 *  \remark     使用递归
 * 
 *  \param[in] head 输入链表
 *  \return         void
 */
void freeList(ListNode* head){
    if(head == NULL)
        return;
    freeList(head->next);
    delete head->next;
}

#endif