//
//  main.cpp
//  121-123-买卖股票
//
//  Created by zhoujian on 2019/12/9.
//  Copyright © 2019 zhoujian. All rights reserved.
//

#include <iostream>
#include "vector"
using namespace std;

/*
 大牛题解：
 https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/solution/yi-ge-fang-fa-tuan-mie-6-dao-gu-piao-wen-ti-by-l-3/
 */
#pragma mark - 最多只允许完成一笔交易（即买入和卖出一支股票）

int maxProfitI_Solution1(vector<int>& prices) {
    if(prices.size() < 2) {
        return 0;
    }
    int res = 0;
    int minPrice = prices[0];
    for(int i = 1; i < prices.size(); i++) {
        minPrice = min(minPrice, prices[i-1]);
        res = max(res, prices[i] - minPrice);
    }
    return res;
}

int maxProfitI_Solution2(vector<int>& prices) {
    if(prices.size() < 2) {
        return 0;
    }
    /*
     dp[i][0] 表示第i天没持有股票的最大利润
     dp[i][1] 表示第i天持有股票的最大利润
     很明显，这题就是求dp[length-1][0]的值
     
     dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i])
     我今天没有持有股票，有两种可能：
     1.我昨天就没有持有
     2.我昨天持有，今天卖掉了，变成了没有持有
     
     dp[i][1] = max(dp[i-1][1], -prices[i])
     我今天持有股票，有两种可能
     1.我昨天就持有
     2.我昨天没有持有，今天买入了
     
     */
    vector<vector<int>> dp(prices.size(), vector<int>(2));
    dp[0][0] = 0;
    dp[0][1] = -prices[0];
    for(int i = 1; i < prices.size(); i++) {
        dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]);
        dp[i][1] = max(dp[i-1][1], -prices[i]); // 买入，只能进行一次操作，所以为 -prices[i]
    }
    return dp[prices.size()-1][0];
}

// 由maxProfitI_Solution2演变而来，新状态只和相邻的一个状态有关
int maxProfitI_Solution3(vector<int>& prices) {
    if(prices.size() < 2) {
        return 0;
    }
    
    int dp_i_0 = 0;
    int dp_i_1 = -prices[0];
    for(int i = 1; i < prices.size(); i++) {
        dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]); // 卖出
        dp_i_1 = max(dp_i_1, -prices[i]); // 买入，只能进行一次操作，所以为 -prices[i]
    }
    return dp_i_0;
}

#pragma mark - 你可以尽可能地完成更多的交易（多次买卖一支股票）

// 贪心算法：遍历整个股票交易日价格列表 price，策略是所有上涨交易日都买卖（赚到所有利润），所有下降交易日都不买卖（永不亏钱）。
int maxProfitII_Solution1(vector<int>& prices) {
    if(prices.size() < 2) {
        return 0;
    }
    int res = 0;
    for(int i = 1; i < prices.size(); i++) {
        
        int profit = prices[i] - prices[i - 1];
        if(profit > 0) {
            res += profit;
        }
    }
    return res;
}

// 动态规划
int maxProfitII_Solution2(vector<int>& prices) {
    if(prices.size() < 2) {
        return 0;
    }
    vector<vector<int>> dp(prices.size(), vector<int>(2));
    dp[0][0] = 0;
    dp[0][1] = -prices[0];
    for(int i = 1; i < prices.size(); i++) {
        dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]);
        dp[i][1] = max(dp[i-1][1], dp[i-1][0]-prices[i]);
    }
    return dp[prices.size()-1][0];
}

// 由maxProfitII_Solution2演变而来
int maxProfitII_Solution3(vector<int>& prices) {
    if(prices.size() < 2) {
        return 0;
    }
    int dp_i_0 = 0;
    int dp_i_1 = -prices[0];
    for(int i = 1; i < prices.size(); i++) {
        int temp = dp_i_0;
        dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);
        dp_i_1 = max(dp_i_1, temp-prices[i]);
    }
    return dp_i_0;
}

#pragma mark - 你最多可以完成 两笔 交易。

int maxProfitIII_Solution1(vector<int>& prices) {
    
    if(prices.size() < 2) {
        return 0;
    }
    int max_k = 2;
    vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(max_k+1, vector<int>(2)));
    
    dp[0][2][0] = 0;
    dp[0][2][1] = -prices[0];
    
    dp[0][1][0] = 0;
    dp[0][1][1] = -prices[0];
    
    for(int i = 1; i < prices.size(); i++) {
        for(int k = max_k; k >= 1; k--) {
            
            dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i]);
            dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i]);
        }
    }
    return dp[prices.size()-1][max_k][0];
    
    
}

//    设dp(i) = 区间[0,1,2...i]的最大利润 + 区间[i,i+1,....n-1]的最大利润,那么本题的最大利润 = max{dp[0],dp[1],dp[2],...,dp[n-1]}.
int maxProfitIII_Solution2(vector<int>& prices) {
    if(prices.size() < 2) {
        return 0;
    }
    vector<int> profits;
    profits.push_back(0);
    
    int profit = 0;
    int minPrice = prices[0];
    for(int i = 1; i < prices.size(); i++) {
        minPrice = min(minPrice, prices[i-1]);
        profit = max(profit, prices[i] - minPrice);
        profits.push_back(profit);
    }
    
    int res = 0;
    profit = 0;
    int maxPrice = prices[prices.size()-1];
    for(int i = (int)prices.size()-2; i >= 0; i--) {
        maxPrice = max(maxPrice, prices[i+1]);
        profit = max(profit, maxPrice-prices[i]);
        res = max(res, profit+profits[i]);
    }
    
    return res;
}

#pragma mark - 含冷冻期:卖出股票后，你无法在第二天买入股票;可多次交易

int maxProfitIV_Solution1(vector<int>& prices) {
    if(prices.size() < 2) {
        return 0;
    }
    
    vector<vector<int>> dp(prices.size(), vector<int>(3));
    dp[0][0] = 0; // 不持股
    dp[0][1] = -prices[0];// 持股
    dp[0][2] = 0; // 冷冻期
    
    for(int i = 1; i < prices.size(); i++) {
        dp[i][0] = max(dp[i-1][0],dp[i-1][2]);
        dp[i][1] = max(dp[i-1][1],dp[i-1][0]-prices[i]);
        dp[i][2] = dp[i-1][1]+prices[i];
        
    }
    return max(dp[prices.size()-1][0], dp[prices.size()-1][2]);
    
//# dp[i][0] 第i天，不持有股票时的最大利润
//# dp[i][1] 第i天，持有股票时的最大利润
//
//    dp[0][0] = 0
//    dp[0][1] = 0 - prices[0]
//
//    dp[1][0] = max(0, prices[1] - prices[0])
//    dp[1][1] = max(dp[0][1], 0-prices[1])
//
//    for i in range(2, n):
//        dp[i][0] = max(dp[i-1][0], dp[i-1][1]+prices[i])
//        dp[i][1] = max(dp[i-1][1], dp[i-2][0]-prices[i])
//
//# print(dp)
//
//        return dp[-1][0]
}

int main(int argc, const char * argv[]) {
    vector<int> prices = {1,2,3,0,2};
//    vector<int> prices = {1,2,3,4,5};
    int res = maxProfitIV_Solution1(prices);
    cout << res << endl;
    return 0;
}

