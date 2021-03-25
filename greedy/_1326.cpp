#include <bits/stdc++.h>
using namespace std;


/** \brief      canPlaceFlowers 种花问题 605
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-3-23
 * 
 *  \param[in] flowerbed  花坛
 *  \param[in] N          种花数目
 *  \return               能否种花
 */
// int minTaps(int n, vector<int>& ranges) {
//     vector<int> land(n);

//     for (int i = 0; i <= n; ++i) {
//         int l = max(i-ranges[i], 0);
//         int r = min(i+ranges[i], n);
//         for (int j = l; j < r; ++j)
//             land[j] = max(land[j], r);
//     }

//     int cur = 0;
//     int cnt = 0;
//     while (cur < n) {
//         if (land[cur] == 0)
//             return -1;
//         cur = land[cur];
//         ++cnt;
//     }
//     return cnt;
// }


int minTaps(int n, vector<int>& ranges) {
    int INF = 0x3f3f3f3f;
    vector<int> f(n + 1, INF);
    f[0] = 0;
    for(int i = 0; i <= n; i++) {
        int l = max(0, i - ranges[i]), r = min(n, i + ranges[i]);
        for(int j = l; j < r; j++)
            f[r] = min(f[r], f[j] + 1);
    }
    return f[n] == INF ? -1 : f[n];
}

int main(int argc, char *argv[])
{
    vector<int> nums = {3,4,1,0,0};

    int output = minTaps(5, nums);
    std::cout << output << '\n';

    return 0;
}