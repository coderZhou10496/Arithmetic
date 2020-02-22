//
//  main.cpp
//  357-CountNumbersWithUniqueDigits
//
//  Created by zhoujian on 2020/2/22.
//  Copyright © 2020 zhoujian. All rights reserved.
//

#include <iostream>
#include "vector"
using namespace std;

/*
 357. 计算各个位数不同的数字个数
 
 给定一个非负整数 n，计算各位数字都不同的数字 x 的个数，其中 0 ≤ x < 10n 。
 
 示例:
 
 输入: 2
 输出: 91
 解释: 答案应为除去 11,22,33,44,55,66,77,88,99 外，在 [0,100) 区间内的所有数字。
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/count-numbers-with-unique-digits
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 
 */

int countNumbersWithUniqueDigits(int n) {
    if(n == 0) {
        return 1;
    }
    if(n == 1) {
        return 10;
    }
    
    /*
     dp[i] 表示只有i位数时，满足条件数字的结果
     推导过程：
     i = 2时，两位数，第一位有9种可能，第二位除去和第一位相同的那个数字，也有9种可能，即 9*9
     i = 3时，三位数，第一位有9种可能，第二位除去和第一位相同的那个数字，有9种可能，第三位除去前两位相同的数字，有8种可能，即 9 * 9 * 8
     i = 4时，同理推得，9 * 9 * 8 *7
     即dp[i] = dp[i-1] * (11 - i)
     */
    
    
    vector<int> dp(n+1, 0);
    dp[0] = 1;
    dp[1] = 9;
    int res = dp[0] + dp[1];
    for(int i = 2; i <= n; i++) {
        dp[i] = dp[i-1] * (11 - i);
        res += dp[i];
    }
    return res;
}

int main(int argc, const char * argv[]) {
    cout << countNumbersWithUniqueDigits(6) << endl;
    return 0;
}
