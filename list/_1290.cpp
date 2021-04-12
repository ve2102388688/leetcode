#include <bits/stdc++.h>
#include "mycommon.hpp"
using namespace std;

/** \brief      getDecimalValue  二进制链表转整数 1290
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-28
 * 
 *  \param[in] head 输入链表
 *  \return         返回整数
 */
// int getDecimalValue(ListNode *head) {
//     if(head == nullptr)
//         return 0;

//     vector<int> weight;
//     for (ListNode *p = head; p != nullptr; p = p->next) {
//         for(auto& e : weight) 
//             e <<= 1;
//         if(p->val == 1)
//             weight.push_back(1);
//     }

//     int num = 0;
//     for(const auto& e : weight)
//         num += e;
//     return num;
// }

int getDecimalValue(ListNode* head) {
    ListNode* cur = head;
    int ans = 0;
    while (cur != nullptr) {
        ans = ans * 2 + cur->val;
        cur = cur->next;
    }
    return ans;
}


int main(int argc, char *argv[])
{
    /**<创建链表 */
    vector<int> s = {1,0,0,1,0,0,1,1,1,0,0,0,0,0,0};
    ListNode *list = creatList(s);

    int output = getDecimalValue(list);       /**<do some job */
    std::cout << output << "\n";

    freeList(list);                         /**<删除链表 */
    return 0;
}