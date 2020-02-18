//
//  main.cpp
//  343-IntegerBreak
//
//  Created by zhoujian on 2020/2/18.
//  Copyright © 2020 zhoujian. All rights reserved.
//

#include <iostream>
#include "vector"
#include "math.h"
using namespace std;

/*
 给定一个正整数 n，将其拆分为至少两个正整数的和，并使这些整数的乘积最大化。 返回你可以获得的最大乘积。
 
 示例 1:
 
 输入: 2
 输出: 1
 解释: 2 = 1 + 1, 1 × 1 = 1。
 示例 2:
 
 输入: 10
 输出: 36
 解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36。
 说明: 你可以假设 n 不小于 2 且不大于 58。
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/integer-break
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 
 */

// 解法一：dp
int integerBreak(int n) {
    if(n <= 1) {
        return 0;
    }
    if(n == 2) {
        return 1;
    }
    if(n == 3) {
        return 2;
    }
    vector<int> dp(n+1, 0);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    for(int i = 4; i <= n; i++) {
        int res = 0;
        for(int j = 1; j <= i/2; j++) {
            res = max(res, dp[j] * dp[i-j]);
        }
        dp[i] = res;
    }
    return dp[n];
}

// 解法二：贪心
/*
把数字拆成尽可能的3之和。
 
 n除以3的整数部分a和余数部分b
 b == 0, 结果为 3^a
 b == 1，结果为 3^(a-1) * 4
 b == 2，结果为 3^a * 2

 */
int integerBreak_solution2(int n) {
    if( n <= 3) {
        return n-1;
    }
    int a = n/3;
    int b = n%3;
    if(b == 0) {
        return pow(3, a);
    }
    if(b == 1) {
        return pow(3, a-1) * 4;
    }
    return pow(3, a)*b;
}
int main(int argc, const char * argv[]) {
    cout << integerBreak_solution2(15) << endl;
    return 0;
}
