#include <bits/stdc++.h>
using namespace std;


/** \brief      removeKdigits 移掉K位数字 402
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-3-16
 * 
 *  \param[in] g   输入胃口
 *  \param[in] s   输入饼重量
 *  \return        最多能满足孩子的数量
 */
string removeKdigits(string& num, int k) {
    /**<单调递增栈 */
    vector<char> sta;
    for (const auto& e : num) {
        while (!sta.empty() && sta.back()>e && k) {
            sta.pop_back();
            --k;
        }
        sta.push_back(e);
    }

    // 如果我们删除了m个数字且m<k，这种情况下我们需要从序列尾部删除额外的k-m个数字
    while (k--)
        sta.pop_back();

    string res;
    int n = sta.size();
    bool isLeadingZero = true;                  /**<删除前导0 */
    for (int i = 0; i < n; ++i) {
        if (isLeadingZero && sta[i]=='0')
            continue;
        isLeadingZero = false;
        res += sta[i];
    }

    return res.empty() ? "0": res;
}

int main(int argc, char *argv[])
{
    string s = "10";
    string output = removeKdigits(s, 1);
    cout << output << " ";

    cout << "\n";
    return 0;
}