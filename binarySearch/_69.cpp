#include <bits/stdc++.h>
using namespace std;

/** \brief      mySqrt x的平方根 69
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-2-28
 * 
 *  \param[in] nums   输入数组
 *  \param[in] target 输入目标
 *  \return           查找的下标
 */
int mySqrt(int x) {
    int low = 0, high = x;
    while (low <= high) {
        int mid = low + (high - low) / 2;       /**<每次都获取中间 */
        int temp = mid * mid;
        if (temp == x)
            return mid;
        else if(temp < x)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return high;
}

int main(int argc, char *argv[])
{
    int output = mySqrt(6);
    cout << output << " ";

    cout << "\n";

    return 0;
}