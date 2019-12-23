//
//  main.cpp
//  322-CoinChange
//
//  Created by zhoujian on 2019/12/22.
//  Copyright © 2019 zhoujian. All rights reserved.
//

#include <iostream>
#include "vector"
#include <algorithm>
using namespace std;

/*
 给定不同面额的硬币 coins 和一个总金额 amount。编写一个函数来计算可以凑成总金额所需的最少的硬币个数。如果没有任何一种硬币组合能组成总金额，返回 -1。
 
 示例 1:
 
 输入: coins = [1, 2, 5], amount = 11
 输出: 3
 解释: 11 = 5 + 5 + 1
 示例 2:
 
 输入: coins = [2], amount = 3
 输出: -1
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/coin-change
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 
 */

// 第一种解法：DP
int coinChange(vector<int>& coins, int amount) {
    if(coins.size() == 0) {
        return -1;
    }
    
    /*
     思路类似于斐波那契数列
     dp[i] 表示凑成金额i所需要的最小硬币数
     则状态转移方程为:dp[11] = min(dp[11-1], dp[11-2], dp[11-5]) + 1;
     */
    vector<int> dp(amount+1, amount+1);
    dp[0] = 0;
    for(int i = 1; i <= amount; i++) {
        for(int coin : coins) {
            if(coin <= i) {
                dp[i] = min(dp[i],dp[i-coin]+1);
            }
        }
    }
    return (dp[amount] == amount+1) ? -1 : dp[amount];
}

// 第二种解法：DPS+剪枝,速度比解法一快(超过了100%的cpp方法)
int res = INT_MAX;

void coinNumberHelper(vector<int>& coins, int currentRes, int amount, int index) {
    if(index < 0) {
        return;
    }
    if(amount%coins[index] == 0) {
        res = min(res, currentRes + amount/coins[index]);
        return;
    }

    // 这一步是剪枝操作：如果下面的结果比res还大，就没有必要进行下去了
    if(currentRes + amount/coins[index] + 1 >= res) {
        return;
    }

    for(int i = amount/coins[index]; i >= 0; i--) {
        coinNumberHelper(coins, currentRes+i, amount-coins[index]*i, index-1);
    }
}

int coinChange2(vector<int>& coins, int amount) {
    if(coins.size() == 0) {
        return -1;
    }
    
    // 排序后先取最大的硬币
    sort(coins.begin(), coins.end());
    
    coinNumberHelper(coins, 0, amount, (int)coins.size()-1);
    
    return res == INT_MAX ? -1 : res;
    
}

int main(int argc, const char * argv[]) {
    vector<int> coins = {1, 2, 5};
    int amount = 11;
    cout << coinChange2(coins, amount) << endl;
    return 0;
}
