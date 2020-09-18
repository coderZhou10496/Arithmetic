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
 N层楼
 K个鸡蛋
 现确定存在楼层F,在F层楼扔鸡蛋恰好摔碎。问最坏情况下，至少扔几次鸡蛋才能确定这个楼层F
 */

#pragma mark - findNumber_solution1
/*
 可以把N层楼和K个鸡蛋的问题转化为一个函数F(N,K)，其中楼层数m和鸡蛋数n是函数的两个参数，函数的值则是最优解的最大尝试次数，假设第一个鸡蛋扔出的位置在第x层（1<=x<=N），会出现两种情况：
 
 1.第一个鸡蛋没碎，则剩N-x层楼和K个鸡蛋，F(N-x,K)+1
 
 2.第一个鸡蛋碎了，则从1到x-1层尝试，剩余鸡蛋K-1，F(x-1,K-1)+1
 
 so，我们要求N层楼K个鸡蛋条件下，最大尝试次数的最小解，即
 
 F(N,K)= Min(Max(F(N-x,K)+1,F(x-1,K-1)+1)) . 1<=x<=N
 
 注：此解法理解简单，虽能求正确答案，但在LeetCode上AC不了，显示超时
 */
int findNumber_solution1(int N, int K) {
    
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
                int condition = max(brokenRes, unBrokenRes) + 1; // 取最大值为最坏情况，因为不知道鸡蛋到底碎没碎
                res = min(condition, res); // 不断和之前结果比较，取最小值
            }
            dp[floor][egg] = res;
        }
    }
    return dp[N][K];

}

#pragma mark - findNumber_solution2
/*
 在解法一的第三个for循环里，floor和egg都是定值,
 
 可以看出dp[drop-1][egg-1]的值随drop的递增而递增，最小值为dpp[0][egg-1] = 0; 最大值为dp[floor-1][egg-1];
 
 dp[floor-drop][egg]的值随drop的递增而递减，最小值为dp[0][egg] = 0; 最大值为dp[floor-1][egg];
 
 所以，dp[drop-1][egg-1] 和 dp[floor-drop][egg] 这两个函数随着drop递增，一定会有个交点。交点的情况分两种：
  （1）交点为整数，直接取值即可
   (2) 交点不为整数，比较交点横坐标左右两侧最近的两个值，然后取最小值，这是为什么在二分查找的过程中需要记录res的原因
 */

int findNumber_solution2(int N, int K) {
    
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
            int start = 1;
            int end = floor;
            int mid = 0;
            while(start <= end) {
                mid = start + (end - start)/2;
                if(dp[mid-1][egg-1] == dp[floor - mid][egg]) {
                    res = min(res, dp[mid-1][egg-1] + 1);
                    break;
                }
                else if(dp[mid-1][egg-1] > dp[floor - mid][egg]) {
                    end = mid - 1;
                    res = min(res, dp[mid-1][egg-1] + 1);
                }
                else {
                    start = mid + 1;
                    res = min(res, dp[floor - mid][egg] + 1);
                }

            }
            dp[floor][egg] = res;

        }
    }
    return dp[N][K];
    
}

#pragma mark - findNumber_solution3

/*
 本题应该逆向思维，若你有 K 个鸡蛋，你最多操作 m 次，求 N 最大值。
 1、无论你在哪层楼扔鸡蛋，鸡蛋只可能摔碎或者没摔碎，碎了的话就测楼下，没碎的话就测楼上。
 2、无论你上楼还是下楼，总的楼层数 = 楼上的楼层数 + 楼下的楼层数 + 1（当前这层楼）。
 根据这个特点，可以写出下面的状态转移方程：
 
 dp[m][k] = dp[m - 1][k] + 1 + dp[m - 1][k - 1];
 dp[m - 1][k]+1： 鸡蛋没碎，扔鸡蛋次数 m 减一，,确定在此层及以下扔出去都不会碎，所以为长度为 dp[m - 1][k] + 1,加上本层1
 dp[m - 1][k - 1]： 鸡蛋碎了，同时扔鸡蛋次数 m 减一，确定在此层以上的楼层扔出去都会碎,所以长度应该是dp[m - 1][k - 1]
 
 */
int findNumber_solution3(int N, int K) {
    
    vector<vector<int>> dp(N+1, vector<int>(K+1, 0));
    for(int m = 1; m <= N; m++) { // 最差情况：只有一个鸡蛋，最多扔N次
        for(int egg = 1; egg <= K; egg++) {
            dp[m][egg] = dp[m-1][egg] + dp[m-1][egg-1] + 1;
            if(dp[m][egg] >= N) {
                return m;
            }
        }
    }
    return N;
    
}

#pragma mark - findNumber_solution4
/*
 对解法三的优化，可优化为一维DP
 */

int findNumber_solution4(int N, int K) {
//    vector<int> dp(K+1, 0);
//    int res = 0;
//    while(dp[K] < N) {
//        for(int i = K; i > 0; i--) {
//            dp[i] = dp[i] + dp[i-1] + 1;
//        }
//        res++;
//    }
//    return res;
    
    vector<vector<int>> dp(N+1, vector<int>(K+1, 0));
    for(int m = 1; m <= N; m++) { // 最差情况：只有一个鸡蛋，最多扔N次
        for(int egg = 1; egg <= K; egg++) {
            dp[m][egg] = dp[m-1][egg] + dp[m-1][egg-1] + 1;
            if(dp[m][egg] >= N) {
                return m;
            }
        }
    }
    return N;
    
}
int main(int argc, const char * argv[]) {
    cout << findNumber_solution4(1000, 4) << endl;
    return 0;
}
