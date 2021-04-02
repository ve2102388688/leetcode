#include <bits/stdc++.h>
using namespace std;

/** \brief      convert Z字形变换 6
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-3-28
 * 
 *  \param[in] s        输入字符串
 *  \param[in] numRows  输入行数
 *  \return             返回Z字变换后的顺序
 */
string convert(string& s, int numRows) {
    if (numRows < 2)                                /**《行数小于2，直接返回 */     
        return s;
    
    vector<string> line(numRows);
    int flag = -1;                                              /**<转折点 */
    int i = 0;                                                  /**<数组个数 */
    for (const auto &e : s) {
        line[i].push_back(e);                                   /**<存放的数组在不停的循环 */
        if (i == 0 || i == numRows-1)   flag = -flag;           /**<转折点 */
        i += flag;
    }

    string res;                                                 /**<把数组串在一起 */
    for (const auto &e : line)
        res += e;
    return res;
}


int main(int argc, char *argv[])
{
    string s = "PAYPALISHIRING";
    string output = convert(s, 3);
    cout << output << "\n";


    return 0;
}