#include <bits/stdc++.h>
using namespace std;


/** \brief      longestValidParentheses	最长有效括号 32
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-3-4
 * 
 *  \param[in] s  输入数组s
 *  \return       下一个更大的元素
 */
bool isvaild(string& s, int i, int j) {
    stack<char> sta;
    for (int k = i; k <= j; ++k) {
        if(s[k] == '(') sta.push(')');
        // else if(s[k] == '[') sta.push(']');
        // else if(s[k] == '{') sta.push('}');
        else if(!sta.empty() && s[k] == sta.top()) sta.pop();
        else
            return false;
    }
    return sta.empty();
}


int longestValidParentheses(string& s) {
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


int longestValidParentheses2(string& s) {
    int n = s.size();
    int maxLen = 0;
    stack<int> sta;
    sta.push(-1);

    for (int i = 0; i < n; ++i) {
        if(s[i] == '(') 
            sta.push(i);
        else {
            sta.pop();
            if (sta.empty())
                sta.push(i);
            else
                maxLen = max(maxLen, i - sta.top());
        }
    }
    return maxLen;
}


int main(int argc, char *argv[])
{
    string s = "(()";
    int output = longestValidParentheses2(s);
    cout << output << " ";
    cout << "\n";

    return 0;
}