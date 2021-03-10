#include <bits/stdc++.h>
using namespace std;


/** \brief      removeDuplicates 删除字符串中的所有相邻重复项 1047
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2021-3-9
 * 
 *  \param[in] string  字符串
 *  \return            删除所有相同项
 */
string removeDuplicates(string& S) {
    stack<char> sta;
    int n = S.size();
    for (int i = n-1; i>=0; --i) {                  /**<倒着遍历，因为栈会会让顺序颠倒 */
        if (!sta.empty() && sta.top() == S[i]) {    /**<栈不空，和栈顶元素相同直接弹出 */
            sta.pop();
        } else {
            sta.push(S[i]);
        }
    }
    string res;
    while (!sta.empty()){
        res += sta.top();
        sta.pop();
    }
    return res;
}

int main(int argc, char *argv[])
{
    string s = "abbaca";
    string output = removeDuplicates(s);
    cout << output << " ";
    
    cout << "\n";
    return 0;
}