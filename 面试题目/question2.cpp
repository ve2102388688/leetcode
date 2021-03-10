#include <bits/stdc++.h>
#include "../order/mycommon.hpp"
using namespace std;



/** \brief      changeTwoNode 最长的合法括号长度
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-3-4
 *  \remark     最长回文子串
 * 
 *  \param[in] nums   输入数组
 *  \return           最小值
 */
bool isvaild(string& s, int i, int j) {
    stack<char> sta;
    for (int k = i; k <= j; ++k) {
        if(s[k] == '(') sta.push(')');
        else if(s[k] == '[') sta.push(']');
        else if(s[k] == '{') sta.push('}');
        else if(!sta.empty() && s[k] == sta.top()) sta.pop();
        else
            return false;
    }
    return sta.empty();
}

int longestLegalLength(string& s) {
    int n = s.size();
    int maxLen = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            if (isvaild(s, i, j)) {
                maxLen = max(maxLen, j + 1 - i);
            }
        }
    }
    return maxLen;
}

int main(int argc, char *argv[])
{
    string s = "({({(({()}})}{())})})[){{{([)()((()]]}])[{)]}{[}{)";

    int output = longestLegalLength(s);       /**<do some job */
    std::cout << output << "\n";

    return 0;
}