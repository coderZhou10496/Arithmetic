//
//  main.cpp
//  338-Counting Bits
//
//  Created by zhoujian on 2020/2/18.
//  Copyright © 2020 zhoujian. All rights reserved.
//

#include <iostream>
#include "vector"
using namespace std;

/*
给定一个非负整数 num。对于 0 ≤ i ≤ num 范围中的每个数字 i ，计算其二进制数中的 1 的数目并将它们作为数组返回。

示例 1:

输入: 2
输出: [0,1,1]
示例 2:

输入: 5
输出: [0,1,1,2,1,2]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/counting-bits
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

// 解法一：求出每位1的个数
int numberOf1(int num) {
    int result = 0;
    while (num != 0) {
        num = num & (num-1);
        result++;
        
    }
    return result;
    
}
vector<int> countBits(int num) {
    vector<int> v(num+1,0);
    for(int i = 0; i <= num; i++) {
        v[i] = numberOf1(i);
    }
    return v;
}
// 解法二：DP
/*
 奇数位最后一位是1，那么，对于奇数，每次右移一位，一定会减少1个1 所以 dp[n] = dp[n/2]+1
 对于偶数，右移一位肯定和本身一样的1，所以，dp[n] = dp[n/2];
 */
vector<int> countBits_solution2(int num) {
    vector<int> dp(num+1,0);
    dp[0] = 0;
    for(int i = 1; i <= num; i++) {
        if((i & 1) == 1) {
            dp[i] = dp[i/2]+1;
        }
        else {
            dp[i] = dp[i/2];
        }
    }
    return dp;
}
// 解法三：精简DP
vector<int> countBits_solution3(int num) {
    vector<int> dp(num+1,0);
    dp[0] = 0;
    for(int i = 1; i <= num; i++) {
        dp[i] = dp[i&(i-1)] + 1;
    }
    return dp;
}
int main(int argc, const char * argv[]) {
    
    vector<int> resylt = countBits_solution3(5);
    for(auto value: resylt) {
        cout << value << endl;
    }
    
    return 0;
}
