//
//  main.cpp
//  44-WildcardMatching
//
//  Created by zhoujian on 2020/1/3.
//  Copyright © 2020 zhoujian. All rights reserved.
//

#include <iostream>
#include "vector"
using namespace std;

/*
 给定一个字符串 (s) 和一个字符模式 (p) ，实现一个支持 '?' 和 '*' 的通配符匹配。
 
 '?' 可以匹配任何单个字符。
 '*' 可以匹配任意字符串（包括空字符串）。
 两个字符串完全匹配才算匹配成功。
 
 说明:
 
 s 可能为空，且只包含从 a-z 的小写字母。
 p 可能为空，且只包含从 a-z 的小写字母，以及字符 ? 和 *。
 示例 1:
 
 输入:
 s = "aa"
 p = "a"
 输出: false
 解释: "a" 无法匹配 "aa" 整个字符串。
 示例 2:
 
 输入:
 s = "aa"
 p = "*"
 输出: true
 解释: '*' 可以匹配任意字符串。
 示例 3:
 
 输入:
 s = "cb"
 p = "?a"
 输出: false
 解释: '?' 可以匹配 'c', 但第二个 'a' 无法匹配 'b'。
 示例 4:
 
 输入:
 s = "adceb"
 p = "*a*b"
 输出: true
 解释: 第一个 '*' 可以匹配空字符串, 第二个 '*' 可以匹配字符串 "dce".
 示例 5:
 
 输入:
 s = "acdcb"
 p = "a*c?b"
 输入: false
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/wildcard-matching
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 
 */

bool isMatch(string s, string p) {
    int sLength = (int)s.length();
    int pLength = (int)p.length();
    
    // dp[i][j]: s的前i个字符能否被p的前j个字符匹配
    vector<vector<bool>> dp(sLength+1, vector<bool>(pLength+1, false));
    dp[0][0] = true;
    for(int i = 1; i <= pLength; i++) {
        if(p[i-1] == '*') {
            dp[0][i] = dp[0][i-1];
        }
    }
    

    for(int i = 1; i <= sLength; i++) {
        for(int j = 1; j <= pLength; j++) {
            if(s[i-1] == p[j-1] || p[j-1] == '?') {
                dp[i][j] = dp[i-1][j-1];
            }
            else if (p[j-1] == '*') {
                // * 匹配空串 ： dp[i][j] = dp[i][j-1]
                // * 匹配任意长度的字符 dp[i][j] = dp[i-1][j]
                dp[i][j] = dp[i][j-1] || dp[i-1][j];
            }

        }
    }
    return dp[sLength][pLength];
}
// 解法二：使用双指针
bool isMatch_solution2(string s, string p) {
    int sLength = (int)s.length();
    int pLength = (int)p.length();
    
    int i = 0;
    int j = 0;
    int sStart = 0;
    int pStart = -1;
    while (i < sLength) {
        if(j < pLength && (s[i] == p[j] || p[j] == '?')) {
            i++;
            j++;
        }
        else if (j < pLength && p[j] == '*') {
            sStart = i;
            pStart = j;
            j++;
        }
        else if (pStart != -1) {
            j = pStart+1;
            sStart++;
            i = sStart;
        }
        else {
            return false;
        }
    }
    for(;j < pLength; j++) {
        if(p[j] != '*') {
            return false;
        }
    }
    return true;

}

int main(int argc, const char * argv[]) {

    
    
    bool res = isMatch("cb", "?a");
    cout << res << endl;
    return 0;
}
