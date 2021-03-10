#include <bits/stdc++.h>
#include "mycommon.hpp"
using namespace std;

/** \brief      hasCycle  环形链表
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-13
 * 
 *  \param[in] head 输入链表
 *  \return         返回是否有环
 */
bool hasCycle(ListNode *head) {
    ListNode *fast = head;
    ListNode *slow = head;
    while (fast != NULL && fast->next != NULL) {        /**<手动画下元素只有3，4的情况*/
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow)                                /**<快慢指针走了之后才判断哈 */
            return true;
    }
    return false;
}

int main(int argc, char *argv[])
{
    /**<创建链表 */
    vector<int> s = {1,2};
    ListNode *list = creatList(s);

    bool output = hasCycle(list);              /**<do some job */
    std::cout << output << std::endl;

    return 0;
}