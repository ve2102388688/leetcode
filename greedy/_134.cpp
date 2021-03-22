#include <bits/stdc++.h>
using namespace std;


/** \brief      canCompleteCircuit 加油站 134
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-3-22
 * 
 *  \param[in] intervals   输入区间
 *  \return                无重叠区间
 */
int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int n = gas.size();
    int index = 0;                                  /**<从最低点出发，最有可能返回 */
    int indexMin = INT_MAX;
    int gasSpare = 0;
    
    for (int i = 0; i < n; ++i) {
        gasSpare += (gas[i] - cost[i]);
        if (gasSpare < indexMin) {
            indexMin = gasSpare;
            index = i;
        }
    }
    return gasSpare < 0 ? -1 : (index + 1) % n;     /**<gasSpare发现每一个站点剩余汽油量均小于0，无法返回 */
}

/**<暴力 */
int canCompleteCircuit2(vector<int>& gas, vector<int>& cost) {
    int n = gas.size();
    int start = 0;
    for (int i = 0; i < n; ++i) {
        int spare = 0;
        start = i;
        for (int j = 0; j <= n; ++j) {          /**<能否转回来，要循环n+1次 */
            int realPos = (start + j) % n;
            spare = spare + gas[realPos] - cost[realPos];   /**<能否达到下一站，上一次的余量加上本次加油减去消耗的汽油 */
            if(spare<0)
                break;
            if (j == n)
                return realPos;
        }
    }

    return -1;
}

int main(int argc, char *argv[])
{
    vector<int> gas = { 1, 2, 3, 4, 5 };
    vector<int> cost = {3, 4, 5, 1, 2};

    int output = canCompleteCircuit2(gas, cost);
    std::cout << output << '\n';

    return 0;
}