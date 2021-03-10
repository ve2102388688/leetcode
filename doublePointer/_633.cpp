#include <bits/stdc++.h>
using namespace std;

/** \brief      judgeSquareSum 平方数之和 633
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-2-24
 * 
 *  \param[in] c   输入非负整数
 *  \return        是否存在平方和
 */
bool judgeSquareSum(int c) {
    int low = 0;
    int high = sqrt(c);
    while (low <= high) {
        int square1 = low * low;
        int square2 = high * high;
        if (square1 == c-square2) return true;
        if (square1 < c-square2) 
            ++low;
        else
            --high;
    }
    return false;
}

int main(int argc, char *argv[])
{
    bool output = judgeSquareSum(2147482647);
    cout << output << " ";

    cout << "\n";

    return 0;
}