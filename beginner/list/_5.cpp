#include <bits/stdc++.h>
#include "mycommon.hpp"
using namespace std;

/** \brief      isPalindrome  回文链表
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-13
 *  \remark     后半截链表内存泄漏，
 * 
 *  \param[in] head 输入链表
 *  \return         返回是否是回文链表
 */
bool isPalindrome(ListNode* head) {
    /**<STEP1 寻找链表的中点，若为奇数则是中间偏右(slow) */
    /**<fast指针每次走两步，slow每次走一步 */
    ListNode *fast = head;
    ListNode *slow = head;
    while (fast != NULL && fast->next != NULL) {    /**<手动画下元素只有3，4的情况*/
        fast = fast->next->next;
        slow = slow->next;
    }

    /**<STEP2 后半部分反转 */
    ListNode *secondHalfHead = NULL;
    ListNode *connect = slow;
    while (slow != NULL) {
        ListNode *temp = slow->next;            /**<这里要临时转存下p->next,最后又恢复给p  */

        slow->next = secondHalfHead;
        secondHalfHead = slow;

        slow = temp;
    }
    
    /**<STEP3 比较，如果是奇数，由于slow取得中间偏右，回文中间那个不会考虑哦 */
    ListNode *p = head;
    ListNode *q = secondHalfHead;
    while (p != NULL) {
        if(p->val != q->val)
            return false;
        p = p->next;
        q = q->next;
    }

    return true;
}

/** \brief      isPalindrome2  回文链表
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-14
 *  \remark     递归方式求解--后序遍历也就是倒序
 * 
 *  \param[in] head 输入链表
 *  \return         返回是否是回文链表
 */
ListNode *myLeft = NULL;                    /**<left和库名重复，所有取了新名字 */
bool traverse(ListNode *right){
    if(right == NULL)    return true;        /**<相当于初始条件，假定初始为真 */
    bool res = traverse(right->next);

    res = (res && right->val == myLeft->val);
    myLeft = myLeft->next;                  /**<右移动一个即可 */
    return res; 
}

bool isPalindrome2(ListNode* head) {
    myLeft = head;                          /**<左边指针往右走 */
    return traverse(head);
}

int main(int argc, char *argv[])
{
    /**<创建链表 */
    vector<int> s = {1,2,3,2,1};
    ListNode *list = creatList(s);

    bool output = isPalindrome(list);              /**<do some job */
    // bool output = isPalindrome2(list);              /**<do some job */
    std::cout << output << std::endl;
    
    freeList(list);
    delete list;                            /**<删除链表 */
    return 0;
}