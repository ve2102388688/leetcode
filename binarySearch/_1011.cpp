#include <bits/stdc++.h>
using namespace std;

/** \brief      shipWithinDays  在D天内送达包裹的能力 1011
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-3-9
 * 
 *  \param[in] weights  输入数组
 *  \param[in] load     输入运载力
 *  \param[in] d        输入天数
 *  \return             能否运载完成
 */
bool canTransfer(vector<int>& weights, int load, int d) {
    int i = 0;
    for (int day = 0; day < d; ++day) {     /**<一共d天。每天一共load运送量*/
        int temp = load;
        while ((temp-=weights[i]) >= 0) {
            ++i;
            if (i == weights.size())
                return true;
        }
    }
    return false;
}

/** \brief      shipWithinDays  在D天内送达包裹的能力 1011
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-3-9
 * 
 *  \param[in] weights  输入数组
 *  \param[in] D        输入时间
 *  \return             最低运载能力
 */
int shipWithinDays(vector<int>& weights, int D) {
    int size = weights.size();
    int maxLoad = 0;
    int minLoad = 0;
    for (int i = 0; i < size; ++i) {
        maxLoad += weights[i];
        minLoad = (minLoad > weights[i]) ? minLoad : weights[i];
    }

    int low = minLoad, high = maxLoad;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (canTransfer(weights, mid, D))
            high = mid -1;
        else
            low = mid + 1;
    }
    return low;
}

int main(int argc, char *argv[])
{
    vector<int> nums1 = {1,2,3,4,5,6,7,8,9,10};
    int output = shipWithinDays(nums1, 5);
    cout << output << " ";

    cout << "\n";   
    return 0;
}