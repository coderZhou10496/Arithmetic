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

int main(int argc, const char * argv[]) {
    vector<int> prices = {1,2,3,4,5};
    int res = maxProfitIII_Solution1(prices);
    int res2 = maxProfitIII_Solution2(prices);
    cout << res << res2 << endl;
    return 0;
}

