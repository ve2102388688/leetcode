#include <bits/stdc++.h>
#include "mycommon.hpp"
using namespace std;

/** \brief      deleteNode  删除链表中的节点 237
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-12
 * 
 *  \param[in] s 输入字符串
 *  \return      返回最长回文子串
 */
void deleteNode(ListNode* node) {
    node->val = node->next->val;
    ListNode *temp = node->next->next;
    delete node->next;                  /**<释放内存 */
    node->next = temp;
}

int main(int argc, char *argv[])
{
    /**<创建链表 */
    vector<int> s = {1,2,3};
    ListNode *list = creatList(s);

    deleteNode(list->next);       /**<do some job */

    printList(list);
    std::cout << "\n";

     /**<删除链表 */
    freeList(list);
    delete list;                           
    return 0;
}