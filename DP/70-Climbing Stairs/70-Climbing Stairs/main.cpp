//
//  main.cpp
//  70-Climbing Stairs
//
//  Created by zhoujian on 2020/1/8.
//  Copyright © 2020 zhoujian. All rights reserved.
//

#include <iostream>
#include "vector"
using namespace std;

/*
 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
 
 每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
 
 注意：给定 n 是一个正整数。
 */

int climbStairs(int n) {
    if(n <= 0) {
        return 0;
    }
    if(n <= 2) {
        return n;
    }
    vector<int> dp(n+1);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

int climbStairs_solution2(int n) {
    
    if(n <= 0) {
        return 0;
    }
    if(n <= 2) {
        return n;
    }
    
    int pre = 1;
    int current = 2;
    for(int i = 3; i <= n; i++) {
            
        int temp = pre + current;
        pre = current;
        current = temp;
    }
    return current;
    
}

int main(int argc, const char * argv[]) {
    
    int res = climbStairs(9);
    int res2 = climbStairs_solution2(9);
    
    cout << res << " " << res2 << endl;
    
    return 0;
}
