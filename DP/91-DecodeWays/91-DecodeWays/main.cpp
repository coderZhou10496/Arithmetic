//
//  main.cpp
//  91-解码方法
//
//  Created by zhoujian on 2020/1/9.
//  Copyright © 2020 zhoujian. All rights reserved.
//

#include <iostream>
#include "vector"
#include "map"
using namespace std;

/*
 一条包含字母 A-Z 的消息通过以下方式进行了编码：
 
 'A' -> 1
 'B' -> 2
 ...
 'Z' -> 26
 给定一个只包含数字的非空字符串，请计算解码方法的总数。
 
 示例 1:
 
 输入: "12"
 输出: 2
 解释: 它可以解码为 "AB"（1 2）或者 "L"（12）。
 示例 2:
 
 输入: "226"
 输出: 3
 解释: 它可以解码为 "BZ" (2 26), "VF" (22 6), 或者 "BBF" (2 2 6) 。
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/decode-ways
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 
 */
int numDecodings(string s) {
    
    
    int length = (int)s.size();
    if(length == 0) {
        return 0;
    }
    if(s[0] == '0'){
        return 0;
    }
    
    // dp[i]:到第i个字符的解码总数
    /*
     第0个字符的值为1 dp[0] = 1;
     到第1个字符时，需要判断两种情况：
        (1)第1个字符是否为0
        (2)和前面的字符组成的数字大小
     大于第1个字符时，判断的情况有：
        (1)第i个字符是否为0，为0时如果s[i-1] > 3，直接返回0
        (2)如果满足s[i-1] == '1' || (s[i-1] == '2' && s[i] >= '1' && s[i] <= '6')，则dp[i] = dp[i-1]+dp[i-2];
        (3)其他情况dp[i] = dp[i-2];
     结果为dp[length-1]
     */
    vector<int> dp(length,0);
    dp[0] = 1;
    
    for(int i = 1; i < length; i++) {
        if(i == 1) {
            if(s[i] == '0') {
                if(s[i-1] == '1' || s[i-1] == '2') {
                    dp[i] = 1;
                }
                else {
                    return 0;
                }
            }
            else {
                dp[i]=s.substr(0,2) <= "26" ? 2 : 1;
            }
        }
        if(i > 1) {
            if(s[i] == '0') {
                if(s[i-1] == '1' || s[i-1] == '2') {
                    dp[i] = dp[i-2];
                }
                else {
                    return 0;
                }
            }
            else if (s[i-1] == '1' || (s[i-1] == '2' && s[i] >= '1' && s[i] <= '6')) {
                dp[i] = dp[i-1]+dp[i-2];
            }
            else {
                dp[i] = dp[i-2];
            }
        }
        
        
    }
    return dp[length-1];
}

int numDecodings_solution2(string s) {
    
    
    int len = (int)s.size();
    if(len == 0) {
        return 0;
    }
    if(s[0] == '0'){
        return 0;
    }
    
    // dp[i]:从第i个字符开始到结尾的字符串解法方式总数
    // 如果s[i]和s[i+1]组成的数字<=26，那么dp[i] = dp[i + 1] + dp[i + 2]
    vector<int> dp(len+1,0);
    dp[len] = 1;
    if (s[len - 1] == '0') {
        dp[len - 1] = 0;
    } else {
        dp[len - 1] = 1;
    }
    for (int i = len - 2; i >= 0; i--) {
        if (s[i] == '0') {
            dp[i] = 0;
            continue;
        }
        if ((s[i]-'0') * 10 + (s[i+1]-'0') <= 26) {
            dp[i] = dp[i + 1] + dp[i + 2];
        } else {
            dp[i] = dp[i + 1];
        }
    }
    return dp[0];
    
}

// 对方法二的优化：由于dp[i]只和dp[i + 1] + dp[i + 2]有关，所以可以用两个int变量表示，不必使用vector
int numDecodings_solution3(string s) {
    
    
    int len = (int)s.size();
    if(len == 0) {
        return 0;
    }
    if(s[0] == '0'){
        return 0;
    }

    int result = s[len - 1] == '0' ? 0 : 1;
    int pre = 1; // 上一个值 也就是 i+1 也可以理解为 next
    
    for (int i = len - 2; i >= 0; i--) {
        if (s[i] == '0') {
            pre = result;
            result = 0;
            continue;
        }
        if ((s[i]-'0') * 10 + (s[i+1]-'0') <= 26) {
            int temp = result;
            result = result + pre;
            pre = temp;
        } else {
            pre = result;
        }
    }
    return result;
    
}
int main(int argc, const char * argv[]) {
    cout << numDecodings_solution3("101") << endl;
    cout << numDecodings_solution3("110") << endl;
    cout << endl;
    
    return 0;
}
