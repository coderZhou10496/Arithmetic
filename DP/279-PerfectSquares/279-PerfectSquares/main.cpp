//
//  main.cpp
//  279-PerfectSquares
//
//  Created by zhoujian on 2020/2/6.
//  Copyright © 2020 zhoujian. All rights reserved.
//

#include <iostream>
#include "vector"
using namespace std;

/*
 给定正整数 n，找到若干个完全平方数（比如 1, 4, 9, 16, ...）使得它们的和等于 n。你需要让组成和的完全平方数的个数最少。
 
 示例 1:
 
 输入: n = 12
 输出: 3
 解释: 12 = 4 + 4 + 4.
 示例 2:
 
 输入: n = 13
 输出: 2
 解释: 13 = 4 + 9.
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/perfect-squares
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
int numSquares(int n) {
    if(n <= 0) {
        return 0;
    }
    if(n <= 2) {
        return n;
    }
    vector<int> number;
    
    for(int i = 1; i < n; i++) {
        if(i * i > n) {
            break;
        }
        number.push_back(i*i);
    }
    vector<int> dp(n+1,INT_MAX);
    dp[0] = 0;
    for(int i = 1; i <= n; i++) {
        for(int num : number) {
            if(i >= num) {
                dp[i] = min(dp[i], 1 + dp[i-num]);
            }
        }
    }
//    for(int i = 1; i <= number.size(); i++) {
//        for(int j = number[i-1]; j <= n; j++) {
//            dp[j] = min(dp[j], 1 + dp[j-number[i-1]]);
//        }
//    }
    return dp[n];
    
}

int main(int argc, const char * argv[]) {
    cout << numSquares(2) << endl;
//    cout << numSquares(13) << endl;
//    cout << numSquares(64) << endl;
    return 0;
}
