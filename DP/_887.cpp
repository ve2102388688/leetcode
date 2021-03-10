#include <bits/stdc++.h>
using namespace std;

/** \brief      superEggDrop 鸡蛋掉落 887
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-2-8
 *  \remark     超时，时间复杂度O(k*n^2)，如(5, 5000)
 * 
 *  \param[in] K 输入鸡蛋个数
 *  \param[in] N 输入楼层高度
 *  \return      返回你确定F的值的最小移动次数是多少？
 */
int superEggDrop(int K, int N) {
    vector<vector<int>> dp(K+1, vector<int>(N+1, 0));

    /**<K=1,最坏的情况就是对应的楼层 */
    for (int i = 1; i <= N; ++i)
        dp[1][i] = i;


    for(int k = 2; k <= K; ++k) { 
        for (int n = 1; n <= N; ++n) {
            int res = INT_MAX;
            for (int i = 1; i <= n; ++i)                                /**<每次线性遍历，得到最小值 */
                res = min(res, max(dp[k][n - i], dp[k - 1][i - 1]) + 1);
            dp[k][n] = res;
        }
    }
    return dp[K][N];
}


/** \brief      superEggDrop 鸡蛋掉落 887
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-2-8
 * 
 *  \param[in] K 输入鸡蛋个数
 *  \param[in] N 输入楼层高度
 *  \return      返回你确定F的值的最小移动次数是多少？
 */
int superEggDrop2(int K, int N) {
    vector<vector<int>> dp(K+1, vector<int>(N+1, 0));

    /**<K=1,最坏的情况就是对应的楼层 */
    for (int i = 1; i <= N; ++i)
        dp[1][i] = i;


    for(int k = 2; k <= K; ++k) {
        for (int n = 1; n <= N; ++n) {
            int res = INT_MAX;
            /**<二分查找 */
            int low = 1, high = n;
            while (low <= high) {
                int mid = (high + low) / 2;
                int not_broken = dp[k][n - mid];                /**<没碎，上面搜索 */
                int broken = dp[k - 1][mid - 1];                /**<碎，下面搜索 */
                if (broken > not_broken) {
                    high = mid - 1;
                    res = min(res, broken) + 1;
                } else if(broken < not_broken){
                    low = mid + 1;
                    res = min(res, not_broken) + 1;
                } else {                                        /**<找到最低点 */
                    res = min(res, not_broken) + 1;
                    break;
                }
            }
            dp[k][n] = res;
        }
    }
    return dp[K][N];
}


/** \brief      superEggDrop 鸡蛋掉落 887
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-2-8
 * 
 *  \param[in] K 输入鸡蛋个数
 *  \param[in] N 输入楼层高度
 *  \return      返回你确定F的值的最小移动次数是多少？
 */
int superEggDrop3(int K, int N) {
    vector<vector<int>> dp(K+1, vector<int>(N+1, 0));
    
    int m = 0;
    while (dp[K][m]<N) {
        ++m;
        for (int k = 1; k <= K; ++k)
            dp[k][m] = dp[k][m - 1] + dp[k - 1][m - 1] + 1;
    }
    return m;
}


int superEggDrop4(int K, int N) {
    vector<vector<int>> dp(K+1, vector<int>(N+1, 0));
    
    int low = 1, high = N;
    while (low < high) {
        int mid = (high + low) / 2;
        if (dp[K][mid] < N) {
            low = mid + 1;
        }else if (dp[K][mid] > N) {
            high = mid - 1;
        }

        for (int k = 1; k <= K; ++k)
            dp[k][mid] = dp[k][mid - 1] + dp[k - 1][mid - 1] + 1;
    }
    return low;
}

int main(int argc, char *argv[])
{
    int output = superEggDrop4(5, 5000);
    std::cout << output << std::endl;

    return 0;
}