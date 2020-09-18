//
//  main.cpp
//  518-CoinChangII
//
//  Created by zhoujian on 2020/4/12.
//  Copyright © 2020 zhoujian. All rights reserved.
//

#include <iostream>
#include "vector"
using namespace std;

int change(int amount, vector<int>& coins) {
    
    /*
     dp[i][j] 表示使用前i种硬币，凑成金额j的方法总数
     
     方程：dp[i][j] = dp[i-1][j] + dp[i][j - coin[i-1]];
     
     dp[i-1][j]：没有用第i-1个硬币就凑齐了
     dp[i][j - coin[i-1]]：前面已经凑齐了部分金额，就差第i-1个就凑齐了
     */
    vector<vector<int>> dp(coins.size()+1, vector<int>(amount+1, 0));
    for (int i = 0; i <= coins.size(); i++) {
        dp[i][0] = 1;
    }
        
    for (int i = 1; i <= coins.size(); i++) {
        for (int j = 1; j <= amount; j++) {
            if (j - coins[i-1] >= 0) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i-1]];
            }
            else {
                dp[i][j] = dp[i - 1][j];
            }
            cout << dp[i][j] << endl;
        }
        
    }
    return dp[coins.size()][amount];

}
int change_sloution2(int amount, vector<int>& coins) {

    vector<int> dp(amount+1, 0);
    dp[0] = 1;
    
    for (int i = 0; i < coins.size(); i++) {
        for(int j = 1; j <= amount; j++) {
            if (j - coins[i] >= 0) {
                dp[j] = dp[j] + dp[j-coins[i]];
            }
        }
    }
    return dp[amount];

}
int main(int argc, const char * argv[]) {
    vector<int> nums = {1,2,5};
    cout << change(5, nums) << endl;
    return 0;
}
