#include <bits/stdc++.h>
using namespace std;

/** \brief      firstBadVersion 第一个错误的版本 278
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-2-28
 * 
 *  \param[in] n   输入n
 *  \return        查找的下标
 */
int firstBadVersion(int n) {
    int low = 1, high = n;
    while (low <= high) {                   /**<注意：这里要有等于，因为出while，必定是low>high */
        int mid = low + (high - low) / 2;
        if(isBadVersion(mid) == false)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;                             /**<返回low */
}

int main(int argc, char *argv[])
{
    int output = firstBadVersion(nums1, 100);
    cout << output << " ";

    cout << "\n";

    return 0;
}