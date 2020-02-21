//
//  main.cpp
//  1-扔鸡蛋
//
//  Created by zhoujian on 2020/2/21.
//  Copyright © 2020 zhoujian. All rights reserved.
//

#include <iostream>
#include "vector"
using namespace std;

/*
 K个鸡蛋
 N层楼
 现确定存在楼层F,在F层楼扔鸡蛋恰好摔碎。问最坏情况下，至少扔几次鸡蛋才能确定这个楼层F
 */

// 题解：
/*
 可以把N层楼和K个鸡蛋的问题转化为一个函数F(N,K)，其中楼层数m和鸡蛋数n是函数的两个参数，函数的值则是最优解的最大尝试次数，假设第一个鸡蛋扔出的位置在第x层（1<=x<=N），会出现两种情况：
 
 1.第一个鸡蛋没碎，则剩N-x层楼和K个鸡蛋，F(N-x,K)+1
 
 2.第一个鸡蛋碎了，则从1到x-1层尝试，剩余鸡蛋K-1，F(x-1,K-1)+1
 
 so，我们要求N层楼K个鸡蛋条件下，最大尝试次数的最小解，即
 
 F(N,K)= Min(Max(F(N-x,K)+1,F(x-1,K-1)+1)) . 1<=x<=N
 */
int findNumber(int N, int K) {
    
    // dp[n][k] 表示最优解
    vector<vector<int>> dp(N+1, vector<int>(K+1, 0));
    
    // 鸡蛋个数的边界情况: 鸡蛋个数为0，当然为0；鸡蛋个数为1，只能一层一层扔，
    for(int floor = 1; floor <= N; floor++) {
        dp[floor][0] = 0;
        dp[floor][1] = floor;
    }
    
    // 楼层的边界情况：楼层为0，则为0；楼层为1，则为1
    for(int egg = 1; egg <= K; egg++) {
        dp[0][egg] = 0;
        dp[1][egg] = 1;
    }
    
    // 从2楼开始，和2个鸡蛋开始
    for(int floor = 2; floor <= N; floor++) {
        for(int egg = 2; egg <= K; egg++) {
            // 你还有egg个鸡蛋，一共有floor层楼的子问题
            int res = INT_MAX;
            for(int drop = 1; drop <= floor; drop++) {
                int brokenRes = dp[drop-1][egg-1]; // 鸡蛋碎了，剩下的问题即如何在drop-1层，用egg-1个鸡蛋寻找最优解
                int unBrokenRes = dp[floor-drop][egg]; // 鸡蛋没碎，剩下问题的即在floor-drop层，用egg个鸡蛋寻找最优解
                int condition = max(brokenRes, unBrokenRes) + 1; // 取最大值，因为不知道鸡蛋到底碎没碎
                res = min(condition, res); // 不断和之前结果比较，取最小值
            }
            dp[floor][egg] = res;
        }
    }
    return dp[N][K];

}

int main(int argc, const char * argv[]) {
    cout << findNumber(100, 1) << endl;
    return 0;
}
