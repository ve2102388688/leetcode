#include <bits/stdc++.h>
#include "../order/mycommon.hpp"
using namespace std;

/** \brief      changeTwoNode 交换链表中的两个结点
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-3-2
 * 
 *  \param[in] head   输入数组
 *  \param[in] v1     输入v1
 *  \param[in] v2     输入v2
 *  \return           返回交换后的结点
 */
ListNode* changeTwoNode(ListNode* head, int v1, int v2) {
    if (head == nullptr || head->next == nullptr)
        return head;
    ListNode *dummy = new ListNode(INT_MIN, head);

    /**<两个结点的前驱、后继 */
    ListNode* v1Pre = dummy;
    ListNode* v2Pre = dummy;
    ListNode* v1Node = nullptr;
    ListNode* v2Node = nullptr;
    ListNode* v2Next = nullptr;
    ListNode* v1Next = nullptr;

    ListNode *p = head;
    for (; p != nullptr; p = p->next) {     /**<查找v1或者v2 */
        if(p->val == v1) {
            v1Node = p;
            v1Next = p->next;
            break;
        }
        if(p->val == v2) {
            v2Node = p;
            v2Next = p->next;
            break;
        }
        v1Pre = v1Pre->next;
        v2Pre = v2Pre->next;
    }

    if (v1Node != nullptr) {            /**<知道v1或者v2，寻找另外一个 */
        p = p->next;                    /**<这里需要移动一个 */
        v2Pre = v2Pre->next;
        for (; p != nullptr; p = p->next) {
            if(p->val == v2) {
                v2Node = p;
                v2Next = p->next;
                break;
            }
            v2Pre = v2Pre->next;
        }
    } else {
        p = p->next;                    /**<这里需要移动一个 */
        v1Pre = v1Pre->next;
        for (; p != nullptr; p = p->next) {
            if(p->val == v1) {
                v1Node = p;
                v1Next = p->next;
                break;
            }
            v1Pre = v1Pre->next;
        }
    }


    /**<需要都找到，否则不做处理 */
    if (v1Node != nullptr && v2Node != nullptr) {
        if(v1Node->next == v2Node) {
            v1Pre->next = v2Node;
            v2Node->next = v1Node;
            v1Node->next = v2Next;
        }else if(v2Node->next == v1Node){
            v2Pre->next = v1Node;
            v1Node->next = v2Node;
            v2Node->next = v1Next;
        } else {
            v1Pre->next = v2Node;
            v2Node->next = v1Next;
            
            v2Pre->next = v1Node;
            v1Node->next = v2Next;
        }
    }

    ListNode *temp = dummy->next;
    delete dummy;
    return temp;
}

int main(int argc, char *argv[])
{
    /**<创建链表 */
    vector<int> s = {1, 2};
    ListNode *list = creatList(s);

    ListNode *output = changeTwoNode(list, 2, 1);       /**<do some job */

    printList(output);
    std::cout << "\n";

    freeList(list);
    delete list;                            /**<删除链表 */
    return 0;
}