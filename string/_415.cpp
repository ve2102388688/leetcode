#include <bits/stdc++.h>
using namespace std;

/** \brief      addStrings 字符串相加 415
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-3-31
 * 
 *  \param[in] s        输入字符串
 *  \param[in] numRows  输入行数
 *  \return             返回Z字变换后的顺序
 */
string addStrings(string& num1, string& num2) {
    int i = num1.size()-1;
    int j = num2.size()-1;

    string res;
    int carry = 0;
    while (i >= 0 && j >= 0) {
        int temp = carry + num1[i--]-'0' + num2[j--] -'0';
        carry = temp / 10;
        res.push_back('0'+temp % 10);
    }
    while (i >= 0) {
        int temp = carry + num1[i--]-'0';
        carry = temp / 10;
        res.push_back('0'+temp % 10);
    }
    while (j >= 0) {
        int temp = carry + num2[j--]-'0';
        carry = temp / 10;
        res.push_back('0'+temp % 10);
    }
    if (carry == 1)
        res.push_back('1');
    reverse(res.begin(), res.end());
    return res;
}

int main(int argc, char *argv[])
{
    string s = "123456789";
    string s2 = "99999999999";
    string output = addStrings(s, s2);
    cout << output << "\n";


    return 0;
}